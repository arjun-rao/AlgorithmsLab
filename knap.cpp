#include<iostream>
using namespace std;

class Sack
{
	int  *weight;
	int  *value;
	int **table;
	int number;
	int capacity;

	public:

	Sack( int n, int cap )
	{
		number = n;
		capacity = cap;
		weight = new  int [n];
		value = new int [n];
		
		table = new int* [n + 1];
		for ( int i = 0; i <= n; i++ )
			table[i] = new int [cap];

		for ( int j = 0 ; j <= cap; j++ )
			table[0][j] = 0;

		for ( int i = 0 ; i <= n; i++ )
			table[i][0] = 0;
	}

	void setData()
	{
		cout << "Enter the weight and value of each item\n";
		
		for ( int i = 0; i < number; i++ )
		{
			cin >> weight[i];
			cin >> value[i];
		}
	}

	void getData()
	{
		cout <<"Item No.\tWeight\tValue\n";
		for ( int i = 0; i < number; i++ )
		{
			cout << i+1 <<"\t" << weight[i] <<"\t" << value[i] << endl;
		}
	}

	void calculate()
	{
		for ( int i = 1; i <= number; i++ )
		{
			for ( int j = 1; j <= capacity; j++ )
			{
				//cout<<endl<<j<<" -Weight["<<i<<" ]= "<<j-weight[i-1]; 
				if ( j - weight[i-1] >= 0 ){
					int index = j-weight[i-1];
					table[i][j] = max ( table[i-1][j], value[i-1] + table[i-1][index ] );
				}
				else
					table[i][j] = table[i-1][j];
				
			}
		}
		cout<<"\nTable:\n";
		cout<<"  ";
		for(int i=0;i<=capacity;i++)cout<<i<<" ";
		cout<<endl;
		for(int i=0;i<=number;i++)
		{
			cout<<i<<" ";
			for(int j=0;j<=capacity;j++)cout<<table[i][j]<<" ";
			cout<<endl;
		}

		cout << "\nThe maximum value for a knapsack of capacity ";
		cout << capacity <<"is" << table[number][capacity] << endl;
		
		int i=number,j=capacity;

		cout<<"\nThe items in the knapsack are:\n";
		while(i!=0 && j!=0)
		{
			if(table[i][j]!= table[i-1][j])
			{
				cout<<"Item "<<i<<" Value: "<<value[i-1]<<endl;
				j=j-weight[i-1];
				i--;
			}
			else
				i--;
		}

	}

	int max( int a, int b )
	{
		return a > b ? a : b;
	}
};

int main()
{
	int number, capacity;
	cout <<"Enter the number of items\n";
	cin >> number;
	cout <<"Enter the maximum capacity of the knapsack\n";
	cin >> capacity;
	Sack s ( number, capacity );

	s.setData();
	s.getData();
	s.calculate();
}
	
	
