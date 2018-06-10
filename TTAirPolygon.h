/*
 * TTAirPolygon.h
 *
 *  Created on: 10 de jun de 2018
 *      Author: almer
 */

#ifndef TTAIRPOLYGON_H_
#define TTAIRPOLYGON_H_

#include <Arduino.h>
namespace TTAIR {

class TTAirPolygon {
private:
  int MIN_LENGTH = 14;
public:
  TTAirPolygon();

  int npoints = 0;
  int xpoints[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int ypoints[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};


  void addPoint(int x, int y);
  bool contains(int x, int y);

  virtual ~TTAirPolygon();
};

} /* namespace TTAIR */

#endif /* TTAIRPOLYGON_H_ */
