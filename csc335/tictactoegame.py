from tictactoeboard import board as board
from randomai import player as badai

board = board()

turn = 0

player1 = badai('x')
player2 = badai('o')

while board.detectWin() == None:
    if turn == 0:
        player1.move(board)
        turn = 1
    if turn == 1:
        player2.move(board)
        turn = 0
    board.printBoard()

print(board.detectWin() + ' Wins!')