import tornado.ioloop
import tornado.web
import tornado.websocket
import json
import uuid
from users import User, UserEncoder, Room
import concurrent
from tornado import gen

users = {}
users_conn = {}
rooms = {}
room = Room(uuid.uuid4(), User('bolek'), User('lolek'))


class MainHandler(tornado.web.RequestHandler):
    def get(self):
        self.render("index.html")

class UserHandler(tornado.web.RequestHandler):
    def get(self, name):
        self.set_cookie('name', name)
        users[name] = User(name)
        self.write(name)

    def post(self):
        name = self.get_body_argument("name")
        self.set_cookie('name', name)
        users[name] = User(name)
        self.render("index.html")


class EchoWebSocket(tornado.websocket.WebSocketHandler):
    def check_origin(self, origin):
        return True
        
    @gen.coroutine
    def open(self):
        print("WebSocket opened")
        name = self.get_cookie('name')
        users_conn[users[name]] = self
        room.adduser(users[name])
        while True:
            for name, user in users.items():
                data = {}
                data[name] = room.pong.get()
                users_conn[user].write_message(data)
            room.pong.run()
            yield gen.sleep(1)

    def on_message(self, message):
        self.write_message("You said: " + message)

    def on_close(self):
        name = self.get_cookie('name')
        del users[name]
        print("WebSocket closed")

application = tornado.web.Application([
    (r"/", MainHandler),
    (r"/u/(.*)", UserHandler),
    (r"/u", UserHandler),
    (r"/ws", EchoWebSocket)
    ])

if __name__ == "__main__":
    application.listen(8888)
    tornado.ioloop.IOLoop.current().start()
