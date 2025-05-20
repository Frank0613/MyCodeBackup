def Bubble_Sort(a):
    for i in range(len(a)-1):
        for j in range(len(a)-i-1):
            if a[j] > a[j+1]:
                a[j], a[j+1] = a[j+1], a[j] #Exchange
                print(a)
            else:
                continue
            #print(a)
print(Bubble_Sort([6, 2, 3, 1, 5, 4]))