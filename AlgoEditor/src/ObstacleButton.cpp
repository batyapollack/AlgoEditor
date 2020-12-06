#include "ObstacleButton.h"
#include "Board.h"



ObstacleButton::ObstacleButton(Board& b)
	:Button( b)

{

	m_sprite.setPosition(OBS_BUT);
	m_sprite.setTexture(MediaSource::instance().getTexture(BRICK_P));
	m_float_rect = m_sprite.getGlobalBounds();


}

ButtonType ObstacleButton::getBtnType()
{
	return OBSTACLE_T;
}

void ObstacleButton::execute(sf::Vector2i loc)
{
	m_board.setCellColor(loc, sf::Color::Black);
	m_board.setCellType(loc, OBSTACLE_T);
	m_board.setBoolCell(loc, false);
}
