# nRadio - [Downloads](https://github.com/maca134/arma-nradio/releases)

## Project abandoned due to lack of help/contributions...

nRadio is a small mod for ARMA that allows clients to listen to internet radio mp3 streams. The mod includes a set of simple functions to interact with the extension and a basic "radio" dialog.
Here is a small video of an earlier version: https://www.youtube.com/watch?v=SUQZwLJ8pTc

#### Adding Stations To The Dialog

If you take a look [here](https://github.com/maca134/arma-nradio/blob/master/sqf/nradio.hpp#L1), this is how the radio stations are defined. If you include the `nRadio` class in the mission's description.ext, the dialog will display those stations instead.

### Functions
##### Core
Get status (STOP, WAITING, PLAYING):
`[] call NRD_fnc_status`

Gets current song (if available):
`[] call NRD_fnc_song`

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

### Donate ###

If you like this app and use it, please consider donating via [PayPal](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=95G5FZ8PSW63W) or becoming a [Patreon](https://www.patreon.com/maca134).
