/* #Qomake
$[
	1.063,
	["NRD_Main",[[0,0,1,1],0.025,0.04,"GUI_GRID"],0,0,0],
	[1800,"NRD_Add_Background",[1,"",["0.29375 * safezoneW + safezoneX","0.357 * safezoneH + safezoneY","0.4125 * safezoneW","0.319 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1801,"NRD_Add_Header",[1,"ARMA LIVE RADIO STREAMING DEVICE",["0.29375 * safezoneW + safezoneX","0.335 * safezoneH + safezoneY","0.4125 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","1"],[]],
	[1803,"NRD_Add_Name_Header",[1,"NEW RADIO STATION NAME",["0.304062 * safezoneW + safezoneX","0.379 * safezoneH + safezoneY","0.391875 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","1"],[]],
	[1600,"NRD_Add_Cancel",[1,"CANCEL",["0.304062 * safezoneW + safezoneX","0.599 * safezoneH + safezoneY","0.0928125 * safezoneW","0.055 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","1"],[]],
	[1601,"NRD_Add_Add",[1,"ADD NEW STATION",["0.603125 * safezoneW + safezoneX","0.599 * safezoneH + safezoneY","0.0928125 * safezoneW","0.055 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","1"],[]],
	[1802,"NRD_Add_URL_Header",[1,"NEW RADIO STATION STREAM URL",["0.304062 * safezoneW + safezoneX","0.489 * safezoneH + safezoneY","0.391875 * safezoneW","0.022 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","1"],[]],
	[1400,"NRD_Add_Name_Edit",[1,"*** ENTER NAME HERE ***",["0.304062 * safezoneW + safezoneX","0.412 * safezoneH + safezoneY","0.391875 * safezoneW","0.055 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
	[1401,"NRD_Add_URL_Edit",[1,"*** ENTER URL HERE ***",["0.304062 * safezoneW + safezoneX","0.522 * safezoneH + safezoneY","0.391875 * safezoneW","0.055 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/

class NRD_Add
{
	idd=23973;
	movingenable=false;
	enableSimulation = true;
	name= "NRD_Add";
	
	class controls 
	{
		class NRD_Add_Background: NRD_RscFrame
		{
			idc = 13413;
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.4125 * safezoneW;
			h = 0.319 * safezoneH;
			colorBackground[] = {0.2,0.2,0.2,0.8};
		};
		class NRD_Add_Header: NRD_RscFrame
		{
			idc = 13414;
			text = "ARMA LIVE RADIO STREAMING DEVICE";
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.335 * safezoneH + safezoneY;
			w = 0.4125 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0.8,0,0,1};
		};
		class NRD_Add_Name_Header: NRD_RscFrame
		{
			idc = 13415;
			text = "NEW RADIO STATION NAME";
			x = 0.304062 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.391875 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0.8,0,0,1};
		};
		class NRD_Add_Cancel: NRD_RscButton
		{
			idc = 13416;
			text = "CANCEL";
			x = 0.304062 * safezoneW + safezoneX;
			y = 0.599 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.055 * safezoneH;
		};
		class NRD_Add_Add: NRD_RscButton
		{
			idc = 13417;
			text = "ADD NEW STATION";
			x = 0.603125 * safezoneW + safezoneX;
			y = 0.599 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.055 * safezoneH;
		};
		class NRD_Add_URL_Header: NRD_RscFrame
		{
			idc = 13418;
			text = "NEW RADIO STATION STREAM URL";
			x = 0.304062 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.391875 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0.8,0,0,1};
		};
		class NRD_Add_Name_Edit: NRD_RscEdit
		{
			idc = 13419;
			text = "";
			x = 0.304062 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.391875 * safezoneW;
			h = 0.055 * safezoneH;
		};
		class NRD_Add_URL_Edit: NRD_RscEdit
		{
			idc = 13420;
			text = "";
			x = 0.304062 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.391875 * safezoneW;
			h = 0.055 * safezoneH;
		};
	};
};