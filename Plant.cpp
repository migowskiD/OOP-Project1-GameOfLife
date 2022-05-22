#include "Plant.h"

Plant::Plant(World& world, const Point& position, const int& strength, const int& initiative, const bool& alive, const int& spreadtimes, const double& spreadchance)
	:Organism(world, position, strength, initiative, alive), spreadtimes(spreadtimes), spreadchance(spreadchance)
{
}

void Plant::Action()
{
	for (int i = 0; i < spreadtimes; i++)
	{
		if (GetAlive() == true && DidSpread() == true)
		{
			Point np = GetRandomSafePoint(GetPosition());
			Organism* o = nullptr;
			if (np.x != GetPosition().x || np.y != GetPosition().y)
			{
				o = Birth(np);
			}
			if (o != nullptr)
			{
				world.AddOrganism(o);
			}
		}
	}
}

void Plant::Collision(Organism* other)
{
	if (this->GetStrength() > other->GetStrength())
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

bool Plant::DidSpread()
{
	double probability = rand() % 100;
	if (probability < (spreadchance * 100))
	{
		//std::cout << probability << " " << spreadchance * 100 << std::endl;
		return true;
	}
	else
		return false;
}