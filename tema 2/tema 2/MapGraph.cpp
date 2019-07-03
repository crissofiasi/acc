#include "pch.h"
#include "MapGrapg.h"

MapGraph::MapGraph() {
}

bool  MapGraph::addVertex(std::string Name, int x, int y) {
	Vertex v ;
	v.Name = Name;
	v.x = x;
	v.y = y;
	std::map<Vertex, std::map<Vertex, int>>::iterator it;
	std::map<Vertex, int> init;
	it = V.find(v);
	if (it == V.end())
		return false;
	std::pair<Vertex, std::map<Vertex, int>> pair(v, init);
	V.insert(pair);
	it = V.find(v);
	if (it != V.end())
		return false;
	return true;
}

bool MapGraph::addEdge(std::string Name1, std::string Name2, int price) {


}

