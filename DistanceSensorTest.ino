
    const int trigPinSensor1 = 9;
    const int echoPinSensor1 = 10;

    const int trigPinSensor2 = 6;
    const int echoPinSensor2 = 5;
    
    void setup() {
      Serial.begin(9600);
      initSensor(trigPinSensor1, echoPinSensor1);
      initSensor(trigPinSensor2, echoPinSensor2);
    }
    void loop() {

      int d1 = getDistanceFromSensor(trigPinSensor1, echoPinSensor1);
      int d2 = getDistanceFromSensor(trigPinSensor2, echoPinSensor2);
    
      Serial.println("----------------------");
      Serial.print("d1: ");
      Serial.println(d1);

      Serial.print("d2: ");
      Serial.println(d2);
    }

    void initSensor(int trigPin, int echoPin){
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
    }
    
    int getDistanceFromSensor(int trigPin, int echoPin){
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);

      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      long duration = pulseIn(echoPin, HIGH);
      
      int distance = duration*0.034/2;
      return distance;
    }
