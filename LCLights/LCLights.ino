
#define PIN_LED_GREEN 4
#define PIN_LED_LEFT  5
#define PIN_LED_RIGHT 6
#define PIN_WARNING   7

#define PIN_TRIGGER 8
#define PIN_FINISH  9

#define RUN_HEARTBEAT
/* #define DEBUG */

void setup() 
{
#ifdef RUN_HEARTBEAT
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
#endif

#ifdef DEBUG
  Serial.begin(9600);
  Serial.println("\n\n***\nSetting up...");
#endif
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_LEFT, OUTPUT);
  pinMode(PIN_LED_RIGHT, OUTPUT);
  pinMode(PIN_WARNING, OUTPUT);
  pinMode(PIN_TRIGGER, INPUT_PULLUP);
  pinMode(PIN_FINISH, INPUT_PULLUP);

  digitalWrite(PIN_LED_GREEN, HIGH);
  digitalWrite(PIN_LED_LEFT, LOW);
  digitalWrite(PIN_LED_RIGHT, LOW);
  digitalWrite(PIN_WARNING, LOW);
#ifdef DEBUG
  Serial.println("Setup done");
#endif

#ifdef RUN_HEARTBEAT
  digitalWrite(LED_BUILTIN, HIGH);
#endif
}

#define DELAY 500 /* ms */
#define PIN_OFFSET 5
void runLights(int t, byte finisher) {

#ifdef DEBUG
  Serial.println("Lights starting");
#endif

  digitalWrite(PIN_WARNING, HIGH);
  delay(2000);
  digitalWrite(PIN_WARNING, LOW);

  digitalWrite(PIN_LED_LEFT, HIGH);
  digitalWrite(PIN_LED_RIGHT, HIGH);
  delay(1000);
  digitalWrite(PIN_LED_LEFT, LOW);
  digitalWrite(PIN_LED_RIGHT, LOW);

  bool cur = 0;
  do {
    digitalWrite(PIN_OFFSET + cur, HIGH);
    delay(DELAY);
    digitalWrite(PIN_OFFSET + cur, LOW);
    t -= DELAY;
    cur = !cur;
  } while(t > 0);

#ifdef DEBUG
  Serial.println("Lights done");
#endif
}

#ifdef DEBUG
int n = 0;
#endif

#ifdef RUN_HEARTBEAT
byte looper = 0;
bool heartbeat_state = HIGH;
#endif

void loop() 
{
#ifdef RUN_HEARTBEAT
  if(looper++ == 0) {
    heartbeat_state = ! heartbeat_state;
    digitalWrite(LED_BUILTIN, heartbeat_state);
  }
#endif

#ifdef DEBUG
  Serial.print("Polling trigger n=");
  Serial.println(n++);
#endif

  if (digitalRead(PIN_TRIGGER) == LOW)
  {
#ifdef DEBUG
    Serial.println("Running lights...");
#endif
    digitalWrite(PIN_LED_GREEN, LOW);
    runLights(10 * 1000, PIN_FINISH);
    delay(DELAY);
    digitalWrite(PIN_LED_GREEN, HIGH);
  }
  delay(5);

}
