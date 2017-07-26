//librerias
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

//variables globales
#define pinSensorLluvia A0
#define pinDeSalida 13//no modificable constante
DHT dht ( pinDeSalida, DHT11);//
Adafruit_BMP085 bmp;
int sensorlluvia; 

//funciones

//void setup

//void loop

void medirTemperatura() {
  //codigo para medir temperatura
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
  }


  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
}

void medirLluvia() {
  //codigo para medir lluvia
  sensorlluvia= analogRead(pinSensorLluvia);
  Serial.println(sensorlluvia);
}

void medirPresionAtmosferica() {
  //codigo para medir medirPresionAtmosferica
Serial.print("Temperature = ");
  int temperatura = bmp.readTemperature();
  
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");

    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
    Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(" meters");
    
    Serial.println();
    delay(500);

}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  dht.begin();
    if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  }
}

void loop() {
  // put your main code here, to run repeatedly:
medirTemperatura();
medirLluvia();
medirPresionAtmosferica();

}
