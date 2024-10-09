s1 = input()
s2 = input()

cnt = 0
while(True):
    s1 = s1.replace(s2,'')
    if cnt == len(s1):
        break
    cnt = len(s1)


if s1 == '':
    s1 = "FRULA"
print(s1)



