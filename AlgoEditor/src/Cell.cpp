#include "Cell.h"



Cell::Cell(sf::Vector2f pos)
	:m_typeCell(NONE_T)
{

	m_shape.setFillColor(sf::Color::White);
	m_shape.setOutlineColor({ 0xA9, 0xA9, 0xA9 });
	m_shape.setOutlineThickness(2);
	m_shape.setPosition(pos);
	m_shape.setSize(sf::Vector2f(25, 25));
	

}

const sf::RectangleShape& Cell::getShape() const
{
	return m_shape;
}

