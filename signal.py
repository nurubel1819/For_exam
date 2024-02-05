import numpy as np
import matplotlib.pyplot as plt
n = np.arange(-15,15)
print(n)
def findxn(n):
    if(0<=n<=10):return (n*n)+n
    elif(-10<=n<0):return -(n*n)+n
    else:return 0
xn = np.array([])
for a in n:
    xn = np.append(xn,findxn(a))
    print(xn)

a=n[0:n.size-5]
a=np.array(n+5)
a=2*a
print(a)

b = n[0:n.size+5]
b = np.array(n-5)
b = 2*b
print(b)

m = a*b
print(m)

yn = m*xn
print(yn)

yn = np.array(yn*-1)
print(yn)

plt.stem(n,yn)
plt.show()
