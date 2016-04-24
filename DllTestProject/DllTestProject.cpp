// DllTestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "OBJReader.h"

using namespace std;

int main()
{
	int a = 2;
	int b = 3;

	cout << "a + b = "
		<< OBJReaderDLL::OBJReader::Test(a, b)
		<< endl;

	char t;
	cin >> t;

    return 0;
}

