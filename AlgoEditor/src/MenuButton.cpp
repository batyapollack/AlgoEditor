#include "MenuButton.h"
#include "Macros.h"
;
MenuButton::MenuButton(sf::RenderWindow& window)
	:m_window(window),m_rects(5)
{
	initialMenu();
	drawMenu();
}

void MenuButton::initialMenu()
{

	m_shape_menu.setSize(sf::Vector2f(55, 260));
	m_shape_menu.setOutlineColor({ 94, 102, 109 });
	m_shape_menu.setFillColor({ 0xD3, 0xD3, 0xD3 });
	m_shape_menu.setOutlineThickness(5);
	m_shape_menu.setPosition(35, 25);

	m_rects[RECT_MENU_T] = m_shape_menu.getGlobalBounds();
	

}

void MenuButton::drawMenu()
{
	m_window.draw(m_shape_menu);
	for (int i = 0; i < m_options.size(); i++)
		m_window.draw(m_options[i].second.get()->getSprite());
	
}

void MenuButton::add(const std::string s, std::unique_ptr<Button> btn)
{
	m_options.emplace_back(option(s, move(btn)));
}

void MenuButton::chooseBtn(const sf::Vector2f& pos)
{
	m_currBtnType = NONE_T;
	for (int i = 0; i < m_options.size(); i++)
		if (m_options[i].second.get()->getGlobalBounds().contains(pos))
		{
			m_currBtnType =m_options[i].second.get()->getBtnType();

			if (m_currBtnType == REF_T|| m_currBtnType == BACK_T || m_currBtnType== INPUT_T)
				m_options[i].second.get()->execute((sf::Vector2i) pos);
		
			return;
		}
	
}

void MenuButton::changeSpriteBtn(const sf::Vector2f& pos)
{
	for (int i = 0; i < m_options.size(); i++)
		if (m_options[i].second.get()->getGlobalBounds().contains(pos))
		{
			m_spritePair.first = m_options[i].second.get()->getBtnType();
			m_spritePair.second = false;
			m_options[i].second.get()->setTexture(PICTURES_TYPE(m_spritePair.first), m_spritePair.second);

			return;
		}
	m_options[m_spritePair.first].second.get()->setTexture(PICTURES_TYPE(m_spritePair.first), true);
	
	//m_currBtnType = NONE_T;
}

void MenuButton::activateBtn(ButtonType type, sf::Vector2i cell)
{
	if (type < m_options.size()&& type> -1
		&&type!= REF_T&&type!=BACK_T&& type != INPUT_T)
	m_options[type].second.get()->execute(cell);

}


