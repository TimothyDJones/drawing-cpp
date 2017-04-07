#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "split.h"
#include "Shape.h"
using namespace std;
using namespace sf;

// finish the ShapeMgr class.
// this class is responsible for maintaining all of the shapes that are drawn by the user
// add data/functions as needed

class ShapeMgr
{
private:
	vector<DrawingShape> shapeVector;

	const float CIRCLE_RADIUS = 20.0;
	const float SQUARE_SIDE_LENGTH = 20.0;

public:

	void processMouseMove(RenderWindow& win, SettingsMgr& settings, int mouseX, int mouseY)
	{
		sf::Vector2f vector;
		vector.x = (float) win.getSize().x;
		vector.y = (float) win.getSize().y;
		if (mouseX < vector.x && mouseX > 50 && mouseY < vector.y )
		{
			
			if (settings.returnShapeType() == "Circle")
			{
				Circle newShape(CIRCLE_RADIUS);
				newShape.setColor(settings.getDrawingColor());
				newShape.setPosition(sf::Vector2f((float) mouseX, (float) mouseY));
				newShape.drawShape(win);
				shapeVector.push_back(newShape);
			}
			else
			{
				Square newShape(SQUARE_SIDE_LENGTH);
				newShape.setColor(settings.getDrawingColor());
				newShape.setPosition(sf::Vector2f((float) mouseX, (float) mouseY));
				newShape.drawShape(win);
				shapeVector.push_back(newShape);
			}
		}
	}

	void draw(RenderWindow& win)
	{
		for (unsigned int i = 0; i < shapeVector.size(); i++)
		{
			(shapeVector[i]);
		}
	}

	void writeToFile(ofstream& file)
	{
		for (unsigned int i = 0; i < shapeVector.size(); i++)
		{
			if (shapeVector[i].getColor() == sf::Color::Blue)
			{
				
			}
		}
	}

	void readFromFile(ifstream& file)
	{
		// finish this code

	}


};
