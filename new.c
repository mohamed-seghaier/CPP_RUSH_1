/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
**
*/

#include "new.h"

Object *new(const Class *class, ...)
{
    va_list ap;
    Class *obj;

    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);
    return (obj);
}

Object *va_new(const Class *class, va_list* ap)
{
    Class *obj;

    if ((obj = malloc(class->__size__)) == NULL)
            raise("Out of memory");
    memcpy(obj, class, class->__size__);
    if (obj->__ctor__)
        obj->__ctor__(obj, ap);
    return (obj);
}

void delete(Object *ptr)
{
    if (((Class *)ptr)->__dtor__) {
        ((Class *)ptr)->__dtor__(ptr);
    }
    if (ptr)
        free(ptr);
}