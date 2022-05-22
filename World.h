#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Organism.h"
#include "Point.h"
#define DEFAULT_I 0

class Organism;

class World {
private:
	int height, width;
	Organism*** map;
	void NewLife();
	std::vector<Organism*> OrganismQueue;
	std::vector<Organism*> NewOrganism;
public:
	World(const int& height, const int& width);
	~World() {};
	void TakeATurn();
	void DrawWorld();
	int GetHeight();
	int GetWidth();
	int MoveOrganism(const Point& op, const Point& np);
	void AddOrganism(Organism* o);
	void DelOrganism(Organism* o);
	Organism* GetOrganism(const Point& p);
	void DeleteAll();
};