#pragma once
#include "AlgoCommand.h"
#include<array>
#include<queue>




struct GraphNodeBFS
{
	sf::Vector2i m_previous; // previous cordes
	DIRECTION m_prevDirec; // prev direc
	bool m_pass; // if node did pass
	GraphNodeBFS() : m_previous(-1, -1), m_prevDirec(NONE_D), m_pass(false) {}; //Ctor of  GraphNode
};

class BFSAlg: public AlgoCommand
{
public:
	BFSAlg(Board& b,sf::RenderWindow& window);
	void execute() override;
	void initilize();

private:
	void clearQueue(std::queue<sf::Vector2i>& q);
	
	bool searchPath();
	void initialGraphNodeBFS();
	void showMinPath();
	std::queue<sf::Vector2i> m_nodeQueue; // make queue to maze
	std::list <DIRECTION> m_path; // the path
	std::vector<std::vector<GraphNodeBFS>> m_edges; // to save every node prev
};

