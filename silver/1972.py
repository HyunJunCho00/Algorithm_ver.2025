import sys
while True:
    line=sys.stdin.readline().strip()
    if line =='*':
        break

    lenn=len(line)

    ch= False
    for i in range(1,lenn):
        lis=set()
        for k in range(lenn-i):
            s=""
            s+=line[k]+line[k+i]
            if s in lis:
                ch=True
            else:
                lis.add(s)
    print(line,end="")
    if ch == True:
        print(" is NOT surprising.")
    else:
        print(" is surprising.")
