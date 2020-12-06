#pragma once
#include "Button.h"
class Board;



class DeleteObstacleButton :public Button 
{
public:
	DeleteObstacleButton(Board& b);
	ButtonType getBtnType()  override;
	 void execute(sf::Vector2i loc)override;




private:




};

