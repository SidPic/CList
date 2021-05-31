/**
    Библиотека для создания двунаправленных списков и взаимодействия с ними.
    ! ЭС - (новый) Элемент Списка
    ! н - новый
    ! п - предыдущий
    ! с - следующий
    ! начальный выбранный элемент - это голова списка
    ! любые функции библиотеки используются только после инициализации списка
    ! функции редактирования и копирования при успехе возвращают 0 - иначе -1
    ! функции перемещения и получения при успехе возвращают указатель на ЭС - иначе NULL (thisnum возвращает 0)
**/

/**       ДЕКЛАРАЦИИ       **/

/** Основных частей списка **/
typedef  int    data_t;   // тип значения элемента данных списка
typedef struct Data Data; // тип элемента данных списка
typedef struct List List; // тип списка

/**        Функций         **/
/**     инициализации     **/
void     List_init    (List *list, data_t value);                       // инициализация значением (обязательна)
void     List_inita   (List *list, data_t* arr );                       // инициализация массивом (обязательна)
/**     редактирования    **/
char     List_delete  (List *list, Data *pos);                          // удаление элемента с позиции pos
char     List_deletea (List *list, Data *begin, Data  *end );           // удаление элемнтов с begin по end подряд
char     List_insert  (List *list, Data *pos,  data_t value);           // вставка значения на место (перед) pos
char     List_inserta (List *list, Data *pos,  data_t* arr );           // вставка массива на место (перед) pos
char     List_swap    (List *list, Data *e1,    Data   *e2 );           // поменять ЭС e1 и e2 местами
/**      копирования      **/
char     List_copy    (List *from,  List  *to, Data *begin, Data *end); // копирование ЭС from в спсиок to с begin по end
char     List_copya   (List *from, data_t *to, Data *begin, Data *end); // копирование ЭC с begin по end в массив to
/**      перемещения      **/
Data*    List_gonext  (List *list);                                     // выбирает следующий ЭС
Data*    List_goprev  (List *list);                                     // выбирает предыдущий ЭС
Data*    List_gohead  (List *list);                                     // выбирает голову списка
Data*    List_gotail  (List *list);                                     // выбирает хвост списка
Data*    List_goend   (List *list);                                     // выбирает самый конец списка list->tail->next
Data*    List_gotonum (List *list, unsigned number);                    // выбирает элемент, находящийся на number позиции
/**       получения       **/
Data*    List_this    (List *list);                                     // возврвщвет выбранный элемент
unsigned List_thisnum (List *list);                                     // возвращает позицию выбранного элемента
Data*    List_getfrom (List *list, unsigned number);                    // возвращает элемент, находящийся на number позиции

/** Укорочение имён функций **/
#ifdef SHORT_LIST_NAMES
    #define init     List_init
    #define inita    List_inita
    #define insert   List_insert
    #define inserta  List_inserta
    #define delete   List_delete
    #define deletea  List_delete
    #define swap     List_swap
    #define copy     List_copy
    #define copya    List_copya
    #define gonext   List_gonext
    #define goprev   List_goprev
    #define gohead   List_gohead
    #define gotail   List_gotail
    #define goend    List_goend
    #define gotonum  List_gotonum
    #define this     List_this
    #define thisnum  List_thisnum
    #define getfrom  List_getfrom
#endif

/**         ОПРЕДЕЛЕНИЯ         **/

/**          Структуры          **/
struct List     /**        Список        **/
{
    Data *head;   // начало, "голова"
    Data *data;   // элементы данных
    Data *tail;   // конец, "хвост"
};

struct Data     /** Элемент данных списка **/
{
    Data *prev;   // предыдущий ЭС
    Data *next;   // следующий ЭС
    data_t value; // значение ЭС
};

/**           Функции           **/
//---------инициализация-----------
/**   инициализация значением   **/
void List_init (List *list, data_t value)
{
    list->data        = (Data*)malloc(sizeof(Data));  // инициализация первого ЭС
    list->data->prev  = NULL;                         // ЭС как головной,
    list->data->next  = NULL;                         //  так и хвостовой
    list->data->value = value;

    list->head = list->data;
    list->tail = list->data;
}

/**   инициализация  массивом   **/
void List_inita (List* list, data_t *arr)
{

}

//---------редактирование----------
/**      вставка  значения      **/
char List_insert (List *list, Data *pos, data_t value)
{
    if (pos == list->head)                                   /** вставка ЭС перед его головой **/
    {
        pos->prev        = (Data*)malloc(sizeof(Data));       // подготовка места для нового ЭС  |    п - н<- с
        pos->prev->prev  = NULL;                              // ЭС становится головным          | NULL - н<- с
        pos->prev->next  = pos;                               // соединение ЭС со старой головой | NULL - н<->с
        list->head       = pos->prev;                         // "голова" перемещается в ЭС
        pos->prev->value = value;                             // присваивание значения ЭС
    }
    else if (pos == list->tail->next)                        /** вставка ЭС после его хвоста **/
    {
        pos        = (Data*)malloc(sizeof(Data));             // подготовка места для нового ЭС  | п ->н - с
        pos->next  = NULL;                                    // ЭС становится хвостовым         | п ->н - NULL
        pos->prev  = list->tail;                              // соединение ЭС со старым хвостом | п<->н - NULL
        list->tail = pos;                                     // "хвост" перемещется в ЭС
        pos->value = value;                                   // присваивание значения ЭС
    }
    else if (pos)                                            /** вставка ЭС между двумя другими **/
    {
        pos->prev->next        = (Data*)malloc(sizeof(Data)); // подготовка места для нового ЭС | п ->н - с
        pos->prev->next->prev  = pos->prev;                   // соединение ЭС с предыдущим     | п<->н - с
        pos->prev->next->next  = pos;                         // соединение ЭС со следующим     | п<->н ->с
        pos->prev              = pos->prev->next;             // соединение следующего с ЭС     | п<->н<->с
        pos->prev->value       = value;                       // присваивание значения ЭС
    }
    else return -1;

    return 0;
}

/**      вставка  массива      **/
char List_inserta (List *list, Data *pos, data_t* arr)
{
    return 0;
}

/**     удаление элемента      **/
char List_delete (List *list, Data *pos)
{
    return 0;
}

/** удаление фрагмента списка  **/
char List_deletea (List *list, Data *begin, Data *end)
{
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
    return list->data;
}

/** перемещение к ПРЕДЫДУЩЕМУ ЭС **/
Data* List_goprev (List *list)
{
    return list->data;
}

/** перемещение к ГОЛОВЕ списка **/
Data* List_gohead (List *list)
{
    return list->data;
}

/** перемещение к ХВОСТУ списка **/
Data* List_gotail (List *list)
{
    return list->data;
}

/** перемещение ЗА ХВОСТ списка **/
Data* List_goend (List *list)
{
    return list->data;
}

/**   перемещение к number ЭС   **/
Data* List_gotonum (List *list, unsigned number)
{
    return list->data;
}

//-----------получение------------
/**   получение выбранного ЭС   **/
Data* List_this (List *list)
{
    return list->data;
}

/** получение номера выбранного ЭС **/
unsigned List_thisnum (List *list)
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
