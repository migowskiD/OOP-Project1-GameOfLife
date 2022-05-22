#pragma once
#include "Animal.h"

#define FOX_STRENGHT 3
#define FOX_INITIATIVE 7

class Fox :public Animal
{
public:
	Fox(World& world, const Point& position);
	void Draw() override;
	bool SameType(Organism* o) override;
	Organism* Birth(const Point& position) override;
	std::string GetName();
	void Action() override;
	~Fox() {};
};
