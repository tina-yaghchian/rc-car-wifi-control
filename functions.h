// NOTE: There will be a commented * beside the lines you'll need to modify, or where you need to add your new code

// **************************** PIN AND VARIABLE DEFINITIONS **************************** //
// --------------------------- TODO #1: DEFINE PINS ON MOTOR DRIVER ---------------------------
// We know our D1 Mini Pro sends our motor driver instructions. This is done by connecting the pins on the D1 Mini Pro with the pins on the motor driver.
// Replace the D0s below with the names of the pins on the D1 Mini Pro that we want our motor driver to receive signals from. 
// For example, MOTOR_IN1 on the motor driver is connected to D1 on the D1 Mini Pro, so we would replace 'D0' with 'D1'.

#define MOTOR_IN1 D1 // Done as an example
#define MOTOR_IN2 D2 // * 
#define EN_PIN D5 // *
#define SERVO_PIN D8 // *


// --------------------------- TODO #2: RENAME SSID AND PASSWORD ---------------------------
// Rename the default wifi network name and password (the part inside the quotations) with your team name and custom password.
// Note: make sure the password is at least 8 characters long.
// You'll need to reconnect to the WiFi again after this.
const char *ssid = "cappuccino_assassino"; // *
const char *password = "cappuccina_ballerina"; // *


// **************************** FUNCTION FOR FORWARD AND BACKWARD MOTIONS **************************** //
void run_motor(int y){
  // FORWARD MOTION
  if (y < 0){ 
    y = abs(y);
    y = map(y, 0, 200, 102, 255);
    analogWrite(EN_PIN, y);
    // Below, we set the pin values to the table values for forward motion
    digitalWrite(MOTOR_IN1, HIGH); 
    digitalWrite(MOTOR_IN2, LOW);
  } 
  // REVERSE MOTION
  else if (y > 0) { 
    y = map(y, 0, 200, 102, 255);
    analogWrite(EN_PIN, abs(y));
  // Here, set the pin values to the table values for reverse motion
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
  }
  // STATIONARY
  else if (y == 0){
  // Do the same thing here, setting the pin values as seen for stationary 
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
  }
}

// **************************** FUNCTION FOR TURNING MOTIONS **************************** //
void steer(int x){
  //  --------------------------- TODO #7: CONVERT THE X COORDINATE FROM THE JOYSTICK INTO DEGREES FOR THE CAR TO TURN ---------------------------
  // This function receives a value x, which represents the x coordinate we received from our joystick. As you can see from the joystick's minimum and maximum values, x is a number between -200 and 200.
  // We want to write code that will turn the x-coordinate we receive into the number of degrees we want our car to turn. This will be a number between 0 to 180. 
  // The syntax to do this is x = map(x, lower range 1, upper range 1, lower range 2, upper range 2)
  // Where lower range 1 and upper range 1 are the bounds of the original range we want to switch from
  // And lower range 2 and upper range 2 are the bounds of the new range we want to switch to

  // replace the zeroes with the correct values
  x = map(x, -200, 200, 0, 180); // *

  // Write the new value for number of degrees we calculated to the servo motor 
  steering_servo.write(x);
}
