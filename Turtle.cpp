#include "Turtle.h"

Turtle::Turtle(World& world, const Point& position)
	:Animal(world, position, TURTLE_STRENGHT, TURTLE_INITIATIVE, true, TURTLE_RANGE, TURTLE_MOVE_CHANCE)
{
}

void Turtle::Draw()
{
	printf("\x1B[93mT\033[0m ");
}

bool Turtle::SameType(Organism* o)
{
	return dynamic_cast<Turtle*>(o) != nullptr;
}

Organism* Turtle::Birth(const Point& position)
{
	Organism* newborn = new Turtle(world, position);
	std::cout << "Turtle has been born (" << position.x << " " << position.y << ")\n";
	return newborn;
}

std::string Turtle::GetName()
{
	return "Turtle";
}

bool Turtle::DidBlock(Organism* other)
{
	if (other->GetStrength() < 5)
	{
		return true;
	}
	return false;
}