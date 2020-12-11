import random
for i in range(100):
    if(i<10):
        inputfile = "input00" + str(i) + ".txt"
    else:
        inputfile = "input0" + str(i) + ".txt"
    inpf = open(inputfile, mode="w")
    inpf.write(str((i+1)*10000)+'\n')
    for j in range((i+1)*10000):
        x = random.randint(-100, 100)
        inpf.write(str(x)+ " ")
    inpf.close()
    