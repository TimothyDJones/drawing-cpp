#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code. DrawingShape should be an abstract base class for Circle and Square
class DrawingShape 
{
private:
	sf::Color color;
	sf::Vector2f position = sf::Vector2f(0.0, 0.0);

public:
	virtual void drawShape(sf::Window) = 0;
	
	void setPosition(sf::Vector2f pos)
	{
		this->position.x = pos.x;
		this->position.y = pos.y;
	}

	sf::Vector2f getPosition()
	{
		return this->position;
	}

	void setColor(sf::Color col)
	{
		this->color = col;
	}

	sf::Color getColor()
	{
		return this->color;
	}
	

};

class Circle : public DrawingShape
{
private:
	float radius = 0.0;

public:
	void drawShape(sf::RenderWindow &renderWindow)
	{

	}

	void setRadius(float rad)
	{
		this->radius = rad;
	}

	float getRadius()
	{
		return this->radius;
	}
};

class Square : public DrawingShape
{
private:
	float sideLength = 0.0;

public:
	void drawShape(sf::RenderWindow &renderWindow)
	{
		sf::RectangleShape sq;
		sq.setSize(sf::Vector2f(this->sideLength, this->sideLength));
		sq.setPosition(this->getPosition());
		sq.setFillColor(this->getColor());
		sq.setOutlineColor(this->getColor());

		renderWindow.draw(sq);		
	}

};

