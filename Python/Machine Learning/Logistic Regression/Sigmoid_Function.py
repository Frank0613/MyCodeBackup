import numpy as np
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
scaler = StandardScaler()

SalaryFile= 'D:\Coding\Python\Machine Learning\Logistic Regression\Diabetes_Data.csv' 
data=pd.read_csv(SalaryFile)

data['Gender'] = data['Gender'].map({'男生':1,'女生':0})

x=data[['Age','Weight','BloodSugar','Gender']]
y=data['Diabetes']
x_train,x_test,y_train,y_test =train_test_split( x, y, test_size=0.2, random_state=10) # random_state can put any number
x_train= x_train.to_numpy() # turn pandas format to matrix, let the data calculate easier
x_test= x_test.to_numpy()

scaler.fit(x_train)
x_train = scaler.transform(x_train)
x_test = scaler.transform(x_test)



w=np.array([1,2,3,4])
b=1

def sigmoid_function(z):
    return 1/(1+np.exp(-z))


def Cost_function(x, y, w, b):
    z = (x*w).sum(axis=1) + b
    y_pred = sigmoid_function(z)
    cost = -(y*np.log(y_pred) + (1-y)*np.log(1-y_pred)).mean()
    return cost

def Gradient_Function(x, y, w, b):
    z = (x*w).sum(axis=1) + b
    y_pred = sigmoid_function(z)
    b_gradient = (y_pred-y).mean()
    w_gradient = np.dot(x.T, (y_pred-y)) / len(y)  # 使用向量化計算
    return w_gradient, b_gradient

def gradient_descent(x,y,W_init,b_init,cost_function,gradient_function,learning_rate,step,p_iter=1000):
    W=W_init
    B=b_init

    c_hist = []
    w_hist = []
    b_hist = []

    for i in range(step):
        wg,bg=gradient_function(x,y,W, B) #Get the slope
        W=W-wg*learning_rate
        B=B-bg*learning_rate
        cost = cost_function(x,y,W,B)

        #save everytime's W、B、cost
        w_hist.append(W)
        b_hist.append(B)
        c_hist.append(cost)

        if i % p_iter == 0:
            print(f'第{i:5}次  Cost值為{cost:7.2f}  W = {W}  B = {B:.2f}') #":3" is how much space you want ot take up, ".2f" is the number of digits after the decimal point

    return W,B,w_hist,b_hist,c_hist



np.set_printoptions(formatter={'float':'{:5.8f}.'.format})

w_final, b_final, w_hist, b_hist, c_hist = gradient_descent(x_train,y_train,w,b,Cost_function,Gradient_Function,0.01,10000,1000)

x_real = np.array([[18,50,100,0]])
x_real = scaler.transform(x_real)
y_real= (x_real*w_final).sum(axis=1) + b_final

y_real_binary = (y_real > 0.5).astype(int)
print(y_real_binary)