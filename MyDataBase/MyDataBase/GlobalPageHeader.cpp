// this class is used to set the GlobalPageHeader value,it provides all the set/get

#include "GlobalPageHeader.h"
#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

GlobalPageHeader::GlobalPageHeader(char *pageData)
{
	_pageData=pageData;
	memcpy(&_generalPageHeader,pageData,sizeof(GeneralPageHeaderStructure));

}

int GlobalPageHeader::getNextPageNumber()
{
	return _generalPageHeader.nextPageNumber;
}

int GlobalPageHeader::getPageNumber()
{
	return _generalPageHeader.pageNumber;
}

int GlobalPageHeader::getPageType()
{
	return _generalPageHeader.pageType;
}

void GlobalPageHeader::setNextPageNumber(int nextPageNumber)
{
	_generalPageHeader.nextPageNumber=nextPageNumber;
	memcpy(_pageData,&_generalPageHeader,sizeof(GeneralPageHeaderStructure));
}

void GlobalPageHeader::setPageNumber(int pageNumber)
{
	_generalPageHeader.pageNumber=pageNumber;
	memcpy(_pageData,&_generalPageHeader,sizeof(GeneralPageHeaderStructure));
}

void GlobalPageHeader::setPageType(int pageType)
{
	_generalPageHeader.pageType=pageType;
	memcpy(_pageData,&_generalPageHeader,sizeof(GeneralPageHeaderStructure));
}

GlobalPageHeader::~GlobalPageHeader()
{

}


