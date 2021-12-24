"""
Tic Tac Toe Player
"""

import math
from copy import deepcopy

X = "X"
O = "O"
EMPTY = None
ai = ""


# X is the MAX player and O is the MIN player

def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    # Determines who's turn it is
    o = 0
    x = 0
    for i in board:
        for j in i:
            if j == X:
                x += 1
            elif j == O:
                o += 1
    if (o + x) == 0:
        return X
    else:
        if isEven(x + o):
            print(X)
            return X
        else:
            print(O)
            return O


def actions(board):
    # All possible valid actions given the current state
    acset = set()
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == EMPTY:
                acset.add((i, j))
    return acset


def result(board, action):
    # Returns the board after a player takes a certain action
    i, j = action
    x = deepcopy(board)
    if x[i][j] is not EMPTY:
        raise Exception("Invalid Action")
    else:
        x[i][j] = player(board)
    return x


def winner(board):
    # Determines who the winner of the board is
    if horizontal(board) is not False:
        return horizontal(board)
    if vertical(board) is not False:
        return vertical(board)
    if diagonal(board) is not False:
        return diagonal(board)
    else:
        return None


def terminal(board):
    # Determines if there is no more possible actions or if someone has won
    if winner(board) is not None:
        return True
    else:
        tilesfilled = 0
        for row in board:
            for tile in row:
                if tile is not EMPTY:
                    tilesfilled += 1
        if tilesfilled == 9:
            return True
        elif tilesfilled == 9:
            return False


def utility(board):
    # Determines the value of the terminal boards
    if winner(board) == X:
        return 1
    elif winner(board) == O:
        return -1
    else:
        return 0


def minimax(board):
    if terminal(board):
        return None
    # Optimal Move
    om = None

    a = -math.inf
    b = math.inf

    if player(board) is X:

        v = -math.inf

        for action in actions(board):

            new_v = value(result(board, action), O, a, b)

            a = max(v, new_v)

            if new_v > v:
                v = new_v
                om = action
    else:

        v = math.inf

        for action in actions(board):

            new_v = value(result(board, action), X, a, b)

            a = min(v, new_v)

            if new_v < v:
                v = new_v
                om = action
    return om


# All functions beyond this comment are helper functions

def isEven(x):
    if (x % 2) == 0:
        return True
    else:
        return False


def value(board, player, alpha, beta):
    if terminal(board):
        return utility(board)
    if player == X:
        v = -math.inf

        for action in actions(board):

            v = max(v, value(result(board, action), O, alpha, beta))

            a = max(alpha, v)

            if alpha >= beta:
                break
            return v
    else:
        v = math.inf

        for action in actions(board):

            v = min(v, value(result(board, action), X, alpha, beta))

            beta = min(beta, v)

            if alpha >= beta:
                break

        return v


def validAction(action):
    m = 0
    for i in action:
        m += i
    if m <= 4:
        return True
    else:
        return False


def vertical(board):
    cols = []

    for i in range(3):
        cols.append([row[i] for row in board])

    for col in cols:
        if col[0] is not EMPTY:
            if col.count(col[0]) == 3:
                return col[0]
    return False


def diagonal(board):
    diags = [[board[0][0], board[1][1], board[2][2]]], [board[0][2], board[1][1], board[2][0]]
    if diags.count(None) == len(diags):
        return False
    for diag in diags:
        if diags is not None:
            if diag.count(diag[0]) == 3:
                return diag[0]
    return False


def horizontal(board):
    for row in board:
        if row[0] is not EMPTY:
            if row.count(row[0]) == 3 and row[0]:
                return row[0]
    return False
