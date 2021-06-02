#ifndef TWO_DIR_LIST_H
#define TWO_DIR_LIST_H
/**
    Библиотека для создания двунаправленных списков и взаимодействия с ними.
    ! ЭС - (новый) Элемент Списка
    ! н - новый
    ! п - предыдущий
    ! с - следующий
    ! тело списка - все его элементы, за исключением хвоста и головы
    ! ЛЮБЫЕ ФУНКЦИИ БИБЛИОТЕКИ ИСПОЛЬЗУЮТСЯ ТОЛЬКО ПОСЛЕ ИНИЦИАЛИЗАЦИИ СПИСКА !
    ! ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ List_inserttobody и List_deletefrombody не предназначены для пользователя,
        МЕСТО НИХ ИСПОЛЬЗОВАТЬ List_insert И List_delete !
    ! начальный выбранный элемент - это голова списка
    ! функции редактирования и копирования при успехе возвращают 0 - иначе -1
    ! функции перемещения и получения при успехе возвращают указатель на ЭС - иначе NULL (getpos возвращает 0)
    ! *aend свляется самым концом вставляемого массива, т.е не указателем на его последний элемент, а указателем на область после него
    !   т.е. aend = arr[ARR_SIZE] (НЕ ARR_SIZE-1!), если массив представлен в виде строки, место указателя на конец можно
    !       использовать NULL или LIST_STR_END
**/
#define LIST_STR_END NULL
                                                                         /** ******************* ДЕКЛАРАЦИИ ******************* **/
                                                                         /** ------------- ОСНОВНЫЕ ЧАСТИ СПИСКА ------------- **/
typedef  int    data_t;                                                   /* тип значения элемента данных списка               */
typedef struct Data Data;                                                 /* тип элемента данных списка                        */
typedef struct List List;                                                 /* тип списка                                        */
                                                                         /** -------------------- ФУНКЦИИ -------------------- **/
                                                                         /**                   инициализация                   **/
void     List_init    (List *list, data_t value);                         /* инициализация переменной                          */
void     List_inita   (List *list, data_t* arr, data_t *aend );           /* инициализация массивом                            */
                                                                         /**                   редактирование                  **/
char     List_delete  (List *list, Data *pos);                            /* удаление элемента  с позиции pos                  */
char     List_deletea (List *list, Data *begin, Data  *end );             /* удаление элементов с begin по end подряд          */
char     List_insert  (List *list, Data *pos,  data_t value);             /* вставка  элемента  на место (перед) pos           */
char     List_inserta (List *list, Data *pos,  data_t* arr, data_t *aend);/* вставка  массива   на место (перед) pos           */
char     List_swap    (List *list, Data *e1,    Data   *e2 );             /* перемена ЭС e1 и e2 местами                       */
                                                                         /**                    копирование                    **/
char     List_copy    (List *from,  List  *to, Data *begin, Data *end);   /* копирование ЭС from с begin по end в список to    */
char     List_copya   (List *from, data_t *to, Data *begin, Data *end);   /* копирование ЭC from с begin по end в массив to    */
                                                                         /**                    перемещение                    **/
Data*    List_gonext  (List *list);                                       /* выбирает следующий  ЭС                            */
Data*    List_goprev  (List *list);                                       /* выбирает предыдущий ЭС                            */
Data*    List_gohead  (List *list);                                       /* выбирает голову списка                            */
Data*    List_gotail  (List *list);                                       /* выбирает хвост  списка                            */
Data*    List_gobegin (List *list);                                       /* выбирает самое начало списка list->head->prev     */
Data*    List_goend   (List *list);                                       /* выбирает самый конец  списка list->tail->next     */
Data*    List_gotonum (List *list, unsigned number);                      /* выбирает элемент, находящийся на number позиции   */
                                                                         /**                     получение                     **/
Data*    List_getprev (List *list);                                       /* возвращает элемент, предыдущий выбранному         */
Data*    List_getnext (List *list);                                       /* возвращает элемент, следующий после выбранного    */
Data*    List_getthis (List *list);                                       /* возвращает выбранный элемент                      */
unsigned List_getpos  (List *list);                                       /* возвращает позицию  выбранного элемента           */
Data*    List_getfrom (List *list, unsigned number);                      /* возвращает элемент, находящийся на number позиции */
                                                                         /**              вспомогательные функции              **/
void    List_baseinit    (List *list);                                    /* базовая инициализация                             */
void  List_inserttohead  (List *list, /* head */ data_t value);           /* вставляет элемент в голову списка                 */
void  List_inserttotail  (List *list, /* tail */ data_t value);           /* вставляет элемент в хвост списка                  */
void  List_inserttobody  (List *list, Data *pos, data_t value);           /* вставляет элемент (только) в тело списка          */
void List_deletefromhead (List *list /* head */);                         /* удаляет   голову  списка                          */
void List_deletefromtail (List *list /* tail */);                         /* удаляет   хвост   списка                          */
void List_deletefrombody (List *list, Data *pos);                         /* удаляет   элемент (только) из тела списка         */
                                                                         /** ------------ Укорочение имён функций ------------ **/
#ifdef SHORT_LIST_NAMES
    #define init     List_init
    #define inita    List_inita
    #define insert   List_insert
    #define inserta  List_inserta
    #define delete   List_delete
    #define deletea  List_deletea
    #define swap     List_swap
    #define copy     List_copy
    #define copya    List_copya
    #define gonext   List_gonext
    #define goprev   List_goprev
    #define gohead   List_gohead
    #define gotail   List_gotail
    #define gobegin  List_gobegin
    #define goend    List_goend
    #define gotonum  List_gotonum
    #define getprev  List_getprev
    #define getnext  List_getnext
    #define getthis  List_getthis
    #define getpos   List_getpos
    #define getfrom  List_getfrom

    #define    baseinit    List_baseinit
    #define  inserttohead  List_inserttohead
    #define  inserttotail  List_inserttotail
    #define deletefromhead List_deletefromhead
    #define deletefromtail List_deletefromtail
#endif
                                                                         /** ------------------------------------------------- **/
                                                                         /** ****************** ОПРЕДЕЛЕНИЯ ****************** **/
                                                                         /** ------------------- СТРУКТУРЫ ------------------- **/
struct List {                                                            /**                      список                       **/
    Data *head;                                                           /* начало, "голова"                                  */
    Data *data;                                                           /* элементы данных, "тело", выбранный элемент        */
    Data *tail;                                                           /* конец, "хвост"                                    */
};

struct Data {                                                            /**               элемент данных списка               **/
    Data *prev;                                                           /* предыдущий ЭС                                     */
    Data *next;                                                           /* следующий ЭС                                      */
    data_t value;                                                         /* значение ЭС                                       */
};
                                                                         /** -------------------- ФУНКЦИИ -------------------- **/
                                                                         /**                    ИНИЦИЛИЗАЦИЯ                   **/
void List_init (List *list, data_t value)                                /**              инициализация переменной             **/
{
    List_baseinit (list);                                                 /* базовая инициализация                             */
    list->head->value = value;                                            /* присваивание значения ЭС                          */
}

void List_inita (List* list, data_t *arr, data_t *aend)                  /**               инициализация массивом              **/
{
    List_baseinit (list);                                                 /* базовая инициализация                             */
    List_inserta (list, list->tail, arr, aend);                           /* вставка массива                                   */
}

                                                                         /**                   РЕДАКТИРОВАНИЕ                  **/
char List_insert (List *list, Data *pos, data_t value)                   /**                  вставка элемента                 **/
{
    if ( pos == list->head->prev ) return -1;                             /* нельзя использовать точку begin для записи!       */
    if (    pos == list->head    ) List_inserttohead (list, value); else  /* вставка элемента в ГОЛОВУ списка                  */
    if ( pos == list->tail->next ) List_inserttotail (list, value); else  /* вставка элемента в КОНЕЦ списка                   */
    if (           pos           ) List_inserttobody (list, pos, value);  /* вставка элемента в ТЕЛО списка                    */
                  else             return -1;                             /* позиция указана некорректно                       */
                 return 0;
}
char List_inserta (List *list, Data *pos, data_t* arr, data_t *aend)     /**                  вставка массива                  **/
{
    if ( pos == list->head->prev ) return -1;                             /* нельзя использовать точку begin для записи!       */
    if (    pos == list->head    ) {                                      /* вставка                                           */
        List_inserttohead (list, *arr++);                                 /*         головного элемента                        */
    }                                                                     /*                                                   */
    if ( pos == list->tail->next ) { while (aend ? arr != aend : *arr)    /* вставка                                           */
        List_inserttotail (list, *arr++);                                 /*         в конец списка                            */
    }                                                                     /*                                                   */
    if (           pos           ) { while (aend ? arr != aend : *arr)    /* вставка                                           */
        List_inserttobody (list, pos, *arr++);                            /*         в тело списка                             */
    }                                                                     /*                                                   */
    else return -1;                                                       /* позиция указана некорректно                       */
    return 0;
}
char List_delete (List *list, Data *pos)                                 /**                 удаление элемента                 **/
{
    if (pos == list->head->prev || pos == list->tail->next) return -1;    /* нельзя удалять точки begin и end!                 */
    if (pos == list->head) List_deletefromhead (list); else               /* удаление головного ЭС                             */
    if (pos == list->tail) List_deletefromtail (list); else               /* удаление хвостового ЭС                            */
    if (      pos        ) List_deletefrombody (list, pos);               /* удаление элемента из тела списка                  */
             else          return -1;                                     /* позиция указана некорректно                       */
            return 0;
}
char List_deletea (List *list, Data *begin, Data *end)                   /**             удаление фрагмента списка             **/
{
    if ( begin == list->head->prev || begin == list->tail->next)return -1;/* нельзя удалять                                    */
    if (  end  == list->head->prev ||  end  == list->tail->next)return -1;/*                точки begin и end спсика!          */
    if ( list->head == list->tail ) list->head->value = 0;     else       /* если список состоит из одного Э, тот не удаляется */
    if (       begin == end       ) List_delete (list, begin); else       /* и так понятно                                     */
    if (       begin && end       )                                       /*                                                   */
    {                                                                     /*                                                   */
        char head = 0, tail = 0;                                          /*                                                   */
        if (begin == list->head) head = 1;           /* голову и                                          */
        if (end == list->tail) end = end->prev, tail = 1;                 /*          хвост пока не трогаем                    */
                                                                          // /*                                                   */

        begin = begin->next;
        while (begin != end) {                                            /* пока не дошли до конца,                           */
            begin = begin->next;                                          /*                         идём туда,                */
            List_deletefrombody (list, begin->prev);                            /*                                    делитим...     */
        }                                                                 /*                                                   */
       List_delete (list, begin->prev);
       if (tail) List_delete (list, begin);
                                                                          /*                                                   */
        if (head) List_deletefromhead (list);              /* если надо, голова                                 */
        if (tail) List_deletefromtail (list);                /*                   и хвост удаляются               */
    }                                                                     /*                                                   */
    else return -1;                                                       /* позиция указана некорректно                       */
    return 0;
}

/**    перемена ЭС местами     **/
char List_swap (List *list, Data *e1, Data *e2)
{
    return 0;
}

//----------копирование-----------
/** копирование в другой список **/
char List_copy (List *from, List *to, Data *begin, Data *end)
{
    return 0;
}

/**    копирование в массив    **/
char List_copya (List *from, data_t *to, Data *begin, Data *end)
{
    return 0;
}

//----------перемещение-----------
/** перемещение к СЛЕДУЮЩЕМУ ЭС **/
Data* List_gonext (List *list)
{
    if ( list->data == list->head->prev ) list->data = list->head; else   // выбранный элемент находится за головой
    if (        list->data->next        ) list->data = list->data->next;  // выбранный элемент определён
                      else                return NULL;                    // элемент, следующий за выбранным не существует

    return list->data;
}

/** перемещение к ПРЕДЫДУЩЕМУ ЭС **/
Data* List_goprev (List *list)
{
    if ( list->data == list->tail->next ) list->data = list->tail; else   // выбранный элемент находится за хвостом
    if (     list->data->prev->prev     ) list->data = list->data->prev;  // выбранный элемент не является головным
                     else                 return NULL;                    // элемент, предшествующий выбранному не существует

    return list->data;
}

/** перемещение к ГОЛОВЕ списка **/
Data* List_gohead (List *list)
{
    list->data = list->head;
    return list->data;
}

/** перемещение к ХВОСТУ списка **/
Data* List_gotail (List *list)
{
    list->data = list->tail;
    return list->data;
}

/** перемещение ЗА ГОЛОВУ списка **/
Data* List_gobegin (List *list)
{
    list->data = list->head->prev;
    return list->data;
}

/** перемещение ЗА ХВОСТ списка **/
Data* List_goend (List *list)
{
    list->data = list->tail->next;
    return list->data;
}

/**   перемещение к number ЭС   **/
Data* List_gotonum (List *list, unsigned number)
{
    return list->data;
}

//-----------получение------------
/**   получение предыдущего ЭС  **/
Data* List_getprev (List *list)
{
    if ( list->data == list->tail->next ) return list->tail;        // выбранный элемент находится за хвостом
    if (     list->data->prev->prev     ) return list->data->prev;  // выбранный элемент не является головным
                      else                return NULL;              // элемент, предшествующий выбранному не существует
}

/**   получение следующего ЭС   **/
Data* List_getnext (List *list)
{
    if ( list->data == list->head->prev ) return list->head;        // выбранный элемент находится за головой
    if (        list->data->next        ) return list->data->next;  // выбранный элемент определён
                      else                return NULL;              // элемент, следующий за выбранным не существует
}

/**   получение выбранного ЭС   **/
Data* List_getthis (List *list)
{
    return list->data != list->head->prev ? list->data : NULL;
}

/** получение номера выбранного ЭС **/
unsigned List_getpos (List *list)
{
    unsigned num = 0;
    return num;
}

/**  получение элемента number  **/
Data* List_getfrom (List *list, unsigned number)
{
    Data *ptr;
    return ptr;
}
                                                                         /** ------------ ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ------------ **/
void List_baseinit (List *list)                                          /**               базовая инициализация               **/
{
    list->head        = (Data*)malloc(sizeof(Data));                      /* инициализация первого ЭС                          */
    list->tail        = list->head;                                       /* первый ЭС явлется как хвостом, так и головой, т.е.*/
    list->head->prev  = (Data*)malloc(sizeof(Data));                      /* предыдущий элемент отсутствует (но зарезервирован)*/
    list->tail->next  = (Data*)malloc(sizeof(Data));                      /*    и следующий то же                              */
    list->data        = list->head;                                       /* выбранный элемент (по умолчанию) - голова списка  */
}
void List_inserttohead (List *list, data_t value)                        /**          вставка элемента в голову списка         **/
{
    list->head->prev->prev  = (Data*)malloc(sizeof(Data));                /* ЭС становится головным          | begin - н<- с   */
    list->head->prev->next  = list->head;                                 /* соединение ЭС со старой головой | begin - н<->с   */
    list->head->prev->value = value;                                      /* присваивание значения ЭС                          */
    list->head              = list->head->prev;                           /* "голова" перемещается в ЭС                        */
}
void List_inserttotail (List *list, data_t value)                        /**          вставка элемента в конец списка          **/
{
    list->tail->next->next  = (Data*)malloc(sizeof(Data));                /* ЭС становится хвостовым         | п ->н - end     */
    list->tail->next->prev  = list->tail;                                 /* соединение ЭС со старым хвостом | п<->н - end     */
    list->tail->next->value = value;                                      /* присваивание значения ЭС                          */
    list->tail              = list->tail->next;                           /* "хвост" перемещется в ЭС                          */
}
void List_inserttobody (List *list, Data* pos, data_t value)             /**          вставка элемента в тело списка           **/
{
    pos->prev->next        = (Data*)malloc(sizeof(Data));                 /* подготовка места для нового ЭС | п ->н - с        */
    pos->prev->next->prev  = pos->prev;                                   /* соединение ЭС с предыдущим     | п<->н - с        */
    pos->prev->next->next  = pos;                                         /* соединение ЭС со следующим     | п<->н ->с        */
    pos->prev              = pos->prev->next;                             /* соединение следующего с ЭС     | п<->н<->с        */
    pos->prev->value       = value;                                       /* присваивание значения ЭС                          */
}
void List_deletefromhead (List *list)                                    /**                удаление головы списка             **/
{
    if (list->head == list->tail) list->head->value = 0; else             /* если голова - единственный ЭС, то она не удаляется*/
        list->head = list->head->next,                                    /* перемещение головы к следующему ЭС                */
        free (list->head->prev->prev),                                    /* очищение старой точки begin                       */
        list->head->prev->prev = NULL,                                    /*                             и закрытие пути туда  */
        list->head->prev->next = NULL,                                    /* закрытие новой                                    */
        list->head->prev->value = 0;                                      /*                точки begin                        */
}
void List_deletefromtail (List *list)                                    /**                удаление хвоста списка             **/
{
    if (list->tail == list->head) list->tail->value = 0; else             /* если хвост - единственный ЭС, то он не удаляется  */
        list->tail = list->tail->prev,                                    /* перемещение хвоста к предыдущему ЭС               */
        free (list->tail->next->next),                                    /* очищение старой точки end                         */
        list->tail->next->next = NULL,                                    /*                           и закрытие пути туда    */
        list->tail->next->prev = NULL,                                    /* закрытие новой                                    */
        list->tail->next->value = 0;                                      /*                точки end                          */
}
void List_deletefrombody (List *list, Data *pos)                         /**         удаление элемента из тела списка          **/
{
    pos->prev->next = pos->next;                                          /* соединение предыдущего ЭС сo следующим после pos  */
    pos->next->prev = pos->prev;                                          /* соединение следующего ЭС со предшествующим pos    */
    free (pos);                                                           /* очищение pos */
}

#endif
