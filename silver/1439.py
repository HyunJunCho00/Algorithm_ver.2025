s=input()
lis=[]
c=""
for ss in s:
    if c:
        if c[len(c)-1]==ss:
            c+=ss
        else:
            lis.append(c[0])
            c=ss
    else:
        c=ss
lis.append(c[0])
b=0
c=0
for l in lis:
    
    if 1 == int(l):
        b+=1
    else:
        c+=1
print(min(b,c))
