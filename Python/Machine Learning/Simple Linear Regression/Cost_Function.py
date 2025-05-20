import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
SalaryFile= 'D:\Coding\Python\Machine Learning\Simple Linear Regression\Salary_Data.csv' 

#get the data
data=pd.read_csv(SalaryFile) 
X=data['YearsExperience']
Y=data['Salary']

#region cost_function
#To get the average distance between Y and Y_pred
def cost_function(W,b):
    Y_pred= X*W + b
    Cost = (Y - Y_pred)**2
    Cost = Cost.sum() / len(X)
    return Cost
#endregion

#region Cost of b=0, W=-100~100
# cons = []
# for W in range(-100,101):
#     cost=cost_function(W,0)
#     cons.append(cost)
# plt.plot(range(-100,101),cons)
# plt.xlabel('W')
# plt.ylabel('cost')
# plt.title('Cost of b = 0, W = -100~100')
#plt.show()
#endregion

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


#Draw
plt.figure(figsize=(7, 7)) #Scale of the graphic
ax = plt.axes(projection="3d") #3D graphic
ax.xaxis.set_pane_color((0, 0, 0)) #color
ax.yaxis.set_pane_color((0, 0, 0))
ax.zaxis.set_pane_color((0, 0, 0))

b_grid, w_grid = np.meshgrid(bs, ws) #turn one-dimensional arrays to the two-dimensional matrix
# https://wangyeming.github.io/2018/11/12/numpy-meshgrid/

ax.plot_surface(w_grid, b_grid, costs, cmap="Greens", alpha=0.7)
ax.plot_wireframe(w_grid, b_grid, costs, color="black", alpha=0.1)

ax.set_title("Cost of b = -100~100, W = -100~100")
ax.set_xlabel("w")
ax.set_ylabel("b")
ax.set_zlabel("cost")

w_index, b_index = np.where(costs == np.min(costs)) #Find the min cost and where they are(index)
ax.scatter(ws[w_index], bs[b_index], costs[w_index, b_index], color="red", s=40)

plt.show()

print(f"當w={ws[w_index]}, b={bs[b_index]} 會有最小cost:{costs[w_index, b_index]}")
#endregion
