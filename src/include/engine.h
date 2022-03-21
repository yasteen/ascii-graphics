#ifndef ENGINE_H
#define ENGINE_H

#include "vecmath.h"
#include "graphics2d.h"
#include "graphics3d.h"

void start_engine(int sleepms, void (*init)(), void (*update)());
void end_engine();

#endif
