import RPi.GPIO as io

io.setmode(io.BOARD)
x=io.setup(15, io.OUT)

if io.input(15):
    print('Input was HIGH')
else:
    print('Input was LOW')

if io.input(22):
    print('Input was HIGH')
else:
    print('Input was LOW')

"""
while(1):

    if(x == 1):
        print(x)
        print("Success")
        break
    print("f")
"""
