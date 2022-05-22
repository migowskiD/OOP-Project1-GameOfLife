#include "Fox.h"

Fox::Fox(World& world, const Point& position)
	:Animal(world, position, FOX_STRENGHT, FOX_INITIATIVE)
{
}

void Fox::Draw()
{
	printf("\x1B[93mF\033[0m ");
}

bool Fox::SameType(Organism* o)
{
	return dynamic_cast<Fox*>(o) != nullptr;
}

Organism* Fox::Birth(const Point& position)
{
	Organism* newborn = new Fox(world, position);
	std::cout << "Fox has been born (" << position.x << " " << position.y << ")\n";
	return newborn;
}

std::string Fox::GetName()
{
	return "Fox";
}

void Fox::Action()
{
	if (GetAlive() == true)
	{
		Point np = GetPosition();
		bool top = true, bot = true, left = true, right = true;
		CheckBorders(np, top, bot, left, right);
		if (top == true)
		{
			np.y--;
			if (world.GetOrganism(np)!=nullptr && world.GetOrganism(np)->GetStrength() > GetStrength())
				top = false;
			np = GetPosition();
		}
		if (bot == true)
		{
			np.y++;
			if (world.GetOrganism(np) != nullptr &&  world.GetOrganism(np)->GetStrength() > GetStrength())
				bot = false;
			np = GetPosition();
		}
		if (left == true)
		{
			np.x--;
			if (world.GetOrganism(np) != nullptr &&  world.GetOrganism(np)->GetStrength() > GetStrength())
				left = false;
			np = GetPosition();
		}
		if (right == true)
		{
			np.x++;
			if (world.GetOrganism(np) != nullptr &&  world.GetOrganism(np)->GetStrength() > GetStrength())
				right = false;
			np = GetPosition();
		}
		if (top == true || bot == true || left == true || right == true)
			np = GetRandomPoint(GetPosition(), top, bot, left, right);
		if (np.x != GetPosition().x || np.y != GetPosition().y)
			world.MoveOrganism(GetPosition(), np);
	}
}