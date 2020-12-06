#include "MenuAlgo.h"

MenuAlgo::MenuAlgo(sf::RenderWindow& window)
	:m_window(window)
{
	m_rect.setSize({ 150,450 });
	m_rect.setPosition({ 20,160 });
	m_float_rect = m_rect.getGlobalBounds();
}

void MenuAlgo::add(const std::string s, std::unique_ptr<AlgoCommand> algo)
{
	m_options.emplace_back(option(s,move (algo)));
}

void MenuAlgo::drawMenuAlgo()
{
	for (int i = 0; i < m_options.size(); i++)
		m_options[i].second->draw(m_window);
}

void MenuAlgo::chooseAlgo(sf::Vector2f pos)
{
	for (int i = 0; i < m_options.size(); i++)
		if (m_options[i].second.get()->getGlobalBounds().contains(pos))
		{
			m_options[i].second.get()->execute();
			m_countSteps = m_options[i].second.get()->getCountSteps();
			m_nameChoosenAlgo = m_options[i].first;
			return;
		}
	

}

void MenuAlgo::changeFloatRectColor(const sf::Vector2f& pos)
{
	for (int i = 0; i < m_options.size(); i++)
		if (m_options[i].second.get()->getGlobalBounds().contains(pos))
		{
			m_options[i].second.get()->highLightColorShape(true);
			m_spritePair.first = i;
			return;
		}
	m_options[m_spritePair.first].second.get()->highLightColorShape(false);
}

unsigned int MenuAlgo::getCountSteps() const
{
	return m_countSteps;
}


