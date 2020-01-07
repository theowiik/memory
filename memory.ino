// A simple memory game.
// Repeat the color pattern that is dsplayed.

// The length of the pattern to win with
const int winLength = 10;

const int nLamps = 3;

// The pattern to repeat
// Contains indices of the combination.. 0 = "lamp 1" 
int pattern[winLength];

// The amount of lights to remember.
int level;

void setup() {
  level = 1;
  generatePattern(pattern);
}

void loop() {
  printPattern();
  
  // get input
  // if input matches pattern:
  //   level++;

  if (level > winLength) {
    win();
  }
}

void generatePattern(int arr[]) {
  for (int i = 0; i < winLength; i++) {
    arr[i] = random(nLamps);
  }
}
