#ifndef PROTO_LIST_H
#define PROTO_LIST_H


#include <stdio.h>
#include <string.h>
// #include "types.h"

typedef struct {
	void * const buffer;
	int push_count;
	int pop_count;
    int index;
	int const size;
	int const element_size;
} listbuf_t;

#define __LISTBUF_VAR_DEF(type, buf, sz)    \
	type buf ## _listbuf_data[sz];			\
	listbuf_t buf = {				        \
		.buffer = buf ## _listbuf_data,		\
		.push_count = 0,			        \
		.pop_count = 0,				        \
		.index = 0,				        	\
		.size = sz,				            \
		.element_size = sizeof(type)		\
	};

// Function prototypes
int __add_element(listbuf_t* lb, void* element);
int __get_element(listbuf_t* lb, int index, void* element);
int __remove_element(listbuf_t *lb, int index, void *element);

#define LISTBUF_DEF(type, buf, size)		\
	__LISTBUF_VAR_DEF(type, buf, size)		\
	int buf ## _add_refd(type *pt)			\
	{										\
		return __add_element(&buf, pt);		\
	}										\
	int buf ## _get_refd(type *pt, int idx)	\
	{										\
		return __get_element(&buf, idx, pt); \
	}										\
	int buf ## _remove_refd(type *pt, int idx)	\
	{										\
		return __remove_element(&buf, idx, pt); \
	}
	


#define LISTBUF_ADD(buf, pt)	 buf ## _add_refd(pt)

#define LISTBUF_GET(buf, pt, idx)	 buf ## _get_refd(pt, idx)

#define LISTBUF_REMOVE(buf, pt, idx) buf ## _remove_refd(pt, idx)

#define LISTBUF_FOREACH(buf, elem)  			\
		memcpy(elem, 							\
		buf.buffer,								\
		buf.element_size);						\
	  	for (									\
		int _i=0;								\
	   	_i<buf.index; 							\
	   	memcpy(elem, 							\
		buf.buffer+(buf.element_size*(_i+1)),	\
		buf.element_size), _i++)            


#endif // PROTO_LIST_H