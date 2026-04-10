#ifndef MODEL_H
#define MODEL_H
#include "vectors.h"

typedef struct 
{
    vec3 scale;
    vec3 offset;
    int loaded;
    char *path;
}
Model;

// basic setup
void modelInit(Model *m, vec3 scale, vec3 offset);

// Temporary models for testing, inplmenting etc
void modelDrawBean();


#endif