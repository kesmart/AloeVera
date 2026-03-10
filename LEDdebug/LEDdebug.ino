const int pumpPin = 26;
const int grPin = 32;
const int rPin = 33;
int message = 0;

void setup() {
  Serial.begin(115200);
  pinMode(pumpPin, OUTPUT);
  pinMode(grPin, OUTPUT);
  pinMode(rPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
  digitalWrite(grPin, HIGH);
  digitalWrite(rPin, HIGH);
  Serial.print("Set to high");

}

void loop() {
  if (Serial.available() > 0) {
    // Read the incoming byte:
    message = Serial.read();
    Serial.println(message);

    if (message == 49) {
      Serial.println("on");
      digitalWrite(pumpPin, HIGH);
      digitalWrite(grPin, LOW);
    }

    if (message == 50) {
      digitalWrite(pumpPin, LOW);
      digitalWrite(grPin, HIGH);
      Serial.println("off");
    }
  }
}
