
// Define names for the pins.
#define SENSOR_PIN A0
#define IN1_PIN 2
#define IN2_PIN 3
#define ENA_PIN 4
#define BUTTON_PIN 53

int analogValue;  // Value of the potentiometer.
bool state;       // Flag to represnt the direction of rotation.

void setup() {
  Serial.begin(9600);  // Start serial communication between the board and the computer.

  // Configuration of the digital pins. 
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(ENA_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Definition of the initial direction.
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  state = true; // This direction is identified by state = true.
}

void loop() {
  analogValue = analogRead(SENSOR_PIN);              // Reads the value of the potentiometer.
  int velocity = map(analogValue, 0, 1023, 0, 255);  // Converts the value of the potentiometer.

  // Write in the serial monitor, the values of the potentiometer and the velocity. 
  Serial.print(analogValue);
  Serial.print(" ");
  Serial.println(velocity);
  
  //Serial.println(digitalRead(BUTTON_PIN));

  // If the button is pressed, inverte the state to change the direction of rotation. 
  if(digitalRead(BUTTON_PIN) == LOW) {
    state = !state;
    while(digitalRead(BUTTON_PIN) == LOW);
    delay(300);
  }

  // Choose the direction of rotation according to the state value.
  if(state == true) {
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, HIGH);
  }
  else {
    digitalWrite(IN1_PIN, HIGH);
    digitalWrite(IN2_PIN, LOW);
  }

  // Set the velocity.
  analogWrite(ENA_PIN, velocity);
    
  delay(100);
}
