#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

int pwmpin = 9; //Sets digital pin 9 as the pwm pin

Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

void setup() {
  Serial.begin(9600);
  Serial.println("This is a test!");
  pinMode(pwmpin, OUTPUT); //Sets pwmpin as output

  pwm1.begin();
  pwm1.setPWMFreq(1600);  // This is the maximum PWM frequency
 
  pwm2.begin();
  pwm2.setPWMFreq(1600);  // This is the maximum PWM frequency

  Wire.setClock(400000);

  for (int k=0; k<=3;k++){
    pwm1.setPWM(k,4096,0);
    delay(10);
  }
  for (int m=0; m<=3; m++){
    pwm2.setPWM(m,4096,0);
    delay(10);
  }  
}

void loop() {
  analogWrite(pwmpin, 255);
  for (int i=0; i<=3; i++){
    pwm1.setPWM(i,0,4960);
    delay(1000);
    pwm1.setPWM(i,4096,0);
    delay(100);
  }
  for (int j=0; j<=3; j++){
    pwm2.setPWM(j,0,4096);
    delay(1000);
    pwm2.setPWM(j,4096,0);
    delay(100);
  }  
}
