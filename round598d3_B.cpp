// round598d3_B.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code written for Codeforces Round 598 Div 3 Problem B: Minimize the permutation
// Author: Isaac Tran

#include "pch.h"
#include <iostream>

using namespace std;

//	Input:
//	q - number of tests (1 <= q <= 100)
//	n (1 <= n <= 100)
//  permutation n (e.g 5 4 1 3 2)

//	Output
//	Min swaps to achieve minimum permutation (e.g 1 5 2 4 3)

//	Algorithm:
//	Sweep through the array from RIGHT to LEFT 
//	and swap all elements that are out of position/breaks ascending order. (a[i-1] > a[i])
//	Repeat until all elements are in place or out of swaps to perform.

/*	Properties	*/
int q;
int n;
int a[100];
int pos[101];		//	a table that stores the position of each value.
bool opDone[101];	//	a table that marks operations at index i as done
					//	false = not done, true = done and cannot be repeated.

void performOperation()
{
	int swapsLeft = n - 1;	//	Number of swaps left allowed to perform.
	bool swappedInLastIteration = false;

/*	NOTE: Wrong algorithm
	Reason: prioritized shifting will sometimes block the next smallest element from being shifted
			as ith operation can only be performed ONCE

	//	Find the first misplaced element 
	// (e.g 5 4 1 3 2) -> value 1 in position 3 (pos[1] = 3)
	//	Repeat until all elements are in place
	for (int i = 1; i <= n; i++)
	{
		if (pos[i] != i - 1)
		{
			//	Swap that element to correct position
			for (int j = pos[i]; j > i; j--)
			{
				if (!opDone[j-1])
				{
					swap(pos[a[j]], pos[a[j - 1]]);		//	Swap element
					swap(a[j], a[j - 1]);				//	Swap position
					swapsLeft--;						//	One operation done -> decrease
					opDone[j - 1] = true;				//	Mark ith op as done
				}

				if (swapsLeft == 0)
					break;
			}
		}

		if (swapsLeft == 0)
			break;
	} */

	do
	{
		//	Note: if no swap is done in this while-loop-iteration, 
		//  it means all elements are in ascending order -> Achieved min permutation
		swappedInLastIteration = false;
		for (int i = n; i > 1; i--)
		{
			if (a[i - 1] > a[i] && opDone[i-1] == false)
			{
				swappedInLastIteration = true;
				swap(pos[a[i]], pos[a[i - 1]]);		//	Swap elements in position table
				swap(a[i], a[i - 1]);				//	Swap elements in a
				swapsLeft--;						//	One operation done -> decrease count
				opDone[i - 1] = true;				//	Mark ith op as done
			}
		}
	}	while (swappedInLastIteration == true && swapsLeft > 0);
}

void outputResult()
{
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << "\n";
}

int main()
{
    //	Read input
	cin >> q;
	for (int test = 0; test < q; test++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> a[j];
			pos[a[j]] = j;
			opDone[j] = false;
		}

		//	If n = 1 -> can just move to output
		if (n > 1)	
			performOperation();

		outputResult();
	}
}
