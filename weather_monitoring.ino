// defining libraries
#include <Wire.h>
#include <SFE_BMP180.h>
#include <DHT.h>
#include <DHT_U.h>

// pinout define
#define DHTPIN 2         //connect dhtpin at analogpin 2
#define DHTTYPE DHT11    //type of sensor used to specify
DHT dht(DHTPIN, DHTTYPE);

#define ALTITUDE 18     // Altitude of mumbai in meters
SFE_BMP180 pressure;

// setup 

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
    
  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {

    Serial.println("BMP180 init fail\n\n");
    Serial.println("Check connection");
    while (1);
  }

}

//loop
void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);
  Serial.print(F("F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F"));
    char status;
  double T, P, p0, a;

  status = pressure.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = pressure.getTemperature(T);
    if (status != 0)
    {

      Serial.print("temperature: ");
      Serial.print(T, 2);
      Serial.println(" deg C ");

      status = pressure.startPressure(3);
      if (status != 0)
      {

        delay(status);
        status = pressure.getPressure(P, T);
        if (status != 0)
        {

          Serial.print("absolute pressure: ");
          Serial.print(P, 2);
          Serial.print(" hpa = ");
          Serial.print(P * 100, 2);
          Serial.print(" pa = ");
          Serial.print(P * 0.000986923, 2);
          Serial.print(" atm = ");
          Serial.print(P * 0.750063755, 2);
          Serial.print(" mmHg = ");
          Serial.print(P * 0.750061683, 2);
          Serial.print(" torr = ");
          Serial.print(P * 0.014503774, 2);
          Serial.println(" psi");


          p0 = pressure.sealevel(P, ALTITUDE); // we're at 943.7 meters 
          Serial.print("relative (sea-level) pressure: ");
          Serial.print(p0, 2);
          Serial.println(" hpa ");;


          a = pressure.altitude(P, p0);
          Serial.print("your altitude: ");
          Serial.print(a, 0);
          Serial.println(" meters ");
        }
        else Serial.println("error retrieving pressure measurement\n");
      }
      else Serial.println("error starting pressure measurement\n");
    }
    else Serial.println("error retrieving temperature measurement\n");
  }
  else Serial.println("error starting temperature measurement\n");
Serial.println("==========================================================================");
  delay(5000);
}