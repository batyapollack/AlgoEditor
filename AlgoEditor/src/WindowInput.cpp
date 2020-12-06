#include "WindowInput.h"

const std::string INPUT_STR = "Please insert number between 5- 30:";
const std::string WRONG_INPUT = "The input is not valid!";


WindowInput::WindowInput()
	:m_inputWindow(sf::VideoMode(550, 230), "Input", sf::Style::Titlebar),m_number(0)
{
	m_inputText.setFont(MediaSource::instance().getFont());
	m_inputText.setString(INPUT_STR);
	m_inputText.setPosition(0, 0);
	m_inputUser.setFont(MediaSource::instance().getFont());
	m_inputUser.setPosition(0,30);
	m_wrongInput.setFont(MediaSource::instance().getFont());
	m_wrongInput.setFillColor(sf::Color::Red);
	m_wrongInput.setPosition(0, 30);
	getInput();
	

}

void WindowInput::getInput()
{
	draw();

	while (m_inputWindow.isOpen())
	{
		handleEvent();
		
		
	}


}

void WindowInput::handleEvent()
{
	sf::Event event;
	while (m_inputWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_inputWindow.close();
			break;

		case sf::Event::TextEntered:
			m_wrongInput.setString("");
			if (event.text.unicode== ENTER)
			{
				
				
				if (validInput())
					m_inputWindow.close();
				
					m_input = "";
				
				return;
			}
			else if (event.text.unicode == BACK_SPACE)
			{

				m_input = m_input.substr(0, m_input.size() - 1);
				m_inputUser.setString(m_input);
				draw();
				break;
			}
			std::string temp;
			temp = event.text.unicode;
			m_input.append(temp);

			m_inputUser.setString(m_input);
			draw();
			break;
		}

	}

}

void WindowInput::draw()
{
	m_inputWindow.clear();
	m_inputWindow.draw(m_inputText);
	m_inputWindow.draw(m_inputUser);
	m_inputWindow.draw(m_wrongInput);
	m_inputWindow.display();

}

bool WindowInput::validInput() noexcept
{
	for (int i = 0; i < m_input.size(); i++)
	{
		if (!isdigit(m_input[i]))
		{
			m_number = 0;
			m_input.clear();
			m_inputUser.setString("");
			m_wrongInput.setString(WRONG_INPUT);
			draw();
			return false;
		}
	}

	m_number = std::stoi(m_input);
	if (m_number > MAX_DIMENSION || m_number < MIN_DIMENSION)
	{
		m_number = 0;
		m_input.clear();
		m_inputUser.setString("");
		m_wrongInput.setString(WRONG_INPUT);
		draw();
		return false;
	}
	return true;


}
