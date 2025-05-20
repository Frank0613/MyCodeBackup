
def isPalindrome(x):
    if(x < 0):
        return False
    rev = 0
    tar = x
    while tar!=0:
        rev = rev * 10 + tar % 10
        tar = tar // 10
    if(rev == x):                                                                                   
        return True
    else:
        return False