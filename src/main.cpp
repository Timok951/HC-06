#include <Arduino.h>
#include <SoftwareSerial.h>

#define BTN 11
#define LED1 8
#define LED2 7
#define LED3 6
#define LED4 5
#define LED5 4
#define LED6 9
#define TX 2
#define RX 1

bool btnFlag = false;

String val;

SoftwareSerial myserial(2, 3);

void setup()
{
  Serial.println(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(BTN, INPUT);

  myserial.println("Hi I am a SoftwareSerial, not Timofey!");
  randomSeed(analogRead(0));
}

void loop()
{
  if (myserial.available())
  {

    val = myserial.read();

    if (val == "MODE_1")
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
    }
    else if (val == "MODE_2")
    {
      do
      {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, LOW);
        delay(500);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, HIGH);

      } while (val == "MODE_1");
    }
    else if (val == "MODE_3")
    {
      for (int i = 0; i < 255; i++)
      {
        analogWrite(LED1, i);
        analogWrite(LED2, i);
        analogWrite(LED3, i);
        analogWrite(LED4, i);
        analogWrite(LED5, i);
        analogWrite(LED6, i);
        delay(10);
      }
      for (int i = 255; i > 0; i--)
      {
        analogWrite(LED1, i);
        analogWrite(LED2, i);
        analogWrite(LED3, i);
        analogWrite(LED4, i);
        analogWrite(LED5, i);
        analogWrite(LED6, i);
        delay(10);
      }
    }
    else if (val == "MODE_CHAOS")
    {
      do
      {
        int randNumber = random(0, 255);
        analogWrite(LED1, randNumber);
        analogWrite(LED2, randNumber);
        analogWrite(LED3, randNumber);
        analogWrite(LED4, randNumber);
        analogWrite(LED5, randNumber);
        analogWrite(LED6, randNumber);
        delay(50);
      } while (val == "MODE_CHAOS");
    }
    else if (digitalRead(LED1))
    {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      myserial.println("Shutting down...");
    }
  }
}
