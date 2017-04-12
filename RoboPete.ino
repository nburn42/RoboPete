/* RoboPete dance 

  This program makes robo pete dance.
  See the wiring diagram to see how to set up the wires.
  
  The code here is run one line at a time from top to bottom in the functions.
  The functions look like this.
  
  void my_function () {
    my code;
  }
  
  The part where robo pete dances is in the "loop" function.
  If you want to change the dance, just change the lines in there.
  
  If you want to learn even more about programming,
  check out the tutorials on adafruit.com

*/

// Which pins are the wires plugged in?
int right_backward = 11;
int right_forward = 10;
int left_backward = 9;
int left_forward = 8;

// The setup routine runs once when you press reset.     //
// You don't need to change this one to change the dance //
void setup() {                
  // Turn the pins to output mode
  pinMode(right_backward, OUTPUT);
  pinMode(right_forward, OUTPUT);
  pinMode(left_forward, OUTPUT);
  pinMode(left_backward, OUTPUT); 
}

// The loop routine runs over and over again forever. //
void loop() {

  //// Move forward, back then stop. ////
  
  int dance_time = random(0, 1000);   // Choose a random dance times from 0 to 1 second.
  
  turn_left_wheel_forward();      // Set the left wheel to forward mode.
  turn_right_wheel_forward();     // Set the right wheel to forward mode.
  delay(dance_time);              // Wait while we drive forward.
  
  turn_left_wheel_backward();     
  turn_right_wheel_backward();
  delay(dance_time);               
  
  stop_left_wheel();
  stop_right_wheel();
  delay(1000);                     // wait for a second (1000 miliseconds)
  
  
  
  //// Turn right, then turn back ////
  
  dance_time = random(0, 1000);
  
  turn_left_wheel_forward();
  stop_right_wheel();
  delay(dance_time);               
  
  turn_left_wheel_backward();
  stop_right_wheel();
  delay(dance_time);               
  
  stop_left_wheel();
  stop_right_wheel();
  delay(1000);               
  
  
  
  //// Spin right, then spin back ////
  
  dance_time = random(0, 1000);
  
  turn_left_wheel_backward();
  turn_right_wheel_forward();
  delay(dance_time);               
  
  turn_left_wheel_forward();
  turn_right_wheel_backward();
  delay(dance_time);               
  
  stop_left_wheel();
  stop_right_wheel();
  delay(1000);               
  
  // Go back to the top of loop and do it again!
}



//// These functions change the electrical signals to move robo pete. ////
//// You don't need to change these.                                  ////

void turn_left_wheel_forward() {
  digitalWrite(left_forward, HIGH);
  digitalWrite(left_backward, LOW);
}

void turn_left_wheel_backward() {
  digitalWrite(left_forward, LOW);
  digitalWrite(left_backward, HIGH);
}

void stop_left_wheel() {
  digitalWrite(left_forward, LOW);
  digitalWrite(left_backward, LOW);
}

void turn_right_wheel_forward() {
  digitalWrite(right_forward, HIGH);
  digitalWrite(right_backward, LOW);
}

void turn_right_wheel_backward() {
  digitalWrite(right_forward, LOW);
  digitalWrite(right_backward, HIGH);
}

void stop_right_wheel() {
  digitalWrite(right_forward, LOW);
  digitalWrite(right_backward, LOW);
}
