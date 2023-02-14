#define pwm1M4 5
#define pwm2M4 4
#define enM4 25

#define encoder4A 40
#define encoder4B 42

int pwm;
int ppr = 133;
int counter = 0;
bool isForward = true;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(pwm1M4, OUTPUT);
  pinMode(pwm2M4, OUTPUT);
  pinMode(enM4, OUTPUT);
  pinMode(encoder4A, INPUT);
  pinMode(encoder4B, INPUT);

  attachInterrupt(digitalPinToInterrupt(encoder4B), detect, RISING);
}

void loop() {

  if (isForward) {
    if (ppr <= counter) {
      pwm = 0;
    }

    // menentukan arah gerak roda
    // pwm1 clockwise/maju
    // pwm2 counterclockwise/mundur

    analogWrite(pwm1M4, 255);
    analogWrite(pwm2M4, 0);
    digitalWrite(enM4, HIGH);
    
    delay(1000);
    
    detachInterrupt(encoder4B);
    Serial.println(pwm);

    counter = 0 ;
    pwm += 10;

    if (pwm > 255) {
      pwm = 255;
//      isForward = false;
    }
//  } else {
//
//    analogWrite(pwm1M4, 0);
//    analogWrite(pwm2M4, pwm);
//    
//    digitalWrite(enM4, HIGH);
//    delay(1000);
//    
//    detachInterrupt(encoder4B);
//    Serial.print(pwm);
//    Serial.print(" "); 
//    //Serial.println(rpm);
//
//    counter = 0;
//    pwm -= 10;
//
//    if (pwm <= 0) {
//      pwm = 0;
//      isForward = true;
//    }
//  }
//
//  attachInterrupt(digitalPinToInterrupt(encoder4B), detect, RISING);
}
}

void detect() {
  if (digitalRead(encoder4A)) {
    counter -= 1;
  } else {
    counter += 1;
  }

  Serial.println(counter);
}
