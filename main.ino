#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(10, 9);

void setup() {
  Bluetooth.begin(9600);
}

void control(long leftBack, long leftFront, long rightBack, long rightFront)
{
  digitalWrite(2, leftBack);
  digitalWrite(3, leftFront);
  digitalWrite(4, rightBack);
  digitalWrite(5, rightFront);
}

void loop() {
  if (Bluetooth.available()) {
    switch (Bluetooth.read()) {
      case 'W': control(LOW, HIGH, LOW, HIGH); break;
      case 'E': control(HIGH, LOW, HIGH, LOW); break;
      case 'S': control(HIGH, LOW, LOW, HIGH); break;
      case 'N': control(LOW, HIGH, HIGH, LOW); break;
      default: control(LOW, LOW, LOW, LOW); break;
    }
  }
}
