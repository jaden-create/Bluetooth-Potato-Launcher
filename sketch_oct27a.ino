int pwm = 12; // assigns pin 12 to variable pwm
int pot = A0; // assigns analog input A0 to variable pot
int t1 = 0;   // declares variable t1
int t2 = 0;   // declares variable t2
int var = 0;
char incoming_var = 0;
void setup()  // setup loop
{
  pinMode(pwm, OUTPUT); // declares pin 12 as output
  pinMode(pot, INPUT);
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available() > 0)
  {
    incoming_var = Serial.read();
    Serial.print(incoming_var);
    Serial.print("\n");
    if(incoming_var == '1'){
      while(incoming_var == '1'){
        t2= analogRead(pot); // reads the voltage at A0 and saves in t2
        t1= 1000-t2;         // subtracts t2 from 1000 ans saves the result in t1
        digitalWrite(pwm, HIGH); // sets pin 12 HIGH
        delayMicroseconds(t1);   // waits for t1 uS (high time)
        digitalWrite(pwm, LOW);  // sets pin 12 LOW
        delayMicroseconds(t2);   // waits for t2 uS (low time
        var = var + 1;
        
        if(var == 2000){
          incoming_var = "0";
          }
      }
      Serial.print("done");
      var=0;
      }
      
  }
  }
