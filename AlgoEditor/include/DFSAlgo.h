#pragma once
#include "AlgoCommand.h"




class DFSAlgo: public AlgoCommand
{
public:
	DFSAlgo(Board& b, sf::RenderWindow& window);
	void execute()override;


private:
	void searchPath(sf::Vector2i pos);
	void buildAdjacents();
	std::vector<std::vector<bool>> m_visited;
	std::vector < std::vector  <std::vector < sf::Vector2i >>> m_adjacents;
	bool m_finish;
};

