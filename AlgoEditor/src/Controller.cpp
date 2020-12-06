#include "Controller.h"
#include "Macros.h"



// Inner singleton
Controller& Controller::getInstance()
{
	static Controller instance;
	return instance;
}

Controller::Controller()
	:m_input(), m_window(sf::VideoMode(1280, 720), "AlgoGraph", sf::Style::Close | sf::Style::Titlebar),
	m_menuBtn(m_window), m_board(m_window, m_menuBtn), m_menuAlgo(m_window)
{
	m_textStepAlgo.setString("0");
}

void Controller::draw()
{
	m_window.clear();
	m_menuBtn.drawMenu();
	m_board.drawMatrix();
	m_menuAlgo.drawMenuAlgo();
	auto printSteps = [&]
	{
		sf::Text a;
		a.setPosition({ 20 , 500 });

		a.setString("Algorithm: " + m_nameAlgo.getString() + "\n" + "Steps: " + m_textStepAlgo.getString());
		a.setFillColor(sf::Color::White);
		a.setFont(MediaSource::instance().getFont());

		a.setScale(0.6, 0.6);
		m_window.draw(a);

	};
	printSteps();
	m_window.display();

}



bool Controller::buttomPressed(sf::Vector2f posMouse, sf::Vector2i cellCurrPos)
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		if (m_menuBtn.getRectMenuGlobalBounds(RECT_MENU_T).contains(posMouse))
		{
			m_menuBtn.chooseBtn(posMouse);
			if (m_menuBtn.getCurrButtonType() == REF_T || m_menuBtn.getCurrButtonType() == BACK_T
				|| m_menuBtn.getCurrButtonType() == INPUT_T)
			{
				m_textStepAlgo.setString("0");
				m_nameAlgo.setString("");
				draw();
			}

		}
		else if (m_menuAlgo.getGlbalBoundMenuAlgo().contains(posMouse))
		{
			m_menuAlgo.chooseAlgo(posMouse);
			m_textStepAlgo.setString(std::to_string(m_menuAlgo.getCountSteps()));
			m_nameAlgo.setString(m_menuAlgo.getNameAlgo());


		}

		else if (m_board.checkClickGrid(posMouse))
		{
			cellCurrPos = m_board.getLocationClickOnMatrix(sf::Vector2i(posMouse));
			m_board.checkAndSetCell(cellCurrPos);
		}


		draw();
		return true;
	}
	return false;
}




void Controller::run()
{
	m_board.read(m_input.getNumber());
	m_board.drawMatrix();
	buildMenuAlgo();
	buildMenuBtn();
	m_menuAlgo.drawMenuAlgo();
	m_menuBtn.drawMenu();
	m_window.display();




	while (m_window.isOpen())
	{
		handleEvents();

	}


}

void Controller::handleEvents()
{
	sf::Vector2i cellCurrPos;
	sf::Event event;
	sf::Vector2f posMouse = (sf::Vector2f)sf::Mouse::getPosition(m_window);
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		}


	}
	if (!buttomPressed(posMouse, cellCurrPos));//no press 
	{
		auto cursorPos = (sf::Vector2f)sf::Mouse::getPosition(m_window);
		sf::Vector2f mousePosF(static_cast<float>(cursorPos.x), static_cast<float>(cursorPos.y));
		m_menuBtn.changeSpriteBtn(mousePosF);
		m_menuAlgo.changeFloatRectColor(mousePosF);
		draw();
	}
}

void Controller::buildMenuAlgo()
{
	m_menuAlgo.add("BFS", std::make_unique<BFSAlg>(m_board, m_window));
	m_menuAlgo.add("DFS", std::make_unique<DFSAlgo>(m_board, m_window));
	m_menuAlgo.add("A*", std::make_unique<AStarAlgo>(m_board, m_window));
}

void Controller::buildMenuBtn()
{
	m_menuBtn.add("ROUTE", std::make_unique<PathPositionButton>(m_board));
	m_menuBtn.add("BRICK", std::make_unique<ObstacleButton>(m_board));
	m_menuBtn.add("DEL", std::make_unique<DeleteObstacleButton>(m_board));
	m_menuBtn.add("REFRESH", std::make_unique<RefreshButton>(m_board));
	m_menuBtn.add("BACK", std::make_unique<BackButton>(m_board));
	m_menuBtn.add("INPUT", std::make_unique<InputButton>(m_board));

}

