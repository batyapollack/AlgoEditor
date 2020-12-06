#include "Board.h"
#include "Macros.h"

Board::Board(sf::RenderWindow& window, MenuButton& menu)
	:m_window(window), m_menu(menu)
{}

void Board::read(int num)
{
	auto clear = [&]
	{
		m_startPath = { -1,-1 };
		m_endPath = { -1,-1 };
		std::vector<std::vector<std::unique_ptr <Cell>>> m_tempMatrix;
		swap(m_matrix, m_tempMatrix);
		
		std::vector<std::vector<bool> > temp;
		swap(m_boolMatrix, temp);
	};

	clear();
	sf::Vector2f position = { 0.0f,0.0f };
	int dimX=num;
	
	m_matrix.resize(dimX);
	m_boolMatrix.resize(dimX);

	for (int i = 0; i < dimX; i++)
	{

		for (int j = 0; j < dimX; j++)
		{
			position = { float(j * SIZE_TILE+ START_GRID_ROW ), float(i * SIZE_TILE+ START_GRID_COL) };
			m_matrix[i].emplace_back(std::make_unique<Cell>(position));
			m_boolMatrix[i].emplace_back(true);
		}
	}
}

void Board::drawMatrix()
{
	for (int i = 0; i <m_matrix.size() ; i++)
		for (int j = 0; j < m_matrix[i].size(); j++)
			m_window.draw((m_matrix[i][j]).get()->getShape());	
}

void Board::checkAndSetCell(sf::Vector2i cell)
{
	if ((m_matrix[cell.x][cell.y]).get()->getTypeCell() == NONE_T)
		m_menu.activateBtn( ButtonType(m_menu.getCurrButtonType()), cell);


	if (m_menu.getCurrButtonType() == DELETE_T)
		m_menu.activateBtn(DELETE_T, cell);	
}

bool Board::checkClickGrid(sf::Vector2f posMouse)const
{
	if (!(posMouse.x > START_GRID_ROW
		&& posMouse.y > START_GRID_COL
		&& posMouse.y < START_GRID_COL + (m_matrix.size() * SIZE_TILE)
		&& posMouse.x < START_GRID_ROW + (m_matrix.size() * SIZE_TILE)))
		return false;
	return true;
}

sf::Vector2i Board::getLocationClickOnMatrix(sf::Vector2i loc) const
{
	sf::Vector2i curr_loc;

	curr_loc.y = (unsigned int)(loc.x - START_GRID_ROW); //col
	curr_loc.y /= (unsigned int)SIZE_TILE;
	curr_loc.x = (unsigned int)(loc.y - START_GRID_COL);//row
	curr_loc.x /= (unsigned int)SIZE_TILE;

	return curr_loc;
}

void Board::copyBoolMatrix(std::vector<std::vector<bool>>& boolMatrix)
{
	boolMatrix = m_boolMatrix;
}

void Board::setCellColor(sf::Vector2i loc,sf::Color color)
{
	m_matrix[loc.x][loc.y].get()->setColor(color);
}

ButtonType Board::getCellType(sf::Vector2i loc) const
{
	return m_matrix[loc.x][loc.y].get()->getTypeCell();
}

void Board::setCellType(sf::Vector2i loc,ButtonType type)
{
	m_matrix[loc.x][loc.y].get()->setTypeCell(type);

}

void Board::setBoolCell(sf::Vector2i loc, bool flag)
{
	m_boolMatrix[loc.x][loc.y] = flag;
}

void Board::refreshBoard()
{
	for (int i = 0; i < m_matrix.size(); i++)
		for (int j = 0; j < m_matrix[i].size(); j++)
		{
				m_matrix[i][j].get()->setTypeCell(NONE_T);
				m_matrix[i][j].get()->setColor(sf::Color::White);
				m_boolMatrix[i][j] = true;
		
		}

	m_startPath = { -1,-1 };
	m_endPath = { -1,-1 };
}

void Board::refreshBackBoard()
{
	for (int i = 0; i < m_matrix.size(); i++)
		for (int j = 0; j < m_matrix[i].size(); j++)
			if(m_matrix[i][j].get()->getTypeCell()!=OBSTACLE_T &&
				m_matrix[i][j].get()->getTypeCell() !=PATH_POS_T)
		{
			m_matrix[i][j].get()->setTypeCell(NONE_T);
			m_matrix[i][j].get()->setColor(sf::Color::White);
			m_boolMatrix[i][j] = true;

		}

}




