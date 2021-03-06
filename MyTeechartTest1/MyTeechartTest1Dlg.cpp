
// MyTeechartTest1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyTeechartTest1.h"
#include "MyTeechartTest1Dlg.h"
#include "afxdialogex.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define MAX_DATA_SIZE 20

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


// CMyTeechartTest1Dlg 对话框




CMyTeechartTest1Dlg::CMyTeechartTest1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyTeechartTest1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyTeechartTest1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TCHART1, m_Teechart1);
	DDX_Control(pDX, IDC_TEECOMMANDER1, m_TeeCommand1);
}

BEGIN_MESSAGE_MAP(CMyTeechartTest1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMyTeechartTest1Dlg 消息处理程序

BOOL CMyTeechartTest1Dlg::OnInitDialog()
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_TeeCommand1.put_ChartLink(m_Teechart1.get_ChartLink());
	m_TeeCommand1.put_Color(RGB(233,233,233));
	m_TeeCommand1.put_Vertical(TRUE);//各个button竖直排列

	////设置图标的宽度和高度
	////m_Teechart1.put_Height(400);
	////m_Teechart1.put_Width(600);

	////设置显示模式（3D/2D）
	((CAspect)m_Teechart1.get_Aspect()).put_View3D(TRUE);
	((CAspect)m_Teechart1.get_Aspect()).put_Chart3DPercent(60);

	////设置图表的标题（CTitles\CStrings）
	linTitle = (CTitles)m_Teechart1.get_Header();
	((CStrings)linTitle.get_Text()).Clear();
	((CStrings)linTitle.get_Text()).Add(COleVariant(_T("")));

	////隐藏图例
	linLengend = (CLegend)m_Teechart1.get_Legend();
	linLengend.put_Visible(FALSE);

	////设置画布
	//linPanel = (CPanel)m_Teechart1.get_Panel();
	//linPanel.put_Color(RGB(255,235,205));//背景色
	////linPanel.put_BorderStyle(0);//暂时不清楚意义

	////设置画布为渐变背景
	//((CGradient)linPanel.get_Gradient()).put_Visible(TRUE);
	//((CGradient)linPanel.get_Gradient()).put_StartColor(RGB(182,182,182));
	//((CGradient)linPanel.get_Gradient()).put_EndColor(RGB(250,250,250));

	////设置坐标轴属性
	linAxes = (CAxes)m_Teechart1.get_Axis();
	//((CAxis)linAxes.get_Bottom()).put_AutomaticMinimum(FALSE);
	//((CAxis)linAxes.get_Bottom()).put_AutomaticMaximum(FALSE);
	//((CAxis)linAxes.get_Bottom()).put_Minimum(0);
	//((CAxis)linAxes.get_Bottom()).put_Maximum(20);
	//
	((CAxisTitle)((CAxis)linAxes.get_Bottom()).get_Title()).put_Caption(_T("x轴"));
	//((CAxisLabels)((CAxis)linAxes.get_Bottom()).get_Labels()).put_ValueFormat(_T("0.0"));
	//((CAxis)linAxes.get_Bottom()).Scroll(1.0,TRUE);//貌似没起作用

	//((CAxis)linAxes.get_Left()).put_AutomaticMinimum(FALSE);
	//((CAxis)linAxes.get_Left()).put_AutomaticMaximum(FALSE);
	//((CAxis)linAxes.get_Left()).put_Minimum(0);
	//((CAxis)linAxes.get_Left()).put_Maximum(300);
	((CAxisTitle)((CAxis)linAxes.get_Left()).get_Title()).put_Caption(_T("y轴"));
	((CAxisTitle)((CAxis)linAxes.get_Left()).get_Title()).put_Angle(0);

	((CAxis)linAxes.get_Depth()).put_Visible(TRUE);
	((CAxisTitle)((CAxis)linAxes.get_Depth()).get_Title()).put_Caption(_T("z轴"));
	((CAxisLabels)((CAxis)linAxes.get_Bottom()).get_Labels()).put_Style(0);


	////删除所有曲线
	//m_Teechart1.RemoveAllSeries();

	////构建数据数组
	//COleSafeArray XValues;  
	//COleSafeArray YValues; 
	//DWORD Xnum[] = {MAX_DATA_SIZE};
	//DWORD Ynum[] = {MAX_DATA_SIZE};
	//XValues.Create(VT_R8, 1, Xnum);
	//YValues.Create(VT_R8, 1, Ynum);
	//double tmp;  
	//long index=0;  
	//for(int i=0; i<MAX_DATA_SIZE; i++)  
	//{  
	//	tmp = i;  
	//	XValues.PutElement(&index, &tmp);  
	//	tmp = rand() % 250;  
	//	YValues.PutElement(&index, &tmp);  
	//	index++;  
	//}

	////添加曲线
	//m_Teechart1.AddSeries(scPoint3D);
	//linSeries = ((CSeries)m_Teechart1.Series(0));
	//for (double i=0; i<20; i+=0.3)
	//{
	//	for (double j=0; j<20; j+=0.3)
	//	{
	//		((CPoint3DSeries)linSeries.get_asPoint3D()).AddXYZ(i,i*j,j,NULL,RGB(255,0,0));
	//	}
	//}

	m_Teechart1.AddSeries(scPoint3D);
	
	//m_Teechart1.get_ClipPoints();
	linSeries = ((CSeries)m_Teechart1.Series(0));
	linSeries.put_Color(RGB(0,0,255));

	((CPointer)((CPoint3DSeries)linSeries.get_asPoint3D()).get_Pointer()).put_Style(psStar);
	((CPointer)((CPoint3DSeries)linSeries.get_asPoint3D()).get_Pointer()).put_Visible(TRUE);
	((CPen0)((CPoint3DSeries)linSeries.get_asPoint3D()).get_Pen()).put_Color(RGB(255,0,0));

	/*
	double r = 5;
	for (double i=-r; i<=r; i+=0.1)
	{
		for (double j=-r; j<=r; j+=0.1)
		{
			double k = r*r-i*i-j*j;
			if (k >= 0)
			{
				k = sqrt(k);
				((CPoint3DSeries)linSeries.get_asPoint3D()).AddXYZ(i,j,k,NULL,RGB(255,0,0));
				((CPoint3DSeries)linSeries.get_asPoint3D()).AddXYZ(i,j,-k,NULL,RGB(0,255,0));
			}		
		}
	}
	*/

	FILE *p = NULL;
	float i,j,k;
	p = fopen("1.txt","rb");
	if (p)
	{
		while(-1 != fscanf(p,"%f %f %f",&i,&j,&k))
		{
			((CPoint3DSeries)linSeries.get_asPoint3D()).AddXYZ(i,j,k,NULL,RGB(255,0,0));
		}
		fclose(p);
	}
	
	//for (int i=0; i<MAX_DATA_SIZE; i++)
	//{
	//	linSeries.AddXY(i+1, rand()%250, NULL, RGB(255,0,0));
	//}
	////linSeries.FillSampleValues(16);
	////linSeries.AddArray(MAX_DATA_SIZE, XValues, YValues);
	//linSeries.put_Title(CString("First Series"));
	//linSeries.put_Color(RGB(250,10,15));

	////是否在图表每个点中显示y值
	//((CMarks)linSeries.get_Marks()).put_Visible(TRUE);
	//((CMarks)linSeries.get_Marks()).put_Style(smsPercent);//设置marks风格，见枚举EMarkStyle
	//((CMarks)linSeries.get_Marks()).put_BackColor(RGB(0,255,0));
	//((CMarks)linSeries.get_Marks()).put_Color(RGB(0,0,255));//这个跟上面到底是什么差别???

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMyTeechartTest1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyTeechartTest1Dlg::OnPaint()
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
HCURSOR CMyTeechartTest1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

