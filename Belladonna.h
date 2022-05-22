#pragma once
#include "Plant.h"

#define BELLADONNA_STRENGHT 99

class Belladonna :public Plant
{
public:
	Belladonna(World& world, const Point& position);
	void Draw() override;
	Organism* Birth(const Point& position) override;
	std::string GetName();
	void Collision(Organism* other);
	~Belladonna() {};
};
