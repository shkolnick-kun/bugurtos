#ifndef _PITEM_H_
#define _PITEM_H_

/*!
\file
\brief Заголовок элементов списка с приоритетами.
*/
//Элемент списка с приоритетами

typedef struct _pitem_t pitem_t;
//Свойства
/*!
\brief
//Элемент списка с приоритетами
*/
struct _pitem_t
{
    item_t parent; /*!< родитель - item_t */
    xlist_t * list; /*!< указательна спиок в который будем вставлять */
    prio_t prio; /*!< приоритет */
};

/*!
   Статическая инициализация объекта типа pitem_t
   \param a - имя переменной
   \param p - приоритет
*/
#define INIT_P_ITEM_T(a,p) { INIT_ITEM_T(a), (xlist_t *)0, (prio_t)p }

//Методы
/*!
\brief
Инициализация объект а типа pitem_t.

\param pitem указатель на объект pitem_t
\param prio приоритет элемента
*/
void pitem_init( pitem_t * pitem, prio_t prio );
/*!
\brief
Вставка элемента типа pitem_t в список типа xlist_t.

\param pitem указатель на объект pitem_t
\param xlist указатель на список
*/
void pitem_insert( pitem_t * pitem, xlist_t * xlist );
/*!
\brief
Быстро вырезать из списка.

Вырезает объект типа gitem_t, из спика типа xlist_t, не обнуляет указатель pitem->list

\param pitem указатель на объект pitem_t
*/
void pitem_fast_cut( pitem_t * pitem );
/*!
\brief
Вырезать из списка.

Вызывает pitem_fast_cut и обнуляет указатель pitem->list

\param pitem указатель на объект pitem_t
*/
void pitem_cut( pitem_t * pitem );

#endif // _PITEM_H_
