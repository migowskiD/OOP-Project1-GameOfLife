#pragma once
#include "Plant.h"

#define SOSNOWSKI_STRENGHT 10

class SosnowskiHogweed :public Plant
{
public:
	SosnowskiHogweed(World& world, const Point& position);
	void Draw() override;
	Organism* Birth(const Point& position) override;
	std::string GetName();
	void Collision(Organism* other) override;
	void Action() override;
	~SosnowskiHogweed() {};
};
