#pragma once
#include "Organism.h"

#define DEFAULT_CHANCE 0.1
#define DEFAULT_TIMES 1
#define DEFAULT_INITIATIVE 0

class Plant : public Organism
{
private:
	int spreadtimes;
	double spreadchance;
public:
	Plant(World& world, const Point& position, const int& strength, const int& initiative = DEFAULT_INITIATIVE, const bool& alive = true, const int& spreadtimes = DEFAULT_TIMES, const double& spreadchance = DEFAULT_CHANCE);
	~Plant() {};
	virtual void Action() override;
	virtual void Collision(Organism* other) override;
	bool DidSpread();
};
