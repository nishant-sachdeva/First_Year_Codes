from pieces import Piece 
from pieces import Knight
from pieces import Rook
from pieces import Bishop
from pieces import Queen
from pieces import King
from pieces import Pawn

from chess import Game


import itertools

WHITE = "white"
BLACK = "black"
#okay, we have all the classes, hopefully
# we should be able to make this work
# this itertools thing apparently does
# this thing about dispaying pretty stuff

chessCardinals = [(1,0),(0,1),(-1,0),(0,-1)]
chessDiagonals = [(1,1),(-1,1),(1,-1),(-1,-1)]

def knightList(x,y,int1,int2):
    """sepcifically for the rook, permutes the values needed around a position for noConflict tests"""
    return [(x+int1,y+int2),(x-int1,y+int2),(x+int1,y-int2),(x-int1,y-int2),(x+int2,y+int1),(x-int2,y+int1),(x+int2,y-int1),(x-int2,y-int1)]
def kingList(x,y):
    return [(x+1,y),(x+1,y+1),(x+1,y-1),(x,y+1),(x,y-1),(x-1,y),(x-1,y+1),(x-1,y-1)]


uniDict = {WHITE : {Pawn : "p", Rook : "r", Knight : "n", Bishop : "b", King : "k", Queen : "q" }, BLACK : {Pawn : "P", Rook : "R", Knight : "N", Bishop : "B", King : "K", Queen : "Q" }}

Game()