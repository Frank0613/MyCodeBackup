keep_going ='y'
while keep_going == 'y':
    working_hours = int(input('Please put your working hours(or -1 to stop):'))
    if(working_hours == -1):
        keep_going ='n'
        continue
    if(working_hours>=5 and working_hours<=8):
        print('good')
    elif(working_hours>=8):
        print('wow')
    else:
        print('bad')