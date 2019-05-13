


class Board:
    def __init__(self):
        self.board = []
        home0 = [' ','1','2','3','4','5','6','7','8']
        home1 = [' ', 'r','n','b','k','q','b','n','r']
        home2 = [' ', 'p','p','p','p','p','p','p','p']
        self.board.append(home0)
        self.board.append(home1)
        self.board.append(home2)
        for i in range(4):
            temp = []
            for j in range(9):
                temp.append('')
            self.board.append(temp)
        home3 = [' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P']
        home4 = [' ', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R']
        self.board.append(home3)
        self.board.append(home4)



    def disp(self):
        strf = ''
        for row in self.board:
            for i in range(2):
                for obj in row:
                    if i%2 == 0: # Print Board Scaffolding
                        strf += '+---'
                    else: # Print objects
                        strf += '|'
                        if obj == '':
                            strf += '   '
                        else:
                            strf += ' ' + obj + ' '
                        # strf += '   '
                if i%2 == 0:
                    strf += '+'
                else:
                    strf += '|'
                strf += '\n'
        for obj in self.board[-1]:
            strf += '+---'
        strf += '+'
        print(strf)
        

