import numpy as np
n=[]
for i in range(3):
	n.append(int(input('enter array elements:')))
n=np.array(n)
c=int(input('enter constant value:'))
magn=np.linalg.norm(n)


#distance from origin
print(c/magn)	
