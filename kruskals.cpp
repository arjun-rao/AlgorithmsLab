#include <iostream>
#include <climits>

using namespace std;

class Graph
{
	int **mat;
	int V;
	int *visited;
	int count;

	public :

	Graph( int ver )
	{
		V = ver;
		count = 0;
	
		visited = new int [V];
		for ( int i = 0; i < V; i++ )
			visited[i] = -1;

		mat = new int* [V];
		for ( int i = 0; i < V; i++ )
			mat[i] = new int [V];
	}

	void setData()
	{
		cout << "Enter the weighted adjacency matrix,\n";
		for (int i = 0; i < V; i++ )
			for ( int j = 0; j < V; j++ )
			{
				cin >> mat[i][j] ;
				if ( mat[i][j] == 0 )
					mat[i][j] = INT_MAX ;
			}
	}

	void kruskal()
	{
		int count = 1, a, b, u, v, min;
		while ( count < V ) //as our tree should contain V nodes
		{ 
			min = INT_MAX;

			//To find the minimum weight edge

			for ( int i = 0; i < V; i ++)
			{
				for ( int j = 0; j < V; j++ )
				{
					if ( mat[i][j] < min )
					{
						min = mat[i][j];
						a = u = i;
						b = v = j;
					}
				}	
			}


			while ( visited[u] != -1 )
				u = visited[u];

			while ( visited[v] != -1 )
				v = visited[v];

			if ( u != v ) //the right condition to check for acyclicity
			{
				visited[v] = u;
				cout << a <<" -> " << b  <<"\t" << mat[a][b] << endl;
				count++;
			}

			//do not reconsider the same edge.
			mat[a][b] = mat[b][a] = INT_MAX;
		}
	}
};

int main ()
{
	int v;
	cout << "Enter the no. of vertices\n";
	cin >> v;
	Graph G ( v );

	G.setData();
	G.kruskal();
}
