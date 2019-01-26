import RPi.GPIO as io

io.setmode(io.BOARD)
io.setup(22, io.OUT)

x = io.output(22, not io.input(22))

do{
    if(x != 1)
    {
        print(x)
    }
}
while(x != 1)
