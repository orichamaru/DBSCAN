import matplotlib.pyplot as plt
x=[]
y=[]
print('Enter input number')
n = int(input())
f=open("input/input_" + str(n) + ".txt")
plt.plot(x,y,'r.')
for w in f:
    q=w.split()
    x.append(float(q[0]))
    y.append(float(q[1]))
plt.plot(x,y,'r.')
plt.axis([0,100,0,100])
print('These are input nodes\n')
plt.show() 
print('Enter Total clusters formed')
tot = int(input())
temp=[]
col = ['r.', 'y.' , 'b.' ,'g.' , 'm.' , 'k.' , 'c.']
colsize = len(col)
for i in range(1,tot+1):
  f=open("output/ans"+ str(n) + "_" + str(i) + ".txt")
  a=[]
  b=[]
  for w in f:
    q=w.split()
    a.append(float(q[0]))
    b.append(float(q[1]))
  temp.append(a)
  temp.append(b)
# print(temp)
for i in range(0,tot):
  plt.plot(temp[2*i], temp[2*i+1])
plt.axis([0,100,0,100])
plt.show()

