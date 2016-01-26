import tornado.ioloop
import tornado.web
import tornado.websocket
import json
import uuid
from users import User, UserEncoder, Room
import concurrent
from threading import Thread
from tornado import gen
from timeit import default_timer as timer
import time


users = {}
users_conn = {}
rooms = {}
room = Room(uuid.uuid4())

p1input = 0.0
p2input = 0.0

# runs game in room
def runGame():
    while room.running:
        global p1input
        global p2input
        room.input(p1input, p2input)
        start = timer()
        room.run(0.02)
        broadcast(createMsg(room.get()))
        p1input = 0.0
        p2input = 0.0
        checkScore()
        end = timer()
        if end-start < 0.02:
            time.sleep(0.02 - (end - start))

# create message from GameInfo
def createMsg(info):
    msg = {}
    msg['p1Score'] = info.p1score
    msg['p2Score'] = info.p2score
    msg['ballPosx'] = info.ballPos.x
    msg['ballPosy'] = info.ballPos.y
    msg['paddleAPosx'] = info.p1Pos.x
    msg['paddleAPosy'] = info.p1Pos.y
    msg['paddleBPosx'] = info.p2Pos.x
    msg['paddleBPosy'] = info.p2Pos.y
    return json.dumps(msg)

# broadcasts game information to players
def broadcast(info):
    for user, conn in users_conn.items():
        try:
            conn.write_message(info)
        except Exception:
            print("exception while broadcasting")

# chekcs score and resets te ball if it chaged
def checkScore():
    info = room.get()
    if room.p1score != info.p1score:
        room.p1score = info.p1score
        room.setBallPosition(info.fieldWidth / 2, info.fieldHeight / 2)
    if room.p2score != info.p2score:
        room.p2score = info.p2score
        room.setBallPosition(info.fieldWidth / 2, info.fieldHeight / 2)


class MainHandler(tornado.web.RequestHandler):
    def get(self):
        self.render("index.html")

class ConnectionHandler(tornado.web.RequestHandler):
    def get(self):
        if self.get_cookie('name', '') == '':
            self.render("index.html")
        self.render("pong.html")

class UserHandler(tornado.web.RequestHandler):
    def get(self, name):
        print(name)
        self.set_cookie('name', name)
        users[name] = User(name)
        self.write(name)

    def post(self):
        name = self.get_body_argument("name")
        self.set_cookie('name', name)
        users[name] = User(name)
        print(name)
        self.render("user.html")


class EchoWebSocket(tornado.websocket.WebSocketHandler):
    def check_origin(self, origin):
        return True
        
    @gen.coroutine
    def open(self):
        name = self.get_cookie('name')
        print("WebSocket opened " + name)
        users_conn[users[name]] = self
        room.adduser(users[name])

    def on_message(self, message):
        data = json.loads(message)
        if "start" in data:
            if not room.running:
                room.running = True
                room.setWidth(data["width"])
                room.setHeight(data["height"])
                print(data["vely"])
                room.setBallVelocity(data["velx"], data["vely"])
                roomThread = Thread(target = runGame)
                roomThread.start()
        else:
            global p1input
            global p2input
            name = self.get_cookie('name')
            p = users[name]
            if p == room.user1:
                if data["up"]:
                    p1input = -1.0
                if data["down"]:
                    p1input = 1.0
            elif p == room.user2:
                if data["up"]:
                    p2input = -1.0
                if data["down"]:
                    p2input = 1.0

    def on_close(self):
        name = self.get_cookie('name')
        room.removeUser(users[name])
        del users_conn[users[name]]
        del users[name]
        print("WebSocket closed " + name)

application = tornado.web.Application([
    (r"/", MainHandler),
    (r"/u/(.*)", UserHandler),
    (r"/u", UserHandler),
    (r"/connect", ConnectionHandler),
    (r"/ws", EchoWebSocket),
    (r"/static/(.*)", tornado.web.StaticFileHandler, {"path": "static"})
    ])

if __name__ == "__main__":
    application.listen(8888)
    tornado.ioloop.IOLoop.current().start()
