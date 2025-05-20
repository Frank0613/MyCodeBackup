#善用字串拼接
def binary(n):
    if n <= 1: #小於2直接印出來
        return str(n)
    else:
       m=n%2
       return binary(n//2) + str(m)
#b=input('請輸入要轉換的數：')
#num=int(b)
for i in range(1,16):
    if i<10:
        print(f" {i} -> {binary(i)}")
    else:
        print(f"{i} -> {binary(i)}")

