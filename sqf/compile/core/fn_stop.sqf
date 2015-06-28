private ['_packet'];
_packet = format['STOP%1', toString [10]];
'nradio' callExtension _packet;