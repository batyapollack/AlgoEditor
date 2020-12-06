#pragma once
#include <SFML/Graphics.hpp>
#include "MediaSource.h"
#include "Macros.h"

class Board;
using namespace ButtonsPositions;


class Button
{
public:
	Button(Board& b);

	const sf::Sprite& getSprite() const{ return m_sprite; };
	const sf::FloatRect& getGlobalBounds()const { return m_float_rect; };
	void setTexture(PICTURES_TYPE i,bool val);
	virtual ButtonType  getBtnType()=0;
	virtual void execute(sf::Vector2i loc) = 0;
	





protected:
	Board& m_board;
	 
	sf::Sprite m_sprite;  //SFML SPRITE THAT HOLD THE SPRITE 
	sf::FloatRect m_float_rect; // HOLD THE GlobalBounds SPRITE
};

