const int ledPin = 9;      // the pin that the LED is attached to
void turn_on(int ledPin, int powerlevel);
void turn_off(int ledPin);

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  pinMode(ledPin, OUTPUT);
}

void turn_on(int ledPin, int powerlevel)
{
    analogWrite(ledPin, powerlevel);
    delay(1000);
}

void turn_off(int ledPin)
{
    analogWrite(ledPin, 0);
}

void loop() 
{
  int i;
  int powerlevel;
  String stringOne = " ";
  // check if data has been sent from the computer:
  if (Serial.available()) {
    // read the most recent byte (which will be from 0 to 255):
    stringOne =  Serial.readString();
    powerlevel = stringOne.toInt();
    // set the power level of the LED:
    for(i = 0; i <10; i++){
      turn_on(ledPin, powerlevel);
      turn_off(ledPin);
    delay(1000);
    }
  }
}
