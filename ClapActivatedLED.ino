#define POTENTIOMETER_PIN A1
#define RGB_RED_PIN 11
#define RGB_BLUE_PIN 10
#define RGB_GREEN_PIN 9


int MIC = 0;     //mic pin
int VALOR;       //Mic input value
int dTime = 80;  //delay time value

int Sensor_pin = A0;  // Reed card pin
int Magnet = 0;       // Magnet defult value

int mode = 0;

void digitalWriteRGB(byte red, byte blue, byte green) {
  digitalWrite(RGB_RED_PIN, red);
  digitalWrite(RGB_BLUE_PIN, blue);
  digitalWrite(RGB_GREEN_PIN, green);
}

void setup() {
  Serial.begin(9600);

  pinMode(MIC, INPUT);

  pinMode(RGB_RED_PIN, OUTPUT);
  pinMode(RGB_BLUE_PIN, OUTPUT);
  pinMode(RGB_GREEN_PIN, OUTPUT);

  pinMode(Sensor_pin, INPUT);
}

void loop() {
  VALOR = digitalRead(MIC);
  Magnet = digitalRead(Sensor_pin);

  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Serial.write(buttonState);
    mode++;
    if (mode == 7) {
      mode = 0;
    }
    buttonState = LOW;
  }

  int potentiometerValue = analogRead(POTENTIOMETER_PIN);

  if (VALOR == HIGH && Magnet) {
    if (mode == 0) {
      digitalWriteRGB(HIGH, LOW, LOW);
      delay(dTime);
    } else if (mode == 1) {
      digitalWriteRGB(LOW, HIGH, LOW);
      delay(dTime);
    } else if (mode == 2) {
      digitalWriteRGB(LOW, LOW, HIGH);
      delay(dTime);
    } else if (mode == 3) {
      digitalWriteRGB(HIGH, HIGH, LOW);
      delay(dTime);
    } else if (mode == 4) {
      digitalWriteRGB(HIGH, LOW, HIGH);
      delay(dTime);
    } else if (mode == 5) {
      digitalWriteRGB(LOW, HIGH, HIGH);
      delay(dTime);
    } else if (mode == 6) {
      digitalWriteRGB(HIGH, HIGH, HIGH);
      delay(dTime);
    } else {
      digitalWriteRGB(LOW, LOW, LOW);
      delay(dTime);
    }
  } else {
    digitalWriteRGB(LOW, LOW, LOW);
  }
}