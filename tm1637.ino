#include <TM1637.h>
#include <dht.h>

int CLK = 2;
int DIO = 3;

TM1637 tm(CLK,DIO);
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;

void setup() {
   Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    
  // put your setup code here, to run once:
  tm.init();

  //set brightness; 0-7
  tm.set(2);
}

void loop() {
  // put your main code here, to run repeatedly:

  
Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
 
  tm.display(3,0);
  tm.display(2,12);
   tm.point(1);

  delay(1000);
  displayNumber(DHT.temperature);

  delay(1000);
  
}

void displayNumber(int num){   
    tm.display(1, num % 10);   
    tm.display(0, num / 10 % 10);   
    //tm.display(1, num / 100 % 10);   
    //tm.display(0, num / 1000 % 10);
}
