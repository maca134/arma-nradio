# nRadio - [Releases](https://github.com/maca134/arma-nradio/releases)

nRadio is a small mod for ARMA that allows clients to listen to internet radio mp3 streams. The mod includes a set of simple functions to interact with the extension and a basic "radio" dialog.

### Functions
##### Core
Get status (STOP, WAITING, PLAYING):
`[] call NRD_fnc_status`

Plays a stream:
`['URL'] call NRD_fnc_play`

Stop playback:
`[] call NRD_fnc_stop`

Set volume (0-100):
`[50] call NRD_fnc_volume`

##### Dialog
Open the built-in dialog
`[] call NRD_fnc_start`

### Dialog IDDs
- 23973: Add Station
- 23974: Main Dialog

### Contributor
- Maca134
- BenR
