#include "Organism.h"

Organism::Organism(World& world, const Point& position, const int& strength, const int& initiative, const bool& alive)
	:world(world), position(position), strength(strength), initiative(initiative), alive(alive)
{
}

int Organism::GetStrength()
{
	return strength;
}
int Organism::GetInitiative()
{
	return initiative;
}
Point Organism::GetPosition() const
{
	return position;
}

void Organism::SetPosition(const Point& p)
{
	this->position = p;
}

World Organism::GetWorld()
{
	return world;
}

bool Organism::GetAlive()
{
	return alive;
}

void Organism::SetAlive(const bool& alive)
{
	this->alive = alive;
}

Point Organism::GetRandomPoint(const Point& p, bool top, bool bot, bool left, bool right)
{
	Point np = p;
	bool found = false;
	CheckBorders(p, top, bot, left, right);
	while (found == false && (top == true || bot == true || left == true || right == true))
	{
		int direction = rand() % 4;
		if (direction == 0 && top == true)
		{
			np.y = p.y - 1;
			np.x = p.x;
			found = true;
		}
		else if (direction == 1 && bot == true)
		{
			np.y = p.y + 1;
			np.x = p.x;
			found = true;
		}
		else if (direction == 2 && left == true)
		{
			np.y = p.y;
			np.x = p.x - 1;
			found = true;
		}
		else if (direction == 3 && right == true)
		{
			np.y = p.y;
			np.x = p.x + 1;
			found = true;
		}
	}
	return np;
}

Point Organism::GetRandomSafePoint(const Point& p)
{
	Point np = p;
	bool top = true, bot = true, left = true, right = true;
	CheckBorders(p, top, bot, left, right);
	if (top == true)
	{
		np.y--;
		if (world.GetOrganism(np) != nullptr)
			top = false;
		np=p;
	}
	if(bot ==true)
	{
		np.y++;
		if (world.GetOrganism(np) != nullptr)
			bot = false;
		np=p;
	}
	if (left == true)
	{
		np.x--;
		if (world.GetOrganism(np) != nullptr)
			left = false;
		np = p;
	}
	if (right == true)
	{
		np.x++;
		if (world.GetOrganism(np) != nullptr)
			right = false;
		np = p;
	}
	if (top == true || bot == true || left == true || right == true)
		np = GetRandomPoint(p, top, bot, left, right);
	return np;
}

void Organism::CheckBorders(const Point& p, bool& top, bool& bot, bool& left, bool& right)
{
	if (p.y == 0)
		top = false;
	if (p.y == world.GetHeight() - 1)
		bot = false;
	if (p.x == 0)
		left = false;
	if (p.x == world.GetWidth() - 1)
		right = false;
}

void Organism::SetStrength(const int& s)
{
	this->strength = s;
}