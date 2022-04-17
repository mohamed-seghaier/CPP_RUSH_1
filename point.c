/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
**
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "point.h"
#include "./new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

void Point_dtor(PointClass *this)
{
    if (!this)
        raise("free called but no object");
}

void *Point_to_string(PointClass *this)
{
    char *str;

    if (!this)
        raise("No Point to_string");
    asprintf(&str, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);


    return (str);
}

Object *Point_add(Object *p1, Object *p2)
{
    Object *tmp;

    if (!p1 || !p2)
        raise("Points to add not found");

    tmp = new(Point,
    (((PointClass*)p1)->x + ((PointClass*)p2)->x),
    (((PointClass*)p1)->y + ((PointClass*)p2)->y)
    );
    return (tmp);
}

Object *Point_sub(Object *p1, Object *p2)
{
    Object *tmp;

    if (!p1 || !p2)
        raise("Ojects to add not found");

    tmp = new(Point,
    (((PointClass*)p1)->x - ((PointClass*)p2)->x),
    (((PointClass*)p1)->y - ((PointClass*)p2)->y)
    );
    return (tmp);
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_to_string,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
