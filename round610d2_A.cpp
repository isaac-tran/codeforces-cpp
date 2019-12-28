// round610d2_A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

/*
	Input:
		t: num of tests
		a: travel start point
		b: travel end point;
		c: location of mobile station
		r: mobile station's radius
		
		t <= 1000
		-10^8 <= a,b,c <= 10^8
		0 <= r < 10^8

	Output:
		x: time spent outside of mobile station's radius (in minutes)

	Algorithm:
		Compute length outside of range on the left of c
		Compute length outside of range on the right of c
		Add the 2 parts together
*/

//	Properties
int t;
int a, b, c, r;		
int totalTime;		//	Total time travelled from a to b
int timeWoRadius;	//	End result: time spent outside of radius

void init()
{
	a = 0;
	b = 0;
	c = 0;
	r = 0;
}

//	Computes non-overlapped area on mobile station's left side from the center.
int computeLeftSide()
{
	int leftEnd = c - r;	//	From this point to the left is non-coverage area

	if (a > leftEnd)	//	a is not in left non-coverage area
		return 0;		
	else				//	a is in left non-coverage area
	{
		if (b < leftEnd)	//	b is also in left non-coverage area -> entire trip is outside coverage area
			return b - a;
		else				//	b is NOT in left non-coverage area -> only part of the trip is outside coverage area
			return leftEnd - a;
	}
}

//	Computes non-overlapped area on mobile station's right side from the center.
//	Computation is similar to computeRightSide()
int computeRightSide()
{
	int rightEnd = c + r;	

	if (b < rightEnd)	
		return 0;
	else
	{
		if (a > rightEnd)
			return b - a;
		else
			return b - rightEnd;
	}
}

int main()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> a >> b >> c >> r;
		
		if (a > b) 
			swap(a, b);

		cout << computeLeftSide() + computeRightSide();
		cout << "\n";
	}
}

