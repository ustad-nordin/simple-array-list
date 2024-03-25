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

int main()
{
    user_t user1 = {1, printHello};  
    user_t user2 = {2, printGreet};

    LISTBUF_ADD(user_list, &user2);
    LISTBUF_ADD(user_list, &user1);

    user_t user = {0};
    LISTBUF_FOREACH(user_list, &user) {
        printf("[FOREACH] user id: %d\n", user.id);
        user.fn();
    }

    return 0;
}


