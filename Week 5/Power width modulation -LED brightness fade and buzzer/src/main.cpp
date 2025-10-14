#include <Arduino.h>

// NAME  : ZAIN RAZA ZAIDI
//Roll No: 23-NTU-CS-B-1096


// -------- LED Configuration --------
#define LED_PIN 18
#define LED_CH  0
#define LED_FREQ 5000
#define LED_RES 8

// -------- Buzzer Configuration --------
#define BUZZER_PIN 27
#define BUZZER_CH  1
#define BUZZER_FREQ 2000
#define BUZZER_RES 10

void setup() {
  // --- LED PWM Setup ---
  ledcSetup(LED_CH, LED_FREQ, LED_RES);
  ledcAttachPin(LED_PIN, LED_CH);

  // --- Buzzer PWM Setup ---
  ledcSetup(BUZZER_CH, BUZZER_FREQ, BUZZER_RES);
  ledcAttachPin(BUZZER_PIN, BUZZER_CH);
}

void loop() {
  // --- LED Fade Loop ---
  for (int duty = 0; duty <= 255; duty++) {
    ledcWrite(LED_CH, duty);
    delay(5);
  }
  for (int duty = 255; duty >= 0; duty--) {
    ledcWrite(LED_CH, duty);
    delay(5);
  }

  // --- Buzzer Pattern ---
  // Simple beep sequence
  for (int i = 0; i < 3; i++) {
    ledcWriteTone(BUZZER_CH, 2000 + i * 400);
    delay(150);
    ledcWrite(BUZZER_CH, 0);
    delay(150);
  }

  // Frequency sweep
  for (int f = 400; f <= 3000; f += 100) {
    ledcWriteTone(BUZZER_CH, f);
    delay(20);
  }
  ledcWrite(BUZZER_CH, 0);
  delay(300);

  // Short melody
  int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
  for (int i = 0; i < 8; i++) {
    ledcWriteTone(BUZZER_CH, melody[i]);
    delay(200);
  }
  ledcWrite(BUZZER_CH, 0);
  delay(500);
}
