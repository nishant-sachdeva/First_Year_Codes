from datetime import date

#date format is year, month, date
def GetDays(date1, date2):
    #now i have the two days, ima gonna get the days btween them
    d0 = date(int(date1[0]), int(date1[1]), int(date1[2]))
    d1 = date(int(date2[0]), int(date2[1]), int(date2[2]))
    delta = d1 - d0
    print(abs(delta.days))


x = input("enter date 1 ")
x1 = x.replace(',' , ' ').split()
print(x1)
y = input("enter date 2 ")
x2 = y.replace(',', ' ').split()
print(x2)
GetDays(x1,x2)