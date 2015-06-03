
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
	ON_BN_CLICKED(IDce, &CcalcAppDlg::OnBnClickedce)
	ON_BN_CLICKED(IDevolution, &CcalcAppDlg::OnBnClickedevolution)
	ON_BN_CLICKED(IDprecent, &CcalcAppDlg::OnBnClickedprecent)
	ON_BN_CLICKED(IDreciprocal, &CcalcAppDlg::OnBnClickedreciprocal)
	ON_BN_CLICKED(IDdms, &CcalcAppDlg::OnBnClickeddms)
	ON_BN_CLICKED(IDcosh, &CcalcAppDlg::OnBnClickedcosh)
	ON_BN_CLICKED(IDcos, &CcalcAppDlg::OnBnClickedcos)
	ON_BN_CLICKED(IDpower, &CcalcAppDlg::OnBnClickedpower)
	ON_BN_CLICKED(IDextract, &CcalcAppDlg::OnBnClickedextract)
	ON_BN_CLICKED(IDmc, &CcalcAppDlg::OnBnClickedmc)
	ON_BN_CLICKED(IDmr, &CcalcAppDlg::OnBnClickedmr)
	ON_BN_CLICKED(IDms, &CcalcAppDlg::OnBnClickedms)
	ON_BN_CLICKED(IDmplus, &CcalcAppDlg::OnBnClickedmplus)
	ON_BN_CLICKED(IDmminus, &CcalcAppDlg::OnBnClickedmminus)
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
	pBox1->SetWindowText(_T("0"));

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
	if (!_gotArray2)
		_array2 = _array1;
	switch (_operator)
	{
		case 0:
			return _array1;
		case 1:
			return _array1 + _array2;
		case 2:
			return _array1 - _array2;
		case 3:
			return _array1 * _array2;
		case 4:
			if (_array2 == 0)
			{
				errno = ERANGE;
				return 0;
			}
			return _array1 / _array2;
		case 5:
			return _array1 / _array2 * 100;
		case 6:
			return pow(_array1, _array2);
		case 7:
			if (_array2 == 0)
			{
				errno = ERANGE;
				return 0;
			}
			return pow(_array1, 1 / _array2);
	}
	return 0;
}


double getArray()
{
	static CString CSstr;
	pBox1->GetWindowText(CSstr);
	return _tstof(CSstr);
}

void keyPress(int num)
{
	static CString CSstr;
	pBox1->GetWindowText(CSstr);
	if (_operator != 0 && _gotArray2 == false)
		_gotArray2 = true;
	if (getArray() == 0 && CSstr.Find(_T(".")) != -1)
		CSstr = "%d";
	else
		CSstr += _T("%d");
	CSstr.Format(CSstr, num);
	pBox1->SetWindowText(CSstr);
}


void CcalcAppDlg::OnBnClickedequal()
{
	static CString CSstr;
	pBox1->GetWindowText(CSstr);
	_array2 = _tstof(CSstr);
	_result = calculate();
	if (!errno)
	{
		pBox1->SetWindowText(_T("数据出错！"));
		return;
	}
	CSstr.Format(_T("%.8lf"), _result);
	pBox1->SetWindowText(CSstr);
	if (_gotArray2)
	{
		_result = _array1 = _array2 = 0;
		_operator = 0;
		_gotArray2 = false;
	}
	else
	{
		_array2 = _result = 0;
	}
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
	errno = NULL;
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
	_gotArray2 = false;
	_array1 = getArray();
	_operator = 1;
	pBox1->SetWindowText(_T("0"));
}


void CcalcAppDlg::OnBnClickedminus()
{
	_gotArray2 = false;
	_array1 = getArray();
	_operator = 2;
	pBox1->SetWindowText(_T("0"));
}


void CcalcAppDlg::OnBnClickedmulti()
{
	_gotArray2 = false;
	_array1 = getArray();
	_operator = 3;
	pBox1->SetWindowText(_T("0"));
}


void CcalcAppDlg::OnBnClickeddivision()
{
	_gotArray2 = false;
	_array1 = getArray();
	_operator = 4;
	pBox1->SetWindowText(_T("0"));
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


void CcalcAppDlg::OnBnClickedce()
{
	if (_gotArray2)
	{
		_array2 = 0;
		_gotArray2 = false;
		pBox1->SetWindowText(_T("0"));
	}
	else
	{
		_array1 = 0;
		_operator = 0;
		pBox1->SetWindowText(_T("0"));
	}
}


void CcalcAppDlg::OnBnClickedevolution()
{
	static CString CSstr;
	_array1 = getArray();
	_result = sqrt(_array1);
	CSstr.Format(_T("%.8lf"), _result);
	pBox1->SetWindowText(CSstr);
}


void CcalcAppDlg::OnBnClickedprecent()
{
	_array1 = getArray();
	_operator = 5;
}


void CcalcAppDlg::OnBnClickedreciprocal()
{
	static CString CSstr;
	_array1 = getArray();
	if (_array1 == 0)
	{
		errno = ERANGE;
		pBox1->SetWindowText(_T("数据出错！"));
		return;
	}
	_result = 1 / _array1;
	CSstr.Format(_T("%.8lf"), _result);
	pBox1->SetWindowText(CSstr);
}


void CcalcAppDlg::OnBnClickeddms()
{
	static CString CSstr; 
	int d, m, s;
	_array1 = getArray();
	d = (int)floor(_array1);
	m = (int)floor(_array1 * 60);
	m %= 60;
	s = (int)floor(_array1 * 3600);
	s %= 60;
	CSstr.Format(_T("%d°%d′%d″"), d, m, s);
	pBox1->SetWindowText(CSstr);
}


void CcalcAppDlg::OnBnClickedcosh()
{
	static CString CSstr;
	_array1 = getArray();
	//cosh函数需替换
	_result = cosh(_array1);
	CSstr.Format(_T("%.8lf"), _result);
	pBox1->SetWindowText(CSstr);
}


void CcalcAppDlg::OnBnClickedcos()
{
	static CString CSstr;
	_array1 = getArray();
	//cos函数需替换
	_result = cos(_array1);
	CSstr.Format(_T("%.8lf"), _result);
	pBox1->SetWindowText(CSstr);
}


void CcalcAppDlg::OnBnClickedpower()
{
	_gotArray2 = false;
	_array1 = getArray();
	_operator = 6;
	pBox1->SetWindowText(_T("0"));
}


void CcalcAppDlg::OnBnClickedextract()
{
	_gotArray2 = false;
	_array1 = getArray();
	_operator = 7;
	pBox1->SetWindowText(_T("0"));
}


void CcalcAppDlg::OnBnClickedmc()
{
	_memory = 0;
}


void CcalcAppDlg::OnBnClickedmr()
{
	static CString CSstr;
	pBox1->GetWindowText(CSstr);
	_memory = _tstof(CSstr);
}


void CcalcAppDlg::OnBnClickedms()
{
	static CString CSstr;
	CSstr.Format(_T("%lf"), _memory);
	pBox1->SetWindowText(CSstr);
}


void CcalcAppDlg::OnBnClickedmplus()
{
	static CString CSstr;
	pBox1->GetWindowText(CSstr);
	_memory += _tstof(CSstr);
}


void CcalcAppDlg::OnBnClickedmminus()
{
	static CString CSstr;
	pBox1->GetWindowText(CSstr);
	_memory -= _tstof(CSstr);
}
