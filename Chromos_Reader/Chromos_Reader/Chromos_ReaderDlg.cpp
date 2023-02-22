
#pragma once
#include "pch.h"
#include "framework.h"
#include "Chromos_Reader.h"
#include "Chromos_ReaderDlg.h"
#include "afxdialogex.h"

//#include "Chromos_STG/ChmFile.h"
//#include "Chromos_STG/Cmpeeks.h"
//#include "Chromos_STG/Lattice.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CChromosReaderDlg::CChromosReaderDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHROMOS_READER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChromosReaderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST5, Chrom_Table);
}

BEGIN_MESSAGE_MAP(CChromosReaderDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON2, &CChromosReaderDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE_STG, &CChromosReaderDlg::OnBnClickedButtonCloseStg)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_STG, &CChromosReaderDlg::OnBnClickedButtonOpenStg)
END_MESSAGE_MAP()

BOOL CChromosReaderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);	

	//ShowWindow(SW_MAXIMIZE);

	//ShowWindow(SW_MINIMIZE);

	Chrom_Table.ModifyStyle(0, LVS_REPORT); 
	Chrom_Table.SetExtendedStyle(Chrom_Table.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	Chrom_Table.InsertColumn(0, _T("Номер"));
	Chrom_Table.InsertColumn(1, _T("Высота"));
	Chrom_Table.InsertColumn(2, _T("Площадь"));
	Chrom_Table.InsertColumn(3, _T("Концентрация"));
	Chrom_Table.InsertColumn(4, _T("Компонент"));

	for(int i(0); i < 5; ++i)
		Chrom_Table.SetColumnWidth(i, 130);
		
	return TRUE;  
}

void CChromosReaderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CChromosReaderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CChromosReaderDlg::OnBnClickedButtonOpenStg()
{
	stg_file_path_dlg = new STG_File_Path();
	stg_file_path_dlg->DoModal();

	CString chm_file_path(_T(""));
	Sleep(100);
	chm_file_path = stg_file_path_dlg->GetStgPath();
	delete stg_file_path_dlg;

	if (!stg_file.ReadChmFile(chm_file_path))
	{
		AfxMessageBox(_T("Ошибка чтения ReadChmFile()"));
		return;
	}

	size_of_stg_file = stg_file.peeks.size();
	CString* str = new CString[5];
	int* max_str_length = new int[5];
	for (unsigned int i = 0; i < 5; ++i)
	{
		str[i] = _T("");
		max_str_length[i] = 0;
	}

	int str_length = 0;

	for (unsigned int i = 0; i < size_of_stg_file; ++i)
	{
		Chrom_Table.InsertItem(i, _T(""));

		str[0].Format(_T("%2d"), i + 1);
		str[1].Format(_T("%.0f"), stg_file.peeks[i].GetHeight());
		str[2].Format(_T("%.0f"), stg_file.peeks[i].GetArea());
		str[3].Format(_T("%.2f"), stg_file.peeks[i].GetConcent());
		str[4].Format(_T("%s"), stg_file.peeks[i].GetComment());

		for (unsigned int j = 0; j < 5; ++j) 
		{
			str_length = str[j].GetLength();
			if (str_length > max_str_length[j])
			{
				max_str_length[j] = str_length;
			}
				
			Chrom_Table.SetItemText(i, j, str[j]);
		}
	}
	for (unsigned int i = 0; i < 5; ++i)
	{
		if (max_str_length[i] >= 20) 
		{
			Chrom_Table.SetColumnWidth(i, max_str_length[i]*7);
		}
	}
	delete[] str;
	delete[] max_str_length;
}

void CChromosReaderDlg::OnBnClickedButtonCloseStg()
{
	if (Chrom_Table.GetItemCount() != 0)
	{
		Chrom_Table.DeleteAllItems();
		for (int i(0); i < 5; ++i)
			Chrom_Table.SetColumnWidth(i, 130);
	}
		
	else AfxMessageBox(_T("Таблица уже пуста"));
	//stg_file_path_dlg.ClearStgPath();
}
