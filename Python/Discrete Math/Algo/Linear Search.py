def Linear_Search(X,a):
    i=1
    while(i<=len(a) and X!=a[i]):
        i+=1
    if(i<=len(a)):
        location = i
    else:
        location = 0
    return location

print(Linear_Search(3,[1,2,3,4,5,6]))