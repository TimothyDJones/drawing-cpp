#include <iostream>
#include <fstream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
using namespace sf;

// Finish this code. Other than where it has comments telling you to 
// add code, you shouldn't need to add any logic to main to satisfy
// the requirements of this programming assignment

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing");
	window.setFramerateLimit(60);

	
	SettingsMgr settingsMgr;
	ShapeMgr    shapeMgr;
	// ************ Add code here to make the managers read from shapes.txt (if the file exists)

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
			{
				window.close();
				// ****** Add code here to write all data to shapes.txt
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				// handle clicking on one of the settings buttons
				settingsMgr.processClick(window);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left))
			{
				// add a shape to our list based on current settings
				shapeMgr.processMouseMove(window, settingsMgr, event.mouseMove.x, event.mouseMove.y);
			}
		}

		// Now render one frame based on new state of settings and new state of drawn shapes
		window.clear();
		settingsMgr.draw(window);
		shapeMgr.draw(window);

		window.display();


	} // end body of animation loop

	return 0;
}