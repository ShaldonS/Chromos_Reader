// STG_File_Path.cpp: файл реализации
//

#include "pch.h"
#include "Chromos_Reader.h"
#include "STG_File_Path.h"
#include "afxdialogex.h"


// Диалоговое окно STG_File_Path

IMPLEMENT_DYNAMIC(STG_File_Path, CDialogEx)

STG_File_Path::STG_File_Path(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_INPUT_FILE_PATH, pParent)
{

}

STG_File_Path::~STG_File_Path()
{
}

void STG_File_Path::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCEDITBROWSE1, stg_path_str);
}


BEGIN_MESSAGE_MAP(STG_File_Path, CDialogEx)
	ON_BN_CLICKED(IDOK, &STG_File_Path::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &STG_File_Path::OnBnClickedCancel)
END_MESSAGE_MAP()


// Обработчики сообщений STG_File_Path


void STG_File_Path::OnBnClickedOk()
{
	GetDlgItem(IDC_MFCEDITBROWSE1)->GetWindowText(stg_path_str_shared);
	//stg_path_str.
	//stg_path_str.Clear();
	//stg_path_str.UpdateData();

	CDialogEx::OnOK();
}

void STG_File_Path::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}

CString STG_File_Path::GetStgPath()
{
	CString stg_path_str_shared_copy(stg_path_str_shared);
	stg_path_str_shared = _T("");
	//stg_path_str.Clear();
	return stg_path_str_shared_copy;
}

void STG_File_Path::ClearStgPath()
{
	//stg_path_str.SetWindowTextW(_T(""));
	//stg_path_str.Clear();
	//stg_path_str.UpdateData();
	stg_path_str_shared.Empty();
}
