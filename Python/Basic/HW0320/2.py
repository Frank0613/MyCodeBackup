#假設 value = 1.23456，
#請使用字串切片(slicing)，再搭配 f-strings 的格式，以一個 print() 來輸出下列的結果:
#1
#1.2
#1.23
#1.234
#1.2345
#1.23456
value=1.23456
s=str(value)
for i in range(0,8):
    if i == 2:
        continue
    print(f"{s[0:i]}")
print('\n')