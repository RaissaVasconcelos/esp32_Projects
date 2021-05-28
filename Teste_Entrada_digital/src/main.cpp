//Autor: Raissa Vasconcelos
//Não usar os pinos de 6-11
#include <Arduino.h>

//--------------Mapeamento do Hardware----------------//
#define btc1 4
#define btc2 5
#define out1 22
#define out2 23

//--------------Mapeamento das Funções----------------//
void read_btc();

void setup()
{
  // put your setup code here, to run once:
  pinMode(btc1, INPUT_PULLUP); //Acionar os resistores pull-up
  pinMode(btc2, INPUT_PULLUP);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);

  //Inicializar as saidas desligadas
  pinMode(out1, LOW);
  pinMode(out2, LOW);
}

void loop()
{
  // put your main code here, to run repeatedly:
  read_btc();
}

//--------------Desenvolvimento das Funções----------------//
void read_btc()
{
  static char estado1 = 0, estado2 = 0; //guardar o status do botão
  //logica para botao1
  if (!digitalRead(btc1))
    estado1=1;
  if(digitalRead(btc1) && estado1) //logica quando o botão for solto, quando o botao e o estado forem 1
  {
    estado1 = 0;
    digitalWrite(out1,!digitalRead(out1));
    delay(130);
  }
  //logica para botao2
  if (!digitalRead(btc2))
    estado2=1;
  if(digitalRead(btc2) && estado2) //logica quando o botão for solto, quando o botao e o estado forem 1
  {
    estado2 = 0;
    digitalWrite(out2,!digitalRead(out2));
    delay(130);
  }
}
 