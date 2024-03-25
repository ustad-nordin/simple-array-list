#include "proto_list.h"



int __add_element(listbuf_t* lb, void* element) {
    
    if (lb->index < lb->size) {
        memcpy(lb->buffer+(lb->index*lb->element_size), element, lb->element_size);
        lb->index++;
        
        return 0;
    }
    
    return -1;
}

int __get_element(listbuf_t* lb, int index, void* element) {
    if (lb->index >= 0 && index < lb->index) {
        memcpy(element, lb->buffer+(index*lb->element_size), lb->element_size);
        
        return 0;
    } 

    return -1;
}
