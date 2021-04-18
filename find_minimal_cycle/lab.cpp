#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
int cycle_end,cycle_start;

/*bool dfs(int v,int** adj) {
    color[v] = 1;
    for (int i;i < v;i++) {
        for(int u;u < v;u++){
         if (color[i] == 0) {
            parent[i] = v;
            if (dfs(i,adj))
                return true;
        } else if (color[i] == 1) {
            cycle_end = v;
            cycle_start = i;
            return true;
           }
        }
    }
    color[v] = 2;
    return false;
}*/

/*
    cout << start << " ";
    visited[start] = true;
    for(int i = 0;i<number;i++){
        if(!visited[i] && (adj[start][i] == 1)) dfs_algo(adj,number,i,visited);
    }


bool dfs_algo(int** adj,int number,int start,vector<int>& visited,vector<int>& parent){
    visited[start] = 1; //Mark as we enter in this vertex
    for(int i = 0;i < number;i++){
        if((visited[i]) == 0 && (adj[start][i] == 1)){
            parent[i] = i;
            if(dfs_algo(adj,number,i,visited,parent)) return true;
        } else if (visited[i] == 1){
            cycle_start = start;
            cycle_end = i;
            return true;
        }
    }
    visited[start] = 2;
    return false;
}*/




/*
void find_cycle(int** adj,int number,vector<int>& visited,vector<int>& parent) {
    visited.assign(number, 0);
    parent.assign(number, -1);
    cycle_start = -1;

    for (int v = 0; v < number; v++) {
        if ((visited[v] == 0) && dfs_algo(adj,number,v,visited,parent))
            break;
    }
    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}*/

/*bool dfs(int** adj,int number,int curr, set<int>&wSet, set<int>&gSet, set<int>&bSet,vector<int>& c) {
   //moving curr to white set to grey set.
   wSet.erase(wSet.find(curr));
   gSet.insert(curr);

   for(int v = 0; v < number; v++) {
      if(adj[curr][v] != 0) {    //for all neighbour vertices
          c.push_back(v);
         if(bSet.find(v) != bSet.end()){
                continue;    //if the vertices are in the black set
         }

         if(gSet.find(v) != gSet.end())
            return true;    //it is a cycle
         if(dfs(adj,number,v, wSet, gSet, bSet,c))
            return true;    //cycle found
      }
   }

   //moving v to grey set to black set.
   gSet.erase(gSet.find(curr));
   bSet.insert(curr);
   c.clear();
   return false;
}

void hasCycle(int** adj,int number,vector<int>& c) {
   set<int> wSet, gSet, bSet;    //three set as white, grey and black
   for(int i = 0; i<number; i++)
      wSet.insert(i);    //initially add all node into the white set

   while(wSet.size() > 0) {
      for(int current = 0; current < number; current++) {
            if(dfs(adj,number,current, wSet, gSet, bSet,c)){
                for(int i = 0;i<c.size();i++) cout << c[i] << " ";
                cout << endl;
            }
      }
   }
}

void dfs_algo(int** adj,int number,int start,vector<bool>& visited){
    cout << start << " ";
    visited[start] = true;
    for(int i = 0;i<number;i++){
        if(!visited[i] && (adj[start][i] == 1)) dfs_algo(adj,number,i,visited);
    }
}

void DFS(int** adj,int node,vector<int> visited,int number){
    if(visited[node]){
        if(node == start){

        }
    }
    visited[node] = 1;
    for(int i = 0;i < number;i++){
        if(adj[node][i] == 1)
    }

}*/



/*if (v == par[u]) {
            continue;
        }*/

void dfs_cycle(int u, int p, int color[], int mark[], int par[], int& cyclenumber,int** graph,int number)
{
    //u - первая вершина

    // already (completely) visited vertex.
    if (color[u] == 2) {
        return;
    }

    // seen vertex, but was not completely visited -> cycle detected.
    // backtrack based on parents to find the complete cycle.
    if (color[u] == 1) {

        cyclenumber++;
        int cur = p;
        mark[cur] = cyclenumber;

        // backtrack the vertex which are
        // in the current cycle thats found
        while (cur != u) {
            cur = par[cur];
            mark[cur] = cyclenumber;
        }
        return;
    }
    par[u] = p;

    // partially visited.
    color[u] = 1;

    // simple dfs on graph
    for(int v = 0;v<number;v++){
        if(graph[u][v] == 1)dfs_cycle(v, u, color, mark, par, cyclenumber,graph,number);
    }

    color[u] = 2;
}

// Function to print the cycles
void printCycles(int edges, int mark[], int& cyclenumber,vector<int> cycles)
{

    // push the edges that into the
    // cycle adjacency list
    for (int i = 1; i <= edges; i++) {
        if (mark[i] != 0)
            cycles[mark[i]].push_back(i);
    }

    // print all the vertex with same cycle
    for (int i = 1; i <= cyclenumber; i++) {
        // Print the i-th cycle
        cout << "Cycle Number " << i << ": ";
        for (int x : cycles[i])
            cout << x << " ";
        cout << endl;
    }
}

int main(int argc,char* argv[])
{

    fstream file_for_reading("C:\\Tests\\1test.in");
    int number_of_vertexes;
    file_for_reading>>number_of_vertexes;
    int ** matrix = new int*[number_of_vertexes];
    for(int i = 0;i < number_of_vertexes;i++){
        matrix[i] = new int[number_of_vertexes];
    }
    for(int i = 0;i < number_of_vertexes;i++){
        for(int j = 0;j < number_of_vertexes;j++){
        int buffer;
        file_for_reading >> buffer;
        matrix[i][j] = buffer;

        cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int color[N];
    int par[N];

    // mark with unique numbers
    int mark[N];

    // store the numbers of cycle
    int cyclenumber = 0;
    int edges = 13;
    vector<int> cycles;

    dfs_cycle(1, 0, color, mark, par, cyclenumber,matrix,number_of_vertexes);
    printCycles(number_of_vertexes, mark, cyclenumber,cycles);

    system("pause");


    return 0;
}
