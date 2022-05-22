#pragma once
#include "Animal.h"

#define HUMAN_STRENGHT 5
#define HUMAN_INITIATIVE 4
#define SPECIAL_TIME 5
#define SPECIAL_COOLDOWN 5
#define DEFAULT_SPECIAL 0

class Human :public Animal
{
private:
	int specialtime, specialcooldown;
public:
	Human(World& world, const Point& position);
	void Draw() override;
	bool SameType(Organism* o) override;
	Organism* Birth(const Point& position) override;
	std::string GetName();
	void Action() override;
	Point CatchMove();
	void SpecialSkill();
	~Human() {};
};
