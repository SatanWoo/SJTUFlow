#ifndef _BOUNDARYSTRATEGY_H
#define _BOUNDARYSTRATEGY_H

typedef enum
{
	BounadaryTypeNone = 0,
	BounadaryTypeHorizontal = 1,
	BounadaryTypeVertical = 2
}BoundaryType;

class BoundaryStrategy
{
public:
	virtual void setUpBoundary(int size, BoundaryType type, float *boundary) = 0;
};

#endif