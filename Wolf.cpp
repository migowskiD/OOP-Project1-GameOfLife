#include "Wolf.h"

Wolf::Wolf(World& world, const Point& position)
	:Animal(world, position, WOLF_STRENGHT, WOLF_INITIATIVE)
{
}

void Wolf::Draw()
{
	printf("\x1B[93mW\033[0m ");
}

bool Wolf::SameType(Organism* o)
{
	return dynamic_cast<Wolf*>(o) != nullptr;
}

Organism* Wolf::Birth(const Point& position)
{
	Organism* newborn = new Wolf(world, position);
	std::cout << "Wolf has been born (" << position.x << " " << position.y << ")\n";
	return newborn;
}

std::string Wolf::GetName()
{
	return "Wolf";
}