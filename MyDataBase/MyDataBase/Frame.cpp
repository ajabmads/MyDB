
#include "Frame.h"

Frame::Frame( int pageSize)
{
	// in the constructor we define the frame general value
	_pageNumber=-1;// no page number assigned to this frame
	_pinCount=-1;// this frame is free, we can assigned a page to this frame
	_isDirty=false;//frame can be access now
	_priority=0;//this frame has no page,so it is being assigned with the priority 0
	_pageData=new char[pageSize];//size of the frameData is equal to the pageSize
}

// use of destructor

Frame :: ~Frame()
{
	delete[] _pageData;
}