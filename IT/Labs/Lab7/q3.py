def UniqueSort(s):
    f = s.replace(',', ' ')
    d = f.split()
    words = []
    for x in d:
        if x not in words:
            words.append(x)
    words.sort()
    print (str(words).strip('[]'))

x = input("please enter the lists of words ")
UniqueSort(x)