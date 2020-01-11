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
const int LIGHT_ONE_IN = 5;
const int LIGHT_TWO_IN = 4;
const int LIGHT_THREE_IN = 3;
const int LIGHT_INPUTS[N_LAMPS] = {LIGHT_ONE_IN, LIGHT_TWO_IN, LIGHT_THREE_IN};

int pattern[winLength];
int level;

// Debug
const int DEBUG_LIGHT = 9;

void setup()
{
  level = 1;
  generatePattern(pattern);

  // Out
  pinMode(LIGHT_ONE_OUT, OUTPUT);
  pinMode(LIGHT_TWO_OUT, OUTPUT);
  pinMode(LIGHT_THREE_OUT, OUTPUT);
  pinMode(DEBUG_LIGHT, OUTPUT);

  // In
  pinMode(LIGHT_ONE_IN, INPUT);
  pinMode(LIGHT_TWO_IN, INPUT);
  pinMode(LIGHT_THREE_IN, INPUT);
}

/**
 * @return the corresponding output pin when given a input pin. Returns -1 if there is not corresponding output pin. 
 */
int getCorrespondingOutputPin(int inputPin)
{
  // TODO: Replace with a hash table.
  switch (inputPin)
  {
  case LIGHT_ONE_IN:
    return LIGHT_ONE_OUT;
    break;
  case LIGHT_TWO_IN:
    return LIGHT_TWO_OUT;
    break;
  case LIGHT_THREE_IN:
    return LIGHT_THREE_OUT;
    break;
  default:
    return -1;
  }
}

void loop()
{
  displayStart();
  displayPattern();
  getInput();
  level += 1;
}

void debugLightOn()
{
  digitalWrite(DEBUG_LIGHT, HIGH);
}

void debugLightOff()
{
  digitalWrite(DEBUG_LIGHT, LOW);
}

/**
 * Returns the next input light pin that is pressed AND released.
 * 
 * @return the next input light pin that is pressed AND released.
 */
int getNextLightInput()
{
  int pressedInput = -1;
  while (pressedInput < 0)
    for (int j = 0; j < (sizeof(LIGHT_INPUTS) / sizeof(int)); j++)
      if (digitalRead(LIGHT_INPUTS[j]) == HIGH)
      {
        debugLightOff();
        pressedInput = LIGHT_INPUTS[j];
      }

  while (true)
    if (digitalRead(pressedInput) == LOW)
      return pressedInput;
}

/**
 * Returns an array with the light input pins.
 * 
 * @return an array with the light input pins.
 */
int getInput()
{
  int input[level];

  for (int i = 0; i < level; i++)
  {
    debugLightOn();
    input[i] = getNextLightInput();
  }

  return -1;
}

/**
 * Checks if two arrays are equal up to a specific index.
 * 
 * @param a1 array 1.
 * @param a2 array 2.
 * @param toIndex the max index to compare.
 */
bool arrayEquals(int a1[], int a2[], int toIndex)
{
  for (int i = 0; i <= toIndex; i++)
    if (a1[i] != a2[i])
      return false;

  return true;
}

/**
 * Displays the start of the pattern.
 */
void displayStart()
{
  int sleepTime = 1000;

  allLightsOff();
  delay(sleepTime);
  allLightsOn();
  delay(sleepTime);
  allLightsOff();
  delay(sleepTime);
}

void allLightsOff()
{
  setAllLightsTo(LOW);
}

void allLightsOn()
{
  setAllLightsTo(HIGH);
}

void setAllLightsTo(int lightStatus)
{
  digitalWrite(LIGHT_ONE_OUT, lightStatus);
  digitalWrite(LIGHT_TWO_OUT, lightStatus);
  digitalWrite(LIGHT_THREE_OUT, lightStatus);
}

/**
 * Displays the pattern.
 */
void displayPattern()
{
  int sleepTime = 500;
  for (int i = 0; i < level; i++)
  {
    digitalWrite(pattern[i], HIGH);
    delay(sleepTime);
    digitalWrite(pattern[i], LOW);
    delay(sleepTime);
  }
}

/**
 * Generates the pattern to repeat.
 * 
 * @param arr[] the array populate.
 */
void generatePattern(int arr[])
{
  randomSeed(analogRead(0));

  for (int i = 0; i < winLength; i++)
  {
    int arraySize = (sizeof(LIGHT_OUTPUTS) / sizeof(int));
    int index = random(3);
    arr[i] = LIGHT_OUTPUTS[index];
  }
}
