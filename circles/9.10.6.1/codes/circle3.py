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

def get_intersections(x0, y0, r0, x1, y1, r1):
    # circle 1: (x0, y0), radius r0
    # circle 2: (x1, y1), radius r1

    d=math.sqrt((x1-x0)**2 + (y1-y0)**2)
    
    # non intersecting
    if d > r0 + r1 :
        return None
    # One circle within other
    if d < abs(r0-r1):
        return None
    # coincident circles
    if d == 0 and r0 == r1:
        return None
    else:
        a=(r0**2-r1**2+d**2)/(2*d)
        h=math.sqrt(r0**2-a**2)
        x2=x0+a*(x1-x0)/d   
        y2=y0+a*(y1-y0)/d   
        x3=x2+h*(y1-y0)/d     
        y3=y2-h*(x1-x0)/d 

        x4=x2-h*(y1-y0)/d
        y4=y2+h*(x1-x0)/d
        
        return (x3, y3, x4, y4)


def line_gen(A,B):
  len =10
  dim = A.shape[0]
  x_AB = np.zeros((dim,len))
  lam_1 = np.linspace(0,1,len)
  for i in range(len):
    temp1 = A + lam_1[i]*(B-A)
    x_AB[:,i]= temp1.T
  return x_AB
  
def line_dir_pt(m,A,k1,k2):
  len = 10
  dim = A.shape[0]
  x_AB = np.zeros((dim,len))
  lam_1 = np.linspace(k1,k2,len)
  for i in range(len):
    temp1 = A + lam_1[i]*m
    x_AB[:,i]= temp1.T
  return x_AB

I = np.eye(2)
e1 = I[:,0]

r1=4
r2=3
A=np.array(([1,0]))
B=np.array(([5,0]))  

intersects=list((get_intersections(A[0],A[1],r1,B[0],B[1],r2)))

C=intersects[0:2]  
D=intersects[2:]  





m1=A-D
m2=B-D
x=((m1.T)@m2)/(LA.norm(m1) * LA.norm(m2))
angle1=mp.acos(x)*(180/np.pi)

print(angle1)

m3=A-C
m4=B-C
Y=((m3.T)@m4)/(LA.norm(m3) * LA.norm(m4))
angle2=mp.acos(Y)*(180/np.pi)

print(angle2)

if angle1==angle2:
	print('hence proved')


##Generating the li

xAC = line_gen(A,C)
xAD = line_gen(A,D)
xAB = line_gen(A,B)
xBC = line_gen(B,C)
xBD = line_gen(B,D)

##Generating the circle
x_circ1= circ_gen(A,r1)
x_circ2= circ_gen(B,r2)
#Plotting all lines
plt.plot(xAC[0,:],xAC[1,:],label='AC')
plt.plot(xAD[0,:],xAD[1,:],label='AD')
plt.plot(xAB[0,:],xAB[1,:],label='AB')
plt.plot(xBC[0,:],xBC[1,:],label='BC')
plt.plot(xBD[0,:],xBD[1,:],label='BD')
#Plotting the circle
plt.plot(x_circ1[0,:],x_circ1[1,:],label='Circle')
plt.plot(x_circ2[0,:],x_circ2[1,:],label='Circle')

#Labeling the coordinates
tri_coords = np.vstack((A,B,C,D)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A','B','C','D']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(0,10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.xlabel('$x$')
plt.ylabel('$y$')
#plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

#if using termux
#plt.savefig('/sdcard/download/fwcassgn/trunk/fwcassgn/trunk/circles/9.10.5.1/figs/circle2.png')
#else
plt.show()

