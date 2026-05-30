#define COMPONENT sys_fusprechf
#define COMPONENT_BEAUTIFIED Fusprech.f
#include "\idi\acre\addons\main\script_mod.hpp"

//#define DEBUG_MODE_FULL
//#define DISABLE_COMPILE_CACHE
//#define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_SYS_FUSPRECHF
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_ENABLED_SYS_FUSPRECHF
    #define DEBUG_SETTINGS DEBUG_SETTINGS_SYS_FUSPRECHF
#endif

#include "\idi\acre\addons\main\script_macros.hpp"

#define NAME_FUSPRECHF Fusprech.f


#define MAIN_DISPLAY (findDisplay 31337)

#include "\idi\acre\addons\sys_components\script_acre_component_defines.hpp"
