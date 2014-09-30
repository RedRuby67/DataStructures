8 24
xxxxxxxxxxxxxxxxxxxxxxxx
--------------------xxxx
-xxxxxxxxxx---xxxxxxxxxx
-xxxx--xx-----xx-x-----x
-xxxx--xxxxxx---x--xxx--
---xxx----xxxxx---xxxx--
-xxxxxxxxxxxxxxxx-xxxxxx
*xxxxxxxxxxxx$----xxxxxxE


3 3
*--
x--
xx$

maze::maze()
{
 ifstream myIns;
 myIns.open("maze.txt");
 assert (myIns.is_open());

 myIns >> yDim >> xDim;

 
 mazeArray = new char[yDim*xDim];
 
 for (int j = 0; j < yDim; j++)
 {
 for (int p = 0; p < xDim; p++)
 {
 myIns >> mazeArray[j * xDim + p];
 }

 }
}

if (i - xDim >= 0 && mazeArray[upIndex] == '$') 
	{
		mazeArray[i] = '*';
		//cout << "This is what my program just did. Goal up " << mazeArray[upIndex] << endl;
		return true;
		
	} 
	
	if (xDim + i < xDim * yDim  - 1 && mazeArray[downIndex] == '$') // used to be else if from here
	{
		mazeArray[i] = '*';
		//cout << "This is what my program just did. Goal down " << mazeArray[downIndex] << endl;
		return true;
	} if (i % xDim >= 0 && mazeArray[leftIndex] == '$')
	{
		mazeArray[i] = '*';
		//cout << "This is what my program just did. Goal left " << mazeArray[leftIndex] << endl;
		return true;
	} if (i % xDim != xDim - 1 && mazeArray[rightIndex] == '$') 
	{
		mazeArray[i] = '*';
		//cout << "This is what my program just did. Goal right " << mazeArray[rightIndex] << endl;
		return true;
		
		// started looking for '-' 
		
	} if ((xDim + i < xDim * yDim  - 1 && mazeArray[downIndex] == '-')) 
	{
		if (solve(downIndex) == true) {
			mazeArray[i] = '*';
			//cout << "This is what my program just did. Space down " << mazeArray[downIndex] << endl;
			return true;
		} else if (mazeArray[downIndex] == 'v') {
			mazeArray[i] = '*';
			return true;
		}
	} if ((i - xDim >= 0 && mazeArray[upIndex] == '-')) 
	{
		if(solve(upIndex) == true) {
			mazeArray[i] = '*';
			//cout << "This is what my program just did. Space up " << mazeArray[upIndex] << endl;
			return true;
		} else if (mazeArray[upIndex] == 'v') {
			mazeArray[i] = '*';
			return true;
		}
		
	} if ((i % xDim != xDim - 1 && mazeArray[rightIndex] == '-')) 
	{
		if (solve(rightIndex) == true) {
			mazeArray[i] = '*';
			//cout << "This is what my program just did. Space right " << mazeArray[rightIndex] << endl;
			return true;
		} else if (mazeArray[rightIndex] == 'v') {
			mazeArray[i] = '*';
			return true;
		}
	} if ((i % xDim >= 0 && mazeArray[leftIndex] == '-'))
	{
		if (solve(leftIndex) == true) {
			mazeArray[i] = '*';
			//cout << "This is what my program just did. Space left " << mazeArray[leftIndex] << endl;
			return true;
		} else if (mazeArray[leftIndex] == 'v') {
			mazeArray[i] = '*';
			return true;
		} 
	}



