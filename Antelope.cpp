#include "Antelope.h"

Antelope::Antelope(World& world, const Point& position)
	:Animal(world, position, ANTELOPE_STRENGHT, ANTELOPE_INITIATIVE, true, ANTELOPE_RANGE)
{
}

void Antelope::Draw()
{
	printf("\x1B[93mA\033[0m ");
}

bool Antelope::SameType(Organism* o)
{
	return dynamic_cast<Antelope*>(o) != nullptr;
}

Organism* Antelope::Birth(const Point& position)
{
	Organism* newborn = new Antelope(world, position);
	std::cout << "Antelope has been born (" << position.x << " " << position.y << ")\n";
	return newborn;
}

std::string Antelope::GetName()
{
	return "Antelope";
}

bool Antelope::DidAvoid()
{
	if (rand() % 2 == 0)
		return true;
	else return false;
}