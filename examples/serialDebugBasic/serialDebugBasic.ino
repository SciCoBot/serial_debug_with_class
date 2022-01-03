#include<serial_debug1.h>

Debug debugObj(Serial);

void funcTest()
{
  debugObj.DEBUGLN("Init of function funcTest()");
  // Print file name
  DEBUG_PRINT_FILE(debugObj);
  // Print line of this file
  DEBUG_PRINT_LINE(debugObj);
  // Print function name
  DEBUG_PRINT_PRETTY_FUNCTION(debugObj);
  debugObj.DEBUGLN("End of function funcTest()");
}

// Define global variables
int variableIntTest = 5;
char* variableCharTest = "hello world";

void setup() 
{
  // Library does not initialize Serial
  Serial.begin(9600); 

  // Print message
  debugObj.DEBUGLN("Debug init...");  
}

void loop() 
{
  // Wait for a serial message to be received for a specified amount of time (default 5 sec)
  debugObj.debugReceiveTimeout();
  debugObj.SEPARATOR();

  //print the value of a variable
  PRINTVARIABLE(variableIntTest, debugObj);
    
  //print the value of a variable
  PRINTVARIABLE(variableCharTest, debugObj);
  debugObj.SEPARATOR();
  
  funcTest();

  debugObj.SEPARATOR();
  Serial.print("Running time up to this point: ");
  //format: hours:minutes:seconds:milliseconds 
  debugObj.debugTime();
  debugObj.SEPARATOR();
}
