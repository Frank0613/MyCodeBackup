def add(x,y):
    return x+y
def sub(x,y):
    return x-y
def mul(x,y):
    return x*y
def div(x,y):
    return x/y
def main():
    keep_going = "y"
    while keep_going =="y":
        x=int(input("Enter X："))
        y=int(input("Enter Y："))
        opt = int(input("What do you want?(0.add,1.sub,2.mul,3.div)"))
        if opt == 0:
            print(add(x,y))
        elif opt ==1:
            print(sub(x,y))
        elif opt ==2:
            print(mul(x,y))
        elif opt ==3:
            print(div(x,y))
        else:
            print("Invalid!!")
main()