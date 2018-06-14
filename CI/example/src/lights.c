#include <stdbool.h>
#include "lights.h"

static bool is_lights_on = false;

void Lights_SetHeadlightSwitchOff(void) { is_lights_on = false; }

void Lights_SetHeadlightSwitchOn(void) { is_lights_on = true; }

bool Lights_IsHeadlightOn(void) { return is_lights_on; }