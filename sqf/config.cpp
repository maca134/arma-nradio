class CfgPatches {
	class a3_nradio {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Functions_F"};
	};
};

class CfgFunctions {
	class NRD {
		class Core {
			file = "\x\addons\a3_nradio\compile\core";
			class status {};
			class play {};
			class stop {};
			class volume {};
			class song {};
		};
		class Dialog {
			file = "\x\addons\a3_nradio\compile\dialog";
			class removeFromProfile {};
			class addStation {};
			class fillStations {};
			class start {};
			class startAdd {};
		};
	};
};

#include "nradio.hpp"