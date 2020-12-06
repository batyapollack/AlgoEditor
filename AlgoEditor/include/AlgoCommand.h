#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include <list>
#include "Board.h"
using namespace ButtonsAlgoPositions;





class AlgoCommand
{
public:
	AlgoCommand(Board& m_board, sf::RenderWindow& window);
	virtual void execute() = 0 ;
    void draw(sf::RenderWindow& window );
	void highLightColorShape(bool flag);
	void copyBoolMatrix();
	const sf::FloatRect& getGlobalBounds()const { return m_float_rect; };
	bool initialGraph();
	unsigned int getCountSteps()const {return m_countStep;};

	static int displayResourceMessageBox();
	static int displayNoValidPathMessageBox();

	
	
protected:
	
	bool posIsValid()const;
	void draw(int time);

	unsigned int m_countStep;
	sf::Sprite m_button_algo;
	sf::RectangleShape m_rectangle;
	sf::FloatRect m_float_rect;
	sf::Text m_text;
	Board& m_board;
	sf::RenderWindow& m_window;
	std::vector<std::vector<bool>> m_bool_matrix;
	sf::Vector2i m_start_pos;
	sf::Vector2i m_end_pos;

	bool m_flagColor = false;

	
	


};

