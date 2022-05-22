#pragma once
#include "Animal.h"

#define ANTELOPE_STRENGHT 4
#define ANTELOPE_INITIATIVE 4
#define ANTELOPE_RANGE 2

class Antelope :public Animal
{
public:
	Antelope(World& world, const Point& position);
	void Draw() override;
	bool SameType(Organism* o) override;
	Organism* Birth(const Point& position) override;
	std::string GetName();
	bool DidAvoid() override;
	~Antelope() {};
};

