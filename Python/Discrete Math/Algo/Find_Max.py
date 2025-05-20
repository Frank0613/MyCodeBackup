def Max(a):
    max = a[1]
    for i in range(2,len(a)):
        if max<a[i]:
            max = a[i]
    return max
print(Max([4,23,45,3,9,12]))