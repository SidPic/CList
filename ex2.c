#include <stdio.h>
#include <stdlib.h>

#define SHORT_LIST_NAMES
#include "list.h"

void main()
{
    List list;
    init(&list, 'a');
    // insert(&list, list.tail->next, 'o');
    // insert(&list, list.head, 'h');
    // insert(&list, list.tail, 'l');
    inserta(&list, list.head->next, L"i! H");

    for (gobegin(&list); gonext(&list);) putchar (getthis(&list)->value);
    puts("\n");
    for (goend(&list); goprev(&list);) putchar (getthis(&list)->value);

    puts("");
}
