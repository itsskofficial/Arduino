const int led = 11;
const int totalStates = 10;

int ledState[totalStates] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
int ledDuration[totalStates] = {1000, 2000, 3000, 4000, 5000 ,6000, 7000, 8000, 9000, 10000};

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i < totalStates; i++) 
  {
    digitalWrite(led, ledState[i]);
    delay(ledDuration[i]);
  }
}
