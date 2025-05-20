import os

os.getcwd() #Get the current working directory
os.chdir('D:\Coding\Python\Python基礎\Module\Dis') #Change the current working directory, it means the file will be here when created.
os.mkdir('file') #Create a file in the specified directory (Created a 'test' file in the 'Dis' file)
os.rmdir('file') #Delete a file in the specified directory (Deleted 'test' file which in the 'Dis' file)
os.listdir('file') #Use list to print all of the contents in the file 
f = os.open('file/file.txt', os.O_RDWR|os.O_CREAT) #Create a file which can read and write
#All the modes
os.O_RDONLY	#Read only
os.O_WRONLY	#Write only
os.O_RDWR	#Read and Write
os.O_APPEND	#Append Mode (Create file when doesn't exist)
os.O_CREAT	#Create and open file
#==========================================================================
Str='Hollow'
os.write(f, Str.encode()) #Write contents in the file
os.rename('test', 'test2') #Rename the files
os.remove('file/file.txt') #Delete the file (used path)
os.stat('file/file.txt') #Get the file's attributes
os.close('file') #Close file if open it

# more --> https://steam.oxxostudio.tw/category/python/library/os.html