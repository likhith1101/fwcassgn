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
    
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

x = np.linspace(-5,5,100)
A=np.array(([0,0]))
theta1 = np.pi*2/3
theta2 = np.pi/2
theta3 = np.pi*7/4
d1=4
d2=2
d3=2*(ma.sqrt(2))
B1 = d1*np.array(([np.cos(theta1),np.sin(theta1)]))
B2 = d2*np.array(([np.cos(theta2),np.sin(theta2)]))
B3 = d3*np.array(([np.cos(theta3),np.sin(theta3)]))
x_AB1=line_gen(A,B1)

plt.plot(x_AB1[0,:],x_AB1[1,:],label='d1={}'.format(d1))
sqr_vert = np.vstack((A,B1)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])
vert_labels = ['(0,0)  theta=120deg']

for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
            (sqr_vert[0,i], sqr_vert[1,i]),
            textcoords = 'offset points',
            xytext = (0,10),
            ha='center')
y = (1/ma.sqrt(3))*x+8/(ma.sqrt(3))
plt.plot(x, y, '-r', label='y=x/sqrt(3)+8/sqrt(3)')

plt.xlabel('x', color='#1C2833')
plt.ylabel('y', color='#1C2833')
plt.legend(loc='upper left')




plt.grid()
plt.show()
            
x_AB2=line_gen(A,B2)
plt.plot(x_AB2[0,:],x_AB2[1,:],label='d2={}'.format(d2))
sqr_vert = np.vstack((A,B2)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])
vert_labels = ['(0,0) theta=90deg']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
            (sqr_vert[0,i], sqr_vert[1,i]),
            textcoords = 'offset points',
            xytext = (0,10),
            ha='center')
y = 0*x+2
plt.plot(x, y, '-r', label='y=2')
plt.xlabel('x', color='#1C2833')
plt.ylabel('y', color='#1C2833')
plt.legend(loc='upper left')




plt.grid()
plt.show()

x_AB3=line_gen(A,B3)
plt.plot(x_AB3[0,:],x_AB3[1,:],label='d3={}'.format(d3))
sqr_vert = np.vstack((A,B3)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])
vert_labels = ['(0,0) theta=315deg']

for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
            (sqr_vert[0,i], sqr_vert[1,i]),
            textcoords = 'offset points',
            xytext = (0,10),
            ha='center')
x = np.linspace(-5,5,100)
y = x-4
plt.plot(x, y, '-r', label='y=x-4')
plt.xlabel('x', color='#1C2833')
plt.ylabel('y', color='#1C2833')
plt.legend(loc='upper left')




plt.grid()
#if using termux
#plt.savefig('/sdcard/download/fwcassgn/trunk/fwcassgn/trunk/vectors/7.2.3/figs/trigraph.png')
#subprocess.run(shlex.split("termux-open /sdcard/download/fwcassgn/trunk/fwcassgn/trunk/vectors/7.2.3/figs/trigraph.png"))
plt.show()

