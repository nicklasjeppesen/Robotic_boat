#include <Servo.h>

// servo range: 0-1023
Servo ServoLeft; 
Servo ServoRight; 

int servoPin_left = 9;

void ServoSetup() {
  ServoLeft.write(90);  // Stop, 
}

void MethodforLeftControl(void) {
  Serial.println("called command left, godt gået Nicklas version 2.0");
   ServoLeft.write(90); 
}

void MethodforRightControl(void) {
  Serial.println("called command Right Godt gået Nicklas");
  ServoLeft.write(130); // 91-180, where 180 is full speed forward, 0 is full speed backward. 
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // Setup Servo; 
  ServoLeft.attach(servoPin_left, 1000, 2000);
  ServoSetup();

  SetActionCommandLeft(MethodforLeftControl); // register method for pushing down button. 
  SetActionCommandRight(MethodforRightControl); 

  ReceiverSetup(); // Execute setup for remoteController; 


}

void loop() {
  // put your main code here, to run repeatedly:
    
    RecevierLoop(); // Run recevier function. 
}
