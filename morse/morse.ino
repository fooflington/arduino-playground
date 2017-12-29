#define PIN_OUT 5
#define PIN_ERR 7
#define PIN_READY 4

#define BASE_TIME 75

#define DOT        1
#define DASH       3
#define GAP        1
#define LETTER_GAP 3
#define WORD_GAP   7

#define DO_DOT pulse(DOT)
#define DO_DASH pulse(DASH);

/* char *message = "SOS Help us"; */

void pulse(byte t) {
  digitalWrite(PIN_OUT, HIGH);
  delay(t * BASE_TIME);
  digitalWrite(PIN_OUT, LOW);
  delay(GAP * BASE_TIME);
}

void pulseError() {
  digitalWrite(PIN_ERR, HIGH);
  delay(GAP * BASE_TIME);
  digitalWrite(PIN_ERR, LOW);
}

void writeChar(char c) {

  if (c >= 'a' && c <= 'z') c -= 'a' - 'A';
  switch (c) {
    case ' ':
      delay(WORD_GAP * BASE_TIME);
      break;

    case 'A':
      pulse(DOT);
      pulse(DASH);
      break;
    case 'B':
      pulse(DASH);
      pulse(DOT);
      pulse(DOT);
      break;

    case 'C':
      pulse(DASH);
      pulse(DOT);
      pulse(DASH);
      pulse(DOT);
      break;

    case 'D':
      pulse(DASH);
      pulse(DOT);
      pulse(DOT);
      break;

    case 'E':
      pulse(DOT);
      break;

    case 'F':
      DO_DOT;
      DO_DOT;
      DO_DASH;
      DO_DOT;
      break;

    case 'G':
      DO_DASH;
      DO_DASH;
      DO_DOT;
      break;

    case 'H':
      DO_DOT;
      DO_DOT;
      DO_DOT;
      DO_DOT;
      break;

    case 'I':
      DO_DOT;
      DO_DOT;
      break;

    case 'J':
      DO_DOT;
      DO_DASH;
      DO_DASH;
      DO_DASH;
      break;

    case 'K':
      DO_DASH;
      DO_DOT;
      DO_DASH;
      break;

    case 'L':
      DO_DOT;
      DO_DASH;
      DO_DOT;
      DO_DOT;
      break;

    case 'M':
      DO_DASH;
      DO_DASH;
      break;

    case 'N':
      DO_DASH;
      DO_DOT;
      break;

    case 'O':
      DO_DASH;
      DO_DASH;
      DO_DASH;
      break;

    case 'P':
      DO_DOT;
      DO_DASH;
      DO_DASH;
      DO_DOT;
      break;

    case 'Q':
      DO_DASH;
      DO_DASH;
      DO_DOT;
      DO_DASH;
      break;

    case 'S':
      DO_DOT;
      DO_DOT;
      DO_DOT;
      break;

    case 'T':
      DO_DASH;
      break;

    case 'U':
      DO_DOT;
      DO_DOT;
      DO_DASH;
      break;

    case 'V':
      DO_DOT;
      DO_DOT;
      DO_DOT;
      DO_DASH;
      break;

    case 'W':
      DO_DOT;
      DO_DASH;
      DO_DASH;
      break;

    case 'X':
      DO_DASH;
      DO_DOT;
      DO_DOT;
      DO_DASH;
      break;

    case 'Y':
      DO_DASH;
      DO_DOT;
      DO_DASH;
      DO_DASH;
      break;

    case 'Z':
      DO_DASH;
      DO_DASH;
      DO_DOT;
      DO_DOT;
      break;

    default:
      pulseError();
  }

  delay(LETTER_GAP * BASE_TIME);
}

void writeStr(char *msg) {
  for (int c = 0; c < strlen(msg); c++) {
    writeChar(msg[c]);
  }
}

void setup() {
  pinMode(PIN_OUT, OUTPUT);
  digitalWrite(PIN_OUT, LOW);
  pinMode(PIN_ERR, OUTPUT);
  digitalWrite(PIN_ERR, LOW);
  pinMode(PIN_READY, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  writeStr("SOS sos 2");
  delay(2000);
}

