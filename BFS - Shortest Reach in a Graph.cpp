#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    public:
        Graph(int n) {
            this->adjMatrix = vector<vector<bool>>(n, vector<bool>(n, false));
            this->distances = vector<int>(n, 0);
            this->visited = vector<bool>(n, false);
            this->n = n;
        }
        
        void addEdge(int u, int v) {
            this->adjMatrix[u][v] = true;
            this->adjMatrix[v][u] = true;
        }
        
        vector<int> calculateDistances(int s){
            visited[s] = true;
            qu.push(s);
            
            while(!qu.empty()){
                int currentNode = qu.front();
                qu.pop();
                for (int i=0; i < n ; i++) {
                    if(i == currentNode) {
                        continue;
                    }
                    else if ((!visited[i]) && adjMatrix[i][currentNode]) {
                        visited[i] = true;
                        qu.push(i);
                        distances[i] += distances[currentNode] + 6;
                    }
                }
            }
            
            return distances;
        }
        
    private:
        int n;
        queue<int> qu;
        vector<bool> visited;
        vector<int> distances;
        vector<vector<bool>> adjMatrix;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q,n,m,u,v,s;
    cin >> q;
    
    while (q > 0) {
        q--;
        cin >> n >> m;
        
        Graph graph(n);
        
        while (m > 0) {
            m--;
            cin >> u >> v;
            graph.addEdge(u-1, v-1);
        }
        
        cin >> s;
        
        vector<int> distances = graph.calculateDistances(s-1);
        for (int i=0; i < n; i++) {
            if(i == (s-1)) {
                continue;
            }
            else if( distances[i] < 6 ) {
                cout << "-1 ";
            }
            else{
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
      
    return 0;
}
