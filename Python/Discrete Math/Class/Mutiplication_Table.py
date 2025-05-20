for i in range(1,10):
    for j in range(1,10):
        print(f"{i}X{j}={i*j}")
print("=================================")

for i in range(81):
    print(f"{i//9+1}X{i%9+1}={(i//9+1)*(i%9+1)}")