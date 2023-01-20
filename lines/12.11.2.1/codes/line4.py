import numpy as np
import math as ma

# Define the vector
A = np.array([12/13, -(3/13), -(4/13)])
B  = np.array([4/13,12/13,3/13])
C  = np.array([3/13,-(4/13),12/13])
# Find the magnitude of the vector

a = np.linalg.norm(A)
b = np.linalg.norm(B)
c = np.linalg.norm(C)

# Divide the vector by its magnitude to find the direction cosines
dir_cos1 = ((A.T)@B) / (a*b)
dir_cos2 = ((B.T)@C) / (b*c)
dir_cos3 = ((A.T)@C) / (a*c)

theta1=ma.acos(dir_cos1)*(180.0/ma.pi)
theta2=ma.acos(dir_cos2)*(180.0/ma.pi)
theta3=ma.acos(dir_cos3)*(180.0/ma.pi)
print(theta1,theta2,theta3)

