n=input()
three=0
for i in range(len(n)):
    three+=int(n[i])
sort_n=sorted(n,key=lambda s:(s),reverse=True)
if three%3==0 and sort_n[len(n)-1]=='0':
    for s in sort_n:
        print(s,end="")
else:
    print(-1)
