#define BLYNK_TEMPLATE_ID "TMPL6e6GjH6Nz"
#define BLYNK_TEMPLATE_NAME "ParkirOtomatis"
#define BLYNK_AUTH_TOKEN "jVREBtGAobmTjMx9VgLSQUXtZIL568B_"
#define SERVO_OPEN_CLOSE 12
#define FRONT_IR 18
#define BACK_IR 22
#define PARKING_LOT_1_IR 2
#define PARKING_LOT_2_IR 0
#define PARKING_LOT_3_IR 4
#define PARKING_LOT_4_IR 5
#define SDA_PIN 26
#define SCL_PIN 27
#define SSID_NAME "Anang's Home"
#define PASSWORD "qweiop123890"

#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

LiquidCrystal_I2C lcd{0x27, 20, 4};
Servo myservo;

int counter = 0;
int prevStates[4] = {1, 1, 1, 1}; // Previous states for parking lot sensors

void setup() {
  Serial.begin(115200);
  myservo.attach(SERVO_OPEN_CLOSE);
  
  pinMode(FRONT_IR, INPUT);
  pinMode(BACK_IR, INPUT);
  
  pinMode(PARKING_LOT_1_IR, INPUT);
  pinMode(PARKING_LOT_2_IR, INPUT);
  pinMode(PARKING_LOT_3_IR, INPUT);
  pinMode(PARKING_LOT_4_IR, INPUT);
  
  Wire.begin(SCL_PIN, SDA_PIN);
  lcd.init();
  lcd.backlight();
  
  Blynk.begin(BLYNK_AUTH_TOKEN, SSID_NAME, PASSWORD);
}

void updateCounter(int currentState, int &prevState) {
  if (currentState == 0 && prevState == 1) {
    counter++; // Car entered
  } else if (currentState == 1 && prevState == 0) {
    counter--; // Car left
  }
  prevState = currentState;
}

void checkGate(int stateFront, int stateBack) {
  lcd.setCursor(0, 0);
  if (stateFront == 0 || stateBack == 0) {
    lcd.clear();
    lcd.print("Gerbang Terbuka");
    myservo.write(60);
    delay(2000);
  } else {
    lcd.print("Gerbang Tertutup");
    myservo.write(0);
  }
}

void displayParkingInfo() {
  if (counter < 0) counter = 0; // Ensure counter doesn't go below 0
  lcd.setCursor(0, 1);
  lcd.print("Total Parkir: ");
  lcd.print(counter);
  Blynk.virtualWrite(V0, "Total Parkir = " + String(counter));
}

void loop() {
  int stateFront = digitalRead(FRONT_IR);
  int stateBack = digitalRead(BACK_IR);

  // Read parking lot sensor states
  int states[] = {
    digitalRead(PARKING_LOT_1_IR),
    digitalRead(PARKING_LOT_2_IR),
    digitalRead(PARKING_LOT_3_IR),
    digitalRead(PARKING_LOT_4_IR)
  };

  checkGate(stateFront, stateBack);

  // Update the parking counter based on sensor states
  for (int i = 0; i < 4; i++) {
    updateCounter(states[i], prevStates[i]);
  }

  // Display the parking counter and send to Blynk
  displayParkingInfo();
  
  Blynk.run();
}
