 #include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
int x,y;
int count = 0;
float cal;
float distance;
void setup() {
  mySerial.begin(9600);

}

void loop() {
  x =analogRead(A0);
  y = analogRead(A1);
  if(x<=390 || y>=540){ //threhold
    count++;
    delay(200);
  }
  if(x>=540 || y <= 390){ //threhold
    count++;
    delay(200);
  }
  cal = count *0.049; // calorie burn for people around 82kg & 6 feet
  distance = count * 0.0005; //half meter per step
  mySerial.print(x); //print value to monbile app
  mySerial.print(",");
  mySerial.print(y);
  mySerial.print(",");
  mySerial.print(count);
  mySerial.print(",");
  mySerial.print(cal);
  mySerial.print(",");
  mySerial.print(distance);
  mySerial.print(";");
  delay(200);
  Serial.print(count);
}
