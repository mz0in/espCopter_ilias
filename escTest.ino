#include <Servo.h>
// ---------------------------------------------------------------------------
Servo motA, motB, motC, motD;
String data;
// ---------------------------------------------------------------------------

/**
 * Start serial, attach motors, and display the instructions and format
 */
void setup() {
    Serial.begin(115200);
    motA.attach(UPPER_LEFT_MOTOR, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motB.attach(UPPER_RIGHT_MOTOR, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motC.attach(LOWR_LEFT_MOTOR, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    motD.attach(LOWER_RIGHT_MOTOR, MIN_PULSE_LENGTH, MAX_PULSE_LENGTH);
    giveInstructions();
}

/**
 * Loop: Read input and execute instruction
 */
void loop() {
    if (Serial.available()) {
        data = Serial.readString();
        char motor = data.charAt(0);
        char time = data.substring(2)
        if(motor == 'a'){
            motA.writeMicroseconds(time);    
        }else if(motor == 'b'){
            motB.writeMicroseconds(time);
        }else if(motor == 'c'){
            motC.writeMicroseconds(time);
        }else if(motor == 'd'){
            motD.writeMicroseconds(time);
        }
    }
}

/**
 * Give user control format
 */
void giveInstructions()
{  
    Serial.println("INTERFACE RULES:");
    Serial.println("\tMOTOR_LETTER.PULSE_LENGTH");
    Serial.println("\t\tMOTOR_LETTER = {a, b, c, d}");
    Serial.println("\t\tPULSER_LENGTH = [1000,2000]");
}

