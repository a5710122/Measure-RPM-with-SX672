#include <Wire.h>
#include <LiquidCrystal_I2C.h> //Library LCD I2C
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int inputPin = 2;     //The pin location of the sensor
int val = 0;       // variable to store the read value
int count ;        //measuring the rising edges of the signal
int Calc = 0 ;    // variable to calculate RPM


void couter() { //This is the function that the interupt calls
  count++;  //This function measures the rising and falling edge of the hall effect sensors signal

}


void setup() {

  Serial.begin(9600);
  lcd.begin();
  pinMode(inputPin, INPUT_PULLUP);
  attachInterrupt(0, couter, FALLING ); // interrupt
  lcd.print("RPM");

}

void loop() {

  //val = digitalRead(inputPin);     // read the input pin
  //Serial.print("val: ");
  //Serial.println(val);
  //delay(500);

  count = 0; //Set count to 0 ready for calculations
  sei();           //Enables interrupts
  lcd.clear();
  lcd.print("RPM");
  lcd.setCursor(0, 1);
  lcd.print(Calc);
  delay (1000);     //Wait 1 second
  cli();           //Disable interrupts
  Calc = count * 5; // (Count/number your rotor blade) * 60s = RPM/minute.

  Serial.print("count_RPM: ");
  Serial.println( Calc);


  Serial.print("count_pluse: ");
  Serial.println(count);

}




