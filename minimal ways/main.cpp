#include <fstream>
#include <iostream>
#include <string>
#include <vector>


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
	int vertex,edge;
	if (!file_for_reading.is_open()) cout << "Open error\n";
	else {
			file_for_reading >> vertex >> edge;
	}
	vector <vector <int> > matrix;
	vector <int> tmp_vector;
	string line;
	while (!file_for_reading.eof()) {
		int number;
		file_for_reading >> number;
		tmp_vector.push_back(number);
		if (tmp_vector.size() == 3) {
			matrix.push_back(tmp_vector);
			tmp_vector.clear();
		}
	}
	
	for (int i = 0; i < matrix.size(); i++) {
		tmp_vector = matrix[i];
		for (int j = 0; j < tmp_vector.size(); j++)cout << tmp_vector[j] << " ";
		cout << endl;
	}



}
