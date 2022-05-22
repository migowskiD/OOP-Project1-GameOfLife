#pragma once
#include "Organism.h"

#define DEFAULT 1

class Animal : public Organism
{
private:
	int range;
	double movechance;
public:
	Animal(World& world, const Point& position, const int& strength, const int& initiative, const bool& alive = true, const int& range = DEFAULT, const double& movechance = DEFAULT);
	~Animal() {};
	virtual void Action() override;
	virtual void Collision(Organism* other) override;
	virtual bool SameType(Organism* o) = 0;
	bool DidMove();
	virtual bool DidBlock(Organism* other);
	virtual bool DidAvoid();
};