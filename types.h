#ifndef __TYPES_H__
#define __TYPES_H__



typedef struct s_user
{
    int id;
    void (*fn)(void);
} user_t;


#endif // __TYPES_H__