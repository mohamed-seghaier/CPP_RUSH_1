/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
**
*/

#define _GNU_SOURCE
#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    if (!this)
        raise("free called but no object");
}

void *Vertex_to_string(VertexClass *this)
{
    char *str;

    if (!this)
        raise("No Vertex to_string");
    asprintf(&str, "<%s (%d, %d, %d)>", this->base.__name__, this->x, this->y, this->z);


    return (str);
}

Object *Vertex_add(Object *p1, Object *p2)
{
    Object *tmp;
    if (!p1 || !p2)
        raise("Vertex to add not found");
    tmp = new(Vertex,
    (((VertexClass *)p1)->x + ((VertexClass *)p2)->x),
    (((VertexClass *)p1)->y + ((VertexClass *)p2)->y),
    (((VertexClass *)p1)->z + ((VertexClass *)p2)->z)
    );
    return (tmp);
}

Object *Vertex_sub(Object *p1, Object *p2)
{
    Object *tmp;
    if (!p1 || !p2)
        raise("Vertex to sub not found");
    tmp = new(Vertex,
    (((VertexClass *)p1)->x - ((VertexClass *)p2)->x),
    (((VertexClass *)p1)->y - ((VertexClass *)p2)->y),
    (((VertexClass *)p1)->z - ((VertexClass *)p2)->z)
    );
    return (tmp);
}

// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_to_string,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Vertex = (const Class *)&_description;
