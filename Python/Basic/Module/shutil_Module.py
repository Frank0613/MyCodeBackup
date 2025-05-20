import shutil

shutil.copyfileobj('file1','file2') #Copy file1's contents to file2
shutil.copyfile('file1','file2') #Copy file1 to the new path and become new file (Overwrite when have the same file name)
shutil.copymode('file1','file2') #Copy file's permission information to file2
shutil.copy('file1','file2') #Copy files and permission information to file2
shutil.copy2('file1','file2') #Copy file1 (Include permission info) to the new path and become new file (Overwrite when have the same file name)
shutil.copystat('file1','file2') #Copy file's permission information、modified time、user to file2
shutil.move('file1','file2') #Move file1 into file2
shutil.copytree('folder1', 'folder2',ignore=shutil.ignore_patterns('*.jpg', '*.png')) #Move all the files in folder1 to folder2 (Expect .jpg and .png) 
shutil.rmtree('folder1') #Delete all the things in folder1

#also can pack and unpack the file. more --> https://steam.oxxostudio.tw/category/python/library/shutil.html#a3
