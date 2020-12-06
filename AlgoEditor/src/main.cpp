/******************************************************************************************
 *	Authors:Eran Safadel & Batya Pollack									      		  *
 *	Project name: Algo																	  *
 *	Copyright 11/2020 							                                          *
 *                                                                  					  *
 *																						  *
 *	We developed Algo Editor using C++,CMake, Graphic Library -SFML 2.5.1                 *  
 *	The program emphasis on:                                                              *
 *	OOP principles- (Abstraction, Encapsulation, Inheritance and Polymorphism).           *
 *	Design patterns- to provide general solutions and to write better code more quickly.  *
 *  STL(Containers,Iterators,Smart pointers  and lambda functions)                        * 
 *  Algorithms: BFS,DFS and A* .                                                          *
 *  Project link:                                                                         * 
 *                                                                                        * 
 *	If you have any comments or suggestions for improvement,                              *
 *	 we'll be more than happy to hear.                                                    *
 *  P.S :                                                                                 *
 *  Algo Editor is distributed in the hope that it will be useful,		                  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.					         	  *
 *									                                             		  *
 ******************************************************************************************/

#include "Controller.h"
int main()
{
	Controller::getInstance().run();
}