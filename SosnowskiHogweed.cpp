#include "SosnowskiHogweed.h"

SosnowskiHogweed::SosnowskiHogweed(World& world, const Point& position)
	:Plant(world, position, SOSNOWSKI_STRENGHT)
{
}

void SosnowskiHogweed::Draw()
{
	printf("\x1B[32m$\033[0m ");
}

Organism* SosnowskiHogweed::Birth(const Point& position)
{
	Organism* newborn = new SosnowskiHogweed(world, position);
	std::cout << "SosnowskiHogweed has spread (" << position.x << " " << position.y << ")\n";
	return newborn;
}

std::string SosnowskiHogweed::GetName()
{
	return "SosnowskiHogweed";
}


void SosnowskiHogweed::Collision(Organism* other)
{
	other->SetAlive(false);
	std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") won with " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
}

void SosnowskiHogweed::Action()
{
	if (GetAlive() == true)
	{
		bool top = true, bot = true, left = true, right = true;
		Point p = GetPosition();
		CheckBorders(p, top, bot, left, right);
		Organism* other = nullptr;

		if (top == true)
		{
			p.y--;
			other = world.GetOrganism(p);
			if (other != nullptr && dynamic_cast<Plant*>(other) == nullptr)
			{
				other->SetAlive(false);
				std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") killed(around) " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
				world.DelOrganism(other);
			}
			p = GetPosition();
		}
		if (bot == true)
		{
			p.y++;
			other = world.GetOrganism(p);
			if (other != nullptr && dynamic_cast<Plant*>(other) == nullptr)
			{
				other->SetAlive(false);
				std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") killed(around) " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
				world.DelOrganism(other);
			}
			p = GetPosition();
		}
		if (left == true)
		{
			p.x--;
			other = world.GetOrganism(p);
			if (other != nullptr && dynamic_cast<Plant*>(other) == nullptr)
			{
				other->SetAlive(false);
				std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") killed(around) " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
				world.DelOrganism(other);
			}
			p = GetPosition();
		}
		if (right == true)
		{
			p.x++;
			other = world.GetOrganism(p);
			if (other != nullptr && dynamic_cast<Plant*>(other) == nullptr)
			{
				other->SetAlive(false);
				std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") killed(around) " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
				world.DelOrganism(other);
			}
			p = GetPosition();
		}
	}
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