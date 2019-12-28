// 1279A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;

/*
	Input
		t: num of tests
		r, g, b: number of red, green, blue lights

		1 <= t < 100
		1 <= r,g,b <= 10^9

	Output:
		Can we create a string of "R","G","B" without same-pairs (e.g "RR", "GG", "BB")?
		Print "Yes" or "No"

	Algorithm:
		Pick the colour with the most lights in it. e.g 4 1 1 -> pick red (r = 4) 
			Red -> Forms RRRR -> 3 slots in the middle to put G or B in (e.g RgRbRgR)
			If not enough lights to fill all the slots -> No
			Otherwise yes (leftovers -> the remaining 2 colours can sort themselves out)
*/

int t, r, g, b;

int main()
{
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> r >> g >> b;

		int mostLights = max(max(r, g), b);
		int totalSumOfTheOtherTwo = r + g + b - mostLights;

		if (totalSumOfTheOtherTwo >= mostLights - 1)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}


