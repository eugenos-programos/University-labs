#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Разработать проект для работы с деревом поиска, содержащий следующие обработчики, которые должны:
– DONE ввести информацию, состоящую из целочисленного ключа и строки текста;
– DONE записать информацию в дерево поиска;
– DONE сбалансировать дерево поиска;
– DONE добавить в дерево поиска новую запись;
– DONE по заданному ключу найти информацию и отобразить ее;
– DONE удалить из дерева поиска информацию с заданным ключом;
– DONE распечатать информацию прямым, обратным обходом и в порядке возрастания ключа;
– DONE решить одну из следующих задач.
Подсчитать число листьев в дереве. (Лист – это узел, из которого нет ссылок на другие узлы дерева).*/

class Tree {
public:
    int data;
    string name;
    Tree* right,* left;
}*root;

struct para{
    int data;
    string name;
};

Tree* create_root(int data, string name) {
    Tree* new_node = new Tree;
    new_node->data = data;
    new_node->name = name;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void make_balance(Tree **p, int n, int k, vector<int> a,vector <para> array_1){
    if (n == k) { *p = NULL;
                	return;
   }
            int m=(n+k)/2;
            *p = new Tree;
            (*p)->data = a[m];
            for(int i = 0;i < array_1.size(); i++){
                if(array_1[i].data == a[m]){
                    (*p)->name = array_1[i].name;
                    break;
                }
            }
            cout << "!!!" <<(*p)->left << endl;
                     cout << "&&&" <<&(*p)->left << endl;

            make_balance( &(*p)->left, n, m, a,array_1);
            make_balance( &(*p)->right, m+1, k, a,array_1);
}

void print_Tree_1(Tree* p,int level)
{
    if(p)
    {
        for(int i = 0;i< level;i++) cout<<"   ";
        cout << p->data << " " << p->name << endl;
        print_Tree_1(p->right,level + 1);
        print_Tree_1(p->left,level + 1);
    }
}

void simm_obhod(Tree * p,int level)
{
    if(p)
    {
        simm_obhod(p->right,level + 1);
        for(int i = 0;i< level;i++) cout<<"   ";
        cout << p->data << " " << p->name << endl;
        simm_obhod(p->left,level + 1);
    }
}

Tree* Del_Info(Tree *root, int key)  {
	Tree *Del, *Prev_Del, *R, *Prev_R;
// Del, Prev_Del – удаляемый узел и его предыдущий (предок);
// R, Prev_R – элемент, на который заменяется удаляемый, и его предок;
	Del = root;
	Prev_Del = NULL;
while (Del != NULL && Del -> data != key) {
		Prev_Del = Del;
		if (Del->data > key)  Del = Del->left;
			else Del = Del->right;
		}
	if (Del == NULL)	{				// Элемент не найден
   	cout <<  "NOT Key!\n";
			return root;
	}
//-------------------------- Поиск элемента R для замены -----------------------------------
	if (Del -> right == NULL) R = Del->left;
	else
		if (Del -> left == NULL) R = Del->right;
		else {
//------------------- Ищем самый правый узел в левом поддереве -----------------------
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}
//---------------- Формируем связи элемента R и его предка Prev_R -------------------
			if( Prev_R == Del)  R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Del->left;    // R->left = Prev_R
			}
    }
	if (Del== root) root = R;			// Удаляя корень, заменяем его на R
	else
	if (Del->data < Prev_Del->data)
			Prev_Del->left = R;				// На левую ветвь
		else	Prev_Del->right = R;
						// На правую ветвь
	delete Del;
	return root;
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
            else t = t->right;
        }
    }
    if (prev == NULL)return;
    if (find) {
        t = create_root(key, name);
        if (key > prev->data)prev->right = t;
        else prev->left = t;
    }
}


void number_of_list(Tree* pointer_on_root,int* number){
    if((pointer_on_root != NULL) && (pointer_on_root->left == NULL) && (pointer_on_root->right == NULL)) {
        (*number)++;
    }
    if(pointer_on_root)
    {

        number_of_list(pointer_on_root->right,number);
        number_of_list(pointer_on_root->left,number);


    }
}
void print_info_2(Tree* root){
    if(root){
        print_info_2(root->right);
        print_info_2(root->left);
        cout << root->data << " " << root->name << endl;
    }
}

void find_info(int key, Tree* p) {
   if(p)
    {
        find_info(key,p->right);
        if(p->data == key){
            cout << "-" << p->data << " " << p->name << "-" << endl;
            return;
        }
        find_info(key,p->left);
    }

}

void print_info_3(Tree* root){
if(root)
    {
        print_info_3(root->left);
        cout << root->data << " " << root->name << " " << endl;
        print_info_3(root->right);
    }
}

void simm(Tree* root){
if(root)
    {
        print_info_3(root->left);
        cout << root->data << " " << root->name << " " << endl;
        print_info_3(root->right);
    }
}

int main()
{
    vector<para> array_1;
    vector<int> array_of_keys;
    vector<string> s;
    cout << "Creating a tree,input data and string:\n";
    int data;
    string name;
    cin >> data;
    array_of_keys.push_back(data);
    s.push_back(name);
    fflush(stdin);
    cin >> name;
    para tmp;
    tmp.data = data;
    tmp.name = name;
    array_1.push_back(tmp);
    root = create_root(data, name);
    while (1) {
        cout << "\n 1 - Add node,2 - pryamoj obhod,3 - balance tree,4 - delete key,\
        5 - number of list,6 - find info,7 - rasp v poryadke vozr,8 - obrathyj obhod,9 - simm_obhod 0 - eXIT\n";
        int kod;
        cin >> kod;
        if (kod == 1) {
            int data;
            string name;
            cout << "Input data and string\n";
            cin >> data;
            array_of_keys.push_back(data);
            sort(array_of_keys.begin(),array_of_keys.end());
            cin >> name;
            tmp.data = data;
            tmp.name = name;
            array_1.push_back(tmp);
            create_list(root, data, name);
        }

        if (kod == 2) {
            cout << "Tree:\n";
            print_Tree_1(root, 0);
        }
        if(kod == 3){

            make_balance(&root,0,array_of_keys.size(),array_of_keys,array_1);
        }

        if(kod == 4){
            int key;
            cout << "Input key\n";
            cin >> key;
            Del_Info(root,key);
        }

        if(kod == 5){
            int number = 0;
            number_of_list(root,&number);
            cout << number << endl;
        }

        if(kod == 6){
            int key;
            cout << "Input key\n";
            cin >> key;
            find_info(key,root);
        }

        if(kod == 7){
            print_info_3(root);
        }

        if(kod == 8) print_info_2(root);

        if(kod == 9) simm_obhod(root,0);

        if (kod == 0) {
            break;
        }
    }
}

