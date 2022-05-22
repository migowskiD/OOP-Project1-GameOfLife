#pragma once
#include "Animal.h"

#define TURTLE_STRENGHT 2
#define TURTLE_INITIATIVE 1
#define TURTLE_RANGE 1
#define TURTLE_MOVE_CHANCE 0.25

class Turtle :public Animal
{
public:
	Turtle(World& world, const Point& position);
	void Draw() override;
	bool SameType(Organism* o) override;
	Organism* Birth(const Point& position) override;
	std::string GetName();
	bool DidBlock(Organism* other) override;
	~Turtle() {};
};