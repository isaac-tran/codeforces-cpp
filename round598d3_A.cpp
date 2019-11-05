// round598d3_A.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code written for Codeforces Round 598 Div 3 Problem A: Payment Without Change
// Author: Isaac Tran

//#include "pch.h"
#include <iostream>

using namespace std;

//------Problem Summary (given, problem, input, output)-----
// a coins of value n
// b coins of value 1

// x (0 <= x <= a) coins of n
// y (0 <= y <= b) coins of 1
// x * a + y * b = S

//	num test cases
// a,b,n,s

// YES or NO

/* Properties */
int a, n;
int b;
int s;
int numOfTests;

//	Check if we can actually give change with the coins we have
bool canPayExactChange()
{
	int coin_n_needed = s / n;
	int coin_1_needed;

	if (a >= coin_n_needed)
		coin_1_needed = s - coin_n_needed * n;
	else
		coin_1_needed = s - a * n;

	if (b < coin_1_needed)
		return false;
	return true;
}

int main()
{
	cin >> numOfTests;

	for (int i = 0; i < numOfTests; i++)
	{
		cin >> a >> b >> n >> s;

		if (canPayExactChange())
		{
			cout << "YES\n";
			continue;
		}
		else
			cout << "NO\n";
	}

	return 0;
}

