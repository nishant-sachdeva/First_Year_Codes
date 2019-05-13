n = int(input("enter the dimensions plis "))

#okay, now we have our dimensions, we will now input the matrix

a = []

for i in range(n):
	row = input().split()
	#basically we split the input string into a bunch of numbers
	for i in range(len(row)):
		row[i] = int(row[i])

	a.append(row)


b = []

for i in range(n):
	row = input().split()
	for i in range(len(row)):
		row[i] = int(row[i])

	b.append(row)

# okay, so now we have the two matrices we will add them
# so now a is my matrix



print("the size of the matrices as follows:")

for i in range(n):
	for j in range(n):
		print(a[i][j] + b[i][j] , end=" ")
	print("")


# this will give the transpose

for i in range(n):
	for j in range(n):
		print(a[j][i] , end = " ")

	print(" ")

