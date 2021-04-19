#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Graph{
private:
    vector<int> cycle_sizes;
    int** adjacency_matrix;
public:
    int number_of_vertexes;
    void read_matrix_from_file(char* file){
        fstream file_for_reading(file);
        file_for_reading >> number_of_vertexes;
        adjacency_matrix = new int*[number_of_vertexes];
        for(int i = 0;i < number_of_vertexes;i++){
            adjacency_matrix[i] = new int[number_of_vertexes];
        }
        for(int i = 0;i < number_of_vertexes; i++){
            for(int j = 0;j < number_of_vertexes;j++){
                file_for_reading >> adjacency_matrix[i][j];
            }
        }
    }
    void find_minimal_cycle_using_DFS(int tmp_located_node,int tmp_size,vector<int> color_array,vector<int> distance_array){
        // First of all all vertexes are white
        color_array[tmp_located_node] = 1; // Mark vertex as 'gray'
        for(int i = 0;i < number_of_vertexes;i++){
            if((color_array[i] == 0) && (adjacency_matrix[tmp_located_node][i] == 1)){
                distance_array[i] = tmp_size + 1;
                find_minimal_cycle_using_DFS(i,tmp_size + 1,color_array,distance_array);
            }
            if((color_array[i] == 1) && (adjacency_matrix[tmp_located_node][i] == 1) && (i != tmp_located_node)){
                tmp_size = tmp_size + 1 - distance_array[i];
                cout << tmp_size << endl;
            }
        }
        color_array[tmp_located_node] = 2;  // Mark vertex as 'black'
    }
};

int main(int argc,char* argv[])
{
    Graph graph_object;
    graph_object.read_matrix_from_file(argv[1]);
    vector<int> color_array(graph_object.number_of_vertexes,0);
    vector<int> distance_array(graph_object.number_of_vertexes,0);
    graph_object.find_minimal_cycle_using_DFS(0,0,color_array,distance_array);
    system("pause");



    return 0;
}
