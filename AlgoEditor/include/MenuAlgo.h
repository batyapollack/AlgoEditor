#pragma once
#include <vector>
#include "AlgoCommand.h"
#include <algorithm>
#include <string>
#include <iostream>



class MenuAlgo
{
public:
	MenuAlgo(sf::RenderWindow& window);
	void add(const std::string s, std::unique_ptr<AlgoCommand> algo);
	void drawMenuAlgo();
	void chooseAlgo(sf::Vector2f pos);
	const sf::FloatRect& getGlbalBoundMenuAlgo()const { return m_float_rect; }
	void changeFloatRectColor(const sf::Vector2f& mousePosF);
	unsigned int getCountSteps()const;
	std::string getNameAlgo() const { return m_nameChoosenAlgo; }
	
private:
	typedef std::pair<const std::string, std::unique_ptr<AlgoCommand>> option;
	std::vector<option> m_options;
	std::pair<int, bool> m_spritePair;
	std::string m_nameChoosenAlgo;
	sf::RenderWindow& m_window;
	sf::RectangleShape m_rect;
	sf::FloatRect m_float_rect;
	unsigned int m_countSteps;
};

