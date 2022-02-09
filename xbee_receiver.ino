#include <SoftwareSerial.h>

SoftwareSerial xbee(0, 1);

int led_p1 = 4;
int led_p2 = 2;

int parking_1 = 7; 
int parking_1_full = LOW;

int parking_2 = 6; 
int parking_2_full = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xbee.begin(9600);
  pinMode(parking_1, INPUT);
  pinMode(parking_2, INPUT);
  pinMode(led_p1, OUTPUT);
  pinMode(led_p2, OUTPUT);
}

void loop() {
  
  parking_1_full = digitalRead(parking_1);
  parking_2_full = digitalRead(parking_2);

  if (parking_1_full == LOW && parking_2_full == HIGH) {
      Serial.print('1');
  }
  else if (parking_1_full == HIGH && parking_2_full == LOW) {
      Serial.print('2');
  }
  else if (parking_1_full == LOW && parking_2_full == LOW) {
      Serial.print('3');
  }
  else if (parking_1_full == HIGH && parking_2_full == HIGH) {
      Serial.print('4');
  }
  
  if (xbee.available()) {
    char received = xbee.read();
    if (received == '1') {
      digitalWrite(led_p1, HIGH);
      digitalWrite(led_p2, LOW);
      delay(10);
    }
    else if (received == '2') {
      digitalWrite(led_p1, LOW);
      digitalWrite(led_p2, HIGH);
      delay(10);
    }
    else if (received == '3') {
      digitalWrite(led_p2, HIGH);
      digitalWrite(led_p1, HIGH);
      delay(10);
    }
    else if (received == '4') {
      digitalWrite(led_p1, LOW);
      digitalWrite(led_p2, LOW);
      delay(10);
    }
  }
}
