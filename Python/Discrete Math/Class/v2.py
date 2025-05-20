n1 = float(input('please enter number one:'))
n2 = float(input('please enter number two:'))
n3 = float(input('please enter number three:'))
test_bool = True
bigger=(n1>n2)

if(n1>n2 and test_bool):
    print('n1>n2')
elif(n1<n2 or test_bool):
    print('n1<n2')
elif(n1==n2):
    print('n1<n2')
else:
    print('n1=n2')

if(bigger):
    print('n1>n2')
elif(not bigger):
    print('n1<n2')
else:
    print('n1=n2')



