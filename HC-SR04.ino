// HC-SR04 Ultrasonic Sensor
#define trigPin 9
#define echoPin 10
#define buzzer 6

// Variables
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  // Trigger the ultrasonic sensor by sending a 10us pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time it takes for the ultrasonic pulse to return
  duration = pulseIn(echoPin, HIGH);

  // Convert the time to distance (in centimeters)
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100); // You can adjust the delay to control the measurement frequency
  if(distance<50)
  {
    digitalWrite(buzzer,LOW);
  }
  else{
    digitalWrite(buzzer,HIGH);
  }
}
