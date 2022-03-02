PORT=/dev/cu.usbmodem1101

image:
	arduino-cli compile -e -b arduino:samd:mkrwifi1010 -v

install:
	arduino-cli core install arduino:samd
	arduino-cli lib install ArduinoMotorCarrier

flash:
	arduino-cli upload -b arduino:samd:mkrwifi1010 -p $(PORT) -v

image_flash:
	arduino-cli compile -u -e -b arduino:samd:mkrwifi1010 -p $(PORT) -v

monitor:
	arduino-cli monitor -p $(PORT)