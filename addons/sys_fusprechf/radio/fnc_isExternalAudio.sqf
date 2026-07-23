#include "..\script_component.hpp"
/*
 * Author: ACRE2Team
 * Returns if the radio's internal (loudspeaker) audio path is currently active.
 *
 * Arguments:
 * 0: Radio ID <STRING> (Unused)
 * 1: Event (Unused)
 * 2: Event data (Unused)
 * 3: Radio data <HASH>
 * 4: Remote <BOOL> (Unused)
 *
 * Return Value:
 * Is External (Loudspeaker) Audio Active <BOOL>
 *
 * Example:
 * ["ACRE_FUSPRECHF_ID_1", "isExternalAudio", [], _radioData, false] call acre_sys_fusprechf_fnc_isExternalAudio
 *
 * Public: No
 */

params ["", "", "", "_radioData"];

(HASH_GET(_radioData,"audioPath") == "INTSPEAKER")
