//Anna Chow
//client

#include "client.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include "config.h"
#include "address.h"
#include "bacdef.h"
#include "handlers.h"
#include "client.h"
#include "dlenv.h"
#include "bacdcode.h"
#include "npdu.h"
#include "apdu.h"
#include "iam.h"
#include "tsm.h"
#include "device.h"
#include "bacfile.h"
#include "datalink.h"
#include "dcc.h"
#include "getevent.h"
#include "txbuf.h"
#include "lc.h"
#include "version.h"
/* include the device object */
#include "device.h"
#include "trendlog.h"
#if defined(INTRINSIC_REPORTING)
#include "nc.h"
#endif /* defined(INTRINSIC_REPORTING) */
#if defined(BACFILE)
#include "bacfile.h"
#endif /* defined(BACFILE) */

std::string INSTRUCTIONS = "Please type one of the following commands:"
"on: turn on light bulb"
"off: turn off light bulb"
"status: get the status of the light bulb"
"exit: exit the client\n";

//implement:
//takes a device ID
Client::Client(int id) {
  deviceID = id;
}
Client::~Client(){}
bool Client::turnOn() {
    //writeprop
}
//turn off lightbulb, return true on success
bool Client::turnOff() {
    //writeprop
}
//read lightbulb status, return 1 if on, 0 if off
bool Client::displayStatus() {
    //readprop
}

int main(){
  BACNET_ADDRESS src = {
    0
  };  /* address where message came from */
  uint16_t pdu_len = 0;
  unsigned timeout = 100;     /* milliseconds */
  time_t total_seconds = 0;
  time_t elapsed_seconds = 0;
  time_t last_seconds = 0;
  time_t current_seconds = 0;
  time_t timeout_seconds = 0;
  BACNET_ADDRESS dest;
  int id;
	//enter a device ID
  std::cin >> id;
  Client lightbulb(id);
	//check if server exists using device id
    //whois or address?
	std::cout << INSTRUCTIONS;
	std::string command;
	std::getline(std::cin, command);
	while (command != "exit") {
		if(command == "on"){
			if(lightbulb.turnOn()){
                std::cout << "Turn on success!" << endl;
            }
            else{
                std::cout << "Could not turn on." << endl;
            }
		}
		else if (command == "off"){
			if(lightbulb.turnOff()){
                std::cout << "Turn off success!" << endl;
            }
            else{
                std::cout << "Could not turn off." << endl;
            }
		}
		else if (command == "status"){
			if(lightbulb.displayStatus()){
                std::cout << "Light is on." << endl;
            }
            else{
                std::cout << "Light is off." << endl;
            }
		}
		else {
			std::cout << "Invalid command. Please try again."
				<< INSTRUCTIONS << std::endl;
		}
		std::getline(std::cin, command);
	}
	return 0;
}
