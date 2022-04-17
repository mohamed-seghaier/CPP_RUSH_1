/*
** EPITECH PROJECT, 2020
** char.c
** File description:
**
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "char.h"
#include "./new.h"

typedef struct 
{
    Class base;
    char c;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->c = va_arg(*args, int);
}

void Char_dtor(CharClass *this)
{
    if (!this)
        raise("free called but no object");
}

void *Char_to_string(CharClass *this)
{
    char *str;

    asprintf(&str, "<%s (%c)>", this->base.__name__, this->c);
    // if (str)
    //     raise("Buffer Error");
    return (str);
}

Object *Char_add(Object *p1, Object *p2)
{
    Object *tmp;
    
    if (!p1 || !p2)
        raise("Chars to add not found");
    tmp = new(Char,
    (((CharClass *)p1)->c + ((CharClass *)p2)->c));
    return (tmp);
}

Object *Char_sub(Object *p1, Object *p2)
{
    Object *tmp;
    
    if (!p1 || !p2)
        raise("Chars to sub not found");
    tmp = new(Char,
    (((CharClass *)p1)->c - ((CharClass *)p2)->c));
    return (tmp);
}

Object *Char_mul(Object *p1, Object *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Char to mul not founds");
    dest = new(Char,
    (((CharClass *)p1)->c * ((CharClass *)p2)->c));
    return (dest);
}

Object *Char_div(Object *p1, Object *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Char to div not found");
    else if ((((CharClass *)p2)->c) == 0)
        return ((CharClass*)new(0));

    dest = new(Char,
    (((CharClass *)p1)->c / ((CharClass *)p2)->c));
    return (dest);
}

static bool Char_eq(CharClass *p1, CharClass *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Char to eq not found");
    return (p1->c == p2->c);
}

static bool Char_gt(CharClass *p1, CharClass *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Char to gt not found");
    return (p1->c > p2->c);
}

static bool Char_lt(CharClass *p1, CharClass *p2)
{
    Object *dest;

    if (!p1 || !p2)
        raise("Char to eq not found");
    return (p1 ->c < p2->c);
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_to_string,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = 0,
};
const Class   *Char = (const Class *)&_description;