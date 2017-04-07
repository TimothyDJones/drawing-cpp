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
	string shapeName;

public:
	virtual void drawShape(sf::Window);
	
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

	void setShapeName(string sName)
	{
		this->shapeName = sName;
	}

	string getShapeName()
	{
		return this->shapeName;
	}
};

class Circle : public DrawingShape
{
private:
	float radius = 0.0;

public:
	Circle(float radius)
	{
		this->radius = radius;
		this->setShapeName("circle");
	}

	void drawShape(sf::RenderWindow &renderWindow)
	{
		sf::CircleShape cir;
		cir.setRadius(this->getRadius());
		cir.setPosition(this->getPosition());
		cir.setFillColor(this->getColor());
		cir.setOutlineColor(this->getColor());

		renderWindow.draw(cir);
	}

	void setRadius(const float rad)
	{
		this->radius = rad;
	}

	const float getRadius() const
	{
		return this->radius;
	}
};

class Square : public DrawingShape
{
private:
	float sideLength = 0.0;

public:
	Square(float sideLength)
	{
		this->sideLength = sideLength;
		this->setShapeName("square");
	}

	void drawShape(sf::RenderWindow &renderWindow)
	{
		sf::RectangleShape sq;
		sq.setSize(sf::Vector2f(this->sideLength, this->sideLength));
		sq.setPosition(this->getPosition());
		sq.setFillColor(this->getColor());
		sq.setOutlineColor(this->getColor());

		renderWindow.draw(sq);		
	}

	void setSideLength(float sLength)
	{
		this->sideLength = sLength;
	}

	const float getSideLength() const
	{
		return this->sideLength;
	}

};

