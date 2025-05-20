def Binary_Search(X,a): #a是已排序遞增數列
    left = 1
    right = len(a)
    while left<right:
        mid = int((left+right)/2)
        if(X>a[mid]):
            left = mid+1
        else:
            right = mid
    if(X==a[left]):
        location = left
    else:
        location = 0
    return location

print(Binary_Search(9,[1,2,3,4,6,7,8,9,21]))
    
    
