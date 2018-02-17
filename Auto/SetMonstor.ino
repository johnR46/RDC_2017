//##################################################################################
void Initial_MotorShield(void)
{ pinMode(StatePin, OUTPUT);      // Fault Monitor
  for (int i = 0; i < 2; i++)
  { pinMode(inApin[i], OUTPUT);   // Initialize digital pins as outputs
    pinMode(inBpin[i], OUTPUT);
    pinMode(pwmpin[i], OUTPUT);
    digitalWrite(inApin[i], LOW); // Initialize braked
    digitalWrite(inBpin[i], LOW);
  }
}

//##################################################################################
void motorOff(int motor)
{ motor--;
  digitalWrite(inApin[motor], LOW);
  digitalWrite(inBpin[motor], LOW);
  analogWrite(pwmpin[motor], 0);
}
void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)
{ if ((motor == 1) || (motor == 2) )
  { motor--;
    if (direct == CW)
    { digitalWrite(inApin[motor], HIGH);
      digitalWrite(inBpin[motor], LOW);
    }
    else if (direct == CCW)
    { digitalWrite(inApin[motor], LOW);
      digitalWrite(inBpin[motor], HIGH);
    }
    else
    { digitalWrite(inApin[motor], LOW);
      digitalWrite(inBpin[motor], LOW);
    }
    analogWrite(pwmpin[motor], pwm);
  }
}

void Check_OverCurrent(void)
{ bool OverCurrent = false;
  OverCurrent = OverCurrent || (analogRead(cspin[0]) > CS_THRESHOLD);
  OverCurrent = OverCurrent || (analogRead(cspin[1]) > CS_THRESHOLD);
    if (OverCurrent)
  { digitalWrite(StatePin, LOW);
    motorOff(1);
    motorOff(2);
   }
  else
    digitalWrite(StatePin, HIGH);
}
//##################################################################################
void Stop(void)
{ motorOff(1);
  motorOff(2);
}

void SprintRight(int xDelay, int xSpeed)
{ 
  Serial.println("SprintRight");
  motorGo(1, CCW, xSpeed);
  motorGo(2, CW, xSpeed);
  delay(xDelay);
  Check_OverCurrent();
}

void SprintLeft(int xDelay, int xSpeed)
{
  Serial.println("SprintLeft");
  motorGo(1, CW, xSpeed);
  motorGo(2, CW, xSpeed);
  delay(xDelay);
  Check_OverCurrent();
}

void Right(int xDelay, int xSpeed)
{ 
  Serial.println("Right");
  motorGo(1, CW, xSpeed);
  motorGo(2, CW, xSpeed);
  delay(xDelay);
  Check_OverCurrent();
}

void Left(int xDelay, int xSpeed)
{ 
  Serial.println("Left");
  motorGo(1, CCW, xSpeed);
  motorGo(2, CCW, xSpeed);
  delay(xDelay);
  Check_OverCurrent();
}

void Go(int xDelay, int xSpeed)
{ 
  Serial.println("Go");
  motorGo(1, CW, xSpeed);
  motorGo(2, CCW, xSpeed);
  delay(xDelay);
  Check_OverCurrent();
}

void Back(int xDelay, int xSpeed)
{ 
  Serial.println("Back");
  motorGo(1, CCW, xSpeed);
  motorGo(2, CW, xSpeed);
  delay(xDelay);
  Check_OverCurrent();
}

