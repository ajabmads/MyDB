// MyDB Main Header Page declaration is here
#ifndef MYDB_MAIN_HEADER_PAGE_H
#define MYDB_MAIN_HEADER_PAGE_H


#include "MyDB_Global_Structure.h"
#include "MyDB_Global_Defines.h"
#include "MyDB_Global_Constant_ExternDefinition.h"

class MyDB_MainHeaderPage
{
	private:
		char *_pageData;
		bool _haveIPinnedThePage;
		bool _isDirty;
		typedef struct MyDB_MainHeaderStructure
		{
			GeneralPageHeaderStruct _generalPageHeaderStruct;
			int _pageType;
			int _totalNumberOfPages;
			int _freePagePointer;
			int _pageSizeOfDatabase;
			int _sysTableHeaderPageNumber;
			int _sysColumnsHeaderPageNumber;
			int _sysIndexHeaderPageNumber;
			int _sysIndexColumnsHeaderPageNumber;
			int _numberOfTables;
			int _numberOfPagesUsed;
		}MyDB_MainheaderStruct;
		MyDB_MainheaderStruct _MyDB_MainHeader;
		

	public:
		DBMainHeaderPage(char *pageData);
		DBMainHeaderPage(int pageNumber);
		virtual ~DBMainHeaderPage();
		static int createHeaderPage(int pageSize, char *pageData,int pageNumber, int numOfPages);

}

#endif /* MYDB_MAIN_HEADER_PAGE_H */