from board import Board


l = Board()
turn = 1
che = 1
print("The indexes start from top left, are 1 based and go right and down")

def check():
	if a >= 1 and b >= 1 and c >= 1 and d >= 1 and a <= 8 and b <= 8 and c <= 8 and d <= 8:
		return 1
	return 0

def execute():
	if check() == 1:
		print("valid input : processing")
		l.board[d][c] = l.board[b][a]
		l.board[b][a] = ' '
	else:
		print("invalid input : please try again")



while(1):
	# break
	Board.disp(l)
	if turn == 1:
		print("capitals go")
	else:
		print("small ones go")
	# take inputs, 
	inpp = input("please enter the source and destination: NOTE THAT THEY SHOULD BE SEPARATED BY A SINGLE SPACE:  ")
	# we have an array of the source and destination
	if inpp[3] == ' ':
		print("invalid input")
		break

	a = int(inpp[0]) 
	b = int(inpp[1]) 
	c = int(inpp[3]) 
	d = int(inpp[4]) 

	if turn == 0:
		if ord(l.board[b][a]) >= ord('A') and ord(l.board[b][a]) <= ord('Z'):
			print("You're out of turn")
			che = 0
		else:
			che = 1
			execute()
	if turn == 1:
		if ord(l.board[b][a]) >= ord('a'):
			print("you're out of turn")
			che = 0
		else:
			che = 1
			execute()

	if che == 1:
		turn = 1 - turn

	
# for i in range(0,7):
# 	for j in range(0,7):
# 		print(l.board[i][j])