#include <stdio.h>
#include <stdlib.h>

#define SHORT_LIST_NAMES
#include "list.h"

void main()
{
    List list;
    init(&list, 'a');
    insert(&list, list.tail->next, 'o');
    insert(&list, list.head, 'h');
    insert(&list, list.tail, 'l');

    while (gonext(&list)) putchar(this(&list)->value);

    puts("");
}
