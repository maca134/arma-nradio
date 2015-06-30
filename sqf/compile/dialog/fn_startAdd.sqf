private ['_display','_cancelButton','_addButton'];
disableSerialization;

createDialog 'NRD_Add';

_display = findDisplay 23973;
_cancelButton = _display displayCtrl 13416;
_addButton = _display displayCtrl 13417;

_cancelButton ctrlAddEventHandler['ButtonClick', {
	closeDialog 1;
}];

_addButton ctrlAddEventHandler['ButtonClick', {
	private ['_name','_url'];
	_name = ctrlText 13419;
	_url = ctrlText 13420;
	[_name,_url] call NRD_fnc_addStation;
	closeDialog 1;
	call NRD_fnc_fillStations;
}];