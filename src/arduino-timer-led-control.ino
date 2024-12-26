const byte grnLed = 3;
const byte orgLed = 4;
const byte redLed = 5;

volatile int Overflow = 0;

const byte btn = 2;

bool redState = false;
bool grnLedState = false;
bool orgLedState = false;

void setup() {
  for (byte i = 3; i <= 5; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(btn, INPUT);

  attachInterrupt(digitalPinToInterrupt(btn), redControl, RISING);

  // Timer1
  cli();
  TCCR1A = 0; 
  TCCR1B = 0;
  OCR1A = 7812;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);

  // Timer2
  TCCR2A = 0;
  TCCR2B = 0;
  TIMSK2 |= (1 << TOIE2);
  TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); 
  TCNT2 = 0;

  TIMSK1 = (1 << OCIE1A);
  sei();
}

void loop() {
}

ISR(TIMER1_COMPA_vect) {
  grnLedState = !grnLedState;
  digitalWrite(grnLed, grnLedState);
}

ISR(TIMER2_OVF_vect) {
  Overflow++;
  if(Overflow == 152){
    orgLedState = !orgLedState;
    digitalWrite(orgLed, orgLedState);
    Overflow = 0;
  }
}

void redControl() {
  redState = !redState;
  digitalWrite(redLed, redState);
}
