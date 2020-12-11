import subprocess
from subprocess import PIPE
#name = "shellsort"
name = "qsort"
#name = "introsort"
#name = "piramidal"
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
    x = -200
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
#process = subprocess.Popen("Shell Sort.exe " + "input001.txt", stdout=PIPE)
#out, err = process.communicate()
#to_file = out.decode("utf-8")
#output_txt = open("output001.txt", "w")
#output_txt.write(to_file)
#output_txt.close()
#from subprocess import PIPE
#import sys
#process = subprocess.Popen(['Shell Sort.exe'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
#f = open('input001.txt', 'r')
#result = subprocess.run(['Shell Sort.exe'], input=0)
#stdout, stderr = process.communicate()
#print(stdout)
#print(stderr)
#result = subprocess.run(
#    [sys.executable, "-c", "import sys; print(sys.stdin.read())"], input=f.read()
#)
#from subprocess import Popen, PIPE

#p = Popen(['Shell Sort.exe', 'input001.txt'], stdin=PIPE, stdout=PIPE, stderr=PIPE)
#output, err = p.communicate(b"input data that is passed to subprocess' stdin")
#rc = p.returncode
#print()
#from subprocess import PIPE, run
#inp = f.read() 
#command = ['Shell Sort.exe']
#result = run(command, stdin=int(inp), stdout=PIPE, stderr=PIPE, universal_newlines=True)
#print(result.returncode, result.stdout, result.stderr)
#subprocess.call(['Shell Sort.exe', '0'])
