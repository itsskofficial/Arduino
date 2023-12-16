#define RED 3
#define BLUE 6
#define GREEN 9

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED, HIGH);
  digitalWrite(BLUE, HIGH);
  delay(1000);
  digitalWrite(BLUE, LOW)
  digitalWrite(GREEN, HIGH);
  delay(1000);
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, HIGH);
  delay(1000);
  digitalWrite(RED, HIGH);
}
