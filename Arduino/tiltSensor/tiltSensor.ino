int tilt = 3;   // 기울기 센서 핀을 3번으로 받음
int led = 5;  // led를 5번 핀으로 출력

void setup() {
  Serial.begin(9600);
  pinMode(tilt, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int state = digitalRead(tilt);  // D3핀에 입력되는 신호 
  if (state == HIGH) {  // 센서가 기울었을 때
    Serial.println("기울어짐");
    digitalWrite(led, HIGH);  // led ON
    delay(300); // 0.3초간 대기
  } else {
    Serial.println("평평함");
    digitalWrite(led, LOW);
    delay(300);
  }
}
