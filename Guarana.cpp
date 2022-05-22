#include "Guarana.h"

Guarana::Guarana(World& world, const Point& position)
	:Plant(world, position, GUARANA_STRENGHT)
{
}

void Guarana::Draw()
{
	printf("\x1B[32m@\033[0m ");
}

Organism* Guarana::Birth(const Point& position)
{
	Organism* newborn = new Guarana(world, position);
	std::cout << "Guarana has spread (" << position.x << " " << position.y << ")\n";
	return newborn;
}

std::string Guarana::GetName()
{
	return "Guarana";
}

void Guarana::Collision(Organism* other)
{
	SetAlive(false);
	other->SetStrength(other->GetStrength() + 3);
	std::cout << this->GetName() << " (" << this->GetPosition().x << " " << this->GetPosition().y << ") was eaten by " << other->GetName() << " (" << other->GetPosition().x << " " << other->GetPosition().y << ") Strength: " << other->GetStrength() << "\n";
}