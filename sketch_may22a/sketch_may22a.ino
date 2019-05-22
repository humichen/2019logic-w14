int ledCount = 10;
int ledPins[]={2,3,4,5,6,7,8,9,10,11};
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for (int thisLed = 0; thisLed < ledCount; thisLed++) {
  pinMode(ledPins[thisLed], OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
int aRead=analogRead(A1);
Serial.println(aRead);
if(aRead<143){aRead=143;}
else if(aRead>488){aRead=488;}
int ledlevel=map(aRead,0,143,488,ledCount);

for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // if the array element's index is less than ledLevel,
    // turn the pin for this element on:
    if (thisLed < ledlevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    }
    // turn off all pins higher than the ledLevel:
   else {
     digitalWrite(ledPins[thisLed], LOW);
  }
 }
delay(10);
}
