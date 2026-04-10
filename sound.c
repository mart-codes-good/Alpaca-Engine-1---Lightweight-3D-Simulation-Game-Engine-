#include "sound.h"
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>
#include <stdio.h>

// Static to avoid other files modifying
static ALCdevice *device = NULL;
static ALCcontext *context = NULL;

bool soundInit(Sound *sound){
    device = alcOpenDevice(NULL); // NULL means use actual system default outputs
    if(!device){
        printf("Sound.c: No audio devide found .\n"); // sanity check
        sound->isInitalized = false;
        return false; // fail safely without destroying something
    }

    context = alcCreateContext(device, NULL); // create workspace for audio states ( buffers, sources, listeners)
    alcMakeContextCurrent(context);
    alutInit(NULL, 0); // Intialize OpenAL toolkit
    sound->isInitalized = true;
    printf("Sound.c: Intialized!\n");
    return true; // It works!
}

void soundPlay(const char *filename){
    // load .wav file to OpenAL buffer, allocates memory and stores the raw audio samples
    ALuint buffer = alutCreateBufferFromFile(filename);
    if(!buffer){
        printf("Sound.c: Failed to load %s\n", filename);
        return;
    }

    // Create an OpenAl Source, A source is something that plays the sound
    ALuint source;
    alGenSources(1, &source);

    alSourcei(source, AL_BUFFER, buffer); // Tells OpenAl which audio to play
    alSourcePlay(source); // Play sound once

}

void soundPlayAt(const char *filename, float x, float y, float z, float volume, float refdist, float rolloff){
    ALuint buffer = alutCreateBufferFromFile(filename);
    if(!buffer){
        printf("Sound.c: Failed to load %s\n", filename);
        return;
    }

    ALuint source;
    alGenSources(1, &source);
     alSourcei(source, AL_BUFFER, buffer);

    // Where sound comes from in 3D space
    alSource3f(source, AL_POSITION, x, y ,z);

    // Set individual sound volume (0.0f = silent, 1.0f = full)
    alSourcef(source, AL_GAIN, volume);

    alSourcef(source, AL_REFERENCE_DISTANCE, refdist); // At this distance from source sound plays at full volume. Beyond it, volume gradually decreases.
    alSourcef(source, AL_ROLLOFF_FACTOR, rolloff); // how fast the sound fades as you move farther away

    alSourcePlay(source);

}

void soundCleanUp(Sound* sound){
    if(!sound->isInitalized) return ; // If failed no cleanup needed

    alutExit(); //  Tell ALUT to close and release its internal memory
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device); 

    sound->isInitalized = false;
    printf("Sound.c: Cleaned up and closed.\n");
}