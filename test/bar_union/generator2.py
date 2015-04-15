import random

n = 10000
bound = 10000
print(n)
for i in range(n):
   # x0=random.randint(0, bound)
    y0=random.randint(0, bound)
    coef=random.randint(0, 1)
    y1=y0+random.randint(1, bound)
    if not coef:
        coef=-1
    print(y0,y1,coef)
