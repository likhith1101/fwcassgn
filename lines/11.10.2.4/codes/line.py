import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
def line_gen(A,B):
   len =10
   dim = A.shape[0]
   x_AB = np.zeros((dim,len))
   lam_1 = np.linspace(0,1,len)
   for i in range(len):
     temp1 = A + lam_1[i]*(B-A)
     x_AB[:,i]= temp1.T
   return x_AB

#input values
p=np.array([2,2*(3**0.5)])
m=(2+3**0.5)

x = np.linspace(2,2*(3**0.5),100)
y = (2+3**0.5)*x-4
plt.plot(x, y, '-r', label='y=(2+sqrt(3))*x-4')
vert_labels = ['(2+sqrt(3))x-y-4=0']
plt.title('Graph of (2+sqrt(3))x-y-4=0')
plt.xlabel('x', color='#1C2833')
plt.ylabel('y', color='#1C2833')
plt.legend(loc='upper left')
plt.grid()
plt.show()
