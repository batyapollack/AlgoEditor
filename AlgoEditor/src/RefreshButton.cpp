#include "RefreshButton.h"
#include "Board.h"

RefreshButton::RefreshButton(Board& b)
	:Button(b)
{
	/*m_button.setPosition(OBS_REFRESH);
	m_button.setFillColor(sf::Color::Blue);*/
	m_sprite.setPosition(OBS_REFRESH);
	m_sprite.setTexture(MediaSource::instance().getTexture(REFRESH_P));
	m_float_rect = m_sprite.getGlobalBounds();
	
}



ButtonType RefreshButton::getBtnType()
{
	
	return REF_T;
}

void RefreshButton::execute(sf::Vector2i loc)
{
	m_board.refreshBoard();
}


