// this header file describe the structures and basic funtionality of BufferManager

#include "MyDB_Global_Constant_ExternDefinition.h"
#include "MyDB_Global_Defines.h"
#include "MyDB_Global_Structure.h"
#include "Frame.h"

class BufferManager
{
	private:
		// constructor of BufferManager
		BufferManager();
		// to find out the instance of BufferManager is available or not
		static BufferManager *bufferManager_Instance;
		int _pageSize;
		int _bufferSize;
		int fd;
		int getFreeFrame();
		int getFrame(int pageNumber);

	public:
		Frame **BUFFERPOOL;
		int numberOfFrames;
		bool isMyDBOpen;
		int totalNumberOfRequestsToBuffer;
		int hit;
		int miss;
		int numberOfPageReads;
		int numberOfDiskAccess;
	// function to control BufferManager
		virtual ~BufferManager();
		static BufferManager *getInstance();
	    int initializeBuffer(double sizeInMB, int pageSize = DEFAULT_PAGE_SIZE);
		int createDatabase(const char *name, int numOfPages = DEFAULT_NUMBER_OF_PAGES);
		int dropDatabase(const char *name);
		int openDatabase(const char *databaseName);
		int closeDatabase();
};

