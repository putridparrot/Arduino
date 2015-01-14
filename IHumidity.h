#ifndef __IHUMIDITY_H
#define __IHUMIDITY_H

#ifndef __EXPORT_H
#include "Export.h"
#endif

class API IHumidity
{
public:
	virtual double getHumidity() = 0;
};

#endif