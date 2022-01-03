#include<serial_debug1.h>

Debug debugObj(Serial);

Debug debugObj1(Serial1);

void setup() 
{
  Serial.begin(9600); 
  debugObj.DEBUGLN("Debug init Serial...");  
  debugObj.SEPARATOR();

  
  Serial1.begin(9600);
  debugObj1.DEBUGLN("Debug init Serial1...");  
  debugObj1.SEPARATOR();
}

void loop() 
{
  debugObj.DEBUGLN("Hi! here is Serial");  
  debugObj.SEPARATOR();
  
  debugObj1.DEBUGLN("Hi! here is Serial");  
  debugObj1.SEPARATOR();

  delay(1000);
}
