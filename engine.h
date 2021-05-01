#ifndef ENGINE_H
#define ENGINE_H

void startEngine(int sleepms, void (*init)(), void (*update)());
void endEngine();

#endif