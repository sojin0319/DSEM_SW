int soundSensor = A0;   // 사운드 센서 핀
int led[6] = {8,9,10,11,12,13}; 
int threshold = 700; // 소리 크기 기준
int count = 0;  // 박수를 몇 번 쳤는지 카운트
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(soundSensor, INPUT);  // 사운드 센서 입력으로 설정
  for (int i=0;i<6;i++) {
    pinMode(led[i], OUTPUT);  // LED 핀 출력으로 설정
  }
}

void loop() {
  val = analogRead(soundSensor);
  if (val >= threshold) { // 감지된 소리의 크기가 500 이상일 때
    for (int i=0;i<6;i++) {
      if (i==count) {// 카운트 된 박수 개수로 led 제어
        Serial.println(val);
        digitalWrite(led[i], HIGH);
      } else {
        digitalWrite(led[i], LOW);
      }
    }
    count = (count < 6) ? count+1 : 0;  // count<6이 참일 때 count+1, 거짓일 때 0 반환

    delay(200); // 박수 중복 입력이 안되게 200ms 딜레이
  } else {  // 감지된 소리의 크기가 500 이하일 때
    delay(1);
  }
}
