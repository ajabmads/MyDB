

#ifndef MYDB_GLOBAL_DEFINES_H_
#define MYDB_GLOBAL_DEFINES_H_

/*  #define for pageTypes */

#define TYPE_DB_MAIN_HEADER_PAGE 0
#define TYPE_DIRECTORY_HEADER_PAGE 1
#define TYPE_DIRECTORY_PAGE 2
#define TYPE_INDEX_HEADER_PAGE 3
#define TYPE_INDEX_PAGE 4
#define TYPE_DATA_PAGE 5
#define TYPE_LEAF_PAGE 6
#define TYPE_UNKNOWN_PAGE 7


/* this define are for BufferManager */
#define FRAME_NOT_AVAILABLE -1;
#define BUFFER_MANAGER_SUCCESS 1;
#define BUFFER_MANAGER_FAILURE 0;



#endif /*MYDB_GLOBAL_DEFINES_H_  */