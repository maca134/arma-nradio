private ['_display','_list','_volume','_playButton','_stopButton','_addButton','_removeButton'];
disableSerialization;
if (isNil 'MRADIO_VOLUME') then {
	MRADIO_VOLUME = 50; /* Set the volume if it doesn't exist */
};
createDialog 'NRD_Main'; /* Create the dialog */

_display = findDisplay 23974;
_list = _display displayCtrl 13410;
_volume = _display displayCtrl 13412;
_volume sliderSetRange [0, 100];
_volume sliderSetPosition MRADIO_VOLUME;

call NRD_fnc_fillStations;

_volume ctrlAddEventHandler['SliderPosChanged', {
	[round (_this select 1)] call NRD_fnc_volume;
}];

/* Buton UI Event Handlers */
_playButton = _display displayCtrl 13406;
_playButton ctrlAddEventHandler['ButtonClick', {
	_selectedStationIndex = lbCurSel 13410;
	if (_selectedStationIndex != -1) then {
		_url = lbData[13410,_selectedStationIndex];
		[_url] call NRD_fnc_play;
		systemChat format ["NRD - Playing %1",_url];
	} else {
		systemChat "Error - Please select a station first";
	};
}];

_stopButton = _display displayCtrl 13407;

_stopButton ctrlAddEventHandler['ButtonClick', NRD_fnc_stop];

_addButton = _display displayCtrl 13408;
_addButton ctrlAddEventHandler['ButtonClick', NRD_fnc_startAdd];

_removeButton = _display displayCtrl 13409;
_removeButton ctrlAddEventHandler['ButtonClick', {
	private ['_selectedStationIndex','_name','_result'];
	_selectedStationIndex = lbCurSel 13410;
	if (_selectedStationIndex != -1) then {
		_name = lbText[13410,_selectedStationIndex];
		_result = [_name] call NRD_fnc_removeFromProfile;
		if (_result) then {
			systemChat "Favourite Removed";
			lbDelete [13410,_selectedStationIndex];
		} else {
			systemChat "Error - Server Stations cannot be removed";
		};
	};
}];