#pragma once
#include "Button.h"
class Board;



class ObstacleButton : public Button
{
public:
	ObstacleButton(Board& b);
	ButtonType getBtnType()  override;
	void execute(sf::Vector2i loc)override;

private:

};

