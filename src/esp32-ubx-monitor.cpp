/*
  Reading Position, Velocity and Time (PVT) via UBX binary commands
  By: Paul Clark (enhanced and adapted for VSCode / PlatformIO by semuadmin)
  SparkFun Electronics
  Date: December 21st, 2022
  License: MIT. Please see LICENSE.md for more information.

  This example shows how to query a u-blox module for its position, velocity and time (PVT) data.
  We also turn off the NMEA output on the I2C port. This decreases the amount of I2C traffic dramatically.
*/

#include <esp32-ubx-monitor.h>

const char * getFixType( uint8_t fix )
{
  return FixStrings[fix];
}

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("SparkFun u-blox Example, adapted by semuadmin");

  Wire.begin(); // Start I2C

  // myGNSS.enableDebugging(); // Uncomment this line to enable helpful debug messages on Serial

  while (myGNSS.begin() == false) // Connect to the u-blox module using Wire port
  {
    Serial.println(F("u-blox GNSS not detected at default I2C address. Retrying..."));
    delay(1000);
  }

  myGNSS.setI2COutput(COM_TYPE_UBX); // Set the I2C port to output UBX only (turn off NMEA noise)

  // myGNSS.saveConfigSelective(VAL_CFG_SUBSEC_IOPORT); //Optional: save (only) the communications port settings to flash and BBR
}

void loop()
{
  // Request (poll) the position, velocity and time (PVT) information.
  // The module only responds when a new position is available. Default is once per second.
  // getPVT() returns true when new data is received.
  if (myGNSS.getPVT() == true)
  {

    double lat = myGNSS.getLatitude() / D7;
    double lon = myGNSS.getLongitude() / D7;
    double alt = myGNSS.getAltitudeMSL() / D3;       // Altitude above Mean Sea Level in m
    const char *fix = getFixType(myGNSS.getFixType()); // Fix type as string
    uint8_t siv = myGNSS.getSIV();                  //  Satellites in view
    double hacc = myGNSS.getHorizontalAccEst() / D3; // Horizontal accuracy estimate in m
    double vacc = myGNSS.getVerticalAccEst() / D3;   // Vertical accuracy estimate in m

    Serial.printf("Lat: %2.6f, Lon: %2.6f, Alt: %2.3f m, Fix: %s, SIV: %2d, Hacc: %2.3f m, Vacc: %2.3f m\n", lat, lon, alt, fix, siv, hacc, vacc);
  }
}
