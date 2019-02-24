from TicTacToe import Board

def main():
    user1 = input('Enter first user name ')
    if not user1:
        user1 = 'Player 1'
    user2 = input('Enter second user name ')
    if not user2:
        user2 = 'Player 2'
    board = Board()

    while not board.is_full() :
        board.print_user_prompt(user1, 'X')
        board.print_the_board()
        if board.check_win('X'):
            break

        board.print_user_prompt(user2, 'O')
        board.print_the_board()
        if board.check_win('O'):
            break
    else:
        print("game tie!")

if __name__ == '__main__':
    main()
