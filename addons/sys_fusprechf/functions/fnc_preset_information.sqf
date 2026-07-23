#include "..\script_component.hpp"
/*
 * Author: ACRE2Team
 * Initialises and registers the default presets with the initial values of transmitting and receiving frequencies for each of the channels.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call acre_sys_fusprechf_fnc_preset_information
 *
 * Public: No
 */

private _presetFrequencies = [];
for "_i" from 0 to 59 do {
    private _basefrequency = 19.9975;
    private _frequencymodifier = _i * 0.025;
    private _frequency = _basefrequency + _frequencymodifier;
    PUSH(_presetFrequencies,_frequency);
};

// channels information
///Default
private _presetData = HASH_CREATE;
private _channels = HASHLIST_CREATELIST(["frequencyTX"]);
for "_i" from 0 to 59 do {
    private _frequency = _presetFrequencies select _i;
    private _channel = HASHLIST_CREATEHASH(_channels);

    HASH_SET(_channel,"frequencyTX",_frequency);
    HASH_SET(_channel,"frequencyRX",_frequency);
    HASH_SET(_channel,"power",8000);
    HASH_SET(_channel,"encryption",0);
    HASH_SET(_channel,"channelMode","BASIC");
    // HASH_SET(_channel,"CTCSSTx",69.3);
    // HASH_SET(_channel,"CTCSSRx",69.3);
    HASH_SET(_channel,"modulation","AM");
    HASH_SET(_channel,"trafficRate",16);
    HASH_SET(_channel,"TEK","");
    HASH_SET(_channel,"RPTR",0.2);
    HASH_SET(_channel,"fade",2);
    HASH_SET(_channel,"phase",256);
    HASH_SET(_channel,"squelch",3);
    //HASH_SET(_channel,"channelNumber",_i);

    HASHLIST_PUSH(_channels,_channel);
};
HASH_SET(_presetData,"channels",_channels);
["ACRE_FUSPRECHF","default",_presetData] call EFUNC(sys_data,registerRadioPreset);
