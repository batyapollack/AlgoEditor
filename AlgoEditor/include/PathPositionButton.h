#pragma once
#include "Button.h"
#include <SFML/Graphics.hpp>

class Board;

class PathPositionButton : public Button
{
public:
	PathPositionButton(Board& b);
	ButtonType getBtnType() override;
	 void execute(sf::Vector2i loc)override;
	
private:
	

};

