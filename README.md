# Sensor de Luz Arduino 

Integrantes:
<ul>
<li>- André Nakamatsu Rocha</li>
<li>- Caio Suzano Ferreira Da Silva</li>
<li>- Matheus Rivera Montovaneli</li>
<li>- Lucas Vasquez Silva</li>
<li>- Guilherme Linard F. R. Gozzi</li>
</ul>

<br />
<br />

# O Projeto
O projeto baseia-se em um sistema para monitorar a luminosidade de uma vinícola por meio de um LDR e alertar por meio de LED's e som se caso o limite de luz exceder o recomendado.
<br />

<img src="../docs/img.png">

<a href="https://www.tinkercad.com/things/hqnSv0cleUD-cp-1-sensor-de-luminosidade/editel?sharecode=W6U-sAYscPEdjHpCb9JnqhZcRVCxMQC69G1Xbp4hNTI">Link do Projeto</a>

# Explicando o código

Primeiro nós definimos as variáveis que serão usadas no código.
```C++
int LEDV = 10; //Led vermelho e sua porta 
int LEDA = 9; //Led amarelo e sua porta
int LEDG = 8; //Led verde e sua porta
float LDR = A0; // Leitor de luminosidade e sua porta
int valorLDR = 0; // Valor inicial do leitor de luminosidade
int buzzer = 7; // buzzer/piezo e sua porta
```

<hr />

Definimos os pinos e se são INPUTS ou OUTPUTS
```C++
void setup()
{
  Serial.begin(9600); // Serial
  pinMode (LEDV, OUTPUT); // Led vermelho definido como saída
  pinMode (LEDG, OUTPUT); // Led verde definido como saída
  pinMode (LEDA, OUTPUT); // Led amarelo definido como saída
  pinMode (LDR, INPUT); // leitor de luminosidade definido como entrada
  pinMode (buzzer, OUTPUT); // buzzer/piezo definido como saída

}
```

<hr />

Primeiramente lêmos a quantidade de luminosidade do local e printamos no terminal
```C++
void loop () 
{
  valorLDR = analogRead(LDR); // atualiza a varíavel valorLDR de acordo com a luminosidade
  Serial.println("Valor lido pelo LDR : "); // texto no monitor serial
  Serial.println(valorLDR); // texto no monitor serial 
  delay (1000); // delay no monitor serial
```

Ainda não fechamos o loop, pois precisamos testar a quantidade de luminosidade.

<br />

Verificamos se a luminosidade do local está abaixo do recomendado e ascendemos o LED Vermelho
```C++
if (valorLDR < 250)//comparativo de luminosidade
  {
    apagaLeds(); // função para apagar as leds
  	digitalWrite(LEDV, HIGH); // código para ligar a led vermelha
    tone(buzzer, 200, 3000); //código do buzzer para emitir som
    delay(5000); // delay do buzer e das luzes
  }
```

<hr />

Caso a luminosidade estiver no intervalo desejado, ascendemos o LED Verde
```C++
if (valorLDR >= 250 && valorLDR < 750) //comparativo de luminosidade
  {
    apagaLeds(); // função para apagar as leds
    digitalWrite(LEDG, HIGH); // código para ligar a led verde
  }
```

<hr />

Caso a luminosidade não estiver perfeita, ascendemos o LED Amarelo
```C++
if (valorLDR >= 750 && valorLDR < 900) //comparativo de luminosidade
  {
  	apagaLeds(); // função para apagar as leds
    digitalWrite(LEDA, HIGH); // código para ligar a led amarela
    tone(buzzer, 400, 3000); //código do buzzer para emitir som
	delay(5000); // delay do buzer e das luzes
  }
```
<hr />

Caso a luminosidade estiver acima do recomendado, novamente ascendemos o LED Vermelho
```C++
if (valorLDR >= 900) //comparativo de luminosidade
  {
    apagaLeds(); // função para apagar as leds
    digitalWrite(LEDV, HIGH); // código para ligar a led vermelha
    tone(buzzer, 200, 3000); //código do buzzer para emitir som
	delay(5000); // delay do buzer e das luzes
  }
} //Fechamos a função loop.
```

<hr />

E por último definimos a função que usamos para apagar os LEDS anteriormente.
```C++ 
   void apagaLeds() // função para apagar as leds
  {
    digitalWrite(LEDV, LOW); // código para apagar a led vermelha
    digitalWrite(LEDG, LOW); // código para apagar a led verde
    digitalWrite(LEDA, LOW); // código para apagar a led amarela
  }
```