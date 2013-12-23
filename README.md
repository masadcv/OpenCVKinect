// *******************************************************************************
//	OpenCVKinect: Provides method to access Kinect Color and Depth Stream        *
//				  in OpenCV Mat format.                                           *
//                                                                                *
//				  Pre-requisites: OpenCV_2.x, OpenNI_2.x, KinectSDK_1.8           *
//                                                                                *
//   Copyright (C) 2013  Muhammad Asad                                            *
//                       Webpage: http://seevisionc.blogspot.co.uk/p/about.html   *
//						 Contact: masad.801@gmail.com                             *
//                                                                                *
//   This program is free software: you can redistribute it and/or modify         *
//   it under the terms of the GNU General Public License as published by         *
//   the Free Software Foundation, either version 3 of the License, or            *
//   (at your option) any later version.                                          *
//                                                                                *
//   This program is distributed in the hope that it will be useful,              *
//   but WITHOUT ANY WARRANTY; without even the implied warranty of               *
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                *
//   GNU General Public License for more details.                                 *
//                                                                                *
//   You should have received a copy of the GNU General Public License            *
//   along with this program.  If not, see <http://www.gnu.org/licenses/>.        *
//                                                                                *
// *******************************************************************************

OpenCVKinect
============

Code for acquiring Depth and Color streams from Kinect sensor in OpenCV Mat format.

Pre-requisites
==============
- Kinect 1.x SDK
- OpenNI 2.x SDK
- OpenCV 2.x
- Kinect Sensor


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



