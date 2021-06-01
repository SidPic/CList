#include <stdio.h>
#include <stdlib.h>

#define SHORT_LIST_NAMES
#include "list.h"

void main()
{
    List list;
    inita(&list, L"YGUMS", LIST_STR_END);
    insert(&list, list.tail->next, 'o');
    insert(&list, list.head, 'h');
    insert(&list, list.tail, 'l');
    int arr[] = L" OK It's WORK! ";
    inserta(&list, list.head->next, arr, LIST_STR_END);

    for (gobegin(&list); gonext(&list);) putchar (getthis(&list)->value);
    puts("\n");
    for (goend(&list); goprev(&list);) putchar (getthis(&list)->value);

    puts("");
}
