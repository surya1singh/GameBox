class Board():
    def __init__(self):
        self._board = [['_','_','_','_'],
                       ['_','_','_','_'],
                       ['_','_','_','_'],
                       ['_','_','_','_']]

    def get_position(self, row, col):
        return self._board[row][col]

    def set_position(self, row, col, char):
        print(row, col)

        self._board[row][col] = char

    def print_the_board(self):
        for row in self._board:
            print('|%s|'%'|'.join(row))

    def print_the_board_for_input(self):
        for row_numer in range(4):
            for col_number in range(4):
                print('|' + str(row_numer), col_number, end='')
            print('|')

    def print_user_prompt(self, name, char):
        print(name+',' ,'where would you like to place an', char)
        self.print_the_board_for_input()
        while True:
            try:
                row, col = map(int,input().split())
            except (TypeError, IndexError, ValueError):
                print('\nThat postition is taken or invalid position')
                self.print_the_board_for_input()
                continue
            if (row in (0,1,2,3) and col in (0,1,2,3)) \
                    and self.get_position(row , col) == '_':
                self.set_position(row, col, char)
                break

    def check_win(self, char):
        f_diag = 0
        b_diag = 0
        row = 0
        col = 0

        for i in range(4):
            row = self._board[i].count(char)
            if self._board[i][i] == char:
                f_diag += 1
            if self._board[i][3-i] == char:
                b_diag += 1

            for j in range(4):
                if self._board[j][i] == char:
                    col += 1

            if 4 in (row, col, f_diag, b_diag):
                return 1
            col = 0


    def is_full(self):
        return sum([x.count('_') for x in self._board]) == 0
