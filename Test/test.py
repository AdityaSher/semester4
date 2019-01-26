import RPi.GPIO as io
import time
io.setmode(io.BOARD)
io.setup(22, io.IN)

while(1):
    x=io.input(22)    
    time.sleep(1)
    print(x)
