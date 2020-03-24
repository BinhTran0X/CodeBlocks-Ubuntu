#include <iostream>
#include <cmath>
#define MAX 1000000

using namespace std;

int main() {
	int v, e, start;
	cin >> v >> e >> start;
	int edge[e][3];
	for (int i = 0; i < e; i++) {
	    for (int j = 0; j < 3; j++) cin >> edge[i][j];
	}

	/*for (int i = 0; i < e; i++) {
	    for (int j = 0; j < 3; j++) cout << edge[i][j] << " ";
	    cout << endl;
	}*/

	int shortestPath[e];
	for(int i = 0; i < e; i ++) {
	    shortestPath[i] = MAX;
	}
	shortestPath[start - 1] = 0;

	int checkVertice[v];
	for (int i = 0; i < v; i++) {
	    checkVertice[i] = 1;
	}

	int parent[v];
	for (int i = 0; i < v; i++) parent[i] = -1;


	int begin = start - 1;
	while (checkVertice[begin]) {
	    checkVertice[begin] = 0;
    	for (int i = 0; i < e; i++) {
	        if (edge[i][0] == begin + 1) {
	            if ((shortestPath[begin] + edge[i][2]) < (shortestPath[edge[i][1] - 1])) parent[edge[i][1] - 1] = begin + 1;
	            shortestPath[edge[i][1] - 1] = min(shortestPath[edge[i][1] - 1], shortestPath[begin] + edge[i][2]);
	        }
	        else if (edge[i][1] == begin + 1) {
	            if (shortestPath[begin] + edge[i][2] < shortestPath[edge[i][0] - 1]) parent[edge[i][0] - 1] = begin + 1;
	            shortestPath[edge[i][0] - 1] = min(shortestPath[edge[i][0] - 1], shortestPath[begin] + edge[i][2]);
	        }
	    }
    	int minPath = MAX;
	    for (int i = 0; i < v; i++) {
	        if (checkVertice[i]){
    	        if (shortestPath[i] < minPath) {
	                begin = i;
	                minPath = shortestPath[i];
	            }
	        }
	    }
	}

	for (int i = 0; i < v; i++) {
	    cout <<"Shortest distance from vertice " << start <<" to vertice " << i+1 << " is " << shortestPath[i] << " ";
	    cout << endl;
	}

	//for (int i = 0; i < v; i++) cout << parent[i];
	cout << endl;

	for (int i = 2; i <= v; i++) {
	    int x = i;
	    cout << "The shortest path from " << i << " to " << start << " is " << i << " ";
        while (parent[x - 1] != -1) {
            cout << parent[x - 1] << " ";
            x = parent[x - 1];
        }
        cout << endl;
	}
}

