#include <SoftwareSerial.h>

SoftwareSerial xbee_transmit(0, 1);
SoftwareSerial bluetooth(4, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xbee_transmit.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
    
  if (xbee.available()) {
    char received = xbee.read();
    if (received == '1') {
      bluetooth.write("1");
    }
      bluetooth.write("2");
    }
    else if (received == '3') {
      bluetooth.write("3");
    }
    else if (received == '4') { 
      bluetooth.write("4");
    }
  }
  delay(1000);
}
