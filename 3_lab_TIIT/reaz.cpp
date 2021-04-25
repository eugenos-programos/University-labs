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
	vector <string> all_sets;
	vector <vector<string>> all_sets_in_array_form;
	vector <vector<string>> array_for_storing_all_elements;
	vector<string> result_array;
	void gel_element_from_OPENSET_to_CLOSESET(string& element, int& tmp_j, int i) {
		do {
			element += all_sets[i][tmp_j];
 			tmp_j++;
			if (all_sets[i][tmp_j] == OPENSET_SYMBOL) {
				gel_element_from_OPENSET_to_CLOSESET(element, tmp_j, i);
				tmp_j++;
			}
		} while (all_sets[i][tmp_j] != CLOSESET_SYMBOL && tmp_j != all_sets[i].size() - 1);
		element += CLOSESET_SYMBOL;
	}
	void gel_element_from_OPENSET_1_to_CLOSESET_1_(string& element, int& tmp_j, int i) {
		do {
			element += all_sets[i][tmp_j];
			tmp_j++;
			if (all_sets[i][tmp_j] == OPENSET_SYMBOL_1) {
				gel_element_from_OPENSET_1_to_CLOSESET_1_(element, tmp_j, i);
				tmp_j++;
			}
		} while (all_sets[i][tmp_j] != CLOSESET_SYMBOL_1 && tmp_j != all_sets[i].size() - 1);
		element += CLOSESET_SYMBOL_1;
	}
public:
	void get_element_from_file(string name_of_file) {
		fstream file(name_of_file);
		string set_object;
		int size = 0;
		while (file >> set_object) {
			all_sets.push_back(set_object);
			size++;
		}
		array_for_storing_all_elements.resize(size);
		file >> set_object;
	}
	void get_element_from_set() {
		for (int i = 0; i < all_sets.size(); i++) {
			string local_set = all_sets[i];
			for (int j = 3; j < local_set.size() - 1; j++) {
				string element = "";
				int tmp_j = j;
				if (local_set[tmp_j] == OPENSET_SYMBOL) {
					gel_element_from_OPENSET_to_CLOSESET(element, tmp_j, i);
					j = tmp_j + 1;
					array_for_storing_all_elements[i].push_back(element);
					continue;
				}
				else if (local_set[tmp_j] == OPENSET_SYMBOL_1) {
					gel_element_from_OPENSET_1_to_CLOSESET_1_(element, tmp_j, i);
					j = tmp_j + 1;
					array_for_storing_all_elements[i].push_back(element);
					continue;
				}
				else {
					while (local_set[tmp_j] != TERMNAME_SYMBOL && tmp_j != local_set.size() - 1) {
						element += local_set[tmp_j];
						tmp_j++;
					}
					array_for_storing_all_elements[i].push_back(element);
					j = tmp_j;
				}
			}
			for (int j = 0; j < array_for_storing_all_elements[i].size(); j++) {
				vector<string> v = array_for_storing_all_elements[i];
				string tmp_elem = v[i];
				for (int k = 0; k < array_for_storing_all_elements[i].size(); k++) {
					if (v[i] == v[k] && k != i) { cout << "Syntax error."; exit(1); }
				}
			}
		}
	}
	void print() {
		for (int i = 0; i < array_for_storing_all_elements.size(); i++) {
			vector<string> tmp_vector = array_for_storing_all_elements[i];
			for (int j = 0; j < array_for_storing_all_elements[i].size(); j++) {
				cout << tmp_vector[j] << " ";
			}
			cout << endl;
		}
	}
};

void main() {
	set object;
	object.get_element_from_file("C:\\Tests\\2_3.txt");
	object.get_element_from_set();
	object.print();

}
