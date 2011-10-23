/*
	Frame is equivalent to page-size of the DataBase block over the hard-disk.
	so when ever be a page is required it is brought into the page from the hard-disk


*/
#ifndef FRAME_H_
#define FRAME_H_

class Frame
{
    public:
		// constructor for the frame
		Frame(int pageSize);
		virtual ~Frame();
		
		long _pageNumber;
		bool _isDirty;//Every write access to a page of a frame sets the dirty flag to TRUE.
					  //Every time a page of a frame is read or written to a DB, the flag is set to FALSE. 
		int _pinCount;//The application can lock a page(or pin it if you may) and then release it after use.  
					  //Every time a page is read from a DB, the frame pincount is set to 0.
					  //The pincount indicates the number of process who have locked but not released.
		char* _pageData;
		unsigned long _priority;
		friend class BufferManager;
};

#endif /* FRAME_H_ */