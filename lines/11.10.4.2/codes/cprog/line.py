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
B = np.loadtxt('result.dat',dtype='float') 
C = np.loadtxt('x.dat',dtype='float')
D = np.loadtxt('y.dat',dtype='float')  

x_AB=line_gen(A,B)
x_CD=line_gen(C,D)

plt.plot(x_AB[0,:],x_AB[1,:],label='AB')
plt.plot(x_CD[0,:],x_CD[1,:],label='CD')
sqr_vert = np.vstack((A,B,C,D)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])
vert_labels = ['A(0,0)','B','C','D']

for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
            (sqr_vert[0,i], sqr_vert[1,i]),
            textcoords = 'offset points',
            xytext = (0,10),
            ha='center')

plt.grid()
plt.axis('equal')
#if using termux
#plt.savefig('/sdcard/download/fwcassgn/trunk/fwcassgn/trunk/line/11.10.4.2/figs/line.png')
#subprocess.run(shlex.split("termux-open /sdcard/download/fwcassgn/trunk/fwcassgn/trunk/line/11.10.4.2/figs/line.png"))

plt.show()
