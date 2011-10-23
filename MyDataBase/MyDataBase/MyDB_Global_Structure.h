// this file declares the GeneralHeader of the Page

#ifndef MYDB_GLOBAL_STRUCTURE_H
#define MYDB_GLOBAL_STRUCTURE_H
#include<sstream>

typedef struct GeneralPageHeaderStructure
{
	int pageNumber;// Each page has a pageNumber
	int pageType;//Each page defines what type of page it is
	int nextPageNumber;//Each page points to the next available page
}GeneralPageHeaderStruct;

#endif  /*MYDB_GLOBAL_STRUCTURE_H*/
