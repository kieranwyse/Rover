/**
* @Author: Kieran Wyse
* @Date:   01-11-2016
* @Email:  kieranwyse@gmail.com
* @Project: Pi-Bot
* @Last modified by:   Kieran Wyse
* @Last modified time: 15-11-2016
* @License: License: GPL v3
#     This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "wiringPIDummy.hpp"
//std::array<std::mutex,17> muxPin;
std::mutex muxPin;

void (*pin0Risingfunc) (void);
 void (*pin1Risingfunc) (void);
 void (*pin2Risingfunc) (void);
 void (*pin3Risingfunc) (void);
 void (*pin4Risingfunc) (void);
 void (*pin5Risingfunc) (void);
 void (*pin6Risingfunc) (void);
 void (*pin7Risingfunc) (void);
 void (*pin8Risingfunc) (void);
 void (*pin9Risingfunc) (void);
 void (*pin10Risingfunc) (void);
 void (*pin11Risingfunc) (void);
 void (*pin12Risingfunc) (void);
 void (*pin13Risingfunc) (void);
 void (*pin14Risingfunc) (void);
 void (*pin15Risingfunc) (void);
 void (*pin16Risingfunc) (void);

 void (*pin0Fallingfunc) (void);
  void (*pin1Fallingfunc) (void);
  void (*pin2Fallingfunc) (void);
  void (*pin3Fallingfunc) (void);
  void (*pin4Fallingfunc) (void);
  void (*pin5Fallingfunc) (void);
  void (*pin6Fallingfunc) (void);
  void (*pin7Fallingfunc) (void);
  void (*pin8Fallingfunc) (void);
  void (*pin9Fallingfunc) (void);
  void (*pin10Fallingfunc) (void);
  void (*pin11Fallingfunc) (void);
  void (*pin12Fallingfunc) (void);
  void (*pin13Fallingfunc) (void);
  void (*pin14Fallingfunc) (void);
  void (*pin15Fallingfunc) (void);
  void (*pin16Fallingfunc) (void);


  void turn(int pin) {

	  muxPin.lock();
    while(pins[pin]) {
    	int maxRotationsPerSecond = 5;
    	      //Maximum rotational freqency 5 rotations per second
    	      //1000 milliseconds
    	      //5*ticks =  total number of ticks
    	      // time between each tick is 1000/(5*ticks)
      int timebetweenticks = 100;
      if(sensorPin[pin] != -1)
        timebetweenticks = ((double)PWMRANGE/pins[pin])*(1000/(maxRotationsPerSecond*ticks[sensorPin[pin]]));

      //wake up evey five milliseconds and call mouse event
      for(int i = 0 ; i < timebetweenticks; i = i+5) {
        muxPin.unlock();
      	std::this_thread::sleep_for(std::chrono::milliseconds(5));
        muxPin.lock();
        if(hardware_mouse_event[pin] != "")
          writeEvent(0,pins[pin],hardware_mouse_event[pin]);

      }// when i reachens time between time between simulate an event





      switch(sensorPin[pin]){
        case 0:
        pin0Risingfunc();
        pin0Fallingfunc();
        break;
        case 1:
        pin1Risingfunc();
        pin1Fallingfunc();
        break;
        case 2:
        pin2Risingfunc();
        pin2Fallingfunc();
        break;
        case 3:
        pin3Risingfunc();
        pin3Fallingfunc();
        break;
        case 4:
        pin4Risingfunc();
        pin4Fallingfunc();
        break;
        case 5:
        pin5Risingfunc();
        pin5Fallingfunc();
        break;
        case 6:
        pin6Risingfunc();
        pin6Fallingfunc();
        break;
        case 7:
        pin7Risingfunc();
        pin7Fallingfunc();
        break;
        case 8:
        pin8Risingfunc();
        pin8Fallingfunc();
        break;
        case 9:
        pin9Risingfunc();
        pin9Fallingfunc();
        break;
        case 10:
        pin10Risingfunc();
        pin10Fallingfunc();
        break;
        case 11:
        pin11Risingfunc();
        pin11Fallingfunc();
        break;
        case 12:
        pin12Risingfunc();
        pin12Fallingfunc();
        break;
        case 13:
        pin13Risingfunc();
        pin13Fallingfunc();
        break;
        case 14:
        pin14Risingfunc();
        pin14Fallingfunc();
        break;
        case 15:
        pin15Risingfunc();
        pin15Fallingfunc();
        break;
        case 16:
        pin16Risingfunc();
        pin16Fallingfunc();
        break;
        default:
        break;
      }

    }
    muxPin.unlock();
  }


void wiringPiISR (int pin,int edge, void (*foo)(void) )  {

  std::cout << "attach function:" << pin <<std::endl;
  if(edge == 1) {
    switch (pin) {
      case 0: pin0Risingfunc = foo;
      break;
      case 1: pin1Risingfunc = foo;
      break;
      case 2: pin2Risingfunc = foo;
      break;
      case 3: pin3Risingfunc = foo;
      break;
      case 4: pin4Risingfunc = foo;
      break;
      case 5: pin5Risingfunc = foo;
      break;
      case 6: pin6Risingfunc = foo;
      break;
      case 7: pin7Risingfunc = foo;
      break;
      case 8: pin8Risingfunc = foo;
      break;
      case 9: pin9Risingfunc = foo;
      break;
      case 10: pin10Risingfunc = foo;
      break;
      case 11: pin11Risingfunc = foo;
      break;
      case 12: pin12Risingfunc = foo;
      break;
      case 13: pin13Risingfunc = foo;
      break;
      case 14: pin14Risingfunc = foo;
      break;
      case 15: pin15Risingfunc = foo;
      break;
      case 16: pin16Risingfunc = foo;
      break;
    }
  }
  if(edge == 0) {
    switch (pin) {
      case 0: pin0Fallingfunc = foo;
      break;
      case 1: pin1Fallingfunc = foo;
      break;
      case 2: pin2Fallingfunc = foo;
      break;
      case 3: pin3Fallingfunc = foo;
      break;
      case 4: pin4Fallingfunc = foo;
      break;
      case 5: pin5Fallingfunc = foo;
      break;
      case 6: pin6Fallingfunc = foo;
      break;
      case 7: pin7Fallingfunc = foo;
      break;
      case 8: pin8Fallingfunc = foo;
      break;
      case 9: pin9Fallingfunc = foo;
      break;
      case 10: pin10Fallingfunc = foo;
      break;
      case 11: pin11Fallingfunc = foo;
      break;
      case 12: pin12Fallingfunc = foo;
      break;
      case 13: pin13Fallingfunc = foo;
      break;
      case 14: pin14Fallingfunc = foo;
      break;
      case 15: pin15Fallingfunc = foo;
      break;
      case 16: pin16Fallingfunc = foo;
      break;
    }
  }
}
std::array<int ,17> pwmRanges = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void softPwmCreate (int pin , int initialValue, int  pwmRange) {
  pwmRanges[pin] = pwmRange;
  //start up the mouse


}


std::array<int ,17> pins = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
std::array<int ,17> ticks = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
std::array<int ,17> sensorPin = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
std::array<std::thread,17> workers = {};


void softPwmWrite (int pin,int duty) {

	muxPin.lock();
  int is_running = pins[pin];
  pins[pin] =duty;
  muxPin.unlock();
  //start the thread up
  if(is_running == 0 && duty  && !workers[pin].joinable()) {
    std::thread t1(turn,pin);
    std::cout<< "pin out:" <<pin <<std::endl;
    workers[pin] = std::move(t1);
  }
  //wait for the thread to end before moving on
  //if we don't it is not pretty
  if(is_running && duty == 0) {
	  std::cout<< "stopping thread pin out:" <<pin <<std::endl;
	  if(workers[pin].joinable()) {
		  std::cout<<"waiting for thread to stop";
		  workers[pin].join();
		  std::cout<< "stopped:"<<pin<<std::endl;
	  }
  }
}

void pinMode (int pin, int mode)  {



}

void pullUpDnControl(int pin, int control) {

}


//the mouse is hardware defined
std::array<std::string, 17> hardware_mouse_event = {};



/*
* Writing evelnts to input echos the events back.
*/

void writeEvent(int x,int y,std::string mouse) {
  struct input_event event, event_end;

  int fd = open(mouse.c_str(), O_RDWR);
  if (fd < 0) {
    std::cerr << "/* Errro open mouse: */" << errno<< '\n';
    return;
  }
  std::memset(&event, 0, sizeof(event));
  std::memset(&event, 0, sizeof(event_end));
  gettimeofday(&event.time, NULL);
  event.type = EV_REL;
  event.code = REL_X;
  event.value = x;
  gettimeofday(&event_end.time, NULL);
  event_end.type = EV_SYN;
  event_end.code = SYN_REPORT;
  event_end.value = 0;

  //Writing evelnts to input echos the events back.
  write(fd, &event, sizeof(event));// Move the mouse
  write(fd, &event_end, sizeof(event_end));// Show move

  gettimeofday(&event.time, NULL);
  event.type = EV_REL;
  event.code = REL_Y;
  event.value = y;
  gettimeofday(&event_end.time, NULL);
  event_end.type = EV_SYN;
  event_end.code = SYN_REPORT;
  event_end.value = 0;

  //Writing evelnts to input echos the events back.
  write(fd, &event, sizeof(event));// Move the mouse
  write(fd, &event_end, sizeof(event_end));// Show move

  close(fd);
  return;
}
/*
*get the mouses attached to the system
*
*/

std::vector<std::string> getMouseDevices() {
  std::vector<std::string> devices;
  std::string line;
  //This file has detials of the input devices attached to the system
  std::ifstream myfile ("/proc/bus/input/devices");
  std::string device;
  //Guess that the last mouse added is the mouse that is used to test
  if (myfile.is_open()) {
    for(std::string word; myfile >> word; )
    if(word.compare(0,14,"Handlers=mouse") == 0) {
      myfile >> word;
      devices.insert(devices.begin(),"/dev/input/"+word);


    }
    myfile.close();
  } else std::cerr << "Unable to open file" << std::endl;

return devices;
}
