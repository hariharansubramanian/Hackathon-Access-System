int GREEN_LED_1 = 6;
int GREEN_LED_2 = 7;
int GREEN_LED_3 = 8;
int GREEN_LED_4 = 9;

int RED_LED_1 = 10;
int RED_LED_2 = 11;
int RED_LED_3 = 12;
int RED_LED_4 = 13;

char isLoveProgramming;
char isParticipating;
char isOrganizing;
char isSolveCodePuzzle;

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println("Were you part of the organizing team for today's Hack-a-thon?(y/n)");
  while (Serial.available() == 0) { }
  isOrganizing = Serial.read();
  Serial.println(isOrganizing);
  Serial.println("\n");

  Serial.println("Do you Love writing code?(y/n)");
  while (Serial.available() == 0) { }
  isLoveProgramming = Serial.read();
  Serial.println(isLoveProgramming);
  Serial.println("\n");

  Serial.println("Are you participating in today's Hack-a-thon?(y/n)");
  while (Serial.available() == 0) { }
  isParticipating = Serial.read();
  Serial.println(isParticipating);
  Serial.println("\n");

  Serial.println("Do you want to attempt a code puzzle?(y/n)[optional]");
  while (Serial.available() == 0) { }
  isSolveCodePuzzle = Serial.read();
  Serial.println(isSolveCodePuzzle);
  if (isSolveCodePuzzle == 'Y' || isSolveCodePuzzle == 'y') {
    doCodeChallenge();
    handleAccess();
  } else {
    Serial.println("\nThats alright :) maybe next time!");
    handleAccess();
  }
}


void handleAccess() {
  if (isLoveProgramming == 'Y'
      || isLoveProgramming == 'y'
      || isParticipating == 'Y'
      || isParticipating == 'y'
      || isOrganizing == 'Y'
      || isOrganizing == 'y') {
    grantEntry();
  } else {
    denyEntry();
  }
}

void doCodeChallenge() {

  Serial.println("\n----------WHAT IS THE PRINT OUTPUT?----------");
  Serial.println("\n  int x = 10;");
  Serial.println("  int y = 10;");
  Serial.println("  if( !(x^y) )");
  Serial.println("    printf(\"x is equal to y\");");
  Serial.println("  else");
  Serial.println("    printf(\"x is not equal to y\");");

  Serial.println("\n----------ANSWER CHOICES----------");
  Serial.println("Enter \"1\" for: \"x is equal to y\"");
  Serial.println("Enter \"2\" for: \"x is not equal to y\"");

  while (Serial.available() == 0) { }
  char codePuzzleAnswer = Serial.read();
  if (codePuzzleAnswer == '1') {
    Serial.println("\nSPOT ON! Right answer!\n");
  } else {
    Serial.println("\nSORRY! Wrong answer!\n");
  }
}
void grantEntry() {
  ClearRedLED();
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  Serial.println("\n----------ACCESS GRANTED!!----------\nYou are worthy to enter!\n\n");
}

void denyEntry() {
  ClearGreenLED();
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  Serial.println("\n----------ACCESS DENIED!!----------\nBoo-hoo..GO BACK HOME!!\n\n");
}


void ClearGreenLED() {
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void ClearRedLED() {
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}
