/* #Feduwa
$[
	1.063,
	["NRD_Main",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[1800,"NRD_Main_Background",[1,"",["0.29375 * safezoneW + safezoneX","0.313 * safezoneH + safezoneY","0.4125 * safezoneW","0.396 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1801,"NRD_Main_Header",[1,"ARMA LIVE RADIO STREAMING DEVICE",["0.29375 * safezoneW + safezoneX","0.291 * safezoneH + safezoneY","0.4125 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","1"],[]],
	[1802,"NRD_Main_Options_Background",[1,"",["0.304062 * safezoneW + safezoneX","0.357 * safezoneH + safezoneY","0.113437 * safezoneW","0.33 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1803,"NRD_Main_Options_Header",[1,"OPTIONS",["0.304062 * safezoneW + safezoneX","0.335 * safezoneH + safezoneY","0.113437 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","1"],[]],
	[1804,"NRD_Main_List_Header",[1,"AVAILABLE STATIONS",["0.427812 * safezoneW + safezoneX","0.335 * safezoneH + safezoneY","0.268125 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","1"],[]],
	[1805,"NRD_Main_List_Background",[1,"",["0.427812 * safezoneW + safezoneX","0.357 * safezoneH + safezoneY","0.268125 * safezoneW","0.33 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1600,"NRD_Main_Options_Play",[1,"PLAY SELECTED",["0.314375 * safezoneW + safezoneX","0.379 * safezoneH + safezoneY","0.0928125 * safezoneW","0.055 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","1"],[]],
	[1601,"NRD_Main_Options_Stop",[1,"STOP PLAYING",["0.314375 * safezoneW + safezoneX","0.456 * safezoneH + safezoneY","0.0928125 * safezoneW","0.055 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","1"],[]],
	[1602,"NRD_Main_Options_Add",[1,"ADD FAVOURITE",["0.314375 * safezoneW + safezoneX","0.533 * safezoneH + safezoneY","0.0928125 * safezoneW","0.055 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","1"],[]],
	[1603,"NRD_Main_Options_Remove",[1,"REMOVE FAVOURITE",["0.314375 * safezoneW + safezoneX","0.61 * safezoneH + safezoneY","0.0928125 * safezoneW","0.055 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","1"],[]],
	[1500,"NRD_Main_List_Listbox",[1,"",["0.438125 * safezoneW + safezoneX","0.379 * safezoneH + safezoneY","0.2475 * safezoneW","0.286 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/

class NRD_Main
{
	idd=23974;
	movingenable=false;
	enableSimulation = true;
	name= "NRD_Main";
	
	class controls 
	{
		class NRD_Main_Background: NRD_RscFrame
		{
			idc = 13400;
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.4125 * safezoneW;
			h = 0.396 * safezoneH;
			colorBackground[] = {0.2,0.2,0.2,0.8};
		};
		class NRD_Main_Header: NRD_RscFrame
		{
			idc = 13401;
			text = "ARMA LIVE RADIO STREAMING DEVICE"; 
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.4125 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0.8,0,0,1};
		};
		/*class NRD_Main_Options_Background: NRD_RscFrame
		{
			idc = 13402;
			x = 0.304062 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.33 * safezoneH;
			colorBackground[] = {0.4,0.4,0.4,1};
		};*/
		class NRD_Main_Options_Header: NRD_RscFrame
		{
			idc = 13403;
			text = "OPTIONS"; 
			x = 0.304062 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0.8,0,0,1};
		};
		class NRD_Main_List_Header: NRD_RscFrame
		{
			idc = 13404;
			text = "AVAILABLE STATIONS"; 
			x = 0.427812 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.268125 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0.8,0,0,1};
		};
		/*class NRD_Main_List_Background: NRD_RscFrame
		{
			idc = 13405;
			x = 0.427812 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.268125 * safezoneW;
			h = 0.33 * safezoneH;
			colorBackground[] = {0.4,0.4,0.4,1};
		};*/
		class NRD_Main_Options_Play: NRD_RscButton
		{
			idc = 13406;
			text = "PLAY SELECTED"; 
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.055 * safezoneH;
		};
		class NRD_Main_Options_Stop: NRD_RscButton
		{
			idc = 13407;
			text = "STOP PLAYING"; 
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.055 * safezoneH;
		};
		class NRD_Main_Options_Add: NRD_RscButton
		{
			idc = 13408;
			text = "ADD FAVOURITE"; 
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.055 * safezoneH;
		};
		class NRD_Main_Options_Remove: NRD_RscButton
		{
			idc = 13409;
			text = "REMOVE FAVOURITE"; 
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.055 * safezoneH;
		};
		class NRD_Main_List_Listbox: NRD_RscListBox
		{
			idc = 13410;
			x = 0.438125 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.2475 * safezoneW;
			h = 0.198 * safezoneH;
		};
		class NRD_Main_Volume_Header: NRD_RscFrame
		{
			idc = 13411;
			text = "RADIO VOLUME";
			x = 0.438125 * safezoneW + safezoneX;
			y = 0.599 * safezoneH + safezoneY;
			w = 0.2475 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0.8,0,0,1};
		};
		class NRD_Main_Volume_Slider: NRD_RscSlider
		{
			idc = 13412;
			x = 0.438125 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.2475 * safezoneW;
			h = 0.033 * safezoneH;
		};
	};
};

