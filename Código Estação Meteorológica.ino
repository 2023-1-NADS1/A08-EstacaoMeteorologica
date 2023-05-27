//pinos do display
#define RS 12
#define EN 11
#define D4  4
#define D5  5
#define D6  6
#define D7  7

#define INTERVALO 5000

//objeto para o sensor DHT22 e DIsplay LCD
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
DHT dht(DHT_PIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("INICIANDO SISTEMA");
  dht.begin();

  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(2, 0);
 
  lcd.print("INIT SYSTEM");

  delay(3000);
}

void loop() {

//dados do sensor
  float h = 0, t = 0, f = 0;

  // umidade
  h = dht.readHumidity();
  // temperatura
  t = dht.readTemperature();
  // Fórmula para converter a temperatura para graus Farenheit
  f = dht.readTemperature(true);

  // Lógica para eliminar resultados indesejados
  if(isnan(h) || isnan(t) || t == 0 || h == 0){
    Serial.println(F("Falha na leitura do sensor"));
  }
  else{
    // Temperatura
    Serial.print(t);
    Serial.print(",");

    // Umidade
    Serial.print(h);
    Serial.print(",");

    Serial.print(f);
    Serial.print(",");
    Serial.println();

    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("MONITORANDO");  
    lcd.setCursor(0, 1);
    lcd.print(t);
    lcd.print("C  ");
    lcd.print(h);
    lcd.print("%RH  ");
  }
  delay(INTERVALO);  
}