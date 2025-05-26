// Motor con intensidad constante

const int motor = 9;
byte intensidad = 20;  // Valor fijo entre 0 y 255

void setup() {
  pinMode(motor, OUTPUT);
  analogWrite(motor, intensidad);  // Aplicar intensidad una vez al iniciar
}

void loop() {
  // No es necesario actualizar constantemente si no cambia
  // Pero si quieres mantenerlo, puedes dejar esto:
  analogWrite(motor, intensidad);
  delay(10);
}
