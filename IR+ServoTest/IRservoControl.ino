#include <IRLibAll.h>
#include <Servo.h>

// You will have to set these values depending on the protocol
// and remote codes that you are using. These are For the Adafruit
// Mini Remote
#define MY_PROTOCOL NEC
#define RIGHT_ARROW   0xfd50af //Move servo clockwise
#define LEFT_ARROW    0xfd10ef //Move servo counterclockwise
#define SELECT_BUTTON 0xfd906f //Center the servo(s)
#define UP_ARROW      0xfda05f //Move vertical servo up
#define DOWN_ARROW    0xfdb04f //Move vertical servo down
#define BUTTON_0 0xfd30cf  //Decrease the step size per movement(degrees per move)
#define BUTTON_1 0xfd08f7  //Increase the step size per movement(degrees per move)
#define BUTTON_2 0xfd8877  //Pushing buttons 2-9 moves to fixed positions
#define BUTTON_3 0xfd48b7
#define BUTTON_4 0xfd28d7
#define BUTTON_5 0xfda857
#define BUTTON_6 0xfd6897
#define BUTTON_7 0xfd18e7
#define BUTTON_8 0xfd9867
#define BUTTON_9 0xfd58a7

IRrecv myReceiver(2); //pin number for the receiver
IRdecode myDecoder;

Servo myServo1;  // create servo object to control a servo
Servo myServo2;
int16_t pos1;         // variable to store the servo position
int16_t pos2;
int16_t Speed;       // Number of degrees to move each time a left/right button is pressed
uint32_t Previous;//handles NEC repeat codes

void setup() {
  myServo.attach(9);      // attaches the servo on pin 9 to the servo object
  pos1 = 90;               // start at midpoint 90 degrees
  pos2 = 90;
  Speed = 3;              // servo moves 3 degrees each time left/right is pushed
  myServo.write(pos);     // Set initial position
  myReceiver.enableIRIn(); // Start the receiver
}

void loop()
{
    if (myReceiver.getResults()) {
       myDecoder.decode();
       if(myDecoder.protocolNum==MY_PROTOCOL) {
         if(myDecoder.value==0xFFFFFFFF)
           myDecoder.value=Previous;
         switch(myDecoder.value) {
            case LEFT_ARROW:    pos1=min(180,pos+Speed); break;
            case RIGHT_ARROW:   pos1=max(0,pos-Speed); break;
            case SELECT_BUTTON: pos=90; break;
            case UP_ARROW:      pos2=min(180,pos+Speed); break;
            case DOWN_ARROW:    pos2=max(0,pos-Speed); break;
            case BUTTON_0:      Speed=min(10, Speed+1); break;
            case BUTTON_1:      Speed=max(1, Speed-1); break;
            case BUTTON_2:      pos=2*20; break;
            case BUTTON_3:      pos=3*20; break;
            case BUTTON_4:      pos=4*20; break;
            case BUTTON_5:      pos=5*20; break;
            case BUTTON_6:      pos=6*20; break;
            case BUTTON_7:      pos=7*20; break;
            case BUTTON_8:      pos=8*20; break;
            case BUTTON_9:      pos=9*20; break;
         }
         myServo1.write(pos1); // tell servo to go to position in variable 'pos'
         myServo2.write(pos2);
         Previous=myDecoder.value;
       }
       myReceiver.enableIRIn();
    }
}
