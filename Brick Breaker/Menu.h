#pragma once
#define max_main_menu 3
#include <SFML/Graphics.hpp>
class menu
{
public:

	menu(float width, float height);
	void draw(sf::RenderWindow& window);
	void moveup();
	void movedown();
	int mainmenupressed()
	{
		return mainmenuselected;
	}
	~menu();

private:

	int mainmenuselected;
	sf::Font font;
	sf::Text mainmenu[max_main_menu];

};