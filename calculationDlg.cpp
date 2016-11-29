// calculationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "calculation.h"
#include "calculationDlg.h"
#include<math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculationDlg dialog

CCalculationDlg::CCalculationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalculationDlg)
	m_result = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalculationDlg)
	DDX_Control(pDX, IDC_BUTTON23, m_fushu);
	DDX_Control(pDX, IDC_BUTTON22, m_yushu);
	DDX_Control(pDX, IDC_BUTTON21, m_daoshu);
	DDX_Control(pDX, IDC_BUTTON20, m_pingfang);
	DDX_Control(pDX, IDC_BUTTON18, m_genhao);
	DDX_Control(pDX, IDC_BUTTON17, m_delete);
	DDX_Control(pDX, IDC_BUTTON16, m_clear);
	DDX_Control(pDX, IDC_BUTTON15, m_dengyu);
	DDX_Control(pDX, IDC_BUTTON14, m_chu);
	DDX_Control(pDX, IDC_BUTTON13, m_cheng);
	DDX_Control(pDX, IDC_BUTTON19, m_jia);
	DDX_Control(pDX, IDC_BUTTON12, m_jian);
	DDX_Control(pDX, IDC_BUTTON11, m_point);
	DDX_Control(pDX, IDC_BUTTON10, m_0);
	DDX_Control(pDX, IDC_BUTTON1, m_1);
	DDX_Control(pDX, IDC_BUTTON2, m_2);
	DDX_Control(pDX, IDC_BUTTON3, m_3);
	DDX_Control(pDX, IDC_BUTTON4, m_4);
	DDX_Control(pDX, IDC_BUTTON5, m_5);
	DDX_Control(pDX, IDC_BUTTON6, m_6);
	DDX_Control(pDX, IDC_BUTTON7, m_7);
	DDX_Control(pDX, IDC_BUTTON8, m_8);
	DDX_Control(pDX, IDC_BUTTON9, m_9);
	DDX_Text(pDX, IDC_EDIT1, m_result);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalculationDlg, CDialog)
	//{{AFX_MSG_MAP(CCalculationDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON23, OnButton23)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON17, Ondelete)
	ON_BN_CLICKED(IDC_BUTTON16, Onclear)
	ON_BN_CLICKED(IDC_BUTTON18, Onsqrt)
	ON_BN_CLICKED(IDC_BUTTON20, Onpingfang)
	ON_BN_CLICKED(IDC_BUTTON21, Ondaoshu)
	ON_BN_CLICKED(IDC_BUTTON22, OnButton22)
	ON_BN_CLICKED(IDC_BUTTON19, Onjia)
	ON_BN_CLICKED(IDC_BUTTON15, Ondengyu)
	ON_BN_CLICKED(IDC_BUTTON12, Onjian)
	ON_BN_CLICKED(IDC_BUTTON13, Oncheng)
	ON_BN_CLICKED(IDC_BUTTON14, Onchu)
	ON_BN_CLICKED(IDC_BUTTON11, Onpoint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculationDlg message handlers

BOOL CCalculationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_flag=1;//初始化标记量flag
	m_temp=0;//初始化标记量temp
	m_sign=0;//初始化标记量sign
	m_sign2=0;//初始化标记量sign2
	t1=1;
	t2=2;
	t3=3;
	t4=4;
	t5=5;
	t6=6;
	t7=7;
	t8=8;
	t9=9;
	t0=0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculationDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculationDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCalculationDlg::OnButton1() 
{
	
	UpdateData(true);
	if(m_flag){//判断是否重新输入，若不是则执行以下代码
		{
		if(!m_sign2)//若未点击过小数点，则输入整数
		m_result=10*m_result+1;
		else{//若点击过小数点，则输入小数
			t1=t1/10;t2=t2/10;t3=t3/10;t4=t4/10;t5=t5/10;t6=t6/10;t7=t7/10;t8=t8/10;t9=t9/10;//每次点击小数后向后进一位
			m_result+=t1;
		}
	}
	}
	else//若是重新输入，则执行以下代码
	{
		m_result = 1;
		m_flag=1;
	}
	UpdateData(false);
}
//按键2到10类似按键1
void CCalculationDlg::OnButton2() 
{
UpdateData(true);
	if(m_flag){
	if(!m_sign2)
		m_result=10*m_result+2;
		else{
			t1=t1/10;t2=t2/10;t3=t3/10;t4=t4/10;t5=t5/10;t6=t6/10;t7=t7/10;t8=t8/10;t9=t9/10;
			m_result+=t2;
		}
	}
	else
	{
		m_result = 2;
		m_flag=1;
	}
	UpdateData(false);	
}

void CCalculationDlg::OnButton3() 
{
UpdateData(true);
		if(m_flag){
		if(!m_sign2)
		m_result=10*m_result+3;
		else{
			t1=t1/10;t2=t2/10;t3=t3/10;t4=t4/10;t5=t5/10;t6=t6/10;t7=t7/10;t8=t8/10;t9=t9/10;
			m_result+=t3;
		}
		}
	else
	{
		m_result = 3;
		m_flag=1;
	}
	UpdateData(false);	
}

void CCalculationDlg::OnButton4() 
{
	UpdateData(true);
	if(m_flag){
		if(!m_sign2)
		m_result=10*m_result+4;
		else{
			t1=t1/10;t2=t2/10;t3=t3/10;t4=t4/10;t5=t5/10;t6=t6/10;t7=t7/10;t8=t8/10;t9=t9/10;
			m_result+=t4;
		}}
	else
	{
		m_result = 4;
		m_flag=1;
	}
	UpdateData(false);
}

void CCalculationDlg::OnButton5() 
{
	UpdateData(true);
	if(m_flag){
		if(!m_sign2)
		m_result=10*m_result+5;
		else{
			t1=t1/10;t2=t2/10;t3=t3/10;t4=t4/10;t5=t5/10;t6=t6/10;t7=t7/10;t8=t8/10;t9=t9/10;
			m_result+=t5;
		}}
	else
	{
		m_result = 5;
		m_flag=1;
	}
	UpdateData(false);
	
}

void CCalculationDlg::OnButton6() 
{
	UpdateData(true);
		if(m_flag){
	if(!m_sign2)
		m_result=10*m_result+6;
		else{
			t1=t1/10;t2=t2/10;t3=t3/10;t4=t4/10;t5=t5/10;t6=t6/10;t7=t7/10;t8=t8/10;t9=t9/10;
			m_result+=t6;
		}}
	else
	{
		m_result = 6;
		m_flag=1;
	}
	UpdateData(false);
}

void CCalculationDlg::OnButton7() 
{
	UpdateData(true);
	if(m_flag){ 
	if(!m_sign2)
		m_result=10*m_result+7;
		else{
			t1=t1/10;t2=t2/10;t3=t3/10;t4=t4/10;t5=t5/10;t6=t6/10;t7=t7/10;t8=t8/10;t9=t9/10;
			m_result+=t7;
			}
	}
	else
	{
		m_result = 7;
		m_flag=1;
	}
	UpdateData(false);
}

void CCalculationDlg::OnButton8() 
{
	UpdateData(true);
	if(m_flag){
		if(!m_sign2)
		m_result=10*m_result+8;
		else{
			t1=t1/10;t2=t2/10;t3=t3/10;t4=t4/10;t5=t5/10;t6=t6/10;t7=t7/10;t8=t8/10;t9=t9/10;
			m_result+=t8;
		}}
	else
	{
		m_result = 8;
		m_flag=1;
	}
	UpdateData(false);
}

void CCalculationDlg::OnButton9() 
{
	UpdateData(true);
	if(m_flag){
		if(!m_sign2)
		m_result=10*m_result+9;
		else{
			t1=t1/10;t2=t2/10;t3=t3/10;t4=t4/10;t5=t5/10;t6=t6/10;t7=t7/10;t8=t8/10;t9=t9/10;
			m_result+=t9;
		}}
	else
	{
		m_result = 9;
		m_flag=1;
	}
	UpdateData(false);
}

void CCalculationDlg::OnButton10() 
{
	UpdateData(true);
		if(m_flag){
			if(!m_sign2)
			m_result=10*m_result;
			else{
					t1=t1/10;t2=t2/10;t3=t3/10;t4=t4/10;t5=t5/10;t6=t6/10;t7=t7/10;t8=t8/10;t9=t9/10;
				}
		}
	else
	{
		m_result = 0;
		m_flag=1;
	}
	UpdateData(false);
}
//按键2到10类似按键1
void CCalculationDlg::OnButton23() //取负数
{
	UpdateData(true);
	m_result=-m_result;
	UpdateData(false);
}

void CCalculationDlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CCalculationDlg::Ondelete() //删除一位数
{
	UpdateData(true);
	m_result=(int)m_result/10;
	// TODO: Add your control notification handler code here
	UpdateData(false);
}

void CCalculationDlg::Onclear() //清屏
{
	UpdateData(true);
	m_result=0;
	m_temp=0;
	m_sign=0;
	m_sign2=0;
	t1=1;t2=2;t3=3;t4=4;t5=5;t6=6;t7=7;t8=8;t9=9;
	// TODO: Add your control notification handler code here
	UpdateData(false);
}

void CCalculationDlg::Onsqrt() //取根号
{

	UpdateData(true);
	m_result=sqrt(m_result);
	// TODO: Add your control notification handler code here
	UpdateData(false);
	// TODO: Add your control notification handler code here
	
}

void CCalculationDlg::Onpingfang() //取平方
{

	UpdateData(true);
	m_result=m_result*m_result;
	// TODO: Add your control notification handler code here
	UpdateData(false);	
}

void CCalculationDlg::Ondaoshu() //取倒数
{

	UpdateData(true);
	m_result=1/m_result;
	// TODO: Add your control notification handler code here
	UpdateData(false);	
}

void CCalculationDlg::OnButton22() //
{

	UpdateData(true);
	m_result=(int)(m_result)%10;
	// TODO: Add your control notification handler code here
	UpdateData(false);	
}

void CCalculationDlg::Onjia() //加法，将sign置1，并用temp存储第一次输入的result
{
	// TODO: Add your control notification handler code here
	m_flag=0;
	m_sign2=0;
	t1=1;t2=2;t3=3;t4=4;t5=5;t6=6;t7=7;t8=8;t9=9;
	m_temp=m_result;
	m_sign=1;
}

void CCalculationDlg::Ondengyu() //等于，通过sign值判断执行什么代码
{
	UpdateData(true);
	switch(m_sign){//判断sign为何值
		case 1:m_result=m_temp+m_result;break;
		case 2:m_result=m_temp-m_result;break;
		case 3:m_result=m_temp*m_result;break;		
		case 4:m_result=m_temp/m_result;break;
	}
	m_temp=0;
	t1=1;t2=2;t3=3;t4=4;t5=5;t6=6;t7=7;t8=8;t9=9;
	UpdateData(false);
}

void CCalculationDlg::Onjian() //减号，将sign置2，并用temp存储第一次输入的result
{
	m_flag=0;
	m_sign2=0;
	t1=1;t2=2;t3=3;t4=4;t5=5;t6=6;t7=7;t8=8;t9=9;
	m_temp=m_result;
	m_sign=2;
	// TODO: Add your control notification handler code here	
}

void CCalculationDlg::Oncheng() //乘号，将sign置3，并用temp存储第一次输入的result
{
	m_flag=0;
	m_sign2=0;
	t1=1;t2=2;t3=3;t4=4;t5=5;t6=6;t7=7;t8=8;t9=9;
	m_temp=m_result;
	m_sign=3;
	// TODO: Add your control notification handler code here
	
}

void CCalculationDlg::Onchu() //除号，将sign置4，并用temp存储第一次输入的result
{
	m_flag=0;
	m_sign2=0;
	t1=1;t2=2;t3=3;t4=4;t5=5;t6=6;t7=7;t8=8;t9=9;
	m_temp=m_result;
	m_sign=4;	
}

void CCalculationDlg::Onpoint() //小数点，将sign2置1
{
    m_sign2=1;	
}
