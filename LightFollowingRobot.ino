#define IN1 2  //IN1 on pin 2 conrtols one side of bridge A
#define IN2 4  //IN2 on pin 4 controls other side of A
#define IN3 6  //IN3 on pin 6 conrtols one side of bridge B
#define IN4 7  //IN4 on pin 7 controls other side of B

//Assign digital pins A0,A2 to Right sensor and Left sensor respectively.
const int SENSORr = A0;
const int SENSORl = A2;

int LeftSensor = 0;
int RightSensor = 0;
int SENSORDIFFERENCE = 0;

void setup(){
Serial.begin(9600); //Start Serial data communication 
}

void loop() {                     // Run continuous Loop
LeftSensor= analogRead(SENSORl); //Read from Left SENSOR
RightSensor= analogRead(SENSORr); //Read from right SENSOR
SENSORDIFFERENCE = abs(LeftSensor - RightSensor);

Serial.println("Left Sensor");
Serial.println(LeftSensor);

Serial.println("Right Sensor ");
Serial.println(RightSensor);


if (LeftSensor > RightSensor && SENSORDIFFERENCE >75) {            //Turns Left as Right sensor detects white line )
Serial.println("RightTurn");
TurnLeft();
}

if (LeftSensor < RightSensor && SENSORDIFFERENCE > 75) { //Turns Right as left sensor detects white line )
Serial.println("LeftTurn");
TurnRight();
}
else if (SENSORDIFFERENCE <75){
Serial.println("Forward");
Forward();
}
}

//Moves the bot forward
void Forward(){  
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW );
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW );
}
//Turns the bot right
void TurnRight(){
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW );
}

//Turns the bot left
void TurnLeft(){
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW );
}
