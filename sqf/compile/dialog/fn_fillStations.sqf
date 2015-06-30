private ['_display','_list','_stations','_localStations'];
_display = findDisplay 23974;
_list = _display displayCtrl 13410;
lbClear _list;

/* Get preset radio stations from mission file */
_stations = if (isClass (missionConfigFile >> 'nRadio')) then {missionConfigFile >> 'nRadio'} else {configFile >> 'nRadio'}; 
for "_i" from 0 to count _stations -1 do {
	private ['_station','_name','_url','_index'];
	_station = _stations select _i;
	_name = getText (_station >> 'name');
	_url = getText (_station >> 'url');
	_index = _list lbAdd _name;
	_list lbSetData [_index,_url];
	_list lbSetColor [_index, [0.8, 0.8, 0.8, 1]];
};

_localStations = profileNamespace getVariable ["NRD_Stations",[]];
if !(_localStations isEqualTo []) then {
	{
		private ['_name','_url','_index'];
		_name = _x select 0;
		_url = _x select 1;
		_index = _list lbAdd _name;
		_list lbSetData [_index,_url];
		_list lbSetColor [_index, [1, 1, 1, 1]];
	} forEach _localStations;
} else {
	profileNamespace setVariable ["NRD_Stations",[]];
	saveProfileNamespace;
};