import matplotlib.pyplot as plt
import numpy as np
import math as ma
from matplotlib import pyplot as plt, patches
import math
import subprocess
import shlex
import warnings
warnings.simplefilter(action='ignore', category=FutureWarning)



def line_gen(A,B):
    len=10
    dim = A.shape[0]
    x_AB = np.zeros((dim,len))
    lam_1 = np.linspace(0,1,len)
    for i in range(len):
        temp1 = A + lam_1[i]*(B-A)
        x_AB[:,i] = temp1.T
    return x_AB
    




A = np.loadtxt('a.dat',dtype='float') 


# a) for line x−sqrt(3)y+8 = 0
x1 = np.loadtxt('x1.dat',dtype='float')
y1 = np.loadtxt('y1.dat',dtype='float')
B1 = np.loadtxt('b1.dat',dtype='float')  
plt.figure(1)
x_AB1=line_gen(A,B1)
x_x1y1=line_gen(x1,y1)
plt.plot(x_AB1[0,:],x_AB1[1,:],label='d1=4')
plt.plot(x_x1y1[0,:],x_x1y1[1,:],label='line')
sqr_vert = np.vstack((A,B1,x1,y1)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])
vert_labels = ['(0,0)  theta=120deg']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
            (sqr_vert[0,i], sqr_vert[1,i]),
            textcoords = 'offset points',
            xytext = (0,10),
            ha='center')
plt.legend()
plt.grid()

# b) for line y-2=0
x2 = np.loadtxt('x2.dat',dtype='float')
y2 = np.loadtxt('y2.dat',dtype='float') 
B2 = np.loadtxt('b2.dat',dtype='float') 
plt.figure(2)
x_AB2=line_gen(A,B2)
x_x2y2=line_gen(x2,y2)
plt.plot(x_AB2[0,:],x_AB2[1,:],label='d2=1')
plt.plot(x_x2y2[0,:],x_x2y2[1,:],label='line')
sqr_vert = np.vstack((A,B2)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])
vert_labels = ['(0,0) theta=90deg']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
            (sqr_vert[0,i], sqr_vert[1,i]),
            textcoords = 'offset points',
            xytext = (0,10),
            ha='center')

plt.legend()
plt.grid()

# c) for line x-y=4
x3 = np.loadtxt('x3.dat',dtype='float')
y3 = np.loadtxt('y3.dat',dtype='float') 
B3 = np.loadtxt('b3.dat',dtype='float') 
plt.figure(3)
x_AB3=line_gen(A,B3)
x_x3y3=line_gen(x3,y3)
plt.plot(x_AB3[0,:],x_AB3[1,:],label='d3=2.82')
plt.plot(x_x3y3[0,:],x_x3y3[1,:],label='line')
sqr_vert = np.vstack((A,B3,x3,y3)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])
vert_labels = ['(0,0) theta=315deg']

for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
            (sqr_vert[0,i], sqr_vert[1,i]),
            textcoords = 'offset points',
            xytext = (0,10),
            ha='center')
plt.legend()
plt.grid()
plt.show()
            





