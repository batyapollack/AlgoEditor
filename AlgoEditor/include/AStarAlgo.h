#pragma once
#include "AlgoCommand.h"
#include <utility>
#include <set>
#include <stack>

// A structure to hold the neccesary parameters 
struct cell
{
    // Row and Column index of its parent 
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1 
    sf::Vector2i  parent;
    // f = g + h 
    double f, g, h;
};



class AStarAlgo: public AlgoCommand
{
public:
	AStarAlgo(Board& b,  sf::RenderWindow& window);
	virtual void execute() override;
	
	
    

private:
    typedef std::pair<double,std::pair<int,int> > pPair;
    bool isValid(sf::Vector2i loc)const;
    bool isUnBlocked(sf::Vector2i loc)const;
    bool isDestination(sf::Vector2i loc)const;
    double calculateHValue(sf::Vector2i)const;
    void addVertexClosedList(pPair pair);
    void findSuccessor(sf::Vector2i newPos, sf::Vector2i pos);
    void tracePath();
    void aStarSearch();
    bool foundDest();
    std::vector<std::vector<bool>>  m_closedList;
    std::vector<std::vector<cell>> m_cellDetails;
    std::set<pPair> openList;
    bool m_foundDest = false;

    

};

