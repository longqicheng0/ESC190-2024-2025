#include "LL.h"


int main()
{
    LL *list;
    create_list(&list);
    insert_list(list, 1);
    insert_list(list, 2);
    insert_list(list, 3);
    insert_list(list, 4);
    insert_list(list, 5);
    print_list(list);
    delete_list_ind(list, 0);
    print_list(list);
    return 0;
}