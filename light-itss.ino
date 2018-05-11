const int trig = 8;
const int echo = 7;
int ledPin = 13; //chân led - 13
int pirPin = 2; //chân cảm biến PIR - 2
int lsPin = 3; //chân cảm biến AS - 3
int speakerPin = 10; //chân còi - 10
int pirVal = 0;
int lsVal = 0;
unsigned long duration; // biến đo thời gian
int distance;           // biến lưu khoảng cách

void setup() {
  pinMode(ledPin, OUTPUT); //xuất tín hiệu ra chân led 13
  pinMode(pirPin, INPUT); //nhận tín hiệu từ cảm biến PIR
  pinMode(lsPin, INPUT); //nhận tín hiệu từ cảm biến AS
  Serial.begin(9600);
  pinMode(trig, OUTPUT); //chân trig phát tín hiệu
  pinMode(echo, INPUT); //chân echo nhận tín hiệu
  pinMode(speakerPin, OUTPUT); //xuất tín hiệu ra còi
}

void loop() {
  pirVal = digitalRead(pirPin); //đọc tín hiệu từ PIR
  lsVal = digitalRead(lsPin); //dọc tín hiệu từ cảm biến AS
  Serial.println(pirVal);
  if (pirVal == HIGH && lsVal == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

   /* Phát xung từ chân trig */
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    distance = int(duration/2/29.412); // speed^-1: 29.412ms/cm
    if(distance <= 150){
      digitalWrite(speakerPin, HIGH);
      delay(100);
      digitalWrite(speakerPin, LOW);
      delay(100);
      }
    digitalWrite(speakerPin, LOW);
}
