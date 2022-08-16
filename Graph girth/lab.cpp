#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

class Graph {
private:
    vector<int> cycle_sizes;
    int** adjacency_matrix;
public:
    int number_of_vertexes;
    void read_matrix_from_file(string file) {
        fstream file_for_reading(file);
        file_for_reading >> number_of_vertexes;
        adjacency_matrix = new int* [number_of_vertexes];
        for (int i = 0; i < number_of_vertexes; i++) {
            adjacency_matrix[i] = new int[number_of_vertexes];
        }
        for (int i = 0; i < number_of_vertexes; i++) {
            for (int j = 0; j < number_of_vertexes; j++) {
                file_for_reading >> adjacency_matrix[i][j];
            }
        }
    }
    void find_minimal_cycle_using_DFS(int tmp_located_node, int tmp_size, vector<int> color_array, vector<int> distance_array, vector<int>& global_color_array) {
        // First of all all vertexes are white
        global_color_array[tmp_located_node] = 1;
        color_array[tmp_located_node] = 1; // Mark vertex as 'gray'
        for (int i = 0; i < number_of_vertexes; i++) {
            if ((color_array[i] == 0) && (adjacency_matrix[tmp_located_node][i] == 1)) {
                distance_array[i] = tmp_size + 1;
                find_minimal_cycle_using_DFS(i, tmp_size + 1, color_array, distance_array, global_color_array);
            }
            if ((color_array[i] == 1) && (adjacency_matrix[tmp_located_node][i] == 1) && (i != tmp_located_node)) {
                tmp_size = tmp_size + 1 - distance_array[i];
                cycle_sizes.push_back(tmp_size);
            }
        }
        color_array[tmp_located_node] = 2;  // Mark vertex as 'black'
    }
    void additional_function(vector<int> global_color_array, vector<int> color_array, vector<int> distance_array) {
        for (int i = 0; i < number_of_vertexes; i++) {
            if (global_color_array[i] == 0) {
                find_minimal_cycle_using_DFS(i, 0, color_array, distance_array, global_color_array);
                additional_function(global_color_array, color_array, distance_array);
            }
        }
    }
    void print_result() {
        if (cycle_sizes.size() == 0) {
            cout << "No cycles.\n";
            return;
        }
        int res = cycle_sizes[0];
        for (int i = 0; i < cycle_sizes.size(); i++) {
            if (cycle_sizes[i] < res) res = cycle_sizes[i];
        }
        cout << "Result - " << res << endl;
    }
};

int main(int argc, char* argv[])
{
    for (int i = 1; i <= 5; i++) {
        Graph graph_object;
        string s = to_string(i);
        string s_1 = "C:\\Tests\\";
        string s_2 = "test.in";
        s_1 = s_1 + s;
        s_1 = s_1 + s_2;
        graph_object.read_matrix_from_file(s_1);
        vector<int> color_array(graph_object.number_of_vertexes, 0);
        vector<int> distance_array(graph_object.number_of_vertexes, 0);
        vector<int> global_color_array(graph_object.number_of_vertexes, 0);
        graph_object.find_minimal_cycle_using_DFS(0, 0, color_array, distance_array, global_color_array);
        graph_object.additional_function(global_color_array, color_array, distance_array);
        graph_object.print_result();
    }
    system("pause");
    return 0;
}
