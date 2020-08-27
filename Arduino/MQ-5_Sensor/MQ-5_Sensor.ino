 int Gas_Sensor = A0;             // MQ-5 가스센서측정핀을 A0에 연결
int Buzzer = 10;                    // 부저를 디지털 핀10에 연결
int LED = 7;                       // LED를 디지털 핀7에 연결
 
void setup() {
  Serial.begin(9600);             // Serial monitor 구동 선언
  pinMode(7, OUTPUT);              // 디지털 핀7을 출력핀으로 선언
  pinMode(10, OUTPUT);              // 디지털 핀10를 출력핀으로 선언
}
 
void loop() {
  float sensor_volt;
  float RS_gas; 
  float ratio;
  float ppm;
  int sensorValue = analogRead(A0);

  sensor_volt = (float)sensorValue/1024*5.0;  // 아날로그 신호를 전압으로 변환
  RS_gas = (5.0-sensor_volt)/sensor_volt; // omit*RL
  ratio = RS_gas/0.15;  // ratio = RS/R0
  ppm = map(sensorValue, 0, 1024, 0, 10000);  // 아날로그 신호를 ppm 단위로 변환

  Serial.print("sensor_volt = ");
  Serial.print(sensor_volt);
  Serial.print(", ");
  Serial.print("ppm = ");
  Serial.println(ppm);
  
  delay(100);                        // 0.1초 딜레이 선언
 
  if(analogRead(A0) < 400) {         // A0 < 400일때,  
    noTone(10);                       // Buzzer의 경고음 OFF 유지
 }
  else if(analogRead(A0) > 400) {     // A0 > 400일때,
    tone(10, 440,10);                    // tone(연결핀, 진동수, 발생시간)
                                        // Buzzer가 0.1초 간격으로 경고음 울림
    digitalWrite(7, HIGH);              // 빨간색 LED가 0.1초 간격으로 점멸
    delay(100);
    digitalWrite(7, LOW);                                    
  }
 }
