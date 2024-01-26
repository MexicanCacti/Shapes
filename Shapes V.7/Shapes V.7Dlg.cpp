// identification comments code block
// Programmer: Milo Dominguez
// Programmer's ID: 1989801

// Shapes V.7Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Shapes V.7.h"
#include "Shapes V.7Dlg.h"
#include "afxdialogex.h"

#include "pShapes.h"

//C++ Libraries
#include <vector>
#include<string>
#include <sstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShapesV7Dlg dialog



CShapesV7Dlg::CShapesV7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPES_V7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShapesV7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CShapesV7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CShapesV7Dlg::OnTcnSelchangeTab1)
	ON_EN_CHANGE(IDC_EDIT1, &CShapesV7Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CShapesV7Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CShapesV7Dlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT5, &CShapesV7Dlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDCANCEL, &CShapesV7Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CShapesV7Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CShapesV7Dlg message handlers

BOOL CShapesV7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, TRUE);		// Set small icon

	// TODO: Add extra initialization here

	// Picture control setup
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC3));
	pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP8), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture->SetBitmap(hb);
	pPicture->ShowWindow(SW_HIDE);

	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	pEdit1->SetWindowText(CString(_T("0.0")));
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	pEdit3->SetWindowText(CString(_T("0.0")));
	CEdit* pEdit5 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT5));
	pEdit5->SetWindowText(CString(_T("0.0")));
	
	CTabCtrl* pTab1 = reinterpret_cast<CTabCtrl*>(GetDlgItem(IDC_TAB1));
	pTab1->InsertItem(0, _T("Square"));
	pTab1->InsertItem(1, _T("Rectangle"));
	pTab1->InsertItem(2, _T("Circle"));
	pTab1->InsertItem(3, _T("Triangle"));
	pTab1->InsertItem(4, _T("Cube"));
	pTab1->InsertItem(5, _T("Box"));
	pTab1->InsertItem(6, _T("Cylinder"));
	pTab1->InsertItem(7, _T("Prism"));
	pTab1->SetCurSel(-1);
	


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShapesV7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShapesV7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShapesV7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CShapesV7Dlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	*pResult = 0;
	// get pointers to all controls in all tabs
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	CEdit* pEdit5 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT5));
	CEdit* pEdit6 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT6));
	CStatic* pStatic1 = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC));
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC3));

	// hide all controls in all tabs
	pEdit1->ShowWindow(SW_HIDE);
	pEdit2->ShowWindow(SW_HIDE);
	pEdit3->ShowWindow(SW_HIDE);
	pEdit4->ShowWindow(SW_HIDE);
	pEdit5->ShowWindow(SW_HIDE);
	pEdit6->ShowWindow(SW_HIDE);
	pStatic1->ShowWindow(SW_HIDE);

	// show shape pictures after initial start ups
	pPicture->ShowWindow(SW_SHOW);

	// show controls for selected tab
	CTabCtrl* pTab = reinterpret_cast<CTabCtrl*>(GetDlgItem(IDC_TAB1));
	switch (pTab->GetCurFocus())
	{
	case 0: // square
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit2->SetWindowTextW(CString(_T("Side")));
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
	}
		break;
	case 1: // rectangle
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit2->SetWindowTextW(CString(_T("Length")));	
		pEdit4->SetWindowTextW(CString(_T("Width")));
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_SHOW);
		pEdit4->ShowWindow(SW_SHOW);
	}
		break;
	case 2: // circle
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit2->SetWindowTextW(CString(_T("Radius")));
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
	}
		break;
	case 3: // triangle
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit2->SetWindowTextW(CString(_T("Side")));
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
	}
		break;
	case 4: // cube
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP5), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit2->SetWindowTextW(CString(_T("Side")));
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
	}
		break;
	case 5: // box
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP6), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit2->SetWindowTextW(CString(_T("Length")));
		pEdit4->SetWindowTextW(CString(_T("Width")));
		pEdit6->SetWindowTextW(CString(_T("Height")));
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_SHOW);
		pEdit4->ShowWindow(SW_SHOW);
		pEdit5->ShowWindow(SW_SHOW);
		pEdit6->ShowWindow(SW_SHOW);
	}
		break;
	case 6: // cylinder
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP7), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit2->SetWindowTextW(CString(_T("Radius")));
		pEdit4->SetWindowTextW(CString(_T("Height")));
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_SHOW);
		pEdit4->ShowWindow(SW_SHOW);
	}
		break;
	case 7: // prism
	{
		HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			MAKEINTRESOURCE(IDB_BITMAP8), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		pPicture->SetBitmap(hb);
		pEdit2->SetWindowTextW(CString(_T("Side")));
		pEdit4->SetWindowTextW(CString(_T("Height")));
		pEdit1->ShowWindow(SW_SHOW);
		pEdit2->ShowWindow(SW_SHOW);
		pEdit3->ShowWindow(SW_SHOW);
		pEdit4->ShowWindow(SW_SHOW);
	}
		break;
	}
}


void CShapesV7Dlg::OnEnChangeEdit1()
{
	CString mEdit1;
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	pEdit1->GetWindowText(mEdit1);
}


void CShapesV7Dlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

}


void CShapesV7Dlg::OnEnChangeEdit3()
{
	CString mEdit3;
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	pEdit3->GetWindowText(mEdit3);
}


void CShapesV7Dlg::OnEnChangeEdit5()
{
	CString mEdit5;
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CEdit* pEdit5 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT5));
	pEdit5->GetWindowText(mEdit5);
}

// CALCULATE BUTTON
void CShapesV7Dlg::OnBnClickedCancel()
{
	ostringstream sout;
	vector<string> tokens;
	CTabCtrl* pTab = reinterpret_cast<CTabCtrl*>(GetDlgItem(IDC_TAB1));
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	CEdit* pEdit5 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT5));
	CEdit* pEdit7 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT7));
	CString mEdit1,mEdit3,mEdit5;
	string sEdit1,sEdit3,sEdit5;

	switch (pTab->GetCurFocus()) {
	case 0:
	{
		tokens.push_back("Square");
		pEdit1->GetWindowText(mEdit1);
		sEdit1 = CStringA(mEdit1);
		tokens.push_back(sEdit1);
		Square square(tokens);
		sout << &square;
		pEdit7->SetWindowText(CString(sout.str().c_str()));
	}
		break;
	case 1:
	{
		tokens.push_back("Rectangle");
		pEdit1->GetWindowText(mEdit1);
		pEdit3->GetWindowText(mEdit3);
		sEdit1 = CStringA(mEdit1);
		sEdit3 = CStringA(mEdit3);
		tokens.push_back(sEdit1);
		tokens.push_back(sEdit3);
		comsc::Rectangle rectangle(tokens);
		sout << &rectangle;
		pEdit7->SetWindowText(CString(sout.str().c_str()));
	}
		break;
	case 2:
	{
		tokens.push_back("Circle");
		pEdit1->GetWindowText(mEdit1);
		sEdit1 = CStringA(mEdit1);
		tokens.push_back(sEdit1);
		Circle circle(tokens);
		sout << &circle;
		pEdit7->SetWindowText(CString(sout.str().c_str()));
	}
		break;
	case 3:
	{
		tokens.push_back("Triangle");
		pEdit1->GetWindowText(mEdit1);
		sEdit1 = CStringA(mEdit1);
		tokens.push_back(sEdit1);
		Triangle triangle(tokens);
		sout << &triangle;
		pEdit7->SetWindowText(CString(sout.str().c_str()));
	}
		break;
	case 4:
	{
		tokens.push_back("Cube");
		pEdit1->GetWindowText(mEdit1);
		sEdit1 = CStringA(mEdit1);
		tokens.push_back(sEdit1);
		Cube cube(tokens);
		sout << &cube;
		pEdit7->SetWindowText(CString(sout.str().c_str()));
	}
		break;
	case 5:
	{
		tokens.push_back("Box");
		pEdit1->GetWindowText(mEdit1);
		pEdit3->GetWindowText(mEdit3);
		pEdit5->GetWindowText(mEdit5);
		sEdit1 = CStringA(mEdit1);
		sEdit3 = CStringA(mEdit3);
		sEdit5 = CStringA(mEdit5);
		tokens.push_back(sEdit1);
		tokens.push_back(sEdit3);
		tokens.push_back(sEdit5);
		Box box(tokens);
		sout << &box;
		pEdit7->SetWindowText(CString(sout.str().c_str()));
	}
		break;
	case 6:
	{
		tokens.push_back("Cylinder");
		pEdit1->GetWindowText(mEdit1);
		pEdit3->GetWindowText(mEdit3);
		sEdit1 = CStringA(mEdit1);
		sEdit3 = CStringA(mEdit3);
		tokens.push_back(sEdit1);
		tokens.push_back(sEdit3);
		Cylinder cylinder(tokens);
		sout << &cylinder;
		pEdit7->SetWindowText(CString(sout.str().c_str()));
	}
		break;
	case 7:
	{
		tokens.push_back("Prism");
		pEdit1->GetWindowText(mEdit1);
		pEdit3->GetWindowText(mEdit3);
		sEdit1 = CStringA(mEdit1);
		sEdit3 = CStringA(mEdit3);
		tokens.push_back(sEdit1);
		tokens.push_back(sEdit3);
		Prism prism(tokens);
		sout << &prism;
		pEdit7->SetWindowText(CString(sout.str().c_str()));
	}
		break;
	}
}

// EXIT BUTTON
void CShapesV7Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
