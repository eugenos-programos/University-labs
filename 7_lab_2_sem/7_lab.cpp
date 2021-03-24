#include <iostream>
using namespace std;

/*Разработать проект для работы с деревом поиска, содержащий следующие обработчики, которые должны:
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


Tree* create_root(int data, string name) {
    Tree* new_node = new Tree;
    new_node->data = data;
    new_node->name = name;
    new_node->left = new_node->right = NULL;
    return new_node;
}


void view_tree(Tree* root,int level) {
    string str;
    if (root) {
        view_tree(root->right, level + 1);		// Правое поддерево
        for (int i = 0; i < level; i++) str = str + "    ";
        cout << str << root->data;
        view_tree(root->left, level + 1); 			// Левое поддерево
    }
}


void create_list(Tree* root,int key, string name) {
    if (root == NULL) { cout << "Empty tree\n"; return; };
    Tree* prev, * t;
    bool find = true;
    t = root;
    prev = t;
    while ((t != NULL) && find) {
        prev = t;
        if (t->data == key) {
            find = false;
            cout << "Key has been used! Please try again!\n";
        }
        else {
            if (key < t->data)t = t->left;
            else t = t->right;   //перемещаемся по дереву по свойствам дерева поиска
        }
    }
    if (prev == NULL)return;
    if (find) {
        t = create_root(key, name);
        if (key > prev->data)prev->right = t;
        else prev->left = t;
    }
}



void balance_tree() {

}

void find_info(int key, Tree* root) {
    
}



int main()
{
    cout << "Creating a tree,input data and string:\n ";
    int data;
    string name;
    cin >> data;
    cin >> name;
    root = create_root(data, name);
    while (1) {
        cout << "\n1 - Add node,2 - view,0 - eXIT\n";
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            cout << "Input data and string\n";
            cin >> data;
            cin >> name;
            create_list(root, data, name);
        }
        if (tmp == 2) {
            cout << "Tree:\n";
            view_tree(root, 0);
        }
        if (tmp == 0) {
            break;
        }
    }


}
