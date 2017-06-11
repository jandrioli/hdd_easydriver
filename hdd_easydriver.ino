int dirpin = 8;
int steppin = 9;

void setup() {
  Serial.begin(115200);

  pinMode(dirpin, OUTPUT);
  pinMode(steppin, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{

  int i;
    digitalWrite(13,LOW);
    delay(10);

  digitalWrite(dirpin, LOW);     // Set the direction.
  delay(100);

  Serial.println(">>");
  for (i = 0; i<500; i++)       // Iterate for 4000 microsteps.
  {
    /*digitalWrite(13, HIGH);
    delay(10);
    digitalWrite(13,LOW);
    delay(10);*/
    digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
    delayMicroseconds(300);    
    digitalWrite(steppin, HIGH); // "Rising Edge" so the easydriver knows to when to step.
    delayMicroseconds(3000);      // This delay time is close to top speed for this
  }                              // particular motor. Any faster the motor stalls.
  

  digitalWrite(dirpin, HIGH);    // Change direction.
  delay(100);

  Serial.println("<<");
  for (i = 0; i<500; i++)       // Iterate for 4000 microsteps
  {
    digitalWrite(steppin, LOW);  // This LOW to HIGH change is what creates the
    delayMicroseconds(300);      // This delay time is close to top speed for this
    digitalWrite(steppin, HIGH); // "Rising Edge" so the easydriver knows to when to step.
    delayMicroseconds(3000);      // This delay time is close to top speed for this
  }                              // particular motor. Any faster the motor stalls.
delay(3000);
}
