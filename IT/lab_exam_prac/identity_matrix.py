n = int(input("enter the side length please "))

for x in range(n):
	for y in range(n):
		if x == y:
			print("1", end = " ")
		else:
			print("0", end = " ")

	print(" ")
	