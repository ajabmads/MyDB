// it defines the function associated with the PageHeader of the Page

#include<string>
#include "MyDB_Global_Structure.h"

class GlobalPageHeader
{
private:
	GeneralPageHeaderStruct _generalPageHeader;
	char *_pageData;
public:
	GlobalPageHeader(char *pageData);
	virtual ~GlobalPageHeader();
	int getPageNumber();
	int getNextPageNumber();
	int getPreviousPageNumber();
	int getPageType();
	void setPageNumber(int pageNumber);
	void setPreviousPageNumber(int previousPageNumber);
	void setNextPageNumber(int nextPageNumber);
	void setPageType(int pageType);
};


