#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Config/config.h"
#include "Client_ahrs/RPCCallerAHRS.h"
#include <iostream>
#include <fstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ahrs_client/Data.h"
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "ahrs_client");
	ros::NodeHandle n;
	ros::Publisher ahrs_data_pub = n.advertise<ahrs_client::Data>("ahrs_data", 1000);
	ros::Rate loop_rate(10);
	RPCCallerAHRS* RPCCaller = new RPCCallerAHRS("150.254.45.220", 2137);
	RPCCaller->Run();
	int count = 0;
	float positionResponseData[6];
	float accelerationResponseData[6];
	float velocityResponseData[6];
	float matrixResponseData[9];
	while(ros::ok()) {
		ahrs_client::Data msg;
		RPCCaller->readPosition(positionResponseData);
		RPCCaller->readAcceleration(accelerationResponseData);
		RPCCaller->readMatrix(matrixResponseData);
		RPCCaller->readVelocity(velocityResponseData);

		msg.xAxisRotation = positionResponseData[3];
		msg.yAxisRotation = positionResponseData[4];
		msg.zAxisRotation = positionResponseData[5];

		msg.xAxisVelocity = velocityResponseData[3];
		msg.yAxisVelocity = velocityResponseData[4];
		msg.zAxisVelocity = velocityResponseData[5];

		msg.xAxisAcceleration = accelerationResponseData[3];
		msg.yAxisAcceleration = accelerationResponseData[4];
		msg.zAxisAcceleration = accelerationResponseData[5];

		msg.rotationMatrix.push_back(matrixResponseData[0]);
		msg.rotationMatrix.push_back(matrixResponseData[1]);
		msg.rotationMatrix.push_back(matrixResponseData[2]);
		msg.rotationMatrix.push_back(matrixResponseData[3]);
		msg.rotationMatrix.push_back(matrixResponseData[4]);
		msg.rotationMatrix.push_back(matrixResponseData[5]);
		msg.rotationMatrix.push_back(matrixResponseData[6]);
		msg.rotationMatrix.push_back(matrixResponseData[7]);
		msg.rotationMatrix.push_back(matrixResponseData[8]);

		// ROS_INFO("%s", msg.data.c_str());
		ahrs_data_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		count++;
	}
	return 0;
}