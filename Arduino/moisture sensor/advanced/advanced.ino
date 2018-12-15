

uint32_t SLEEP_TIME = 30000; // Sleep time between reads (in milliseconds)

long buffer[NUM_READS];
int idx;

/// @brief Structure to be used in percentage and resistance values matrix to be filtered (have to be in pairs)
typedef struct {
    int moisture; //!< Moisture
    long resistance; //!< Resistance
} values;

const long knownResistor = 4700;  // Constant value of known resistor in Ohms

int supplyVoltage;                // Measured supply voltage
int sensorVoltage;                // Measured sensor voltage

values valueOf[NUM_READS];        // Calculated moisture percentages and resistances to be sorted and filtered

int i;                            // Simple index variable

void setup()
{
    // initialize the digital pins as an output.
    // Pin 6,7 is for sensor 1
    // initialize the digital pin as an output.
    // Pin 6 is sense resistor voltage supply 1
    pinMode(6, OUTPUT);

    // initialize the digital pin as an output.
    // Pin 7 is sense resistor voltage supply 2
    pinMode(7, OUTPUT);
}

void presentation()
{
    sendSketchInfo("Soil Moisture Sensor Reverse Polarity", "1.0");
    present(CHILD_ID, S_MOISTURE);
}

void loop()
{

    measure(6,7,1);
    Serial.print ("\t");
    Serial.println (average());
    long read1 = average();

    measure(7,6,0);
    Serial.print ("\t");
    Serial.println (average());
    long read2= average();

    long sensor1 = (read1 + read2)/2;

    Serial.print ("resistance bias =" );
    Serial.println (read1-read2);
    Serial.print ("sensor bias compensated value = ");
    Serial.println (sensor1);
    Serial.println ();

    //send back the values
    send(msg.set((long int)ceil(sensor1)));
    // delay until next measurement (msec)
    sleep(SLEEP_TIME);
}

void measure (int phase_b, int phase_a, int analog_input)
{
    // read sensor, filter, and calculate resistance value
    // Noise filter: median filter

    for (i=0; i<NUM_READS; i++) {

        // Read 1 pair of voltage values
        digitalWrite(phase_a, HIGH);                 // set the voltage supply on
        delayMicroseconds(25);
        supplyVoltage = analogRead(analog_input);   // read the supply voltage
        delayMicroseconds(25);
        digitalWrite(phase_a, LOW);                  // set the voltage supply off
        delay(1);

        digitalWrite(phase_b, HIGH);                 // set the voltage supply on
        delayMicroseconds(25);
        sensorVoltage = analogRead(analog_input);   // read the sensor voltage
        delayMicroseconds(25);
        digitalWrite(phase_b, LOW);                  // set the voltage supply off

        // Calculate resistance
        // the 0.5 add-term is used to round to the nearest integer
        // Tip: no need to transform 0-1023 voltage value to 0-5 range, due to following fraction
        long resistance = (knownResistor * (supplyVoltage - sensorVoltage ) / sensorVoltage) ;

        delay(1);
        addReading(resistance);
        Serial.print (resistance);
        Serial.print ("\t");
    }
}
