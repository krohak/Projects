from SimpleCV import Image, Color, Display
from time import sleep
import sys

display = Display()
# Load an image from imgur.
img = Image('http://i.imgur.com/lfAeZ4n.png')
# binarize the image using a threshold of 90 
# and invert the results.
output = img.binarize(90).invert()
# create the side by side image.
result = output
result.save('juniperbinary.png')

# show the resulting image.

result.save(display)

try:
	while not display.isDone():
		sleep(0.1)
	

except KeyboardInterrupt:
	sys.exit()

# save the results to a file. 
