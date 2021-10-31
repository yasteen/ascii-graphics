#ifndef ENGINE_H 
#define ENGINE_H

#include "vecmath.h"
#include "graphics2d.h"
#include "graphics3d.h"

void startEngine(int sleepms, void (*init)(), void (*update)());
void endEngine();

#endif
