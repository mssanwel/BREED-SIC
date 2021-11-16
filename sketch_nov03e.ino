//encoder - measure howm much it moved

#include <Servo.h>

#define PIN_PMETER          A5    // PIN Potentiometer
#define PIN_PUSHERESC       6     // PIN to control ESC, normally the white wire from ESC 
#define PIN_BTN             7     // PIN for button to On/Off reading from Potentiometer

/*///////////////////////////////////////////////////////////////////////////////////////////////////////
 * The following are the setting for the ESC used, for other ESC, just chnage setting according to
 * ESC Spec
 *///////////////////////////////////////////////////////////////////////////////////////////////////////
#define THROTTLE_MIN        1500
#define THROTTLE_MAX        2000
#define THROTTLE_BRAKE       1000
// End of ESC setting ///////////////////////////////////////////////////////////////////////////////////

int     throttle      = THROTTLE_MIN; // default throttle
boolean startReading  = false;        // default to not reading 

Servo   pusherESC;                    


void setup() {
  Serial.begin(9600);
  Serial.println("Started Setup........");
  
  pusherESC.attach(PIN_PUSHERESC);
  pusherESC.writeMicroseconds(THROTTLE_MIN);
  Serial.println("Arming........");   // just some display message 
  delay(2000);
  Serial.println("Arming........After delay");  

  // when running arduino without computer, after seeing the onboard LED goes on and then off
  // I will know the setup had completed and the arduino is now in the loop 
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
   pusherESC.writeMicroseconds(THROTTLE_MIN);
   delay(2000);
   pusherESC.writeMicroseconds(THROTTLE_MAX); // brake DC brushed motor
   delay(2000);
   //pusherESC.writeMicroseconds(THROTTLE_BRAKE); // brake DC brushed motor
   delay(100);  
}
