#pragma once
#include<array>
#include "SFML/Graphics.hpp"
#include <Windows.h>

enum ButtonType
{
	PATH_POS_T, OBSTACLE_T, DELETE_T,REF_T,BACK_T,INPUT_T,NONE_T

};

namespace GridProperties {
	constexpr float START_GRID_ROW = 150.0f;
	constexpr float START_GRID_COL = 20.0f;
	constexpr int SIZE_TILE = 25;
}


const sf::Vector2i INITIAL_POS_PATH = sf::Vector2i{ -1,-1 };


enum  GlobalBoundsRect
{
	RECT_MENU_T, RECT_PATH_T, RECT_BLOCK_T, RECT_DEL_T, RECT_REF_T
};
enum  PICTURES_TYPE
{
	ROUTE_P,BRICK_P, DEL_P, REFRESH_P,BACK_P,INPUT_P,CIRECLE_ALGO_P
};


enum DIRECTION { LEFT_D, RIGHT_D, UP_D, DOWN_D, NONE_D };

namespace ButtonsAlgoPositions {
	const sf::Vector2f BFS_BTN_POS = { 35.0,310 };
	const sf::Vector2f DFS_BTN_POS = { 35.0, 370 };
	const sf::Vector2f ASTAR_BTN_POS = { 35.0, 430 };
}

constexpr int DELAYTIME = 500;


 static const std::array<sf::Vector2i, 4> moves
= { sf::Vector2i(-1, 0), // up
	sf::Vector2i(1, 0), // down
	sf::Vector2i(0, -1), // right
	sf::Vector2i(0, 1) } // left
 ; 

 
 namespace ButtonsPositions {
	 const sf::Vector2f PATH_POS_BUT = { 50.0f,35.0f };
	 const sf::Vector2f OBS_BUT = { 50.0f,75.0f };
	 const sf::Vector2f DEL_OBS_BUT = { 50.0f,115.0f };
	 const sf::Vector2f OBS_REFRESH = { 50.0f,155.0f };
	 const sf::Vector2f OBS_BACK = { 50.0f,195.0f };
	 const sf::Vector2f OBS_INPUT = { 50.0f,235.0f };
 }


 const char ENTER = '\r';
 const char BACK_SPACE = '\b';
 const sf::Color LIGHT_BLUE = { 8,138,160 };




