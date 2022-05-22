#pragma once
#include "Plant.h"

#define GRASS_STRENGHT 0

class Grass :public Plant
{
public:
	Grass(World& world, const Point& position);
	void Draw() override;
	Organism* Birth(const Point& position) override;
	std::string GetName();
	~Grass() {};
};

