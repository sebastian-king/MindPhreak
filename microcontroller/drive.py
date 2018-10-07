import serial
import time

ser=serial.Serial('/dev/ttyUSB0', 115200)  #change ACM number as found from ls /dev/tty/ACM*

print 'connected'
ser.readline()

while True:
	f = open("filedrive.txt", "r")
	drive = f.read()

	if drive == 'STOP':
		print 'stopping'
		ser.write('0 0')
		break

	print 'do: ', drive
	ser.write(drive)

	time.sleep(0.25)

ser.write('0 0');
