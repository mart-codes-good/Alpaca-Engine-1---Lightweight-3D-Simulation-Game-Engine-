#include "vectors.h"

static inline vec3 vec3Init(float x, float y , float z){ // make new vector
    vec3 v = { x, y, z };
    return v;
} 
static inline vec3 vec3add(vec3 a, vec3 b){ // adds a + b returns new vector
    vec3 v = {a.x + b.x, a.y + b.y, a.z + b.z};
    return v;
} 
static inline vec3 vec3sub(vec3 a, vec3 b){ // sub a - b return new vector
    vec3 v = {a.x - b.x, a.y - b.y, a.z - b.z};
    return v;
} 