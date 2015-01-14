#ifndef _ITEMPERATURE_H
#define _ITEMPERATURE_H

#ifndef __EXPORT_H
#include "Export.h"
#endif

class API ITemperature
{
public:
	virtual double getTemperature() = 0;
};

#endif

