import RPi.GPIO as io
import time
io.setmode(io.BOARD)
io.setup(15, io.OUT)
io.setup(22, io.OUT)

while(1):
    print(io.input(15))
    time.sleep(5)
    print(io.input(22))
    break;
    """if io.input(22):
        print('Input was 22HIGH')
        break
        print("22")
    """
    """else:
        print('Input was 22LOW')"""

"""
while(1):

    if(x == 1):
        print(x)
        print("Success")
        break
    print("f")
"""
