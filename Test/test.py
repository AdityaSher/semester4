import RPi.GPIO as io
import time 
io.setmode(io.BOARD)
x=io.setup(15, io.IN)
io.setup(22, io.IN)

while(1):

    """if io.input(15):
        print('Input was HIGH')
    else:
        print('Input was LOW')
    """
    if io.input(22):
        #time.sleep(2)
        print('Input was HIGH')
        break
    
    """
    else:
        print('Input was LOW')
    """  

"""
while(1):

    if(x == 1):
        print(x)
        print("Success")
        break
    print("f")
"""
