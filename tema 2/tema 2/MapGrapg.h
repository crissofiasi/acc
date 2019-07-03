#pragma once
#include <string>
#include <list>
#include <map>
#include <string>

class MapGraph {
	std::map<Vertex,std::map<Vertex,int>> V;
	std::map<std::string, Vertex> CNames;

public:
	MapGraph();
	bool addVertex(std::string Name,int x, int y);
	bool addEdge(std::string Name1, std::string Name2, int price);
	void printGraph();
};

class Vertex {
public:
	std::string Name;
	int x, y;
};
