#include "TTAirPolygon.h"


TTAIR::TTAirPolygon *poly;

void setup() {
  //INICIANDO SERIAL
  Serial.begin(115200);

  //Instanciando a classe em memória
  poly = new TTAIR::TTAirPolygon();

  //Criando o ponto inicial para o poligono
  poly->addPoint(0, 120);

  //Criando os pontos recebidos
  poly->addPoint(125, 60);
  poly->addPoint(250, 70);
  poly->addPoint(500, 50);
  poly->addPoint(750, 70);
  poly->addPoint(1000, 30);
  poly->addPoint(1500, 30);
  poly->addPoint(2000, 30);
  poly->addPoint(3000, 40);
  poly->addPoint(4000, 70);
  poly->addPoint(6000, 60);
  poly->addPoint(8000, 30);

  //Criando mais dois pontos para fechar o polígono.
  //Origem e fim devem se encontrar.
  poly->addPoint(1000, 120);
  poly->addPoint(0, 120);
}

void loop() {
  //Delay
  delay(500);

  //Verificando se o ponto (1000,90) está dentro
  if (poly->contains(1000, 90)) {
    Serial.println("Escutou");
  } else {
    Serial.println("Nao Escutou");
  }

  //Verificando se o ponto (1000,10) está dentro
  if (poly->contains(1000, 10)) {
    Serial.println("Escutou");
  } else {
    Serial.println("Nao Escutou");
  }


}
