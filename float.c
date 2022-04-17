/*
** EPITECH PROJECT, 2020
** float.c
** File description:
**
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "float.h"
#include "./new.h"

typedef struct 
{
    Class base;
    float flo;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->flo = va_arg(*args, int);
}

void Float_dtor(FloatClass *this)
{
    if (!this)
        raise("free called but no object");
}

void *Float_to_string(FloatClass *this)
{
    char *str;

    if (!this)
        raise("No Float to_string");
    asprintf(&str, "<%s (%f)>", this->base.__name__, this->flo);

    return (str);
}

Object *Float_add(Object *p1, Object *p2)
{
    Object *tmp;
    
    if (!p1 || !p2)
        raise("Floats to add not found");
    tmp = new(Float,
    (((FloatClass *)p1)->flo + ((FloatClass *)p2)->flo));
    return (tmp);
}

Object *Float_sub(Object *p1, Object *p2)
{
    Object *tmp;
    
    if (!p1 || !p2)
        raise("Floats to sub not found");
    tmp = new(Float,
    (((FloatClass *)p1)->flo - ((FloatClass *)p2)->flo));
    return (tmp);
}

Object *Float_mul(Object *p1, Object *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Float to mul not founds");
    dest = new(Float,
    (((FloatClass *)p1)->flo * ((FloatClass *)p2)->flo));
    return (dest);
}

Object *Float_div(Object *p1, Object *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Float to div not found");
    else if ((((FloatClass *)p2)->flo) == 0)
        return (new(Float, (float)0));

    dest = new(Float,
    (((FloatClass *)p1)->flo / ((FloatClass *)p2)->flo));
    return (dest);
}

Object *Float_eq(Object *p1, Object *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Float to eq not found");
    dest = new(Float,
    (((FloatClass *)p1)->flo == ((FloatClass *)p2)->flo));
    return (dest);
}

Object *Float_gt(Object *p1, Object *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Float to gt not found");
    dest = new(Float,
    (((FloatClass *)p1)->flo > ((FloatClass *)p2)->flo));
    return (dest);
}

Object *Float_lt(Object *p1, Object *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Float to eq not found");
    dest = new(Float,
    (((FloatClass *)p1)->flo < ((FloatClass *)p2)->flo));
    return (dest);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_to_string,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .flo = 0,
};
const Class   *Float = (const Class *)&_description;