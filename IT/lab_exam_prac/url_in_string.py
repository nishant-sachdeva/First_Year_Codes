import validators

line = input("Please enter the string ")

check = 0

for i in range(len(line)):
    for j in range(i, len(line)+1):
        l = line[i:j]
        #now we will check if this guy is valid operator or not
        if validators.url(l):        
            print("valid url found: ", end=" ")
            print(l)
            check = 1


if check == 0:
    print("there is no valid url in this string ")
else:
    print("the string contains the shown urls")

        