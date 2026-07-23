class CfgWeapons {
    class ACRE_BaseRadio;
    class CBA_MiscItem_ItemInfo;

    class ACRE_FUSPRECHF: ACRE_BaseRadio {
        displayName = QUOTE(NAME_FUSPRECHF);
        useActionTitle = QUOTE(NAME_FUSPRECHF);
        picture = QPATHTOF(Data\static\fusprech_f_icon.paa);
        model = QPATHTOF(Data\Models\acre_fusprechf_model.p3d);
        descriptionShort = "Fusprech.f HF Radio";

        scopeCurator = 2;
        scope = 2;

        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 8;
            scope = 0;
        };

        class Library {
            libTextDesc = QUOTE(NAME_FUSPRECHF);
        };

        EGVAR(arsenalStats,frequencyMin) = 28000e3;
        EGVAR(arsenalStats,frequencyMax) = 33900e3;
        EGVAR(arsenalStats,transmitPower) = 8000;
        EGVAR(arsenalStats,effectiveRange) = "3-5km (2-3km)";
        EGVAR(arsenalStats,externalSpeaker) = 1;
    };

    RADIO_ID_LIST(ACRE_FUSPRECHF)
};
