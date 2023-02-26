import math as ma
import numpy as np
import mpmath as mp
import math
import matplotlib.pyplot as plt
from numpy import linalg as LA



#if using termux
import subprocess
import shlex
#end if

def circ_gen(O,r):
    len = 50
    theta = np.linspace(0,2*np.pi,len)
    x_circ = np.zeros((2,len))
    x_circ[0,:] = r*np.cos(theta)
    x_circ[1,:] = r*np.sin(theta)
    x_circ = (x_circ.T + O).T
    return x_circ




def line_gen(A,B):
  len =10
  dim = A.shape[0]
  x_AB = np.zeros((dim,len))
  lam_1 = np.linspace(0,1,len)
  for i in range(len):
    temp1 = A + lam_1[i]*(B-A)
    x_AB[:,i]= temp1.T
  return x_AB
 
def conic_quad(q,V,u,f):
    return q@V@q + 2*u@q + f

 
def inter_pt(m,q,V,u,f):
    a = m@V@m
    b = m@(V@q+u)
    c = conic_quad(q,V,u,f)
    l1,l2 =np.roots([a,2*b,c])
#    print(a,b,c)
    x1 = q+l1*m
    x2 = q+l2*m
    return x1,x2

 
def line_dir_pt(m,A,k1,k2):
  len = 10
  dim = A.shape[0]
  x_AB = np.zeros((dim,len))
  lam_1 = np.linspace(k1,k2,len)
  for i in range(len):
    temp1 = A + lam_1[i]*m
    x_AB[:,i]= temp1.T
  return x_AB

r1= np.loadtxt('r1.dat',dtype='int')
r2= np.loadtxt('r2.dat',dtype='int')
A = np.loadtxt('a.dat',dtype='float')
B = np.loadtxt('b.dat',dtype='float')
C = np.loadtxt('c.dat',dtype='float')
D = np.loadtxt('d.dat',dtype='float')
X=C
X1=D
##Generating the lines

xAC = line_gen(A,C)
xXX1=line_gen(X,X1)
xAD = line_gen(A,D)
xAB = line_gen(A,B)
xBC = line_gen(B,C)
xBD = line_gen(B,D)

##Generating the circle
x_circ1= circ_gen(A,r1)
x_circ2= circ_gen(B,r2)

plt.plot(x_circ1[0,:],x_circ1[1,:],label='Circle1')                               
plt.plot(x_circ2[0,:],x_circ2[1,:],label='Circle2')

plt.plot(xAC[0,:],xAC[1,:],label='')
plt.plot(xXX1[0,:],xXX1[1,:],label='line x')
plt.plot(xAD[0,:],xAD[1,:],label='')
plt.plot(xAB[0,:],xAB[1,:],label='')
plt.plot(xBC[0,:],xBC[1,:],label='')
plt.plot(xBD[0,:],xBD[1,:],label='')



#Labeling the coordinates
tri_coords = np.vstack((A,B,C,D,X,X1)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A','B','C','D','','']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(0,10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

#if using termux
#plt.savefig('/sdcard/download/fwcassgn/trunk/fwcassgn/trunk/circles/9.10.6.1/figs/circle3.png')
#else
plt.show()
