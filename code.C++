

//Definindo as variaveis do código
int LEDV = 10; //Led vermelho e sua porta 
int LEDA = 9; //Led amarelo e sua porta
int LEDG = 8; //Led verde e sua porta
float LDR = A0; // Leitor de luminosidade e sua porta
int valorLDR = 0; // Valor inicial do leitor de luminosidade
int buzzer = 7; // buzzer/piezo e sua porta


//definições dos pinos e serial
void setup()
{
  Serial.begin(9600); // Serial
  pinMode (LEDV, OUTPUT); // Led vermelho definido como saída
  pinMode (LEDG, OUTPUT); // Led verde definido como saída
  pinMode (LEDA, OUTPUT); // Led amarelo definido como saída
  pinMode (LDR, INPUT); // leitor de luminosidade definido como entrada
  pinMode (buzzer, OUTPUT); // buzzer/piezo definido como saída

}


//Progamação do sistema de acender e apagar leds
void loop () 
{
  valorLDR = analogRead(LDR); // atualiza a varíavel valorLDR de acordo com a luminosidade
  Serial.println("Valor lido pelo LDR : "); // texto no monitor serial
  Serial.println(valorLDR); // texto no monitor serial 
  delay (1000); // delay no monitor serial
  
  if (valorLDR < 250)//comparativo de luminosidade
  {
    apagaLeds(); // função para apagar as leds
    digitalWrite(LEDV, HIGH); // código para ligar a led vermelha
    tone(buzzer, 200, 3000); //código do buzzer para emitir som
    delay(5000); // delay do buzer e das luzes
  }
  if (valorLDR >= 250 && valorLDR < 750) //comparativo de luminosidade
  {
    apagaLeds(); // função para apagar as leds
    digitalWrite(LEDG, HIGH); // código para ligar a led verde
  }
  if (valorLDR >= 750 && valorLDR < 900) //comparativo de luminosidade
  {
    apagaLeds(); // função para apagar as leds
    digitalWrite(LEDA, HIGH); // código para ligar a led amarela
    tone(buzzer, 400, 3000); //código do buzzer para emitir som
    delay(5000); // delay do buzer e das luzes
  }
  if (valorLDR >= 900) //comparativo de luminosidade
  {
    apagaLeds(); // função para apagar as leds
    digitalWrite(LEDV, HIGH); // código para ligar a led vermelha
    tone(buzzer, 200, 3000); //código do buzzer para emitir som
    delay(5000); // delay do buzer e das luzes
  }
  
}   
   void apagaLeds() // função para apagar as leds
  {
    digitalWrite(LEDV, LOW); // código para apagar a led vermelha
    digitalWrite(LEDG, LOW); // código para apagar a led verde
    digitalWrite(LEDA, LOW); // código para apagar a led amarela
  }





