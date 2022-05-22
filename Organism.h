#pragma once
#include "World.h"
#include "Point.h"

class World;

class Organism {
private:
	int strength;
	int initiative;
	Point position;
	bool alive;
protected:
	World& world;
public:
	Organism(World& world, const Point& position, const int& strength, const int& initiative, const bool& alive);
	void SetStrength(const int& s);
	virtual void Action() = 0;
	virtual void Collision(Organism* other) = 0;
	virtual void Draw() = 0;
	int GetStrength();
	int GetInitiative();
	Point GetPosition() const;
	void SetPosition(const Point& p);
	bool GetAlive();
	void SetAlive(const bool& alive);
	World GetWorld();
	virtual Point GetRandomPoint(const Point& p, bool top = true, bool bot = true, bool left = true, bool right = true);
	virtual Point GetRandomSafePoint(const Point& p);
	void CheckBorders(const Point& p, bool& top, bool& bot, bool& left, bool& right);
	virtual std::string GetName() = 0;
	virtual Organism* Birth(const Point& position) = 0;
	~Organism() {};
};