#include <BluetoothSerial.h>
#include <ESP32Servo.h>

BluetoothSerial SerialBT;

// Pin tanımları
#define LED_PIN 33
#define SERVO_PIN 32
int stepPins[] = {12, 14, 26, 27};  // 28BYJ-48 motor pinleri

Servo myServo;
bool ledState = false;

// Half-step dizilim
int stepSequence[8][4] = {
  {1,0,0,0},
  {1,1,0,0},
  {0,1,0,0},
  {0,1,1,0},
  {0,0,1,0},
  {0,0,1,1},
  {0,0,0,1},
  {1,0,0,1}
};

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Motors"); // Bluetooth cihaz adı
  Serial.println("Bluetooth started");

  // LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Step motor pinleri
  for(int i=0;i<4;i++){
    pinMode(stepPins[i], OUTPUT);
    digitalWrite(stepPins[i], LOW);
  }

  // Servo motor
  myServo.attach(SERVO_PIN);
}

void loop() {
  if (SerialBT.available()) {
    String cmd = SerialBT.readStringUntil('\n');
    cmd.trim();           // boşluk ve \r karakterlerini temizler
    cmd.toUpperCase();    // tüm harfleri büyük yap

    Serial.print("Received cmd: '"); 
    Serial.print(cmd); 
    Serial.println("'");

    // LED kontrolü
    if (cmd == "L1") {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
      SerialBT.println(ledState ? "LED ON" : "LED OFF");
      Serial.println(ledState ? "LED ON" : "LED OFF");
    }

    // Step motor ileri
    else if (cmd == "S+") {
      Serial.println("Step Forward Command Received");
      for(int i=0;i<8;i++){
        for(int j=0;j<4;j++){
          digitalWrite(stepPins[j], stepSequence[i][j]);
        }
        delay(20); // hızı ayarlayabilirsiniz
      }
    }

    // Step motor geri
    else if (cmd == "S-") {
      Serial.println("Step Backward Command Received");
      for(int i=7;i>=0;i--){
        for(int j=0;j<4;j++){
          digitalWrite(stepPins[j], stepSequence[i][j]);
        }
        delay(20); // hızı ayarlayabilirsiniz
      }
    }

    // Servo motor 0°
    else if (cmd == "SV0") {
      myServo.write(0);
      SerialBT.println("Servo 0°");
      Serial.println("Servo 0°");
    }

    // Servo motor 90°
    else if (cmd == "SV90") {
      myServo.write(90);
      SerialBT.println("Servo 90°");
      Serial.println("Servo 90°");
    }

    else {
      Serial.print("Unknown command: ");
      Serial.println(cmd);
    }
  }
}
