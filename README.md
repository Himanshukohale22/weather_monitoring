# weather_monitoring
demo 
AIM: weather monitoring by Arduino-uno

COMPONENTS:
1.  Microcontroller unit (MCU) / Arduino-Uno 
2.  2.  Sensors (a) DHT11 (b) BMP180
3. Wires 
4. Breadboard
THEORY:
BASIC:
In this project, we’ve made a device that moniters the parameters of the environment like temperature,pressure, humidity and altitude.
We areusing the “DHT11 sensor” which is easily capable of measuring the temperature and humidity , and the “BMP180” sensor is used for measuring the altitude and pressure, also we are using the arduino uno there which helps in displaying the values in the serial monitor.
DHT11 and BMP180 sensors are connected to the Arduino-uno.

ARDUINO-UNO:
Arduino Uno is a microcontroller board based on the ATmega328P (datasheet). It has 14 digital input/output pins (of which 6 can be used as PWM outputs), 6 analog inputs, and a 16 MHz ceramic resonator.
The board can operate on an external supply from 6 to 20 volts. If supplied with less than 7V, however, the 5V pin may supply less than five volts and the board may become unstable. If using more than 12V, the
voltage regulator may overheat and damage the board. The recommended range is 7 to 12 volts.
The ATmega328 has 32 KB (with 0.5 KB occupied by the bootloader). It also has 2 KB of SRAM and 1 KB of EEPROM
The ATmega328 also supports I2C (TWI) and SPI communication.
The ATmega328 provides UART (5V) serial communication, which is available on digital pins 0 (RX) and 1 (TX).



//DHT11
THE DHT11:
The DHT11 sensor in the weather monitoring system measures the temperature and humidity by the inbuilt sensors.
There are two sensors, one of them measures the temperature and the other one always measures the humidity.
There is an IC too which sends the data in the multiplex form and we always connect this DHT11 sensor with the Arduino and Arduino gets this information.
After getting the information the Arduino works on the data. according to the code and inbuilt sensor library. To make this weather monitoring system Arduino calibrates the sensor by using the coding which we will upload to the Arduino.
Humidity calculation formula by DHT11 :
![image](https://user-images.githubusercontent.com/114358863/207405182-b82d0c7b-2ea2-464e-98d4-e0997c16af84.png)


DHT11 Specifications
1.Operating Voltage: 3.5V to 5.5V
2.Operating current: 0.3mA (measuring) 60uA (standby)
3.Output: Serial data
4.Temperature Range: 0°C to 50°C
5.Humidity Range: 20% to 90%
6.Resolution: Temperature and Humidity both are 16-bit
7.Accuracy: ±1°C and ±1%

//bmp180
BMP180:
The BMP180 is the function compatible successor of the BMP085, a new generation of high precision digital pressure sensors for consumer applications.
The BMP180 is designed to be connected directly to a microcontroller of a mobile device via the I2C bus.
I2C stands for the inter-integrated controller. This is a serial communication protocol that can connect low-speed devices. It is a master-slave communication in which we can connect and control multiple slaves from a single master. In this, each slave device has a specific address.
The pressure and temperature data has to be compensated by the calibration data of the E2PROM of the BMP180.
With the measured pressure p and the pressure at sea level p0 e.g. 1013.25hPa, the altitude in meters can be calculated with the international barometric formula:
With the measured pressure p and the absolute altitude, the pressure at sea level can be calculated:

![image](https://user-images.githubusercontent.com/114358863/207405277-52e0f11f-46ba-4675-bce9-9b202fef85e3.png)


BMP180 SPECIFICATIONS:
1.operating  voltage of  BMP180: 1.3V – 3.6V
2.Input voltage of  BMP180MODULE: 3.3V to 5.5V
3.Peak current : 1000uA
4.Consumes 0.1uA standby
5.Maximum voltage at SDA , SCL : VCC + 0.3V
6.Operating temperature: -40ºC to +80ºC
CIRCUIT DIAGRAM OF THE PROJECT:

![image](https://user-images.githubusercontent.com/114358863/207405018-f14be706-3237-49cd-b5ec-3f4f11d6b85c.png)



WORKING:
1. In the above diagram, DHT11 and BMP180 sensors are connected to arduino-uno 2. DHT11 has 3 pins [power,ground and data pin] . Data pin is connected to digital pin number 2 of arduino-uno. Power pin is connected to 5v , ground is connected to the ground pin of arduino-uno 3. BMP180 runs on I2C protocols. I2C is a serial communication protocol that has 2 lines i.e SDA and SCL. SCL works as a clock, SDA line is connected to BMP180 sensor. Power pin and ground pins of BMP180 are connected to 5v and ground pin of arduino-uno 4. After hardware connections, we implement the code in the arduino IDE . 5. After flashing the code in the arduino IDE, we get the required values of all  weather parameters in the serial monitor of the arduino IDE. CODE:

READINGS:
![image](https://user-images.githubusercontent.com/114358863/207405362-3d796063-3c7e-4d86-9ef0-cedbfb324f87.png)

CONCLUSION:
We made a weather monitoring system using arduino-uno and with the help of sensors like BMP180 and DHT11 and produced the readings of the required weather parameters.
