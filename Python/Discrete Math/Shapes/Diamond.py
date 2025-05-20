Layer = int(input('Enter A Layer：'))

for i in range(Layer):
    print((Layer-i-1)*" "+(2*i+1)*"*")
for j in range(Layer-2,-1,-1):
    print((Layer-j-1)*" "+(2*j+1)*"*")




