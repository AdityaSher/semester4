import RPi.GPIO as io

io.setmode(io.BOARD)
x=io.setup(15, io.IN)
#x = io.output(15, not io.input(15))


while(1):

    if(x == 1):
        print(x)
        print("Success")
        break
    print("f")

