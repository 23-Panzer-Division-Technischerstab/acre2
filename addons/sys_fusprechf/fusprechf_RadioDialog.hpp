#define CODE_SPACING    0.0245

#define CONTROL_SetRelativePos(xpos,ypos) x = H_OFFSET + (xpos * 0.001); y = H_OFFSET + (ypos * 0.001);
#define CONTROL_SetDimensions(width, height) w = width * 0.001; h = height * 0.001;

#define BEGIN_CONTROL(name, parent, idval) class name: parent { idc = idval;
#define END_CONTROL        };

#define NEW_SCALE 0.85
#define SCALE (NEW_SCALE/0.8)


class FUSPRECHF_RadioDialog {
    idd = 31337;
    MovingEnable = 0;
    onUnload = QUOTE(['closeGui'] call GUI_INTERACT_EVENT);
    onLoad = QUOTE(_this call FUNC(render));
    controlsBackground[] = {"FUSPRECHFBackground"};
    objects[] = {};
    class FUSPRECHFBackground {
        type = CT_STATIC;
        idc = 99999;
        style = QUOTE(ST_PICTURE + ST_KEEP_ASPECT_RATIO);
        colorBackground[] = {0, 0, 0, 0};
        colorText[] = {1, 1, 1, 1};
        font = FontM;
        sizeEx = 0.04;
        x = "safezoneX";
        y = QUOTE((0.5-((1*safezoneW)/2)));
        w = QUOTE(1*safezoneW);
        h = QUOTE(1*safezoneW);

        text = QPATHTOF(Data\static\fusprech_f_base.paa);
    };
    class controls {
        BEGIN_CONTROL(ChannelKnob,FUSPRECHF_RscPicture,106)
            x = "safezoneX";
            y = QUOTE((0.5-((1*safezoneW)/2)));
            w = QUOTE(1*safezoneW);
            h = QUOTE(1*safezoneW);
            text = QPATHTOF(Data\knobs\channel\fusprech_f_frequency_341.paa);
        END_CONTROL

        BEGIN_CONTROL(ChannelKnobButton,FUSPRECHF_RscButton,201)
            x = QUOTE(safeZoneX + safeZoneW * 0.46484375);
            y = QUOTE(safeZoneY + safeZoneH * 0.44444445);
            w = QUOTE(safeZoneW * 0.0703125);
            h = QUOTE(0.1*SafeZoneW);
            colorBackground[] = {1, 0, 0, 0};
            text = "";
            onMouseButtonUp = "[_this,0] call acre_sys_fusprechf_fnc_onChannelKnobPress";
            toolTip = ECSTRING(sys_radio,ui_ChangeChannel);
        END_CONTROL

        BEGIN_CONTROL(VolumeKnob,FUSPRECHF_RscPicture,107)
            x = "safezoneX";
            y = QUOTE((0.5-((1*safezoneW)/2)));
            w = QUOTE(1*safezoneW);
            h = QUOTE(1*safezoneW);
            text = QPATHTOF(Data\knobs\volume\fusprech_f_volume_5.paa);
        END_CONTROL

        BEGIN_CONTROL(VolumeKnobButton,FUSPRECHF_RscButton,202)
            x = QUOTE(safeZoneX + safeZoneW * 0.70410157);
            y = QUOTE(safeZoneY + safeZoneH * 0.68055556);
            w = QUOTE(safeZoneW * 0.09960938);
            h = QUOTE(0.1*SafeZoneW);
            colorBackground[] = {0, 1, 0, 0};
            text = "";
            onMouseButtonUp = QUOTE(_this call FUNC(onVolumeKnobPress));
            toolTip = ECSTRING(sys_radio,ui_ChangeVolume);
        END_CONTROL

        BEGIN_CONTROL(Speaker,FUSPRECHF_RscPicture,108)
            x = "safezoneX";
            y = QUOTE((0.5-((1*safezoneW)/2)));
            w = QUOTE(1*safezoneW);
            h = QUOTE(1*safezoneW);
            text = QPATHTOF(Data\knobs\speaker\fusprech_f_speaker_off.paa);
        END_CONTROL

        BEGIN_CONTROL(SpeakerButton,FUSPRECHF_RscButton,203)
            x = QUOTE(safeZoneX + safeZoneW * 0.22070313);
            y = QUOTE(safeZoneY + safeZoneH * 0.32291667);
            w = QUOTE(safeZoneW * 0.09472657);
            h = QUOTE(0.1*SafeZoneW);
            colorBackground[] = {0, 1, 0, 0};
            text = "";
            onMouseButtonUp = QUOTE(_this call FUNC(onSpeakerPress));
            toolTip = ECSTRING(sys_radio,ui_ChangeVolume);
        END_CONTROL

        BEGIN_CONTROL(CallButton,FUSPRECHF_RscButton,204)
            x = QUOTE(safeZoneX + safeZoneW * 0.7578125);
            y = QUOTE(safeZoneY + safeZoneH * 0.46875);
            w = QUOTE(safeZoneW * 0.04589844);
            h = QUOTE(0.1*SafeZoneW);
            colorBackground[] = {0, 1, 0, 0};
            text = "";
            onMouseButtonUp = QUOTE(_this call FUNC(onCallPress));
            toolTip = ECSTRING(sys_radio,ui_ChangeVolume);
        END_CONTROL
    };
};
