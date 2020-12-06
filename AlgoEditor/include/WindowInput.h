#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include "MediaSource.h"
#include "Macros.h"

constexpr int MAX_DIMENSION = 30;
constexpr int MIN_DIMENSION = 5;

class WindowInput
{
public:

	WindowInput();
	void getInput();
	void handleEvent();
	int getNumber()const { return m_number; }
	void draw();
	bool validInput()noexcept;


private:
	sf::RenderWindow m_inputWindow;
	int m_number=0;
	std::string m_input;

	sf::Text m_inputText;
	sf::Text m_wrongInput;

	sf::Text m_inputUser;
	


};

