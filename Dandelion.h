#pragma once
#include "Plant.h"

#define DANDELION_STRENGHT 0
#define DANDELION_INITIATIVE 0
#define DANDELION_SPREADTIMES 3

class Dandelion :public Plant
{
public:
	Dandelion(World& world, const Point& position);
	void Draw() override;
	Organism* Birth(const Point& position) override;
	std::string GetName();
	~Dandelion() {};
};