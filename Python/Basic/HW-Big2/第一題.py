
def binary(n):
    if n <= 1: #小於2直接印出來
        return str(n)
    else:
        m=n%2
        return binary(n//2) + str(m)

for i in range(1,16):
    str0='0'*(8-len(binary(i)))
    if i<10:
        print(f" {i} -> {str0}{binary(i)}")
    else:
        print(f"{i} -> {str0}{binary(i)}")

