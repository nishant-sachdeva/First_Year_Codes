n = int(input("enter the number please "))

a = 0
b = n

for i in range(n):
	for f in range(a):
		print(" ", end=" ")
	for f in range(b):
		print("*", end=" ")
	print(" ")

	a = a + 1
	b = b - 1

