#include <stdio.h>
#include <math.h>


int board[20],count;

void queen(int row,int n);
void print(int n);
int place(int row,int column);


int main()
{
	int n;
	scanf("%d",&n);
	queen(1,n);
	return 0;
}

void print(int n)
{
	int i,j;
	printf("\n\nSolution: %d\n\t",++count);
	for(i=1;i<=n;i++)
	printf("%d\t",i);
	for( i=1;i<=n;i++)
	{
		printf("\n%d",i);
		for(j=1;j<=n;j++)
		{
			if(board[i]==j)
				printf("\tQ");
			else
				printf("\t");
		}
	}
	printf("\n\n");
}


int place(int row,int column)
{
	int i;
	for(i=1;i<=row;i++)
	{
		if(board[i]==column)
			return 0;
		else if (abs(board[i]-column)==abs(i-row))
			return 0;
	}
	return 1;
}


void queen(int row,int n)
{
	int column;
	for(column =1 ;column<=n;column++)
	{
		if(place(row,column))
		{
			if(place(row,column))
			{
				board[row]=column;
				if(row==n)
					print(n);
				else
					queen(row+1,n);
			}
		}
	}
}



