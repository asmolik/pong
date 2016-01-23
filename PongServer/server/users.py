from json.encoder import JSONEncoder
import pong_ext

class User(object):
    def __init__(self, name):
        self.name = name


class UserEncoder(JSONEncoder):
    def default(self, obj):
        if isinstance(obj, User):
            return obj.__dict__
        return JSONEncoder.default(self, obj)


class Room(object):
    def __init__(self, id):
        self.id = id
        self.p1score = 0
        self.p2score = 0
        self.user1 = None
        self.user2 = None
        self.users = set()
        self.pong = pong_ext.Pong()

    def setWidth(self, w):
        self.pong.setWidth(w)

    def setHeight(self, h):
        self.pong.setHeight(h)

    def setBallVelocity(self, x, y):
        self.pong.setBallVelocity(x, y)

    def setBallPosition(self, x, y):
        self.pong.setBallPosition(x, y)

    def adduser(self, user):
        if self.user1 is None:
            self.user1 = user
        elif self.user2 is None:
            self.user2 = user
        else:
            self.users.add(user)

    def input(self, p1, p2):
        self.pong.p1input(p1)
        self.pong.p2input(p2)

    def run(self, time):
        self.pong.run(time)

    def get(self):
        return self.pong.get()