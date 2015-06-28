private ['_name','_url','_localStations'];
_name = [_this, 0, '', ['']] call BIS_fnc_param;
_url = [_this, 1, '', ['']] call BIS_fnc_param;
_localStations = profileNamespace getVariable ["NRD_Stations",[]];
_localStations pushBack [_name,_url];
profileNamespace setVariable ["NRD_Stations",_localStations];
saveProfileNamespace;