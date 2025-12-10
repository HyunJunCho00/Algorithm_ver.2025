s = input()
subs = set()

for i in range(len(s)):
    ss = ""
    for k in range(i, len(s)):
        ss += s[k]
        subs.add(ss)
print(len(subs))
