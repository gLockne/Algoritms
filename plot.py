import matplotlib.pyplot as plt
from array import *
x = []
y = []
for j in range(100):
    if(j<10):
        inputfile = "output00" + str(j) + ".txt"
    else:
        inputfile = "output0" + str(j) + ".txt"
    outf = open(inputfile, mode="r")
    outf.read(11) #не знаю как подругому считывать нужныее символы
    #print(outf.read(8))
    x.append(j*10000)
    y.append(float(outf.read(8)))
plt.plot(x, y)
plt.show()