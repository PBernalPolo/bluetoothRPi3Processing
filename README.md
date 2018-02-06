# bluetoothRPi3Processing
Some lines of code to use the bluetooth of the RPi3 with Processing.


## Materials (the ones I used)
- Raspberry Pi 3
- Arduino Uno
- Bluetooth module HC-05


## Instructions
The instructions have been obtained from:
https://medium.com/@fsjohnny/connecting-your-bluetooth-obdii-adapter-or-other-serial-port-adapters-to-a-raspberry-pi-3-f2c9663dae73

1. Run Raspbian's default bluetooth manager:
   ```
   bluetoothctl
   ```
1. Turn the bluetooth controller on:
   ```
   power on
   ```
1. Enable bluetoothctl's pairing mode by turning on the default agent:
   ```
   agent on
   default-agent
   ```
1. Scan for nearby devices:
   ```
   scan on
   ```
   The mac addresses of all the devices your RPi can find will start appearing, usually with the nickname of the device next to it.
1. Once you spot your device on the scanned list (HC-05 in our case), pair it:
   ```
   pair XX:XX:XX:XX:XX:XX
   ```
1. Trust the device, which will allow us to auto connect to this device on startup in a later stage:
   ```
   trust XX:XX:XX:XX:XX:XX
   ```
1. Create a symbolic link to use the Processing serial library:
   ```
   sudo rfcomm bind rfcomm0 XX:XX:XX:XX:XX:XX
   ```
1. Run the Processing sketch:
   ```
   DISPLAY=:0 processing-java --sketch=/home/pi/bluetooth_RPi --present
   ```

Now, Arduino and Processing should be exchanging information.
