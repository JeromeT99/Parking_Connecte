#include <SoftwareSerial.h>

SoftwareSerial xbee(0, 1);

int led_p1 = 4;
int led_p2 = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xbee.begin(9600);
  pinMode(led_p1, OUTPUT);
  pinMode(led_p2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
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
