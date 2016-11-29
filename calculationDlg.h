// calculationDlg.h : header file
//

#if !defined(AFX_CALCULATIONDLG_H__700FEF8B_AF17_46F7_BE38_5B419DF190B2__INCLUDED_)
#define AFX_CALCULATIONDLG_H__700FEF8B_AF17_46F7_BE38_5B419DF190B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalculationDlg dialog

class CCalculationDlg : public CDialog
{
// Construction
public:
	CCalculationDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalculationDlg)
	enum { IDD = IDD_CALCULATION_DIALOG };
	CButton	m_fushu;
	CButton	m_yushu;
	CButton	m_daoshu;
	CButton	m_pingfang;
	CButton	m_genhao;
	CButton	m_delete;
	CButton	m_clear;
	CButton	m_dengyu;
	CButton	m_chu;
	CButton	m_cheng;
	CButton	m_jia;
	CButton	m_jian;
	CButton	m_point;
	CButton	m_0;
	CButton	m_1;
	CButton	m_2;
	CButton	m_3;
	CButton	m_4;
	CButton	m_5;
	CButton	m_6;
	CButton	m_7;
	CButton	m_8;
	CButton	m_9;
	double	m_result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalculationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButton10();
	afx_msg void OnButton23();
	afx_msg void OnChangeEdit1();
	afx_msg void Ondelete();
	afx_msg void Onclear();
	afx_msg void Onsqrt();
	afx_msg void Onpingfang();
	afx_msg void Ondaoshu();
	afx_msg void OnButton22();
	afx_msg void Onjia();
	afx_msg void Ondengyu();
	afx_msg void OnOutofmemoryAnimate2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void Onjian();
	afx_msg void Oncheng();
	afx_msg void Onchu();
	afx_msg void Onpoint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	double m_temp;//定义temp存储第一次输入的result
	int m_flag;//定义flag判断是否执行第二次输入
	int m_sign;//定义sign判断执行四则运算哪一种
	int m_sign2;//定义sign2判断是否点击小数点
	double t1,t2,t3,t4,t5,t6,t7,t8,t9,t0;//小数点后的数值
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATIONDLG_H__700FEF8B_AF17_46F7_BE38_5B419DF190B2__INCLUDED_)
