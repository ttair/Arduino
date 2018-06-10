/*
 * TTAirPolygon.cpp
 *
 *  Created on: 10 de jun de 2018
 *      Author: almer
 */

#include "TTAirPolygon.h"


namespace TTAIR {


TTAirPolygon::TTAirPolygon(){

}
TTAirPolygon::~TTAirPolygon(){

}

bool TTAirPolygon::contains(int x, int y) {

  if (npoints <= 2) {
    return false;
  }
  int hits = 0;

  int lastx = xpoints[npoints - 1];
  int lasty = ypoints[npoints - 1];
  int curx, cury;

  // Walk the edges of the polygon
  for (int i = 0; i < npoints; lastx = curx, lasty = cury, i++) {
    curx = xpoints[i];
    cury = ypoints[i];

    if (cury == lasty) {
      continue;
    }

    int leftx;
    if (curx < lastx) {
      if (x >= lastx) {
        continue;
      }
      leftx = curx;
    } else {
      if (x >= curx) {
        continue;
      }
      leftx = lastx;
    }

    double test1, test2;
    if (cury < lasty) {
      if (y < cury || y >= lasty) {
        continue;
      }
      if (x < leftx) {
        hits++;
        continue;
      }
      test1 = x - curx;
      test2 = y - cury;
    } else {
      if (y < lasty || y >= cury) {
        continue;
      }
      if (x < leftx) {
        hits++;
        continue;
      }
      test1 = x - lastx;
      test2 = y - lasty;
    }

    if (test1 < (test2 / (lasty - cury) * (lastx - curx))) {
      hits++;
    }
  }
  Serial.println("CONTAINS?");
  return ((hits & 1) != 0);
}

void TTAirPolygon::addPoint(int x, int y) {
    if (npoints <MIN_LENGTH){
      xpoints[npoints] = x;
      ypoints[npoints] = y;
      npoints++;
      Serial.println("Adicionados: ");
      Serial.println(npoints);
    }else {
      Serial.println("ERRO ADDPoint");
    }

}




} /* namespace TTAIR */
