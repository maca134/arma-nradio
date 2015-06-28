class NRD_RscListBox
{
	deletable = 0;
	fade = 0;
	access = 0;
	type = 5;
	w = 0.4;
	h = 0.4;
	rowHeight = 0;
	colorText[] = {1,1,1,1};
	colorDisabled[] = {1,1,1,0.25};
	colorScrollbar[] = {1,0,0,0};
	colorSelect[] = {0,0,0,1};
	colorSelect2[] = {0,0,0,1};
	colorSelectBackground[] = {0.95,0.95,0.95,1};
	colorSelectBackground2[] = {1,1,1,0.5};
	colorBackground[] = {0,0,0,0.3};
	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
	arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {1,1,1,1};
	colorPictudeDisabled[] = {1,1,1,0.25};
	tooltipColorText[] = {1,1,1,1};
	tooltipColorBox[] = {1,1,1,1};
	tooltipColorShade[] = {0,0,0,0.65};
	class ListScrollBar
	{
		color[] = {1,1,1,1};
		autoScrollEnabled = 1;
	};
	style = 16;
	font = "PuristaMedium";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow = 0;
	colorShadow[] = {0,0,0,0.5};
	period = 1.2;
	maxHistoryDelay = 1;
	colorPictureDisabled[] = {1,1,1,1};
};

class NRD_RscButton {
	access = 0;
	type = 1;
	style = 0;
	x = 0; y = 0; w = 0.3; h = 0.1;
	text = "";
	font = "PuristaLight";
	sizeEx = 0.04;
	colorText[] = {1,1,1,1};
	colorDisabled[] = {0,0,0,0};
	colorBackground[] = {0,0,0,1};
	colorBackgroundDisabled[] = {0,0,0,0};
	colorBackgroundActive[] = {0.5,0,0,1};
	offsetX = 0.004;
	offsetY = 0.004;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	colorFocused[] = {0,0,0,1};
	colorShadow[] = {0,0,0,0};
	shadow = 0;
	colorBorder[] = {0,0,0,0};
	borderSize = 0;
	soundEnter[] = {"",0.1,1};
	soundPush[] = {"",0.1,1};
	soundClick[] = {"",0.1,1};
	soundEscape[] = {"",0.1,1};
};

class NRD_RscFrame
{
    type = 0;
    idc = -1;
    style = 0x00;
    shadow = 2;
    colorBackground[] = { 0.2,0.2,0.2, 0.6};
    colorText[] = {1,1,1,1};
    font = "PuristaMedium";
    sizeEx = 0.04;
    text = "";
};

class NRD_RscSlider
{
	style = 1024;
	type = 43;
	shadow = 2;
	x = 0;
	y = 0;
	h = 0.029412;
	w = 0.400000;
	color[] = {1, 1, 1, 0.7};
	colorActive[] = {1, 1, 1, 1};
	colorDisabled[] = {1, 1, 1, 0.500000};
	arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
	arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
	border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
	thumb = "\A3\ui_f\data\gui\cfg\slider\thumb_ca.paa";
};

class NRD_RscEdit
{
	access=0;
	type=2;
	style=0x00+64;
	colorBackground[]={0,0,0,0};
	colorText[]={1,1,1,1};
	colorSelection[]={1,1,1,0.25};
	colorDisabled[]={1,1,1,0};
	font="PuristaMedium";
	sizeEx=0.04;
	autocomplete="";
	text="";
	size=0.2;
	shadow=0;
};