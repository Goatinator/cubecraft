#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

//Standard C headers
#include <malloc.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//DevKitPro headers
#include <gccore.h>
#include <wiiuse/wpad.h>

#include "debug.h"

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(*arr))

extern int gDisplayWidth;
extern int gDisplayHeight;
extern u16 gControllerPressedKeys;
extern u16 gControllerHeldKeys;
extern s8 gAnalogStickX;
extern s8 gAnalogStickY;
extern s8 gCStickX;
extern s8 gCStickY;

#endif //GUARD_GLOBAL_H
