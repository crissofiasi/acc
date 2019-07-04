#include "stdafx.h"
#include "MapGraph.h"
#include <iostream>


bool Point::operator ==(Point const &other) {

	return (this->x == other.x) && (this->y == other.y);
}

bool Point::operator !=(Point const &other) {

	return !(*this==other);
}


bool operator<(Point const &v1,Point const &v2) {
	return v1.Name < v2.Name;
}

MapGraph::MapGraph() {
}

bool  MapGraph::addVertex(std::string Name, double x, double y) {
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


Point MapGraph::getPointByName(std::string Name) {
	return CNames[Name];
}


std::list<Point> MapGraph::dijkstra(Point startpoint, Point goalpoint){

	std::set<Point> Q;
	std::map<Point, double> dist;
	std::map<Point, Point> prev;
	Point u,undefined;
	undefined.x= undefined.y = -1;
	undefined.Name = "undefined";
	for (auto pair : V)
	{
		Point p = pair.first;
		dist[p] = INT64_MAX;
		prev[p] = undefined;
		Q.insert(p);
	}
	dist[startpoint] = 0;

	while (!Q.empty())
	{
		double minDist = INT64_MAX;
		
		for (Point p : Q) {
			if (dist[p] < minDist)
			{
				u = p;
				minDist = dist[p];
			}
		}
		Q.erase(u);

		for (auto pair : V[u]) {
			Point neighbor = pair.first;
			if (Q.find(neighbor) != Q.end())
			{
				double alt = dist[u] + pair.second;
				if (alt < dist[neighbor])
				{
					dist[neighbor] = alt;
					prev[neighbor] = u;
				}
			}
		}
		if (u == goalpoint)
			break;

	}

	
	std::list<Point> l;
	Point End = goalpoint;
	while (End != undefined) {
		l.push_front(End);
		End = prev[End];
	}

	return l;
}
std::list<Point> MapGraph::aStarSearch(Point startpoint, Point goalpoint){
	std::list<Point> l;
	return l;

}


void MapGraph::addCities() {
	
	
	this->addVertex("Bucharest", 44.433333, 26.1);
	this->addVertex("Iaşi", 47.166667, 27.6);
	this->addVertex("Cluj-Napoca", 46.766667, 23.6);
	this->addVertex("Timişoara", 45.749444, 21.227222);
	this->addVertex("Galaţi", 45.45, 28.05);
	this->addVertex("Braşov", 45.633333, 25.583333);
	this->addVertex("Craiova", 44.316667, 23.8);
	this->addVertex("Constanţa", 44.183333, 28.65);
	this->addVertex("Ploieşti", 44.95, 26.016667);
	this->addVertex("Oradea", 47.066667, 21.933333);
	this->addVertex("Brăila", 45.266667, 27.983333);
	this->addVertex("Bacău", 46.566667, 26.9);
	this->addVertex("Piteşti", 44.85, 24.866667);
	this->addVertex("Arad", 46.183333, 21.316667);
	this->addVertex("Sibiu", 45.8, 24.15);
	this->addVertex("Târgu-Mureş", 46.55, 24.566667);
	this->addVertex("Baia Mare", 47.666667, 23.583333);
	this->addVertex("Buzău", 45.15, 26.833333);
	this->addVertex("Botoşani", 47.75, 26.666667);
	this->addVertex("Satu Mare", 47.8, 22.883333);
	this->addVertex("Râmnicu Vâlcea", 45.1, 24.366667);
	this->addVertex("Drobeta-Turnu Severin", 44.631944, 22.656111);
	this->addVertex("Scheia", 47.65, 26.233333);
	this->addVertex("Focşani", 45.7, 27.183333);
	this->addVertex("Piatra Neamţ", 46.916667, 26.333333);
	this->addVertex("Târgu Jiu", 45.05, 23.283333);
	this->addVertex("Tulcea", 45.166667, 28.8);
	this->addVertex("Târgovişte", 44.933333, 25.45);
	this->addVertex("Reşiţa", 45.300833, 21.889167);
	this->addVertex("Bistriţa", 47.133333, 24.483333);
	this->addVertex("Salcia", 44.433333, 24.316667);
	this->addVertex("Călăraşi", 44.2, 27.333333);
	this->addVertex("Vaslui", 46.633333, 27.733333);
	this->addVertex("Giurgiu", 43.883333, 25.966667);
	this->addVertex("Deva", 45.883333, 22.9);
	this->addVertex("Alba Iulia", 46.066667, 23.583333);
	this->addVertex("Zalău", 47.2, 23.05);
	this->addVertex("Sfântu-Gheorghe", 45.866667, 25.783333);
	this->addVertex("Slobozia", 44.566667, 27.366667);
	this->addVertex("Alexandria", 43.983333, 25.333333);
	this->addVertex("Hunedoara", 45.75, 22.9);
	this->addVertex("Miercurea-Ciuc", 46.35, 25.8);
	this->addVertex("Slatina", 44.433333, 24.366667);
	this->addVertex("Suceava", 47.633333, 26.25);


}