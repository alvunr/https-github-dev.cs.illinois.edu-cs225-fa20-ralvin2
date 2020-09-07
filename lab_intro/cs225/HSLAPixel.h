/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#pragma once

#include <iostream>
#include <sstream>

namespace cs225 {
  class HSLAPixel {
  public:
    double h;
    double s;
    double l;
    double a;
    HSLAPixel();
    HSLAPixel(double h, double s, double l);
    HSLAPixel(double h, double s, double l, double a);
  };
}





// ya so this is my first time doing this and idk if im doing it right lol