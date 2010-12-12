/**************************************************************************
    worklist_c.h a work queue C template 4 BuguRTOS-x.x.x.
    Copyright (C) 2010  anonimous

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Please contact with me by E-mail: shkolnick.kun@gmail.com
**************************************************************************/

/*****************************************************************************************
```````````````````````````````..:+oyhdmNNMMMMMMNmmdhyo+:..```````````````````````````````
``````````````````````````.:oydNMMMMMMMMMNNNNNNNNMMMMMMMMMNdy+:.``````````````````````````
```````````````````````:sdNMMMMMNdys+/::----------::/osydNMMMMMNds:```````````````````````
```````````````````.+hNMMMMmho/-..........................-/shmMMMMNh/.```````````````````
````````````````./hNMMMNho:...................................-:ohNMMMNh/`````````````````
``````````````.smMMMNy/-.......:////ss++/+-.......................-+yNMMMmo.``````````````
````````````-sNMMMd+-.....:////:-...-/s::..............+o/-..........-odMMMNs.````````````
``````````.sNMMNh/....................................-o:--............./hMMMNo.``````````
`````````+mMMMh:-........................................-...............-/dMMMm/`````````
```````.yMMMm/...................-::--..................:-........--........+mMMMy.```````
``````:mMMMy-.......................-::-...............-:.........-::........-yMMMd:``````
`````/NMMN+-..................::-.....-:-............../--.........-:/-.......-+NMMN:`````
````+NMMm::o/-..--/+o+o+++++o+osys+//::-::.............:/....-:-::-..-++-.......:NMMN/````
```/NMMm:.-++-+yhs/-``       `dMMMMMmho+:-..............:-/+yho/:/+oyo//o-......./mMMN:```
``-NMMm/....-/--::/o+o+oo+oo++oosyss+smyo/.............:yyho-`     smMMddh-......./NMMN.``
`.hMMM/......-++:-.-:oooooooooosyyhhys/...............-+osyyyyysssssooo+ohhs-......+MMMh.`
`+MMMy.......-::/++:-.....-:/++++o+o/--................--/oooo+o++o+++////-y/.......hMMM/`
.mMMN:.........--:---...-::/+//::--.......................--//+//-...-.....+/......./NMMd`
/MMMy............-::----------....----/+-.....................-++/:---....-o-........hMMN:
yMMM/.............--:://///oo+++/+++oo+-.......................-://+/:--::::.........+MMMs
mMMN:................----:/h:::/:/::---.........................--/osss+++:..........:NMMd
MMMd-....................:mNs:-....................................--:odo:-..........:mMMN
MMMd-....................yoshyoso:--................................../mm/...........:mMMM
MMMm:..................../-o/h.y-:+dooo+/:--....................-/osydddmh...........:mMMN
mMMN:........................+mNs `h.  -d/:/+h++ooooy+++s++y+++mo+y` yh.do...........:NMMh
sMMM+........................-hmMo/ds  oMo`.-o     :h   s:`h` `Nysd.-Ny-h:...........+MMMo
/MMMh........................./smMMMMd+NMMNNMh`    sN: .mNNMddNMMMMNmN+..............hMMN:
.dMMN/........................./+hMMMMMMMMMMMMmhyyyNMNNMMMMMMMMMMMNsoo-............./NMMd`
`+MMMh.........................-/+omMMMMMMMMMMMMMMMMMMMMMMMMMMMMms-/+...............hMMM/`
`.hMMM+..........................:/-omMMMMMMMMMMMMMMMdmMdhMMMds/-..-...............oMMMy``
``.NMMN/............................--/hNN/h.`ys:dmsd:-syos+--+.................../NMMN.``
```/NMMm:...........................:+/--:+s++oo+osoo+/:-..-/+::-................/mMMN:```
````/NMMN:............................-/++/:-..........-//+/-..:+.--............/NMMN/````
`````:NMMN+-.............../+-.............-://////////:-.......+s+::.........-oNMMN:`````
``````:mMMMy-..............:/o-.................................:yo//........-hMMMd-``````
```````.yMMMm+.............:o:++-...............................+y+o-......-+mMMMs.```````
`````````/mMMMd/-...........-++:+/-.---........................-ho+/.....-/dMMMm/`````````
``````````.oNMMMh/............-++:++/////:....................-yo:o-...-+hMMMNo.``````````
````````````.sNMMMdo-...........-++::++:-:/+//:..............:o:/o-..-omMMMNo.````````````
``````````````.omMMMNy+-..........-/+-.:/+/:--:+++/++//:/::/+/-+/.-+hMMMMmo```````````````
`````````````````/hNMMMNho:-...............-:/:-....--::::--..-/ohNMMMNy:`````````````````
```````````````````./hNMMMMmhs/-..........................-/shNMMMMNy/.```````````````````
```````````````````````:sdNMMMMMNdhso+/:----------:/+oshdNMMMMMNho:```````````````````````
``````````````````````````.:+ydNMMMMMMMMMMNNNNNNMMMMMMMMMMmds+:```````````````````````````
````````````````````````````````.:/osyhdmNNMMMMNNmdhyso/:.````````````````````````````````
******************************************************************************************
*                                                                                        *
*                   This logo was graciously delivered by 10003-kun ITT:                 *
*                                                                                        *
*                           http://www.0chan.ru/r/res/9996.html                          *
*                                                                                        *
*****************************************************************************************/
/*
This is template file 4 prioritized "list of works" implementation

Such "works" may be ISRs in software implemented interrupt controller, ISR's botom halfs,
processes, or other "works" that need 2B scheduled.
*/

/*************************************************************

Macros 2 #define 4 template application

---------------------------------------
function name macros

ITEM_CUT
ITEM_FASTCUT
ITEM_INSERT
ITEM_MOVE
LIST_SWITCH
LIST_HEAD

---------------------------------------
type name macros

ITEM_T
PRIO_T
INDEX_T
LIST_T

---------------------------------------
struct fielt macros

LIST
HEAD
---------------------------------------------------------------
#define ITEM_CUT
#define ITEM_INSERT
#define ITEM_MOVE
#define LIST_MOVE
#define LIST_SWITCH
#define LIST_HEAD

#define ITEM_T
#define PRIO_T
#define INDEX_T
#define LIST_T

#define LIST
#define HEAD


#undef ITEM_CUT
#undef ITEM_INSERT
#undef ITEM_MOVE
#undef LIST_MOVE
#undef LIST_SWITCH
#undef LIST_HEAD

#undef ITEM_T
#undef PRIO_T
#undef INDEX_T
#undef LIST_T

#undef LIST
#undef HEAD



**************************************************************/

#ifndef ITEM_CUT
	#error "You must "#define ITEM_CUT"!"
#endif

#ifndef ITEM_FASTCUT
	#error "You must "#define ITEM_FASTCUT"!"
#endif

#ifndef ITEM_INSERT
	#error "You must "#define ITEM_INSERT"!"
#endif

#ifndef ITEM_MOVE
	#error "You must "#define ITEM_MOVE"!"
#endif

#ifndef LIST_SWITCH
	#error "You must "#define LIST_SWITCH""
#endif

#ifndef LIST_HEAD
	#error "You must "#define LIST_HEAD""
#endif

//====================================================
#ifndef ITEM_T
	#error "You must "#define ITEM_T""
#endif

#ifndef PRIO_T
	#error "You must "#define PRIO_T""
#endif

#ifndef INDEX_T
	#error "You must "#define INDEX_T""
#endif

#ifndef LIST_T
	#error "You must "#define LIST_T""
#endif

//====================================================
#ifndef LIST
	#error "You must "#define LIST""
#endif
#ifndef HEAD
	#error "You must "#define HEAD""
#endif
INLINE static inline void _item_fast_cut( ITEM_T * item ){
    register LIST_T * list = item->LIST;
    PRIO_T prio = (PRIO_T)(item->prio);
    if(item->next==item){
        //it was the only item in the prioritylist
        list->HEAD[prio] = ((ITEM_T *)0);
        list->index &= ~(INDEX_T)(((INDEX_T)1)<<((PRIO_T)prio));

    }else{
        // switch the prioritylist if we cut its head
        register ITEM_T ** head = ((ITEM_T **)&(list->HEAD))+(PRIO_T)prio;
        if(*head==item)*head = item->next;
        // weld prev and next items
        item->prev->next = item->next;
        item->next->prev = item->prev;
        // keep item links cnsistent
        item->next = item;
        item->prev = item;
    }
}
//====================================================
void ITEM_CUT( ITEM_T * item ){
    _item_fast_cut(item);
    item->LIST = (LIST_T *)0;
}

//====================================================
void ITEM_FASTCUT( ITEM_T * item ){
    _item_fast_cut(item);
}

INLINE static inline void _item_insert( ITEM_T * item, LIST_T * list ){
    PRIO_T prio = (PRIO_T)(item->prio);
    INDEX_T mask = ((INDEX_T)1)<<((PRIO_T)prio);
    if( (list->index) & mask ){
        //  not a new prio, insert to existing prioritylist
        register ITEM_T * current_head = list->HEAD[(PRIO_T)prio];
        item->next = current_head;
        item->prev = current_head->prev;
        current_head->prev = item;
        item->prev->next = item;
    }else{
        // new prio, create prioritylist
        list->index |= (INDEX_T)mask;
        list->HEAD[(PRIO_T)prio] = item;
    }
    item->LIST = list;
}
//====================================================
void ITEM_INSERT( ITEM_T * item, LIST_T * list ){
    _item_insert(item,list);
}

//====================================================
void ITEM_MOVE( ITEM_T * item, LIST_T * new_list ){
    _item_fast_cut(item);
    _item_insert(item,new_list);
}

//====================================================
void LIST_SWITCH( LIST_T * list, PRIO_T prio){
    list->HEAD[(PRIO_T)prio] = list->HEAD[(PRIO_T)prio]->next;
}

//====================================================
ITEM_T * LIST_HEAD( LIST_T * list ){
    INDEX_T index = (INDEX_T)(list->index);
#ifdef CONFIG_USE_O1_SEARCH
    INDEX_T upper = ~(INDEX_T)0, lower = ~(INDEX_T)0, middle;
    PRIO_T step = (PRIO_T)BITS_IN_INDEX_T, prio = (PRIO_T)0;
    while(step){
        step>>=1;
        middle = ((INDEX_T)lower)>>((PRIO_T)step);
        if( ((INDEX_T)index) & ((INDEX_T)upper) & ((INDEX_T)middle) ){
            lower = (INDEX_T)middle;
        }else{
            upper = ~(INDEX_T)middle;
            prio += (PRIO_T)step;
        }
    }
    if((INDEX_T)index) return( (ITEM_T *)(list->HEAD[(PRIO_T)prio]) );
    else return( (ITEM_T *)0 );
#else
    if((INDEX_T)index){
        PRIO_T prio = (PRIO_T)0;
        INDEX_T mask = (INDEX_T)1;
        while(mask){
            if( ((INDEX_T)mask)&((INDEX_T)index) )break;
            prio++;
            mask<<=1;
        }
        return( (ITEM_T *)(list->HEAD[(PRIO_T)prio]) );
    }else return( (ITEM_T *)0 );
#endif
}
