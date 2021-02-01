#include <DHT.h> //inclui a biblioteca dos sensores DHT
#define DHTPIN 2 //define o pino 2 para receber dados do sensor
#define DHTTYPE DHT11 //define o tipo de sensor, nesse caso DHT11

DHT dht (DHTPIN, DHTTYPE); //cria o obj do tipo DHT, passando como parâmetros o pino e o tipo 

void setup() {
  Serial.begin(9600); //inicia a comunicação serial
  dht.begin(); //inicia o sensor DHT11
}

void loop() {
  delay (1000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)){
    return;
  }

  Serial.print("A umidade no quarto do theo agora é: ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("A temperatura no quarto do theo agora é: ");
  Serial.print(t);
  Serial.println("°C ");

}
