#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
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
		circleBtn.setPosition(sf::Vector2f(50.0, 500.0));

		// Initialize setting labels
		sf::Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			cout << "Unable to load font file!" << endl;

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
		Vector2f mouse = win.mapPixelToCoords(Mouse::getPosition(win));
		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			blueBtn.setFillColor(sf::Color::Blue);
			currentDrawingColor = sf::Color::Blue;
		}
		else if(redBtn.getGlobalBounds().contains(mouse))
		{
			redBtn.setFillColor(sf::Color::Red);
			currentDrawingColor = sf::Color::Red;
		}
		else if (greenBtn.getGlobalBounds().contains(mouse))
		{
			greenBtn.setFillColor(sf::Color::Green);
			currentDrawingColor = sf::Color::Green;
		}
		else if (squareBtn.getGlobalBounds().contains(mouse))
		{
			squareBtn.setFillColor(sf::Color::Magenta);
			currentDrawingShape = "Square";
		}
		else if(circleBtn.getGlobalBounds().contains(mouse))
		{
			circleBtn.setFillColor(sf::Color::Magenta);
			currentDrawingShape = "Circle";
		}
	}

	void draw(RenderWindow& win)
	{
		win.draw(drawingColorLabel);
		win.draw(blueBtn);
		win.draw(greenBtn);
		win.draw(redBtn);

		win.draw(drawingShapeLabel);
		win.draw(circleBtn);
		win.draw(squareBtn);
	}

	void writeToFile(ofstream& file)
	{
		string colorName;
		if (sf::Color::Red == currentDrawingColor)
		{
			colorName = "Red";
		}
		else if (sf::Color::Green == currentDrawingColor)
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
		string line, temp, colorName;
		while (getline(file, line))
		{
			stringstream iss(line);
			getline(iss, temp, ',');
			if (temp == "settings")
			{
				getline(iss, colorName, ',');
				getline(iss, this->currentDrawingShape);

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
		}
		else
		{
			blueBtn.setFillColor(sf::Color::Transparent);
			greenBtn.setFillColor(sf::Color::Transparent);
			redBtn.setFillColor(sf::Color::Red);
		}

		// Shape buttons
		if (this->currentDrawingShape == "Circle")
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

	string returnShapeType()
	{
		return currentDrawingShape;
	}

	string returnColorType()
	{
		if (currentDrawingColor == sf::Color::Blue)
			return "Blue";
		else if (currentDrawingColor == sf::Color::Green)
			return "Green";
		else
			return "Red";
	}

	sf::Color getDrawingColor()
	{
		return this->currentDrawingColor;
	}
};
