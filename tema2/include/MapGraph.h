#pragma once
#include <string>
#include <list>
#include <map>
#include <string>
#include <list>
class Point {
public:
	std::string Name;
	int x, y;
	bool friend   operator < (Point const& v1, Point const& v2);
};

class MapGraph {
	std::map<Point, std::map<Point, double>> V;
	std::map<std::string, Point> CNames;

public:
	MapGraph();
	bool addVertex(std::string Name, int x, int y);
	bool addEdge(std::string Name1, std::string Name2, double lenght);
	void printGraph();
	int getNumVertices();
	int getNumEdges();
	std::list<Point> dijkstra(Point startpoint, Point goalpoint);
	std::list<Point> aStarSearch(Point startpoint, Point goalpoint);

};


