// The time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 15;        

// The time when the sensor outputs a low impulse
long unsigned int lowIn;         

// The amount of milliseconds the sensor has to be low 
// before we assume all motion has stopped
long unsigned int pauseTime = 5000;  

boolean lockLow = true;
boolean takeLowTime;  

int pirPin = 4;    // The digital pin connected to the PIR sensor's output
int ledPin = 13;   // LED pin
int buzzerPin = 7; // Buzzer pin

/////////////////////////////
// SETUP
void setup(){
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

/////////////////////////////
// LOOP
void loop(){
  if (digitalRead(pirPin) == HIGH) {  
    Serial.println("Motion Detected!");
    digitalWrite(ledPin, HIGH);   // Turn on LED
    digitalWrite(buzzerPin, HIGH); // Turn on Buzzer
    delay(2000);  // Keep LED and buzzer ON for 2 seconds
  } else {
    digitalWrite(ledPin, LOW);    // Turn off LED
    digitalWrite(buzzerPin, LOW); // Turn off Buzzer
  }
}
