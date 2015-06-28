private ['_search','_result','_localStations'];
_search = [_this, 0, '', ['']] call BIS_fnc_param;
_result = false;
_localStations = profileNamespace getVariable ["NRD_Stations",[]];
{
	if (_x select 0 == _search) exitWith {
		_localStations deleteAt _forEachIndex;
		_result = true;
	};
} forEach _localStations;
profileNamespace setVariable ["NRD_Stations",_localStations];
saveProfileNamespace;
_result