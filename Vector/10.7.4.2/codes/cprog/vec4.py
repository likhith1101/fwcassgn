import numpy as np
import matplotlib.pyplot as plt
import matplotlib
import subprocess
import shlex
import warnings
warnings.simplefilter(action='ignore', category=FutureWarning)

#line generation function
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
B = np.loadtxt('b.dat',dtype='float')
C = np.loadtxt('c.dat',dtype='float')
rank = np.loadtxt('rank.dat',dtype='int')
#F = np.loadtxt('result.dat',dtype='float')


#line generation with the calculated distances(d1,d2,d3)
x_AB = line_gen(A,B)
x_BC = line_gen(B,C)
x_CA = line_gen(C,A)




plt.plot(x_AB[0,:],x_AB[1,:],label='$distance(AB)$')
plt.plot(x_BC[0,:],x_BC[1,:],label='$distance(BC)$')
plt.plot(x_CA[0,:],x_CA[1,:],label='$distance(CA)$')

sqr_vert = np.vstack((A,B,C)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])

vert_labels = ['A(-2,3)','B(1,2)','C(7,0)']

for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
            (sqr_vert[0,i], sqr_vert[1,i]),
            textcoords = 'offset points',
            xytext = (0,10),
            ha='center')


if rank==1:
	plt.legend(['rank(F) = 1, is collinear'])
else:
	plt.legend(['rank(F) != 1, is not collinear'])

plt.xlabel('$x$')                    
plt.ylabel('$y$')

plt.grid()
plt.axis('equal')
#if using termux
plt.savefig('/sdcard/download/fwcassgn/trunk/fwcassgn/trunk/vectors/10.7.4.2/figs/fig.png')
#subprocess.run(shlex.split("termux-open /sdcard/download/fwcassgn/trunk/fwcassgn/trunk/vectors/10.7.4.2/figs/fig.png"))
plt.show()

