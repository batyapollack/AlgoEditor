#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include "Board.h"
#include "MenuButton.h"
#include "MenuAlgo.h"
#include<vector>
#include "BFSAlg.h"
#include "DFSAlgo.h"
#include "AStarAlgo.h"
#include <string>
#include "WindowInput.h"
#include "InputButton.h"


class Controller
{
public:

	static Controller& getInstance();
	Controller(const Controller&) = delete;
	Controller& operator=(const Controller&) = delete;
	void run();
	void handleEvents();
	void buildMenuAlgo();
	void buildMenuBtn();
	
	

private:

	Controller();
	void draw();
	bool buttomPressed(sf::Vector2f, sf::Vector2i);
	WindowInput m_input;
	sf::RenderWindow m_window;
	MenuButton m_menuBtn;
	Board m_board;
	MenuAlgo m_menuAlgo;
	sf::Text m_textStepAlgo;
	sf::Text m_nameAlgo;
	

	


};

