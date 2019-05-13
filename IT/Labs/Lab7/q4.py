def JoinIntegers(a):
    # we have the list of numbers as string
    ans = a.strip('[]').replace(',', '')
    print(ans)

x = input("please enter the numbers ")
JoinIntegers(x)