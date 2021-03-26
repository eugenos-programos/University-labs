#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstring>

using namespace std;

/*Задан неориентированный взвешенный связный граф. Для каждой его вершины u выведите расстояние от первой вершины до u.

Формат ввода:
	Первая строка входного файла содержит числа n и m - количество вершин и ребер в
графе соответственно (1 <= n <= 30 000, 0 <= m <= 400 000). Следующие m строк содержат по
три числа - вершины, которые соединяет соответствующее ребро графа и его вес. Веса
ребер неотрицательны и не превышают 10^4 .

Формат вывода:
	Выведите в выходной файл n чисел - для каждой вершины выведите расстояние от
первой вершины до нее.

Пример ввода:
4 5
1 2 1
1 3 5
2 4 8
3 4 1
2 3 3

Пример вывода:
0 1 4 5
*/

int main() {
	ifstream file_for_reading("C:\\Tests\\path.in.txt");
	int number_of_vertexes,edge;
	if (!file_for_reading.is_open()) cout << "Open error\n";
	else {
			file_for_reading >> number_of_vertexes >> edge;
	}
	if (number_of_vertexes < 1 || number_of_vertexes >30000 || edge<0 || edge>400000) { cout << "Correct your vallues"; exit(1); };
	int i;
	int** matrix = new int* [number_of_vertexes];
	for (i = 0; i < number_of_vertexes; i++)
		matrix[i] = new int[number_of_vertexes];
	for (i = 0; i < number_of_vertexes; i++) {
		for (int j = 0; j < number_of_vertexes; j++) {
			matrix[i][j] = 0;
		}
	}
	int tmp = 0;
	while (tmp != edge) {
		int first_vertex,second_vertex,edge_size;
		file_for_reading >> first_vertex >> second_vertex >> edge_size;
		matrix[first_vertex-1][second_vertex-1] = matrix[second_vertex-1][first_vertex-1] = edge_size;
		tmp++;
	}
	file_for_reading.close();
	for (i = 0; i < number_of_vertexes; i++) {
		for (int j = 0; j < number_of_vertexes; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	int* result_array = new int[number_of_vertexes];
	int* marked_vertexes = new int[number_of_vertexes];
	for (int i = 0; i < number_of_vertexes; i++) {
		result_array[i] = 400001;                                            
		marked_vertexes[i] = 1;
	}
	int begin_index,minimal_distance,minimal_index,temp_distance;
	result_array[0] = 0;
	do {
		minimal_distance = minimal_index = 400001;
		for ( i = 0; i < number_of_vertexes; i++) {
			if ((marked_vertexes[i] == 1) && (result_array[i] < minimal_distance)) {
				minimal_distance = result_array[i];
				minimal_index = i; 
			}
		}
		if (minimal_index != 400001) {
			for ( i = 0; i < number_of_vertexes; i++) {
				if (matrix[minimal_index][i] > 0) {
					temp_distance = minimal_distance + matrix[minimal_index][i];
					if (temp_distance < result_array[i]) result_array[i] = temp_distance;
				}
			}
			marked_vertexes[minimal_index] = 0;
		}
	} while (minimal_index < 400001);
	delete[] marked_vertexes;
	for (i = 0; i < number_of_vertexes; i++)cout << result_array[i] << " ";
	ofstream file_for_writing("C:\\Tests\\path.out.txt");
	for (i = 0; i < number_of_vertexes; i++)file_for_writing << result_array[i] << " ";
	file_for_writing.close();
}
