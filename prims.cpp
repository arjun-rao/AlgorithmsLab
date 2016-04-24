#include<iostream>
#include <cstdlib>
#include <climits>

using namespace std;



class Graph{

	
	 int vertex;
	 int **a;
	public:
		Graph(int ver){
			vertex=ver;
			a=new int*[ver];
			for(int i=0;i<ver;i++){
				a[i]=new int[ver];
				for(int j=0;j<ver;j++)a[i][j] = 0;
			}
			
		}
	 
		void inEdge(int x,int y)
		{
			a[x][y] = 1;
			a[y][x] = 1;
			
		}
		void input(){
			for(int i=0;i<vertex;i++){
				for(int j=0;j<vertex;j++){
					cin>>a[i][j];
				}
			}
		}
		void display(){
			for(int i=0;i<vertex;i++){
				for(int j=0;j<vertex;j++){
					cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		~Graph()
		{
			
			for(int i=0;i<vertex;i++){
				delete [] a[i];
			}
			delete [] a;
		}
		
		int minWeight(bool visited[],int weight[])
		{
			int min = INT_MAX, min_index;
			for(int i=0;i<vertex;i++)
			{
				if(visited[i]==false && weight[i]<min)
				{
					min= weight[i];
					min_index= i;
				}
			}
			return min_index;
		}

		void prims()
		{
			int V  = vertex;
			//initialise MST[],visited[],weight[]
		   	int *MST= new int[V],*weight = new int[V];
			bool *visited = new bool[V];

			for(int i=0;i<V;i++)
			{
				visited[i] = false;
				weight[i] = INT_MAX;
			}
			
			weight[0] = 0;
			MST[0] = -1; //MST starts with root node
			
			//for V vertices
			for(int c=0;c<V-1;c++)
			{
				int u = minWeight(visited,weight);

				visited[u] = true;

				for(int v=0;v<V;v++)
				{
					if(a[u][v] && visited[v]==false && a[u][v]< weight[v])
					{
						MST[v] = u;
						weight[v]= a[u][v];
					}
				}
			}


			//print solution
			cout<<"\nEdge - Weight\n";
			for(int i=1;i<V;i++)
			{
				cout<<MST[i]<<" - "<<i<<"\t"<<a[i][MST[i]]<<endl;
			}


		}


};



int main()
{

	int n;
	cout<<"Vertices:";
	cin>>n;
	Graph G(n);
	cout<<"Adjacency Matrix:\n";
	G.input();
	G.prims();
	cout<<endl;
 
}
