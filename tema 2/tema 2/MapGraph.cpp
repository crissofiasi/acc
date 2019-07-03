#include "stdafx.h"
#include "MapGraph.h"
#include <iostream>

bool operator<(Point const &v1,Point const &v2) {
	return v1.Name < v2.Name;
}

MapGraph::MapGraph() {
}

bool  MapGraph::addVertex(std::string Name, int x, int y) {
	Point v;
	v.Name = Name;
	v.x = x;
	v.y = y;
	std::map<Point, std::map<Point, double>>::iterator it;
	std::map<Point, double> init;
	it = V.find(v);
	if (it != V.end())
		return false;
	std::pair<Point, std::map<Point, double>> pair(v, init);
	V.insert(pair);
	it = V.find(v);
	if (it == V.end())
		return false;
	std::pair<std::string, Point> pair2(Name, v);
	CNames.insert(pair2);
	return true;
}

bool MapGraph::addEdge(std::string Name1, std::string Name2, double cost) {
	std::map<std::string, Point>::iterator it;
	std::map<Point, std::map<Point, double>>::iterator it2;
	it = CNames.find(Name1);
	if (it == CNames.end())
		return false;
	it = CNames.find(Name2);
	if (it == CNames.end())
		return false;
	it2 = V.find(CNames.find(Name1)->second);
	it2->second.insert(std::pair<Point, int>(CNames.find(Name2)->second, cost));
	it2 = V.find(CNames.find(Name2)->second);
	it2->second.insert(std::pair<Point, int>(CNames.find(Name1)->second, cost));
	return true;
}

void MapGraph::printGraph() {
	std::cout << "vertices:" << std::endl;
	for (auto p : CNames) {
		std::cout << p.first<<std::endl;
	}
	std::cout << "edges:" << std::endl;
	for (auto p : V) {
		for (auto p2 : p.second) {
			if (p.first < p2.first)
				std::cout << p.first.Name << "---" << p2.first.Name << std::endl;
		}
	}


}


int MapGraph::getNumVertices() {return CNames.size(); }
int MapGraph::getNumEdges() {
	int n=0;
	for (auto p : V) {
		for (auto p2 : p.second) {
			if (p.first < p2.first)
				n++;
		}
	}

	return n;
}
std::list<Point> MapGraph::dijkstra(Point startpoint, Point goalpoint){
	std::list<Point> l;
	return l;
}
std::list<Point> MapGraph::aStarSearch(Point startpoint, Point goalpoint){
	std::list<Point> l;
	return l;

}
