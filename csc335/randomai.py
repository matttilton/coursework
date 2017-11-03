import random

class player:
    name = ''

    def __init__(self, name):
        self.name = name

    def move(self, board):
        while board.mark(random.randint(0,2), random.randint(0,2), self.name) != 0:
            pass