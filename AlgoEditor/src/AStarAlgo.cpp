#include "AStarAlgo.h"

AStarAlgo::AStarAlgo(Board& b, sf::RenderWindow& window)
	:AlgoCommand(b,window)
{
	m_button_algo.setPosition(ASTAR_BTN_POS);
	m_float_rect = m_button_algo.getGlobalBounds();
	m_text.setString("A*");
	m_text.setCharacterSize(35);
	m_text.setPosition(ASTAR_BTN_POS.x + 55.0f, ASTAR_BTN_POS.y + 55.0f);
	m_text.setScale(0.37, 0.37);
	
}

void AStarAlgo::execute()
{


	if (initialGraph())
	{
		aStarSearch();
	}
}

void AStarAlgo::aStarSearch()
{
	if (!(isValid(m_start_pos) && isValid(m_end_pos)))
		return;
	if (isDestination(m_start_pos))
		return;

	auto initData = [&]
	{
		std::vector<std::vector<bool>>  closedList;
		std::vector<std::vector<cell>> cellDetails;

		closedList.resize(m_bool_matrix.size());
		for (int i = 0; i < closedList.size(); i++)
			closedList[i].resize(closedList.size());

		cellDetails.resize(m_bool_matrix.size());
		for (int i = 0; i < cellDetails.size(); i++)
			cellDetails[i].resize(cellDetails.size());
		std::swap(m_closedList, closedList);
		std::swap(m_cellDetails, cellDetails);

	};
	int i, j;
	auto updateCellMatrix = [&]
	{
		for( i =0; i<m_cellDetails.size();i++)
			for (j = 0; j < m_cellDetails[i].size(); j++)
			{
				m_cellDetails[i][j].f = FLT_MAX;
				m_cellDetails[i][j].g = FLT_MAX;
				m_cellDetails[i][j].h = FLT_MAX;
				m_cellDetails[i][j].parent = { -1,-1 };
			}
		
		//init src cell
		i = m_start_pos.x, j = m_start_pos.y;

		m_cellDetails[i][j].f = 0.0;
		m_cellDetails[i][j].g = 0.0;
		m_cellDetails[i][j].h = 0.0;
		m_cellDetails[i][j].parent = { i,j };
	};
	initData();
	updateCellMatrix();
	openList.insert(std::make_pair(0.0, std::make_pair(i,j)));
	
	
		
	
	

	m_foundDest = false; // the destination is not reached.
	
	while (!openList.empty())
	{
		pPair p = *openList.begin();
		openList.erase(openList.begin());
		addVertexClosedList(p);

		for (int i = 0; i < moves.size(); i++)
		{
			findSuccessor({ p.second.first + moves[i].x,p.second.second + moves[i].y }, { p.second.first,p.second.second });
			if (foundDest())
				return;
		}	
	}
	// if not found a route  
	AlgoCommand::displayNoValidPathMessageBox();
}

bool AStarAlgo::foundDest()
{
	if (m_foundDest)
	{
		openList.clear();
		m_closedList.clear();
	}
	return m_foundDest;
}

bool AStarAlgo::isValid(sf::Vector2i loc)const
{
	return (loc.x >= 0) && (loc.x < m_bool_matrix.size()) &&
		(loc.y >= 0) && (loc.y < m_bool_matrix.size());
}

bool AStarAlgo::isUnBlocked(sf::Vector2i loc)const
{

	return m_bool_matrix[loc.x][loc.y];
}

bool AStarAlgo::isDestination(sf::Vector2i loc)const
{
	return loc == m_end_pos;
}

double AStarAlgo::calculateHValue(sf::Vector2i loc) const
{
	return ((double)sqrt((loc.x - m_end_pos.x) * (loc.x - m_end_pos.x)
		+ (loc.y - m_end_pos.y) * (loc.y - m_end_pos.y)));
}

void AStarAlgo::addVertexClosedList(pPair pair)
{
	m_closedList[pair.second.first][pair.second.second] = true;
}

void AStarAlgo::findSuccessor(sf::Vector2i newPos,sf::Vector2i pos)
{
	double gNew, hNew, fNew;
	if (!isValid(newPos))
		return;
	if (isDestination(newPos))
	{
		m_cellDetails[newPos.x][newPos.y].parent = pos;
		tracePath();
		m_foundDest = true;
		return;
	}

	else if (m_closedList[newPos.x][newPos.y] == false &&
		isUnBlocked(newPos) == true)
	{
		gNew = m_cellDetails[pos.x][pos.y].g + 1.0;
		hNew = calculateHValue(newPos);
		fNew = gNew + hNew;

		// If it isn’t on the open list, add it to 
		// the open list. Make the current square 
		// the parent of this square. Record the 
		// f, g, and h costs of the square cell 
		//                OR 
		// If it is on the open list already, check 
		// to see if this path to that square is better, 
		// using 'f' cost as the measure. 
		if (m_cellDetails[newPos.x][newPos.y].f == FLT_MAX ||
			m_cellDetails[newPos.x][newPos.y].f > fNew)
		{
			openList.insert(std::make_pair(fNew,std::make_pair(newPos.x,newPos.y)));
			if (newPos != m_start_pos)
			{
				m_board.setCellColor({ newPos.x, newPos.y }, sf::Color::Red);
				m_countStep++;
			}
			draw(DELAYTIME);
			// Update the details of this cell 
			m_cellDetails[newPos.x][newPos.y].f = fNew;
			m_cellDetails[newPos.x][newPos.y].g = gNew;
			m_cellDetails[newPos.x][newPos.y].h = hNew;
			m_cellDetails[newPos.x][newPos.y].parent =  pos ;

		}
	}

}

void AStarAlgo::tracePath()
{

		sf::Vector2i tempVertex = m_end_pos;
		std::stack<sf::Vector2i> Path;

	while (!(m_cellDetails[tempVertex.x][tempVertex.y].parent == m_start_pos) )
	{
		Path.push(tempVertex);
		tempVertex = m_cellDetails[tempVertex.x][tempVertex.y].parent;
	}

	Path.push(tempVertex);
	while (!Path.empty())
	{
		
		sf::Vector2i pathStep = Path.top();
		if(pathStep!=m_end_pos)
		m_board.setCellColor(pathStep, sf::Color::Green);
		draw(DELAYTIME);
		Path.pop();
	}

	return;


}


