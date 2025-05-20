for i in range(1,10):
    for j in range(1,10):
        if i in range(5) and j in range(2,10) and i*j<10:
            print(f"{i}x{j}= {i*j}",end=' ')
        else:
            print(f"{i}x{j}={i*j}",end=' ')
        if j==9:
            print(end='\n')