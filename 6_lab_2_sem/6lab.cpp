
#include <iostream>

/*Написать программу по созданию, добавлению (в начало, в конец), просмотру (с начала, с конца)
и удалить чётные элементы для двунаправленных линейных списков.*/


struct queque {
    int data;
    queque* next,* prev;
}* end,* begin;


queque* creating(queque* begin,queque* end,int data) {
    queque* new_node = new queque;
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

queque* add_to_the_begin(queque* begin, int data) {
    queque* new_node = new queque;
    new_node->data = data;   //+data
    new_node->prev = NULL;   
    new_node->next = begin;    // Link two neighbour elements
    begin->prev = new_node;    
    begin = new_node;      //new head 
    std::cout << "Add element " << data << " to the BEGIN;\n";
    return begin;
}

queque* add_to_the_end(queque* end, int data) {
    queque* new_node = new queque;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = end;
    end->next = new_node;
    end = new_node;
    std::cout << "Add element " << data << " to the END;\n";
    return end;
}

void view_from_begin(queque* begin) {

    if (begin == NULL) {
        std::cout << "Empty queque\n;";
        return;
    }
        queque* tmp = begin;

        std::cout << "Head->";

        while (tmp != NULL) { std::cout << "|" << tmp->data << "|"; tmp = tmp->next; }

        std::cout << "<-End;\n";

}


void view_from_end(queque* end) {

    if (end == NULL) {
        std::cout << "Empty queque\n;";
        return;
    }

        queque* tmp = end;

        std::cout << "End->";
        while (tmp != NULL) { std::cout << "|" << tmp->data << "|"; tmp = tmp->prev; }
        std::cout << "<-Head;\n";

}

void ind_zad(queque** begin, queque** end) {
    queque* tmp = *begin;
    while (tmp != NULL) {
        while ((*begin)->data % 2 == 0) {
            if (tmp->next == NULL) { *end = *begin = NULL; return; };  //выход если остался один чётный
            *begin = (*begin)->next;
            (*begin)->prev = NULL;
            tmp = *begin;
        }
        while ((*end)->data % 2 == 0) {
            *end = (*end)->prev;
            (*end)->next = NULL;
            if (*end == *begin) { return; };
        }
        while (tmp->data % 2 == 0) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tmp = tmp->next;
        }
        tmp = tmp->next;
    }
}

int main()
{
    int num;
    int data;
    data = rand() - RAND_MAX / 2;
    begin = end = creating(begin, end, data);
    std::cout << "Queque is created\n___________\n";
    while (std::cout << "1 - add element,2 - view,3 - Ind_zad,4 - create(if we delete all queque),0 - Exit," << std::endl && std::cin >> num) {
        if (num == 1) {
            int tmp_choose;
            std::cout << "1 - begin,2 - end\n";
            std::cin >> tmp_choose;
            if (tmp_choose == 1) { int data;             data = rand() - RAND_MAX / 2;    begin = add_to_the_begin(begin, data); }
            if (tmp_choose == 2) { int data;             data = rand() - RAND_MAX / 2;     end = add_to_the_end(end, data); }
        }
        else if (num == 2) {
            int tmp_choose;
            std::cout << "1 - begin,2 - end\n";
            std::cin >> tmp_choose;
            if (tmp_choose == 1) {
                    std::cout << "\n____QUEQUE____\n";
                    view_from_begin(begin);
                    std::cout << std::endl;

            }
            if (tmp_choose == 2) { 
                    std::cout << "\n____QUEQUE____\n";
                    view_from_end(end);
                    std::cout << std::endl;
            }
        }
        else if (num == 3) {
            ind_zad(&begin,&end);
            std::cout << "\n____QUEQUE____\n";
            view_from_begin(begin);
            std::cout << std::endl;
        
        }
        else if (num == 4) {
            int data;
            data = rand() - RAND_MAX / 2;
            begin = end = creating(begin, end, data);
            std::cout << "Ok\n___________\n";
        }
        else if (num == 0) {
            std::cout << "Good bye" << std::endl;
            exit(1);
        }
        else { std::cout << "\nError,try again;\n"; }
    }
}
