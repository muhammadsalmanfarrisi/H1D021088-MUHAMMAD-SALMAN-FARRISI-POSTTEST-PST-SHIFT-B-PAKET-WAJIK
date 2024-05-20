#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo myservo;

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D3;
int SCL_pin = D7;
void setup()
{
    myservo.attach(D4);
    Wire.begin(SDA_pin, SCL_pin);
    lcd.begin(16, 2);
    lcd.init();
    lcd.backlight();
    myservo.write(0);
    Serial.begin(9600);
}

void loop()
{

    myservo.write(90);
    // jika pintu kebuka (bergerak 90 deratay)
    if (myservo.write(90))
    {
        // maka lcd menampilkan tulisan pintu terbuka kemudian....(dibawah)
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pintu");
        lcd.setCursor(0, 1);
        lcd.print("terbuka");
        delay(1000);
        // setelah delay maka akan tertutup(kembali ke 0 derajat)
        myservo.write(0);
    }
    else if (myservo.write(0);)
    {
        // jila tertutup (servo kembali ke 0 derajat, maka lcd akan menampilkan tulisan tertutup)
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Pintu");
        lcd.setCursor(0, 1);
        lcd.print("tertutup");
    }

    // put your main code here, to run repeatedly:
}