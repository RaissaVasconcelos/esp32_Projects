//---------------------------------------------------
// Autor: Raissa Vasconcelos
//---------------------------------------------------
// Projeto de controle da saída utilizando leds sem utilizar a função delay
// A função delay trava o processador do ESP32, por isso,
// não é usada em projetos que precisam de uma precisão
#include <Arduino.h>
//-------------Mapeamento do Hardware----------------
#define out1 18
#define out2 4
#define out3 5
//-------------Constantes do Projeto----------------
#define out1_temp 400
#define out2_temp 800
#define out3_temp 500
//-------------Variavéis Globais----------------
int out1_save_temp,
    out2_save_temp,
    out3_save_temp;

void setup()
{
  // put your setup code here, to run once:
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
  digitalWrite(out3, LOW);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (millis() - out1_save_temp >= out1_temp)
  {
    digitalWrite(out1, !digitalRead(out1));
    out1_save_temp = millis();
  } //end of out1
  if (millis() - out2_save_temp >= out2_temp)
  {
    digitalWrite(out2, !digitalRead(out2));
    out2_save_temp = millis();
  } //end of out2
  if (millis() - out3_save_temp >= out3_temp)
  {
    digitalWrite(out3, !digitalRead(out3));
    out3_save_temp = millis();
  } //end of out3
}