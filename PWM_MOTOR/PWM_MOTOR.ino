// Motor con intensidad constante

const int motor = 9;
byte intensidad = 100;  // Valor fijo entre 0 y 255

void setup() {
  pinMode(motor, OUTPUT);
  analogWrite(motor, intensidad);  // Aplicar intensidad una vez al iniciar
}

void loop() {
  analogWrite(motor, intensidad);
  delay(10);
}
