// maze.h
#ifndef MAZE_H_
#define MAZE_H_

#include <iostream>

class maze 
{
	public:
		maze();
		~maze();
		void start();
		void init();
		bool solve(int index);
		//bool solved();
		
		// for cout
		friend std::ostream& operator <<(std::ostream& outs, const maze& source);
		
	private:
		char* mazeArray;  // represent maze as 1-dim dynamically allocated array that pointer points to
		int startingIndex; // int that represents starting point of maze
		int xDim;  // x-dimension of maze
		int yDim;  // y-dimension of maze
		//bool solved; 
		int upIndex;
		int downIndex;
		int leftIndex;
		int rightIndex;
};

// Nonmembers

#endif
