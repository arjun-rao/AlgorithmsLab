#include <iostream>
#include <cstdlib>

using namespace std;

int qLoc[20]; //store location ie. the column number of the n queens

void printBoard(int n);
void placeQueen(int Qi,int n);
bool checkPosition(int Qi,int column);


int main()
{
	int n;
	cin>>n;
	placeQueen(0,n);
	return 0;

}

void printBoard(int n)
{
	static int solution;
	cout<<"\n\nSolution: "<< ++solution <<"\n\t";
	
	//print labels for column numbers
	for(int i=0;i<n;i++)
		printf("%d\t",i+1); 

	for(int Qi = 0; Qi < n ; Qi++ ) //print position of each queen row wise
	{
		cout<<"\n"<<Qi+1; //label for row

		for(int column = 0; column <n; column ++)
		{
			if(qLoc[Qi]==column)
				cout<<"\tQ";
			else
				cout<<"\t";
		}
		cout<<"\n\n";//next row new line

	}
}


bool checkPosition(int Qi,int column)
{
	//check positions of previous queens against the given column.

	for(int prev = 0 ; prev < Qi ; prev++)
	{
		//check if a previous queen is in this column
		if(qLoc[prev] == column)
			return false;

		//check if this position conflicts with previous queens diagonally
		/*
			for example if 2nd queen (Qi = 1) is placed in the 2nd column, ie column = 1 
			|0-1| = |0 -1| = 1 (for cell 0,0)
			|0-1| = |2-1| = 1 (for cell 0,2)
			|2-1| = |0-1| = 1 (for cell 2,0)
			|2-1| = |2-1| = 1 (for cell 2,2)
			if (col of prev - current queen col == row of prev queen - row of current queen) its a conflict
			the Qi denotes the row number as its generated row wise.

		*/


		if(abs(qLoc[prev]-column) == abs(prev - Qi))
			return false;


	}
	return true;
}

void placeQueen(int Qi, int n)
{
	if(Qi == n) //we have found a solution
	{
		printBoard(n);
	}
	else //figure out the locatin for Qi
	{
		for(int column = 0; column < n; column++)
		{
			if(checkPosition(Qi,column))
			{
				// we can place Qi in this column
				qLoc[Qi] = column;
				
				//using this find the position for the next queen
				placeQueen(Qi+1,n);

				//backtrack to get the next solution by resetting the position of Qi
				qLoc[Qi] = -1;
			}
		}
	}
}


