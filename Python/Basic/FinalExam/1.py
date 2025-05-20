filename='D:\Coding\Python\Python基礎\FinalExam\互動二-110AC1011-顏維廷'
file=open(filename,'w')

def get_Fibonacci(n):
    if n==0 or n==1:
        return 1
    return get_Fibonacci(n-1) + get_Fibonacci(n-2)

for input in range(13):
    if input<10:
        file.write(f"fib( {input}) = {get_Fibonacci(input)}\n")
    else:
        file.write(f"fib({input}) = {get_Fibonacci(input)}\n")
file.close()