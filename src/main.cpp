#include <Arduino.h>
#include <SoftwareSerial.h>

#define BTN 8
#define LED1 3
#define LED2 5
#define LED3 6
#define LED4 9
#define LED5 10
#define LED6 11
#define TX 12
#define RX 13

bool btnFlag = false;

String val;

SoftwareSerial myserial(TX, RX);

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(BTN, INPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);

  myserial.begin(9600);
  myserial.println("Hi I am a SoftwareSerial, not Timofey!");
  randomSeed(analogRead(0));
}

void loop()
{
  if (myserial.available())
  {

    val = myserial.readString();

    if (val == "MODE_1")
    {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      myserial.println("Mode1!");
    }
    else if (val == "MODE_2")
    {
      while (!myserial.available())
      {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, LOW);
        digitalWrite(LED5, HIGH);
        digitalWrite(LED6, LOW);
        delay(500);
        myserial.print("switching");
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, HIGH);
        digitalWrite(LED5, LOW);
        digitalWrite(LED6, HIGH);
        delay(500);
      }
    }
    else if (val == "MODE_3")
    {
      while (!myserial.available())
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
    }
    else if (val == "MODE_CHAOS")
    {
      while (!myserial.available())
      {
        int randNumber = random(0, 255);
        analogWrite(LED1, randNumber);
        analogWrite(LED2, randNumber);
        analogWrite(LED3, randNumber);
        analogWrite(LED4, randNumber);
        analogWrite(LED5, randNumber);
        analogWrite(LED6, randNumber);
        delay(5);
      }
    }
  }
  if (digitalRead(BTN))
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    delay(5);
    while (digitalRead(BTN))
    {
    }

    myserial.println("Shutting down...");
  }
}
