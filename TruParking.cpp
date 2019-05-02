#include <SharpIR.h>
#include <Time.h>

#define ir A0
#define ir2 A1
#define model 100500

SharpIR Sensor1 = SharpIR(ir, model);
SharpIR Sensor2 = SharpIR(ir2, model);

boolean sensorA_isBroken = false;
boolean sensorB_isBroken = false;

boolean sensorABroken_isLogged = false;
boolean sensorAUnbroken_isLogged = false;

boolean sensorBBroken_isLogged = false;
boolean sensorBUnbroken_isLogged = false;

boolean sensorA_isFirst = false;
boolean sensorB_isFirst = false;

long time_A_Broke = 0;
long time_A_Unbroke = 0;
long time_B_Broke = 0;
long time_B_Unbroke = 0;

boolean isEntrance = true;

long time = 0;


void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  delay(500);   

  int disA = Sensor1.distance();  // this returns the distance to the object you're measuring
  int disB = Sensor2.distance(); // this returns the distance to the object you're measuring
  
  if ((disA < 250) && (disA >= 1))
  {
    sensorA_isBroken = true;
    
    if (!sensorABroken_isLogged)
    {
      time_A_Broke = millis();
      //Serial.println("A Broken: ");
      //Serial.println(disA);
      sensorABroken_isLogged = true;
      sensorAUnbroken_isLogged = false;
    }
  }
  
  else if ((disA >= 250) || (disA == 0))
  {
    sensorA_isBroken = false;
    
    if (!sensorAUnbroken_isLogged)
    {
      time_A_Unbroke = millis();
      //Serial.println("A unbroken: ");
      //Serial.println(disA);
      sensorAUnbroken_isLogged = true;
      sensorABroken_isLogged = false;
    }
  }
  
  if ((disB < 250) && (disB >= 1))
  {
    sensorB_isBroken = true;
    
    if (!sensorBBroken_isLogged)
    {
      time_B_Broke = millis();
      //Serial.println("B Broken: ");
      //Serial.println(disB);
      sensorBBroken_isLogged = true;
      sensorBUnbroken_isLogged = false;
    }
  }
  
  else if ((disB >= 250) || (disB == 0))
  {
    sensorB_isBroken = false;
    
    if (!sensorBUnbroken_isLogged)
    {
      time_B_Unbroke = millis();
      //Serial.println("B unbroken: ");
      //Serial.println(disB);
      sensorBUnbroken_isLogged = true;
      sensorBBroken_isLogged = false;
    }
  }

  if ((time_B_Broke > time_A_Broke) && (time_B_Broke < time_A_Unbroke))
  {
    isEntrance = true;
    time = time_B_Broke;
    
    //Serial.print("\tEntrance at");
    Serial.println("E ");
    //Serial.println(time);
    
    time_A_Broke = 0;
    time_A_Unbroke = 0;
    //time_B_Broke = 0;
    time_B_Unbroke = 0;
    //delay(1000);
    //take pic
    //send(isEntrance, time, pic)
  }
  
  if ((time_A_Broke > time_B_Broke) && (time_A_Broke < time_B_Unbroke))
  {
    isEntrance = false;
    time = time_A_Broke;
    
    //Serial.print("\tExit at");
    Serial.println("X ");
    //Serial.println(time);
    
    //time_A_Broke = 0;
    time_A_Unbroke = 0;
    time_B_Broke = 0;
    time_B_Unbroke = 0;
    //delay(1000);
    //take pic
    //send(isEntrance, time, pic)
  }
}
