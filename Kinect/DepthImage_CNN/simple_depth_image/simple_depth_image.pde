/***********************************
*
* Processing code for displaying the Depth Image and RGB Image from the Kinect sensor. 
*
* Modified version of the code taken from the book 'Making Things See' by 
* Greg Boreinstein. Works on Processing v2.2.1 
*
*@krohak
***********************************/

import SimpleOpenNI.*;
SimpleOpenNI kinect;

void setup()
{

size(640*2, 480);
kinect = new SimpleOpenNI(this);

kinect.enableDepth();
kinect.enableRGB();

}
void draw()
{

kinect.update();

image(kinect.depthImage(), 0, 0);
image(kinect.rgbImage(), 640, 0);

}
