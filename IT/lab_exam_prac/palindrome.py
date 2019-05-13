number = int(input("Enter your number  "))
copy = number
reverse = 0

while int(copy) > 0 :
	temp = int(copy%10)
	reverse = reverse*10 + temp
	copy = copy/10
	# print("copy is ")
	# print(copy)
	# print("Temp is ")
	# print(temp)

print("The reverse number is ")
print(reverse)

#assuming the number is the reverse now

if number == reverse:
	print("yes it is a palindrome")
else:
	print("Well, ....oops!")




