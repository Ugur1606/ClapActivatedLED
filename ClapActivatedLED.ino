//En altta potentiometer ile parlaklık ayarlamak için olan kodu ekledim deneriz onu.
//Renkler arasında geçiş için button koyabiliriz. 7 seçenek olur 6 renk sabit yanar son seçenekte de renkler arasında yumuşak otomatik geçiş yapabilir. 
//Örnek olarak kırmızı tuşa başlar bastın sarı bastın yeşil bastın camgöbeği bastın mmavi bastn pembe en son bi daha bastın renkler arasında yumuşak geçiş.

#define POTENTIOMETER_PIN A1
#define RGB_RED_PIN 11
#define RGB_BLUE_PIN 10
#define RGB_GREEN_PIN 9

int MIC = 0; //mic pin
int VALOR;   //Mic input value?
int dTime = 80; //delay time value 

int Sensor_pin = A0 ; // Reed card pin
int Magnet = 0 ; // Magnet defult value

void digitalWriteRGB(byte red, byte blue, byte green)
{
  digitalWrite(RGB_RED_PIN, red);
  digitalWrite(RGB_BLUE_PIN, blue);
  digitalWrite(RGB_GREEN_PIN, green);
}

void setup()    
{    
  Serial.begin(9600); //If we are not using the serial monitor delete this line.

  pinMode(MIC, INPUT) ; 

  pinMode(RGB_RED_PIN, OUTPUT);
  pinMode(RGB_BLUE_PIN, OUTPUT);
  pinMode(RGB_GREEN_PIN, OUTPUT);

  //digitalWriteRGB(LOW, LOW, LOW); //This line was a test purpose if the leds at HIGH position on boot reactivate this line.

  pinMode(Sensor_pin, INPUT) ; 

  //digitalWrite(RGB_RED_PIN, LOW); //I don't remember why tf we had this line.
}

void loop()
{  
  

  VALOR = digitalRead(MIC);
  Magnet = digitalRead(Sensor_pin);

  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int mode = map(potentiometerValue, 0, 1023, 0, 6);

  if(VALOR == HIGH && Magnet)
  {
    if (mode== 0){
        digitalWriteRGB(HIGH,LOW,LOW);
        delay(dTime);
    }
    else if(mode== 1){
        digitalWriteRGB(LOW,HIGH,LOW);
        delay(dTime);
    }
    else if(mode== 2){
        digitalWriteRGB(LOW,LOW,HIGH);
        delay(dTime);
    }
    else if(mode== 3){
        digitalWriteRGB(HIGH,HIGH,LOW);
        delay(dTime);
    }
    else if(mode== 4){
        digitalWriteRGB(HIGH,LOW,HIGH);
        delay(dTime);
    }
    else if(mode== 5){
        digitalWriteRGB(LOW,HIGH,HIGH);
        delay(dTime);
    }
    else if(mode== 6){
        digitalWriteRGB(HIGH,HIGH,HIGH);
        delay(dTime);
    }
    else{
        digitalWriteRGB(LOW,LOW,LOW);
        delay(dTime);
          }
  
    
    /*
    switch(mode)
    {
      case 0:
        digitalWriteRGB(HIGH,LOW,LOW);
        delay(dTime);

      case 1:
        digitalWriteRGB(LOW,HIGH,LOW);
        delay(dTime);
      
      case 2:
        digitalWriteRGB(LOW,LOW,HIGH);
        delay(dTime);
      
      case 3:
        digitalWriteRGB(HIGH,HIGH,LOW);
        delay(dTime);

      case 4:
        digitalWriteRGB(HIGH,LOW,HIGH);
        delay(dTime);

      case 5:
        digitalWriteRGB(LOW,HIGH,HIGH);
        delay(dTime);
      case 6:
        digitalWriteRGB(HIGH,HIGH,HIGH);
        delay(dTime);

      default:
        digitalWriteRGB(LOW,LOW,LOW);
        delay(dTime);
    }
    */
  }
  else{
    digitalWriteRGB(LOW,LOW,LOW);

  }
}


/*
  Potentiometer'ın map'lemesini değiştirip parlaklık için kullanabiliriz.
  ------------------------------------------------------------------------------
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int brightness = map(potentiometerValue, 0, 1023, 0, 255);
  analogWrite(LED_PIN, brightness);
*/