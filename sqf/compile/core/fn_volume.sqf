private ['_volume', '_packet'];
_volume = [_this, 0, 0, [0]] call BIS_fnc_param;
MRADIO_VOLUME = _volume;
_packet = format['VOLUME%1%2%3', toString [10], _volume, toString [10]];
'nradio' callExtension _packet;