/**
 * The microcontroller that I am using cannot read resistance
 * The photocell acts like a variable resistor. 
 *  moreLight = less resistance 
 * A fixed resistor operates as a voltage divider on the circuit so the microcontroller can read the voltage as output
 * Utilized a 10 Kilobyte resistor on the circuit to accomplish this task. 
 *  
*/
const int minOutput = 0;
const int maxOutput = 800; //hardware max output possible 
int lightSensor = A0;

void setup(){
    Serial.begin(9600);
}

void loop(){
    int analog;
    int outputRange;

    analog = analogReader(lightSensor);
    outputRange = map(analog, minOutput, maxOutput, 0, 3); 

    switch(range){
        case 0:
            Serial.println("Its dark!");
            break;
        case 1:
            Serial.println("Its dim!");
            break;
        case 2:
            Serial.println("Its medium light!");
            break;
        case 3:
            Serial.println("Its bright!");
            break;            
    }

    delay(250);
}