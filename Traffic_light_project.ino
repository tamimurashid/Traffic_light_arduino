// Traffic light pins
int trafficLights[4][3] = {
  {1, 2, 3},   // Side 1: Green, Yellow, Red
  {4, 5, 6},   // Side 2: Green, Yellow, Red
  {7, 8, 9},   // Side 3: Green, Yellow, Red
  {10, 11, 12}  // Side 4: Green, Yellow, Red
};

void setup() {
  // Set all LED pins as output
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      pinMode(trafficLights[i][j], OUTPUT);
      digitalWrite(trafficLights[i][j], LOW); // Turn off all
    }
  }
}

// Turn on Red for specific sides
void setRed(int side1, int side2) {
  digitalWrite(trafficLights[side1][0], LOW);  // Green OFF
  digitalWrite(trafficLights[side1][1], LOW);  // Yellow OFF
  digitalWrite(trafficLights[side1][2], HIGH); // Red ON

  digitalWrite(trafficLights[side2][0], LOW);
  digitalWrite(trafficLights[side2][1], LOW);
  digitalWrite(trafficLights[side2][2], HIGH);
}

// Turn on Green for specific sides
void setGreen(int side1, int side2) {
  digitalWrite(trafficLights[side1][2], LOW);  // Red OFF
  digitalWrite(trafficLights[side1][1], LOW);  // Yellow OFF
  digitalWrite(trafficLights[side1][0], HIGH); // Green ON

  digitalWrite(trafficLights[side2][2], LOW);
  digitalWrite(trafficLights[side2][1], LOW);
  digitalWrite(trafficLights[side2][0], HIGH);
}

// Turn on Yellow for specific sides
void setYellow(int side1, int side2) {
  digitalWrite(trafficLights[side1][0], LOW);  // Green OFF
  digitalWrite(trafficLights[side1][1], HIGH); // Yellow ON
  digitalWrite(trafficLights[side1][2], LOW);  // Red OFF

  digitalWrite(trafficLights[side2][0], LOW);
  digitalWrite(trafficLights[side2][1], HIGH);
  digitalWrite(trafficLights[side2][2], LOW);
}

void loop() {
  // Phase 1: North & South = Green | East & West = Red
  setRed(1, 3);    // East & West
  setGreen(0, 2);  // North & South
  delay(5000);     // Green duration

  // Yellow before changing
  setYellow(0, 2);
  delay(2000);

  // Phase 2: East & West = Green | North & South = Red
  setRed(0, 2);    // North & South
  setGreen(1, 3);  // East & West
  delay(5000);     // Green duration

  // Yellow before changing
  setYellow(1, 3);
  delay(2000);
}
