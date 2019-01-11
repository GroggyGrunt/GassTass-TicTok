#include <SimpleTimer.h>

const int OUT_0_PIN = 0;
const int OUT_1_PIN = 1;
const int OUT_2_PIN = 2;
const int OUT_3_PIN = 3;
const int OUT_4_PIN = 4;
const int OUT_5_PIN = 5;
const int OUT_6_PIN = 6;
const int OUT_7_PIN = 7;

const int divider0 = 1;
const int divider1 = 2;
const int divider2 = 3;
const int divider3 = 4;
const int divider4 = 5;
const int divider5 = 6;
const int divider6 = 7;
const int divider7 = 8;

int bpm = 120;
int cyclePeriod = 60000 / bpm / 4;
unsigned long count = 0;
bool started = false;

SimpleTimer timer;

void cycleOn();
void cycleOff();

void setup() {
  pinMode(OUT_0_PIN, OUTPUT);
  pinMode(OUT_1_PIN, OUTPUT);
  pinMode(OUT_2_PIN, OUTPUT);
  pinMode(OUT_3_PIN, OUTPUT);
  pinMode(OUT_4_PIN, OUTPUT);
  pinMode(OUT_5_PIN, OUTPUT);
  pinMode(OUT_6_PIN, OUTPUT);
  pinMode(OUT_7_PIN, OUTPUT);
}

void loop() {
  if (!started) {
    cycleOn();
    started = true;
  }

  timer.run();
}

void cycleOn() {
  digitalWrite(OUT_0_PIN, !(count % divider0));
  digitalWrite(OUT_1_PIN, !(count % divider1));
  digitalWrite(OUT_2_PIN, !(count % divider2));
  digitalWrite(OUT_3_PIN, !(count % divider3));
  digitalWrite(OUT_4_PIN, !(count % divider4));
  digitalWrite(OUT_5_PIN, !(count % divider5));
  digitalWrite(OUT_6_PIN, !(count % divider6));
  digitalWrite(OUT_7_PIN, !(count % divider7));
  
  timer.setTimeout(cyclePeriod, cycleOn);
  timer.setTimeout(2, cycleOff); // 2ms trigger length
}

void cycleOff() {
  digitalWrite(OUT_0_PIN, LOW);
  digitalWrite(OUT_1_PIN, LOW);
  digitalWrite(OUT_2_PIN, LOW);
  digitalWrite(OUT_3_PIN, LOW);
  digitalWrite(OUT_4_PIN, LOW);
  digitalWrite(OUT_5_PIN, LOW);
  digitalWrite(OUT_6_PIN, LOW);
  digitalWrite(OUT_7_PIN, LOW);

  count++;
}