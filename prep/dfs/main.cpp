#include <iostream>
#include <cmath>
# define MAX 1000000

using namespace std;

//dfs
int main()
{
    int v, e, start;
    cin >> v >> e >> start;
    start -= 1;

    int **mst = new int* [v - 1];
    for (int i = 0; i < v - 1; i++) {
        mst[i] = new int [2];
        for (int j = 0; j < 2; j++) {
            mst[i][j] = 0;
        }
    }

    int **edge = new int* [e];
    for (int i = 0; i < e; i++) {
        edge[i] = new int [2];
        for (int j = 0; j < 2; j++) {
            cin >> edge[i][j];
        }
        edge[i][3] = 1;
    }

    int *checkEdge = new int [e];
    for (int i = 0 ; i < e; i++) {
        checkEdge[i] = 1;
    }

    int *vertice = new int [v];
    for(int i = 0; i < v; i ++) {
        vertice[i] = 1;
    }
    vertice[start] = 0;

    for (int i = 0; i < v - 1; i++) {
        int minEdge = MAX;
        int addEdge = 0;
        for (int j = 0; j < e; j++) {
            if (checkEdge[j] == 1) {
                if (vertice[edge[j][1] - 1] == 0 && vertice[edge[j][0] - 1] == 1){
                    addEdge = j;
                    break;
                }
                else if (vertice[edge[j][1] - 1] == 1 && vertice[edge[j][0] - 1] == 0){
                    addEdge = j;
                    break;
                }
            }
        }
        checkEdge[addEdge] = 0;
        vertice[edge[addEdge][0] - 1] = 0;
        vertice[edge[addEdge][1] - 1] = 0;
        for (int k = 0; k < 2; k++) cout << edge[addEdge][k] << " ";
        cout << endl;
    }
}
