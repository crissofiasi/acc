// tema 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SortAlgs.h"
#include <iostream>
#include <chrono>
#include <fstream>

int main()
{
	std::ofstream myFile;
	myFile.open("out.txt");
	int ns[4] = { 100000, 300000, 600000 , 1000000 }, i;
	int k = 0;
	for (k = 0; k < 4; k++)
	{
		int n = ns[k];
		int *a = new int[n];
		int *b = new int[n];


		std::cout << std::endl << "N=" << n << std::endl << std::endl;
		myFile << std::endl << "N=" << n << std::endl << std::endl;
		SortAlgs algs;

		for (i = 0; i < n; i++)
			b[i] = rand();

		for (i = 0; i < n; i++)
			a[i] = b[i];


		std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
		std::cout << "buble.....";
		myFile << "buble.....";

		algs.bubbleSort(a, n);

		std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << time_span.count() << " seconds."<< std::endl;
		myFile << time_span.count() << " seconds." << std::endl;


		for (i = 0; i < n; i++)
			a[i] = b[i];

		t1 = std::chrono::steady_clock::now();
		std::cout << "Ranking...";
		myFile << "Ranking...";

		algs.rankingSort(a, n);

		t2 = std::chrono::steady_clock::now();
		time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << time_span.count() << " seconds." << std::endl;
		myFile << time_span.count() << " seconds." << std::endl;


		for (i = 0; i < n; i++)
			a[i] = b[i];

		t1 = std::chrono::steady_clock::now();
		std::cout << "merge.....";
		myFile << "merge.....";

		algs.mergeSort(a, n);

		t2 = std::chrono::steady_clock::now();
		time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << time_span.count() << " seconds." << std::endl;
		myFile << time_span.count() << " seconds." << std::endl;

		for (i = 0; i < n; i++)
			a[i] = b[i];

		t1 = std::chrono::steady_clock::now();
		std::cout << "Bitonic...";
		myFile << "Bitonic...";

		algs.bitonicSort(a, n);

		t2 = std::chrono::steady_clock::now();
		time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << time_span.count() << " seconds." << std::endl;
		myFile << time_span.count() << " seconds." << std::endl;

		for (i = 0; i < n; i++)
			a[i] = b[i];

		t1 = std::chrono::steady_clock::now();
		std::cout << "Linear....";
		myFile << "Linear....";

		algs.linearSort(a, n);

		t2 = std::chrono::steady_clock::now();
		time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << time_span.count() << " seconds." << std::endl;
		myFile << time_span.count() << " seconds." << std::endl;

		delete[] a;
	}


	/*for (int i = 0; i < n; i++)
		std::cout << a[i]<< " , ";
	std::cout << std::endl;
	*/
	myFile.close();
	system("pause");
	return 0;
}

