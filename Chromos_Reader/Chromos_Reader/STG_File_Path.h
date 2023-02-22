#pragma once

class STG_File_Path : public CDialogEx
{
	DECLARE_DYNAMIC(STG_File_Path)

public:
	STG_File_Path(CWnd* pParent = nullptr);   
	virtual ~STG_File_Path();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INPUT_FILE_PATH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);   

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CMFCEditBrowseCtrl stg_path_str;
	CString stg_path_str_shared;
	CString GetStgPath();
	void ClearStgPath();
};
