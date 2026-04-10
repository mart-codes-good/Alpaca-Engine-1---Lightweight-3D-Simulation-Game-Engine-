#ifndef SOUND_H
#define SOUND_H

#include <stdbool.h>

typedef struct{
    bool isInitalized;
}
Sound;

// Intialize sound
bool soundInit(Sound *sound);

void soundPlay(const char *filename);

void soundPlayAt(const char *filename, float x, float y, float z, float volume, float refdist, float rolloff);

void soundCleanUp(Sound* sound);

#endif