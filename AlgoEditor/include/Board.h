#pragma once
#include<vector>
#include<string>
#include "Cell.h"
#include <iostream>
#include "MenuButton.h"
#include "Macros.h"
using namespace GridProperties;


class Board
{
public:

	Board(sf::RenderWindow& window, MenuButton& menu);
	void read(int num);
	void drawMatrix();
	unsigned int getMatrixSize()const { return m_matrix.size(); }
	void checkAndSetCell(sf::Vector2i cell);
	bool checkClickGrid(sf::Vector2f posMouse)const;
	sf::Vector2i getLocationClickOnMatrix(sf::Vector2i loc) const;
	void copyBoolMatrix(std::vector<std::vector<bool>>& m_bool_matrix);
	sf::Vector2i getStartPos()const { return m_startPath; }
	void setStartPos(const sf::Vector2i& pos) { m_startPath = pos; }
	sf::Vector2i getEndPos()const { return m_endPath; }
	void setEndPos(const sf::Vector2i& loc) { m_endPath = loc; }
	void setCellColor(sf::Vector2i loc, sf::Color color);
	ButtonType getCellType(sf::Vector2i loc)const;
	void setCellType(sf::Vector2i loc,ButtonType type);
	void setBoolCell(sf::Vector2i loc, bool flag);

	void refreshBoard();
	void refreshBackBoard();
	





private:
	std::vector<std::vector<std::unique_ptr <Cell>>> m_matrix;
	std::vector<std::vector<bool>> m_boolMatrix;
	sf::RenderWindow& m_window;
	MenuButton& m_menu;

	sf::Vector2i m_startPath = {-1, -1};
	sf::Vector2i m_endPath = { -1, -1 };

};

