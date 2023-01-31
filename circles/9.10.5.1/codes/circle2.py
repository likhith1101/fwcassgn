import numpy as np
import mpmath as mp
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

r=1
O=np.array(([0,0]))  

C=e1

alphadeg = 30
alpha= alphadeg*np.pi/180
ac = 2*r*np.sin(alpha/2)
B =  np.array(([np.cos(alpha),np.sin(alpha)]))

betadeg = 60
phideg = alphadeg+betadeg
phi = phideg*np.pi/180
ab = 2*r*np.sin(phi/2)
A=  np.array(([int(np.cos(phi)),int(np.sin(phi))]))

gammadeg = 45
gamma = gammadeg*np.pi/180
bd = 2*r*np.sin(gamma/2)
D =  np.array(([-np.cos(gamma),-np.sin(gamma)]))





#Proof of the problem
#angle ADC

m1=A-D
m2=C-D
x=((m1.T)@m2)/(LA.norm(m1) * LA.norm(m2))
angle=mp.acos(x)*(180/np.pi)

print(angle)




##Generating the li

xOC = line_gen(O,C)
xOA = line_gen(O,A)
xOB = line_gen(O,B)
xCD = line_gen(C,D)
xAD = line_gen(A,D)

##Generating the circle
x_circ= circ_gen(O,r)

#Plotting all lines
plt.plot(xOA[0,:],xOA[1,:],label='OA')
plt.plot(xOB[0,:],xOB[1,:],label='OB')
plt.plot(xOC[0,:],xOC[1,:],label='OC')
plt.plot(xCD[0,:],xCD[1,:],label='CD')
plt.plot(xAD[0,:],xAD[1,:],label='AD')

#Plotting the circle
plt.plot(x_circ[0,:],x_circ[1,:],label='Circle')


#Labeling the coordinates
tri_coords = np.vstack((O,A,B,C,D)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['O','A','B','C','D']
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
plt.savefig('/sdcard/download/fwcassgn/trunk/fwcassgn/trunk/circles/9.10.5.1/figs/circle2.png')
#else
plt.show()
