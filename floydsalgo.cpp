#include<iostream>
#include <cstdlib>
#define INT_MAX 999999

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
		Graph(const Graph &g){
			vertex=g.vertex;
			a=new int*[vertex];
			for(int i=0;i<vertex;i++){
				a[i]=new int[vertex];
				for(int j=0;j<vertex;j++)a[i][j] = g.a[i][j];
			}
			
		}
		void equals(Graph &c)
		{
			if(c.vertex == this->vertex)
			{
				for(int i=0;i<vertex;i++){
					for(int j=0;j<vertex;j++){
						this->a[i][j] = c.a[i][j];
					}
				}
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
					if(a[i][j] == 0 && i!=j)
						a[i][j] = INT_MAX;
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
	        friend void floyds(Graph g,Graph &c);
};

int minim(int a,int b)
{
	return a<b?a:b;
}


void floyds(Graph g, Graph &c)
{
	Graph prev(g),next(g.vertex);
	for(int k=0;k<g.vertex;k++)
	{
	       for(int i=0;i<g.vertex;i++)
		{
			for(int j=0;j<g.vertex;j++)
				prev.a[i][j] = minim(prev.a[i][j],prev.a[i][k] + prev.a[k][j]);
		
		}
		//prev.equals(next);
	}
	prev.display();

}

int main()
{

	int n;
	cout<<"Vertices:";
	cin>>n;
	Graph G(n);
	cout<<"Adjacency Matrix:\n";
	G.input();
	cout<<"D0:\n";
	G.display();
	cout<<"Shortest path:\n";
	Graph C(n);
	floyds(G,C);
	//C.display();
	cout<<endl;
 
}
