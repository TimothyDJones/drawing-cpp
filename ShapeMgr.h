#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"
#include "split.h"
using namespace std;
using namespace sf;

// finish the ShapeMgr class.
// this class is responsible for maintaining all of the shapes that are drawn by the user
// add data/functions as needed

class ShapeMgr
{
private:
	// finish this code
	vector<Drawable> shapeVector;

public:

	void processMouseMove(RenderWindow& win, SettingsMgr& settings, int mouseX, int mouseY)
	{
		// finish this code
	}

	void draw(RenderWindow& win)
	{
		// finish this code
	}

	void writeToFile(ofstream& file)
	{
		// finish this code
	}

	void readFromFile(ifstream& file)
	{
		// finish this code

	}


};
