/***********************************
*
* Processing code for a simple application which detects the closest 
* object in front of the Kinect Sensor and tracks the object, thus drawing 
* a line on screen. The closer the object is, the thicker the line would be.
*
* Modified version of the code taken from the book 'Making Things See' by 
* Greg Boreinstein. Works on Processing v2.2.1 
*
*@krohak
***********************************/
import SimpleOpenNI.*;
SimpleOpenNI kinect;


int closestValue;
int closestX;
int closestY;
float lastX;
float lastY;
float lastZ;
int thick;
void setup()
{
size(640, 480);
kinect = new SimpleOpenNI(this);
kinect.enableDepth();
//black background
background(0);
}
void draw()
{
closestValue = 8000;
kinect.update();
int[] depthValues = kinect.depthMap();
for(int y = 0; y < 480; y++){
for(int x = 0; x < 640; x++){ 

  
int i = x + y * 640;
int currentDepthValue = depthValues[i];


if(currentDepthValue > 610 && currentDepthValue < 1525 
&& currentDepthValue < closestValue){
closestValue = currentDepthValue;
closestX = x;
closestY = y;

float interpolatedZ = lerp(lastZ, closestValue, 0.3f);

int cValue = (1525 - (int)interpolatedZ) + 610;

float inches = cValue/25.4;

int thickness = ((((int)inches-2)*3)/3);  //thickness calculated on the basis of Z-Axis

thick = thickness;

}
}
}


float interpolX = lerp(lastX, closestX, 0.3f); 
float interpolY = lerp(lastY, closestY, 0.3f);

stroke(255,0,0);




strokeWeight(thick);
line(lastX, lastY, interpolX, interpolY); 
lastX = interpolX;
lastY = interpolY;
lastZ = closestValue;
}
void mousePressed(){  //clear screen

background(0);
}