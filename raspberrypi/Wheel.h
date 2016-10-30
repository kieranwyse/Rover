/**
* @Author: Kieran Wyse
* @Date:   28-10-2016
* @Email:  kieranwyse@gmail.com
* @Project: Pi-Bot
* @Last modified by:   Kieran Wyse
* @Last modified time: 29-10-2016
* @License: GPL v3
*     This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef WHEEL_H
#define WHEEL_H

#include "InterInterface.h"

#include "TractionControl.h"

class Wheel: public InterInterface
{
  public:
    Wheel(float diameter,int ticks,int motorPinForward,int motorPinReverse,int sensorPin);
    double distance();
    double velocity();
    int getFrequency();
    void setFrequency(int frequency);
    void stop();
    double update();
    friend ostream& operator<<(ostream& stream,Wheel ob);
    friend istream& operator>>(istream& stream,Wheel ob);

  private:
    TractionControl *_contol;
    void pwm(int pin,int duty);
    double _previousDistance;
    double _distance;
    double _velocity;
    int _frequency;
    int _motorPinForward;
    int _motorPinReverse;
    int _sensorPin;
    float _diameter;
    int _ticks;
    double _const;
    unsigned long _prevPulses;
    bool _forward;

};

#endif
