
#pragma once
#include "ChmFile.h"
#include "STG_File_Path.h"

// Диалоговое окно CChromosReaderDlg
class CChromosReaderDlg : public CDialogEx
{
// Создание
public:
	CChromosReaderDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHROMOS_READER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl Chrom_Table;
	//afx_msg void OnBnClickedButton2();	
	afx_msg void OnBnClickedButtonCloseStg();
	afx_msg void OnBnClickedButtonOpenStg();
private:
	CChmFile stg_file;
	STG_File_Path *stg_file_path_dlg;
	size_t size_of_stg_file;
	void clear_Chrom_Table();
};
