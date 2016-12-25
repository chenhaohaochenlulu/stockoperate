//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-06                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************
#include "object.h"

#if OBJECT_DEBUG
int main()
{
	return 0;
}
#endif

void * Object::getClass()
{
	printf("Object::getCalss() not available for base type.\n");
	return this;
}