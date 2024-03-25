#include <stdio.h>
#include "proto_list.h"
#include "types.h"


LISTBUF_DEF(user_t, user_list, 10)


void printHello() {
  printf("hello there!\n"); 
}

void printGreet() {
  printf("Yo wazup G!\n");
}


/**
 * To compile the sourcecode:
 * Mac: clang -o a.out -g main.c proto_list.c
 * Linux: gcc -o a.out -g main.c proto_list.c
 */

int main()
{
    user_t user1 = {1, printHello};  
    user_t user2 = {2, printGreet};
    user_t user3 = {3, printHello};

    LISTBUF_ADD(user_list, &user1);
    LISTBUF_ADD(user_list, &user2);
    LISTBUF_ADD(user_list, &user3);

    user_t user = {0};
    LISTBUF_FOREACH(user_list, &user) {
        printf("[FOREACH] user id: %d\n", user.id);
        user.fn();
    }

    LISTBUF_REMOVE(user_list, &user, 2);
    printf("[REMOVED] user id: %d\n", user.id);

    LISTBUF_FOREACH(user_list, &user) {
        printf("[FOREACH] user id: %d\n", user.id);
        user.fn();
    }


    return 0;
}


