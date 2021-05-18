/*
    The Source code uses a Temputure Sensor LM35 to 
    read the tempture of a room.

    LM35 output = 0.01V per degree centigrade on the Vo Pin
        The Analog to digital converter (ADC) on the Arduino reads the voltage from Ground to VCC(5v) and converts it to a digital number
        result = 10 bit value which is proportional to the voltage applied from the Temputure Sensor
        VCC (Voltage to Common Collector) = Postive Voltage to circuit
        VSS (Voltage Source Supply) = Negative Voltage to circuit
        At 0v = reads 0, VCC = 1023

        Formulas Needed:
                V = (ADC/1023)
                Degrees Centegade = V/(0.01) | Degrees Centegrade = V * 100
                Fahrenheit = (Celcius * 1.8)+32    
    The circuit:
    - LM35 to 5v, GND, and Vo to analog 0
 */

//LM35 output variable 
int lM35_sensorData = A0;

void setup()
{
    // data is being sent at the baud rate 9600 (referring to 9600 bits per second (bps))
    Serial.begin(9600);
}

// Infinate Loop
void loop()
{ 
    float device;
    float temp;

    //reads data from sensor
    device = analogRead(lM35_sensorData);

    //convert the 10bit analog value to celcius
    temp = float(device) / 1023; //
    temp = temp * 500;

    // Print temputure to console
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.println(" Celcius");

    //Prints Fahrentheit conversion to console
    Serial.print("Fahrenheit: ");
    Serial.println((temp*1.8)+32);
    
    // Each 1000 milliseconds is the time stamp of 1 second 
    delay(1000); // reads every 10 second
}
