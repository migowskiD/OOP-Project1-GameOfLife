#include "Sheep.h"

Sheep::Sheep(World& world, const Point& position)
	:Animal(world, position, SHEEP_STRENGHT, SHEEP_INITIATIVE)
{
}

void Sheep::Draw()
{
	printf("\x1B[93mS\033[0m ");
}

bool Sheep::SameType(Organism* o)
{
	return dynamic_cast<Sheep*>(o) != nullptr;
}

Organism* Sheep::Birth(const Point& position)
{
	Organism* newborn = new Sheep(world, position);
	std::cout << "Sheep has been born (" << position.x << " " << position.y << ")\n";
	return newborn;
}

std::string Sheep::GetName() 
{
	return "Sheep";
}