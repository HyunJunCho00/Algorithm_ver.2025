import re
n=input()
nn = re.findall(r'X+|\.+' , n)
ss=""
ch=True
for nnn in nn:
    if nnn.startswith("."):
        ss+=nnn
    else:
        if len(nnn)%2:
            ch=False
            break
        else:
            a=len(nnn)//4
            b=(len(nnn)-a*4)//2
            for i in range(a):
                ss+="AAAA"
            for i in range(b):
                ss+="BB"
if ch==True:
    print(ss)
else:
    print(-1)
