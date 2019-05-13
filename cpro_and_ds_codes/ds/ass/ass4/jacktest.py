from random import randint

n = randint(5, 50)
t = randint(n-1, 100)
print(str(n) + " " + str(t))
x = ""
for i in range(n-1):
    x += str(randint(1, 100)) + " "

print(x)

d = ""
for i in range(n-2):
	d += str(randint(1,100)) + " "
print(d)