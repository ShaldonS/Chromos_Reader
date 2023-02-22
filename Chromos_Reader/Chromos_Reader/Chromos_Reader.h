
// Chromos_Reader.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CChromosReaderApp:
// Сведения о реализации этого класса: Chromos_Reader.cpp
//

class CChromosReaderApp : public CWinApp
{
public:
	CChromosReaderApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CChromosReaderApp theApp;
