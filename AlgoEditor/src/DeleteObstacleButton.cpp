#include "DeleteObstacleButton.h"
#include "Board.h"

DeleteObstacleButton::DeleteObstacleButton(Board& b)
	:Button(b)
{

	m_sprite.setPosition(DEL_OBS_BUT);
	m_sprite.setTexture(MediaSource::instance().getTexture(DEL_P));
	m_float_rect = m_sprite.getGlobalBounds();
}

ButtonType DeleteObstacleButton::getBtnType()
{
	return DELETE_T;
}

void DeleteObstacleButton::execute(sf::Vector2i loc)
{

	if (m_board.getCellType(loc) == PATH_POS_T)
	{
		if (loc == m_board.getStartPos())
			m_board.setStartPos(INITIAL_POS_PATH);
		else
			m_board.setEndPos(INITIAL_POS_PATH);
	}
	m_board.setCellType(loc, NONE_T);
	m_board.setCellColor(loc, sf::Color::White);
	m_board.setBoolCell(loc, true);


}
