//Code for the QRE1113 Digital board
//Outputs via the serial terminal – Lower numbers mean more reflected
//3000 or more means nothing was reflected.

const int LINE_SENSOR_PIN = 9;
const long CUTOFF_TIME = 3000;

void setup(){
  Serial.begin(9600);
}


void loop() {
  int val = readQD();
  if (1000 < val && val < 2000) {
    Serial.println(val);
  }
}

int readQD(){

  pinMode(LINE_SENSOR_PIN, OUTPUT);
  digitalWrite(LINE_SENSOR_PIN, HIGH);
  delayMicroseconds(10);
  pinMode(LINE_SENSOR_PIN, INPUT);
  
  long initialTime = micros();
  //time how long the input is HIGH, but quit after 3ms as nothing happens after that
  while (!hasDissipated(LINE_SENSOR_PIN) && micros() - initialTime < CUTOFF_TIME);
  int diff = micros() - initialTime;
  return diff;
}

bool hasDissipated(int pin) {
  return digitalRead(pin) == LOW;
}
