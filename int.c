/*
** EPITECH PROJECT, 2020
** int.c
** File description:
** integer
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "int.h"
#include "./new.h"

typedef struct
{
    Class   base;
    int     nb;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->nb = va_arg(*args, int);
}

void Int_dtor(IntClass *this)
{
    if (!this)
        raise("free called but no object");
}

void *Int_to_string(IntClass *this)
{
    char *str;

    if (!this)
        raise("No Int to_string");
    asprintf(&str, "<%s (%d)>", this->base.__name__, this->nb);

    return (str);
}

Object *Int_add(Object *p1, Object *p2)
{
    Object *tmp;

    if (!p1 || !p2)
        raise("Ints to add not found");

    tmp = new(Int,
    (((IntClass*)p1)->nb + ((IntClass*)p2)->nb));
    return (tmp);
}

Object *Int_sub(Object *p1, Object *p2)
{
    Object *tmp;

    if (!p1 || !p2)
        raise("Int to add not found");

    tmp = new(Int,
    (((IntClass*)p1)->nb - ((IntClass*)p2)->nb));
    return (tmp);
}

Object *Int_mul(Object *p1, Object *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Int to mul not founds");
    dest = new(Int,
    (((IntClass *)p1)->nb * ((IntClass *)p2)->nb));
    return (dest);
}

Object *Int_div(Object *p1, Object *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Int to div not found");
    else if ((((IntClass *)p2)->nb) == 0)
        return (new(Int, (int)0));
    dest = new(Int,
    (((IntClass *)p1)->nb / ((IntClass *)p2)->nb));
    return (dest);
}

Object *Int_eq(Object *p1, Object *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Int to eq not found");
    dest = new(Int,
    (((IntClass *)p1)->nb == ((IntClass *)p2)->nb));
    return (dest);
}

Object *Int_gt(Object *p1, Object *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Int to gt not found");
    dest = new(Int,
    (((IntClass *)p1)->nb > ((IntClass *)p2)->nb));
    return (dest);
}

Object *Int_lt(Object *p1, Object *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("int to eq not found");
    dest = new(Int,
    (((IntClass *)p1)->nb < ((IntClass *)p2)->nb));
    return (dest);
}

// Create additional functions here

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_to_string,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .nb = 0,
};

const Class   *Int = (const Class *)&_description;
