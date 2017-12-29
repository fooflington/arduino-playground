#define PIN_OUT 5
#define BASE_TIME 50

#define DOT        1
#define DASH       3
#define GAP        1
#define LETTER_GAP 3
#define WORD_GAP   7

void pulse(int t) {
  digitalWrite(PIN_OUT, HIGH);
  delay(t * BASE_TIME);
  digitalWrite(PIN_OUT, LOW);
}

void setup() {
  pinMode(PIN_OUT, OUTPUT);
  digitalWrite(PIN_OUT, LOW);
}

void loop() {
  
}

