#include "Human.h"

Human::Human(World& world, const Point& position)
	:Animal(world, position, HUMAN_STRENGHT, HUMAN_INITIATIVE), specialcooldown(DEFAULT_SPECIAL), specialtime(DEFAULT_SPECIAL)
{
}

void Human::Draw()
{
	printf("\x1B[95mH\033[0m ");
}

bool Human::SameType(Organism* o)
{
	return dynamic_cast<Human*>(o) != nullptr;
}

Organism* Human::Birth(const Point& position)
{
	Organism* newborn = new Human(world, position);
	std::cout << "Human has been born ( " << position.x << " " << position.y << " )\n";
	return newborn;
}

std::string Human::GetName()
{
	return "Human";
}

Point Human::CatchMove()
{
	char command;
	bool top = true, bot = true, left = true, right = true;
	Point np = GetPosition();
	CheckBorders(np, top, bot, left, right);
	if (top == false && bot == false && left == false && right == false)
		return np;
	std::cout << "Use NUMPAD arrows or WSAD to move the man or E to use special skill\n";
	world.DrawWorld();
	while (true)
	{
		std::cin >> command;
		if ((command == '8' || command == 'W' || command == 'w') && top == true)
		{
			np.y--;
			return np;
		}
		else if ((command == '2' || command == 'S' || command == 's') && bot == true)
		{
			np.y++;
			return np;
		}
		else if ((command == '4' || command == 'A' || command == 'a') && left == true)
		{
			np.x--;
			return np;
		}
		else if ((command == '6' || command == 'D' || command == 'd') && right == true)
		{
			np.x++;
			return np;
		}
		else if (command == 'e')
		{
			if (specialtime == 0 && specialcooldown == 0)
			{
				specialtime = 5;
				specialcooldown = 5;
				std::cout << "Burning activated for " << specialtime << " turns!\n";
			}
			else if (specialcooldown > 0 && specialtime==0)
			{
				std::cout << "Can't use special skill for " << specialcooldown << " turns!\n";
			}
		}
	}
}

void Human::Action()
{
	if (GetAlive() == true)
	{
		Point np = CatchMove();
		if (specialtime > 0)
		{
			SpecialSkill();
			specialtime--;
		}
		else if (specialcooldown > 0)
		{
			specialcooldown--;
		}
		if (np.x != GetPosition().x || np.y != GetPosition().y)
			GetWorld().MoveOrganism(GetPosition(), np);
	}
}

void Human::SpecialSkill()
{
	bool top = true, bot = true, left = true, right = true;
	Point p = GetPosition();
	CheckBorders(p, top, bot, left, right);
	Organism* other = nullptr;
	if (top == true)
	{
		p.y--;
		other = world.GetOrganism(p);
		if (other != nullptr)
		{
			other->SetAlive(false);
			std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") burned(around) " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
			world.DelOrganism(other);
		}
		p = GetPosition();
	}
	if (bot == true)
	{
		p.y++;
		other = world.GetOrganism(p);
		if (other != nullptr)
		{
			other->SetAlive(false);
			std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") burned(around) " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
			world.DelOrganism(other);
		}
		p = GetPosition();
	}
	if (left == true)
	{
		p.x--;
		other = world.GetOrganism(p);
		if (other != nullptr)
		{
			other->SetAlive(false);
			std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") burned(around) " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
			world.DelOrganism(other);
		}
		p = GetPosition();
	}
	if (right == true)
	{
		p.x++;
		other = world.GetOrganism(p);
		if (other != nullptr)
		{
			other->SetAlive(false);
			std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") burned(around) " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
			world.DelOrganism(other);
		}
		p = GetPosition();
	}
}