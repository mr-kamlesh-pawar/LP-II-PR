#include <iostream>
#include <vector>
using namespace std;

void addEdge(int graph[6][6], int edge1, int edge2){
    graph[edge1][edge2] = 1;
    graph[edge2][edge1] = 1;
}

bool safeToAssign(int i, int j, int graph[6][6], int v, vector<int>& color){
    for(int k=0; k<v; k++){
        if(graph[i][k]==1 && color[k]==j){
            return false;
        }
    }
    return true;
}

bool solveColoring(int graph[6][6], int m, int v, int i, vector<int>& color){
    if(i == v){
        return true;
    }
    for(int j=0; j<m; j++){
        if(safeToAssign(i, j, graph, v, color)){
            color[i] = j;
            if(solveColoring(graph, m, v, i+1, color)) return true;
            color[i] = -1; // backtrack
        }
    }
    return false;
}

bool graphColoring(int graph[6][6], int m, int v){
    vector<int> color(v, -1);
    if(solveColoring(graph, m, v, 0, color)){
        cout << "Color Assignments: ";
        for(int i=0; i<v; i++)
            cout << "V" << i << "=" << color[i] << " ";
        cout << endl;
        return true;
    }
    else{
        cout << "No coloring possible with " << m << " colors.\n";
        return false;
    }
}

int main(){
    int m = 3;  // No. of colors
    int v = 6;  // No. of vertices
    int graph[6][6] = {0};

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 5);

    graphColoring(graph, m, v);
    return 0;
}