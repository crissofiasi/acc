// tema 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MapGraph.h"
#include <iostream>
#include "tema2.h"
int main()
{
	MapGraph myMap;
	/*myMap.addVertex("Iasi", 1, 1);
	myMap.addVertex("Vaslui", 2, 2);
	myMap.addVertex("Constanta", 3, 5);
	myMap.addVertex("Bacau", 1, 2);*/


	myMap.addCities();






	myMap.addEdge("Iasi", "Vaslui", 42);
	myMap.addEdge("Vaslui", "Constanta", 132);
	myMap.addEdge("Iasi", "Bacau", 62);
	myMap.addEdge("Vaslui", "Bacau", 57);
	myMap.addEdge("Constanta", "Bacau", 143);

	std::cout << "No. of Vertices=" << myMap.getNumVertices() << std::endl;
	std::cout << "No. of edges=" << myMap.getNumEdges() << std::endl;
	myMap.printGraph();

	std::list<Point> route = myMap.dijkstra(myMap.getPointByName("Iasi"), myMap.getPointByName("Constanta"));

	std::cout << "Dijkstra:"<<std::endl;

	for (Point p : route) {
		std::cout << " --> " << p.Name;
	}
	std::cout << std::endl;

	system("pause");
    return 0;
}

