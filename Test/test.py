import RPi.GPIO as io
import time
io.setmode(io.BOARD)
io.setup(22, io.IN)

while(1):
    x=io.input(22)    
    print(x)
    if(x==1):
        print("high")
        break
