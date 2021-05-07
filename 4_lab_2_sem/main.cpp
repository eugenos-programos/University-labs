#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <io.h>
#include <string.h>
#include <windows.h>

using namespace std;

struct sklad {
    char name[10];
    int number, cost, days;
}info;

void Out(sklad z)
{
    printf("\n %12s || Дней - %3d || Цена - %3d || Количество - %3d.\n", z.name, z.days, z.cost, z.number);
}

int linear_find(char* array, char* array2) {
    for (int i = 0; i < sizeof(array2); ++i) {
         if (array2[i] != array[i]) {
             return 0;
         }
    }
    return 1;
}

void direct_selection(int kol,sklad* a) {
    for (int i = 0; i < kol - 2; i++) {
        int m = i;
        for (int j = i + 1; j < kol - 1; j++) {
            if (a[j].name[0] > a[m].name[0]) m = j;
            swap(a[m], a[i]);
        }
    }
}

void Quick_Sort(sklad * a, int begin, int end)
{
    int left, right, x;
    left = begin;   
    right = end;
    x = a[(left + right) / 2].name[0];
    do {
        while (a[left].name[0] < x)  left++;
        while (x < a[right].name[0]) right--;
        if (left <= right) {
            swap(a[left], a[right]);
            left++;
            right--;                    // Непостредственно перестановка элементов больших и меньших выбранного справа и слево
        }
    } while (left <= right);
    if (begin < right) Quick_Sort(a, begin, right);    // повтор тех же операций,только уже с частью части
    if (left < end) Quick_Sort(a, left, end);
}

int s = sizeof(sklad);
FILE* file_zp;
char File_Zap[] = "C:\\HHH\\For_lab.txt";

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int kod, D_f, i = 0, kol;
    long len;
    sklad * mas_Z;
    while (true) {
        cout << "________________________________";
        puts("\n Create - 1\n Add - 2\n View - 3\n Sort - 4\n EXIT - 0");
        cout << "________________________________\n";
        cin >> kod;
        switch (kod) {
        case 1:
            if ((file_zp = fopen(File_Zap, "wb")) == NULL) {
                puts("\n Create ERROR!");
                exit(0);
            }
            fclose(file_zp);
            break;
        case 2:
            file_zp = fopen(File_Zap, "ab");
            cout << "\n Name -  ";
            fflush(stdin);
            cin >> info.name;
            cout << "\nCost,days,numbers:\n";
            cin >> info.cost >> info.days >> info.number;
            fwrite(&info, s, 1, file_zp);
            fclose(file_zp);
            break;
        case 3:
            if ((file_zp = fopen(File_Zap, "rb")) == NULL) {
                puts("\n Open ERROR!");
                exit(0);
            }
            printf("\n\t--------- Information ---------");
            while (1) {
                if (!fread(&info, s, 1, file_zp)) break;
                Out(info);
            }
            fclose(file_zp);
            break;
        case 4:
        {
            file_zp = fopen(File_Zap, "rb");
            D_f = _fileno(file_zp);
            len = _filelength(D_f);
            kol = len / s;
            mas_Z = new sklad[kol];
            for (i = 0; i < kol; i++)
                fread((mas_Z + i), s, 1, file_zp);
            fclose(file_zp);
            int tmp;
            cout << "\nChoose sort: 1-linear,2-direct selection,3-Quck,4-Binary,5 - ind_zad\n";
            cin >> tmp;
            if (tmp == 1) {
                cout << "Set name:" << endl;
                char* name_one = new char[10];       
                cin >> name_one;
                for (i = 0; i < kol; i++)
                    if (linear_find(mas_Z[i].name, name_one) == 1) Out(mas_Z[i]);
                delete[] name_one;
            }
            if (tmp == 2) {
                direct_selection(kol, mas_Z);
                for (int i = 0; i < kol; i++) {
                    Out(mas_Z[i]);
                }
            }
            if (tmp == 3) {
                Quick_Sort(mas_Z, 0, kol - 1);
                for (int i = 0; i < kol; i++) {
                    Out(mas_Z[i]);
                }
            }
            if (tmp == 4) {
                direct_selection(kol, mas_Z);
                char* key = new char[10];
                cout << "Input key\n";
                cin >> key;
                int left = 0;
                while (left <= kol) // пока левая граница не "перескочит" правую
                {
                    int mid = (left + kol) / 2; // ищем середину отрезка
                    if (linear_find(mas_Z[mid].name, key) == 1) {  // если ключевое поле равно искомому
                        Out(mas_Z[mid]);    // мы нашли требуемый элемент,
                        break;
                    }
                    if (key[0] > mas_Z[mid].name[0])     // если искомое ключевое поле меньше найденной середины
                        kol = mid - 1;  // смещаем правую границу, продолжим поиск в левой части
                    else                  
                        left = mid + 1;   // смещаем левую границу, продолжим поиск в правой части
                }
                delete[]key;
            }
            if (tmp == 5) {
                direct_selection(kol, mas_Z);
                for (i = 0; i < kol; i++)
                    if ((mas_Z[i].days > 30) & (mas_Z[i].cost > 100000) ) Out(mas_Z[i]);
            }
            delete[]mas_Z;
            break;
        }
        case 0:
            exit(1);
        }
    }
}
