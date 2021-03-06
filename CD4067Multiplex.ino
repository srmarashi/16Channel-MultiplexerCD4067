//16 channels cd4067 Library Free changes by: S.R.Marashi   srmarashi@yahoo.com
// Here is pinout for 16-Channel-Multiplexer CD4067 MultiPlexer Digital To analog
// S0 --> Arduino Digital 3
// S1 --> Arduino Digital 4
// S2 --> Arduino Digital 5
// S3 --> Arduino Digital 6
// E --> Arduino Digital 2
// Z --> Arduino analog A0
// VEE/GND --> Arduino GND (Connect Both of them to GND)
// VCC --> Arduino +5V
// Y0 to Y15 --> Analog Extended Pins

const byte ENPIN = 2; //Enable pin
const byte APIN = 3; //S0
const byte BPIN = 4; //S1
const byte CPIN = 5; //S2
const byte DPIN = 6; //S3


// an analog pin need to Cycle Digital Pins
const byte SPIN = A0;

void setup() {

  //  pins out and LOW
  pinMode(APIN, OUTPUT);
  pinMode(BPIN, OUTPUT);
  pinMode(CPIN, OUTPUT);
  pinMode(DPIN, OUTPUT);
  digitalWrite(APIN, LOW);
  digitalWrite(BPIN, LOW);
  digitalWrite(CPIN, LOW);
  digitalWrite(DPIN, LOW);

  // Enable pin should have Voltage for activating module
  pinMode(ENPIN, OUTPUT);
  digitalWrite(ENPIN, LOW);

  Serial.begin(9600);
  Serial.println("1 analog and 3 Digital pins give 16 ANALOG Low precision PIN ");
}

void loop()
{

  // for example pin0 and pin15 will read continusely and will print out analog Result Valuue
  Serial.println(CycleRecall(15));
  Serial.println("----------");
  delay(100);
}


// reading function for the CD4067B
int CycleRecall(byte channel) {

  digitalWrite(APIN, bitRead(channel, 0));
  digitalWrite(BPIN, bitRead(channel, 1));
  digitalWrite(CPIN, bitRead(channel, 2));
  digitalWrite(DPIN, bitRead(channel, 3));
  
  //Cyle ReCall
  return analogRead(SPIN);
}
