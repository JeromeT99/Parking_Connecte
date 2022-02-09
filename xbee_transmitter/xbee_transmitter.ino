#include <SoftwareSerial.h>

SoftwareSerial xbee_transmit(0, 1);
SoftwareSerial bluetooth(4, 2);
int parking_1 = 7; 
int parking_1_full = LOW;

int parking_2 = 6; 
int parking_2_full = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(parking_1, INPUT);
  pinMode(parking_2, INPUT);
  Serial.begin(9600);
  xbee_transmit.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  
  parking_1_full = digitalRead(parking_1);
  parking_2_full = digitalRead(parking_2);

  if (parking_1_full == LOW && parking_2_full == HIGH) {
    bluetooth.write("1");
  }
  else if (parking_1_full == HIGH && parking_2_full == LOW) {
    bluetooth.write("2");
  }
  else if (parking_1_full == LOW && parking_2_full == LOW) {
    bluetooth.write("3");
  }
  else if (parking_1_full == HIGH && parking_2_full == HIGH) {
    bluetooth.write("4");
  }
    
  if (bluetooth.available() > 0) {
    char received = bluetooth.read();
    if (received == '1') {
      Serial.print('1');
    }
    else if (received == '2') { 
      Serial.print('2');
    }
    else if (received == '3') {
      Serial.print('3');
    }
    else if (received == '4') { 
      Serial.print('4');
    }
  }
  delay(1000);
}
