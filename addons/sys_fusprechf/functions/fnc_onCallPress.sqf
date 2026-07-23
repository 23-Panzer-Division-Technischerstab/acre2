#include "..\script_component.hpp"
/*
 * Author: ACRE2Team
 * Handles the event of pressing the call button. Plays an alert tone, mirroring the
 * historical Fusprech.f's front-panel button that transmitted a 1000Hz calling tone
 * to get the other station's attention before/after a conversation.
 *
 * Arguments:
 * 0: Unused <TYPE>
 * 1: Left or right mouse click identifier <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [["", 0], 0] call acre_sys_fusprechf_fnc_onCallPress
 *
 * Public: No
 */

["Acre_GenericBeep", [0,0,0], [0,0,0], 1, false] call EFUNC(sys_sounds,playSound);
