const int red_pin = 10;
const int green_pin = 9;
const int blue_pin = 8;
const int water_pin = A0;

const int sensor_max = 600;
const int sensor_min = 480;
int sensor_diff = 0;

float level = 0;
int red = 0;
int green = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  sensor_diff = sensor_max - sensor_min;
  Serial.begin(9600);
  pinMode(4,INPUT);
  digitalWrite(12,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  level = analogRead(A0);
  level = level - sensor_min;
  if(level < 0) level = 0;
  else if(level > sensor_diff) level = sensor_diff;
  level = level / sensor_diff * 100;
  red = 255 - ((level - 50) * 5.1);
  if (red > 255) red = 255;
  green = level * 64 / 100;
  setColor(red,green,0);

//joystick
  Serial.print(analogRead(A2));
  Serial.print(" ");
  Serial.print(analogRead(A3));
  Serial.print(" ");
  Serial.println(digitalRead(12));
  delay(100);
}


void setColor(int red, int green, int blue)
{
  analogWrite(red_pin, red);
  analogWrite(green_pin, green);
  analogWrite(blue_pin, blue);  
}
