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
    def __init__(self, id, user1, user2):
        self.id = id
        self.user1 = user1
        self.user2 = user2
        self.users = set()
        self.pong = pong_ext.Pong(0)

    def adduser(self, user):
        self.users.add(user)