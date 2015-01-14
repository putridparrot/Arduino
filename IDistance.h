#ifndef __IDISTANCE_H
#define __IDISTANCE_H

#ifndef __EXPORT_H
#include "Export.h"
#endif

class API IDistance
{
public:
	virtual double getDistance() = 0;
};

#endif
