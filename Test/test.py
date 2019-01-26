import RPi.GPIO as io
import time
io.setmode(io.BOARD)
io.setup(22, io.IN)


x=io.input(22)
print(x)
time.sleep(2)
