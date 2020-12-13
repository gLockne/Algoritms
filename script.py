import subprocess
from subprocess import PIPE

import matplotlib.pyplot as plt
#name = "shellsort"
#name = "qsort"
#name = "introsort"
name = "piramidal"
compilation = subprocess.run("gcc -o " + name + ".exe " + name + ".c")
for i in range(100):
    if(i<10):
        proc = subprocess.Popen(name + ".exe " + "input00" + str(i) + ".txt", stdout=PIPE)
    else:
        proc = subprocess.Popen(name + ".exe " + "input0" + str(i) + ".txt", stdout=PIPE)
    out, err = proc.communicate()
    mf = out.decode("utf-8")
    if(i<10):
        output = open("output00" + str(i) + ".txt", "w")
    else:
        output = open("output0" + str(i) + ".txt", "w")
    output.write(mf)
    output.close()

print("test outs...")

for j in range(100):
    if(j<10):
        inputfile = "output00" + str(j) + ".txt"
    else:
        inputfile = "output0" + str(j) + ".txt"
    outf = open(inputfile, mode="r")
    x = -200000
    n = 1
    for line in outf:
        if(line[0] != "T"):
            if(line != "\n"):
                if(x>int(line)):
                    print("ALERT")
                    n = 0
                x = int(line)
    if(n != 1):
        print("ALERT in " + inputfile)

    outf.close()