import mysql.connector

connection = mysql.connector.connect( #Log in 

    host = '127.0.0.1',
    port = '3306',
    user = 'root',
    password = 'f9r2a0n6k13',
    database = 'company' #Can write the database u want to use
)

cursor = connection.cursor() #Tell them I want to use

#--Create Database(cursor.execute(MySQL syntax))
#cursor.execute('create database `python`;') 

#--Show up the database's name
cursor.execute('show databases;')
record = cursor.fetchall() #get the return(list)
for i in record:
    print(i)




cursor.close()
connection.commit() #If any data is changed, need to write 'commit'
connection.close()