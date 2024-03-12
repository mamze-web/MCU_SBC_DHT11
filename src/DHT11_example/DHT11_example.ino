#include <DHT11.h> // DHT11 라이브러리 포함

DHT11 dht11(2); // 디지털 핀 2에 연결된 DHT11 센서 객체 생성

void setup() {
    Serial.begin(9600); // 시리얼 통신 시작 (9600 bps)
}

void loop() {
    int temperature = 0; // 온도 변수 초기화
    int humidity = 0;    // 습도 변수 초기화

    int result = dht11.readTemperatureHumidity(temperature, humidity); // 온도와 습도 읽기

    if (result == 0) { // 성공적으로 읽었을 때
        Serial.print("Temperature: "); // 온도 출력
        Serial.print(temperature);
        Serial.print(" °C\tHumidity: "); // 습도 출력
        Serial.print(humidity);
        Serial.println(" %");
    } else { // 실패했을 때
        Serial.println(DHT11::getErrorString(result)); // 에러 메시지 출력
    }
}
