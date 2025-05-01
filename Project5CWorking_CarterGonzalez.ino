/* Project 5C - Pedestrian Traffic Lights
   By: Carter Gonzalez 4/21/2025 */
#define westButton 4
#define eastButton 2
#define westRed 13
#define westYellow 12
#define westGreen 11
#define eastRed 7
#define eastYellow 6
#define eastGreen 5
#define pedButton 8
#define westBlue 9
#define eastBlue 9

void changeYellowLight(int yellowDirection);

void changeGreenToRed(int greenDirection, int yellowDirection, int redDirection);

void changeRedToGreen(int greenDirection, int yellowDirection, int redDirection);

void changeToPedestrian(int greenDirection, int yellowDirection, int redDirection, int blueDirection);


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

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(pedButton) == LOW)  // If pedestrian light low, normal traffic procedure
  {
    if (digitalRead(westButton) == HIGH && trafficWest == true) {
      Serial.println("WEST");

      trafficWest != true;
      changeGreenToRed(westGreen, westYellow, westRed);  // Function changing green light to red light
      changeYellowLight(eastYellow);
      changeRedToGreen(eastGreen, eastYellow, eastRed);
    }
  
     else if (digitalRead(westButton) == LOW && trafficWest != true) {
        Serial.println("EAST");
          trafficWest = true;
          changeGreenToRed(westGreen, westYellow, westRed);
          changeYellowLight(westYellow);
          changeRedToGreen(eastGreen, eastYellow, eastRed);
      }
    
    /*if (digitalRead(pedButton) == HIGH) {
      //if (trafficWest) // turn off westGreen
      //else // turn off eastGreen
      changeToPedestrian(westGreen, westYellow, westRed, westBlue);
      changeToPedestrian(eastGreen, eastYellow, eastRed, eastBlue);
    }*/
  }
   else if (digitalRead(pedButton) == HIGH)  // If pedestrian light high, ped lights turn on
    {
      Serial.println("PED");
       changeToPedestrian(westBlue, westGreen, westYellow, westRed);
       changeToPedestrian(eastBlue, eastGreen, eastYellow, eastRed);  }
}
void changeToPedestrian(int blueDirection, int greenDirection, int yellowDirection, int redDirection) {  // Defines function for pedestrian light


  /*delay(flowTime);
  digitalWrite(greenDirection, LOW);
  digitalWrite(yellowDirection, LOW);
  delay(changeDelay);
  digitalWrite(yellowDirection, LOW);
  digitalWrite(redDirection, HIGH);
  delay(changeDelay);*/

  changeGreenToRed(greenDirection, yellowDirection, redDirection);
  digitalWrite(blueDirection, HIGH);
  digitalWrite(blueDirection, HIGH);
  delay(changeDelay);
   digitalWrite(blueDirection, LOW);
  digitalWrite(blueDirection, LOW);
}
void changeYellowLight(int yellowDirection) {  // Defines function of how yellow light changes
  for (int a = 0; a < 5; a++) {
    digitalWrite(yellowDirection, LOW);
    delay(yellowBlinkTime);
    digitalWrite(yellowDirection, HIGH);
    delay(yellowBlinkTime);
    digitalWrite(yellowDirection, LOW);
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
  digitalWrite(yellowDirection, LOW);
  digitalWrite(redDirection, LOW);
  digitalWrite(greenDirection, HIGH);
}
