// maze.cxx
// help from Sheefali Tewari on solve function

#include <cassert>  // provides assert 
#include "maze.h"
#include <cstdlib>
#include <iostream>
#include <fstream>  

using namespace std;

maze::maze(void) {
    ifstream myIns; 
    myIns.open("maze.txt");
    if (myIns.fail()) { 
        cerr << "Error while opening maze.txt" << endl;
        exit (1);
    }
    myIns >> yDim >> xDim; 
    
    cout << " xDim = " << xDim << " and yDim = " << yDim << endl;

        mazeArray = new char [xDim*yDim]; // allocates a char array and points mazeArray pointer to it
            for (int i=0; i < xDim*yDim; i++) {
               
                myIns >> mazeArray[i];            
        }

    myIns.close();
}



maze::~maze()
{
	delete[] mazeArray;
}

void maze::init() {
    //bool solved;

    for (int i=0; i < xDim * yDim; i++) 
    {
        if (mazeArray[i] == '*') 
        {
            startingIndex = i;
            break;
        }

    }
    //solved = solve(startingIndex);
    solve(startingIndex);
}
/*
void maze::start()
{    
	for(int i = 0; i < (xDim * yDim); i++)
    {
        if(mazeArray[i] == '*')
        {
            startingIndex = i;
        }
    }

      //cout << "The starting Index is " << startingIndex << endl;
        //startingIndex = mazeArray['*'];
    }


void maze::init() {
	start();

	solve(startingIndex); // maybe solve(mazeArray[startingIndex]);
}
*/

bool maze::solve(int index) {
	int i = index;
    mazeArray[i] = 'v' ; //mark current spot as visited
	
	// down
    if ((i < ((xDim*yDim) - xDim))) 
    {
        if(mazeArray[i+xDim] == '$')
        {
            mazeArray[i] = '*';
            return true;
        }
    
    }
    if ((i < ((xDim*yDim) - xDim))) 
    {
        if (mazeArray[i + xDim] == '-')
        {
            if (solve(i + xDim))
            {
                mazeArray[i] = '*';
                return true;
            }
        }
    } 

	// up
    if((i >= xDim))
    {
        if (mazeArray[i - xDim] == '$')
        {
            mazeArray[i] = '*';
            return true;
        }   
    }
    if ((i >= xDim)) 
    {
        if (mazeArray[i - xDim] == '-')
        {
            if (solve(i - xDim))
            {
                mazeArray[i] = '*';
                return true;
            }
        }
    }
    	// right
    if (!(i % xDim == (xDim - 1))) 
    {
        if (mazeArray[i + 1] == '$')
        {
            mazeArray[i] = '*';
            return true;
        }
    }
    if (!(i % xDim == (xDim - 1))) 
    {
        if(mazeArray[i + 1] == '-')
        {
            if (solve(i + 1))
            {
                mazeArray[i] = '*';
                return true;
            }
        }
    }
    	// left
    if (!(i % xDim == 0))
    {
        if (mazeArray[i + 1] == '$')
        {
            mazeArray[i] = '*';
            return true;
        } 
    } 
    if (!(i % xDim == 0))
    {
        if (mazeArray[i - 1] == '-')
        {
            if (solve(i - 1))
            {
                mazeArray[i] = '*';
                return true;
            }
        }
    }

    // mazeArray[i] = '-';  
     mazeArray[i] = '*';
    return false;
}
	/*
	//cout << "Solver started." << endl;
	int i = index;
	//cout << "Checking Index: " << index << endl;
	//upIndex = i - xDim;
	//downIndex = i + xDim;
	//leftIndex = i - 1;
	//rightIndex = i + 1;
	
	mazeArray[i] = 'v';
	//cout << "Character marked as visited." << endl;
// down
    if ((i < ((xDim*yDim) - xDim))) 
    //if((i+yDim) <= (xDim*yDim)-xDim) 
    {
        if(mazeArray[i+xDim] == '$')
        {
            mazeArray[i] = '*';
            return true;
        }
    
    }
    if ((i < ((xDim*yDim) - xDim))) 
    {
        if (mazeArray[i + xDim] == '-')
        {
            if(solve(i + xDim))
            {
                mazeArray[i] = '*';
                return true;
            }
        }
    } 

	// up
    if((i >= xDim))
    {
        if (mazeArray[i - xDim] == '$')
        {
            mazeArray[i] = '*';
            return true;
        }   
    }
    if((i >= xDim)) 
    {
        if(mazeArray[i - xDim] == '-')
        {
            if(solve(i - xDim))
            {
                mazeArray[i] = '*';
                return true;
            }
        }
    }
    	// right
    if(!(i % xDim == (xDim - 1))) 
    {
        if (mazeArray[i + 1] == '$')
        {
            mazeArray[i] = '*';
            return true;
        }
    }
    if (!(i % xDim == (xDim - 1))) 
    {
        if(mazeArray[i + 1] == '-')
        {
            if (solve(i + 1))
            {
                mazeArray[i] = '*';
                return true;
            }
        }
    }
    	// left
    if (!(i % xDim == 0))
    {
        if (mazeArray[i + 1] == '$')
        {
            mazeArray[i] = '*';
            return true;
        } 
    } 
    if (!(i % xDim == 0))
    {
        if(mazeArray[i - 1] == '-')
        {
            if(solve(i - 1))
            {
                mazeArray[i] = '*';
                return true;
            }
        }
    }

    mazeArray[i] = '-';
    return false;
}	
	*/


	// mark current spot as visited with v to prevent infinite loop
	// look up for $, if there make self '*' return true
	// look up for -, if there solve(upIndex), if true change self to '*' return true
	// same with right, left, down...
	// return false

ostream& operator <<(ostream& outs, const maze& source) 
{  
	 for (int i=0; i < source.xDim*source.yDim; i++) {
            if((i!=0) && (i % source.xDim == 0)) 
            {
                outs << "\n";
            }
            
            outs << source.mazeArray[i];
        }
    return outs;
}

	/*
	//(outs<<source.<something>
	// want to print out the maze, use double loop
	for (int j = 0; j < source.yDim; j++)
	{
	for (int p = 0; p < source.xDim; p++)
	{
	outs << source.mazeArray[j * source.xDim + p];
	}
	cout << endl;
}
	return outs;
}
*/
