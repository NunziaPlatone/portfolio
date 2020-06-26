#include <Servo.h>

Servo myServo; // Declare a servo object for us to control
Servo myservo2;
int servoPin = 9; // Var for the pin the servo connects to
int servoPin2 = 10;
int pos = 0; // Var to keep track of the servo's position
int pos2 = 0;

int amount = 0;
int numbottleend = 0;


int buttonPin = 3;
int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  
  myServo.attach(servoPin); // Tell the servo to what pin it's connected to
  myservo2.attach(servoPin2);

  
  Serial.begin(9600);
}
void loop() {
  pos = 0;
  pos2 = 0;
  int motorchoose = 0;
  myServo.write(pos);
  myservo2.write(pos2);
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  
  if(buttonState){
    int numbottleend= rand() % 360 + 1;
  
   
    if(numbottleend > 180){
      amount = (numbottleend - 100) / 2;
      motorchoose = 1;
     }else{
      amount = numbottleend; 
     }
     
    delay(15);
    for(pos = 0; pos < 180; pos += 1){ // Loop, pos is added to (from 0 to 160)
      if(motorchoose != 1){
        if(pos == amount){   
          Serial.println(pos);
          delay(3000);
          break;
        }else{
          myServo.write(pos);
         }
       }else{
        myServo.write(pos); // Turn the servo to the position in pos 
       }
       
      
      delay(50);
    }
    for(pos2 = 0; pos2 < 180; pos2 += 1){ // Loop, pos is added to (from 0 to 160)
      if(motorchoose == 1){
        if(pos2 == amount){   
          Serial.println(pos2);
          delay(3000);
          break;
        }else{
            myservo2.write(pos2); // Turn the servo to the position in pos
            delay(50);
        }
      }else{
        break;
      }
      
    }
 }
  
   
   
 
}
