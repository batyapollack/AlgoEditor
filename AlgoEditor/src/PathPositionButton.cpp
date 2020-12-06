#include "PathPositionButton.h"
#include "Board.h"


PathPositionButton::PathPositionButton(Board& b)
	:Button(b)
{

	m_sprite.setPosition( PATH_POS_BUT);
	m_sprite.setTexture(MediaSource::instance().getTexture(ROUTE_P));
	m_float_rect = m_sprite.getGlobalBounds();
	

}

ButtonType PathPositionButton::getBtnType()
{
	return PATH_POS_T;
}

void PathPositionButton::execute(sf::Vector2i loc)
{
	if (m_board.getStartPos() == INITIAL_POS_PATH)
	{
		m_board.setCellColor(loc, sf::Color::Blue);
		m_board.setCellType(loc, PATH_POS_T);
		m_board.setStartPos(loc);
	}
	else if (m_board.getEndPos() == INITIAL_POS_PATH)
	{
		m_board.setCellColor(loc, sf::Color::Blue);
		m_board.setCellType(loc, PATH_POS_T);
		m_board.setEndPos(loc);
	}

}
