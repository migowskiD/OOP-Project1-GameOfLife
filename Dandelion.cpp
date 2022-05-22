#include "Dandelion.h"

Dandelion::Dandelion(World& world, const Point& position)
	:Plant(world, position, DANDELION_STRENGHT, DANDELION_INITIATIVE, true, DANDELION_SPREADTIMES)
{
}

void Dandelion::Draw()
{
	printf("\x1B[32mD\033[0m ");
}

Organism* Dandelion::Birth(const Point& position)
{
	Organism* newborn = new Dandelion(world, position);
	std::cout << "Dandelion has spread (" << position.x << " " << position.y << ")\n";
	return newborn;
}

std::string Dandelion::GetName()
{
	return "Dandelion";
}