import numpy as np
import math as ma

# Define the vector
A = np.array([12/13, -(3/13), -(4/13)])
B  = np.array([4/13,12/13,3/13])
C  = np.array([3/13,-(4/13),12/13])
P=np.array([A,B,C])
I=[[1,0,0],[0,1,0],[0,0,1]]
R=(P.T)@P
if int(R[0][0]) and int(R[1][1]) and int(R[2][2])==1:
    print('All three vectors are orthogonal to each other')
else:
    print('Not orthogonal')


