#include "Belladonna.h"

Belladonna::Belladonna(World& world, const Point& position)
	:Plant(world, position, BELLADONNA_STRENGHT)
{
}

void Belladonna::Draw()
{
	printf("\x1B[32mB\033[0m ");
}

Organism* Belladonna::Birth(const Point& position)
{
	Organism* newborn = new Belladonna(world, position);
	std::cout << "Belladonna has spread (" << position.x << " " << position.y << ")\n";
	return newborn;
}

std::string Belladonna::GetName()
{
	return "Belladonna";
}

void Belladonna::Collision(Organism* other)
{
	other->SetAlive(false);
	std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") won with " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ")\n";
}