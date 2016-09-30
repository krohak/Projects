from SimpleCV import Image,Color,Display
from time import sleep
img = Image('http://i.imgur.com/lfAeZ4n.png')
# create an edge image using the Canny edge detector
# set the first threshold to 160
output = img.edges(t1=160)
# generate the side by side image.
result = output
# show the results.
# save the output images. 
result.save('juniperedges.png')

while 1:

	result.show()
	sleep(11111111111)
