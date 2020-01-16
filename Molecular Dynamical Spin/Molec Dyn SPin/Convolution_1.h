// $Id: Convolution.h,v 1.1.1.1 2007/06/19 02:02:45 awseed Exp $

#ifndef HYLIB__CONVOLUTION_HH
#define HYLIB__CONVOLUTION_HH

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

class Convolution
{
private :
  float *zed;
  int   noSteps;
  float step;
  float beamWidth;

public :
    Convolution(int nStep, float dStep, float* dbz, float beam);
    virtual ~Convolution();
    float get_value(float range, float angle);
    float beam_height( float angle, float range)  ;
    float get_elevation( float height, float range) ;
    float get_power( float theta) ;

};


#endif // HYLIB__CONVOLUTION_HH
