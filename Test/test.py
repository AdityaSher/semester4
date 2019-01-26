import RPi.GPIO as io

io.setmode(io.BOARD)
x=io.setup(15, io.IN)
io.setup(22, io.IN)

while(1):
    if io.input(22):
        print('Input was HIGH')
        break

"""
while(1):

    if(x == 1):
        print(x)
        print("Success")
        break
    print("f")
"""
