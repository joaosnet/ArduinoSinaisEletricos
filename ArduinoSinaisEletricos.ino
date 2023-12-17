void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial com taxa de baud de 9600
}

void loop() {
  int valorSensor1 = analogRead(A0); // Lê o valor do primeiro sensor conectado ao pino A0
  int valorSensor2 = analogRead(A1); // Lê o valor do segundo sensor conectado ao pino A1

  // Formata os valores em uma string
  String mensagem = String(valorSensor1) + " | " + String(valorSensor2);

  // Envia a string pela porta serial
  Serial.println(mensagem);

}
