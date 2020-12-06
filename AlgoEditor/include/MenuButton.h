#pragma once
#include <vector>
#include "PathPositionButton.h"
#include "DeleteObstacleButton.h"
#include "ObstacleButton.h"
#include "RefreshButton.h"
#include "BackButton.h"
#include "Button.h"

class MenuButton
{
public:
	MenuButton(sf::RenderWindow& window);
	const sf::FloatRect& getRectMenuGlobalBounds(int i)const { return m_rects[i]; }
	int getCurrButtonType()const { return m_currBtnType; }
	void drawMenu();
	void add(const std::string s, std::unique_ptr<Button> algo);
	void chooseBtn(const sf::Vector2f& pos);
	void changeSpriteBtn(const sf::Vector2f& pos);
	void activateBtn(ButtonType type, sf::Vector2i cell);

private:
	void initialMenu();
	sf::RenderWindow& m_window;
	typedef std::pair<const std::string, std::unique_ptr<Button>> option;
	std::vector<option> m_options;
	std::pair<int, bool> m_spritePair;
	sf::RectangleShape m_shape_menu;
	int m_currBtnType;
	std::vector<sf::FloatRect> m_rects;


	

};

