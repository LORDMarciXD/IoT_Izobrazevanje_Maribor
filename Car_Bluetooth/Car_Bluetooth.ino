//th hc/*
// * Program za spreminjanje nastavitev Bluetooth modula
//* Navodila:
//* https://www.instructables.com/id/Modify-The-HC-05-Bluetooth-Module-Defaults-Using-A/
//*/


/*
AUTHOR: Hazim Bitar (techbitar)
DATE: Aug 29, 2013
LICENSE: Public domain (use at your own risk)
CONTACT: techbitar at gmail dot com (techbitar.com)
To return HC-05 to mfg. default settings: "AT+ORGL"
To get version of your HC-05 enter: "AT+VERSION?"
To change device name from the default HC-05 to let's say MYBLUE enter: "AT+NAME=MYBLUE"
To change default security code from 1234 to 2987 enter: "AT+PSWD=2987"
To change HC-05 baud rate from default 9600 to 115200, 1 stop bit, 0 parity enter: "AT+UART=115200,1,0"

*/

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(13, 9);   // RX | TX pin on NodeMCU

void setup() 
{

  Serial.begin(9600);
  delay (2000);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);  // HC-05 default speed in AT 
                          // command mode
}

void loop()
{
  // Keep reading from HC-05 and send to Arduino 
  // Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor 
  //  and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}
