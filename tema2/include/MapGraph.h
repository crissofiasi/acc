#pragma once
#include <string>
#include <list>
#include <map>
#include <string>
#include <list>
#include <set>
class Point {
public:
	std::string Name;
	double x, y;
	bool friend   operator < (Point const& v1, Point const& v2);
	bool operator ==(Point const &other);
	bool operator !=(Point const &other);
};

class MapGraph {
	std::map<Point, std::map<Point, double>> V;
	std::map<std::string, Point> CNames;

public:
	MapGraph();
	bool addVertex(std::string Name, double x, double y);
	bool addEdge(std::string Name1, std::string Name2, double lenght);
	void printGraph();
	int getNumVertices();
	int getNumEdges();
	std::list<Point> dijkstra(Point startpoint, Point goalpoint);
	std::list<Point> aStarSearch(Point startpoint, Point goalpoint);
	Point getPointByName(std::string Name);

	void addCities();

};


