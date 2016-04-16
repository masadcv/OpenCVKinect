
OpenCVKinect: Provides method to access Kinect Color and Depth Stream
              in OpenCV Mat format.

OpenCVKinect
============

Code for acquiring Depth and Color streams from Kinect sensor in OpenCV Mat format. 

Pre-requisites
==============

- Kinect 1.x SDK
- OpenNI 2.x SDK
- OpenCV 2.x
- Kinect Sensor

Update 16/04/2016 - The project now includes OpenNI and OpenCV libraries and include files and has been tested on Windows 8.1. This enables it to run with only requiring Kinect 1.8 SDK installation as a pre-requisite. 

Usage
=====

Include the source file in your project and create a class object where data streams are required.

To set up the object call following function in the same order.

setMode(flag) - for specifying the data streams which will be returned

                Possible flag modes for data stream acquisition
                - C_MODE_DEPTH
                - C_MODE_COLOR
                - C_MODE_DEPTH | C_MODE_COLOR
                - C_MODE_DEPTH | C_MODE_COLOR | C_MODE_ALIGNED

init() - initializing the data streams and device drivers
getData() - to get a vector of OpenCV Mat giving Depth and Color streams
getColor() - get Color stream
getDepth() - get Depth stream

          Return a cv::vector <cv::Mat> which can be accessed with index flags
          - C_DEPTH_STREAM
          - C_COLOR_STREAM
          
          example: accessing depth and color stream from cv::vector <cv::Mat> myDataStreams
          - cv::Mat depth = myDataStreams[C_DEPTH_STREAM];
          - cv::Mat color = myDataStreams[C_COLOR_STREAM];

This code includes a sample which demonstrates the functionality of the class.

Update
======
The example code now includes an example to visualize depth map using colormaps similar to matlab figures. 

The update also fixes the following:
- Fix no stream when selecting color or depth stream alone
- Added example for colorizing depth map for better visualization.
- Added OpenCV and OpenNI libraries and include folder - making the project work out-of-the-box only requiring installation of Kinect SDK 1.8.
- Sample data collected using Kinect - includes examples of different visualizations of depth map

Examples
========

<img src="https://github.com/devkicks/OpenCVKinect/blob/master/CollectedSampleData/color/colorAGif.gif" alt="Color Image" width="400"/>
<img src="https://github.com/devkicks/OpenCVKinect/blob/master/CollectedSampleData/colorizedDepth/colorizedDepthAGif.gif" alt="Colorized Depth" width="400"/>


<img src="https://github.com/devkicks/OpenCVKinect/blob/master/CollectedSampleData/color/b/color_00123.png" alt="Color Image" width="200"/>
<img src="https://github.com/devkicks/OpenCVKinect/blob/master/CollectedSampleData/colorizedDepth/b/colorizedDepth_00123.png" alt="Color Image" width="200"/>
<img src="https://github.com/devkicks/OpenCVKinect/blob/master/CollectedSampleData/colorizedDepth/b/colorizedDepth_00126.png" alt="Color Image" width="200"/>
<img src="https://github.com/devkicks/OpenCVKinect/blob/master/CollectedSampleData/colorizedDepth/b/colorizedDepth_00129.png" alt="Color Image" width="200"/>
<img src="https://github.com/devkicks/OpenCVKinect/blob/master/CollectedSampleData/colorizedDepth/b/colorizedDepth_00132.png" alt="Color Image" width="200"/>
<img src="https://github.com/devkicks/OpenCVKinect/blob/master/CollectedSampleData/colorizedDepth/b/colorizedDepth_00134.png" alt="Color Image" width="200"/>
<img src="https://github.com/devkicks/OpenCVKinect/blob/master/CollectedSampleData/colorizedDepth/b/colorizedDepth_00137.png" alt="Color Image" width="200"/>
<img src="https://github.com/devkicks/OpenCVKinect/blob/master/CollectedSampleData/colorizedDepth/b/colorizedDepth_00140.png" alt="Color Image" width="200"/>
<img src="https://github.com/devkicks/OpenCVKinect/blob/master/CollectedSampleData/colorizedDepth/b/colorizedDepth_00143.png" alt="Color Image" width="200"/>
<img src="https://github.com/devkicks/OpenCVKinect/blob/master/CollectedSampleData/colorizedDepth/b/colorizedDepth_00146.png" alt="Color Image" width="200"/>
 


Copyright (C) 2013  Muhammad Asad
- Webpage: http://seevisionc.blogspot.co.uk/p/about.html
- Contact: masad.801@gmail.com


This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.


You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
