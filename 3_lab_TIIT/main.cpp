#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

#define OPENSET_SYMBOL '{'
#define CLOSESET_SYMBOL '}'
#define OPENSET_SYMBOL_1 '<'
#define CLOSESET_SYMBOL_1 '>'
#define TERMNAME_SYMBOL ','
#define DEFNAME_SYMBOL '='


class set {
private:
	vector <string> all_sets;  // Тут храним строки из файла 
	vector <vector<string>> array_for_storing_all_elements; //Тут уже храним массив массивов строк(элементы уже выделены из строки)
	vector<string> result_array;  // Пересечение
	void gel_element_from_OPENSET_to_CLOSESET(string& element, int& tmp_j, int i,vector<string> set) {
		do {
			element += set[i][tmp_j];
 			tmp_j++;
			if (set[i][tmp_j] == OPENSET_SYMBOL) {
				gel_element_from_OPENSET_to_CLOSESET(element, tmp_j, i,set);
				tmp_j++;
			}
		} while (set[i][tmp_j] != CLOSESET_SYMBOL && tmp_j != set[i].size() - 1);
		element += CLOSESET_SYMBOL;
	}
	void gel_element_from_OPENSET_1_to_CLOSESET_1_(string& element, int& tmp_j, int i, vector<string> set) {
		do {
			element += set[i][tmp_j];
			tmp_j++;
			if (set[i][tmp_j] == OPENSET_SYMBOL_1) {
				gel_element_from_OPENSET_1_to_CLOSESET_1_(element, tmp_j, i,set);
				tmp_j++;
			}
		} while (set[i][tmp_j] != CLOSESET_SYMBOL_1 && tmp_j != set[i].size() - 1);
		element += CLOSESET_SYMBOL_1;
	}
	bool is_this_res_element(string key,int number_of_array) {
		int point = 1;
		for (int i = 0; i < array_for_storing_all_elements.size(); i++) {
			if (i != number_of_array) {
				for (int j = 0; j < array_for_storing_all_elements[i].size(); j++) {
					if (array_for_storing_all_elements[i][j] == key) {
						point++;
						break;
					}
				}
			}
		}
		if (point == array_for_storing_all_elements.size()) return true;
		else return false;
	}
	bool fucnt(string key) {
		for (int i = 0; i < result_array.size(); i++) {
			if (key == result_array[i]) return false;
		}
		return true;
	}
	bool check_syntax_error() {
		string error_1[8] = { "{,", ",}" , "]" , "[" , ",," , " ", "<,", ",>"};
		for (int i = 0; i < all_sets.size(); i++) {
			for (int j = 0; j < 8; j++) {
				if (all_sets[i].find(error_1[j]) != string::npos) {
					cout << "Syntax error,OPENSET,TERMNAME\n";
					return false;
				}
			}
			if ((int)all_sets[i][0] < 65 && (int)all_sets[i][0] > 90) {
				cout << "Syntax error,Name of set\n";
				return false;
			}
			if (all_sets[i][1] != DEFNAME_SYMBOL) {
				cout << "Syntax error,DEFNAME\n";
				return false;
			}
			if (all_sets[i][2] != OPENSET_SYMBOL || all_sets[i][all_sets[i].size() - 1] != CLOSESET_SYMBOL) {
				cout << "Syntax error,OPEN-,CLOSESET\n";
				return false;
			}
		}	
		for (int i = 0; i < all_sets.size(); i++) {
			int number_open = 0, number_close = 0;
			for (int j = 0; j < all_sets[i].size(); j++) {
				if (all_sets[i][j] == OPENSET_SYMBOL) number_open++;
				if (all_sets[i][j] == CLOSESET_SYMBOL) number_close++;
			}
			if (number_close != number_open) {
				cout << "Syntax error,number of close,open symbols\n";
				return false;
			}
		}
		return true;
	}
public:
	bool get_element_from_file(string name_of_file) {
		fstream file(name_of_file);
		string set_object;
		int size = 0;
		while (file >> set_object) {
			all_sets.push_back(set_object);
			size++;
		}
		array_for_storing_all_elements.resize(size);
		file >> set_object;
		if (!check_syntax_error()) return false;
		else return true;
	}
	void get_element_from_set() {
		for (int i = 0; i < all_sets.size(); i++) {
			for (int j = 3; j < all_sets[i].size() - 1; j++) {
				string element = "";
				int tmp_j = j;
				if (all_sets[i][tmp_j] == OPENSET_SYMBOL) {
					gel_element_from_OPENSET_to_CLOSESET(element, tmp_j, i,all_sets);
					j = tmp_j + 1;
					array_for_storing_all_elements[i].push_back(element);
					continue;
				}
				else if (all_sets[i][tmp_j] == OPENSET_SYMBOL_1) {
					gel_element_from_OPENSET_1_to_CLOSESET_1_(element, tmp_j, i,all_sets);
					j = tmp_j + 1;
					array_for_storing_all_elements[i].push_back(element);
					continue;
				}
				else {
					while (all_sets[i][tmp_j] != TERMNAME_SYMBOL && tmp_j != all_sets[i].size() - 1) {
						element += all_sets[i][tmp_j];
						tmp_j++;
					}
					array_for_storing_all_elements[i].push_back(element);
					j = tmp_j;
				}
			}
		}
	}
	void print() {
		for (int i = 0; i < array_for_storing_all_elements.size(); i++) {
			for (int j = 0; j < array_for_storing_all_elements[i].size(); j++) {
				if ((array_for_storing_all_elements[i][j][0] == OPENSET_SYMBOL) && (array_for_storing_all_elements[i][j][1] != CLOSESET_SYMBOL)) {
					vector<string> tmp_mn;
					for (int k = 1; k < array_for_storing_all_elements[i][j].size() - 1; k++) {
						string element = "";
						int tmp_j = k;
						if (array_for_storing_all_elements[i][j][k] == OPENSET_SYMBOL) {
							gel_element_from_OPENSET_to_CLOSESET(element, tmp_j, j,array_for_storing_all_elements[i]);
							k = tmp_j + 1;
							tmp_mn.push_back(element);
							continue;
						}
						else if (array_for_storing_all_elements[i][j][k] == OPENSET_SYMBOL_1) {
							gel_element_from_OPENSET_1_to_CLOSESET_1_(element, tmp_j, j,array_for_storing_all_elements[i]);
							k = tmp_j + 1;
							tmp_mn.push_back(element);
							continue;
						}
						else {
							while (array_for_storing_all_elements[i][j][tmp_j] != TERMNAME_SYMBOL && tmp_j != array_for_storing_all_elements[i][j].size() - 1) {
								element += array_for_storing_all_elements[i][j][tmp_j];
								tmp_j++;
							}
							tmp_mn.push_back(element);
							k = tmp_j;
						}
					}
					for (int z = 0; z < tmp_mn.size(); z++) {
						if (!is_this_res_element(tmp_mn[z], i)) {
							break;
						}
						if ((is_this_res_element(tmp_mn[z], i) == 1) && (z == tmp_mn.size() - 1)) {
							result_array.push_back(array_for_storing_all_elements[i][j]);
						}
					}
				}
				if (is_this_res_element(array_for_storing_all_elements[i][j], i) && fucnt(array_for_storing_all_elements[i][j])) {
					result_array.push_back(array_for_storing_all_elements[i][j]);
				}
			}
		}
		cout << "Result: ";
		if (result_array.size() == 0) {
			cout << "Empty set\n";
			return;
		}
		for (int i = 0; i < result_array.size(); i++) {
			cout << result_array[i] << " ";
		}
		cout << endl;
	}
};

void main() {
	for (int i = 1; i <= 7; i++) {
		set object;
		string s = to_string(i);
		if (object.get_element_from_file(".//" + s + "test.txt")) {
			object.get_element_from_set();
			object.print();
		}
	}
}
