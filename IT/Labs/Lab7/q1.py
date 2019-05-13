def isLeapYear(a):
    if (a%100) == 0:
        if (a%400) == 0:
            print("leap year")
        else:
            print("not leap year")
    elif (a % 4) == 0:
        print("leap year")
    else:
        print("not leap year")

print("please enter year")
x = int(input())
isLeapYear(x)