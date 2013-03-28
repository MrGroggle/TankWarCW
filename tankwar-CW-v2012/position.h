#ifndef position_H
#define position_H

#define PI 3.1415927
#define DEG2RAD(DEG) ((DEG)*((PI)/(180.0)))
#define RAD2DEG(RAD) ((RAD)*((180.0)/(PI)))

class position
{
private:
	  float x,y,th;
   public:
	   position(){}; // Construtor
	   ~position(){}; // Destructor
	  void set(float newX, float newY, float newTh){x = newX;y = newY;th = newTh;}
	  float getX(){return x;}
	  float getY(){return y;}
	  float getTh(){return th;}
};
#endif