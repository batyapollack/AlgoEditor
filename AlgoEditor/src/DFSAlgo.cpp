#include "DFSAlgo.h"

DFSAlgo::DFSAlgo(Board& b, sf::RenderWindow& window)
	:AlgoCommand(b,window)
{
	m_button_algo.setPosition(DFS_BTN_POS);
	m_float_rect = m_button_algo.getGlobalBounds();

	m_text.setString("DFS");
	m_text.setCharacterSize(35);
	m_text.setPosition(DFS_BTN_POS.x + 51.0f, DFS_BTN_POS.y + 55.0f);
	m_text.setScale(0.37, 0.37);

}

void DFSAlgo::execute()
{

	auto clear = [&]
	{
		m_finish = false;
		for (size_t i = 0; i < m_adjacents.size(); i++)
			m_adjacents[i].clear();
		for (size_t i = 0; i < m_visited.size(); i++)
			m_visited[i].clear();
	};
	clear();

	if (initialGraph())
	{
		auto mSwap = [&]
		{
			std::vector<std::vector<bool>> visited;
			std::vector < std::vector  <std::vector < sf::Vector2i >>> adjacents;

			adjacents.resize(m_bool_matrix.size());
			for (size_t i = 0; i < adjacents.size(); i++)
				adjacents[i].resize(m_bool_matrix[0].size());

			visited.resize(m_bool_matrix.size());
			for (size_t i = 0; i < visited.size(); i++)
				visited[i].resize(m_bool_matrix[0].size());

			std::swap(m_visited, visited);
			std::swap(m_adjacents, adjacents);
		};
		mSwap();
	
		buildAdjacents();
		searchPath(m_start_pos);
		if(!m_visited[m_end_pos.x][m_end_pos.y])
			AlgoCommand::displayNoValidPathMessageBox();
	}

}

void DFSAlgo::searchPath(sf::Vector2i pos)
{
	m_visited[pos.x][pos.y] = true;
	sf::Vector2i ngbCell;
	// Recur for all the vertices adjacent 
	// to this vertex 

	for (int i = 0; i < m_adjacents[pos.x][pos.y].size(); i++)
	{
		ngbCell = m_adjacents[pos.x][pos.y][i];
		if (!(m_visited[ngbCell.x][ngbCell.y]))
		{
			if (ngbCell == m_end_pos || m_finish)
			{
				m_finish = true;
				m_visited[m_end_pos.x][m_end_pos.y] = true;
				return;
				
			}
			if (ngbCell != m_start_pos)
			{
				m_board.setCellColor(ngbCell, sf::Color::Red);
				m_countStep++;
			}

			draw(DELAYTIME);
			searchPath(ngbCell);
		}
	}
	

}

void DFSAlgo::buildAdjacents()
{
	
	
	sf::Vector2i ngbCell;
	sf::Vector2i cell;

	for (int i = 0; i < m_adjacents.size(); i++)
	{
		for (int j = 0; j < m_adjacents[i].size(); j++)
		{
	
			if ((m_bool_matrix[i][j]))
				for (size_t k = 0; k < 4;k++)
				{
					cell = { i,j };
					ngbCell = cell+moves[k] ;// cell to check

					if (ngbCell.x < 0 || ngbCell.y < 0 ||
						ngbCell.x >= static_cast<int>(m_bool_matrix.size()) || ngbCell.y >= static_cast<int>(m_bool_matrix[0].size())
						|| !m_bool_matrix[ngbCell.x][ngbCell.y]
						)
						continue;

					
					m_adjacents[i][j].push_back(ngbCell);
				}
		}
	}
}
