// A simple color memory game.
// Repeat the color pattern that is dsplayed.

// The length of the pattern to win with
const int winLength = 10;

// remove and retrieve from the size of tthe LIGHT_OUTPUTS arr.
const int N_LAMPS = 3;

// Out
const int LIGHT_ONE_OUT = 13;
const int LIGHT_TWO_OUT = 12;
const int LIGHT_THREE_OUT = 11;

const int LIGHT_OUTPUTS[N_LAMPS] = {LIGHT_ONE_OUT, LIGHT_TWO_OUT, LIGHT_THREE_OUT};

// Input
const int LIGHT_ONE_IN = 4;
const int LIGHT_TWO_IN = 3;
const int LIGHT_THREE_IN = 2;

int pattern[winLength];
int level;

void setup() {
  level = 6;
  generatePattern(pattern);

  // Out
  pinMode(LIGHT_ONE_OUT, OUTPUT);
  pinMode(LIGHT_TWO_OUT, OUTPUT);
  pinMode(LIGHT_THREE_OUT, OUTPUT);

  // In
  pinMode(LIGHT_ONE_IN, INPUT);
  pinMode(LIGHT_TWO_IN, INPUT);
  pinMode(LIGHT_THREE_IN, INPUT);
}

void loop() {
  displayStart();
  displayPattern();
}

/**
 * Displays the start of the pattern.
 */
void displayStart() {
  int sleepTime = 1000;

  allLightsOff();
  delay(sleepTime);
  allLightsOn();
  delay(sleepTime);
  allLightsOff();
  delay(sleepTime);
}

void allLightsOff() {
  setAllLightsTo(LOW);
}

void allLightsOn() {
  setAllLightsTo(HIGH);
}

void setAllLightsTo(int lightStatus) {
  digitalWrite(LIGHT_ONE_OUT, lightStatus);
  digitalWrite(LIGHT_TWO_OUT, lightStatus);
  digitalWrite(LIGHT_THREE_OUT, lightStatus);
}

/**
 * Displays the pattern.
 */
void displayPattern() {
  int sleepTime = 500;
  for (int i = 0; i < level; i++) {
    digitalWrite(pattern[i], HIGH);
    delay(sleepTime);
    digitalWrite(pattern[i], LOW);
    delay(sleepTime);
  }
}

/**
 * Generates the pattern to repeat.
 * @arr[] the array populate.
 */
void generatePattern(int arr[]) {
  randomSeed(analogRead(0));

  for (int i = 0; i < winLength; i++) {
    int arraySize = (sizeof(LIGHT_OUTPUTS) / sizeof(int));
    int index = random(3);
    arr[i] = LIGHT_OUTPUTS[index];
  }
}
