const int led = 9;
const int sensor_pin = A0;
int sensor;
const int threshold = 500;

void setup (){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor_pin, INPUT);
}

void loop(){
  sensor = analogRead(sensor_pin);
  if(sensor>threshold){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  delay(10);
}