#include <Servo.h>
#include <math.h>  

const int SERVO_PIN = 3;
const double PI_CONST = 3.14;

int dist = 0;
double baseDist = 150;
double currentDist;
double armLength = 5;
double regulatorP = 10;
double angle;
double time;
Servo servo;

double getDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
 
  time = pulseIn(echoPin, HIGH);
  return 0.01723 * time;
}

void setup()
{
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  servo.write(0);
}

void loop()
{
  currentDist = getDistance(7, 7) - baseDist;
  dist = int(currentDist / 10) * regulatorP;
  angle = atan(dist/armLength)*180/PI;
  Serial.println(angle);
  servo.write(regulatorP*angle);
}