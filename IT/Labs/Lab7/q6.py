import sys
import string

inp = sys.argv[1]
out = sys.argv[2]

fileforinput = open(inp, 'r').read()
translator = str.maketrans('','', string.punctuation)
strr = fileforinput.translate(translator)
words = strr.upper().split()
#okay, so i have the requisite words;
#now we will make the freq thing
fileforoutput = open(out , 'w')
# now we will start appeding
words2 = []
for i in words:
    if i not in words2:
        words2.append(i)

for i in range(0, len(words2)):
    print(words2[i], " : " , words.count(words2[i]))
    fileforoutput.write(str(words2[i]))
    fileforoutput.write(" : ")
    fileforoutput.write(str(words.count(words2[i])))
    fileforoutput.write('\n')
# okay so far so good
