/*******************************************************
	Author: 
		Liu Caiquan
	Date: 
		@8th-December-2016@

	CarLife Protocol version:
		@V1.2.4@
							Copyright (C) Under BaiDu, Inc.
*******************************************************/
#ifndef C_CARLIFE_LOG_H
#define C_CARLIFE_LOG_H

#include<iostream>
#include<string>
using namespace std;
class CCarLifeLog{
public:
	static void carLifeLog(string log);
	static void carLifeLog(int value);
	static void carLifeLogWithPrefix(string log);
	static void carLifeLogWithPrefix(int value);

	static void carLifeLogLn(string log);
	static void carLifeLogLn(int value);
	static void carLifeLogLnWithPrefix(string log);
	static void carLifeLogLnWithPrefix(int value);
};


















































#endif































