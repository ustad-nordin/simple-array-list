# Simple Array List

## Intro
This is a simple array that behaves like a list.
At the moment you can add any type of data, get an element from a specific index and 
you loop through the array using built-in foreach loop. See an exaample below.

```c
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
```
See main.c for the complete code.

## What's next
This is the first version, but I'll add some more features. Feel free to clone the project to improve it.
