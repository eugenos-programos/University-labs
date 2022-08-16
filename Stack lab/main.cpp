#include <cstdlib>
#include <iostream>

using namespace std;

/* Написать программу по созданию, добавлению, просмотру и решению поставленной задачи
(в рассмотренных примерах это действие отсутствует) для однонаправленного линейного списка типа СТЕК.
Реализовать сортировку стека двумя рассмотренными выше методами.Во всех заданиях создать список из 
положительных и отрицательных случайных целых чисел.2. Удалить из созданного списка элементы с четными
числами.*/

struct stack {
	int data;
	stack* next;
}*start;

stack* push_element(int number, stack* pointer) {
	stack* t = new stack;
	t->data = number;
	t->next = pointer;
	return t;
}

void view_stack(stack* pointer) {
	if (pointer == NULL) {
		cout << "Empty stack" << endl;
		return;
	}
	stack* t = pointer;
	cout << "Stack_____________" << endl;
	while (t != NULL) {
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;
}

stack* ind_zad(stack* pointer) {  //вершина
	stack* tmp = pointer;
	while (tmp != NULL) {
		if ((tmp->next == NULL) && (tmp->data % 2 != 0)) return pointer;
		do {
			if ((tmp == pointer) && (tmp->data % 2 == 0)) {
				cout << "!";
				if (tmp->next == NULL) {
					stack* delete_node = tmp;
					free(tmp);
					pointer = NULL;
					return pointer;
				}
				stack* delete_node = tmp->next;
				tmp->data = tmp->next->data;     // заменяем данные вершины на данные из след.элемента
				tmp->next = tmp->next->next;
				free(delete_node);
			}
			} while (tmp->data % 2 == 0);
		do{
			if ((tmp->next != NULL) && (tmp->next->data % 2 == 0)) {
				cout << "!!";
				stack* delete_node = tmp->next;
				tmp->next = tmp->next->next;
				free(delete_node);
			}
		} while ((tmp->next != NULL) && (tmp->next->data % 2 == 0));
		if (tmp->next != NULL) tmp = tmp->next;
	}
	return pointer;
}

void Sort_p(stack** p) {
	stack* t = NULL, * t1, * r;
	if ((*p)->next->next == NULL) return;
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next)
			if (t1->next->data > t1->next->next->data) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while ((*p)->next->next != t);
}

void Sort_info(stack* p) {
	stack* t = NULL, * t1;
	do {
		t1 = p;
		while (t1->next != NULL) {
			if (t1->data > t1->next->data) {
				swap(t1->data, t1->next->data);
			}
			t1 = t1->next;
		}
		t = t1;
	} while (p->next != t);
}

int main()
{
	setlocale(LC_ALL, "");
	int tmp;
	cout << "1-Создать стек/Добавить элементы,2-Просмотреть стек,3-инд.задание,4-сортировка через указатели,5-сортировка через данные,0 - EXIT" << endl;
	while (cin >> tmp) {
		if (tmp == 1) {
			int element;
			cout << "input number\n";
			cin >> element;
			start = push_element(element, start);
			cout << "____" << endl;
		}
		if (tmp == 2) {
			view_stack(start);
		}
		if (tmp == 3) {
			start = ind_zad(start);
			view_stack(start);
		}
		if (tmp == 4) {
			Sort_p(&start);
			view_stack(start);
		}
		if (tmp == 5) {
			ind_zad(start);
			view_stack(start);
		}
		if (tmp == 0)exit(1);
	}
}
