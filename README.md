
# u-blox UBX Receiver receiver example

https://learn.sparkfun.com/tutorials/gnss-receiver-breakout---max-m10s-qwiic-hookup-guide

This example shows how to query a u-blox module for its position, velocity and time (PVT) data.
We also turn off the NMEA output on the I2C port. This decreases the amount of I2C traffic dramatically.


## Instructions

1. Install the [PlatformIO extension](https://docs.platformio.org/en/latest/integration/ide/vscode.html) for VSCode if you haven't already.
1. Download and unzip this repo, or clone it:

    ```shell
    git clone https://github.com/semuconsulting/esp32-m10s-monitor.git
    ```

1. Connect your ESP32 device to the NEO-M10S via I2C ports (SDA/SCL), or use the QWIIC connector as per the tutorial above.
1. Connect your ESP32 device to your workstation via its USB port.
1. Open the project folder in VSCode.
1. Open the PlatformIO Project Tasks tab and select 'Upload and Monitor'. The code should automatically build and upload (on some ESP32 devices you may have to press the RESET button momentarily first).
1. For further details and troubleshooting, refer to the Sparkfun tutorial at the link above.

### Sample output:

```
Lat: 51.250643, Lon: -2.610237, Alt: 35.250 m, Fix: 3D, SIV: 11, Hacc: 5.208 m, Vacc: 7.299 m
Lat: 51.250643, Lon: -2.610235, Alt: 35.060 m, Fix: 3D, SIV: 11, Hacc: 5.219 m, Vacc: 7.314 m
Lat: 51.250643, Lon: -2.610235, Alt: 35.093 m, Fix: 3D, SIV: 11, Hacc: 5.232 m, Vacc: 7.331 m
Lat: 51.250643, Lon: -2.610235, Alt: 35.041 m, Fix: 3D, SIV: 11, Hacc: 5.243 m, Vacc: 7.346 m
```

## License

Author: SparkFun Electronics / Paul Clark, adapted for VSCode / PlatformIO by semuadmin
  
Date: March 7th, 2022

License: MIT. See license file for more information but you can basically do whatever you want with this code.
