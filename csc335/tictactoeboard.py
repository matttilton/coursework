class board:
    topLeft = None
    topMiddle = None
    topRight = None
    middleLeft = None
    middleMiddle = None
    middleRight = None
    bottomLeft = None
    bottomMiddle = None
    bottomRight = None

    def detectWin(self):
        if self.topLeft == self.middleLeft == self.bottomLeft: #check left column
            if self.topLeft != None:
                return self.topLeft
        if self.topMiddle == self.middleMiddle == self.bottomMiddle: #check middle column
            if self.topMiddle != None:
                return self.topMiddle
        if self.topRight == self.middleRight == self.bottomRight: #check right column
            if self.topRight != None:
                return self.topRight
        if self.topLeft == self.topMiddle == self.topRight: # check top row
            if self.topLeft != None:
                return self.topLeft
        if self.middleLeft == self.middleMiddle == self.middleRight: # check middle row
            if self.middleLeft != None:
                return self.middleLeft
        if self.bottomLeft == self.bottomMiddle == self.bottomRight: # checks bottom row
            if self.bottomLeft != None:
                return self.bottomLeft
        if self.bottomLeft == self.middleMiddle == self.topRight: # checks LR diagonal
            if self.bottomLeft != None:
                return self.bottomLeft
        if self.topLeft == self.middleMiddle == self.bottomRight: # checks RL diagonal
            if self.topLeft != None:
                return self.topLeft
        return None

    def mark(self, x, y, player):
        if x == 0 and y == 0:
            if self.topLeft == None:
                self.topLeft == player
            else:
                return -1
        elif x == 1 and y == 0:
            if self.topMiddle == None:
                self.topMiddle = player
            else:
                return -1
        elif x == 2 and y == 0:
            if self.topRight == None:
                self.topRight = player
            else:
                return -1
        elif x == 0 and y == 1:
            if self.middleLeft == None:
                self.middleLeft = player
            else:
                return -1
        elif x == 1 and y == 1:
            if self.middleMiddle == None:
                self.middleMiddle = player
            else:
                return -1
        elif x == 2 and y == 1:
            if self.middleRight == None:
                self.middleRight = player
            else:
                return -1
        elif x == 0 and y == 2:
            if self.bottomLeft == None:
                self.bottomLeft = player
            else:
                return -1
        elif x == 1 and y == 2:
            if self.bottomMiddle == None:
                self.bottomMiddle = player
            else:
                return -1
        elif x == 2 and y == 2:
            if self.bottomRight == None:
                self.bottomRight == player
            else:
                return -1
        return 0

    def getBoard(self):
        return [self.topLeft, self.topMiddle, self.topRight, self.middleLeft, self.middleMiddle, self.middleRight, self.bottomLeft, self.bottomMiddle, self.bottomRight]

    def printBoard(self):
        
        print(self.topLeft + ' | ' + self.topMiddle + ' | ' + self.topRight)