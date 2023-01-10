#include "Menu.h"


menu::menu(float width, float height)
{

	if (!font.loadFromFile("C:/Users/HP Zbook/source/repos/Brick Breaker/Font/arial.ttf")) {}


	//play
	mainmenu[0].setFont(font);
	mainmenu[0].setFillColor(sf::Color::Yellow);
	mainmenu[0].setString("Play");
	mainmenu[0].setCharacterSize(50);
	mainmenu[0].setPosition(sf::Vector2f(width / 2, height / (max_main_menu + 1)));


	//option
	mainmenu[1].setFont(font);
	mainmenu[1].setFillColor(sf::Color::White);
	mainmenu[1].setString("Credits ");
	mainmenu[1].setCharacterSize(50);
	mainmenu[1].setPosition(sf::Vector2f(width / 2, height / (max_main_menu + 1) * 2));


	//exit
	mainmenu[2].setFont(font);
	mainmenu[2].setFillColor(sf::Color::White);
	mainmenu[2].setString("Exit");
	mainmenu[2].setCharacterSize(50);
	mainmenu[2].setPosition(sf::Vector2f(width / 2, height / (max_main_menu + 1) * 3));


	mainmenuselected = 0;

}


menu::~menu()
{

}


//function of drawing main menu
void menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainmenu[i]);
	}
}


//move down
void menu::movedown()
{
	if (mainmenuselected + 1 <= max_main_menu)//check if not on the last item (exit)
	{
		mainmenu[mainmenuselected].setFillColor(sf::Color::White);//check the previous item's color
		mainmenuselected++; //move to the lower item
		if (mainmenuselected == 3)
		{
			mainmenuselected = 0;
		}
		mainmenu[mainmenuselected].setFillColor(sf::Color::Yellow); //change the new items color
	}
}


//move up
void menu::moveup()
{
	if (mainmenuselected - 1 >= -1)//check if not on the first item (start)
	{
		mainmenu[mainmenuselected].setFillColor(sf::Color::White);//check the previous item's color

		mainmenuselected--; //move to the upper item
		if (mainmenuselected == -1)
		{
			mainmenuselected = 2;
		}
		mainmenu[mainmenuselected].setFillColor(sf::Color::Yellow); //change the new items color
	}
}
