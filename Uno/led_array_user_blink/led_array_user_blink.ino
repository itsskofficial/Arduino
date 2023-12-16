const int led = 11;
const int totalStates = 10;

int ledState[totalStates];
int ledDuration[totalStates] = {1000, 2000, 3000, 4000, 5000 ,6000, 7000, 8000, 9000, 10000};

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  while (!Serial)
  {
    ;
  }

  for (int i=0; i < totalStates; i++)
  {
    Serial.print("Please type 1 or 0 for LED state. This is step ");
    Serial.print(i + 1);
    Serial.print(" out of ");
    Serial.print(totalStates);
    Serial.print(". The default is 1");

    while (Serial.available()==0)
    {
    }

    char userInput = Serial.read();
    if (userInput == '1')
    {
      ledState[i] = 1;
    }
    else if (userInput == '0')
    {
      ledState[i] = 0;
    }
    else
    {
      ledState[i] = 1;
    }

    Serial.println(ledState[i]);
  }

  Serial.println("Great, now lets blink this LED");
  for (int i=0; i < totalStates; i++)
  {
    Serial.print("Step: ");
    Serial.println(i+1);
    Serial.print("State is ");
    Serial.print(ledState[i]);
    Serial.print(" for duration of ");
    Serial.print(ledDuration[i]);
    Serial.println(" milliseconds");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i < totalStates; i++) 
  {
    digitalWrite(led, ledState[i]);
    delay(ledDuration[i]);
  }
}
