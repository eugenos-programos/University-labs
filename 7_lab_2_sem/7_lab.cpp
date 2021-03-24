#include <iostream>
using namespace std;

/*   Rазработать проект для работы с деревом поиска, содержащий следующие обработчики, которые должны:
– ввести информацию, состоящую из целочисленного ключа и строки текста;
– записать информацию в дерево поиска;
– сбалансировать дерево поиска;
– добавить в дерево поиска новую запись;
– по заданному ключу найти информацию и отобразить ее;
– удалить из дерева поиска информацию с заданным ключом;
– распечатать информацию прямым, обратным обходом и в порядке возрастания ключа;
– решить одну из следующих задач.
Подсчитать число листьев в дереве. (Лист – это узел, из которого нет ссылок на другие узлы дерева).*/

class Tree {
public:
    int data;
    string name;
    Tree* right,* left;
}*root;


void balance_tree() {

}


Tree* add_node(int data, string name, Tree* root)
{
    Tree* t = root;


}

void find_info(int key, Tree* root) {
    
}



Tree* create_tree(int data, string name) {
    Tree* new_node = new Tree;
    new_node->data = data;
    new_node->name = name;
    new_node->left = new_node->right = NULL;
    return new_node;
}



int main()
{
    cout << "1-"
}
