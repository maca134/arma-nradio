private ['_url', '_packet'];
_url = [_this, 0, '', ['']] call BIS_fnc_param;
_packet = format['PLAY%1%2%3', toString [10], _url, toString [10]];
'nradio' callExtension _packet;