import pandas as pd
from sklearn.preprocessing import OneHotEncoder
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
import numpy as np
onehot_encoder = OneHotEncoder()
scaler = StandardScaler()


SalaryFile= 'D:\Coding\Python\Machine Learning\Multiple Linear Regression\Salary_Data2.csv' 
data=pd.read_csv(SalaryFile)


#region Label_Encoding
data["EducationLevel"] = data["EducationLevel"].map({"高中以下":0,"大學":1,"碩士以上":2})
#endregion

#region OneHot_Encoding
onehot_encoder.fit(data[["City"]]) #Only accept the two-dimensional matrix, so need two []
city_encoded = onehot_encoder.transform(data[["City"]]).toarray()
data[["CityA","CityB","CityC"]]=city_encoded #Add title
data=data.drop(["City","CityC"], axis=1) #delete "column" is axis=1, "row" is axis=0
#print(data)
#endregion

#region Train & Test
x=data[['YearsExperience','EducationLevel','CityA','CityB']]
y=data['Salary']
x_train,x_test,y_train,y_test =train_test_split( x, y, test_size=0.2, random_state=10) # random_state can put any number
x_train= x_train.to_numpy() # turn pandas format to matrix, let the data calculate easier
x_test= x_test.to_numpy()
#endregion

#region Feature Scaling
scaler.fit(x_train)
x_train = scaler.transform(x_train)
x_test = scaler.transform(x_test)
#endregion

w = np.array([0,2,3,4])
b = 1
#region y_pred = w1x1 + w2x2... + b
def cost_function(x,y,w,b): 
    y_pred= (x*w).sum(axis=1) + b
    cost = ((y-y_pred)**2).mean()
    return cost

#print(cost_function(x_train,y_train,w,b))
#endregion

#region Cost_function
def Cost_function(x, y, w, b):
  y_pred = (x*w).sum(axis=1) + b
  cost = ((y - y_pred)**2).mean()
  return cost
#endregion

#region Gradient_Function
def Gradient_Function(x,y,w,b):
    y_pred= (x*w).sum(axis=1) + b
    b_gradient = (y_pred-y).mean()
    w_gradient = np.zeros(x.shape[1]) #shape can get column and row amount 
    for i in range(x.shape[1]):
        w_gradient[i] = (x[:,i]*(y_pred-y)).mean() # x_train[:,0] --> : is all the data in first dimensional, 0 is first column in second dimensional 
    return w_gradient,b_gradient
#endregion


#region Gradient_Descent
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

w_final, b_final, w_hist, b_hist, c_hist =gradient_descent(x_train,y_train,w,b,Cost_function,Gradient_Function,0.01,10000,1000)

y_pred = (w_final*x_test).sum(axis=1) + b_final
#print(pd.DataFrame({"y_pred": y_pred,"y_test": y_test}))



#endregion

#region real
#5.3年、碩士、城市A
x_real = np.array([[40,2,1,0]])
x_real = scaler.transform(x_real)
y_real= (x_real*w_final).sum(axis=1) + b_final

print(y_real)
#endregion


