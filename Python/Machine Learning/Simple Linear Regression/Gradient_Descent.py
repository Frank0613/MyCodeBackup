import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

#region Get the data
SalaryFile= 'D:\Coding\Python\Machine Learning\Simple Linear Regression\Salary_Data.csv' 
data=pd.read_csv(SalaryFile) 
X=data['YearsExperience']
Y=data['Salary']
#endregion

#region cost_function
def cost_function(W,b):
    Y_pred= X*W + b
    Cost = (Y - Y_pred)**2
    Cost = Cost.sum() / len(X)
    return Cost
#endregion

#region gradient_function
def gradient_function(W, b):
    w_gradient = (X*(W*X+b-Y)).mean() #2*X*(W*X+b-Y) can ignore 2 because does not affect
    b_gradient = (W*X+b-Y).mean()
    return w_gradient, b_gradient
#endregion

#region gradient_descent
def gradient_descent(W_init,b_init,cost_function,gradient_function,learning_rate,step,p_iter=1000):
    W=W_init
    B=b_init

    c_hist = []
    w_hist = []
    b_hist = []

    for i in range(step):
        wg,bg=gradient_function(W, B) #Get the slope
        W=W-wg*learning_rate
        B=B-bg*learning_rate
        cost = cost_function(W,B)

        #save everytime's W、B、cost
        w_hist.append(W)
        b_hist.append(B)
        c_hist.append(cost)

        if i % p_iter == 0:
            print(f'第{i:5}次 Cost值為{cost:7.2f} W = {W:5.2f} B = {B:5.2f} W_gradient = {wg:4f} B_gradient = {bg:4f}') #":3" is how much space you want ot take up, ".2f" is the number of digits after the decimal point

    return W,B,w_hist,b_hist,c_hist
#endregion
w_final, b_final, w_hist, b_hist, c_hist =gradient_descent(99,-7,cost_function,gradient_function,1.0e-2,10000,1000)
print(f'最終結果：W={w_final:4f} B={b_final:4f}')

#region Cost of b = -100~100, W = -100~100
ws = np.arange(-100, 101)
bs = np.arange(-100, 101)
costs = np.zeros((201, 201))

i = 0
for w in ws: 
  j = 0
  for b in bs: 
    cost = cost_function(w, b)
    costs[i,j] = cost
    j = j+1
  i = i+1
#endregion

#region compare with the b = -100~100, W = -100~100 graphic

plt.figure(figsize=(7, 7)) #Scale of the graphic
ax = plt.axes(projection="3d") #3D graphic
ax.xaxis.set_pane_color((0, 0, 0)) #color
ax.yaxis.set_pane_color((0, 0, 0))
ax.zaxis.set_pane_color((0, 0, 0))

b_grid, w_grid = np.meshgrid(bs, ws) #turn one-dimensional arrays to the two-dimensional matrix
ax.plot_surface(w_grid, b_grid, costs, cmap="Greens", alpha=0.5)
ax.set_title("Cost of b = -100~100, W = -100~100")
ax.set_xlabel("w")
ax.set_ylabel("b")
ax.set_zlabel("cost")

#process of find the point
ax.scatter(w_hist[0],b_hist[0],c_hist[0],color="green", s=40) #init_point
ax.plot(w_hist,b_hist,c_hist,color="blue") #route
ax.scatter(w_final,b_final,color="red", s=40) #destination
#endregion
#plt.plot(np.arange(0,100),c_hist[:100]) #show up top 100 routes
plt.show()




