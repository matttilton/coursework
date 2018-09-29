# Matthew Tilton
# checkers engine written to test and train AI
# The overall structure of this as well as a few of the bits of code came from
# https://github.com/everestwitman/Pygame-Checkers/blob/master/checkers.py
# It was adapted to not use a gui and to accept no human players
# I have tried to modify this structure such that it can be extended to other board games

##DIRECTIONS##
NORTHWEST = "northwest"
NORTHEAST = "northeast"
SOUTHWEST = "southwest"
SOUTHEAST = "southeast"


class Game:
    """
    The main game control.
    """

    def __init__(self):
        self.board = Board()
        self.turn = 0
        self.hop = False

    def game_loop(self):
        """
        The event loop. This is where events are triggered
        (like a mouse click) and then effect the game state.
        """
        pass

    def main(self):
        """"This executes the game and controls its flow."""
        while True:  # main game loop
            self.game_loop()

    def end_turn(self):
        """
        End the turn. Switches the current player.
        end_turn() also checks for and game and resets a lot of class attributes.
        """
        if self.turn == 2:
            self.turn = 1
        else:
            self.turn = 2

        self.legal_moves = []

        if self.check_for_endgame():
            if self.turn == 2:
                self.broadcast_win(1)
            else:
                self.broadcast_win(2)

    def check_for_endgame(self):
        if (self.board.legal_moves(1) is None):
            return 1
        elif (self.board.legal_moves(2) is None):
            return 2
        return False

    def broadcast_win(self, player):
        if (player == 1):
            self.player1.win(True)
            self.player2.win(False)
        elif (player == 2):
            self.player1.win(False)
            self.player2.win(True)


class Board:
    def __init__(self):
        self.matrix = self.new_board()

    def new_board(self):
        """
        Create a new board matrix.
        """

        # initialize Tiles and place them in matrix

        matrix = [[None] * 8 for i in range(8)]

        # The following code block has been adapted from
        # http://itgirl.dreamhosters.com/itgirlgames/games/Program%20Leaders/ClareR/Checkers/checkers.py
        for x in range(8):
            for y in range(8):
                if (x % 2 != 0) and (y % 2 == 0):
                    matrix[y][x] = Tile("WHITE")
                elif (x % 2 != 0) and (y % 2 != 0):
                    matrix[y][x] = Tile("BLACK")
                elif (x % 2 == 0) and (y % 2 != 0):
                    matrix[y][x] = Tile("WHITE")
                elif (x % 2 == 0) and (y % 2 == 0):
                    matrix[y][x] = Tile("BLACK")

        # initialize the pieces and put them in the appropriate Tiles

        for x in range(8):
            for y in range(3):
                if matrix[x][y].type == "BLACK":
                    matrix[x][y].occupant = Piece(1, x, y)
            for y in range(5, 8):
                if matrix[x][y].type == "BLACK":
                    matrix[x][y].occupant = Piece(2, x, y)

        return matrix

    def draw(self, turn):
        board_string = ''
        legal_moves = self.get_legal_moves_in_board_form(turn)

        for y in range(8):
            for x in range(8):
                tile = self.matrix[x][7 - y]
                # print(legal_moves[x][y])
                if (tile.occupant is not None):
                    board_string = board_string + \
                        '[' + str(tile.occupant.player) + ']'
                elif legal_moves[x][y] == "LEGAL":
                    board_string = board_string + '[-]'
                else:
                    board_string = board_string + '[ ]'

            board_string = board_string + '\n'
        print(board_string)

    def getState(self):
        pass

    def rel(self, direction, x, y):
        """
        Returns the coordinates one Tile in a different direction to x, y.
        """
        if direction == NORTHWEST:
            return (self.matrix[x - 1][y - 1], x - 1, y - 1, direction)
        elif direction == NORTHEAST:
            return (self.matrix[x - 1][y - 1], x + 1, y - 1, direction)
        elif direction == SOUTHWEST:
            return (self.matrix[x - 1][y - 1], x - 1, y + 1, direction)
        elif direction == SOUTHEAST:
            return (self.matrix[x - 1][y - 1], x + 1, y + 1, direction)
        else:
            return None

    def adjacent(self, x, y):
        """
        Returns a list of Tiles locations that are adjacent (on a diagonal) to x, y.
        """
        return [self.rel(NORTHWEST, x, y), self.rel(NORTHEAST, x, y), self.rel(SOUTHWEST, x, y), self.rel(SOUTHEAST, x, y)]

    def location(self, x, y):
        """
        Takes a set of coordinates as arguments and returns self.matrix[x][y]
        This can be faster than writing something like self.matrix[coords[0]][coords[1]]
        """
        return self.matrix[x][y]

    def legal_moves(self, player):
        """
        Returns a list of legal moves for a player.
        """
        for x in self.matrix:
            for y in self.matrix[x]:

    def remove_piece(self, x, y):
        """
        Removes a piece from the board at position x, y. 
        """
        self.matrix[x][y].occupant = None

    def move_piece(self, start_x, start_y, end_x, end_y):
        pass

    def king(self, x, y):
        """
        Takes in x, y, the coordinates of Tile to be considered for kinging.
        If it meets the criteria, then king() kings the piece in that Tile and kings it.
        """
        if self.location(x, y).occupant != None:
            if (self.location(x, y).occupant.player == 2 and y == 0) or (self.location(x, y).occupant.player == 1 and y == 7):
                self.location(x, y).occupant.is_king = True


class Player:
    def __init__(self):
        pass


class Piece:
    # Initialize a piece
    def __init__(self, player, x, y, is_king=None):
        self.player = player
        self.is_king = is_king
        self.x = x
        self.y = y


class Tile:
    # Initialize a tile
    def __init__(self, type, occupant=None):
        self.type = type
        self.occupant = occupant


board = Board()
board.draw(1)
