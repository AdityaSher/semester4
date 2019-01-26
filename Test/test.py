import RPi.GPIO as io
import time
io.setmode(io.BOARD)
x=io.setup(15, io.IN)
io.setup(22, io.IN)

while(1):

    if io.input(15):
        print('Input was 15HIGH')
        break
        print("15")
    else:
        print('Input was 15LOW')
    
    if io.input(22):
        print('Input was 22HIGH')
        break
        print("22")
    
    else:
        print('Input was 22LOW')

"""
while(1):

    if(x == 1):
        print(x)
        print("Success")
        break
    print("f")
"""
