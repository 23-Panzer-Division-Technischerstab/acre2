#include "..\script_component.hpp"
/*
 * Author: ACRE2Team
 * Handles the event of pressing the external speaker toggle button. Switches the
 * radio's audio output between the internal loudspeaker and the headset.
 *
 * Arguments:
 * 0: Unused <TYPE>
 * 1: Left or right mouse click identifier <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [["", 0], 0] call acre_sys_fusprechf_fnc_onSpeakerPress
 *
 * Public: No
 */

private _audioPath = GET_STATE("audioPath");

if (_audioPath == "INTSPEAKER") then {
    ["setState", ["audioPath", "HEADSET"]] call GUI_DATA_EVENT;
} else {
    ["setState", ["audioPath", "INTSPEAKER"]] call GUI_DATA_EVENT;
};

["Acre_GenericClick", [0,0,0], [0,0,0], 1, false] call EFUNC(sys_sounds,playSound);

[MAIN_DISPLAY] call FUNC(render);
