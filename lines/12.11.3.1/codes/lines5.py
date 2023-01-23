import numpy as np
n=[]
for i in range(3):
	n.append(int(input('enter array elements:')))
n=np.array(n)
c=int(input('enter constant value:'))
magn=np.linalg.norm(n)
e=np.eye(3,dtype=int)


# direction cosines
for i in range(len(n)):
	print(((e[i].T)@n)/(magn*(np.linalg.norm(e[i]))))

#distance from origin
print(c/magn)	
