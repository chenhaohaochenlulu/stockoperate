//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-06                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************
#ifndef OBJECT_H
#define OBJECT_H
#define OBJECT_DEBUG 0//1
#include <stdio.h>
class Object
{
public:
	virtual void * getClass();
};
#endif
