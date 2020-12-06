#include "BackButton.h"
#include "Board.h"

BackButton::BackButton(Board& b)
	:Button(b)
{

	m_sprite.setPosition(OBS_BACK);
	m_sprite.setTexture(MediaSource::instance().getTexture(BACK_P));
	m_float_rect = m_sprite.getGlobalBounds();
}

ButtonType BackButton::getBtnType()
{
	return BACK_T;
}

void BackButton::execute(sf::Vector2i loc)
{
	m_board.refreshBackBoard();
}
