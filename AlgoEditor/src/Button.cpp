#include "Button.h"
#include "Board.h"

Button::Button(Board& b)
	:m_board(b)
{
}

void Button::setTexture(PICTURES_TYPE i,bool val)
{
	if(val)
	m_sprite.setTexture(MediaSource::instance().getTexture(i));
	else 
		m_sprite.setTexture(MediaSource::instance().getTextureHighlight(i));
}



