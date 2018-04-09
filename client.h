//Anna Chow
//basic client

#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <string>
#include <iostream>

//define my class and functions
class Client{
public:
  Client(int); //takes a device ID
  ~Client(); //destructor
  //test server exists
  //turn on lightbulb, return true on success
  bool turnOn();
  //turn off lightbulb, return true on success
  bool turnOff();
  //read lightbulb status, return true on success
  bool displayStatus();
private:
  //init?
  int deviceID;
};
#endif