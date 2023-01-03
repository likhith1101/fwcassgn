import numpy as np
import matplotlib.pyplot as plt
import matplotlib
import subprocess
import shlex
import warnings
warnings.simplefilter(action='ignore', category=FutureWarning)

#line generation function
def line_gen(A,B,len):
    dim = A.shape[0]
    x_AB = np.zeros((dim,len))
    lam_1 = np.linspace(0,1,len)
    for i in range(len):
        temp1 = A + lam_1[i]*(B-A)
        x_AB[:,i] = temp1.T
    return x_AB





A = np.array(([2,3]))
B = np.array(([4,1]))
C = np.array(([-5,7]))
D = np.array(([-1,3]))
a=int(input('if a='))
b=int(input('if b='))
E = np.array(([a,b]))
F = np.array(([-a,-b]))


d1=np.linalg.norm(A-B) #calculating distance between A and B    
print('d1=',d1)

d2=np.linalg.norm(C-D) #calculating distance between C and D 
print('d2=',d2)


d3=np.linalg.norm(E-F) #calculating distance between E and F 
print('d3=',d3)



#line generation with the calculated distances(d1,d2,d3)
x_AB = line_gen(A,B,int(d1))
x_CD = line_gen(C,D,int(d2))
x_EF = line_gen(E,F,int(d3))




plt.plot(x_AB[0,:],x_AB[1,:],label='$distance(AB)$')
plt.plot(x_CD[0,:],x_CD[1,:],label='$distance(CD)$')
plt.plot(x_EF[0,:],x_EF[1,:],label='$distance(EF)$')



sqr_vert = np.vstack((A,B,C,D,E,F)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])
textE='E(a={a:},b={b:})'
textF='F(a={a:},b={b:})'
vert_labels = ['A(2,3)','B(4,1)','C(-5,7)','D(-1,3)',textE.format(a=a,b=b),textF.format(a=-a,b=-b)]

for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
            (sqr_vert[0,i], sqr_vert[1,i]),
            textcoords = 'offset points',
            xytext = (0,10),
            ha='center')


plt.xlabel('$x$')                    
plt.ylabel('$y$')
plt.legend(['d1($AB$)='+str(d1),'d2($CD$)='+str(d2),'d3($EF$)='+str(d3)])
plt.grid()
plt.axis('equal')
#if using termux
plt.savefig('/sdcard/download/fwcassgn/trunk/vectors/7.1/figs/graph.png')
subprocess.run(shlex.split("termux-open /sdcard/download/fwcassgn/vectors/7.1/figs/graph.png"))
plt.show()
