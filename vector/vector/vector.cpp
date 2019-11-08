// vector.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
#include "TVector.h"

int timer(TVector<int> testvec);

int main()
{
	// declaration of testvec
	TVector<int> testvec;

	testvec.push_back(1);

	std::cout << testvec.at(1);

	return 0;
}

int timer(TVector<int> testvec)
{
	std::cout << std::endl;

	for (int i = 0; i < 5; ++i)
	{
		// record start time
		auto start = std::chrono::steady_clock::now();

		// call of function from tvector
		testvec.push_back(3);

		// record end time
		auto end = std::chrono::steady_clock::now();

		// calculate duration
		std::chrono::duration<double> diff = end - start;

		//std::cout << "Recording time: " << diff.count() << std::endl;
	}

	std::cout << std::endl;
	std::vector<int> test;
	
	for (int i = 0; i < 5; ++i)
	{
		// record start time
		auto start = std::chrono::steady_clock::now();

		// call of function from vector libary
		test.push_back(2);

		// record end time
		auto end = std::chrono::steady_clock::now();

		// calculate duration
		std::chrono::duration<double> diff = end - start;

		//std::cout << "Recording time: " << diff.count() << std::endl;
	}

	return 0;
}