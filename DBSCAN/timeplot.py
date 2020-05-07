import matplotlib.pyplot as plt
x=[]
y=[]
f=open("output.txt")
for w in f:
    q=w.split()
    x.append(q[0])
    y.append(q[1])
plt.plot(x,y)   
plt.show()  