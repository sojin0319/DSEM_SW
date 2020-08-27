#include <DHT.h>
#define DHTPIN 2     // 디지털 2번핀 사용
#define DHTTYPE DHT11   // DHT 11 모델사용 
DHT dht(DHTPIN, DHTTYPE);
int cds=0;

void setup() {
  Serial.begin(9600);
  dht.begin();
}                                                                     

void loop() {
  int h = dht.readHumidity(); // 습도 측정
  int t = dht.readTemperature(); // 섭씨 온도 측정

  //Serial.print("H:");
  Serial.print(h);
  Serial.print(" ");
  //Serial.print("%, ");

  //Serial.print("T:");
  Serial.print(t);
  Serial.print(" ");
  //Serial.print("C, ");
  
  cds = analogRead(A0);
  //Serial.print("cds=");
  Serial.print(cds);
  //Serial.print("(Lux)");
  Serial.println();
  delay(1000);  // 1초
}
