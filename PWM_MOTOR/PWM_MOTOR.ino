//HOLA VIERA

const int motor = 9;
byte intensidad = 0;
String buffer = "";  // Acumula los caracteres numéricos

void setup() {
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ingrese un valor entre 0 y 100:");
}

void loop() {
  if (Serial.available() > 0) {
    char numero = Serial.read();

    // Ignorar saltos de línea
    if (numero == '\n' || numero == '\r') {
      if (buffer.length() > 0) {
        int valor = buffer.toInt();  // Convierte el texto a número

        if (valor >= 0 && valor <= 100) {
          intensidad = map(valor, 0, 100, 0, 255);
          Serial.print("PWM actualizado a: ");
          Serial.print(valor);
          Serial.println("%");
        } else {
          Serial.println("Valor fuera de rango (0-100).");
        }

        buffer = ""; // Limpiar para la próxima entrada
      }
    }
    // Acumular solo si es número
    else if (isDigit(numero)) {
      buffer += numero;
    }
  }

  analogWrite(motor, intensidad);
  delay(10);
}
