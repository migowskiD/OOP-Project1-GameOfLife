#include "Grass.h"

Grass::Grass(World& world, const Point& position)
	:Plant(world, position, GRASS_STRENGHT)
{
}

void Grass::Draw()
{
	printf("\x1B[32mG\033[0m ");
}

Organism* Grass::Birth(const Point& position)
{
	Organism* newborn = new Grass(world, position);
	std::cout << "Grass has spread (" << position.x << " " << position.y << ")\n";
	return newborn;
}

std::string Grass::GetName()
{
	return "Grass";
}