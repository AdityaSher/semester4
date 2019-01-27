import RPi.GPIO as io
import time
io.setmode(io.BCM)
io.setup(22, io.IN)

time.sleep(5)

while(1):
    x=io.input(22)    
    print(x)
    if(x==1):
        print("high")
        break
