// it contains all the functionality of the BufferManager

#include "BufferManager.h"
#include "GlobalPageHeader.h"
#include "MyDB_Global_Constant_ExternDefinition.h"
#include "MyDB_Global_Defines.h"
#include "DBMainHeaderPage.h"

#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<sys\stat.h>
#include<sys\types.h>

// all function definition is starts from here

BufferManager::BufferManager()
{
	BUFFERPOOL=NULL;
	fd=-1;
	initializeBuffer(10,DEFAULT_PAGE_SIZE);// function is used to initialize the Buffer of 10MB and
										   // default page size is in KB here its 8KB
	isMyDBOpen=false;
}

// int BufferManager::initializeBuffer(sizeInMB,DEFAULT_PAGE_SIZE) function definition is here

int BufferManager::initializeBuffer(double size,int pageSize)
{
	//check first BUFFERPOOL is null or not,if not then delete it and and set it to NULL
	//find out the number of frames and assigned each frame its default value

	if(BUFFERPOOL != NULL)
	{
		delete[] BUFFERPOOL;
		BUFFERPOOL=NULL;
	}
	numberOfDiskAccess=0;
	numberOfPageReads=0;

	// check for number of frames
	_bufferSize=size; 
	_pageSize=pageSize;// pagesize is equal to the disk block
	numberOfFrames=(size*1024*1024)/_pageSize;
	// check for pageSize and number of frames
	printf("page size is in Bytes and is equal to : %d \n",_pageSize);
	printf("number of frames in BufferPool is : %d \n",numberOfFrames);
	//Each frame of the bufferpool is being initialized with the different values
	for(int i=0;i<numberOfFrames;i++)
	{
		BUFFERPOOL[i]=new Frame(_pageSize);
	}
	// message
	printf("In initializeBuffer function :Each frame of the buffer pool is being initialized: \n");
	printf("In initializeBuffer function :BUFFERPOOL is being initialized successfully \n");

	return BUFFER_MANAGER_SUCCESS;
}

BufferManager::~BufferManager()
{
	delete[] BUFFERPOOL;
}

BufferManager* BufferManager::bufferManager_Instance=NULL;

BufferManager* BufferManager::getInstance()
{
	if(bufferManager_Instance==NULL)
	{
		bufferManager_Instance=new BufferManager();
	}
	return bufferManager_Instance;
}

