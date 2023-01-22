import numpy as np
import math as ma

# Define the vector
A = np.array(np.round_([(12/13), ((-3)/13), ((-4)/13)]))
B  = np.array(np.round_([(4/13),(12/13),(3/13)]))
C  = np.array(np.round_([(3/13),((-4)/13),(12/13)]))
P=np.array([A,B,C])
I=(np.eye(3, dtype = float))

if ((P.T)@P==I).all():
    print('All three vectors are orthogonal to each other')
else:
    print('Not orthogonal')


