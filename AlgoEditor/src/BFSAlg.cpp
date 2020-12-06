#include "BFSAlg.h"



BFSAlg::BFSAlg(Board& b,sf::RenderWindow& window)
	:AlgoCommand(b,window)
{

	initilize();
}

void BFSAlg::execute()
{
	if (initialGraph())
	{
		searchPath();
		showMinPath();
	}

}

void BFSAlg::initilize()
{
	//init button
	m_button_algo.setPosition(BFS_BTN_POS);
	m_float_rect = m_button_algo.getGlobalBounds();

	//init text
	m_text.setString("BFS");
	m_text.setCharacterSize(35);
	m_text.setPosition(BFS_BTN_POS.x + 51.0f, BFS_BTN_POS.y + 55.0f);
	m_text.setScale(0.37, 0.37);

	
}







void BFSAlg::clearQueue(std::queue<sf::Vector2i>& q)
{
	std::queue<sf::Vector2i> empty;
	std::swap(q, empty);
}

bool BFSAlg::searchPath()
{
	

	initialGraphNodeBFS();

							
  // loop as long there item in the queue and destination didn't found
	m_nodeQueue.push(m_start_pos); // enter start to the queune
	m_edges[m_start_pos.x][m_start_pos.y].m_pass = true; // make start as pass
	
	while (!m_nodeQueue.empty() && !(m_edges[m_end_pos.x][m_end_pos.y].m_pass))
	{
		sf::Vector2i currNode = m_nodeQueue.front(); // get item form the quecue
		m_nodeQueue.pop(); // remove from queue

		for (size_t i = 0; i < moves.size(); i++)
		{
			sf::Vector2i temp = moves[i] + currNode; // next node to mode

													 // case temp if out bound
			if (temp.x < 0 || temp.y < 0 ||
				temp.x >= static_cast<int>(m_edges.size()) || temp.y >= static_cast<int>(m_edges[0].size()))
				continue;
			// if there wall in the maze skip it
			// or some egede pass on this egede
			if (!m_bool_matrix[temp.x][temp.y] || m_edges[temp.x][temp.y].m_pass)
				continue;

			else
			{
				m_nodeQueue.push(temp); // put node in the queue
				if (temp != m_end_pos)
				{
					m_board.setCellColor({ temp.x,temp.y }, sf::Color::Red);
					m_countStep++;
				}
				m_edges[temp.x][temp.y].m_pass = true; // set it pass
				m_edges[temp.x][temp.y].m_previous = currNode; // set it curr node
				switch (i) // set the prevDirection to the node
				{
				case 0:
					m_edges[temp.x][temp.y].m_prevDirec = UP_D;
					break;
				case 1:
					m_edges[temp.x][temp.y].m_prevDirec = DOWN_D;
					break;
				case 2:
					m_edges[temp.x][temp.y].m_prevDirec = LEFT_D;
					break;
				case 3:
					m_edges[temp.x][temp.y].m_prevDirec = RIGHT_D;
					break;
				default:
					break;
				}

			}
		}

		draw(DELAYTIME);
	}
	if (!m_edges[m_end_pos.x][m_end_pos.y].m_pass)
		AlgoCommand::displayNoValidPathMessageBox();

	return true;
}

void BFSAlg::initialGraphNodeBFS()
{
	//init GraphNode
	copyBoolMatrix();
	auto mSwap = [&]
	{
		std::vector<std::vector<GraphNodeBFS>> tempEdges(m_bool_matrix.size());
		for (size_t i = 0; i < tempEdges.size(); i++)
			tempEdges[i].resize(m_bool_matrix[0].size());
		std::swap(m_edges, tempEdges);
	};
	mSwap();
}

void BFSAlg::showMinPath()
{
	if (!m_edges[m_end_pos.x][m_end_pos.y].m_pass) // if there isn't path
		return;								// return empty list

	sf::Vector2i currNode = m_end_pos; // move back for destion to start to 
	while (currNode != m_start_pos) // move until start
	{
		m_path.push_front(m_edges[currNode.x][currNode.y].m_prevDirec); // put direction on the list head
		currNode = sf::Vector2i(m_edges[currNode.x][currNode.y].m_previous); // move to the next node
		if (currNode != m_start_pos)
			m_board.setCellColor({ currNode.x,currNode.y }, sf::Color::Green);
		draw(DELAYTIME);
	}

	auto clearData = [&]
	{
		m_path.clear();
		clearQueue(m_nodeQueue);
		for (int i = 0; i < m_edges.size(); i++)
			m_edges[i].clear();

	};
	clearData();

}
