#include "Animal.h"

Animal::Animal(World& world, const Point& position, const int& strength, const int& initiative, const bool& alive, const int& range, const double& movechance)
	:Organism(world, position, strength, initiative, alive), range(range), movechance(movechance)
{
}

void Animal::Action()
{
	for (int i = 0; i < range; i++)
	{
		if (GetAlive() == true && DidMove() == true)
		{
			Point np = GetRandomPoint(GetPosition());
			if (np.x != GetPosition().x || np.y != GetPosition().y)
				if (world.MoveOrganism(GetPosition(), np) == 1)
					break;
		}
	}

}

void Animal::Collision(Organism* other)
{
	if (SameType(other))
	{
		Point np = GetRandomSafePoint(GetPosition());
		Organism* o = nullptr;
		if (np.y != GetPosition().y || np.x != GetPosition().x)
		{
			o = Birth(np);
		}
		else
		{
			Point np = GetRandomSafePoint(other->GetPosition());
			if (np.y != other->GetPosition().y || np.x != other->GetPosition().x)
			{
				o = Birth(np);
			}
		}
		if (o != nullptr)
		{
			world.AddOrganism(o);
		}
	}
	else
	{
		if (DidAvoid())
		{
			Point np = GetRandomSafePoint(GetPosition());
			if (np.y != GetPosition().y || np.x != GetPosition().x)
			{
				std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") avoided " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
				world.MoveOrganism(GetPosition(), np);
				return;
			}
		}
		if (DidBlock(other))
		{
			std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") blocked " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
		}
		else if (this->GetStrength() > other->GetStrength())
		{
			other->SetAlive(false);
			std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") won with " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
		}
		else
		{
			SetAlive(false);
			std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") lost with " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
		}
	}
}

bool Animal::DidMove()
{
	double probability = rand() % 100;
	if (probability < (movechance * 100))
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Animal::DidBlock(Organism* other)
{
	return false;
}

bool Animal::DidAvoid()
{
	return false;
}