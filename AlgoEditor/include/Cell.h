#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "MediaSource.h"
;
class Cell
{
public:
	Cell(sf::Vector2f pos);
	const sf::RectangleShape& getShape()const;
	void setColor(sf::Color color) { m_shape.setFillColor(color); }
	ButtonType getTypeCell()const { return m_typeCell; }
	void setTypeCell(ButtonType type) { m_typeCell = type; }
	

private:
	sf::RectangleShape m_shape;
	bool m_cellEmpty = true;
	ButtonType m_typeCell;
	
};