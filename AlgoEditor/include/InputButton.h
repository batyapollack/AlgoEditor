#pragma once
#include "Button.h"
#include "WindowInput.h"

class InputButton:public Button
{
public:
	InputButton(Board& b);
	ButtonType getBtnType()  override;
	void execute(sf::Vector2i loc)override;
};

