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


#include "OpenCVKinect.h"

void displayIntroAndUsage()
{
	std::cout << "***********************************************************" << std::endl;
	std::cout << "OpenCVKinect Sample Implementation" << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "This example demonstrates the use of OpenCVKinect" << std::endl;
	std::cout << std::endl;

	std::cout << "Flags used: C_MODE_DEPTH -->> Acquire Depth Stream Data" << std::endl;
	std::cout << "            C_MODE_COLOR -->> Acquire Color Stream Data" << std::endl;
	std::cout << "            C_MODE_ALIGNED -->> (Optional) Register Color and Depth Streams for Aligned Frames" << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void displayMenu()
{
	std::cout << "Please select the mode for acquiring data streams from Kinect" << std::endl;
	std::cout << "1. C_MODE_COLOR - Acquire Color Stream only" << std::endl;
	std::cout << "2. C_MODE_DEPTH - Acquire Depth Stream only" << std::endl;
	std::cout << "3. C_MODE_COLOR | C_MODE_DEPTH - Acquire both Color and Depth Streams" << std::endl;
	std::cout << "4. C_MODE_COLOR | C_MODE_DEPTH | C_ALIGNED- Acquire both Color and Depth Streams with registration" << std::endl;
	std::cout << std::endl;
	std::cout << "Please select from option 1-4" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

// colorize depth map based on solution at: http://stackoverflow.com/a/13843342
// possible colorizing options: http://docs.opencv.org/2.4/modules/contrib/doc/facerec/colormaps.html#applycolormap

//    COLORMAP_AUTUMN = 0,
//    COLORMAP_BONE = 1,
//    COLORMAP_JET = 2,
//    COLORMAP_WINTER = 3,
//    COLORMAP_RAINBOW = 4,
//    COLORMAP_OCEAN = 5,
//    COLORMAP_SUMMER = 6,
//    COLORMAP_SPRING = 7,
//    COLORMAP_COOL = 8,
//    COLORMAP_HSV = 9,
//    COLORMAP_PINK = 10,
//    COLORMAP_HOT = 11

cv::Mat colorizeDepth(const cv::Mat &inDepth, int colorOpts)
{
	// define min and max for kinec : http://stackoverflow.com/a/7698010
	// for Kinect 360 this is
	// min --> 600  - 0.4m
	// max --> 4000 - 4m  

	double minDistance, maxDistance;
	//minDistance = 600;
	//maxDistance = 4000;

	// or alternatively we can look at min max of the current depth frame
	// this is not good for dynamic scene as color representation changes at each frame
	// depending on the farthest object
	 cv::minMaxIdx(inDepth, &minDistance, &maxDistance);
	cv::Mat adjustedMap;
	// expand your range to 0..255. Similar to histEq();
	inDepth.convertTo(adjustedMap, CV_8UC1, 255 / (maxDistance-minDistance), - minDistance); 

	// colorize the depth map
	cv::Mat colorizedDepth;
	cv::applyColorMap(adjustedMap, colorizedDepth, colorOpts);

	//cv::imshow("Out", colorizedDepth);

	return colorizedDepth;
}

int main()
{
	displayIntroAndUsage();
	cv::vector<cv::Mat> dataStream;
	OpenCVKinect myDataCap;

	int selectedOption = 0;
DISPLAY_OPTIONS:
	displayMenu();

	std::cin >> selectedOption;
	switch(selectedOption)
	{
	case 1:
		myDataCap.setMode(C_MODE_COLOR);
		break;
	case 2:
		myDataCap.setMode(C_MODE_DEPTH);
		break;
	case 3:
		myDataCap.setMode(C_MODE_DEPTH | C_MODE_COLOR);
		break;
	case 4:
		myDataCap.setMode(C_MODE_DEPTH | C_MODE_COLOR | C_MODE_ALIGNED);
		break;
	default:
		std::cout << "Error: Invalid option selected." << std::endl;
		goto DISPLAY_OPTIONS;
		break;
	}

	if(!myDataCap.init())
	{
		std::cout << "Error initializing" << std::endl;
		return 1;
	}

	char ch = ' ';
	int colorOpts = 0;

	while(ch != 27)
	{
		dataStream = myDataCap.getData();
		std::cout << dataStream.size() <<  std::endl;
		
		cv::imshow("Depth", dataStream[C_DEPTH_STREAM]);

		// if depth map is present then colorize it and display
		if(selectedOption > 1)
			cv::imshow("Colorized Depth", colorizeDepth(dataStream[C_DEPTH_STREAM], colorOpts));

		cv::imshow("Color", dataStream[C_COLOR_STREAM]);
		ch = cv::waitKey(10);

		if(ch == 't')
		{
			// toggle through different color maps
			colorOpts = (colorOpts + 1)%11;
		}		
	}
	return 1;
}