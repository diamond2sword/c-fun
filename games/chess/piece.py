import enum

class Piece(enum.IntFlag):
    Z = 1 << -1 # zero
    P = 1 << 0 # pawn
    R = 1 << 1 # rook
    N = 1 << 2 # knight
    B = 1 << 3 # bishop
    Q = 1 << 4 # queen
    K = 1 << 5 # king
    U = 1 << 6 # unmoved
    S = 1 << 7 # shadow
    PR = 1 << 8 # promote rook
    PN = 1 << 9 # promote knight
    PB = 1 << 10 # promote bishop
    PQ = 1 << 11 # promote queen
    X = 1 << 12 # bounds
    


def main():
    pass
