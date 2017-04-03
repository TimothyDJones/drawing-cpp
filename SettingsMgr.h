#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Util.h"
using namespace std;
using namespace sf;

// Finish this class. SettingsMgr is responsible for maintaining the current
// settings:
// -current drawing color
// -current shape (circle or square)
// -current size (small, med, large)
// This class also renders the "buttons" for the user to click on, 
// and updates the current settings when the user clicks on a button

class SettingsMgr
{
private:
	sf::Color currentDrawingColor;
	std::string currentDrawingShape;

	sf::CircleShape blueBtn, greenBtn, redBtn, circleBtn;
	sf::RectangleShape squareBtn;

	sf::Text drawingColorLabel;
	sf::Text drawingShapeLabel;

	const float BUTTON_RADIUS = 10.0;
	const string COLOR_LABEL = "Drawing Color";
	const string SHAPE_LABEL = "Drawing Shape";


public:
	SettingsMgr()
	{
		// finish this 
		// Initialize the buttons
		squareBtn.setSize(sf::Vector2f(20.0, 20.0));
		squareBtn.setFillColor(sf::Color::Transparent);
		squareBtn.setOutlineColor(sf::Color::Black);
		squareBtn.setOutlineThickness(2);
		squareBtn.setPosition(sf::Vector2f(50.0, 450.0));

		blueBtn.setRadius(BUTTON_RADIUS);
		blueBtn.setFillColor(sf::Color::Transparent);
		blueBtn.setOutlineColor(sf::Color::Black);
		blueBtn.setOutlineThickness(2);
		blueBtn.setPosition(sf::Vector2f(50.0, 150.0));

		greenBtn = blueBtn;
		greenBtn.setPosition(sf::Vector2f(50.0, 200.0));

		redBtn = blueBtn;
		redBtn.setPosition(sf::Vector2f(50.0, 250.0));

		circleBtn = redBtn;
		circleBtn.setPointCount(sf::Vector2f(50.0, 500.0));

		// Initialize setting labels
		sf::Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("Unable to load font file!");

		drawingColorLabel.setString(COLOR_LABEL);
		drawingColorLabel.setFont(font);
		drawingColorLabel.setCharacterSize(25);
		drawingColorLabel.setPosition(sf::Vector2f(50.0, 100.0));

		drawingShapeLabel = drawingColorLabel;
		drawingShapeLabel.setString(SHAPE_LABEL);
		drawingShapeLabel.setPosition(sf::Vector2f(50.0, 400.0));
	}
	

	void processClick(RenderWindow& win)
	{
		// finish this function. This function gets called on a mouse "up" event (a click)
		// It should change the appropriate setting if a user has clicked on one
		// of the buttons. Otherwise, it does nothing
	}

	void draw(RenderWindow& win)
	{
		// finish this function. It should render all of the "buttons" that the 
		// user can click on to establish current settings
		win.draw(drawingColorLabel);
		win.draw(blueBtn);
		win.draw(greenBtn);
		win.draw(redBtn);

		win.draw(currentDrawingShape);
		win.draw(circleBtn);
		win.draw(squareBtn);
	}

	void writeToFile(ofstream& file)
	{
		string colorName;
		// finish this code
		if (sf::Color::Red == currentDrawingColor)
		{
			colorName = "Red";
		} else if (sf::Color::Green == currentDrawingColor)
		{
			colorName = "Green";
		}
		else
		{
			colorName = "Blue";
		}

		file << "settings," << colorName << "," << currentDrawingShape << endl;
	}

	void readFromFile(ifstream& file)
	{
		// finish this code
		string line, temp, colorName;
		while (getline(file, line)) {
			std::stringstream iss(line);
			std::getline(iss, temp, ',');
			if (temp == "settings")
			{
				std::getline(iss, colorName, ',');
				std::getline(iss, this->currentDrawingShape);

				if (colorName == "Green")
					this->currentDrawingColor = sf::Color::Green;					
				else if (colorName == "Blue")
					this->currentDrawingColor = sf::Color::Blue;
				else
					this->currentDrawingColor = sf::Color::Red;

				this->setActiveButtons();
				break;
			}

		}

	}

	void setActiveButtons()
	{
		// Color buttons
		if (this->currentDrawingColor == sf::Color::Green)
		{
			blueBtn.setFillColor(sf::Color::Transparent);
			greenBtn.setFillColor(sf::Color::Green);
			redBtn.setFillColor(sf::Color::Transparent);
		}
		else if (this->currentDrawingColor == sf::Color::Blue)
		{
			blueBtn.setFillColor(sf::Color::Blue);
			greenBtn.setFillColor(sf::Color::Transparent);
			redBtn.setFillColor(sf::Color::Transparent);
		} else
		{
			blueBtn.setFillColor(sf::Color::Transparent);
			greenBtn.setFillColor(sf::Color::Transparent);
			redBtn.setFillColor(sf::Color::Red);
		}

		// Shape buttons
		if (this->currentDrawingShape == "circle")
		{
			circleBtn.setFillColor(sf::Color::Black);
			squareBtn.setFillColor(sf::Color::Transparent);
		}
		else
		{
			circleBtn.setFillColor(sf::Color::Transparent);
			squareBtn.setFillColor(sf::Color::Black);
		}
	}

};
