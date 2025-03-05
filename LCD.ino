#include <LiquidCrystal.h>

int sensePin = A0;
int sensorInput;
double temp;

const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);  // Initialize LCD
  lcd.setCursor(0, 0);
  lcd.print("Frikk Braendsrod");
}

void loop() {
  // Display "NTNU Gjovik" for 10 seconds
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Frikk Braendsrod");
  lcd.setCursor(2, 1);
  lcd.print("NTNU Gjovik");
  delay(5000);

  // Read temperature and update display
  double tempSum = 0.0;
  int samples = 1000; // Number of readings for accuracy

  // Take multiple readings and sum them
  for (int i = 0; i < samples; i++) {
    sensorInput = analogRead(A0);
    tempSum += (double)sensorInput * 5.0 / 1024.0 * 100.0; // Convert to temperature
    delay(10); // Small delay for stability
  }

  // Compute average temperature
  temp = tempSum / samples;
  temp = temp - 30;
  temp = temp / 2;

  // Display the final computed temperature
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Frikk Braendsrod");
  lcd.setCursor(1, 1);
  lcd.print("Temp: ");
  lcd.print(temp, 2); // Show temp with 2 decimal places
  lcd.print(" C");

  delay(5000); // Show temp for 2 seconds before switching back
}
