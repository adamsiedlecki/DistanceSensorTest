    /*
    * Ultrasonic Sensor HC-SR04 and Arduino Tutorial
    *
    * by Dejan Nedelkovski,
    * www.HowToMechatronics.com
    *
    */
    // defines pins numbers
    const int trigPinSensor1 = 9;
    const int echoPinSensor1 = 10;

    const int trigPinSensor2 = 6;
    const int echoPinSensor2 = 5;
    
    void setup() {
      Serial.begin(9600); // Starts the serial communication
      initSensor(trigPinSensor1, echoPinSensor1);
      initSensor(trigPinSensor2, echoPinSensor2);
    }
    void loop() {

      int d1 = getDistanceFromSensor(trigPinSensor1, echoPinSensor1);
      int d2 = getDistanceFromSensor(trigPinSensor2, echoPinSensor2);
    
    // Prints the distance on the Serial Monitor
    //Serial.print("Distance: ");
    Serial.println("----------------------");
    Serial.print("d1: ");
    Serial.println(d1);

    //Serial.println("");
    Serial.print("d2: ");
    Serial.println(d2);
    }

    void initSensor(int trigPin, int echoPin){
      pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
      pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    }
    int getDistanceFromSensor(int trigPin, int echoPin){
      // Clears the trigPin
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      long duration = pulseIn(echoPin, HIGH);
      // Calculating the distance
      int distance = duration*0.034/2;
      return distance;
    }
