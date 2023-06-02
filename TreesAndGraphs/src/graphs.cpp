#include <iostream>
#include <vector>
using namespace std;


unordered_map<int, vector<int>> buildGraph(vector<vector<int>> edges){

    unordered_map<int, vector<int>> graph;

    for(vector<int> edge : edges){
        int x = edge[0], y = edge[1];
        graph[x].push_back(y);
    }

    return graph;

}

//------------------------------------------------------------------

//globals 
unordered_map<int, vector<int>> graph;
vector<bool> seen;

//perform dfs on node and all of its neighbors from hashmap
void dfs(int i){
    for(int neighbor : graph[i]){
        if(!seen[neighbor]){
            seen[neighbor] = true;
            dfs(neighbor);
        }
    }
}

int numProvinces(vector<vector<int>>& isConnected){


    graph.clear();

    //we're given an adjacency matrix, so the first thing to do is iterate through [i][j] and map each node to its neighbor
    int n = isConnected.size();
    seen = vector<bool>(n, false);
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(isConnected[i][j] == 1){
                graph[i].push_back(j); //need to map both i and j because it is an undirected graph
                graph[j].push_back(i);
            }
        }
    }

    //now attempt to do a dfs on every node
    for(int i = 0; i < n; i++){
        if(!seen[i]){ //if we havent seen this node before
            //add it to seen arr
            seen[i] = true;
            ans++;
            //now perform dfs to update seen arr
            dfs(i);
        }
    }

    return ans;

}

//------------------------------------------------------------------


int main(){

    //------------------------------------------------------------------

    /*


        0 ----> 1 ----> 2 ----> 3
        ^               |
        |               |
        |---------------|               
        
        This graph is represented by an array of edges:
        edges = [[0, 1], [1, 2], [2, 3], [2, 0]]
    */
   
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};

    unordered_map<int, vector<int>> graph = buildGraph(edges);

    //this gives me all the neighbors of node 2
    // for(int neighbor : graph[2]){
    //     cout << neighbor << endl;
    // }

    //------------------------------------------------------------------


    /*
    Example 1: 547. Number of Provinces

    There are n cities. A province is a group of directly or indirectly connected cities and 
    no other cities outside of the group. You are given an n x n matrix isConnected where 
    isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and 
    isConnected[i][j] = 0 otherwise. Return the total number of provinces.

    */

    vector<vector<int>> isConnectedTest1 = {{1,1,0},{1,1,0},{0,0,1}};
    vector<vector<int>> isConnectedTest2 = {{1,0,0},{0,1,0},{0,0,1}};
    
    cout << numProvinces(isConnectedTest1) << endl;
    cout << numProvinces(isConnectedTest2) << endl;

    //------------------------------------------------------------------


    return 0;
}