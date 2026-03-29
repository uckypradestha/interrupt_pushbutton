#include <Arduino.h>

int buttonPin = 2;  // Pin tombol (harus pin interrupt: 2 atau 3 pada Arduino Uno)
int buttonLED = 11; // LED yang dikontrol oleh tombol (via interrupt)
int blinkLED = 12;  // LED yang akan berkedip terus di loop

// Variabel global untuk menyimpan status tombol
volatile int buttonState;  // volatile karena diakses oleh ISR

/* Fungsi Interrupt Service Routine (ISR)
Fungsi ini akan dipanggil otomatis saat terjadi interrupt */
void buttonInterrupt() {
  // Membaca kondisi tombol
  buttonState = digitalRead(buttonPin);
  // Jika tombol tidak ditekan (HIGH karena INPUT_PULLUP)
  if (buttonState == HIGH) {
    digitalWrite(buttonLED, LOW); // Matikan LED jika tombol dilepas
  }
  // Jika tombol ditekan (LOW)
  if (buttonState == LOW) {
    digitalWrite(buttonLED, HIGH); // Nyalakan LED jika tombol ditekan
  }
}

void setup() {
  // Set pin sebagai input dengan internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // Set pin LED sebagai output
  pinMode(buttonLED, OUTPUT);
  pinMode(blinkLED, OUTPUT);

  /*
  Mengaktifkan interrupt
  digitalPinToInterrupt(buttonPin) → konversi pin ke nomor interrupt
  buttonInterrupt → fungsi ISR yang dipanggil
  CHANGE → interrupt terjadi saat perubahan HIGH ↔ LOW
  */
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, CHANGE);
}

void loop() {
  // LED ini akan terus berkedip (simulasi proses utama)
  digitalWrite(blinkLED, HIGH);
  delay(200); // delay (blocking)
  digitalWrite(blinkLED, LOW);
  delay(200);// delay (blocking)
}