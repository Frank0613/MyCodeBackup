import math 
def ClosestPair(a):
    min = math.inf
    for i in range(len(a)):
        for j in range(i):
            dis = (a[j][0] - a[i][0])**2 + (a[j][1] - a[i][1])**2
            if(dis < min):
                min = dis
                closestPair = [(a[j][0],a[j][1]),(a[i][0],a[i][1])]
    return closestPair
                
    




print(ClosestPair([(-1,5),(4,1),(7,4),(-3,3)]))