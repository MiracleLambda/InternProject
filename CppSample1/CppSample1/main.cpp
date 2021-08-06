#include <stdio.h>
#include "string.h"

const char* GetString1() 
{
	const char* st = "String";
	return st;
}

char* GetString2()
{
	char st[] = "String";
	return st;
}

char* GetString3()
{
	char* st = new char[6];
	//strcpy(st, "String");
	memcpy(st, "String", 6);
	st[6] = '\0';
	return st;
}

int main() 
{
	printf("%s\n", GetString3());
}