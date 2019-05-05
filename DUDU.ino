//Define Pins
//Motor A
int enableA = 5;
int MotorA1 = 6;
int MotorA2 = 7;

//Motor B
int enableB = 8;
int MotorB1 = 9;
int MotorB2 = 10;

//IR Receiver
#include <IRremote.h>
const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {

  Serial.begin (9600);

  //IR
  irrecv.enableIRIn();
  irrecv.blink13(true);

  //configure pin modes
  pinMode (enableA, OUTPUT);
  pinMode (MotorA1, OUTPUT);
  pinMode (MotorA2, OUTPUT);

  pinMode (enableB, OUTPUT);
  pinMode (MotorB1, OUTPUT);
  pinMode (MotorB2, OUTPUT);

  Serial.println("HaHa"); 
}

void loop() {
  /*
    //enabling motor A
    Serial.println ("Enabling Motors");
    digitalWrite (enableA, HIGH);
    digitalWrite (enableB, HIGH);
    delay (1000);
    //do something

    Serial.println ("Motion Forward");
    digitalWrite (MotorA1, LOW);
    digitalWrite (MotorA2, HIGH);

    digitalWrite (MotorB1, LOW);
    digitalWrite (MotorB2, HIGH);

    //3s forward
    delay (3000);

    Serial.println ("Motion Backwards");
    //reverse
    digitalWrite (MotorA1,HIGH);
    digitalWrite (MotorA2,LOW);

    digitalWrite (MotorB1,HIGH);
    digitalWrite (MotorB2,LOW);

    //5s backwards
    delay (3000);

    Serial.println ("Stoping motors");
    //stop
    digitalWrite (enableA, LOW);
    digitalWrite (enableB, LOW);
    delay (3000);
  */
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    //up arrow
    if (results.value == 0x40BE12ED) {
      Serial.println ("Motion Forward");
      digitalWrite (MotorA1, LOW);
      digitalWrite (MotorA2, HIGH);

      digitalWrite (MotorB1, LOW);
      digitalWrite (MotorB2, HIGH);

      digitalWrite (enableA, HIGH);
      digitalWrite (enableB, HIGH);
      delay(500);
      digitalWrite (enableA, LOW);
      digitalWrite (enableB, LOW);
    }

      //down arrow
      if (results.value == 0x40BEB24D) {
        Serial.println ("Motion Backward");
        digitalWrite (MotorA1, HIGH);
        digitalWrite (MotorA2, LOW);

        digitalWrite (MotorB1, HIGH);
        digitalWrite (MotorB2, LOW);

        digitalWrite (enableA, HIGH);
        digitalWrite (enableB, HIGH);
        delay(500);
        digitalWrite (enableA, LOW);
        digitalWrite (enableB, LOW);
      }
      
      //left
      if (results.value == 0x40BE728D) {
        Serial.println ("Motion Left");
        digitalWrite (MotorA1, HIGH);
        digitalWrite (MotorA2, LOW);

        digitalWrite (MotorB1, LOW);
        digitalWrite (MotorB2, HIGH);

        digitalWrite (enableA, HIGH);
        digitalWrite (enableB, HIGH);
        delay(500);
        digitalWrite (enableA, LOW);
        digitalWrite (enableB, LOW);
    
      }
      //right
      if (results.value == 0x40BE926D) {
        Serial.println ("Motion Right");
        digitalWrite (MotorA1, LOW);
        digitalWrite (MotorA2, HIGH);

        digitalWrite (MotorB1, HIGH);
        digitalWrite (MotorB2, LOW);

        digitalWrite (enableA, HIGH);
        digitalWrite (enableB, HIGH);
        delay(500);
        digitalWrite (enableA, LOW);
        digitalWrite (enableB, LOW);
    
      }


      irrecv.resume();
    }
}
