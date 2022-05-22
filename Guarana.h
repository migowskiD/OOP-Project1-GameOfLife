#pragma once
#include "Plant.h"

#define GUARANA_STRENGHT 0

class Guarana :public Plant
{
public:
	Guarana(World& world, const Point& position);
	void Draw() override;
	Organism* Birth(const Point& position) override;
	std::string GetName();
	void Collision(Organism* other) override;
	~Guarana() {};
};
