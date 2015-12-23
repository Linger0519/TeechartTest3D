
// MyTeechartTest1Dlg.h : ͷ�ļ�
//

#pragma once
#include "tchart1.h"

#include "CSeries.h" 
#include "CAxis.h"
#include "CAxisTitle.h"
#include "CAxisLabels.h"
#include "CAxes.h"
#include "CLegend.h"
#include "CStrings.h"
#include "CTitles.h"
#include "CPanel.h"
#include "CGradient.h"
#include "CAspect.h"
#include "CMarks.h"
#include "CPoint3DSeries.h"
#include "CIsoSurfaceSeries.h"
#include "CPointer.h"
#include "CPen0.h"
#include "teecommander1.h"

// CMyTeechartTest1Dlg �Ի���
class CMyTeechartTest1Dlg : public CDialogEx
{
// ����
public:
	CMyTeechartTest1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYTEECHARTTEST1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTchart1 m_Teechart1;
	CSeries linSeries;
	CAxes linAxes;
	CLegend linLengend;
	CTitles linTitle;
	CPanel linPanel;
	CTeecommander1 m_TeeCommand1;
};
