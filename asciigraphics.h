#ifndef ASCIIGRAPHICS_H
#define ASCIIGRAPHICS_H

#include "asciigraphics/vecmath.h"
#include "asciigraphics/graphics2d.h"
#include "asciigraphics/graphics3d.h"

void startEngine(int sleepms, void (*init)(), void (*update)());
void endEngine();

#endif
