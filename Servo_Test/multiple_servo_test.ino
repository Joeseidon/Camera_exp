

Servo vertical_tilt;
Servo horizontal_pan;

//Pin def
int verticalServo = 9;
int horizontalServo = 6;

//Position var
int tilt = 0;
int pan = 0;

void servoSweep(Servo x, int pass)
{
    for(int i = 0; i<=pass; i++)
    {
        int pos = 0;
        for(pos = 0; pos <= 180; pos +=1){
            x.write(pos);
            delay(15);
        }

        for(pos = 0; pos >= 0; pos -=1){
            x.write(pos);
            delay(15);
        }
    }
}

void setup()
{
    vertical_tilt.attach(verticalServo);
    horizontal_pan.attach(horizontalServo);
}

void loop()
{
    servoSweep(vertical_tilt,1);
    servoSweep(horizontal_pan,1);
}
