def Insertion_Sort(a): 
    n = len(a)
    for j in range(1,n):
        i = 0
        while a[i]<a[j]:
            i+=1
        m = a[j]
        for k in range(j-i):
            a[j-k] = a[j-k-1]
        a[i] = m
    return a

print(Insertion_Sort([4,2,5,3,1]))