#pragma once
#include "Button.h"
class RefreshButton: public Button
{
public:

	
	RefreshButton(Board& b);
	ButtonType getBtnType()  override;
	void execute(sf::Vector2i loc)override;

private:


};

