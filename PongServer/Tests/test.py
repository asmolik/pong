import unittest
from unittest.mock import MagicMock
import sys
sys.modules['pong_ext'] = MagicMock()

from server.users import Room, User

class TestRoom(unittest.TestCase):
    def setUp(self):
        a = User('a')
        b = User('b')
        self.room = Room(1)
        self.room.adduser(a)
        self.room.adduser(b)
        self.room.pong.get = MagicMock()
        self.room.pong.run = MagicMock()

    def test_room_users(self):
        c = User('c')
        self.room.adduser(c)
        self.assertEqual(self.room.user1.name, 'a')
        self.assertTrue(c in self.room.users)

    def test_room_pong(self):
        self.room.pong.get()
        self.room.pong.get.assert_called_with()
        self.room.pong.run()
        self.room.pong.run.assert_called_with()

if __name__ == '__main__':
    unittest.main()