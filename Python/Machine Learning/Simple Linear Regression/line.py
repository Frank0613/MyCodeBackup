import pandas as pd
import matplotlib as mlt #main matplotlib mode
import matplotlib.pyplot as plt #pyplot can draw table or linear graphic
from matplotlib.font_manager import fontManager #Import the fontManager class from the font_manager submodule in the matplotlib module.
from ipywidgets import interact #Value can be adjusted dynamically 

fontManager.addfont('D:\Coding\Python\Machine Learning\Simple Linear Regression\ChineseFont.ttf')
#set the font
mlt.rc('font',family='ChineseFont')

SalaryFile= 'D:\Coding\Python\Machine Learning\Simple Linear Regression\Salary_Data.csv' 

    #get the data
data=pd.read_csv(SalaryFile) 
X=data['YearsExperience']
Y=data['Salary']
    #Draw the graphic
def Plot_Pred(W,b):
    Y_pred = W*X+b
    plt.scatter(X,Y,marker='x',color='red',label='實際數據')
    plt.plot(X,Y_pred,color='blue',label='預測線')
    plt.xlabel('年資')
    plt.xlim([0,12]) #Limite the X value
    plt.ylabel('薪水(y)')
    plt.ylim([0,140])
    plt.title('年資-薪水')
    plt.legend() #Show up the label
    plt.show()

print(Plot_Pred(-100,0))











