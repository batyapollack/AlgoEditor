#include "AlgoCommand.h"



AlgoCommand::AlgoCommand(Board& board, sf::RenderWindow& window)
	:m_board(board), m_window(window), m_countStep(0)
{
	
	m_button_algo.setTexture(MediaSource::instance().getTexture(CIRECLE_ALGO_P));
	m_text.setFont(MediaSource::instance().getFont());
	m_text.setCharacterSize(100);
	m_text.setOrigin(100, 100);
	m_text.setFillColor(sf::Color::Yellow);
     m_start_pos = m_board.getStartPos();
	 m_end_pos = m_board.getEndPos();
	 


}

void AlgoCommand::draw(sf::RenderWindow& window)
{

	m_rectangle.setSize({ m_float_rect.height, m_float_rect.width });
	m_rectangle.setPosition({ m_float_rect.left,m_float_rect.top });
	m_rectangle.setOutlineColor(sf::Color::White);
	auto changeRectColor = [&]
	{
		if (m_flagColor)
		{
			m_rectangle.setOutlineThickness(0.8);
			m_rectangle.setFillColor(LIGHT_BLUE);
			m_text.setFillColor(sf::Color::White);

		}
		else
		{
			m_rectangle.setOutlineThickness(0);
			m_rectangle.setFillColor(sf::Color::Blue);
			m_text.setFillColor(sf::Color::Yellow);
		}
	};
	changeRectColor();


	window.draw(m_rectangle);
	window.draw(m_text);
}

void AlgoCommand::highLightColorShape(bool flag)
{
	m_flagColor = flag;
}

void AlgoCommand::copyBoolMatrix()
{
	m_board.copyBoolMatrix(m_bool_matrix);
}

bool AlgoCommand::initialGraph()
{
	copyBoolMatrix();
	m_start_pos = m_board.getStartPos();
	m_end_pos = m_board.getEndPos();
	m_countStep = 0;
	if (!posIsValid())
		return false;
	
	return true;
}



int AlgoCommand::displayResourceMessageBox()
{
	
	int msgboxID = MessageBox(
			NULL,
		"Resource not available\nPlease choose valid path!",
		"Error",
			MB_OK | MB_ICONWARNING
		);
		return msgboxID;
}

int AlgoCommand::displayNoValidPathMessageBox()
{
	int msgboxID = MessageBox(
		NULL,
		"No route found!",
		"Error",
		MB_OK | MB_ICONWARNING
	);
	return msgboxID;
}




bool AlgoCommand::posIsValid() const
{
	if (m_start_pos == sf::Vector2i{ -1,-1 } || m_end_pos == sf::Vector2i{ -1,-1 })
	{
		displayResourceMessageBox();
		return false;
	}
	return true;
}

void AlgoCommand::draw(int t)
{
	m_window.clear();
	m_board.drawMatrix();
	m_window.display();
	sf::Time time = sf::microseconds(3*t);
	sf::sleep(time);

}
