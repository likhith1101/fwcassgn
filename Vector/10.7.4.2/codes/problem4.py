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




x=int(input('if x ='))
y=int(input('if y ='))
A = np.array(([x,y]))
B = np.array(([1,2]))
C = np.array(([7,0]))


area=0.5*(np.linalg.norm(np.cross((A-B),(A-C))))
pointsA='x={x:},y={y:}'
if area==0:
	print('collinear because ar(ABC) is zero for'+pointsA.format(x=x,y=y))
else:
	print('not collinear because ar(ABC) not equal to zero for'+pointsA.format(x=x,y=y))



#line generation with the calculated distances(d1,d2,d3)
x_AB = line_gen(A,B)
x_BC = line_gen(B,C)
x_CA = line_gen(C,A)




plt.plot(x_AB[0,:],x_AB[1,:],label='$distance(AB)$')
plt.plot(x_BC[0,:],x_BC[1,:],label='$distance(BC)$')
plt.plot(x_CA[0,:],x_CA[1,:],label='$distance(CA)$')

sqr_vert = np.vstack((A,B,C)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])
textA='A(x={x:},y={y:})'
vert_labels = [textA.format(x=x,y=y),'B(1,2)','C(7,0)']

for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
            (sqr_vert[0,i], sqr_vert[1,i]),
            textcoords = 'offset points',
            xytext = (0,10),
            ha='center')


plt.xlabel('$x$')                    
plt.ylabel('$y$')
if area==0:
	plt.legend(['ar(ABC) = 0, is collinear for '+pointsA.format(x=x,y=y)])
else:
	plt.legend(['ar(ABC) != 0, is not collinear for '+pointsA.format(x=x,y=y)])
plt.grid()
plt.axis('equal')
#if using termux
#plt.savefig('/sdcard/download/fwcassgn/trunk/fwcassgn/trunk/vectors/7.2.3/figs/trigraph.png')
#subprocess.run(shlex.split("termux-open /sdcard/download/fwcassgn/trunk/fwcassgn/trunk/vectors/7.2.3/figs/trigraph.png"))
plt.show()
