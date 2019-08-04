#ifndef _MBOT_SERIAL_H_
#define _MBOT_SERIAL_H_

#include <SoftwareSerial.h>

/**
  * Since the Bluetooth module & the serial port are located on the same pin,
  * serial communication with the mBot is done through bluetooth.
  *
  * For debugging purposes, you may want to install the Serial Bluetooth terminal app on your phone (https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=en)
  * Then, in the Devices menu, switch to the Bluetooth LE tab and long-tap the Makeblock entry then select Edit.
  * From there, check Custom and edit each entry (a manu will popup for each edit box once you press them, simply select one of the proposed UUIDs)
  */
#define MBOT_SERIAL_BAUD_RATE 115200

#endif // _MBOT_SERIAL_H_
