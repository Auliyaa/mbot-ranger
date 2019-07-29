#include <MeAuriga.h>
#include <mbot/serial.h>

void setup()
{
  // Simply initiaite a serial connection with the proper baud rate and follow the instructions in the mbot/serial.h header file.
  Serial.begin(MBOT_SERIAL_BAUD_RATE);
}

void loop()
{
  Serial.println("Hi there.");
  delay(1000);
}
