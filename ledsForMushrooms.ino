/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int analogOutPin3 = 11;
int analogOutPin2 = 5;
int analogOutPin1 = 3;

const float pi = 3.14;
float timePeriod = 10;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600); 
  
  
  pinMode(analogOutPin1, OUTPUT);
  
}



void displayfunctionSM(float normalisedTime,int pin){
  Serial.println(normalisedTime);
  float displayvalue=sin((normalisedTime)*pi);
  
  analogWrite(pin, int(abs(displayvalue)*255.));
  
  
}
void displayfunctionS(float normalisedTime,int pin){
  Serial.println(normalisedTime);
  float displayvalue=sin((normalisedTime)*2*pi-pi/2.0)*0.5+0.5;
  
  analogWrite(pin, int(abs(displayvalue)*255.));
  
}
void displayfunctionSaw(float normalisedTime,int pin){
  Serial.println(normalisedTime);
  float displayvalue=normalisedTime;
  if (displayvalue > 0.5){displayvalue=(1.0-displayvalue)*2;}else{displayvalue*=2;}
  analogWrite(pin, int(abs(displayvalue)*255.));
  
}



// the loop routine runs over and over again forever:
void loop() {

  
  
  unsigned long runningtime=millis();
  Serial.println("loop");
  float localruntime=float(runningtime)/1000.0;
  float cycles=localruntime/timePeriod;
  float normalisedTime=cycles-int(cycles);

  
  displayfunctionSaw(normalisedTime,analogOutPin3);
  displayfunctionS(normalisedTime+0.5,analogOutPin2);
  displayfunctionSM(normalisedTime+0.3,analogOutPin1);
  
  delay(20); 
  
  
}
