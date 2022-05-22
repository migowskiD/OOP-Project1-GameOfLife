#pragma once
#include "Animal.h"

#define SHEEP_STRENGHT 4
#define SHEEP_INITIATIVE 4

class Sheep :public Animal
{
public:
	Sheep(World& world, const Point& position);
	void Draw() override;
	bool SameType(Organism* o) override;
	Organism* Birth(const Point& position) override;
	std::string GetName();
	~Sheep() {};
};
