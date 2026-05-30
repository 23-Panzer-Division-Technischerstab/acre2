class CfgWeapons {
    class ACRE_BaseRadio;
    class CBA_MiscItem_ItemInfo;

    class ACRE_FUSPRECHF: ACRE_BaseRadio {
        displayName = QUOTE(NAME_FUSPRECHF);
        useActionTitle = QUOTE(NAME_FUSPRECHF);
        picture = QPATHTOF(Data\static\bf888s_icon.paa);
        model = QPATHTOF(Data\models\acre_bf888s_model.p3d);
        descriptionShort = "Fusprech.f HF Radio";

        scopeCurator = 2;
        scope = 2;

        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 8;
            scope = 0;
        };

        class Library {
            libTextDesc = QUOTE(NAME_BF888S);
        };

        EGVAR(arsenalStats,frequencyMin) = 19998e3;
        EGVAR(arsenalStats,frequencyMax) = 21473e3;
        EGVAR(arsenalStats,transmitPower) = 8000;
        EGVAR(arsenalStats,effectiveRange) = "3-5km (2-3km)";
    };

    RADIO_ID_LIST(ACRE_FUSPRECHF)
};
