//CfgAcreComponents.hpp

class CfgAcreComponents {
    class ACRE_ComponentBase;

    class ACRE_BaseAntenna: ACRE_ComponentBase {
        type = ACRE_COMPONENT_ANTENNA;
        simple = 1;
        polarization = VERTICAL_POLARIZE;
        heightAG = AVERAGE_MAN_HEIGHT;
        orient = 90; // in degrees off of flat plane
        name = "Default Antenna";
        shortName = "Default";
        connector = ACRE_CONNECTOR_TNC;
        height = 1.2; //meters
        // binaryGainFile = QPATHTOF(binary\Thales_100cm_Whip_gain.aba);
        compatibleRadios[] = {};
    };

    class ACRE_WW2_2M_VH : ACRE_BaseAntenna {
        name = "2 Meter Whip Antenna";
        shortName = "2M Whip";
        connector = ACRE_CONNECTOR_SMA;
        height = 2;
        binaryGainFile = QPATHTOF(binary\2mFusprechf_gain.aba);
        compatibleRadios[] = {"ACRE_FUSPRECHF"};
    };
};
