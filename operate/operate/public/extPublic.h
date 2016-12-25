//**********************************************************************
//**                                                                  **
//**        (C)Copyright ASUSTEK Hunter_Chen   2009-09                **
//**                                                                  **
//**              All Rights Reserved.                                **
//**                                                                  **
//**********************************************************************
#ifndef EXTPUBLIC_H
#define EXTPUBLIC_H

	extern ACCIO accio;
	extern ACCPCI accpci;
	extern CAccsio accsio;
	extern CAccMem accmem;
	extern CMsr accmsr;
	extern CErrorWarning tplerr;
	extern FILE * fp_result;
	extern CTplKeyword tplKeyword;
	extern CDescripTab despTab;
	extern CGet get;
	extern CBracket block;
	extern CIfStruct ifStruct;
	extern CProgramStruct programStruct;
	extern CReturn tplret;
	extern COperatorPriority tplopp;
	extern CParseVariable parseVar;
	extern CExpressions tplexp;
#endif