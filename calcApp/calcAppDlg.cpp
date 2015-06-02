
// calcAppDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calcApp.h"
#include "calcAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalcAppDlg 对话框



CcalcAppDlg::CcalcAppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalcAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalcAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDpower, CPowerButton);
	DDX_Control(pDX, IDextract, CExtractButton);
}

BEGIN_MESSAGE_MAP(CcalcAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDequal, &CcalcAppDlg::OnBnClickedequal)
	ON_BN_CLICKED(ID1, &CcalcAppDlg::OnBnClicked1)
	ON_BN_CLICKED(ID2, &CcalcAppDlg::OnBnClicked2)
	ON_BN_CLICKED(ID3, &CcalcAppDlg::OnBnClicked3)
	ON_BN_CLICKED(ID4, &CcalcAppDlg::OnBnClicked4)
	ON_BN_CLICKED(ID5, &CcalcAppDlg::OnBnClicked5)
	ON_BN_CLICKED(ID6, &CcalcAppDlg::OnBnClicked6)
	ON_BN_CLICKED(ID7, &CcalcAppDlg::OnBnClicked7)
	ON_BN_CLICKED(ID8, &CcalcAppDlg::OnBnClicked8)
	ON_BN_CLICKED(ID9, &CcalcAppDlg::OnBnClicked9)
	ON_BN_CLICKED(ID0, &CcalcAppDlg::OnBnClicked0)
	ON_BN_CLICKED(IDc, &CcalcAppDlg::OnBnClickedc)
	ON_BN_CLICKED(IDopposite, &CcalcAppDlg::OnBnClickedopposite)
	ON_BN_CLICKED(IDplus, &CcalcAppDlg::OnBnClickedplus)	
	ON_BN_CLICKED(IDminus, &CcalcAppDlg::OnBnClickedminus)
	ON_BN_CLICKED(IDmulti, &CcalcAppDlg::OnBnClickedmulti)
	ON_BN_CLICKED(IDdivision, &CcalcAppDlg::OnBnClickeddivision)
	ON_BN_CLICKED(IDbackspace, &CcalcAppDlg::OnBnClickedbackspace)
	ON_BN_CLICKED(IDdot, &CcalcAppDlg::OnBnClickeddot)
END_MESSAGE_MAP()


// CcalcAppDlg 消息处理程序

BOOL CcalcAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	HINSTANCE hIExtract;
	HBITMAP hBExtract;
	hIExtract = ::AfxGetInstanceHandle();
	hBExtract = ::LoadBitmap(hIExtract, MAKEINTRESOURCE(IDB_BITMAP2));
	CExtractButton.SetBitmap(hBExtract);

	HINSTANCE hIPower;
	HBITMAP hBPoewer;
	hIPower = ::AfxGetInstanceHandle();
	hBPoewer = ::LoadBitmap(hIPower, MAKEINTRESOURCE(IDB_BITMAP1));
	CPowerButton.SetBitmap(hBPoewer);

	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_EDIT1);

	m_Font.CreateFont(0, 0, 0, 0, 400, FALSE, FALSE, 0,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, L"Microsoft Sans Serif");
	pEdit->SetFont(&m_Font);
	m_Font.DeleteObject();

	pBox1 = (CEdit*)GetDlgItem(IDC_EDIT1);

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalcAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalcAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalcAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


double calculate()
{
	switch (_operator)
	{
	case 1:
			return _array1 + _array2;
		case 2:
			return _array1 - _array2;
		case 3:
			return _array1 * _array2;
		case 4:
			return _array1 / _array2;
		case 5:
			return 0;
	}
	return 0;
}


double getArray()
{
	static CString CSstr;
	pBox1->GetWindowText(CSstr);
	return _ttol(CSstr);
}

void keyPress(int num)
{
	static CString CSstr;
	pBox1->GetWindowText(CSstr);
	CSstr += _T("%d");
	CSstr.Format(CSstr, num);
	pBox1->SetWindowText(CSstr);
}


void CcalcAppDlg::OnBnClickedequal()
{
	static CString CSstr;
	pBox1->GetWindowText(CSstr);
	_array2 = _ttol(CSstr);
	_result = calculate();
	CSstr.Format(_T("%0.8lf"), _result);
	pBox1->SetWindowText(CSstr);
}


void CcalcAppDlg::OnBnClicked1()
{
	keyPress(1);
}


void CcalcAppDlg::OnBnClicked2()
{
	keyPress(2);
}


void CcalcAppDlg::OnBnClicked3()
{
	keyPress(3);
}


void CcalcAppDlg::OnBnClicked4()
{
	keyPress(4);
}


void CcalcAppDlg::OnBnClicked5()
{
	keyPress(5);
}


void CcalcAppDlg::OnBnClicked6()
{
	keyPress(6);
}


void CcalcAppDlg::OnBnClicked7()
{
	keyPress(7);
}


void CcalcAppDlg::OnBnClicked8()
{
	keyPress(8);
}


void CcalcAppDlg::OnBnClicked9()
{
	keyPress(9);
}


void CcalcAppDlg::OnBnClicked0()
{
	if (getArray()!=0)
		keyPress(0);
}


void CcalcAppDlg::OnBnClickedc()
{
	_array1 = _array2 = 0;
	_gotArray2 = false;
	_operator = 0;
	pBox1->SetWindowText(_T("0"));
}


void CcalcAppDlg::OnBnClickedopposite()
{
	static CString CSstr,CSminus;
	CSminus = "-";
	pBox1->GetWindowText(CSstr);
	pBox1->SetWindowText(CSminus+CSstr);
}


void CcalcAppDlg::OnBnClickedplus()
{
	_array1 = getArray();
	_operator = 1;
}


void CcalcAppDlg::OnBnClickedminus()
{
	_array1 = getArray();
	_operator = 2;
}


void CcalcAppDlg::OnBnClickedmulti()
{
	_array1 = getArray();
	_operator = 3;
}


void CcalcAppDlg::OnBnClickeddivision()
{
	_array1 = getArray();
	_operator = 4;
}


void CcalcAppDlg::OnBnClickedbackspace()
{
	static CString CSstr;
	pBox1->GetWindowText(CSstr);
	pBox1->SetWindowText(CSstr.Left(CSstr.GetLength() - 1));
}


void CcalcAppDlg::OnBnClickeddot()
{
	static CString CSstr;
	pBox1->GetWindowText(CSstr);
	CSstr += _T(".");
	pBox1->SetWindowText(CSstr);
}
