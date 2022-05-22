#pragma once
#include "Animal.h"

#define WOLF_STRENGHT 9
#define WOLF_INITIATIVE 5

class Wolf :public Animal
{
public:
	Wolf(World& world, const Point& position);
	void Draw() override;
	bool SameType(Organism* o) override;
	Organism* Birth(const Point& position) override;
	std::string GetName();
	~Wolf() {};
};