import sys

n=int(input())
arr=[]
for _ in range(n):
    str=input()
    arr.append(str)


def digit(s):
    dig_sum=0
    for ss in s:
        if ss.isdigit():
            dig_sum+=int(ss)
    return dig_sum
sorted_list = sorted(arr, key=lambda s: (len(s), digit(s), s))
for s in sorted_list:
    print(s)
