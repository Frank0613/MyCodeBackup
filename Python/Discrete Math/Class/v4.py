list_a = [1,2,3,4,5]

list_b = ['test','a',True,3,4,5]

list_b.append("frank") # 插最後面

for content in list_b:
    print(content,end=',')

print('\n')
print('=====================')
 
list_b.pop(0)

for content in list_b:
    print(content,end=',')

