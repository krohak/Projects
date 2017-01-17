# Projects

**A repository containing some of the code I've written/experimented with over the past few years.**

## Arduino

### [HKIE_Linus](https://github.com/krohak/Projects/blob/master/Arduino/HKIE_Linus/HKIE_Linus.ino)

**[Video](https://www.instagram.com/p/2ocdYKlCXW/)**

[<img src="https://raw.githubusercontent.com/krohak/Projects/master/Arduino/HKIE_Linus/hkie.jpg" width="400px">](https://www.instagram.com/p/2ocdYKlCXW/)

Line-Following Car built for the finals of 'Ambitions', a competition organized by The Hong Kong Institute of Engineers. The Car, Linus, uses two infrared sensors at the front to detect the line and two servo motors attached to a motor controller board for autonomous control. Linus made a place for itself amongst the finalists.

### [Rube_Goldberg](https://github.com/krohak/Projects/blob/master/Arduino/Rube_Goldberg/Rube_Goldberg.ino)

**[Video](https://www.youtube.com/watch?v=huZIT-BSQT0)**

[<img src="http://img.youtube.com/vi/huZIT-BSQT0/0.jpg" width="400px">](https://www.youtube.com/watch?v=huZIT-BSQT0)

The code for a Rube Goldberg machine built for the final project of my Intro to Electrical and Electronics Engineering course at The University of Hong Kong.

### [Ard_Calculator](https://github.com/krohak/Projects/blob/master/Arduino/Ard_Calculator/Ard_Calculator.ino)

A very basic Arduino sketch for a Calculator using DTMF as input and four 7-Segment LED displays as output.

### [Batsignal](https://github.com/krohak/Projects/blob/master/Arduino/Batsignal/Batsignal.ino)

**[Video](https://www.youtube.com/watch?v=WW_cGdG26EU)**

[<img src="https://pbs.twimg.com/profile_banners/3312354553/1439293197" width="400px">](https://www.youtube.com/watch?v=WW_cGdG26EU)

Custom Batman Logo programmed on Arduino Uno. It creates custom characters using 8 byte arrays to display the design on the 20x4 LCD screen.

### [Snake](https://github.com/krohak/Projects/blob/master/Arduino/Snake/Snake.ino)

**[Video](https://www.instagram.com/p/39gnu1FCfa/)**

Arduino version of the classic game Snake.

### [Pong](https://github.com/krohak/Projects/blob/master/Arduino/Snake/Snake.ino)

**[Video](https://www.instagram.com/p/3gSbgblCcf/)**

Arduino version of the classic game 'Pong' using 16x2 LCD. Input from DTMF, a small buzzer in use for random 8-bit sound effects.


## Code


### [HKU](https://github.com/krohak/Projects/blob/master/Code/HKU/hku.py)

A script for [lazy] students from HKU to enroll in the pre-selected courses (from the temporary course list) during the add/drop period. Since I didn't have access to internet during the latest add/drop period, I wrote this code and scheduled it to run on a server.

### [NIFTY](https://github.com/krohak/Projects/blob/master/Code/NIFTY/nseLTP_xl.py)

A web scraping program to plot the growth of [LTP](http://budgeting.thenest.com/ltp-stock-market-26186.html) (Last Trade Price) over time for a given [Strike Price](http://www.investopedia.com/terms/s/strikeprice.asp) of [NIFTY](https://en.wikipedia.org/wiki/NIFTY_50) on The National Stock Exchange of India (NSE)'s [website](https://www.nseindia.com/).

It takes data (Strike Price and its Expiry) from two Excel sheets ([CALL.xlsx](https://github.com/krohak/Projects/blob/master/Code/NIFTY/CALL.xlsx) and [PUT.xlsx](https://github.com/krohak/Projects/blob/master/Code/NIFTY/PUT.xlsx)), finds the corresponding [table](https://www.nseindia.com/live_market/dynaContent/live_watch/option_chain/optionKeys.jsp?symbolCode=-10003&symbol=NIFTY&symbol=NIFTY&instrument=-&date=-&segmentLink=17&symbolCount=2&segmentLink=17) on the website and appends the multiple LTPs and the present day's NIFTY value in those excel sheets. Lastly, it outputs two graphs inside [CALLchart.xlsx](https://github.com/krohak/Projects/blob/master/Code/NIFTY/CALLchart.xlsx) and [PUTchart.xlsx](https://github.com/krohak/Projects/blob/master/Code/NIFTY/PUTchart.xlsx) which outlines the growth of LTPs of the various Strike Prices over time.


## Kinect


### [DepthImage_CNN](https://github.com/krohak/Projects/tree/master/Kinect/DepthImage_CNN)

**[Video](https://www.instagram.com/p/BJ2ibjVj62a/)**

[<img src="https://github.com/krohak/Projects/blob/master/Kinect/DepthImage_CNN/simple_depth_image/cnn.gif" width="400px">](https://www.instagram.com/p/BJ2ibjVj62a/)

This is an experiment which combines the Depth Image captured from a Kinect Sensor with a Convolutional Neural Network, made for the purpose of recreating artistic styles of paintings.

### [Pen_kinect](https://github.com/krohak/Projects/blob/master/Kinect/Pen_kinect/Pen_kinect.pde)

Processing code for a simple application which detects the closest object in front of the Kinect Sensor and tracks the object, thus drawing a line on screen. The closer the object is, the thicker the line would be.


## Raspberry Pi


### [Rpi-Arduino](https://github.com/krohak/Projects/tree/master/Raspberry%20Pi/Arduino)

For communication between Arduino and Rpi.

### [Python](https://github.com/krohak/Projects/tree/master/Raspberry%20Pi/Python)

Various misc. Python programs on Rpi.

### [SimpleCV](https://github.com/krohak/Projects/tree/master/Raspberry%20Pi/SimpleCV)

SimpleCV is a Python library for Image Processing. This folder contains code which utilize it to manipulate images and for motion sensing.

### [Twython](https://github.com/krohak/Projects/tree/master/Raspberry%20Pi/Twython)

Python library for Twitter API. Folder contains code for Twitter keyword search and update.
