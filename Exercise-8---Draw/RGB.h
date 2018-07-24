/*
 * RGB.h
 *
 *  Created on: May 23, 2018
 *      Author: mcsa
 */

#ifndef RGB_H_
#define RGB_H_

struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

#endif /* RGB_H_ */
