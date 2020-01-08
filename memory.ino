// A simple memory game.
// Repeat the color pattern that is dsplayed.

// The length of the pattern to win with
const int winLength = 10;

const int N_LAMPS = 3;
const int LIGHT_ONE_OUT = 13;
const int LIGHT_ONE_IN = 2;

int pattern[winLength];
int level;

void setup() {
  level = 1;
  generatePattern(pattern);

  pinMode(LIGHT_ONE_OUT, OUTPUT);
  pinMode(LIGHT_ONE_IN, INPUT);

  // debug light
  pinMode(8, OUTPUT);
}

void loop() {
  //digitalWrite(LIGHT_ONE_OUT, HIGH);

  if (digitalRead(LIGHT_ONE_IN) == HIGH) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
}

void generatePattern(int arr[]) {
  for (int i = 0; i < winLength; i++) {
    arr[i] = random(N_LAMPS);
  }
}
