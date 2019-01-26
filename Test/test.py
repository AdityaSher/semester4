import RPi.GPIO as io

io.setmode(io.BOARD)
io.setup(22, io.OUT)

io.output(22, not io.input(22))
