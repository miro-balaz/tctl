import random

n = 10000
bound = 10000
print(n)
for i in range(n):
    x0=random.randint(0, bound)
    y0=random.randint(0, bound)
    x1=x0+random.randint(1, bound)
    y1=y0+random.randint(1, bound)
  
    print(x0,y0,x1,y1)
