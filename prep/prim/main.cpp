#include <iostream>
#include <cmath>
# define MAX 1000000

using namespace std;

//prim
int main()
{
    int v, e, start;
    cin >> v >> e >> start;
    start -= 1;

    int **mst = new int* [v - 1];
    for (int i = 0; i < v - 1; i++) {
        mst[i] = new int [3];
        for (int j = 0; j < 3; j++) {
            mst[i][j] = 0;
        }
    }

    int **edge = new int* [e];
    for (int i = 0; i < e; i++) {
        edge[i] = new int [4];
        for (int j = 0; j < 3; j++) {
            cin >> edge[i][j];
        }
        edge[i][3] = 1;
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
            if (edge[j][3] == 1) {
                if (vertice[edge[j][1] - 1] == 0 && vertice[edge[j][0] - 1] == 1){
                    if (edge[j][2] < minEdge) {
                        addEdge = j;
                        minEdge = edge[j][2];
                    }
                }
                else if (vertice[edge[j][1] - 1] == 1 && vertice[edge[j][0] - 1] == 0){
                    if (edge[j][2] < minEdge) {
                        addEdge = j;
                        minEdge = edge[j][2];
                    }
                }
            }
        }
        edge[addEdge][3] = 0;
        vertice[edge[addEdge][0] - 1] = 0;
        vertice[edge[addEdge][1] - 1] = 0;
        //for (int k = 0; k < 3; k++) cout << edge[addEdge][k] << " ";
        mst[i] = new int [3];
        for (int k = 0; k < 3; k++) {
            mst[i][k] = edge[addEdge][k];
        }
        //cout << endl;
    }

    for (int i = 0; i < v - 1; i++) {
        for (int j = 0; j < 3; j ++) {
            cout << mst[i][j] << " ";
        }
        cout << endl;
    }
}
