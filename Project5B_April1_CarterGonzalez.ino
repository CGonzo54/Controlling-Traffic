/* Project 5B - Traffic Lights
   By: Carter Gonzalez 4/1/2025 */
#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10

void changeYellowLight(int yellowDirection);

void changeGreenToRed(int greenDirection, int yellowDirection, int redDirection);

void changeRedToGreen(int greenDirection, int yellowDirection, int redDirection);


#define yellowBlinkTime 500

boolean trafficWest = true;  // west = true, east = false
int flowTime = 10000;
int changeDelay = 2000;



void setup() {
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);

  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}

void loop() {
  if (digitalRead(westButton) == HIGH) {
    if (trafficWest != true) {
      trafficWest = true;
      /* delay(flowTime);
      digitalWrite(eastGreen, LOW);

      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, HIGH);
      delay(changeDelay); */
      changeGreenToRed(eastGreen, eastYellow, eastRed);  // Function changing green light to red light

      /*for ( int a = 0; a < 5; a++)
      {
        digitalWrite(westYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(westYellow, HIGH);
        delay(yellowBlinkTime);
      } */
      changeYellowLight(westYellow); // 

      /*digitalWrite(westYellow, LOW);
      digitalWrite(westRed, LOW);
      digitalWrite(westGreen, HIGH); */
      
      changeRedToGreen(westGreen, westYellow, westRed);
    }
  }
  if (digitalRead(eastButton) == HIGH) {
    if (trafficWest == true) {
      trafficWest = false;
      /*delay(flowTime);
      digitalWrite(westGreen, LOW);
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, HIGH);
      delay(changeDelay); */
      changeGreenToRed(westGreen, westYellow, westRed);
      /*for (int a = 0; a < 5; a++) {
        digitalWrite(eastYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(eastYellow, HIGH);
        delay(yellowBlinkTime);
      } */
      changeYellowLight(eastYellow);

      /*digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, LOW);
      digitalWrite(eastGreen, HIGH); */
      changeRedToGreen(eastGreen, eastYellow, eastRed);
    }
  }
}
void changeYellowLight(int yellowDirection) {  // Defines function of how yellow light changes
  for (int a = 0; a < 5; a++) {
    digitalWrite(yellowDirection, LOW);
    delay(yellowBlinkTime);
    digitalWrite(yellowDirection, HIGH);
    delay(yellowBlinkTime);
  }
}

void changeGreenToRed(int greenDirection, int yellowDirection, int redDirection)  // Defines the function of how green changes to red
{
  delay(flowTime);
  digitalWrite(greenDirection, LOW);

  digitalWrite(yellowDirection, HIGH);
  delay(changeDelay);
  digitalWrite(yellowDirection, LOW);
  digitalWrite(redDirection, HIGH);
  delay(changeDelay);
}

void changeRedToGreen(int greenDirection, int yellowDirection, int redDirection)  // Defines function of how light changes to green
{
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastRed, LOW);
  digitalWrite(eastGreen, HIGH);
}
