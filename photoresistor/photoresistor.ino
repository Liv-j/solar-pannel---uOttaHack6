#include <Servo.h>

//setting baseline + attaching + recording
Servo servo1;  
int currentAngle = 90;
const int MOVE_ANGLE =15;

void setup() {
    servo1.attach(9);
    Serial.begin(9600);
    
}

//loops indefinetly so it's always checking for the side with the most amount of light
void loop() {
   //captures values of the photoresistors
    int topValue = analogRead(A0);
    int bottomValue = analogRead(A4);
   //debug prints to compare
    Serial.println("Analog  Value: ");
    Serial.println(topValue);
    Serial.println(", ");
    Serial.println(bottomValue);
    
    //moving towards the bottom photoresistors side if detect more light
    if (bottomValue - topValue > 20){
        Serial.println("move 5 top");
        if(currentAngle - MOVE_ANGLE >= 0){
          Serial.println("move 5 ");
          currentAngle = currentAngle - MOVE_ANGLE;
          Serial.println(currentAngle);
          servo1.write(currentAngle); }

    //moving towards the bottom photoresistors side if detect more light
    } else if (topValue - bottomValue > 20) {
        Serial.println("move 5 bottom");
        if(currentAngle + MOVE_ANGLE <= 180){
          Serial.println("move 5 ");
          currentAngle = currentAngle + MOVE_ANGLE;
          Serial.println(currentAngle);
          servo1.write(currentAngle);}
    } 
     //servo can take a chill pill....for now....
    else {
         Serial.println("chill");
    }
    delay(100);
}
