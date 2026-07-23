#include "..\script_component.hpp"
/*
 * Author: ACRE2Team
 * Renders the radio when opened.
 *
 * Arguments:
 * 0: Display identifier <NUMBER>
 *
 * Return Value:
 * True <BOOL>
 *
 * Example:
 * [DisplayID] call acre_sys_fusprechf_fnc_render
 *
 * Public: No
 */

#define RADIO_CTRL(var1) (_display displayCtrl var1)


params ["_display"];

private _currentAbsChannel = [GVAR(currentRadioId)] call FUNC(getCurrentChannelInternal);
private _currentChannel = _currentAbsChannel;


//private _currentChannelKnobState = _currentChannelArray select 0; //channel from 0 to 15
private _currentVolume = GET_STATE("volume"); //from 0 to 1
private _currentVolumeKnobState = round (_currentVolume * 5);

{_x ctrlEnable false;} forEach [RADIO_CTRL(201),RADIO_CTRL(202)];

private _currentViewFrame = 0;
_currentViewFrame = 0;

{
    (RADIO_CTRL(_x)) ctrlSetFade 0;
    (RADIO_CTRL(_x)) ctrlCommit 0;
} forEach [106,107];

RADIO_CTRL(106) ctrlSetText format ["\idi\acre\addons\sys_fusprechf\Data\knobs\channel\fusprech_f_frequency_%1.paa", _currentChannel + 341];
RADIO_CTRL(107) ctrlSetText format ["\idi\acre\addons\sys_fusprechf\Data\knobs\volume\fusprech_f_volume_%1.paa", _currentVolumeKnobState];
RADIO_CTRL(201) ctrlSetTooltip format ["%1: %2",LELSTRING(sys_radio,ui_CurrentChannel), _currentChannel + 1];
RADIO_CTRL(202) ctrlSetTooltip format ["%1: %2%3", LELSTRING(sys_radio,ui_CurrentVolume),round (_currentVolume * 100), "%"];

private _audioPath = GET_STATE("audioPath");
RADIO_CTRL(108) ctrlSetText (if (_audioPath == "INTSPEAKER") then {
    QPATHTOF(Data\knobs\speaker\fusprech_f_speaker_on.paa)
} else {
    QPATHTOF(Data\knobs\speaker\fusprech_f_speaker_off.paa)
});

{_x ctrlEnable true;} forEach [RADIO_CTRL(201),RADIO_CTRL(202)];

TRACE_3("rendering",_currentChannel,_currentVolume,EGVAR(sys_radio,currentRadioDialog));
true
