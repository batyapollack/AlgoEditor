#pragma once
#include "Button.h"

class Board;
class BackButton : public Button

{
public:

	BackButton(Board& b);
	ButtonType  getBtnType()override;
	void execute(sf::Vector2i loc)override;

private:

};

