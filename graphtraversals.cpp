/**
 * Implementation of the BFS and DFS algorithms
 * Author: Arjun Rao
 * Usage: 
 * Run	./graphtraversals
 *
 **/




#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

class Graph{
	
	private:
	 int vertex;
	 int **a;int *visited;
	public:
		
		Graph(int ver)
		{
			
			vertex=ver;
			a=new int*[ver];
			for(int i=0;i<ver;i++){
				a[i]=new int[ver];
			}
			visited=new int[ver];
			for(int i=0;i<ver;i++){
				visited[i]=0;		
			}
		} 
		
		void get_input(){
			for(int i=0;i<vertex;i++){
				for(int j=0;j<vertex;j++){
					cin>>a[i][j];
				}
			}
		}
		
		void DFS()
		{
			for(int i=0;i<vertex;i++)
			{
				if(!visited[i])
					dfs(i);
				cout<<"\n";
			}
		}

		void BFS()
		{
			for(int i=0;i<vertex;i++)
			{
				if(!visited[i])
					bfs(i);
				cout<<"\n";
			}
		}
		void dfs(int node)
		{
			visited[node]=1;		
			int i;
			cout<<node<<" ";
				for(i=0;i<vertex;i++){
					if(a[node][i] && !visited[i]){				
						dfs(i);
					}
				}
			
		}
		void bfs(int node){
			visited[node]=1;
			queue<int> qu;
			qu.push(node);
			
			while(!qu.empty()){
				int element=qu.front();
				int i;
				qu.pop();
				cout<<element<<" ";
				for(i=0;i<vertex;i++){
					if(a[element][i] && !visited[i]){
						qu.push(i);
						visited[i]=1;
					}
				}
			}
		}
						
};

int main()
{
	int n;
	cout<<"Enter no. of vertices:";
	cin>>n;
	Graph G(n);
	cout<<"Enter the adjacency matrix:\n";
	G.get_input();
	cout<<"DFS Traversals:\n";
	G.DFS();
	cout<<"BFS Traversals:\n";
	G.BFS();
	cout<<endl;
 
}
