#define topSensorPinH 2
#define topSensorPinV 3
#define middleSensorPinH 4
#define middleSensorPinV 5
#define bottomSensorPinH 6
#define bottomSensorPinV 7

#define topRelay 8
#define middleRelay 9
#define bottomRelay 10

#define cyan 1
#define magenta 0

int topSensorStateH = 0;
int topSensorStateV = 0;
int middleSensorStateH = 0;
int middleSensorStateV = 0;
int bottomSensorStateH = 0;
int bottomSensorStateV = 0;

void setup() {
  
  pinMode(topSensorPinH, INPUT);
  pinMode(topSensorPinV, INPUT);

  pinMode(middleSensorPinH, INPUT);
  pinMode(middleSensorPinV, INPUT);

  pinMode(bottomSensorPinH, INPUT);
  pinMode(bottomSensorPinV, INPUT);

  digitalWrite(topSensorPinH, HIGH);
  digitalWrite(topSensorPinV, HIGH);
  
  digitalWrite(middleSensorPinH, HIGH);
  digitalWrite(middleSensorPinV, HIGH);
  digitalWrite(bottomSensorPinH, HIGH);
  digitalWrite(bottomSensorPinV, HIGH);

  pinMode(topRelay, OUTPUT);
  pinMode(middleRelay, OUTPUT);
  pinMode(bottomRelay, OUTPUT);
  digitalWrite(topRelay, cyan);
  digitalWrite(middleRelay, cyan);
  digitalWrite(bottomRelay, cyan);
  
  Serial.begin(9600);
  delay(1000);
}

void loop(){
  topSensorStateH = digitalRead(topSensorPinH);
  topSensorStateV = digitalRead(topSensorPinV);
  middleSensorStateH = digitalRead(middleSensorPinH);
  middleSensorStateV = digitalRead(middleSensorPinV);
  bottomSensorStateH = digitalRead(bottomSensorPinH);
  bottomSensorStateV = digitalRead(bottomSensorPinV);

  if (topSensorStateH == LOW || topSensorStateV == LOW) {
    digitalWrite(topRelay, cyan);
    //delay(3000);
  } else {
    digitalWrite(topRelay, magenta);
  }

  if (middleSensorStateH == LOW || middleSensorStateV == LOW) {
    digitalWrite(middleRelay, cyan);
    //delay(3000);
  } else {
    digitalWrite(middleRelay, magenta);
  }

  if (bottomSensorStateH == LOW || bottomSensorStateV == LOW) {
    digitalWrite(bottomRelay, cyan);
    //delay(3000);
  } else {
    digitalWrite(bottomRelay, magenta);
  }
}