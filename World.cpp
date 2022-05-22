#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Human.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "SosnowskiHogweed.h"

#define DEFAULT_DENSITY 0.25
#define NUMBER_OF_ORGANISMS 10



World::World(const int& height, const int& width) 
	:height(height), width(width)
{
		map = new Organism * *[height];
		for (int y = 0; y < height; y++)
		{
			map[y] = new Organism * [width];
			for (int x = 0; x < width; x++)
			{
				map[y][x] = nullptr;
			}
		}
		NewLife();
}

void World::DrawWorld()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[y][x] == nullptr)
			{
				std::cout << ". ";
			}
			else
				map[y][x]->Draw();
		}
		std::cout << "\n";
	}
}

Organism* World::GetOrganism(const Point& p)
{
	return map[p.y][p.x];
}

bool InitComp(Organism* a, Organism* b) 
{
	return a->GetInitiative() > b->GetInitiative();
}

void World::NewLife()
{
	Point p;
	p.y = rand() % height;
	p.x = rand() % width;
	map[p.y][p.x] = new Human(*this, p);
	OrganismQueue.push_back(map[p.y][p.x]);
	for (int i = 0; i < height * width * DEFAULT_DENSITY; i++)
	{
		while (map[p.y][p.x] != nullptr)
		{
			p.y = rand() % height;
			p.x = rand() % width;
		}
		if (i % NUMBER_OF_ORGANISMS == 0)
		{
			map[p.y][p.x] = new Wolf(*this, p);
			OrganismQueue.push_back(map[p.y][p.x]);
		}
		else if (i % NUMBER_OF_ORGANISMS == 1)
		{
			map[p.y][p.x] = new Sheep(*this, p);
			OrganismQueue.push_back(map[p.y][p.x]);
		}
		else if (i % NUMBER_OF_ORGANISMS == 2)
		{
			map[p.y][p.x] = new Fox(*this, p);
			OrganismQueue.push_back(map[p.y][p.x]);
		}
		else if (i % NUMBER_OF_ORGANISMS == 3)
		{
			map[p.y][p.x] = new Turtle(*this, p);
			OrganismQueue.push_back(map[p.y][p.x]);
		}
		else if (i % NUMBER_OF_ORGANISMS == 4)
		{
			map[p.y][p.x] = new Antelope(*this, p);
			OrganismQueue.push_back(map[p.y][p.x]);
		}
		else if (i % NUMBER_OF_ORGANISMS == 5)
		{
			map[p.y][p.x] = new Grass(*this, p);
			OrganismQueue.push_back(map[p.y][p.x]);
		}
		else if (i % NUMBER_OF_ORGANISMS == 6)
		{
			map[p.y][p.x] = new Dandelion(*this, p);
			OrganismQueue.push_back(map[p.y][p.x]);
		}
		else if (i % NUMBER_OF_ORGANISMS == 7)
		{
			map[p.y][p.x] = new Guarana(*this, p);
			OrganismQueue.push_back(map[p.y][p.x]);
		}
		else if (i % NUMBER_OF_ORGANISMS == 8)
		{
			map[p.y][p.x] = new Belladonna(*this, p);
			OrganismQueue.push_back(map[p.y][p.x]);
		}
		else if (i % NUMBER_OF_ORGANISMS == 9)
		{
			map[p.y][p.x] = new SosnowskiHogweed(*this, p);
			OrganismQueue.push_back(map[p.y][p.x]);
		}
	}
	stable_sort(OrganismQueue.begin(), OrganismQueue.end(), InitComp);
}

int World::GetHeight()
{
	return height;
}

int World::GetWidth()
{
	return width;
}

int World::MoveOrganism(const Point& op, const Point& np)
{
	if (map[np.y][np.x] == nullptr)
	{
		map[np.y][np.x] = map[op.y][op.x];
		map[np.y][np.x]->SetPosition(np);
		map[op.y][op.x] = nullptr;
		return 0;
	}
	else
	{
		map[np.y][np.x]->Collision(map[op.y][op.x]);
		if (map[np.y][np.x] == nullptr || map[np.y][np.x]->GetAlive() == false)
		{
			map[np.y][np.x] = map[op.y][op.x];
			map[np.y][np.x]->SetPosition(np);
			map[op.y][op.x] = nullptr;
		}
		else if (map[op.y][op.x] != nullptr && map[op.y][op.x]->GetAlive() == false)
		{
			map[op.y][op.x] = nullptr;
		}
		return 1;
	}
}

void World::AddOrganism(Organism* o)
{
	map[o->GetPosition().y][o->GetPosition().x] = o;
	NewOrganism.push_back(o);
}

void World::DelOrganism(Organism* o)
{
	map[o->GetPosition().y][o->GetPosition().x] = nullptr;
}

void World::TakeATurn()
{
	for (Organism* o : OrganismQueue)
	{
			o->Action();
	}
	while (NewOrganism.size() > 0)
	{
		OrganismQueue.push_back(NewOrganism.front());
		NewOrganism.erase(NewOrganism.begin());
	}
	for (int i = 0; i < OrganismQueue.size(); i++)
	{
		if (OrganismQueue[i]->GetAlive() == false)
		{
			Organism* o = OrganismQueue[i];
			delete o;
			OrganismQueue.erase(OrganismQueue.begin() + i);
			i--;
		}
	}
	stable_sort(OrganismQueue.begin(), OrganismQueue.end(), InitComp);
}

void World::DeleteAll()
{
	for (int i = 0; i < OrganismQueue.size(); i++)
	{
		Organism* o = OrganismQueue[i];
		delete o;
		OrganismQueue.erase(OrganismQueue.begin() + i);
		i--;
	}
}