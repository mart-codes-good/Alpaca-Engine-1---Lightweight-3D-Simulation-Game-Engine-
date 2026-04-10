#ifndef VECTORS_H
#define VECTORS_H

typedef struct vec3 // 3D vector
{
    float x, y, z;
}
vec3;

static inline vec3 vec3Init(float x, float y , float z);
static inline vec3 vec3add(vec3 a, vec3 b);
static inline vec3 vec3sub(vec3 a, vec3 b);



/*
    Some notes in terms of the design choices:
        When you mark a function as inline, the compiler tries to insert the code directly 
        where it’s called instead of jumping to a separate function in memory.

        removes the overhead of a function call, it’s faster, especially for very short math functions like these.

        Without static, if you define a normal function in a header file and include it in multiple .c files, 
        the linker will throw a “multiple definition” error.
*/          

#endif