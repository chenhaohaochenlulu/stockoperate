#pragma once
#include < vcclr.h >
#include "tabData.h"
#include "donate.h"
#include "wOperateSetting.h"
char object[OBJECT_LEN];
double price=0;
CtabData  tabDataYear,  tabDataMonth, tabDataWeek, tabDataDay, tabData4Hour, tabDataHour, tabData45Min, tabData30Min, tabData15Min, tabData10Min, tabData5Min;
namespace woperate {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OperateSetting;
	using namespace Donate;
	/// <summary>
	/// Summary for FormParse
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormParse : public System::Windows::Forms::Form
	{
	public:
		FormParse(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		int isNumber(String ^str)
		{
			char buf[OBJECT_LEN];
			 // Pin memory so GC can't move it while native function is called
			 pin_ptr<const wchar_t> wch = PtrToStringChars(str);

			 size_t convertedChars = 0;
			 size_t  sizeInBytes = ((str->Length + 1) * 2);
			 errno_t err = 0;
			 char    *ch = buf;//(char *)malloc(sizeInBytes);
			 if(sizeInBytes>OBJECT_LEN)sizeInBytes=OBJECT_LEN-2;

			 err = wcstombs_s(&convertedChars, 
				 ch, sizeInBytes,
				 wch, sizeInBytes);
			 int n;
			 for(n=0;n<OBJECT_LEN;n++)
			 {
			    if(buf[n]==0) return 0;
				if(buf[n]<='9'&&buf[n]>='0') return 1;
			 }
			 return 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormParse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  parseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::Label^  labelPrice;
	private: System::Windows::Forms::TextBox^  textBoxPrice;
	private: System::Windows::Forms::TabPage^  tab10Min;
	private: System::Windows::Forms::TabPage^  tab15Min;
	private: System::Windows::Forms::TabPage^  tab30Min;
	private: System::Windows::Forms::TabPage^  tab45Min;
	private: System::Windows::Forms::TabPage^  tabHour;
	private: System::Windows::Forms::TabPage^  tab4Hour;
	private: System::Windows::Forms::TabPage^  tabDay;
	private: System::Windows::Forms::TabPage^  tabWeek;
	private: System::Windows::Forms::TabPage^  tabMonth;
	private: System::Windows::Forms::TabPage^  tabYear;
	private: System::Windows::Forms::TabControl^  woperateParseTab;
	private: System::Windows::Forms::TabPage^  tab5Min;
	private: System::Windows::Forms::Label^  labelObject;
	private: System::Windows::Forms::TextBox^  textBoxObject;
	private: System::Windows::Forms::Button^  buttonStart;
	private: System::Windows::Forms::Label^  label10MinMADir6;
	private: System::Windows::Forms::TextBox^  textBox10MinMA6;
	private: System::Windows::Forms::TextBox^  textBox10MinMA5;
	private: System::Windows::Forms::Label^  label10MinMA6;
	private: System::Windows::Forms::Label^  label10MinMA5;
	private: System::Windows::Forms::Label^  label10MinMADir5;
	private: System::Windows::Forms::ListBox^  listBox10MinMADir5;
	private: System::Windows::Forms::Label^  label10MinMA56;
	private: System::Windows::Forms::Label^  label10MinMADir4;
	private: System::Windows::Forms::ListBox^  listBox10MinMADir4;
	private: System::Windows::Forms::TextBox^  textBox10MinMA4;
	private: System::Windows::Forms::TextBox^  textBox10MinMA3;
	private: System::Windows::Forms::Label^  label10MinMA4;
	private: System::Windows::Forms::Label^  label10MinMA3;
	private: System::Windows::Forms::Label^  label10MinMADir3;
	private: System::Windows::Forms::ListBox^  listBox10MinMADir3;
	private: System::Windows::Forms::Label^  label10MinMA34;
	private: System::Windows::Forms::Label^  label10MinMADir2;
	private: System::Windows::Forms::ListBox^  listBox10MinMADir2;
	private: System::Windows::Forms::TextBox^  textBox10MinMA2;
	private: System::Windows::Forms::TextBox^  textBox10MinMA1;
	private: System::Windows::Forms::Label^  label10MinMA2;
	private: System::Windows::Forms::Label^  label10MinMA1;
	private: System::Windows::Forms::Label^  label10MinMADir1;
	private: System::Windows::Forms::ListBox^  listBox10MinMADir1;
	private: System::Windows::Forms::Label^  label10MinMA12;
	private: System::Windows::Forms::TextBox^  textBox10MinCciCci;
	private: System::Windows::Forms::Label^  label10MinCciCci;
	private: System::Windows::Forms::Label^  label10MinCciDir;
	private: System::Windows::Forms::ListBox^  listBox10MinCciDir;
	private: System::Windows::Forms::Label^  label10MinCci;
	private: System::Windows::Forms::TextBox^  textBox10MinCrC;
	private: System::Windows::Forms::Label^  label10MinCrC;
	private: System::Windows::Forms::TextBox^  textBox10MinCrB;
	private: System::Windows::Forms::Label^  label10MinCrB;
	private: System::Windows::Forms::TextBox^  textBox10MinCrA;
	private: System::Windows::Forms::TextBox^  textBox10MinCrCr;
	private: System::Windows::Forms::Label^  label10MinCrA;
	private: System::Windows::Forms::Label^  label10MinCrCr;
	private: System::Windows::Forms::Label^  label10MinCrDir;
	private: System::Windows::Forms::ListBox^  listBox10MinCrDir;
	private: System::Windows::Forms::Label^  label10MinCr;
	private: System::Windows::Forms::TextBox^  textBox10MinDmaAma;
	private: System::Windows::Forms::TextBox^  textBox10MinDmaDma;
	private: System::Windows::Forms::Label^  label10MinDmaAma;
	private: System::Windows::Forms::Label^  label10MinDmaDma;
	private: System::Windows::Forms::Label^  label10MinDmaDir;
	private: System::Windows::Forms::ListBox^  listBox10MinDmaDir;
	private: System::Windows::Forms::Label^  label10MinDma;
	private: System::Windows::Forms::TextBox^  textBox10MinRocRocma;
	private: System::Windows::Forms::TextBox^  textBox10MinRocRoc;
	private: System::Windows::Forms::Label^  label10MinRocRocma;
	private: System::Windows::Forms::Label^  label10MinRocRoc;
	private: System::Windows::Forms::Label^  label10MinRocDir;
	private: System::Windows::Forms::ListBox^  listBox10MinRocDir;
	private: System::Windows::Forms::Label^  label10MinRoc;
	private: System::Windows::Forms::TextBox^  textBox10MinVrLong;
	private: System::Windows::Forms::TextBox^  textBox10MinVrShort;
	private: System::Windows::Forms::Label^  label10MinVrLong;
	private: System::Windows::Forms::Label^  label10MinVrShort;
	private: System::Windows::Forms::Label^  label10MinVrDir;
	private: System::Windows::Forms::ListBox^  listBox10MinVrDir;
	private: System::Windows::Forms::Label^  label10MinVr;
	private: System::Windows::Forms::Label^  label10MinVolDir2;
	private: System::Windows::Forms::ListBox^  listBox10MinVolDir2;
	private: System::Windows::Forms::TextBox^  textBox10MinVol2;
	private: System::Windows::Forms::TextBox^  textBox10MinVol1;
	private: System::Windows::Forms::Label^  label10MinVol2;
	private: System::Windows::Forms::Label^  label10MinVol1;
	private: System::Windows::Forms::Label^  label10MinVolDir1;
	private: System::Windows::Forms::ListBox^  listBox10MinVolDir1;
	private: System::Windows::Forms::Label^  label10MinVol;
	private: System::Windows::Forms::TextBox^  textBox10MinWr2;
	private: System::Windows::Forms::TextBox^  textBox10MinWr1;
	private: System::Windows::Forms::Label^  label10MinWr2;
	private: System::Windows::Forms::Label^  label10MinWr1;
	private: System::Windows::Forms::Label^  label10MinWrDir;
	private: System::Windows::Forms::ListBox^  listBox10MinWrDir;
	private: System::Windows::Forms::Label^  label10MinWr;
	private: System::Windows::Forms::TextBox^  textBox10MinRsiLong;
	private: System::Windows::Forms::TextBox^  textBox10MinRsiMiddle;
	private: System::Windows::Forms::TextBox^  textBox10MinRsiShort;
	private: System::Windows::Forms::Label^  label10MinRsiLong;
	private: System::Windows::Forms::Label^  label10MinRsiMiddle;
	private: System::Windows::Forms::Label^  label10MinRsiShort;
	private: System::Windows::Forms::Label^  label10MinRsiDir;
	private: System::Windows::Forms::ListBox^  listBox10MinRsiDir;
	private: System::Windows::Forms::Label^  label10MinRsi;
	private: System::Windows::Forms::TextBox^  textBox10MinKdjJ;
	private: System::Windows::Forms::TextBox^  textBox10MinKdjD;
	private: System::Windows::Forms::TextBox^  textBox10MinKdjK;
	private: System::Windows::Forms::Label^  label10MinKdjJ;
	private: System::Windows::Forms::Label^  label10MinKdjD;
	private: System::Windows::Forms::Label^  label10MinKdjK;
	private: System::Windows::Forms::Label^  label10MinKdjDir;
	private: System::Windows::Forms::ListBox^  listBox10MinKdjDir;
	private: System::Windows::Forms::Label^  label10MinKdj;
	private: System::Windows::Forms::TextBox^  textBox10MinMacdDea;
	private: System::Windows::Forms::TextBox^  textBox10MinMacdDif;
	private: System::Windows::Forms::TextBox^  textBox10MinMacdMacd;
	private: System::Windows::Forms::Label^  label10MinMacdDea;
	private: System::Windows::Forms::Label^  label10MinMacdDif;
	private: System::Windows::Forms::Label^  label10MinMacdMacd;
	private: System::Windows::Forms::Label^  label10MinMacdDir;
	private: System::Windows::Forms::ListBox^  listBox10MinMacdDir;
	private: System::Windows::Forms::Label^  label10MinMacd;
	private: System::Windows::Forms::TextBox^  textBox10MinBollUpper;
	private: System::Windows::Forms::TextBox^  textBox10MinBollMid;
	private: System::Windows::Forms::TextBox^  textBox10MinBollLow;
	private: System::Windows::Forms::Label^  label10MinBollUpper;
	private: System::Windows::Forms::Label^  label10MinBollMid;
	private: System::Windows::Forms::Label^  label10MinBollLow;
	private: System::Windows::Forms::Label^  label10MinBollDir;
	private: System::Windows::Forms::ListBox^  listBox10MinBollDir;
	private: System::Windows::Forms::Label^  label10MinBoll;
	private: System::Windows::Forms::Label^  label15MinMADir6;
	private: System::Windows::Forms::TextBox^  textBox15MinMA6;
	private: System::Windows::Forms::TextBox^  textBox15MinMA5;
	private: System::Windows::Forms::Label^  label15MinMA6;
	private: System::Windows::Forms::Label^  label15MinMA5;
	private: System::Windows::Forms::Label^  label15MinMADir5;
	private: System::Windows::Forms::ListBox^  listBox15MinMADir5;
	private: System::Windows::Forms::Label^  label15MinMA56;
	private: System::Windows::Forms::Label^  label15MinMADir4;
	private: System::Windows::Forms::ListBox^  listBox15MinMADir4;
	private: System::Windows::Forms::TextBox^  textBox15MinMA4;
	private: System::Windows::Forms::TextBox^  textBox15MinMA3;
	private: System::Windows::Forms::Label^  label15MinMA4;
	private: System::Windows::Forms::Label^  label15MinMA3;
	private: System::Windows::Forms::Label^  label15MinMADir3;
	private: System::Windows::Forms::ListBox^  listBox15MinMADir3;
	private: System::Windows::Forms::Label^  label15MinMA34;
	private: System::Windows::Forms::Label^  label15MinMADir2;
	private: System::Windows::Forms::ListBox^  listBox15MinMADir2;
	private: System::Windows::Forms::TextBox^  textBox15MinMA2;
	private: System::Windows::Forms::TextBox^  textBox15MinMA1;
	private: System::Windows::Forms::Label^  label15MinMA2;
	private: System::Windows::Forms::Label^  label15MinMA1;
	private: System::Windows::Forms::Label^  label15MinMADir1;
	private: System::Windows::Forms::ListBox^  listBox15MinMADir1;
	private: System::Windows::Forms::Label^  label15MinMA12;
	private: System::Windows::Forms::TextBox^  textBox15MinCciCci;
	private: System::Windows::Forms::Label^  label15MinCciCci;
	private: System::Windows::Forms::Label^  label15MinCciDir;
	private: System::Windows::Forms::ListBox^  listBox15MinCciDir;
	private: System::Windows::Forms::Label^  label15MinCci;
	private: System::Windows::Forms::TextBox^  textBox15MinCrC;
	private: System::Windows::Forms::Label^  label15MinCrC;
	private: System::Windows::Forms::TextBox^  textBox15MinCrB;
	private: System::Windows::Forms::Label^  label15MinCrB;
	private: System::Windows::Forms::TextBox^  textBox15MinCrA;
	private: System::Windows::Forms::TextBox^  textBox15MinCrCr;
	private: System::Windows::Forms::Label^  label15MinCrA;
	private: System::Windows::Forms::Label^  label15MinCrCr;
	private: System::Windows::Forms::Label^  label15MinCrDir;
	private: System::Windows::Forms::ListBox^  listBox15MinCrDir;
	private: System::Windows::Forms::Label^  label15MinCr;
	private: System::Windows::Forms::TextBox^  textBox15MinDmaAma;
	private: System::Windows::Forms::TextBox^  textBox15MinDmaDma;
	private: System::Windows::Forms::Label^  label15MinDmaAma;
	private: System::Windows::Forms::Label^  label15MinDmaDma;
	private: System::Windows::Forms::Label^  label15MinDmaDir;
	private: System::Windows::Forms::ListBox^  listBox15MinDmaDir;
	private: System::Windows::Forms::Label^  label15MinDma;
	private: System::Windows::Forms::TextBox^  textBox15MinRocRocma;
	private: System::Windows::Forms::TextBox^  textBox15MinRocRoc;
	private: System::Windows::Forms::Label^  label15MinRocRocma;
	private: System::Windows::Forms::Label^  label15MinRocRoc;
	private: System::Windows::Forms::Label^  label15MinRocDir;
	private: System::Windows::Forms::ListBox^  listBox15MinRocDir;
	private: System::Windows::Forms::Label^  label15MinRoc;
	private: System::Windows::Forms::TextBox^  textBox15MinVrLong;
	private: System::Windows::Forms::TextBox^  textBox15MinVrShort;
	private: System::Windows::Forms::Label^  label15MinVrLong;
	private: System::Windows::Forms::Label^  label15MinVrShort;
	private: System::Windows::Forms::Label^  label15MinVrDir;
	private: System::Windows::Forms::ListBox^  listBox15MinVrDir;
	private: System::Windows::Forms::Label^  label15MinVr;
	private: System::Windows::Forms::Label^  label15MinVolDir2;
	private: System::Windows::Forms::ListBox^  listBox15MinVolDir2;
	private: System::Windows::Forms::TextBox^  textBox15MinVol2;
	private: System::Windows::Forms::TextBox^  textBox15MinVol1;
	private: System::Windows::Forms::Label^  label15MinVol2;
	private: System::Windows::Forms::Label^  label15MinVol1;
	private: System::Windows::Forms::Label^  label15MinVolDir1;
	private: System::Windows::Forms::ListBox^  listBox15MinVolDir1;
	private: System::Windows::Forms::Label^  label15MinVol;
	private: System::Windows::Forms::TextBox^  textBox15MinWr2;
	private: System::Windows::Forms::TextBox^  textBox15MinWr1;
	private: System::Windows::Forms::Label^  label15MinWr2;
	private: System::Windows::Forms::Label^  label15MinWr1;
	private: System::Windows::Forms::Label^  label15MinWrDir;
	private: System::Windows::Forms::ListBox^  listBox15MinWrDir;
	private: System::Windows::Forms::Label^  label15MinWr;
	private: System::Windows::Forms::TextBox^  textBox15MinRsiLong;
	private: System::Windows::Forms::TextBox^  textBox15MinRsiMiddle;
	private: System::Windows::Forms::TextBox^  textBox15MinRsiShort;
	private: System::Windows::Forms::Label^  label15MinRsiLong;
	private: System::Windows::Forms::Label^  label15MinRsiMiddle;
	private: System::Windows::Forms::Label^  label15MinRsiShort;
	private: System::Windows::Forms::Label^  label15MinRsiDir;
	private: System::Windows::Forms::ListBox^  listBox15MinRsiDir;
	private: System::Windows::Forms::Label^  label15MinRsi;
	private: System::Windows::Forms::TextBox^  textBox15MinKdjJ;
	private: System::Windows::Forms::TextBox^  textBox15MinKdjD;
	private: System::Windows::Forms::TextBox^  textBox15MinKdjK;
	private: System::Windows::Forms::Label^  label15MinKdjJ;
	private: System::Windows::Forms::Label^  label15MinKdjD;
	private: System::Windows::Forms::Label^  label15MinKdjK;
	private: System::Windows::Forms::Label^  label15MinKdjDir;
	private: System::Windows::Forms::ListBox^  listBox15MinKdjDir;
	private: System::Windows::Forms::Label^  label15MinKdj;
	private: System::Windows::Forms::TextBox^  textBox15MinMacdDea;
	private: System::Windows::Forms::TextBox^  textBox15MinMacdDif;
	private: System::Windows::Forms::TextBox^  textBox15MinMacdMacd;
	private: System::Windows::Forms::Label^  label15MinMacdDea;
	private: System::Windows::Forms::Label^  label15MinMacdDif;
	private: System::Windows::Forms::Label^  label15MinMacdMacd;
	private: System::Windows::Forms::Label^  label15MinMacdDir;
	private: System::Windows::Forms::ListBox^  listBox15MinMacdDir;
	private: System::Windows::Forms::Label^  label15MinMacd;
	private: System::Windows::Forms::TextBox^  textBox15MinBollUpper;
	private: System::Windows::Forms::TextBox^  textBox15MinBollMid;
	private: System::Windows::Forms::TextBox^  textBox15MinBollLow;
	private: System::Windows::Forms::Label^  label15MinBollUpper;
	private: System::Windows::Forms::Label^  label15MinBollMid;
	private: System::Windows::Forms::Label^  label15MinBollLow;
	private: System::Windows::Forms::Label^  label15MinBollDir;
	private: System::Windows::Forms::ListBox^  listBox15MinBollDir;
	private: System::Windows::Forms::Label^  label15MinBoll;
	private: System::Windows::Forms::Label^  label30MinMADir6;
	private: System::Windows::Forms::TextBox^  textBox30MinMA6;
	private: System::Windows::Forms::TextBox^  textBox30MinMA5;
	private: System::Windows::Forms::Label^  label30MinMA6;
	private: System::Windows::Forms::Label^  label30MinMA5;
	private: System::Windows::Forms::Label^  label30MinMADir5;
	private: System::Windows::Forms::ListBox^  listBox30MinMADir5;
	private: System::Windows::Forms::Label^  label30MinMA56;
	private: System::Windows::Forms::Label^  label30MinMADir4;
	private: System::Windows::Forms::ListBox^  listBox30MinMADir4;
	private: System::Windows::Forms::TextBox^  textBox30MinMA4;
	private: System::Windows::Forms::TextBox^  textBox30MinMA3;
	private: System::Windows::Forms::Label^  label30MinMA4;
	private: System::Windows::Forms::Label^  label30MinMA3;
	private: System::Windows::Forms::Label^  label30MinMADir3;
	private: System::Windows::Forms::ListBox^  listBox30MinMADir3;
	private: System::Windows::Forms::Label^  label30MinMA34;
	private: System::Windows::Forms::Label^  label30MinMADir2;
	private: System::Windows::Forms::ListBox^  listBox30MinMADir2;
	private: System::Windows::Forms::TextBox^  textBox30MinMA2;
	private: System::Windows::Forms::TextBox^  textBox30MinMA1;
	private: System::Windows::Forms::Label^  label30MinMA2;
	private: System::Windows::Forms::Label^  label30MinMA1;
	private: System::Windows::Forms::Label^  label30MinMADir1;
	private: System::Windows::Forms::ListBox^  listBox30MinMADir1;
	private: System::Windows::Forms::Label^  label30MinMA12;
	private: System::Windows::Forms::TextBox^  textBox30MinCciCci;
	private: System::Windows::Forms::Label^  label30MinCciCci;
	private: System::Windows::Forms::Label^  label30MinCciDir;
	private: System::Windows::Forms::ListBox^  listBox30MinCciDir;
	private: System::Windows::Forms::Label^  label30MinCci;
	private: System::Windows::Forms::TextBox^  textBox30MinCrC;
	private: System::Windows::Forms::Label^  label30MinCrC;
	private: System::Windows::Forms::TextBox^  textBox30MinCrB;
	private: System::Windows::Forms::Label^  label30MinCrB;
	private: System::Windows::Forms::TextBox^  textBox30MinCrA;
	private: System::Windows::Forms::TextBox^  textBox30MinCrCr;
	private: System::Windows::Forms::Label^  label30MinCrA;
	private: System::Windows::Forms::Label^  label30MinCrCr;
	private: System::Windows::Forms::Label^  label30MinCrDir;
	private: System::Windows::Forms::ListBox^  listBox30MinCrDir;
	private: System::Windows::Forms::Label^  label30MinCr;
	private: System::Windows::Forms::TextBox^  textBox30MinDmaAma;
	private: System::Windows::Forms::TextBox^  textBox30MinDmaDma;
	private: System::Windows::Forms::Label^  label30MinDmaAma;
	private: System::Windows::Forms::Label^  label30MinDmaDma;
	private: System::Windows::Forms::Label^  label30MinDmaDir;
	private: System::Windows::Forms::ListBox^  listBox30MinDmaDir;
	private: System::Windows::Forms::Label^  label30MinDma;
	private: System::Windows::Forms::TextBox^  textBox30MinRocRocma;
	private: System::Windows::Forms::TextBox^  textBox30MinRocRoc;
	private: System::Windows::Forms::Label^  label30MinRocRocma;
	private: System::Windows::Forms::Label^  label30MinRocRoc;
	private: System::Windows::Forms::Label^  label30MinRocDir;
	private: System::Windows::Forms::ListBox^  listBox30MinRocDir;
	private: System::Windows::Forms::Label^  label30MinRoc;
	private: System::Windows::Forms::TextBox^  textBox30MinVrLong;
	private: System::Windows::Forms::TextBox^  textBox30MinVrShort;
	private: System::Windows::Forms::Label^  label30MinVrLong;
	private: System::Windows::Forms::Label^  label30MinVrShort;
	private: System::Windows::Forms::Label^  label30MinVrDir;
	private: System::Windows::Forms::ListBox^  listBox30MinVrDir;
	private: System::Windows::Forms::Label^  label30MinVr;
	private: System::Windows::Forms::Label^  label30MinVolDir2;
	private: System::Windows::Forms::ListBox^  listBox30MinVolDir2;
	private: System::Windows::Forms::TextBox^  textBox30MinVol2;
	private: System::Windows::Forms::TextBox^  textBox30MinVol1;
	private: System::Windows::Forms::Label^  label30MinVol2;
	private: System::Windows::Forms::Label^  label30MinVol1;
	private: System::Windows::Forms::Label^  label30MinVolDir1;
	private: System::Windows::Forms::ListBox^  listBox30MinVolDir1;
	private: System::Windows::Forms::Label^  label30MinVol;
	private: System::Windows::Forms::TextBox^  textBox30MinWr2;
	private: System::Windows::Forms::TextBox^  textBox30MinWr1;
	private: System::Windows::Forms::Label^  label30MinWr2;
	private: System::Windows::Forms::Label^  label30MinWr1;
	private: System::Windows::Forms::Label^  label30MinWrDir;
	private: System::Windows::Forms::ListBox^  listBox30MinWrDir;
	private: System::Windows::Forms::Label^  label30MinWr;
	private: System::Windows::Forms::TextBox^  textBox30MinRsiLong;
	private: System::Windows::Forms::TextBox^  textBox30MinRsiMiddle;
	private: System::Windows::Forms::TextBox^  textBox30MinRsiShort;
	private: System::Windows::Forms::Label^  label30MinRsiLong;
	private: System::Windows::Forms::Label^  label30MinRsiMiddle;
	private: System::Windows::Forms::Label^  label30MinRsiShort;
	private: System::Windows::Forms::Label^  label30MinRsiDir;
	private: System::Windows::Forms::ListBox^  listBox30MinRsiDir;
	private: System::Windows::Forms::Label^  label30MinRsi;
	private: System::Windows::Forms::TextBox^  textBox30MinKdjJ;
	private: System::Windows::Forms::TextBox^  textBox30MinKdjD;
	private: System::Windows::Forms::TextBox^  textBox30MinKdjK;
	private: System::Windows::Forms::Label^  label30MinKdjJ;
	private: System::Windows::Forms::Label^  label30MinKdjD;
	private: System::Windows::Forms::Label^  label30MinKdjK;
	private: System::Windows::Forms::Label^  label30MinKdjDir;
	private: System::Windows::Forms::ListBox^  listBox30MinKdjDir;
	private: System::Windows::Forms::Label^  label30MinKdj;
	private: System::Windows::Forms::TextBox^  textBox30MinMacdDea;
	private: System::Windows::Forms::TextBox^  textBox30MinMacdDif;
	private: System::Windows::Forms::TextBox^  textBox30MinMacdMacd;
	private: System::Windows::Forms::Label^  label30MinMacdDea;
	private: System::Windows::Forms::Label^  label30MinMacdDif;
	private: System::Windows::Forms::Label^  label30MinMacdMacd;
	private: System::Windows::Forms::Label^  label30MinMacdDir;
	private: System::Windows::Forms::ListBox^  listBox30MinMacdDir;
	private: System::Windows::Forms::Label^  label30MinMacd;
	private: System::Windows::Forms::TextBox^  textBox30MinBollUpper;
	private: System::Windows::Forms::TextBox^  textBox30MinBollMid;
	private: System::Windows::Forms::TextBox^  textBox30MinBollLow;
	private: System::Windows::Forms::Label^  label30MinBollUpper;
	private: System::Windows::Forms::Label^  label30MinBollMid;
	private: System::Windows::Forms::Label^  label30MinBollLow;
	private: System::Windows::Forms::Label^  label30MinBollDir;
	private: System::Windows::Forms::ListBox^  listBox30MinBollDir;
	private: System::Windows::Forms::Label^  label30MinBoll;
	private: System::Windows::Forms::Label^  label45MinMADir6;
	private: System::Windows::Forms::TextBox^  textBox45MinMA6;
	private: System::Windows::Forms::TextBox^  textBox45MinMA5;
	private: System::Windows::Forms::Label^  label45MinMA6;
	private: System::Windows::Forms::Label^  label45MinMA5;
	private: System::Windows::Forms::Label^  label45MinMADir5;
	private: System::Windows::Forms::ListBox^  listBox45MinMADir5;
	private: System::Windows::Forms::Label^  label45MinMA56;
	private: System::Windows::Forms::Label^  label45MinMADir4;
	private: System::Windows::Forms::ListBox^  listBox45MinMADir4;
	private: System::Windows::Forms::TextBox^  textBox45MinMA4;
	private: System::Windows::Forms::TextBox^  textBox45MinMA3;
	private: System::Windows::Forms::Label^  label45MinMA4;
	private: System::Windows::Forms::Label^  label45MinMA3;
	private: System::Windows::Forms::Label^  label45MinMADir3;
	private: System::Windows::Forms::ListBox^  listBox45MinMADir3;
	private: System::Windows::Forms::Label^  label45MinMA34;
	private: System::Windows::Forms::Label^  label45MinMADir2;
	private: System::Windows::Forms::ListBox^  listBox45MinMADir2;
	private: System::Windows::Forms::TextBox^  textBox45MinMA2;
	private: System::Windows::Forms::TextBox^  textBox45MinMA1;
	private: System::Windows::Forms::Label^  label45MinMA2;
	private: System::Windows::Forms::Label^  label45MinMA1;
	private: System::Windows::Forms::Label^  label45MinMADir1;
	private: System::Windows::Forms::ListBox^  listBox45MinMADir1;
	private: System::Windows::Forms::Label^  label45MinMA12;
	private: System::Windows::Forms::TextBox^  textBox45MinCciCci;
	private: System::Windows::Forms::Label^  label45MinCciCci;
	private: System::Windows::Forms::Label^  label45MinCciDir;
	private: System::Windows::Forms::ListBox^  listBox45MinCciDir;
	private: System::Windows::Forms::Label^  label45MinCci;
	private: System::Windows::Forms::TextBox^  textBox45MinCrC;
	private: System::Windows::Forms::Label^  label45MinCrC;
	private: System::Windows::Forms::TextBox^  textBox45MinCrB;
	private: System::Windows::Forms::Label^  label45MinCrB;
	private: System::Windows::Forms::TextBox^  textBox45MinCrA;
	private: System::Windows::Forms::TextBox^  textBox45MinCrCr;
	private: System::Windows::Forms::Label^  label45MinCrA;
	private: System::Windows::Forms::Label^  label45MinCrCr;
	private: System::Windows::Forms::Label^  label45MinCrDir;
	private: System::Windows::Forms::ListBox^  listBox45MinCrDir;
	private: System::Windows::Forms::Label^  label45MinCr;
	private: System::Windows::Forms::TextBox^  textBox45MinDmaAma;
	private: System::Windows::Forms::TextBox^  textBox45MinDmaDma;
	private: System::Windows::Forms::Label^  label45MinDmaAma;
	private: System::Windows::Forms::Label^  label45MinDmaDma;
	private: System::Windows::Forms::Label^  label45MinDmaDir;
	private: System::Windows::Forms::ListBox^  listBox45MinDmaDir;
	private: System::Windows::Forms::Label^  label45MinDma;
	private: System::Windows::Forms::TextBox^  textBox45MinRocRocma;
	private: System::Windows::Forms::TextBox^  textBox45MinRocRoc;
	private: System::Windows::Forms::Label^  label45MinRocRocma;
	private: System::Windows::Forms::Label^  label45MinRocRoc;
	private: System::Windows::Forms::Label^  label45MinRocDir;
	private: System::Windows::Forms::ListBox^  listBox45MinRocDir;
	private: System::Windows::Forms::Label^  label45MinRoc;
	private: System::Windows::Forms::TextBox^  textBox45MinVrLong;
	private: System::Windows::Forms::TextBox^  textBox45MinVrShort;
	private: System::Windows::Forms::Label^  label45MinVrLong;
	private: System::Windows::Forms::Label^  label45MinVrShort;
	private: System::Windows::Forms::Label^  label45MinVrDir;
	private: System::Windows::Forms::ListBox^  listBox45MinVrDir;
	private: System::Windows::Forms::Label^  label45MinVr;
	private: System::Windows::Forms::Label^  label45MinVolDir2;
	private: System::Windows::Forms::ListBox^  listBox45MinVolDir2;
	private: System::Windows::Forms::TextBox^  textBox45MinVol2;
	private: System::Windows::Forms::TextBox^  textBox45MinVol1;
	private: System::Windows::Forms::Label^  label45MinVol2;
	private: System::Windows::Forms::Label^  label45MinVol1;
	private: System::Windows::Forms::Label^  label45MinVolDir1;
	private: System::Windows::Forms::ListBox^  listBox45MinVolDir1;
	private: System::Windows::Forms::Label^  label45MinVol;
	private: System::Windows::Forms::TextBox^  textBox45MinWr2;
	private: System::Windows::Forms::TextBox^  textBox45MinWr1;
	private: System::Windows::Forms::Label^  label45MinWr2;
	private: System::Windows::Forms::Label^  label45MinWr1;
	private: System::Windows::Forms::Label^  label45MinWrDir;
	private: System::Windows::Forms::ListBox^  listBox45MinWrDir;
	private: System::Windows::Forms::Label^  label45MinWr;
	private: System::Windows::Forms::TextBox^  textBox45MinRsiLong;
	private: System::Windows::Forms::TextBox^  textBox45MinRsiMiddle;
	private: System::Windows::Forms::TextBox^  textBox45MinRsiShort;
	private: System::Windows::Forms::Label^  label45MinRsiLong;
	private: System::Windows::Forms::Label^  label45MinRsiMiddle;
	private: System::Windows::Forms::Label^  label45MinRsiShort;
	private: System::Windows::Forms::Label^  label45MinRsiDir;
	private: System::Windows::Forms::ListBox^  listBox45MinRsiDir;
	private: System::Windows::Forms::Label^  label45MinRsi;
	private: System::Windows::Forms::TextBox^  textBox45MinKdjJ;
	private: System::Windows::Forms::TextBox^  textBox45MinKdjD;
	private: System::Windows::Forms::TextBox^  textBox45MinKdjK;
	private: System::Windows::Forms::Label^  label45MinKdjJ;
	private: System::Windows::Forms::Label^  label45MinKdjD;
	private: System::Windows::Forms::Label^  label45MinKdjK;
	private: System::Windows::Forms::Label^  label45MinKdjDir;
	private: System::Windows::Forms::ListBox^  listBox45MinKdjDir;
	private: System::Windows::Forms::Label^  label45MinKdj;
	private: System::Windows::Forms::TextBox^  textBox45MinMacdDea;
	private: System::Windows::Forms::TextBox^  textBox45MinMacdDif;
	private: System::Windows::Forms::TextBox^  textBox45MinMacdMacd;
	private: System::Windows::Forms::Label^  label45MinMacdDea;
	private: System::Windows::Forms::Label^  label45MinMacdDif;
	private: System::Windows::Forms::Label^  label45MinMacdMacd;
	private: System::Windows::Forms::Label^  label45MinMacdDir;
	private: System::Windows::Forms::ListBox^  listBox45MinMacdDir;
	private: System::Windows::Forms::Label^  label45MinMacd;
	private: System::Windows::Forms::TextBox^  textBox45MinBollUpper;
	private: System::Windows::Forms::TextBox^  textBox45MinBollMid;
	private: System::Windows::Forms::TextBox^  textBox45MinBollLow;
	private: System::Windows::Forms::Label^  label45MinBollUpper;
	private: System::Windows::Forms::Label^  label45MinBollMid;
	private: System::Windows::Forms::Label^  label45MinBollLow;
	private: System::Windows::Forms::Label^  label45MinBollDir;
	private: System::Windows::Forms::ListBox^  listBox45MinBollDir;
	private: System::Windows::Forms::Label^  label45MinBoll;
	private: System::Windows::Forms::Label^  labelHourMADir6;
	private: System::Windows::Forms::TextBox^  textBoxHourMA6;
	private: System::Windows::Forms::TextBox^  textBoxHourMA5;
	private: System::Windows::Forms::Label^  labelHourMA6;
	private: System::Windows::Forms::Label^  labelHourMA5;
	private: System::Windows::Forms::Label^  labelHourMADir5;
	private: System::Windows::Forms::ListBox^  listBoxHourMADir5;
	private: System::Windows::Forms::Label^  labelHourMA56;
	private: System::Windows::Forms::Label^  labelHourMADir4;
	private: System::Windows::Forms::ListBox^  listBoxHourMADir4;
	private: System::Windows::Forms::TextBox^  textBoxHourMA4;
	private: System::Windows::Forms::TextBox^  textBoxHourMA3;
	private: System::Windows::Forms::Label^  labelHourMA4;
	private: System::Windows::Forms::Label^  labelHourMA3;
	private: System::Windows::Forms::Label^  labelHourMADir3;
	private: System::Windows::Forms::ListBox^  listBoxHourMADir3;
	private: System::Windows::Forms::Label^  labelHourMA34;
	private: System::Windows::Forms::Label^  labelHourMADir2;
	private: System::Windows::Forms::ListBox^  listBoxHourMADir2;
	private: System::Windows::Forms::TextBox^  textBoxHourMA2;
	private: System::Windows::Forms::TextBox^  textBoxHourMA1;
	private: System::Windows::Forms::Label^  labelHourMA2;
	private: System::Windows::Forms::Label^  labelHourMA1;
	private: System::Windows::Forms::Label^  labelHourMADir1;
	private: System::Windows::Forms::ListBox^  listBoxHourMADir1;
	private: System::Windows::Forms::Label^  labelHourMA12;
	private: System::Windows::Forms::TextBox^  textBoxHourCciCci;
	private: System::Windows::Forms::Label^  labelHourCciCci;
	private: System::Windows::Forms::Label^  labelHourCciDir;
	private: System::Windows::Forms::ListBox^  listBoxHourCciDir;
	private: System::Windows::Forms::Label^  labelHourCci;
	private: System::Windows::Forms::TextBox^  textBoxHourCrC;
	private: System::Windows::Forms::Label^  labelHourCrC;
	private: System::Windows::Forms::TextBox^  textBoxHourCrB;
	private: System::Windows::Forms::Label^  labelHourCrB;
	private: System::Windows::Forms::TextBox^  textBoxHourCrA;
	private: System::Windows::Forms::TextBox^  textBoxHourCrCr;
	private: System::Windows::Forms::Label^  labelHourCrA;
	private: System::Windows::Forms::Label^  labelHourCrCr;
	private: System::Windows::Forms::Label^  labelHourCrDir;
	private: System::Windows::Forms::ListBox^  listBoxHourCrDir;
	private: System::Windows::Forms::Label^  labelHourCr;
	private: System::Windows::Forms::TextBox^  textBoxHourDmaAma;
	private: System::Windows::Forms::TextBox^  textBoxHourDmaDma;
	private: System::Windows::Forms::Label^  labelHourDmaAma;
	private: System::Windows::Forms::Label^  labelHourDmaDma;
	private: System::Windows::Forms::Label^  labelHourDmaDir;
	private: System::Windows::Forms::ListBox^  listBoxHourDmaDir;
	private: System::Windows::Forms::Label^  labelHourDma;
	private: System::Windows::Forms::TextBox^  textBoxHourRocRocma;
	private: System::Windows::Forms::TextBox^  textBoxHourRocRoc;
	private: System::Windows::Forms::Label^  labelHourRocRocma;
	private: System::Windows::Forms::Label^  labelHourRocRoc;
	private: System::Windows::Forms::Label^  labelHourRocDir;
	private: System::Windows::Forms::ListBox^  listBoxHourRocDir;
	private: System::Windows::Forms::Label^  labelHourRoc;
	private: System::Windows::Forms::TextBox^  textBoxHourVrLong;
	private: System::Windows::Forms::TextBox^  textBoxHourVrShort;
	private: System::Windows::Forms::Label^  labelHourVrLong;
	private: System::Windows::Forms::Label^  labelHourVrShort;
	private: System::Windows::Forms::Label^  labelHourVrDir;
	private: System::Windows::Forms::ListBox^  listBoxHourVrDir;
	private: System::Windows::Forms::Label^  labelHourVr;
	private: System::Windows::Forms::Label^  labelHourVolDir2;
	private: System::Windows::Forms::ListBox^  listBoxHourVolDir2;
	private: System::Windows::Forms::TextBox^  textBoxHourVol2;
	private: System::Windows::Forms::TextBox^  textBoxHourVol1;
	private: System::Windows::Forms::Label^  labelHourVol2;
	private: System::Windows::Forms::Label^  labelHourVol1;
	private: System::Windows::Forms::Label^  labelHourVolDir1;
	private: System::Windows::Forms::ListBox^  listBoxHourVolDir1;
	private: System::Windows::Forms::Label^  labelHourVol;
	private: System::Windows::Forms::TextBox^  textBoxHourWr2;
	private: System::Windows::Forms::TextBox^  textBoxHourWr1;
	private: System::Windows::Forms::Label^  labelHourWr2;
	private: System::Windows::Forms::Label^  labelHourWr1;
	private: System::Windows::Forms::Label^  labelHourWrDir;
	private: System::Windows::Forms::ListBox^  listBoxHourWrDir;
	private: System::Windows::Forms::Label^  labelHourWr;
	private: System::Windows::Forms::TextBox^  textBoxHourRsiLong;
	private: System::Windows::Forms::TextBox^  textBoxHourRsiMiddle;
	private: System::Windows::Forms::TextBox^  textBoxHourRsiShort;
	private: System::Windows::Forms::Label^  labelHourRsiLong;
	private: System::Windows::Forms::Label^  labelHourRsiMiddle;
	private: System::Windows::Forms::Label^  labelHourRsiShort;
	private: System::Windows::Forms::Label^  labelHourRsiDir;
	private: System::Windows::Forms::ListBox^  listBoxHourRsiDir;
	private: System::Windows::Forms::Label^  labelHourRsi;
	private: System::Windows::Forms::TextBox^  textBoxHourKdjJ;
	private: System::Windows::Forms::TextBox^  textBoxHourKdjD;
	private: System::Windows::Forms::TextBox^  textBoxHourKdjK;
	private: System::Windows::Forms::Label^  labelHourKdjJ;
	private: System::Windows::Forms::Label^  labelHourKdjD;
	private: System::Windows::Forms::Label^  labelHourKdjK;
	private: System::Windows::Forms::Label^  labelHourKdjDir;
	private: System::Windows::Forms::ListBox^  listBoxHourKdjDir;
	private: System::Windows::Forms::Label^  labelHourKdj;
	private: System::Windows::Forms::TextBox^  textBoxHourMacdDea;
	private: System::Windows::Forms::TextBox^  textBoxHourMacdDif;
	private: System::Windows::Forms::Label^  labelHourMacdDea;
	private: System::Windows::Forms::TextBox^  textBoxHourMacdMacd;
	private: System::Windows::Forms::Label^  labelHourMacdDif;
	private: System::Windows::Forms::Label^  labelHourMacdMacd;
	private: System::Windows::Forms::Label^  labelHourMacdDir;
	private: System::Windows::Forms::ListBox^  listBoxHourMacdDir;
	private: System::Windows::Forms::Label^  labelHourMacd;
	private: System::Windows::Forms::TextBox^  textBoxHourBollUpper;
	private: System::Windows::Forms::TextBox^  textBoxHourBollMid;
	private: System::Windows::Forms::TextBox^  textBoxHourBollLow;
	private: System::Windows::Forms::Label^  labelHourBollUpper;
	private: System::Windows::Forms::Label^  labelHourBollMid;
	private: System::Windows::Forms::Label^  labelHourBollLow;
	private: System::Windows::Forms::Label^  labelHourBollDir;
	private: System::Windows::Forms::ListBox^  listBoxHourBollDir;
	private: System::Windows::Forms::Label^  labelHourBoll;
	private: System::Windows::Forms::Label^  label4HourMADir6;
	private: System::Windows::Forms::TextBox^  textBox4HourMA6;
	private: System::Windows::Forms::TextBox^  textBox4HourMA5;
	private: System::Windows::Forms::Label^  label4HourMA6;
	private: System::Windows::Forms::Label^  label4HourMA5;
	private: System::Windows::Forms::Label^  label4HourMADir5;
	private: System::Windows::Forms::ListBox^  listBox4HourMADir5;
	private: System::Windows::Forms::Label^  label4HourMA56;
	private: System::Windows::Forms::Label^  label4HourMADir4;
	private: System::Windows::Forms::ListBox^  listBox4HourMADir4;
	private: System::Windows::Forms::TextBox^  textBox4HourMA4;
	private: System::Windows::Forms::TextBox^  textBox4HourMA3;
	private: System::Windows::Forms::Label^  label4HourMA4;
	private: System::Windows::Forms::Label^  label4HourMA3;
	private: System::Windows::Forms::Label^  label4HourMADir3;
	private: System::Windows::Forms::ListBox^  listBox4HourMADir3;
	private: System::Windows::Forms::Label^  label4HourMA34;
	private: System::Windows::Forms::Label^  label4HourMADir2;
	private: System::Windows::Forms::ListBox^  listBox4HourMADir2;
	private: System::Windows::Forms::TextBox^  textBox4HourMA2;
	private: System::Windows::Forms::TextBox^  textBox4HourMA1;
	private: System::Windows::Forms::Label^  label4HourMA2;
	private: System::Windows::Forms::Label^  label4HourMA1;
	private: System::Windows::Forms::Label^  label4HourMADir1;
	private: System::Windows::Forms::ListBox^  listBox4HourMADir1;
	private: System::Windows::Forms::Label^  label4HourMA12;
	private: System::Windows::Forms::TextBox^  textBox4HourCciCci;
	private: System::Windows::Forms::Label^  label4HourCciCci;
	private: System::Windows::Forms::Label^  label4HourCciDir;
	private: System::Windows::Forms::ListBox^  listBox4HourCciDir;
	private: System::Windows::Forms::Label^  label4HourCci;
	private: System::Windows::Forms::TextBox^  textBox4HourCrC;
	private: System::Windows::Forms::Label^  label4HourCrC;
	private: System::Windows::Forms::TextBox^  textBox4HourCrB;
	private: System::Windows::Forms::Label^  label4HourCrB;
	private: System::Windows::Forms::TextBox^  textBox4HourCrA;
	private: System::Windows::Forms::TextBox^  textBox4HourCrCr;
	private: System::Windows::Forms::Label^  label4HourCrA;
	private: System::Windows::Forms::Label^  label4HourCrCr;
	private: System::Windows::Forms::Label^  label4HourCrDir;
	private: System::Windows::Forms::ListBox^  listBox4HourCrDir;
	private: System::Windows::Forms::Label^  label4HourCr;
	private: System::Windows::Forms::TextBox^  textBox4HourDmaAma;
	private: System::Windows::Forms::TextBox^  textBox4HourDmaDma;
	private: System::Windows::Forms::Label^  label4HourDmaAma;
	private: System::Windows::Forms::Label^  label4HourDmaDma;
	private: System::Windows::Forms::Label^  label4HourDmaDir;
	private: System::Windows::Forms::ListBox^  listBox4HourDmaDir;
	private: System::Windows::Forms::Label^  label4HourDma;
	private: System::Windows::Forms::TextBox^  textBox4HourRocRocma;
	private: System::Windows::Forms::TextBox^  textBox4HourRocRoc;
	private: System::Windows::Forms::Label^  label4HourRocRocma;
	private: System::Windows::Forms::Label^  label4HourRocRoc;
	private: System::Windows::Forms::Label^  label4HourRocDir;
	private: System::Windows::Forms::ListBox^  listBox4HourRocDir;
	private: System::Windows::Forms::Label^  label4HourRoc;
	private: System::Windows::Forms::TextBox^  textBox4HourVrLong;
	private: System::Windows::Forms::TextBox^  textBox4HourVrShort;
	private: System::Windows::Forms::Label^  label4HourVrLong;
	private: System::Windows::Forms::Label^  label4HourVrShort;
	private: System::Windows::Forms::Label^  label4HourVrDir;
	private: System::Windows::Forms::ListBox^  listBox4HourVrDir;
	private: System::Windows::Forms::Label^  label4HourVr;
	private: System::Windows::Forms::Label^  label4HourVolDir2;
	private: System::Windows::Forms::ListBox^  listBox4HourVolDir2;
	private: System::Windows::Forms::TextBox^  textBox4HourVol2;
	private: System::Windows::Forms::TextBox^  textBox4HourVol1;
	private: System::Windows::Forms::Label^  label4HourVol2;
	private: System::Windows::Forms::Label^  label4HourVol1;
	private: System::Windows::Forms::Label^  label4HourVolDir1;
	private: System::Windows::Forms::ListBox^  listBox4HourVolDir1;
	private: System::Windows::Forms::Label^  label4HourVol;
	private: System::Windows::Forms::TextBox^  textBox4HourWr2;
	private: System::Windows::Forms::TextBox^  textBox4HourWr1;
	private: System::Windows::Forms::Label^  label4HourWr2;
	private: System::Windows::Forms::Label^  label4HourWr1;
	private: System::Windows::Forms::Label^  label4HourWrDir;
	private: System::Windows::Forms::ListBox^  listBox4HourWrDir;
	private: System::Windows::Forms::Label^  label4HourWr;
	private: System::Windows::Forms::TextBox^  textBox4HourRsiLong;
	private: System::Windows::Forms::TextBox^  textBox4HourRsiMiddle;
	private: System::Windows::Forms::TextBox^  textBox4HourRsiShort;
	private: System::Windows::Forms::Label^  label4HourRsiLong;
	private: System::Windows::Forms::Label^  label4HourRsiMiddle;
	private: System::Windows::Forms::Label^  label4HourRsiShort;
	private: System::Windows::Forms::Label^  label4HourRsiDir;
	private: System::Windows::Forms::ListBox^  listBox4HourRsiDir;
	private: System::Windows::Forms::Label^  label4HourRsi;
	private: System::Windows::Forms::TextBox^  textBox4HourKdjJ;
	private: System::Windows::Forms::TextBox^  textBox4HourKdjD;
	private: System::Windows::Forms::TextBox^  textBox4HourKdjK;
	private: System::Windows::Forms::Label^  label4HourKdjJ;
	private: System::Windows::Forms::Label^  label4HourKdjD;
	private: System::Windows::Forms::Label^  label4HourKdjK;
	private: System::Windows::Forms::Label^  label4HourKdjDir;
	private: System::Windows::Forms::ListBox^  listBox4HourKdjDir;
	private: System::Windows::Forms::Label^  label4HourKdj;
	private: System::Windows::Forms::TextBox^  textBox4HourMacdDea;
	private: System::Windows::Forms::TextBox^  textBox4HourMacdDif;
	private: System::Windows::Forms::TextBox^  textBox4HourMacdMacd;
	private: System::Windows::Forms::Label^  label4HourMacdDea;
	private: System::Windows::Forms::Label^  label4HourMacdDif;
	private: System::Windows::Forms::Label^  label4HourMacdMacd;
	private: System::Windows::Forms::Label^  label4HourMacdDir;
	private: System::Windows::Forms::ListBox^  listBox4HourMacdDir;
	private: System::Windows::Forms::Label^  label4HourMacd;
	private: System::Windows::Forms::TextBox^  textBox4HourBollUpper;
	private: System::Windows::Forms::TextBox^  textBox4HourBollMid;
	private: System::Windows::Forms::TextBox^  textBox4HourBollLow;
	private: System::Windows::Forms::Label^  label4HourBollUpper;
	private: System::Windows::Forms::Label^  label4HourBollMid;
	private: System::Windows::Forms::Label^  label4HourBollLow;
	private: System::Windows::Forms::Label^  label4HourBollDir;
	private: System::Windows::Forms::ListBox^  listBox4HourBollDir;
	private: System::Windows::Forms::Label^  label4HourBoll;
	private: System::Windows::Forms::Label^  labelWeekMADir6;
	private: System::Windows::Forms::TextBox^  textBoxWeekMA6;
	private: System::Windows::Forms::TextBox^  textBoxWeekMA5;
	private: System::Windows::Forms::Label^  labelWeekMA6;
	private: System::Windows::Forms::Label^  labelWeekMA5;
	private: System::Windows::Forms::Label^  labelWeekMADir5;
	private: System::Windows::Forms::ListBox^  listBoxWeekMADir5;
	private: System::Windows::Forms::Label^  labelWeekMADir56;
	private: System::Windows::Forms::Label^  labelWeekMADir4;
	private: System::Windows::Forms::ListBox^  listBoxWeekMADir4;
	private: System::Windows::Forms::TextBox^  textBoxWeekMA4;
	private: System::Windows::Forms::TextBox^  textBoxWeekMA3;
	private: System::Windows::Forms::Label^  labelWeekMA4;
	private: System::Windows::Forms::Label^  labelWeekMA3;
	private: System::Windows::Forms::Label^  labelWeekMADir3;
	private: System::Windows::Forms::ListBox^  listBoxWeekMADir3;
	private: System::Windows::Forms::Label^  labelWeekMADir34;
	private: System::Windows::Forms::Label^  labelWeekMADir2;
	private: System::Windows::Forms::ListBox^  listBoxWeekMADir2;
	private: System::Windows::Forms::TextBox^  textBoxWeekMA2;
	private: System::Windows::Forms::TextBox^  textBoxWeekMA1;
	private: System::Windows::Forms::Label^  labelWeekMA2;
	private: System::Windows::Forms::Label^  labelWeekMA1;
	private: System::Windows::Forms::Label^  labelWeekMADir1;
	private: System::Windows::Forms::ListBox^  listBoxWeekMADir1;
	private: System::Windows::Forms::Label^  labelWeekMA12;
	private: System::Windows::Forms::TextBox^  textBoxWeekCciCci;
	private: System::Windows::Forms::Label^  labelWeekCciCci;
	private: System::Windows::Forms::Label^  labelWeekCciDir;
	private: System::Windows::Forms::ListBox^  listBoxWeekCciDir;
	private: System::Windows::Forms::Label^  labelWeekCci;
	private: System::Windows::Forms::TextBox^  textBoxWeekCrC;
	private: System::Windows::Forms::Label^  labelWeekCrC;
	private: System::Windows::Forms::TextBox^  textBoxWeekCrB;
	private: System::Windows::Forms::Label^  labelWeekCrB;
	private: System::Windows::Forms::TextBox^  textBoxWeekCrA;
	private: System::Windows::Forms::TextBox^  textBoxWeekCrCr;
	private: System::Windows::Forms::Label^  labelWeekCrA;
	private: System::Windows::Forms::Label^  labelWeekCrCr;
	private: System::Windows::Forms::Label^  labelWeekCrDir;
	private: System::Windows::Forms::ListBox^  listBoxWeekCrDir;
	private: System::Windows::Forms::Label^  labelWeekCr;
	private: System::Windows::Forms::TextBox^  textBoxWeekDmaAma;
	private: System::Windows::Forms::TextBox^  textBoxWeekDmaDma;
	private: System::Windows::Forms::Label^  labelWeekDmaAma;
	private: System::Windows::Forms::Label^  labelWeekDmaDma;
	private: System::Windows::Forms::Label^  labelWeekDmaDir;
	private: System::Windows::Forms::ListBox^  listBoxWeekDmaDir;
	private: System::Windows::Forms::Label^  labelWeekDma;
	private: System::Windows::Forms::TextBox^  textBoxWeekRocRocma;
	private: System::Windows::Forms::TextBox^  textBoxWeekRocRoc;
	private: System::Windows::Forms::Label^  labelWeekRocRocma;
	private: System::Windows::Forms::Label^  labelWeekRocRoc;
	private: System::Windows::Forms::Label^  labelWeekRocDir;
	private: System::Windows::Forms::ListBox^  listBoxWeekRocDir;
	private: System::Windows::Forms::Label^  labelWeekRoc;
	private: System::Windows::Forms::TextBox^  textBoxWeekVrLong;
	private: System::Windows::Forms::TextBox^  textBoxWeekVrShort;
	private: System::Windows::Forms::Label^  labelWeekVrLong;
	private: System::Windows::Forms::Label^  labelWeekVrShort;
	private: System::Windows::Forms::Label^  labelWeekVrDir;
	private: System::Windows::Forms::ListBox^  listBoxWeekVrDir;
	private: System::Windows::Forms::Label^  labelWeekVr;
	private: System::Windows::Forms::Label^  labelWeekVolDir2;
	private: System::Windows::Forms::ListBox^  listBoxWeekVolDir2;
	private: System::Windows::Forms::TextBox^  textBoxWeekVol2;
	private: System::Windows::Forms::TextBox^  textBoxWeekVol1;
	private: System::Windows::Forms::Label^  labelWeekVol2;
	private: System::Windows::Forms::Label^  labelWeekVol1;
	private: System::Windows::Forms::Label^  labelWeekVolDir1;
	private: System::Windows::Forms::ListBox^  listBoxWeekVolDir1;
	private: System::Windows::Forms::Label^  labelWeekVol;
	private: System::Windows::Forms::TextBox^  textBoxWeekWr2;
	private: System::Windows::Forms::TextBox^  textBoxWeekWr1;
	private: System::Windows::Forms::Label^  labelWeekWr2;
	private: System::Windows::Forms::Label^  labelWeekWr1;
	private: System::Windows::Forms::Label^  labelWeekWrDir;
	private: System::Windows::Forms::ListBox^  listBoxWeekWrDir;
	private: System::Windows::Forms::Label^  labelWeekWr;
	private: System::Windows::Forms::TextBox^  textBoxWeekRsiLong;
	private: System::Windows::Forms::TextBox^  textBoxWeekRsiMiddle;
	private: System::Windows::Forms::TextBox^  textBoxWeekRsiShort;
	private: System::Windows::Forms::Label^  labelWeekRsiLong;
	private: System::Windows::Forms::Label^  labelWeekRsiMiddle;
	private: System::Windows::Forms::Label^  labelWeekRsiShort;
	private: System::Windows::Forms::Label^  labelWeekRsiDir;
	private: System::Windows::Forms::ListBox^  listBoxWeekRsiDir;
	private: System::Windows::Forms::Label^  labelWeekRsi;
	private: System::Windows::Forms::TextBox^  textBoxWeekKdjJ;
	private: System::Windows::Forms::TextBox^  textBoxWeekKdjD;
	private: System::Windows::Forms::TextBox^  textBoxWeekKdjK;
	private: System::Windows::Forms::Label^  labelWeekKdjJ;
	private: System::Windows::Forms::Label^  labelWeekKdjD;
	private: System::Windows::Forms::Label^  labelWeekKdjK;
	private: System::Windows::Forms::Label^  labelWeekKdjDir;
	private: System::Windows::Forms::ListBox^  listBoxWeekKdjDir;
	private: System::Windows::Forms::Label^  labelWeekKdj;
	private: System::Windows::Forms::TextBox^  textBoxWeekMacdDea;
	private: System::Windows::Forms::TextBox^  textBoxWeekMacdDif;
	private: System::Windows::Forms::TextBox^  textBoxWeekMacdMacd;
	private: System::Windows::Forms::Label^  labelWeekMacdDea;
	private: System::Windows::Forms::Label^  labelWeekMacdDif;
	private: System::Windows::Forms::Label^  labelWeekMacdMacd;
	private: System::Windows::Forms::Label^  labelWeekMacdDir;
	private: System::Windows::Forms::ListBox^  listBoxWeekMacdDir;
	private: System::Windows::Forms::Label^  labelWeekMacd;
	private: System::Windows::Forms::TextBox^  textBoxWeekBollUpper;
	private: System::Windows::Forms::TextBox^  textBoxWeekBollMid;
	private: System::Windows::Forms::TextBox^  textBoxWeekBollLow;
	private: System::Windows::Forms::Label^  labelWeekBollUpper;
	private: System::Windows::Forms::Label^  labelWeekBollMid;
	private: System::Windows::Forms::Label^  labelWeekBollLow;
	private: System::Windows::Forms::Label^  labelWeekBollDir;
	private: System::Windows::Forms::ListBox^  listBoxWeekBollDir;
	private: System::Windows::Forms::Label^  labelWeekBoll;
	private: System::Windows::Forms::Label^  labelMonthMADir6;
	private: System::Windows::Forms::TextBox^  textBoxMonthMA6;
	private: System::Windows::Forms::TextBox^  textBoxMonthMA5;
	private: System::Windows::Forms::Label^  labelMonthMA6;
	private: System::Windows::Forms::Label^  labelMonthMA5;
	private: System::Windows::Forms::Label^  labelMonthMADir5;
	private: System::Windows::Forms::ListBox^  listBoxMonthMADir5;
	private: System::Windows::Forms::Label^  labelMonthMA56;
	private: System::Windows::Forms::Label^  labelMonthMADir4;
	private: System::Windows::Forms::ListBox^  listBoxMonthMADir4;
	private: System::Windows::Forms::TextBox^  textBoxMonthMA4;
	private: System::Windows::Forms::TextBox^  textBoxMonthMA3;
	private: System::Windows::Forms::Label^  labelMonthMA4;
	private: System::Windows::Forms::Label^  labelMonthMA3;
	private: System::Windows::Forms::Label^  labelMonthMADir3;
	private: System::Windows::Forms::ListBox^  listBoxMonthMADir3;
	private: System::Windows::Forms::Label^  labelMonthMA34;
	private: System::Windows::Forms::Label^  labelMonthMADir2;
	private: System::Windows::Forms::ListBox^  listBoxMonthMADir2;
	private: System::Windows::Forms::TextBox^  textBoxMonthMA2;
	private: System::Windows::Forms::TextBox^  textBoxMonthMA1;
	private: System::Windows::Forms::Label^  labelMonthMA2;
	private: System::Windows::Forms::Label^  labelMonthMA1;
	private: System::Windows::Forms::Label^  labelMonthMADir1;
	private: System::Windows::Forms::ListBox^  listBoxMonthMADir1;
	private: System::Windows::Forms::Label^  labelMonthMA12;
	private: System::Windows::Forms::TextBox^  textBoxMonthCciCci;
	private: System::Windows::Forms::Label^  labelMonthCciCci;
	private: System::Windows::Forms::Label^  labelMonthCciDir;
	private: System::Windows::Forms::ListBox^  listBoxMonthCciDir;
	private: System::Windows::Forms::Label^  labelMonthCci;
	private: System::Windows::Forms::TextBox^  textBoxMonthCrC;
	private: System::Windows::Forms::Label^  labelMonthCrC;
	private: System::Windows::Forms::TextBox^  textBoxMonthCrB;
	private: System::Windows::Forms::Label^  labelMonthCrB;
	private: System::Windows::Forms::TextBox^  textBoxMonthCrA;
	private: System::Windows::Forms::TextBox^  textBoxMonthCrCr;
	private: System::Windows::Forms::Label^  labelMonthCrA;
	private: System::Windows::Forms::Label^  labelMonthCrCr;
	private: System::Windows::Forms::Label^  labelMonthCrDir;
	private: System::Windows::Forms::ListBox^  listBoxMonthCrDir;
	private: System::Windows::Forms::Label^  labelMonthCr;
	private: System::Windows::Forms::TextBox^  textBoxMonthDmaAma;
	private: System::Windows::Forms::TextBox^  textBoxMonthDmaDma;
	private: System::Windows::Forms::Label^  labelMonthDmaAma;
	private: System::Windows::Forms::Label^  labelMonthDmaDma;
	private: System::Windows::Forms::Label^  labelMonthDmaDir;
	private: System::Windows::Forms::ListBox^  listBoxMonthDmaDir;
	private: System::Windows::Forms::Label^  labelMonthDma;
	private: System::Windows::Forms::TextBox^  textBoxMonthRocRocma;
	private: System::Windows::Forms::TextBox^  textBoxMonthRocRoc;
	private: System::Windows::Forms::Label^  labelMonthRocRocma;
	private: System::Windows::Forms::Label^  labelMonthRocRoc;
	private: System::Windows::Forms::Label^  labelMonthRocDir;
	private: System::Windows::Forms::ListBox^  listBoxMonthRocDir;
	private: System::Windows::Forms::Label^  labelMonthRoc;
	private: System::Windows::Forms::TextBox^  textBoxMonthVrLong;
	private: System::Windows::Forms::TextBox^  textBoxMonthVrShort;
	private: System::Windows::Forms::Label^  labelMonthVrLong;
	private: System::Windows::Forms::Label^  labelMonthVrShort;
	private: System::Windows::Forms::Label^  labelMonthVrDir;
	private: System::Windows::Forms::ListBox^  listBoxMonthVrDir;
	private: System::Windows::Forms::Label^  labelMonthVr;
	private: System::Windows::Forms::Label^  labelMonthVolDir2;
	private: System::Windows::Forms::ListBox^  listBoxMonthVolDir2;
	private: System::Windows::Forms::TextBox^  textBoxMonthVol2;
	private: System::Windows::Forms::TextBox^  textBoxMonthVol1;
	private: System::Windows::Forms::Label^  labelMonthVol2;
	private: System::Windows::Forms::Label^  labelMonthVol1;
	private: System::Windows::Forms::Label^  labelMonthVolDir1;
	private: System::Windows::Forms::ListBox^  listBoxMonthVolDir1;
	private: System::Windows::Forms::Label^  labelMonthVol;
	private: System::Windows::Forms::TextBox^  textBoxMonthWr2;
	private: System::Windows::Forms::TextBox^  textBoxMonthWr1;
	private: System::Windows::Forms::Label^  labelMonthWr2;
	private: System::Windows::Forms::Label^  labelMonthWr1;
	private: System::Windows::Forms::Label^  labelMonthWrDir;
	private: System::Windows::Forms::ListBox^  listBoxMonthWrDir;
	private: System::Windows::Forms::Label^  labelMonthWr;
	private: System::Windows::Forms::TextBox^  textBoxMonthRsiLong;
	private: System::Windows::Forms::TextBox^  textBoxMonthRsiMiddle;
	private: System::Windows::Forms::TextBox^  textBoxMonthRsiShort;
	private: System::Windows::Forms::Label^  labelMonthRsiLong;
	private: System::Windows::Forms::Label^  labelMonthRsiMiddle;
	private: System::Windows::Forms::Label^  labelMonthRsiShort;
	private: System::Windows::Forms::Label^  labelMonthRsiDir;
	private: System::Windows::Forms::ListBox^  listBoxMonthRsiDir;
	private: System::Windows::Forms::Label^  labelMonthRsi;
	private: System::Windows::Forms::TextBox^  textBoxMonthKdjJ;
	private: System::Windows::Forms::TextBox^  textBoxMonthKdjD;
	private: System::Windows::Forms::TextBox^  textBoxMonthKdjK;
	private: System::Windows::Forms::Label^  labelMonthKdjJ;
	private: System::Windows::Forms::Label^  labelMonthKdjD;
	private: System::Windows::Forms::Label^  labelMonthKdjK;
	private: System::Windows::Forms::Label^  labelMonthKdjDir;
	private: System::Windows::Forms::ListBox^  listBoxMonthKdjDir;
	private: System::Windows::Forms::Label^  labelMonthKdj;
	private: System::Windows::Forms::TextBox^  textBoxMonthMacdDea;
	private: System::Windows::Forms::TextBox^  textBoxMonthMacdDif;
	private: System::Windows::Forms::TextBox^  textBoxMonthMacdMacd;
	private: System::Windows::Forms::Label^  labelMonthMacdDea;
	private: System::Windows::Forms::Label^  labelMonthMacdDif;
	private: System::Windows::Forms::Label^  labelMonthMacdMacd;
	private: System::Windows::Forms::Label^  labelMonthMacdDir;
	private: System::Windows::Forms::ListBox^  listBoxMonthMacdDir;
	private: System::Windows::Forms::Label^  labelMonthMacd;
	private: System::Windows::Forms::TextBox^  textBoxMonthBollUpper;
	private: System::Windows::Forms::TextBox^  textBoxMonthBollMid;
	private: System::Windows::Forms::TextBox^  textBoxMonthBollLow;
	private: System::Windows::Forms::Label^  labelMonthBollUpper;
	private: System::Windows::Forms::Label^  labelMonthBollMid;
	private: System::Windows::Forms::Label^  labelMonthBollLow;
	private: System::Windows::Forms::Label^  labelMonthBollDir;
	private: System::Windows::Forms::ListBox^  listBoxMonthBollDir;
	private: System::Windows::Forms::Label^  labelMonthBoll;
	private: System::Windows::Forms::Label^  labelYearMADir6;
	private: System::Windows::Forms::TextBox^  textBoxYearMA6;
	private: System::Windows::Forms::TextBox^  textBoxYearMA5;
	private: System::Windows::Forms::Label^  labelYearMA6;
	private: System::Windows::Forms::Label^  labelYearMA5;
	private: System::Windows::Forms::Label^  labelYearMADir5;
	private: System::Windows::Forms::ListBox^  listBoxYearMADir5;
	private: System::Windows::Forms::Label^  labelYearMA56;
	private: System::Windows::Forms::Label^  labelYearMADir4;
	private: System::Windows::Forms::ListBox^  listBoxYearMADir4;
	private: System::Windows::Forms::TextBox^  textBoxYearMA4;
	private: System::Windows::Forms::TextBox^  textBoxYearMA3;
	private: System::Windows::Forms::Label^  labelYearMA4;
	private: System::Windows::Forms::Label^  labelYearMA3;
	private: System::Windows::Forms::Label^  labelYearMADir3;
	private: System::Windows::Forms::ListBox^  listBoxYearMADir3;
	private: System::Windows::Forms::Label^  labelYearMA34;
	private: System::Windows::Forms::Label^  labelYearMADir2;
	private: System::Windows::Forms::ListBox^  listBoxYearMADir2;
	private: System::Windows::Forms::TextBox^  textBoxYearMA2;
	private: System::Windows::Forms::TextBox^  textBoxYearMA1;
	private: System::Windows::Forms::Label^  labelYearMA2;
	private: System::Windows::Forms::Label^  labelYearMA1;
	private: System::Windows::Forms::Label^  labelYearMADir1;
	private: System::Windows::Forms::ListBox^  listBoxYearMADir1;
	private: System::Windows::Forms::Label^  labelYearMA12;
	private: System::Windows::Forms::TextBox^  textBoxYearCciCci;
	private: System::Windows::Forms::Label^  labelYearCciCci;
	private: System::Windows::Forms::Label^  labelYearCciDir;
	private: System::Windows::Forms::ListBox^  listBoxYearCciDir;
	private: System::Windows::Forms::Label^  labelYearCci;
	private: System::Windows::Forms::TextBox^  textBoxYearCrC;
	private: System::Windows::Forms::Label^  labelYearCrC;
	private: System::Windows::Forms::TextBox^  textBoxYearCrB;
	private: System::Windows::Forms::Label^  labelYearCrB;
	private: System::Windows::Forms::TextBox^  textBoxYearCrA;
	private: System::Windows::Forms::TextBox^  textBoxYearCrCr;
	private: System::Windows::Forms::Label^  labelYearCrA;
	private: System::Windows::Forms::Label^  labelYearCrCr;
	private: System::Windows::Forms::Label^  labeYearCrDir;
	private: System::Windows::Forms::ListBox^  listBoxYearCrDir;
	private: System::Windows::Forms::Label^  labelYearCr;
	private: System::Windows::Forms::TextBox^  textBoxYearDmaAma;
	private: System::Windows::Forms::TextBox^  textBoxYearDmaDma;
	private: System::Windows::Forms::Label^  labelYearDmaAma;
	private: System::Windows::Forms::Label^  labelYearDmaDma;
	private: System::Windows::Forms::Label^  labelYearDmaDir;
	private: System::Windows::Forms::ListBox^  listBoxYearDmaDir;
	private: System::Windows::Forms::Label^  labelYearDma;
	private: System::Windows::Forms::TextBox^  textBoxYearRocRocma;
	private: System::Windows::Forms::TextBox^  textBoxYearRocRoc;
	private: System::Windows::Forms::Label^  labelYearRocRoc_ma;
	private: System::Windows::Forms::Label^  labelYearRocRoc;
	private: System::Windows::Forms::Label^  labelYearRocDir;
	private: System::Windows::Forms::ListBox^  listBoxYearRocDir;
	private: System::Windows::Forms::Label^  labelYearRoc;
	private: System::Windows::Forms::TextBox^  textBoxYearVrLong;
	private: System::Windows::Forms::TextBox^  textBoxYearVrShort;
	private: System::Windows::Forms::Label^  labelYearVrLong;
	private: System::Windows::Forms::Label^  labelYearVrShort;
	private: System::Windows::Forms::Label^  labelYearVrDir;
	private: System::Windows::Forms::ListBox^  listBoxYearVrDir;
	private: System::Windows::Forms::Label^  labelYearVr;
	private: System::Windows::Forms::Label^  labelYearVolDir2;
	private: System::Windows::Forms::ListBox^  listBoxYearVolDir2;
	private: System::Windows::Forms::TextBox^  textBoxYearVol2;
	private: System::Windows::Forms::TextBox^  textBoxYearVol1;
	private: System::Windows::Forms::Label^  labelYearVol2;
	private: System::Windows::Forms::Label^  labelYearVol1;
	private: System::Windows::Forms::Label^  labelYearVolDir1;
	private: System::Windows::Forms::ListBox^  listBoxYearVolDir1;
	private: System::Windows::Forms::Label^  labelYearVol;
	private: System::Windows::Forms::TextBox^  textBoxYearWr2;
	private: System::Windows::Forms::TextBox^  textBoxYearWr1;
	private: System::Windows::Forms::Label^  labelYearWr2;
	private: System::Windows::Forms::Label^  labelYearWr1;
	private: System::Windows::Forms::Label^  labelYearWrDir;
	private: System::Windows::Forms::ListBox^  listBoxYearWrDir;
	private: System::Windows::Forms::Label^  labelYearWr;
	private: System::Windows::Forms::TextBox^  textBoxYearRsiLong;
	private: System::Windows::Forms::TextBox^  textBoxYearRsiMiddle;
	private: System::Windows::Forms::TextBox^  textBoxYearRsiShort;
	private: System::Windows::Forms::Label^  labelYearRsiLong;
	private: System::Windows::Forms::Label^  labelYearRsiMiddle;
	private: System::Windows::Forms::Label^  labelYearRsiShort;
	private: System::Windows::Forms::Label^  labelYearRsiDir;
	private: System::Windows::Forms::ListBox^  listBoxYearRsiDir;
	private: System::Windows::Forms::Label^  labelYearRsi;
	private: System::Windows::Forms::TextBox^  textBoxYearKdjJ;
	private: System::Windows::Forms::TextBox^  textBoxYearKdjD;
	private: System::Windows::Forms::TextBox^  textBoxYearKdjK;
	private: System::Windows::Forms::Label^  labelYearKdjJ;
	private: System::Windows::Forms::Label^  labelYearKdjD;
	private: System::Windows::Forms::Label^  labelYearKdjK;
	private: System::Windows::Forms::Label^  labelYearKdjDir;
	private: System::Windows::Forms::ListBox^  listBoxYearKdjDir;
	private: System::Windows::Forms::Label^  labelYearKdj;
	private: System::Windows::Forms::TextBox^  textBoxYearMacdDea;
	private: System::Windows::Forms::TextBox^  textBoxYearMacdDif;
	private: System::Windows::Forms::TextBox^  textBoxYearMacdMacd;
	private: System::Windows::Forms::Label^  labelYearMacdDea;
	private: System::Windows::Forms::Label^  labelYearMacdDif;
	private: System::Windows::Forms::Label^  labelYearMacdMacd;
	private: System::Windows::Forms::Label^  labelYearMacdDir;
	private: System::Windows::Forms::ListBox^  listBoxYearMacdDir;
	private: System::Windows::Forms::Label^  labelYearMacd;
	private: System::Windows::Forms::TextBox^  textBoxYearBollUpper;
	private: System::Windows::Forms::TextBox^  textBoxYearBollMid;
	private: System::Windows::Forms::TextBox^  textBoxYearBollLow;
	private: System::Windows::Forms::Label^  labelYearBollUpper;
	private: System::Windows::Forms::Label^  labelYearBollMid;
	private: System::Windows::Forms::Label^  labelYearBollLow;
	private: System::Windows::Forms::Label^  labelYearBollDir;
	private: System::Windows::Forms::ListBox^  listBoxYearBollDir;
	private: System::Windows::Forms::Label^  labelYearBoll;
	private: System::Windows::Forms::Label^  label5MinMADir6;
	private: System::Windows::Forms::TextBox^  textBox5MinMA6;
	private: System::Windows::Forms::TextBox^  textBox5MinMA5;
	private: System::Windows::Forms::Label^  label5MinMA6;
	private: System::Windows::Forms::Label^  label5MinMA5;
	private: System::Windows::Forms::Label^  label5MinMADir5;
	private: System::Windows::Forms::ListBox^  listBox5MinMADir5;
	private: System::Windows::Forms::Label^  label5MinMA56;
	private: System::Windows::Forms::Label^  label5MinMADir4;
	private: System::Windows::Forms::ListBox^  listBox5MinMADir4;
	private: System::Windows::Forms::TextBox^  textBox5MinMA4;
	private: System::Windows::Forms::TextBox^  textBox5MinMA3;
	private: System::Windows::Forms::Label^  label5MinMA4;
	private: System::Windows::Forms::Label^  label5MinMA3;
	private: System::Windows::Forms::Label^  label5MinMADir3;
	private: System::Windows::Forms::ListBox^  listBox5MinMADir3;
	private: System::Windows::Forms::Label^  label5MinMA34;
	private: System::Windows::Forms::Label^  label5MinMADir2;
	private: System::Windows::Forms::ListBox^  listBox5MinMADir2;
	private: System::Windows::Forms::TextBox^  textBox5MinMA2;
	private: System::Windows::Forms::TextBox^  textBox5MinMA1;
	private: System::Windows::Forms::Label^  label5MinMA2;
	private: System::Windows::Forms::Label^  label5MinMA1;
	private: System::Windows::Forms::Label^  label5MinMADir1;
	private: System::Windows::Forms::ListBox^  listBox5MinMADir1;
	private: System::Windows::Forms::Label^  label5MinMA12;
	private: System::Windows::Forms::TextBox^  textBox5MinCciCci;
	private: System::Windows::Forms::Label^  label5MinCciCci;
	private: System::Windows::Forms::Label^  label5MinCciDir;
	private: System::Windows::Forms::ListBox^  listBox5MinCciDir;
	private: System::Windows::Forms::Label^  label5MinCci;
	private: System::Windows::Forms::TextBox^  textBox5MinCrC;
	private: System::Windows::Forms::Label^  label5MinCrC;
	private: System::Windows::Forms::TextBox^  textBox5MinCrB;
	private: System::Windows::Forms::Label^  label5MinCrB;
	private: System::Windows::Forms::TextBox^  textBox5MinCrA;
	private: System::Windows::Forms::TextBox^  textBox5MinCrCr;
	private: System::Windows::Forms::Label^  label5MinCrA;
	private: System::Windows::Forms::Label^  label5MinCrCr;
	private: System::Windows::Forms::Label^  label5MinCrDir;
	private: System::Windows::Forms::ListBox^  listBox5MinCrDir;
	private: System::Windows::Forms::Label^  label5MinCr;
	private: System::Windows::Forms::TextBox^  textBox5MinDmaAma;
	private: System::Windows::Forms::TextBox^  textBox5MinDmaDma;
	private: System::Windows::Forms::Label^  label5MinDmaAma;
	private: System::Windows::Forms::Label^  label5MinDmaDma;
	private: System::Windows::Forms::Label^  label5MinDmaDir;
	private: System::Windows::Forms::ListBox^  listBox5MinDmaDir;
	private: System::Windows::Forms::Label^  label5MinDma;
	private: System::Windows::Forms::TextBox^  textBox5MinRocRocma;
	private: System::Windows::Forms::TextBox^  textBox5MinRocRoc;
	private: System::Windows::Forms::Label^  label5MinRocRocma;
	private: System::Windows::Forms::Label^  label5MinRocRoc;
	private: System::Windows::Forms::Label^  label5MinRocDir;
	private: System::Windows::Forms::ListBox^  listBox5MinRocDir;
	private: System::Windows::Forms::Label^  label5MinRoc;
	private: System::Windows::Forms::TextBox^  textBox5MinVrLong;
	private: System::Windows::Forms::TextBox^  textBox5MinVrShort;
	private: System::Windows::Forms::Label^  label5MinVrLong;
	private: System::Windows::Forms::Label^  label5MinVrShort;
	private: System::Windows::Forms::Label^  label5MinVrDir;
	private: System::Windows::Forms::ListBox^  listBox5MinVrDir;
	private: System::Windows::Forms::Label^  label5MinVr;
	private: System::Windows::Forms::Label^  label5MinVolDir2;
	private: System::Windows::Forms::ListBox^  listBox5MinVolDir2;
	private: System::Windows::Forms::TextBox^  textBox5MinVol2;
	private: System::Windows::Forms::TextBox^  textBox5MinVol1;
	private: System::Windows::Forms::Label^  label5MinVol2;
	private: System::Windows::Forms::Label^  label5MinVol1;
	private: System::Windows::Forms::Label^  label5MinVolDir1;
	private: System::Windows::Forms::ListBox^  listBox5MinVolDir1;
	private: System::Windows::Forms::Label^  label5MinVol;
	private: System::Windows::Forms::TextBox^  textBox5MinWr2;
	private: System::Windows::Forms::TextBox^  textBox5MinWr1;
	private: System::Windows::Forms::Label^  label5MinWr2;
	private: System::Windows::Forms::Label^  label5MinWr1;
	private: System::Windows::Forms::Label^  label5MinWrDir;
	private: System::Windows::Forms::ListBox^  listBox5MinWrDir;
	private: System::Windows::Forms::Label^  label5MinWr;
	private: System::Windows::Forms::TextBox^  textBox5MinRsiLong;
	private: System::Windows::Forms::TextBox^  textBox5MinRsiMiddle;
	private: System::Windows::Forms::TextBox^  textBox5MinRsiShort;
	private: System::Windows::Forms::Label^  label5MinRsiLong;
	private: System::Windows::Forms::Label^  label5MinRsiMiddle;
	private: System::Windows::Forms::Label^  label5MinRsiShort;
	private: System::Windows::Forms::Label^  label5MinRsiDir;
	private: System::Windows::Forms::ListBox^  listBox5MinRsiDir;
	private: System::Windows::Forms::Label^  label5MinRsi;
	private: System::Windows::Forms::TextBox^  textBox5MinKdjJ;
	private: System::Windows::Forms::TextBox^  textBox5MinKdjD;
	private: System::Windows::Forms::TextBox^  textBox5MinKdjK;
	private: System::Windows::Forms::Label^  label5MinKdjJ;
	private: System::Windows::Forms::Label^  label5MinKdjD;
	private: System::Windows::Forms::Label^  label5MinKdjK;
	private: System::Windows::Forms::Label^  label5MinKdjDir;
	private: System::Windows::Forms::ListBox^  listBox5MinKdjDir;
	private: System::Windows::Forms::Label^  label5MinKdj;
	private: System::Windows::Forms::TextBox^  textBox5MinMacdDea;
	private: System::Windows::Forms::TextBox^  textBox5MinMacdDif;
	private: System::Windows::Forms::TextBox^  textBox5MinMacdMacd;
	private: System::Windows::Forms::Label^  label5MinMacdDea;
	private: System::Windows::Forms::Label^  label5MinMacdDif;
	private: System::Windows::Forms::Label^  label5MinMacdMacd;
	private: System::Windows::Forms::Label^  label5MinMacdDir;
	private: System::Windows::Forms::ListBox^  listBox5MinMacdDir;
	private: System::Windows::Forms::Label^  label5MinMacd;
	private: System::Windows::Forms::TextBox^  textBox5MinBollUpper;
	private: System::Windows::Forms::TextBox^  textBox5MinBollMid;
	private: System::Windows::Forms::TextBox^  textBox5MinBollLow;
	private: System::Windows::Forms::Label^  label5MinBollUpper;
	private: System::Windows::Forms::Label^  label5MinBollMid;
	private: System::Windows::Forms::Label^  label5MinBollLow;
	private: System::Windows::Forms::Label^  label5MinBollDir;
	private: System::Windows::Forms::ListBox^  listBox5MinBollDir;
	private: System::Windows::Forms::Label^  label5MinBoll;
	private: System::Windows::Forms::Label^  labelDayMADir6;
	private: System::Windows::Forms::TextBox^  textBoxDayMA6;
	private: System::Windows::Forms::TextBox^  textBoxDayMA5;
	private: System::Windows::Forms::Label^  labelDayMA6;
	private: System::Windows::Forms::Label^  labelDayMA5;
	private: System::Windows::Forms::Label^  labelDayMADir5;
	private: System::Windows::Forms::ListBox^  listBoxDayMADir5;
	private: System::Windows::Forms::Label^  labelDayMA56;
	private: System::Windows::Forms::Label^  labelDayMADir4;
	private: System::Windows::Forms::ListBox^  listBoxDayMADir4;
	private: System::Windows::Forms::TextBox^  textBoxDayMA4;
	private: System::Windows::Forms::TextBox^  textBoxDayMA3;
	private: System::Windows::Forms::Label^  labelDayMA4;
	private: System::Windows::Forms::Label^  labelDayMA3;
	private: System::Windows::Forms::Label^  labelDayMADir3;
	private: System::Windows::Forms::ListBox^  listBoxDayMADir3;
	private: System::Windows::Forms::Label^  labelDayMA34;
	private: System::Windows::Forms::Label^  label1DayMADir2;
	private: System::Windows::Forms::ListBox^  listBoxDayMADir2;
	private: System::Windows::Forms::TextBox^  textBoxDayMA2;
	private: System::Windows::Forms::TextBox^  textBoxDayMA1;
	private: System::Windows::Forms::Label^  labelDayMA2;
	private: System::Windows::Forms::Label^  labelDayMa1;
	private: System::Windows::Forms::Label^  labelDayMaDir1;
	private: System::Windows::Forms::ListBox^  listBoxDayMADir1;
	private: System::Windows::Forms::Label^  labelDayMa12;
	private: System::Windows::Forms::TextBox^  textBoxDayCciCci;
	private: System::Windows::Forms::Label^  labelDayCciCci;
	private: System::Windows::Forms::Label^  labelDayCciDir;
	private: System::Windows::Forms::ListBox^  listBoxDayCciDir;
	private: System::Windows::Forms::Label^  labelDayCci;
	private: System::Windows::Forms::TextBox^  textBoxDayCrC;
	private: System::Windows::Forms::Label^  labelDayCrC;
	private: System::Windows::Forms::TextBox^  textBoxDayCrB;
	private: System::Windows::Forms::Label^  labelDayCrB;
	private: System::Windows::Forms::TextBox^  textBoxDayCrA;
	private: System::Windows::Forms::TextBox^  textBoxDayCrCr;
	private: System::Windows::Forms::Label^  labelDayCrA;
	private: System::Windows::Forms::Label^  labelDayCrCr;
	private: System::Windows::Forms::Label^  labelDayCrDir;
	private: System::Windows::Forms::ListBox^  listBoxDayCrDir;
	private: System::Windows::Forms::Label^  labelDayCr;
	private: System::Windows::Forms::TextBox^  textBoxDayDmaAma;
	private: System::Windows::Forms::TextBox^  textBoxDayDmaDma;
	private: System::Windows::Forms::Label^  labelDayDmaAma;
	private: System::Windows::Forms::Label^  labelDayDmaDma;
	private: System::Windows::Forms::Label^  labelDayDmaDir;
	private: System::Windows::Forms::ListBox^  listBoxDayDmaDir;
	private: System::Windows::Forms::Label^  labelDayDma;
	private: System::Windows::Forms::TextBox^  textBoxDayRocRocma;
	private: System::Windows::Forms::TextBox^  textBoxDayRocRoc;
	private: System::Windows::Forms::Label^  labelDayRocMa;
	private: System::Windows::Forms::Label^  labelDayRocRoc;
	private: System::Windows::Forms::Label^  labelDayRocDir;
	private: System::Windows::Forms::ListBox^  listBoxDayRocDir;
	private: System::Windows::Forms::Label^  labelDayRoc;
	private: System::Windows::Forms::TextBox^  textBoxDayVrLong;
	private: System::Windows::Forms::TextBox^  textBoxDayVrShort;
	private: System::Windows::Forms::Label^  labelDayVrLong;
	private: System::Windows::Forms::Label^  labelDayVrShort;
	private: System::Windows::Forms::Label^  labelDayVrDir;
	private: System::Windows::Forms::ListBox^  listBoxDayVrDir;
	private: System::Windows::Forms::Label^  labelDayVr;
	private: System::Windows::Forms::Label^  labelDayVolDir2;
	private: System::Windows::Forms::ListBox^  listBoxDayVolDir2;
	private: System::Windows::Forms::TextBox^  textBoxDayVol2;
	private: System::Windows::Forms::TextBox^  textBoxDayVol1;
	private: System::Windows::Forms::Label^  labelDayVol2;
	private: System::Windows::Forms::Label^  labelDayVol1;
	private: System::Windows::Forms::Label^  labelDayVolDir1;
	private: System::Windows::Forms::ListBox^  listBoxDayVolDir1;
	private: System::Windows::Forms::Label^  labelDayVol;
	private: System::Windows::Forms::TextBox^  textBoxDayWr2;
	private: System::Windows::Forms::TextBox^  textBoxDayWr1;
	private: System::Windows::Forms::Label^  labelDayWrLong;
	private: System::Windows::Forms::Label^  labelDayWrShort;
	private: System::Windows::Forms::Label^  labelDayWrDir;
	private: System::Windows::Forms::ListBox^  listBoxDayWrDir;
	private: System::Windows::Forms::Label^  labelDayWr;
	private: System::Windows::Forms::TextBox^  textBoxDayRsiLong;
	private: System::Windows::Forms::TextBox^  textBoxDayRsiMiddle;
	private: System::Windows::Forms::TextBox^  textBoxDayRsiShort;
	private: System::Windows::Forms::Label^  labelDayRsiLong;
	private: System::Windows::Forms::Label^  labelDayRsiMiddle;
	private: System::Windows::Forms::Label^  labelDayRsiShort;
	private: System::Windows::Forms::Label^  labelDayRsiDir;
	private: System::Windows::Forms::ListBox^  listBoxDayRsiDir;
	private: System::Windows::Forms::Label^  labelDayRsi;
	private: System::Windows::Forms::TextBox^  textBoxDayKdjJ;
	private: System::Windows::Forms::TextBox^  textBoxDayKdjD;
	private: System::Windows::Forms::TextBox^  textBoxDayKdjK;
	private: System::Windows::Forms::Label^  labelDayKdjJ;
	private: System::Windows::Forms::Label^  labelDayKdjD;
	private: System::Windows::Forms::Label^  labelDayKdjK;
	private: System::Windows::Forms::Label^  labelDayKdjDir;
	private: System::Windows::Forms::ListBox^  listBoxDayKdjDir;
	private: System::Windows::Forms::Label^  labelDayKdj;
	private: System::Windows::Forms::TextBox^  textBoxDayMacdDea;
	private: System::Windows::Forms::TextBox^  textBoxDayMacdDif;
	private: System::Windows::Forms::TextBox^  textBoxDayMacdMacd;
	private: System::Windows::Forms::Label^  labelDayMacdDea;
	private: System::Windows::Forms::Label^  labelDayMacdDif;
	private: System::Windows::Forms::Label^  labelDayMacdMacd;
	private: System::Windows::Forms::Label^  labelDayMacdDir;
	private: System::Windows::Forms::ListBox^  listBoxDayMacdDir;
	private: System::Windows::Forms::Label^  labelDayMacd;
	private: System::Windows::Forms::TextBox^  textBoxDayBollUpper;
	private: System::Windows::Forms::TextBox^  textBoxDayBollMid;
	private: System::Windows::Forms::TextBox^  textBoxDayBollLow;
	private: System::Windows::Forms::Label^  labelDayBollUpper;
	private: System::Windows::Forms::Label^  labelDayBollMid;
	private: System::Windows::Forms::Label^  labelDayBollLow;
	private: System::Windows::Forms::Label^  labelDayBollDir;
	private: System::Windows::Forms::ListBox^  listBoxDayBollDir;
	private: System::Windows::Forms::Label^  labelDayBoll;
	private: System::Windows::Forms::ListBox^  listBoxYearMADir6;
	private: System::Windows::Forms::ListBox^  listBox4HourMADir6;
	private: System::Windows::Forms::ListBox^  listBoxDayMADir6;
	private: System::Windows::Forms::ListBox^  listBoxWeekMADir6;
	private: System::Windows::Forms::ListBox^  listBoxMonthMADir6;
	private: System::Windows::Forms::ListBox^  listBox15MinMADir6;
	private: System::Windows::Forms::ListBox^  listBox30MinMADir6;
	private: System::Windows::Forms::ListBox^  listBox45MinMADir6;
	private: System::Windows::Forms::ListBox^  listBoxHourMADir6;
	private: System::Windows::Forms::ListBox^  listBox10MinMADir6;
	private: System::Windows::Forms::ListBox^  listBox5MinMADir6;
private: System::Windows::Forms::ToolStripMenuItem^  settingToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  donateToolStripMenuItem;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->parseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->donateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labelPrice = (gcnew System::Windows::Forms::Label());
			this->textBoxPrice = (gcnew System::Windows::Forms::TextBox());
			this->tab10Min = (gcnew System::Windows::Forms::TabPage());
			this->listBox10MinMADir6 = (gcnew System::Windows::Forms::ListBox());
			this->label10MinMADir6 = (gcnew System::Windows::Forms::Label());
			this->textBox10MinMA6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinMA5 = (gcnew System::Windows::Forms::TextBox());
			this->label10MinMA6 = (gcnew System::Windows::Forms::Label());
			this->label10MinMA5 = (gcnew System::Windows::Forms::Label());
			this->label10MinMADir5 = (gcnew System::Windows::Forms::Label());
			this->listBox10MinMADir5 = (gcnew System::Windows::Forms::ListBox());
			this->label10MinMA56 = (gcnew System::Windows::Forms::Label());
			this->label10MinMADir4 = (gcnew System::Windows::Forms::Label());
			this->listBox10MinMADir4 = (gcnew System::Windows::Forms::ListBox());
			this->textBox10MinMA4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinMA3 = (gcnew System::Windows::Forms::TextBox());
			this->label10MinMA4 = (gcnew System::Windows::Forms::Label());
			this->label10MinMA3 = (gcnew System::Windows::Forms::Label());
			this->label10MinMADir3 = (gcnew System::Windows::Forms::Label());
			this->listBox10MinMADir3 = (gcnew System::Windows::Forms::ListBox());
			this->label10MinMA34 = (gcnew System::Windows::Forms::Label());
			this->label10MinMADir2 = (gcnew System::Windows::Forms::Label());
			this->listBox10MinMADir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox10MinMA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinMA1 = (gcnew System::Windows::Forms::TextBox());
			this->label10MinMA2 = (gcnew System::Windows::Forms::Label());
			this->label10MinMA1 = (gcnew System::Windows::Forms::Label());
			this->label10MinMADir1 = (gcnew System::Windows::Forms::Label());
			this->listBox10MinMADir1 = (gcnew System::Windows::Forms::ListBox());
			this->label10MinMA12 = (gcnew System::Windows::Forms::Label());
			this->textBox10MinCciCci = (gcnew System::Windows::Forms::TextBox());
			this->label10MinCciCci = (gcnew System::Windows::Forms::Label());
			this->label10MinCciDir = (gcnew System::Windows::Forms::Label());
			this->listBox10MinCciDir = (gcnew System::Windows::Forms::ListBox());
			this->label10MinCci = (gcnew System::Windows::Forms::Label());
			this->textBox10MinCrC = (gcnew System::Windows::Forms::TextBox());
			this->label10MinCrC = (gcnew System::Windows::Forms::Label());
			this->textBox10MinCrB = (gcnew System::Windows::Forms::TextBox());
			this->label10MinCrB = (gcnew System::Windows::Forms::Label());
			this->textBox10MinCrA = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinCrCr = (gcnew System::Windows::Forms::TextBox());
			this->label10MinCrA = (gcnew System::Windows::Forms::Label());
			this->label10MinCrCr = (gcnew System::Windows::Forms::Label());
			this->label10MinCrDir = (gcnew System::Windows::Forms::Label());
			this->listBox10MinCrDir = (gcnew System::Windows::Forms::ListBox());
			this->label10MinCr = (gcnew System::Windows::Forms::Label());
			this->textBox10MinDmaAma = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinDmaDma = (gcnew System::Windows::Forms::TextBox());
			this->label10MinDmaAma = (gcnew System::Windows::Forms::Label());
			this->label10MinDmaDma = (gcnew System::Windows::Forms::Label());
			this->label10MinDmaDir = (gcnew System::Windows::Forms::Label());
			this->listBox10MinDmaDir = (gcnew System::Windows::Forms::ListBox());
			this->label10MinDma = (gcnew System::Windows::Forms::Label());
			this->textBox10MinRocRocma = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinRocRoc = (gcnew System::Windows::Forms::TextBox());
			this->label10MinRocRocma = (gcnew System::Windows::Forms::Label());
			this->label10MinRocRoc = (gcnew System::Windows::Forms::Label());
			this->label10MinRocDir = (gcnew System::Windows::Forms::Label());
			this->listBox10MinRocDir = (gcnew System::Windows::Forms::ListBox());
			this->label10MinRoc = (gcnew System::Windows::Forms::Label());
			this->textBox10MinVrLong = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinVrShort = (gcnew System::Windows::Forms::TextBox());
			this->label10MinVrLong = (gcnew System::Windows::Forms::Label());
			this->label10MinVrShort = (gcnew System::Windows::Forms::Label());
			this->label10MinVrDir = (gcnew System::Windows::Forms::Label());
			this->listBox10MinVrDir = (gcnew System::Windows::Forms::ListBox());
			this->label10MinVr = (gcnew System::Windows::Forms::Label());
			this->label10MinVolDir2 = (gcnew System::Windows::Forms::Label());
			this->listBox10MinVolDir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox10MinVol2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinVol1 = (gcnew System::Windows::Forms::TextBox());
			this->label10MinVol2 = (gcnew System::Windows::Forms::Label());
			this->label10MinVol1 = (gcnew System::Windows::Forms::Label());
			this->label10MinVolDir1 = (gcnew System::Windows::Forms::Label());
			this->listBox10MinVolDir1 = (gcnew System::Windows::Forms::ListBox());
			this->label10MinVol = (gcnew System::Windows::Forms::Label());
			this->textBox10MinWr2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinWr1 = (gcnew System::Windows::Forms::TextBox());
			this->label10MinWr2 = (gcnew System::Windows::Forms::Label());
			this->label10MinWr1 = (gcnew System::Windows::Forms::Label());
			this->label10MinWrDir = (gcnew System::Windows::Forms::Label());
			this->listBox10MinWrDir = (gcnew System::Windows::Forms::ListBox());
			this->label10MinWr = (gcnew System::Windows::Forms::Label());
			this->textBox10MinRsiLong = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinRsiMiddle = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinRsiShort = (gcnew System::Windows::Forms::TextBox());
			this->label10MinRsiLong = (gcnew System::Windows::Forms::Label());
			this->label10MinRsiMiddle = (gcnew System::Windows::Forms::Label());
			this->label10MinRsiShort = (gcnew System::Windows::Forms::Label());
			this->label10MinRsiDir = (gcnew System::Windows::Forms::Label());
			this->listBox10MinRsiDir = (gcnew System::Windows::Forms::ListBox());
			this->label10MinRsi = (gcnew System::Windows::Forms::Label());
			this->textBox10MinKdjJ = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinKdjD = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinKdjK = (gcnew System::Windows::Forms::TextBox());
			this->label10MinKdjJ = (gcnew System::Windows::Forms::Label());
			this->label10MinKdjD = (gcnew System::Windows::Forms::Label());
			this->label10MinKdjK = (gcnew System::Windows::Forms::Label());
			this->label10MinKdjDir = (gcnew System::Windows::Forms::Label());
			this->listBox10MinKdjDir = (gcnew System::Windows::Forms::ListBox());
			this->label10MinKdj = (gcnew System::Windows::Forms::Label());
			this->textBox10MinMacdDea = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinMacdDif = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinMacdMacd = (gcnew System::Windows::Forms::TextBox());
			this->label10MinMacdDea = (gcnew System::Windows::Forms::Label());
			this->label10MinMacdDif = (gcnew System::Windows::Forms::Label());
			this->label10MinMacdMacd = (gcnew System::Windows::Forms::Label());
			this->label10MinMacdDir = (gcnew System::Windows::Forms::Label());
			this->listBox10MinMacdDir = (gcnew System::Windows::Forms::ListBox());
			this->label10MinMacd = (gcnew System::Windows::Forms::Label());
			this->textBox10MinBollUpper = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinBollMid = (gcnew System::Windows::Forms::TextBox());
			this->textBox10MinBollLow = (gcnew System::Windows::Forms::TextBox());
			this->label10MinBollUpper = (gcnew System::Windows::Forms::Label());
			this->label10MinBollMid = (gcnew System::Windows::Forms::Label());
			this->label10MinBollLow = (gcnew System::Windows::Forms::Label());
			this->label10MinBollDir = (gcnew System::Windows::Forms::Label());
			this->listBox10MinBollDir = (gcnew System::Windows::Forms::ListBox());
			this->label10MinBoll = (gcnew System::Windows::Forms::Label());
			this->tab15Min = (gcnew System::Windows::Forms::TabPage());
			this->listBox15MinMADir6 = (gcnew System::Windows::Forms::ListBox());
			this->label15MinMADir6 = (gcnew System::Windows::Forms::Label());
			this->textBox15MinMA6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinMA5 = (gcnew System::Windows::Forms::TextBox());
			this->label15MinMA6 = (gcnew System::Windows::Forms::Label());
			this->label15MinMA5 = (gcnew System::Windows::Forms::Label());
			this->label15MinMADir5 = (gcnew System::Windows::Forms::Label());
			this->listBox15MinMADir5 = (gcnew System::Windows::Forms::ListBox());
			this->label15MinMA56 = (gcnew System::Windows::Forms::Label());
			this->label15MinMADir4 = (gcnew System::Windows::Forms::Label());
			this->listBox15MinMADir4 = (gcnew System::Windows::Forms::ListBox());
			this->textBox15MinMA4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinMA3 = (gcnew System::Windows::Forms::TextBox());
			this->label15MinMA4 = (gcnew System::Windows::Forms::Label());
			this->label15MinMA3 = (gcnew System::Windows::Forms::Label());
			this->label15MinMADir3 = (gcnew System::Windows::Forms::Label());
			this->listBox15MinMADir3 = (gcnew System::Windows::Forms::ListBox());
			this->label15MinMA34 = (gcnew System::Windows::Forms::Label());
			this->label15MinMADir2 = (gcnew System::Windows::Forms::Label());
			this->listBox15MinMADir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox15MinMA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinMA1 = (gcnew System::Windows::Forms::TextBox());
			this->label15MinMA2 = (gcnew System::Windows::Forms::Label());
			this->label15MinMA1 = (gcnew System::Windows::Forms::Label());
			this->label15MinMADir1 = (gcnew System::Windows::Forms::Label());
			this->listBox15MinMADir1 = (gcnew System::Windows::Forms::ListBox());
			this->label15MinMA12 = (gcnew System::Windows::Forms::Label());
			this->textBox15MinCciCci = (gcnew System::Windows::Forms::TextBox());
			this->label15MinCciCci = (gcnew System::Windows::Forms::Label());
			this->label15MinCciDir = (gcnew System::Windows::Forms::Label());
			this->listBox15MinCciDir = (gcnew System::Windows::Forms::ListBox());
			this->label15MinCci = (gcnew System::Windows::Forms::Label());
			this->textBox15MinCrC = (gcnew System::Windows::Forms::TextBox());
			this->label15MinCrC = (gcnew System::Windows::Forms::Label());
			this->textBox15MinCrB = (gcnew System::Windows::Forms::TextBox());
			this->label15MinCrB = (gcnew System::Windows::Forms::Label());
			this->textBox15MinCrA = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinCrCr = (gcnew System::Windows::Forms::TextBox());
			this->label15MinCrA = (gcnew System::Windows::Forms::Label());
			this->label15MinCrCr = (gcnew System::Windows::Forms::Label());
			this->label15MinCrDir = (gcnew System::Windows::Forms::Label());
			this->listBox15MinCrDir = (gcnew System::Windows::Forms::ListBox());
			this->label15MinCr = (gcnew System::Windows::Forms::Label());
			this->textBox15MinDmaAma = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinDmaDma = (gcnew System::Windows::Forms::TextBox());
			this->label15MinDmaAma = (gcnew System::Windows::Forms::Label());
			this->label15MinDmaDma = (gcnew System::Windows::Forms::Label());
			this->label15MinDmaDir = (gcnew System::Windows::Forms::Label());
			this->listBox15MinDmaDir = (gcnew System::Windows::Forms::ListBox());
			this->label15MinDma = (gcnew System::Windows::Forms::Label());
			this->textBox15MinRocRocma = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinRocRoc = (gcnew System::Windows::Forms::TextBox());
			this->label15MinRocRocma = (gcnew System::Windows::Forms::Label());
			this->label15MinRocRoc = (gcnew System::Windows::Forms::Label());
			this->label15MinRocDir = (gcnew System::Windows::Forms::Label());
			this->listBox15MinRocDir = (gcnew System::Windows::Forms::ListBox());
			this->label15MinRoc = (gcnew System::Windows::Forms::Label());
			this->textBox15MinVrLong = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinVrShort = (gcnew System::Windows::Forms::TextBox());
			this->label15MinVrLong = (gcnew System::Windows::Forms::Label());
			this->label15MinVrShort = (gcnew System::Windows::Forms::Label());
			this->label15MinVrDir = (gcnew System::Windows::Forms::Label());
			this->listBox15MinVrDir = (gcnew System::Windows::Forms::ListBox());
			this->label15MinVr = (gcnew System::Windows::Forms::Label());
			this->label15MinVolDir2 = (gcnew System::Windows::Forms::Label());
			this->listBox15MinVolDir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox15MinVol2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinVol1 = (gcnew System::Windows::Forms::TextBox());
			this->label15MinVol2 = (gcnew System::Windows::Forms::Label());
			this->label15MinVol1 = (gcnew System::Windows::Forms::Label());
			this->label15MinVolDir1 = (gcnew System::Windows::Forms::Label());
			this->listBox15MinVolDir1 = (gcnew System::Windows::Forms::ListBox());
			this->label15MinVol = (gcnew System::Windows::Forms::Label());
			this->textBox15MinWr2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinWr1 = (gcnew System::Windows::Forms::TextBox());
			this->label15MinWr2 = (gcnew System::Windows::Forms::Label());
			this->label15MinWr1 = (gcnew System::Windows::Forms::Label());
			this->label15MinWrDir = (gcnew System::Windows::Forms::Label());
			this->listBox15MinWrDir = (gcnew System::Windows::Forms::ListBox());
			this->label15MinWr = (gcnew System::Windows::Forms::Label());
			this->textBox15MinRsiLong = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinRsiMiddle = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinRsiShort = (gcnew System::Windows::Forms::TextBox());
			this->label15MinRsiLong = (gcnew System::Windows::Forms::Label());
			this->label15MinRsiMiddle = (gcnew System::Windows::Forms::Label());
			this->label15MinRsiShort = (gcnew System::Windows::Forms::Label());
			this->label15MinRsiDir = (gcnew System::Windows::Forms::Label());
			this->listBox15MinRsiDir = (gcnew System::Windows::Forms::ListBox());
			this->label15MinRsi = (gcnew System::Windows::Forms::Label());
			this->textBox15MinKdjJ = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinKdjD = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinKdjK = (gcnew System::Windows::Forms::TextBox());
			this->label15MinKdjJ = (gcnew System::Windows::Forms::Label());
			this->label15MinKdjD = (gcnew System::Windows::Forms::Label());
			this->label15MinKdjK = (gcnew System::Windows::Forms::Label());
			this->label15MinKdjDir = (gcnew System::Windows::Forms::Label());
			this->listBox15MinKdjDir = (gcnew System::Windows::Forms::ListBox());
			this->label15MinKdj = (gcnew System::Windows::Forms::Label());
			this->textBox15MinMacdDea = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinMacdDif = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinMacdMacd = (gcnew System::Windows::Forms::TextBox());
			this->label15MinMacdDea = (gcnew System::Windows::Forms::Label());
			this->label15MinMacdDif = (gcnew System::Windows::Forms::Label());
			this->label15MinMacdMacd = (gcnew System::Windows::Forms::Label());
			this->label15MinMacdDir = (gcnew System::Windows::Forms::Label());
			this->listBox15MinMacdDir = (gcnew System::Windows::Forms::ListBox());
			this->label15MinMacd = (gcnew System::Windows::Forms::Label());
			this->textBox15MinBollUpper = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinBollMid = (gcnew System::Windows::Forms::TextBox());
			this->textBox15MinBollLow = (gcnew System::Windows::Forms::TextBox());
			this->label15MinBollUpper = (gcnew System::Windows::Forms::Label());
			this->label15MinBollMid = (gcnew System::Windows::Forms::Label());
			this->label15MinBollLow = (gcnew System::Windows::Forms::Label());
			this->label15MinBollDir = (gcnew System::Windows::Forms::Label());
			this->listBox15MinBollDir = (gcnew System::Windows::Forms::ListBox());
			this->label15MinBoll = (gcnew System::Windows::Forms::Label());
			this->tab30Min = (gcnew System::Windows::Forms::TabPage());
			this->listBox30MinMADir6 = (gcnew System::Windows::Forms::ListBox());
			this->label30MinMADir6 = (gcnew System::Windows::Forms::Label());
			this->textBox30MinMA6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinMA5 = (gcnew System::Windows::Forms::TextBox());
			this->label30MinMA6 = (gcnew System::Windows::Forms::Label());
			this->label30MinMA5 = (gcnew System::Windows::Forms::Label());
			this->label30MinMADir5 = (gcnew System::Windows::Forms::Label());
			this->listBox30MinMADir5 = (gcnew System::Windows::Forms::ListBox());
			this->label30MinMA56 = (gcnew System::Windows::Forms::Label());
			this->label30MinMADir4 = (gcnew System::Windows::Forms::Label());
			this->listBox30MinMADir4 = (gcnew System::Windows::Forms::ListBox());
			this->textBox30MinMA4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinMA3 = (gcnew System::Windows::Forms::TextBox());
			this->label30MinMA4 = (gcnew System::Windows::Forms::Label());
			this->label30MinMA3 = (gcnew System::Windows::Forms::Label());
			this->label30MinMADir3 = (gcnew System::Windows::Forms::Label());
			this->listBox30MinMADir3 = (gcnew System::Windows::Forms::ListBox());
			this->label30MinMA34 = (gcnew System::Windows::Forms::Label());
			this->label30MinMADir2 = (gcnew System::Windows::Forms::Label());
			this->listBox30MinMADir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox30MinMA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinMA1 = (gcnew System::Windows::Forms::TextBox());
			this->label30MinMA2 = (gcnew System::Windows::Forms::Label());
			this->label30MinMA1 = (gcnew System::Windows::Forms::Label());
			this->label30MinMADir1 = (gcnew System::Windows::Forms::Label());
			this->listBox30MinMADir1 = (gcnew System::Windows::Forms::ListBox());
			this->label30MinMA12 = (gcnew System::Windows::Forms::Label());
			this->textBox30MinCciCci = (gcnew System::Windows::Forms::TextBox());
			this->label30MinCciCci = (gcnew System::Windows::Forms::Label());
			this->label30MinCciDir = (gcnew System::Windows::Forms::Label());
			this->listBox30MinCciDir = (gcnew System::Windows::Forms::ListBox());
			this->label30MinCci = (gcnew System::Windows::Forms::Label());
			this->textBox30MinCrC = (gcnew System::Windows::Forms::TextBox());
			this->label30MinCrC = (gcnew System::Windows::Forms::Label());
			this->textBox30MinCrB = (gcnew System::Windows::Forms::TextBox());
			this->label30MinCrB = (gcnew System::Windows::Forms::Label());
			this->textBox30MinCrA = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinCrCr = (gcnew System::Windows::Forms::TextBox());
			this->label30MinCrA = (gcnew System::Windows::Forms::Label());
			this->label30MinCrCr = (gcnew System::Windows::Forms::Label());
			this->label30MinCrDir = (gcnew System::Windows::Forms::Label());
			this->listBox30MinCrDir = (gcnew System::Windows::Forms::ListBox());
			this->label30MinCr = (gcnew System::Windows::Forms::Label());
			this->textBox30MinDmaAma = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinDmaDma = (gcnew System::Windows::Forms::TextBox());
			this->label30MinDmaAma = (gcnew System::Windows::Forms::Label());
			this->label30MinDmaDma = (gcnew System::Windows::Forms::Label());
			this->label30MinDmaDir = (gcnew System::Windows::Forms::Label());
			this->listBox30MinDmaDir = (gcnew System::Windows::Forms::ListBox());
			this->label30MinDma = (gcnew System::Windows::Forms::Label());
			this->textBox30MinRocRocma = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinRocRoc = (gcnew System::Windows::Forms::TextBox());
			this->label30MinRocRocma = (gcnew System::Windows::Forms::Label());
			this->label30MinRocRoc = (gcnew System::Windows::Forms::Label());
			this->label30MinRocDir = (gcnew System::Windows::Forms::Label());
			this->listBox30MinRocDir = (gcnew System::Windows::Forms::ListBox());
			this->label30MinRoc = (gcnew System::Windows::Forms::Label());
			this->textBox30MinVrLong = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinVrShort = (gcnew System::Windows::Forms::TextBox());
			this->label30MinVrLong = (gcnew System::Windows::Forms::Label());
			this->label30MinVrShort = (gcnew System::Windows::Forms::Label());
			this->label30MinVrDir = (gcnew System::Windows::Forms::Label());
			this->listBox30MinVrDir = (gcnew System::Windows::Forms::ListBox());
			this->label30MinVr = (gcnew System::Windows::Forms::Label());
			this->label30MinVolDir2 = (gcnew System::Windows::Forms::Label());
			this->listBox30MinVolDir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox30MinVol2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinVol1 = (gcnew System::Windows::Forms::TextBox());
			this->label30MinVol2 = (gcnew System::Windows::Forms::Label());
			this->label30MinVol1 = (gcnew System::Windows::Forms::Label());
			this->label30MinVolDir1 = (gcnew System::Windows::Forms::Label());
			this->listBox30MinVolDir1 = (gcnew System::Windows::Forms::ListBox());
			this->label30MinVol = (gcnew System::Windows::Forms::Label());
			this->textBox30MinWr2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinWr1 = (gcnew System::Windows::Forms::TextBox());
			this->label30MinWr2 = (gcnew System::Windows::Forms::Label());
			this->label30MinWr1 = (gcnew System::Windows::Forms::Label());
			this->label30MinWrDir = (gcnew System::Windows::Forms::Label());
			this->listBox30MinWrDir = (gcnew System::Windows::Forms::ListBox());
			this->label30MinWr = (gcnew System::Windows::Forms::Label());
			this->textBox30MinRsiLong = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinRsiMiddle = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinRsiShort = (gcnew System::Windows::Forms::TextBox());
			this->label30MinRsiLong = (gcnew System::Windows::Forms::Label());
			this->label30MinRsiMiddle = (gcnew System::Windows::Forms::Label());
			this->label30MinRsiShort = (gcnew System::Windows::Forms::Label());
			this->label30MinRsiDir = (gcnew System::Windows::Forms::Label());
			this->listBox30MinRsiDir = (gcnew System::Windows::Forms::ListBox());
			this->label30MinRsi = (gcnew System::Windows::Forms::Label());
			this->textBox30MinKdjJ = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinKdjD = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinKdjK = (gcnew System::Windows::Forms::TextBox());
			this->label30MinKdjJ = (gcnew System::Windows::Forms::Label());
			this->label30MinKdjD = (gcnew System::Windows::Forms::Label());
			this->label30MinKdjK = (gcnew System::Windows::Forms::Label());
			this->label30MinKdjDir = (gcnew System::Windows::Forms::Label());
			this->listBox30MinKdjDir = (gcnew System::Windows::Forms::ListBox());
			this->label30MinKdj = (gcnew System::Windows::Forms::Label());
			this->textBox30MinMacdDea = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinMacdDif = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinMacdMacd = (gcnew System::Windows::Forms::TextBox());
			this->label30MinMacdDea = (gcnew System::Windows::Forms::Label());
			this->label30MinMacdDif = (gcnew System::Windows::Forms::Label());
			this->label30MinMacdMacd = (gcnew System::Windows::Forms::Label());
			this->label30MinMacdDir = (gcnew System::Windows::Forms::Label());
			this->listBox30MinMacdDir = (gcnew System::Windows::Forms::ListBox());
			this->label30MinMacd = (gcnew System::Windows::Forms::Label());
			this->textBox30MinBollUpper = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinBollMid = (gcnew System::Windows::Forms::TextBox());
			this->textBox30MinBollLow = (gcnew System::Windows::Forms::TextBox());
			this->label30MinBollUpper = (gcnew System::Windows::Forms::Label());
			this->label30MinBollMid = (gcnew System::Windows::Forms::Label());
			this->label30MinBollLow = (gcnew System::Windows::Forms::Label());
			this->label30MinBollDir = (gcnew System::Windows::Forms::Label());
			this->listBox30MinBollDir = (gcnew System::Windows::Forms::ListBox());
			this->label30MinBoll = (gcnew System::Windows::Forms::Label());
			this->tab45Min = (gcnew System::Windows::Forms::TabPage());
			this->listBox45MinMADir6 = (gcnew System::Windows::Forms::ListBox());
			this->label45MinMADir6 = (gcnew System::Windows::Forms::Label());
			this->textBox45MinMA6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinMA5 = (gcnew System::Windows::Forms::TextBox());
			this->label45MinMA6 = (gcnew System::Windows::Forms::Label());
			this->label45MinMA5 = (gcnew System::Windows::Forms::Label());
			this->label45MinMADir5 = (gcnew System::Windows::Forms::Label());
			this->listBox45MinMADir5 = (gcnew System::Windows::Forms::ListBox());
			this->label45MinMA56 = (gcnew System::Windows::Forms::Label());
			this->label45MinMADir4 = (gcnew System::Windows::Forms::Label());
			this->listBox45MinMADir4 = (gcnew System::Windows::Forms::ListBox());
			this->textBox45MinMA4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinMA3 = (gcnew System::Windows::Forms::TextBox());
			this->label45MinMA4 = (gcnew System::Windows::Forms::Label());
			this->label45MinMA3 = (gcnew System::Windows::Forms::Label());
			this->label45MinMADir3 = (gcnew System::Windows::Forms::Label());
			this->listBox45MinMADir3 = (gcnew System::Windows::Forms::ListBox());
			this->label45MinMA34 = (gcnew System::Windows::Forms::Label());
			this->label45MinMADir2 = (gcnew System::Windows::Forms::Label());
			this->listBox45MinMADir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox45MinMA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinMA1 = (gcnew System::Windows::Forms::TextBox());
			this->label45MinMA2 = (gcnew System::Windows::Forms::Label());
			this->label45MinMA1 = (gcnew System::Windows::Forms::Label());
			this->label45MinMADir1 = (gcnew System::Windows::Forms::Label());
			this->listBox45MinMADir1 = (gcnew System::Windows::Forms::ListBox());
			this->label45MinMA12 = (gcnew System::Windows::Forms::Label());
			this->textBox45MinCciCci = (gcnew System::Windows::Forms::TextBox());
			this->label45MinCciCci = (gcnew System::Windows::Forms::Label());
			this->label45MinCciDir = (gcnew System::Windows::Forms::Label());
			this->listBox45MinCciDir = (gcnew System::Windows::Forms::ListBox());
			this->label45MinCci = (gcnew System::Windows::Forms::Label());
			this->textBox45MinCrC = (gcnew System::Windows::Forms::TextBox());
			this->label45MinCrC = (gcnew System::Windows::Forms::Label());
			this->textBox45MinCrB = (gcnew System::Windows::Forms::TextBox());
			this->label45MinCrB = (gcnew System::Windows::Forms::Label());
			this->textBox45MinCrA = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinCrCr = (gcnew System::Windows::Forms::TextBox());
			this->label45MinCrA = (gcnew System::Windows::Forms::Label());
			this->label45MinCrCr = (gcnew System::Windows::Forms::Label());
			this->label45MinCrDir = (gcnew System::Windows::Forms::Label());
			this->listBox45MinCrDir = (gcnew System::Windows::Forms::ListBox());
			this->label45MinCr = (gcnew System::Windows::Forms::Label());
			this->textBox45MinDmaAma = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinDmaDma = (gcnew System::Windows::Forms::TextBox());
			this->label45MinDmaAma = (gcnew System::Windows::Forms::Label());
			this->label45MinDmaDma = (gcnew System::Windows::Forms::Label());
			this->label45MinDmaDir = (gcnew System::Windows::Forms::Label());
			this->listBox45MinDmaDir = (gcnew System::Windows::Forms::ListBox());
			this->label45MinDma = (gcnew System::Windows::Forms::Label());
			this->textBox45MinRocRocma = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinRocRoc = (gcnew System::Windows::Forms::TextBox());
			this->label45MinRocRocma = (gcnew System::Windows::Forms::Label());
			this->label45MinRocRoc = (gcnew System::Windows::Forms::Label());
			this->label45MinRocDir = (gcnew System::Windows::Forms::Label());
			this->listBox45MinRocDir = (gcnew System::Windows::Forms::ListBox());
			this->label45MinRoc = (gcnew System::Windows::Forms::Label());
			this->textBox45MinVrLong = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinVrShort = (gcnew System::Windows::Forms::TextBox());
			this->label45MinVrLong = (gcnew System::Windows::Forms::Label());
			this->label45MinVrShort = (gcnew System::Windows::Forms::Label());
			this->label45MinVrDir = (gcnew System::Windows::Forms::Label());
			this->listBox45MinVrDir = (gcnew System::Windows::Forms::ListBox());
			this->label45MinVr = (gcnew System::Windows::Forms::Label());
			this->label45MinVolDir2 = (gcnew System::Windows::Forms::Label());
			this->listBox45MinVolDir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox45MinVol2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinVol1 = (gcnew System::Windows::Forms::TextBox());
			this->label45MinVol2 = (gcnew System::Windows::Forms::Label());
			this->label45MinVol1 = (gcnew System::Windows::Forms::Label());
			this->label45MinVolDir1 = (gcnew System::Windows::Forms::Label());
			this->listBox45MinVolDir1 = (gcnew System::Windows::Forms::ListBox());
			this->label45MinVol = (gcnew System::Windows::Forms::Label());
			this->textBox45MinWr2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinWr1 = (gcnew System::Windows::Forms::TextBox());
			this->label45MinWr2 = (gcnew System::Windows::Forms::Label());
			this->label45MinWr1 = (gcnew System::Windows::Forms::Label());
			this->label45MinWrDir = (gcnew System::Windows::Forms::Label());
			this->listBox45MinWrDir = (gcnew System::Windows::Forms::ListBox());
			this->label45MinWr = (gcnew System::Windows::Forms::Label());
			this->textBox45MinRsiLong = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinRsiMiddle = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinRsiShort = (gcnew System::Windows::Forms::TextBox());
			this->label45MinRsiLong = (gcnew System::Windows::Forms::Label());
			this->label45MinRsiMiddle = (gcnew System::Windows::Forms::Label());
			this->label45MinRsiShort = (gcnew System::Windows::Forms::Label());
			this->label45MinRsiDir = (gcnew System::Windows::Forms::Label());
			this->listBox45MinRsiDir = (gcnew System::Windows::Forms::ListBox());
			this->label45MinRsi = (gcnew System::Windows::Forms::Label());
			this->textBox45MinKdjJ = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinKdjD = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinKdjK = (gcnew System::Windows::Forms::TextBox());
			this->label45MinKdjJ = (gcnew System::Windows::Forms::Label());
			this->label45MinKdjD = (gcnew System::Windows::Forms::Label());
			this->label45MinKdjK = (gcnew System::Windows::Forms::Label());
			this->label45MinKdjDir = (gcnew System::Windows::Forms::Label());
			this->listBox45MinKdjDir = (gcnew System::Windows::Forms::ListBox());
			this->label45MinKdj = (gcnew System::Windows::Forms::Label());
			this->textBox45MinMacdDea = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinMacdDif = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinMacdMacd = (gcnew System::Windows::Forms::TextBox());
			this->label45MinMacdDea = (gcnew System::Windows::Forms::Label());
			this->label45MinMacdDif = (gcnew System::Windows::Forms::Label());
			this->label45MinMacdMacd = (gcnew System::Windows::Forms::Label());
			this->label45MinMacdDir = (gcnew System::Windows::Forms::Label());
			this->listBox45MinMacdDir = (gcnew System::Windows::Forms::ListBox());
			this->label45MinMacd = (gcnew System::Windows::Forms::Label());
			this->textBox45MinBollUpper = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinBollMid = (gcnew System::Windows::Forms::TextBox());
			this->textBox45MinBollLow = (gcnew System::Windows::Forms::TextBox());
			this->label45MinBollUpper = (gcnew System::Windows::Forms::Label());
			this->label45MinBollMid = (gcnew System::Windows::Forms::Label());
			this->label45MinBollLow = (gcnew System::Windows::Forms::Label());
			this->label45MinBollDir = (gcnew System::Windows::Forms::Label());
			this->listBox45MinBollDir = (gcnew System::Windows::Forms::ListBox());
			this->label45MinBoll = (gcnew System::Windows::Forms::Label());
			this->tabHour = (gcnew System::Windows::Forms::TabPage());
			this->listBoxHourMADir6 = (gcnew System::Windows::Forms::ListBox());
			this->labelHourMADir6 = (gcnew System::Windows::Forms::Label());
			this->textBoxHourMA6 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourMA5 = (gcnew System::Windows::Forms::TextBox());
			this->labelHourMA6 = (gcnew System::Windows::Forms::Label());
			this->labelHourMA5 = (gcnew System::Windows::Forms::Label());
			this->labelHourMADir5 = (gcnew System::Windows::Forms::Label());
			this->listBoxHourMADir5 = (gcnew System::Windows::Forms::ListBox());
			this->labelHourMA56 = (gcnew System::Windows::Forms::Label());
			this->labelHourMADir4 = (gcnew System::Windows::Forms::Label());
			this->listBoxHourMADir4 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxHourMA4 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourMA3 = (gcnew System::Windows::Forms::TextBox());
			this->labelHourMA4 = (gcnew System::Windows::Forms::Label());
			this->labelHourMA3 = (gcnew System::Windows::Forms::Label());
			this->labelHourMADir3 = (gcnew System::Windows::Forms::Label());
			this->listBoxHourMADir3 = (gcnew System::Windows::Forms::ListBox());
			this->labelHourMA34 = (gcnew System::Windows::Forms::Label());
			this->labelHourMADir2 = (gcnew System::Windows::Forms::Label());
			this->listBoxHourMADir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxHourMA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourMA1 = (gcnew System::Windows::Forms::TextBox());
			this->labelHourMA2 = (gcnew System::Windows::Forms::Label());
			this->labelHourMA1 = (gcnew System::Windows::Forms::Label());
			this->labelHourMADir1 = (gcnew System::Windows::Forms::Label());
			this->listBoxHourMADir1 = (gcnew System::Windows::Forms::ListBox());
			this->labelHourMA12 = (gcnew System::Windows::Forms::Label());
			this->textBoxHourCciCci = (gcnew System::Windows::Forms::TextBox());
			this->labelHourCciCci = (gcnew System::Windows::Forms::Label());
			this->labelHourCciDir = (gcnew System::Windows::Forms::Label());
			this->listBoxHourCciDir = (gcnew System::Windows::Forms::ListBox());
			this->labelHourCci = (gcnew System::Windows::Forms::Label());
			this->textBoxHourCrC = (gcnew System::Windows::Forms::TextBox());
			this->labelHourCrC = (gcnew System::Windows::Forms::Label());
			this->textBoxHourCrB = (gcnew System::Windows::Forms::TextBox());
			this->labelHourCrB = (gcnew System::Windows::Forms::Label());
			this->textBoxHourCrA = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourCrCr = (gcnew System::Windows::Forms::TextBox());
			this->labelHourCrA = (gcnew System::Windows::Forms::Label());
			this->labelHourCrCr = (gcnew System::Windows::Forms::Label());
			this->labelHourCrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxHourCrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelHourCr = (gcnew System::Windows::Forms::Label());
			this->textBoxHourDmaAma = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourDmaDma = (gcnew System::Windows::Forms::TextBox());
			this->labelHourDmaAma = (gcnew System::Windows::Forms::Label());
			this->labelHourDmaDma = (gcnew System::Windows::Forms::Label());
			this->labelHourDmaDir = (gcnew System::Windows::Forms::Label());
			this->listBoxHourDmaDir = (gcnew System::Windows::Forms::ListBox());
			this->labelHourDma = (gcnew System::Windows::Forms::Label());
			this->textBoxHourRocRocma = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourRocRoc = (gcnew System::Windows::Forms::TextBox());
			this->labelHourRocRocma = (gcnew System::Windows::Forms::Label());
			this->labelHourRocRoc = (gcnew System::Windows::Forms::Label());
			this->labelHourRocDir = (gcnew System::Windows::Forms::Label());
			this->listBoxHourRocDir = (gcnew System::Windows::Forms::ListBox());
			this->labelHourRoc = (gcnew System::Windows::Forms::Label());
			this->textBoxHourVrLong = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourVrShort = (gcnew System::Windows::Forms::TextBox());
			this->labelHourVrLong = (gcnew System::Windows::Forms::Label());
			this->labelHourVrShort = (gcnew System::Windows::Forms::Label());
			this->labelHourVrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxHourVrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelHourVr = (gcnew System::Windows::Forms::Label());
			this->labelHourVolDir2 = (gcnew System::Windows::Forms::Label());
			this->listBoxHourVolDir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxHourVol2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourVol1 = (gcnew System::Windows::Forms::TextBox());
			this->labelHourVol2 = (gcnew System::Windows::Forms::Label());
			this->labelHourVol1 = (gcnew System::Windows::Forms::Label());
			this->labelHourVolDir1 = (gcnew System::Windows::Forms::Label());
			this->listBoxHourVolDir1 = (gcnew System::Windows::Forms::ListBox());
			this->labelHourVol = (gcnew System::Windows::Forms::Label());
			this->textBoxHourWr2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourWr1 = (gcnew System::Windows::Forms::TextBox());
			this->labelHourWr2 = (gcnew System::Windows::Forms::Label());
			this->labelHourWr1 = (gcnew System::Windows::Forms::Label());
			this->labelHourWrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxHourWrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelHourWr = (gcnew System::Windows::Forms::Label());
			this->textBoxHourRsiLong = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourRsiMiddle = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourRsiShort = (gcnew System::Windows::Forms::TextBox());
			this->labelHourRsiLong = (gcnew System::Windows::Forms::Label());
			this->labelHourRsiMiddle = (gcnew System::Windows::Forms::Label());
			this->labelHourRsiShort = (gcnew System::Windows::Forms::Label());
			this->labelHourRsiDir = (gcnew System::Windows::Forms::Label());
			this->listBoxHourRsiDir = (gcnew System::Windows::Forms::ListBox());
			this->labelHourRsi = (gcnew System::Windows::Forms::Label());
			this->textBoxHourKdjJ = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourKdjD = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourKdjK = (gcnew System::Windows::Forms::TextBox());
			this->labelHourKdjJ = (gcnew System::Windows::Forms::Label());
			this->labelHourKdjD = (gcnew System::Windows::Forms::Label());
			this->labelHourKdjK = (gcnew System::Windows::Forms::Label());
			this->labelHourKdjDir = (gcnew System::Windows::Forms::Label());
			this->listBoxHourKdjDir = (gcnew System::Windows::Forms::ListBox());
			this->labelHourKdj = (gcnew System::Windows::Forms::Label());
			this->textBoxHourMacdDea = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourMacdDif = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourMacdMacd = (gcnew System::Windows::Forms::TextBox());
			this->labelHourMacdDea = (gcnew System::Windows::Forms::Label());
			this->labelHourMacdDif = (gcnew System::Windows::Forms::Label());
			this->labelHourMacdMacd = (gcnew System::Windows::Forms::Label());
			this->labelHourMacdDir = (gcnew System::Windows::Forms::Label());
			this->listBoxHourMacdDir = (gcnew System::Windows::Forms::ListBox());
			this->labelHourMacd = (gcnew System::Windows::Forms::Label());
			this->textBoxHourBollUpper = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourBollMid = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHourBollLow = (gcnew System::Windows::Forms::TextBox());
			this->labelHourBollUpper = (gcnew System::Windows::Forms::Label());
			this->labelHourBollMid = (gcnew System::Windows::Forms::Label());
			this->labelHourBollLow = (gcnew System::Windows::Forms::Label());
			this->labelHourBollDir = (gcnew System::Windows::Forms::Label());
			this->listBoxHourBollDir = (gcnew System::Windows::Forms::ListBox());
			this->labelHourBoll = (gcnew System::Windows::Forms::Label());
			this->tab4Hour = (gcnew System::Windows::Forms::TabPage());
			this->listBox4HourMADir6 = (gcnew System::Windows::Forms::ListBox());
			this->label4HourMADir6 = (gcnew System::Windows::Forms::Label());
			this->textBox4HourMA6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourMA5 = (gcnew System::Windows::Forms::TextBox());
			this->label4HourMA6 = (gcnew System::Windows::Forms::Label());
			this->label4HourMA5 = (gcnew System::Windows::Forms::Label());
			this->label4HourMADir5 = (gcnew System::Windows::Forms::Label());
			this->listBox4HourMADir5 = (gcnew System::Windows::Forms::ListBox());
			this->label4HourMA56 = (gcnew System::Windows::Forms::Label());
			this->label4HourMADir4 = (gcnew System::Windows::Forms::Label());
			this->listBox4HourMADir4 = (gcnew System::Windows::Forms::ListBox());
			this->textBox4HourMA4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourMA3 = (gcnew System::Windows::Forms::TextBox());
			this->label4HourMA4 = (gcnew System::Windows::Forms::Label());
			this->label4HourMA3 = (gcnew System::Windows::Forms::Label());
			this->label4HourMADir3 = (gcnew System::Windows::Forms::Label());
			this->listBox4HourMADir3 = (gcnew System::Windows::Forms::ListBox());
			this->label4HourMA34 = (gcnew System::Windows::Forms::Label());
			this->label4HourMADir2 = (gcnew System::Windows::Forms::Label());
			this->listBox4HourMADir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox4HourMA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourMA1 = (gcnew System::Windows::Forms::TextBox());
			this->label4HourMA2 = (gcnew System::Windows::Forms::Label());
			this->label4HourMA1 = (gcnew System::Windows::Forms::Label());
			this->label4HourMADir1 = (gcnew System::Windows::Forms::Label());
			this->listBox4HourMADir1 = (gcnew System::Windows::Forms::ListBox());
			this->label4HourMA12 = (gcnew System::Windows::Forms::Label());
			this->textBox4HourCciCci = (gcnew System::Windows::Forms::TextBox());
			this->label4HourCciCci = (gcnew System::Windows::Forms::Label());
			this->label4HourCciDir = (gcnew System::Windows::Forms::Label());
			this->listBox4HourCciDir = (gcnew System::Windows::Forms::ListBox());
			this->label4HourCci = (gcnew System::Windows::Forms::Label());
			this->textBox4HourCrC = (gcnew System::Windows::Forms::TextBox());
			this->label4HourCrC = (gcnew System::Windows::Forms::Label());
			this->textBox4HourCrB = (gcnew System::Windows::Forms::TextBox());
			this->label4HourCrB = (gcnew System::Windows::Forms::Label());
			this->textBox4HourCrA = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourCrCr = (gcnew System::Windows::Forms::TextBox());
			this->label4HourCrA = (gcnew System::Windows::Forms::Label());
			this->label4HourCrCr = (gcnew System::Windows::Forms::Label());
			this->label4HourCrDir = (gcnew System::Windows::Forms::Label());
			this->listBox4HourCrDir = (gcnew System::Windows::Forms::ListBox());
			this->label4HourCr = (gcnew System::Windows::Forms::Label());
			this->textBox4HourDmaAma = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourDmaDma = (gcnew System::Windows::Forms::TextBox());
			this->label4HourDmaAma = (gcnew System::Windows::Forms::Label());
			this->label4HourDmaDma = (gcnew System::Windows::Forms::Label());
			this->label4HourDmaDir = (gcnew System::Windows::Forms::Label());
			this->listBox4HourDmaDir = (gcnew System::Windows::Forms::ListBox());
			this->label4HourDma = (gcnew System::Windows::Forms::Label());
			this->textBox4HourRocRocma = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourRocRoc = (gcnew System::Windows::Forms::TextBox());
			this->label4HourRocRocma = (gcnew System::Windows::Forms::Label());
			this->label4HourRocRoc = (gcnew System::Windows::Forms::Label());
			this->label4HourRocDir = (gcnew System::Windows::Forms::Label());
			this->listBox4HourRocDir = (gcnew System::Windows::Forms::ListBox());
			this->label4HourRoc = (gcnew System::Windows::Forms::Label());
			this->textBox4HourVrLong = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourVrShort = (gcnew System::Windows::Forms::TextBox());
			this->label4HourVrLong = (gcnew System::Windows::Forms::Label());
			this->label4HourVrShort = (gcnew System::Windows::Forms::Label());
			this->label4HourVrDir = (gcnew System::Windows::Forms::Label());
			this->listBox4HourVrDir = (gcnew System::Windows::Forms::ListBox());
			this->label4HourVr = (gcnew System::Windows::Forms::Label());
			this->label4HourVolDir2 = (gcnew System::Windows::Forms::Label());
			this->listBox4HourVolDir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox4HourVol2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourVol1 = (gcnew System::Windows::Forms::TextBox());
			this->label4HourVol2 = (gcnew System::Windows::Forms::Label());
			this->label4HourVol1 = (gcnew System::Windows::Forms::Label());
			this->label4HourVolDir1 = (gcnew System::Windows::Forms::Label());
			this->listBox4HourVolDir1 = (gcnew System::Windows::Forms::ListBox());
			this->label4HourVol = (gcnew System::Windows::Forms::Label());
			this->textBox4HourWr2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourWr1 = (gcnew System::Windows::Forms::TextBox());
			this->label4HourWr2 = (gcnew System::Windows::Forms::Label());
			this->label4HourWr1 = (gcnew System::Windows::Forms::Label());
			this->label4HourWrDir = (gcnew System::Windows::Forms::Label());
			this->listBox4HourWrDir = (gcnew System::Windows::Forms::ListBox());
			this->label4HourWr = (gcnew System::Windows::Forms::Label());
			this->textBox4HourRsiLong = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourRsiMiddle = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourRsiShort = (gcnew System::Windows::Forms::TextBox());
			this->label4HourRsiLong = (gcnew System::Windows::Forms::Label());
			this->label4HourRsiMiddle = (gcnew System::Windows::Forms::Label());
			this->label4HourRsiShort = (gcnew System::Windows::Forms::Label());
			this->label4HourRsiDir = (gcnew System::Windows::Forms::Label());
			this->listBox4HourRsiDir = (gcnew System::Windows::Forms::ListBox());
			this->label4HourRsi = (gcnew System::Windows::Forms::Label());
			this->textBox4HourKdjJ = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourKdjD = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourKdjK = (gcnew System::Windows::Forms::TextBox());
			this->label4HourKdjJ = (gcnew System::Windows::Forms::Label());
			this->label4HourKdjD = (gcnew System::Windows::Forms::Label());
			this->label4HourKdjK = (gcnew System::Windows::Forms::Label());
			this->label4HourKdjDir = (gcnew System::Windows::Forms::Label());
			this->listBox4HourKdjDir = (gcnew System::Windows::Forms::ListBox());
			this->label4HourKdj = (gcnew System::Windows::Forms::Label());
			this->textBox4HourMacdDea = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourMacdDif = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourMacdMacd = (gcnew System::Windows::Forms::TextBox());
			this->label4HourMacdDea = (gcnew System::Windows::Forms::Label());
			this->label4HourMacdDif = (gcnew System::Windows::Forms::Label());
			this->label4HourMacdMacd = (gcnew System::Windows::Forms::Label());
			this->label4HourMacdDir = (gcnew System::Windows::Forms::Label());
			this->listBox4HourMacdDir = (gcnew System::Windows::Forms::ListBox());
			this->label4HourMacd = (gcnew System::Windows::Forms::Label());
			this->textBox4HourBollUpper = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourBollMid = (gcnew System::Windows::Forms::TextBox());
			this->textBox4HourBollLow = (gcnew System::Windows::Forms::TextBox());
			this->label4HourBollUpper = (gcnew System::Windows::Forms::Label());
			this->label4HourBollMid = (gcnew System::Windows::Forms::Label());
			this->label4HourBollLow = (gcnew System::Windows::Forms::Label());
			this->label4HourBollDir = (gcnew System::Windows::Forms::Label());
			this->listBox4HourBollDir = (gcnew System::Windows::Forms::ListBox());
			this->label4HourBoll = (gcnew System::Windows::Forms::Label());
			this->tabDay = (gcnew System::Windows::Forms::TabPage());
			this->listBoxDayMADir6 = (gcnew System::Windows::Forms::ListBox());
			this->labelDayMADir6 = (gcnew System::Windows::Forms::Label());
			this->textBoxDayMA6 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayMA5 = (gcnew System::Windows::Forms::TextBox());
			this->labelDayMA6 = (gcnew System::Windows::Forms::Label());
			this->labelDayMA5 = (gcnew System::Windows::Forms::Label());
			this->labelDayMADir5 = (gcnew System::Windows::Forms::Label());
			this->listBoxDayMADir5 = (gcnew System::Windows::Forms::ListBox());
			this->labelDayMA56 = (gcnew System::Windows::Forms::Label());
			this->labelDayMADir4 = (gcnew System::Windows::Forms::Label());
			this->listBoxDayMADir4 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxDayMA4 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayMA3 = (gcnew System::Windows::Forms::TextBox());
			this->labelDayMA4 = (gcnew System::Windows::Forms::Label());
			this->labelDayMA3 = (gcnew System::Windows::Forms::Label());
			this->labelDayMADir3 = (gcnew System::Windows::Forms::Label());
			this->listBoxDayMADir3 = (gcnew System::Windows::Forms::ListBox());
			this->labelDayMA34 = (gcnew System::Windows::Forms::Label());
			this->label1DayMADir2 = (gcnew System::Windows::Forms::Label());
			this->listBoxDayMADir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxDayMA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayMA1 = (gcnew System::Windows::Forms::TextBox());
			this->labelDayMA2 = (gcnew System::Windows::Forms::Label());
			this->labelDayMa1 = (gcnew System::Windows::Forms::Label());
			this->labelDayMaDir1 = (gcnew System::Windows::Forms::Label());
			this->listBoxDayMADir1 = (gcnew System::Windows::Forms::ListBox());
			this->labelDayMa12 = (gcnew System::Windows::Forms::Label());
			this->textBoxDayCciCci = (gcnew System::Windows::Forms::TextBox());
			this->labelDayCciCci = (gcnew System::Windows::Forms::Label());
			this->labelDayCciDir = (gcnew System::Windows::Forms::Label());
			this->listBoxDayCciDir = (gcnew System::Windows::Forms::ListBox());
			this->labelDayCci = (gcnew System::Windows::Forms::Label());
			this->textBoxDayCrC = (gcnew System::Windows::Forms::TextBox());
			this->labelDayCrC = (gcnew System::Windows::Forms::Label());
			this->textBoxDayCrB = (gcnew System::Windows::Forms::TextBox());
			this->labelDayCrB = (gcnew System::Windows::Forms::Label());
			this->textBoxDayCrA = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayCrCr = (gcnew System::Windows::Forms::TextBox());
			this->labelDayCrA = (gcnew System::Windows::Forms::Label());
			this->labelDayCrCr = (gcnew System::Windows::Forms::Label());
			this->labelDayCrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxDayCrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelDayCr = (gcnew System::Windows::Forms::Label());
			this->textBoxDayDmaAma = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayDmaDma = (gcnew System::Windows::Forms::TextBox());
			this->labelDayDmaAma = (gcnew System::Windows::Forms::Label());
			this->labelDayDmaDma = (gcnew System::Windows::Forms::Label());
			this->labelDayDmaDir = (gcnew System::Windows::Forms::Label());
			this->listBoxDayDmaDir = (gcnew System::Windows::Forms::ListBox());
			this->labelDayDma = (gcnew System::Windows::Forms::Label());
			this->textBoxDayRocRocma = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayRocRoc = (gcnew System::Windows::Forms::TextBox());
			this->labelDayRocMa = (gcnew System::Windows::Forms::Label());
			this->labelDayRocRoc = (gcnew System::Windows::Forms::Label());
			this->labelDayRocDir = (gcnew System::Windows::Forms::Label());
			this->listBoxDayRocDir = (gcnew System::Windows::Forms::ListBox());
			this->labelDayRoc = (gcnew System::Windows::Forms::Label());
			this->textBoxDayVrLong = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayVrShort = (gcnew System::Windows::Forms::TextBox());
			this->labelDayVrLong = (gcnew System::Windows::Forms::Label());
			this->labelDayVrShort = (gcnew System::Windows::Forms::Label());
			this->labelDayVrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxDayVrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelDayVr = (gcnew System::Windows::Forms::Label());
			this->labelDayVolDir2 = (gcnew System::Windows::Forms::Label());
			this->listBoxDayVolDir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxDayVol2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayVol1 = (gcnew System::Windows::Forms::TextBox());
			this->labelDayVol2 = (gcnew System::Windows::Forms::Label());
			this->labelDayVol1 = (gcnew System::Windows::Forms::Label());
			this->labelDayVolDir1 = (gcnew System::Windows::Forms::Label());
			this->listBoxDayVolDir1 = (gcnew System::Windows::Forms::ListBox());
			this->labelDayVol = (gcnew System::Windows::Forms::Label());
			this->textBoxDayWr2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayWr1 = (gcnew System::Windows::Forms::TextBox());
			this->labelDayWrLong = (gcnew System::Windows::Forms::Label());
			this->labelDayWrShort = (gcnew System::Windows::Forms::Label());
			this->labelDayWrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxDayWrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelDayWr = (gcnew System::Windows::Forms::Label());
			this->textBoxDayRsiLong = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayRsiMiddle = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayRsiShort = (gcnew System::Windows::Forms::TextBox());
			this->labelDayRsiLong = (gcnew System::Windows::Forms::Label());
			this->labelDayRsiMiddle = (gcnew System::Windows::Forms::Label());
			this->labelDayRsiShort = (gcnew System::Windows::Forms::Label());
			this->labelDayRsiDir = (gcnew System::Windows::Forms::Label());
			this->listBoxDayRsiDir = (gcnew System::Windows::Forms::ListBox());
			this->labelDayRsi = (gcnew System::Windows::Forms::Label());
			this->textBoxDayKdjJ = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayKdjD = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayKdjK = (gcnew System::Windows::Forms::TextBox());
			this->labelDayKdjJ = (gcnew System::Windows::Forms::Label());
			this->labelDayKdjD = (gcnew System::Windows::Forms::Label());
			this->labelDayKdjK = (gcnew System::Windows::Forms::Label());
			this->labelDayKdjDir = (gcnew System::Windows::Forms::Label());
			this->listBoxDayKdjDir = (gcnew System::Windows::Forms::ListBox());
			this->labelDayKdj = (gcnew System::Windows::Forms::Label());
			this->textBoxDayMacdDea = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayMacdDif = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayMacdMacd = (gcnew System::Windows::Forms::TextBox());
			this->labelDayMacdDea = (gcnew System::Windows::Forms::Label());
			this->labelDayMacdDif = (gcnew System::Windows::Forms::Label());
			this->labelDayMacdMacd = (gcnew System::Windows::Forms::Label());
			this->labelDayMacdDir = (gcnew System::Windows::Forms::Label());
			this->listBoxDayMacdDir = (gcnew System::Windows::Forms::ListBox());
			this->labelDayMacd = (gcnew System::Windows::Forms::Label());
			this->textBoxDayBollUpper = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayBollMid = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDayBollLow = (gcnew System::Windows::Forms::TextBox());
			this->labelDayBollUpper = (gcnew System::Windows::Forms::Label());
			this->labelDayBollMid = (gcnew System::Windows::Forms::Label());
			this->labelDayBollLow = (gcnew System::Windows::Forms::Label());
			this->labelDayBollDir = (gcnew System::Windows::Forms::Label());
			this->listBoxDayBollDir = (gcnew System::Windows::Forms::ListBox());
			this->labelDayBoll = (gcnew System::Windows::Forms::Label());
			this->tabWeek = (gcnew System::Windows::Forms::TabPage());
			this->listBoxWeekMADir6 = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekMADir6 = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekMA6 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekMA5 = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekMA6 = (gcnew System::Windows::Forms::Label());
			this->labelWeekMA5 = (gcnew System::Windows::Forms::Label());
			this->labelWeekMADir5 = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekMADir5 = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekMADir56 = (gcnew System::Windows::Forms::Label());
			this->labelWeekMADir4 = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekMADir4 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxWeekMA4 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekMA3 = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekMA4 = (gcnew System::Windows::Forms::Label());
			this->labelWeekMA3 = (gcnew System::Windows::Forms::Label());
			this->labelWeekMADir3 = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekMADir3 = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekMADir34 = (gcnew System::Windows::Forms::Label());
			this->labelWeekMADir2 = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekMADir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxWeekMA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekMA1 = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekMA2 = (gcnew System::Windows::Forms::Label());
			this->labelWeekMA1 = (gcnew System::Windows::Forms::Label());
			this->labelWeekMADir1 = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekMADir1 = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekMA12 = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekCciCci = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekCciCci = (gcnew System::Windows::Forms::Label());
			this->labelWeekCciDir = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekCciDir = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekCci = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekCrC = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekCrC = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekCrB = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekCrB = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekCrA = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekCrCr = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekCrA = (gcnew System::Windows::Forms::Label());
			this->labelWeekCrCr = (gcnew System::Windows::Forms::Label());
			this->labelWeekCrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekCrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekCr = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekDmaAma = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekDmaDma = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekDmaAma = (gcnew System::Windows::Forms::Label());
			this->labelWeekDmaDma = (gcnew System::Windows::Forms::Label());
			this->labelWeekDmaDir = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekDmaDir = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekDma = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekRocRocma = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekRocRoc = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekRocRocma = (gcnew System::Windows::Forms::Label());
			this->labelWeekRocRoc = (gcnew System::Windows::Forms::Label());
			this->labelWeekRocDir = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekRocDir = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekRoc = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekVrLong = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekVrShort = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekVrLong = (gcnew System::Windows::Forms::Label());
			this->labelWeekVrShort = (gcnew System::Windows::Forms::Label());
			this->labelWeekVrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekVrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekVr = (gcnew System::Windows::Forms::Label());
			this->labelWeekVolDir2 = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekVolDir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxWeekVol2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekVol1 = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekVol2 = (gcnew System::Windows::Forms::Label());
			this->labelWeekVol1 = (gcnew System::Windows::Forms::Label());
			this->labelWeekVolDir1 = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekVolDir1 = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekVol = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekWr2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekWr1 = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekWr2 = (gcnew System::Windows::Forms::Label());
			this->labelWeekWr1 = (gcnew System::Windows::Forms::Label());
			this->labelWeekWrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekWrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekWr = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekRsiLong = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekRsiMiddle = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekRsiShort = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekRsiLong = (gcnew System::Windows::Forms::Label());
			this->labelWeekRsiMiddle = (gcnew System::Windows::Forms::Label());
			this->labelWeekRsiShort = (gcnew System::Windows::Forms::Label());
			this->labelWeekRsiDir = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekRsiDir = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekRsi = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekKdjJ = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekKdjD = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekKdjK = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekKdjJ = (gcnew System::Windows::Forms::Label());
			this->labelWeekKdjD = (gcnew System::Windows::Forms::Label());
			this->labelWeekKdjK = (gcnew System::Windows::Forms::Label());
			this->labelWeekKdjDir = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekKdjDir = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekKdj = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekMacdDea = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekMacdDif = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekMacdMacd = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekMacdDea = (gcnew System::Windows::Forms::Label());
			this->labelWeekMacdDif = (gcnew System::Windows::Forms::Label());
			this->labelWeekMacdMacd = (gcnew System::Windows::Forms::Label());
			this->labelWeekMacdDir = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekMacdDir = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekMacd = (gcnew System::Windows::Forms::Label());
			this->textBoxWeekBollUpper = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekBollMid = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeekBollLow = (gcnew System::Windows::Forms::TextBox());
			this->labelWeekBollUpper = (gcnew System::Windows::Forms::Label());
			this->labelWeekBollMid = (gcnew System::Windows::Forms::Label());
			this->labelWeekBollLow = (gcnew System::Windows::Forms::Label());
			this->labelWeekBollDir = (gcnew System::Windows::Forms::Label());
			this->listBoxWeekBollDir = (gcnew System::Windows::Forms::ListBox());
			this->labelWeekBoll = (gcnew System::Windows::Forms::Label());
			this->tabMonth = (gcnew System::Windows::Forms::TabPage());
			this->listBoxMonthMADir6 = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthMADir6 = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthMA6 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthMA5 = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthMA6 = (gcnew System::Windows::Forms::Label());
			this->labelMonthMA5 = (gcnew System::Windows::Forms::Label());
			this->labelMonthMADir5 = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthMADir5 = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthMA56 = (gcnew System::Windows::Forms::Label());
			this->labelMonthMADir4 = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthMADir4 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxMonthMA4 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthMA3 = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthMA4 = (gcnew System::Windows::Forms::Label());
			this->labelMonthMA3 = (gcnew System::Windows::Forms::Label());
			this->labelMonthMADir3 = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthMADir3 = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthMA34 = (gcnew System::Windows::Forms::Label());
			this->labelMonthMADir2 = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthMADir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxMonthMA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthMA1 = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthMA2 = (gcnew System::Windows::Forms::Label());
			this->labelMonthMA1 = (gcnew System::Windows::Forms::Label());
			this->labelMonthMADir1 = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthMADir1 = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthMA12 = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthCciCci = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthCciCci = (gcnew System::Windows::Forms::Label());
			this->labelMonthCciDir = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthCciDir = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthCci = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthCrC = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthCrC = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthCrB = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthCrB = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthCrA = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthCrCr = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthCrA = (gcnew System::Windows::Forms::Label());
			this->labelMonthCrCr = (gcnew System::Windows::Forms::Label());
			this->labelMonthCrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthCrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthCr = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthDmaAma = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthDmaDma = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthDmaAma = (gcnew System::Windows::Forms::Label());
			this->labelMonthDmaDma = (gcnew System::Windows::Forms::Label());
			this->labelMonthDmaDir = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthDmaDir = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthDma = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthRocRocma = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthRocRoc = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthRocRocma = (gcnew System::Windows::Forms::Label());
			this->labelMonthRocRoc = (gcnew System::Windows::Forms::Label());
			this->labelMonthRocDir = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthRocDir = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthRoc = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthVrLong = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthVrShort = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthVrLong = (gcnew System::Windows::Forms::Label());
			this->labelMonthVrShort = (gcnew System::Windows::Forms::Label());
			this->labelMonthVrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthVrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthVr = (gcnew System::Windows::Forms::Label());
			this->labelMonthVolDir2 = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthVolDir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxMonthVol2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthVol1 = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthVol2 = (gcnew System::Windows::Forms::Label());
			this->labelMonthVol1 = (gcnew System::Windows::Forms::Label());
			this->labelMonthVolDir1 = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthVolDir1 = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthVol = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthWr2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthWr1 = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthWr2 = (gcnew System::Windows::Forms::Label());
			this->labelMonthWr1 = (gcnew System::Windows::Forms::Label());
			this->labelMonthWrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthWrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthWr = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthRsiLong = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthRsiMiddle = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthRsiShort = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthRsiLong = (gcnew System::Windows::Forms::Label());
			this->labelMonthRsiMiddle = (gcnew System::Windows::Forms::Label());
			this->labelMonthRsiShort = (gcnew System::Windows::Forms::Label());
			this->labelMonthRsiDir = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthRsiDir = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthRsi = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthKdjJ = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthKdjD = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthKdjK = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthKdjJ = (gcnew System::Windows::Forms::Label());
			this->labelMonthKdjD = (gcnew System::Windows::Forms::Label());
			this->labelMonthKdjK = (gcnew System::Windows::Forms::Label());
			this->labelMonthKdjDir = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthKdjDir = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthKdj = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthMacdDea = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthMacdDif = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthMacdMacd = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthMacdDea = (gcnew System::Windows::Forms::Label());
			this->labelMonthMacdDif = (gcnew System::Windows::Forms::Label());
			this->labelMonthMacdMacd = (gcnew System::Windows::Forms::Label());
			this->labelMonthMacdDir = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthMacdDir = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthMacd = (gcnew System::Windows::Forms::Label());
			this->textBoxMonthBollUpper = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthBollMid = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonthBollLow = (gcnew System::Windows::Forms::TextBox());
			this->labelMonthBollUpper = (gcnew System::Windows::Forms::Label());
			this->labelMonthBollMid = (gcnew System::Windows::Forms::Label());
			this->labelMonthBollLow = (gcnew System::Windows::Forms::Label());
			this->labelMonthBollDir = (gcnew System::Windows::Forms::Label());
			this->listBoxMonthBollDir = (gcnew System::Windows::Forms::ListBox());
			this->labelMonthBoll = (gcnew System::Windows::Forms::Label());
			this->tabYear = (gcnew System::Windows::Forms::TabPage());
			this->listBoxYearMADir6 = (gcnew System::Windows::Forms::ListBox());
			this->labelYearMADir6 = (gcnew System::Windows::Forms::Label());
			this->textBoxYearMA6 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearMA5 = (gcnew System::Windows::Forms::TextBox());
			this->labelYearMA6 = (gcnew System::Windows::Forms::Label());
			this->labelYearMA5 = (gcnew System::Windows::Forms::Label());
			this->labelYearMADir5 = (gcnew System::Windows::Forms::Label());
			this->listBoxYearMADir5 = (gcnew System::Windows::Forms::ListBox());
			this->labelYearMA56 = (gcnew System::Windows::Forms::Label());
			this->labelYearMADir4 = (gcnew System::Windows::Forms::Label());
			this->listBoxYearMADir4 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxYearMA4 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearMA3 = (gcnew System::Windows::Forms::TextBox());
			this->labelYearMA4 = (gcnew System::Windows::Forms::Label());
			this->labelYearMA3 = (gcnew System::Windows::Forms::Label());
			this->labelYearMADir3 = (gcnew System::Windows::Forms::Label());
			this->listBoxYearMADir3 = (gcnew System::Windows::Forms::ListBox());
			this->labelYearMA34 = (gcnew System::Windows::Forms::Label());
			this->labelYearMADir2 = (gcnew System::Windows::Forms::Label());
			this->listBoxYearMADir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxYearMA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearMA1 = (gcnew System::Windows::Forms::TextBox());
			this->labelYearMA2 = (gcnew System::Windows::Forms::Label());
			this->labelYearMA1 = (gcnew System::Windows::Forms::Label());
			this->labelYearMADir1 = (gcnew System::Windows::Forms::Label());
			this->listBoxYearMADir1 = (gcnew System::Windows::Forms::ListBox());
			this->labelYearMA12 = (gcnew System::Windows::Forms::Label());
			this->textBoxYearCciCci = (gcnew System::Windows::Forms::TextBox());
			this->labelYearCciCci = (gcnew System::Windows::Forms::Label());
			this->labelYearCciDir = (gcnew System::Windows::Forms::Label());
			this->listBoxYearCciDir = (gcnew System::Windows::Forms::ListBox());
			this->labelYearCci = (gcnew System::Windows::Forms::Label());
			this->textBoxYearCrC = (gcnew System::Windows::Forms::TextBox());
			this->labelYearCrC = (gcnew System::Windows::Forms::Label());
			this->textBoxYearCrB = (gcnew System::Windows::Forms::TextBox());
			this->labelYearCrB = (gcnew System::Windows::Forms::Label());
			this->textBoxYearCrA = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearCrCr = (gcnew System::Windows::Forms::TextBox());
			this->labelYearCrA = (gcnew System::Windows::Forms::Label());
			this->labelYearCrCr = (gcnew System::Windows::Forms::Label());
			this->labeYearCrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxYearCrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelYearCr = (gcnew System::Windows::Forms::Label());
			this->textBoxYearDmaAma = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearDmaDma = (gcnew System::Windows::Forms::TextBox());
			this->labelYearDmaAma = (gcnew System::Windows::Forms::Label());
			this->labelYearDmaDma = (gcnew System::Windows::Forms::Label());
			this->labelYearDmaDir = (gcnew System::Windows::Forms::Label());
			this->listBoxYearDmaDir = (gcnew System::Windows::Forms::ListBox());
			this->labelYearDma = (gcnew System::Windows::Forms::Label());
			this->textBoxYearRocRocma = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearRocRoc = (gcnew System::Windows::Forms::TextBox());
			this->labelYearRocRoc_ma = (gcnew System::Windows::Forms::Label());
			this->labelYearRocRoc = (gcnew System::Windows::Forms::Label());
			this->labelYearRocDir = (gcnew System::Windows::Forms::Label());
			this->listBoxYearRocDir = (gcnew System::Windows::Forms::ListBox());
			this->labelYearRoc = (gcnew System::Windows::Forms::Label());
			this->textBoxYearVrLong = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearVrShort = (gcnew System::Windows::Forms::TextBox());
			this->labelYearVrLong = (gcnew System::Windows::Forms::Label());
			this->labelYearVrShort = (gcnew System::Windows::Forms::Label());
			this->labelYearVrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxYearVrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelYearVr = (gcnew System::Windows::Forms::Label());
			this->labelYearVolDir2 = (gcnew System::Windows::Forms::Label());
			this->listBoxYearVolDir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBoxYearVol2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearVol1 = (gcnew System::Windows::Forms::TextBox());
			this->labelYearVol2 = (gcnew System::Windows::Forms::Label());
			this->labelYearVol1 = (gcnew System::Windows::Forms::Label());
			this->labelYearVolDir1 = (gcnew System::Windows::Forms::Label());
			this->listBoxYearVolDir1 = (gcnew System::Windows::Forms::ListBox());
			this->labelYearVol = (gcnew System::Windows::Forms::Label());
			this->textBoxYearWr2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearWr1 = (gcnew System::Windows::Forms::TextBox());
			this->labelYearWr2 = (gcnew System::Windows::Forms::Label());
			this->labelYearWr1 = (gcnew System::Windows::Forms::Label());
			this->labelYearWrDir = (gcnew System::Windows::Forms::Label());
			this->listBoxYearWrDir = (gcnew System::Windows::Forms::ListBox());
			this->labelYearWr = (gcnew System::Windows::Forms::Label());
			this->textBoxYearRsiLong = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearRsiMiddle = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearRsiShort = (gcnew System::Windows::Forms::TextBox());
			this->labelYearRsiLong = (gcnew System::Windows::Forms::Label());
			this->labelYearRsiMiddle = (gcnew System::Windows::Forms::Label());
			this->labelYearRsiShort = (gcnew System::Windows::Forms::Label());
			this->labelYearRsiDir = (gcnew System::Windows::Forms::Label());
			this->listBoxYearRsiDir = (gcnew System::Windows::Forms::ListBox());
			this->labelYearRsi = (gcnew System::Windows::Forms::Label());
			this->textBoxYearKdjJ = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearKdjD = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearKdjK = (gcnew System::Windows::Forms::TextBox());
			this->labelYearKdjJ = (gcnew System::Windows::Forms::Label());
			this->labelYearKdjD = (gcnew System::Windows::Forms::Label());
			this->labelYearKdjK = (gcnew System::Windows::Forms::Label());
			this->labelYearKdjDir = (gcnew System::Windows::Forms::Label());
			this->listBoxYearKdjDir = (gcnew System::Windows::Forms::ListBox());
			this->labelYearKdj = (gcnew System::Windows::Forms::Label());
			this->textBoxYearMacdDea = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearMacdDif = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearMacdMacd = (gcnew System::Windows::Forms::TextBox());
			this->labelYearMacdDea = (gcnew System::Windows::Forms::Label());
			this->labelYearMacdDif = (gcnew System::Windows::Forms::Label());
			this->labelYearMacdMacd = (gcnew System::Windows::Forms::Label());
			this->labelYearMacdDir = (gcnew System::Windows::Forms::Label());
			this->listBoxYearMacdDir = (gcnew System::Windows::Forms::ListBox());
			this->labelYearMacd = (gcnew System::Windows::Forms::Label());
			this->textBoxYearBollUpper = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearBollMid = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYearBollLow = (gcnew System::Windows::Forms::TextBox());
			this->labelYearBollUpper = (gcnew System::Windows::Forms::Label());
			this->labelYearBollMid = (gcnew System::Windows::Forms::Label());
			this->labelYearBollLow = (gcnew System::Windows::Forms::Label());
			this->labelYearBollDir = (gcnew System::Windows::Forms::Label());
			this->listBoxYearBollDir = (gcnew System::Windows::Forms::ListBox());
			this->labelYearBoll = (gcnew System::Windows::Forms::Label());
			this->woperateParseTab = (gcnew System::Windows::Forms::TabControl());
			this->tab5Min = (gcnew System::Windows::Forms::TabPage());
			this->listBox5MinMADir6 = (gcnew System::Windows::Forms::ListBox());
			this->label5MinMADir6 = (gcnew System::Windows::Forms::Label());
			this->textBox5MinMA6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinMA5 = (gcnew System::Windows::Forms::TextBox());
			this->label5MinMA6 = (gcnew System::Windows::Forms::Label());
			this->label5MinMA5 = (gcnew System::Windows::Forms::Label());
			this->label5MinMADir5 = (gcnew System::Windows::Forms::Label());
			this->listBox5MinMADir5 = (gcnew System::Windows::Forms::ListBox());
			this->label5MinMA56 = (gcnew System::Windows::Forms::Label());
			this->label5MinMADir4 = (gcnew System::Windows::Forms::Label());
			this->listBox5MinMADir4 = (gcnew System::Windows::Forms::ListBox());
			this->textBox5MinMA4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinMA3 = (gcnew System::Windows::Forms::TextBox());
			this->label5MinMA4 = (gcnew System::Windows::Forms::Label());
			this->label5MinMA3 = (gcnew System::Windows::Forms::Label());
			this->label5MinMADir3 = (gcnew System::Windows::Forms::Label());
			this->listBox5MinMADir3 = (gcnew System::Windows::Forms::ListBox());
			this->label5MinMA34 = (gcnew System::Windows::Forms::Label());
			this->label5MinMADir2 = (gcnew System::Windows::Forms::Label());
			this->listBox5MinMADir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox5MinMA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinMA1 = (gcnew System::Windows::Forms::TextBox());
			this->label5MinMA2 = (gcnew System::Windows::Forms::Label());
			this->label5MinMA1 = (gcnew System::Windows::Forms::Label());
			this->label5MinMADir1 = (gcnew System::Windows::Forms::Label());
			this->listBox5MinMADir1 = (gcnew System::Windows::Forms::ListBox());
			this->label5MinMA12 = (gcnew System::Windows::Forms::Label());
			this->textBox5MinCciCci = (gcnew System::Windows::Forms::TextBox());
			this->label5MinCciCci = (gcnew System::Windows::Forms::Label());
			this->label5MinCciDir = (gcnew System::Windows::Forms::Label());
			this->listBox5MinCciDir = (gcnew System::Windows::Forms::ListBox());
			this->label5MinCci = (gcnew System::Windows::Forms::Label());
			this->textBox5MinCrC = (gcnew System::Windows::Forms::TextBox());
			this->label5MinCrC = (gcnew System::Windows::Forms::Label());
			this->textBox5MinCrB = (gcnew System::Windows::Forms::TextBox());
			this->label5MinCrB = (gcnew System::Windows::Forms::Label());
			this->textBox5MinCrA = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinCrCr = (gcnew System::Windows::Forms::TextBox());
			this->label5MinCrA = (gcnew System::Windows::Forms::Label());
			this->label5MinCrCr = (gcnew System::Windows::Forms::Label());
			this->label5MinCrDir = (gcnew System::Windows::Forms::Label());
			this->listBox5MinCrDir = (gcnew System::Windows::Forms::ListBox());
			this->label5MinCr = (gcnew System::Windows::Forms::Label());
			this->textBox5MinDmaAma = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinDmaDma = (gcnew System::Windows::Forms::TextBox());
			this->label5MinDmaAma = (gcnew System::Windows::Forms::Label());
			this->label5MinDmaDma = (gcnew System::Windows::Forms::Label());
			this->label5MinDmaDir = (gcnew System::Windows::Forms::Label());
			this->listBox5MinDmaDir = (gcnew System::Windows::Forms::ListBox());
			this->label5MinDma = (gcnew System::Windows::Forms::Label());
			this->textBox5MinRocRocma = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinRocRoc = (gcnew System::Windows::Forms::TextBox());
			this->label5MinRocRocma = (gcnew System::Windows::Forms::Label());
			this->label5MinRocRoc = (gcnew System::Windows::Forms::Label());
			this->label5MinRocDir = (gcnew System::Windows::Forms::Label());
			this->listBox5MinRocDir = (gcnew System::Windows::Forms::ListBox());
			this->label5MinRoc = (gcnew System::Windows::Forms::Label());
			this->textBox5MinVrLong = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinVrShort = (gcnew System::Windows::Forms::TextBox());
			this->label5MinVrLong = (gcnew System::Windows::Forms::Label());
			this->label5MinVrShort = (gcnew System::Windows::Forms::Label());
			this->label5MinVrDir = (gcnew System::Windows::Forms::Label());
			this->listBox5MinVrDir = (gcnew System::Windows::Forms::ListBox());
			this->label5MinVr = (gcnew System::Windows::Forms::Label());
			this->label5MinVolDir2 = (gcnew System::Windows::Forms::Label());
			this->listBox5MinVolDir2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox5MinVol2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinVol1 = (gcnew System::Windows::Forms::TextBox());
			this->label5MinVol2 = (gcnew System::Windows::Forms::Label());
			this->label5MinVol1 = (gcnew System::Windows::Forms::Label());
			this->label5MinVolDir1 = (gcnew System::Windows::Forms::Label());
			this->listBox5MinVolDir1 = (gcnew System::Windows::Forms::ListBox());
			this->label5MinVol = (gcnew System::Windows::Forms::Label());
			this->textBox5MinWr2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinWr1 = (gcnew System::Windows::Forms::TextBox());
			this->label5MinWr2 = (gcnew System::Windows::Forms::Label());
			this->label5MinWr1 = (gcnew System::Windows::Forms::Label());
			this->label5MinWrDir = (gcnew System::Windows::Forms::Label());
			this->listBox5MinWrDir = (gcnew System::Windows::Forms::ListBox());
			this->label5MinWr = (gcnew System::Windows::Forms::Label());
			this->textBox5MinRsiLong = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinRsiMiddle = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinRsiShort = (gcnew System::Windows::Forms::TextBox());
			this->label5MinRsiLong = (gcnew System::Windows::Forms::Label());
			this->label5MinRsiMiddle = (gcnew System::Windows::Forms::Label());
			this->label5MinRsiShort = (gcnew System::Windows::Forms::Label());
			this->label5MinRsiDir = (gcnew System::Windows::Forms::Label());
			this->listBox5MinRsiDir = (gcnew System::Windows::Forms::ListBox());
			this->label5MinRsi = (gcnew System::Windows::Forms::Label());
			this->textBox5MinKdjJ = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinKdjD = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinKdjK = (gcnew System::Windows::Forms::TextBox());
			this->label5MinKdjJ = (gcnew System::Windows::Forms::Label());
			this->label5MinKdjD = (gcnew System::Windows::Forms::Label());
			this->label5MinKdjK = (gcnew System::Windows::Forms::Label());
			this->label5MinKdjDir = (gcnew System::Windows::Forms::Label());
			this->listBox5MinKdjDir = (gcnew System::Windows::Forms::ListBox());
			this->label5MinKdj = (gcnew System::Windows::Forms::Label());
			this->textBox5MinMacdDea = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinMacdDif = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinMacdMacd = (gcnew System::Windows::Forms::TextBox());
			this->label5MinMacdDea = (gcnew System::Windows::Forms::Label());
			this->label5MinMacdDif = (gcnew System::Windows::Forms::Label());
			this->label5MinMacdMacd = (gcnew System::Windows::Forms::Label());
			this->label5MinMacdDir = (gcnew System::Windows::Forms::Label());
			this->listBox5MinMacdDir = (gcnew System::Windows::Forms::ListBox());
			this->label5MinMacd = (gcnew System::Windows::Forms::Label());
			this->textBox5MinBollUpper = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinBollMid = (gcnew System::Windows::Forms::TextBox());
			this->textBox5MinBollLow = (gcnew System::Windows::Forms::TextBox());
			this->label5MinBollUpper = (gcnew System::Windows::Forms::Label());
			this->label5MinBollMid = (gcnew System::Windows::Forms::Label());
			this->label5MinBollLow = (gcnew System::Windows::Forms::Label());
			this->label5MinBollDir = (gcnew System::Windows::Forms::Label());
			this->listBox5MinBollDir = (gcnew System::Windows::Forms::ListBox());
			this->label5MinBoll = (gcnew System::Windows::Forms::Label());
			this->labelObject = (gcnew System::Windows::Forms::Label());
			this->textBoxObject = (gcnew System::Windows::Forms::TextBox());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->tab10Min->SuspendLayout();
			this->tab15Min->SuspendLayout();
			this->tab30Min->SuspendLayout();
			this->tab45Min->SuspendLayout();
			this->tabHour->SuspendLayout();
			this->tab4Hour->SuspendLayout();
			this->tabDay->SuspendLayout();
			this->tabWeek->SuspendLayout();
			this->tabMonth->SuspendLayout();
			this->tabYear->SuspendLayout();
			this->woperateParseTab->SuspendLayout();
			this->tab5Min->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->fileToolStripMenuItem, 
				this->parseToolStripMenuItem, this->settingToolStripMenuItem, this->helpToolStripMenuItem, this->donateToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(7, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1100, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->openToolStripMenuItem});
			this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 23);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(118, 24);
			this->openToolStripMenuItem->Text = L"Open";
			// 
			// parseToolStripMenuItem
			// 
			this->parseToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->parseToolStripMenuItem->Name = L"parseToolStripMenuItem";
			this->parseToolStripMenuItem->Size = System::Drawing::Size(60, 23);
			this->parseToolStripMenuItem->Text = L"Parse";
			// 
			// settingToolStripMenuItem
			// 
			this->settingToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->settingToolStripMenuItem->Name = L"settingToolStripMenuItem";
			this->settingToolStripMenuItem->Size = System::Drawing::Size(68, 23);
			this->settingToolStripMenuItem->Text = L"Setting";
			this->settingToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormParse::settingToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(53, 23);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// donateToolStripMenuItem
			// 
			this->donateToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->donateToolStripMenuItem->Name = L"donateToolStripMenuItem";
			this->donateToolStripMenuItem->Size = System::Drawing::Size(71, 23);
			this->donateToolStripMenuItem->Text = L"Donate";
			this->donateToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormParse::donateToolStripMenuItem_Click);
			// 
			// labelPrice
			// 
			this->labelPrice->AutoSize = true;
			this->labelPrice->Location = System::Drawing::Point(341, 43);
			this->labelPrice->Name = L"labelPrice";
			this->labelPrice->Size = System::Drawing::Size(49, 18);
			this->labelPrice->TabIndex = 2;
			this->labelPrice->Text = L"Price:";
			// 
			// textBoxPrice
			// 
			this->textBoxPrice->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxPrice->Location = System::Drawing::Point(410, 35);
			this->textBoxPrice->Name = L"textBoxPrice";
			this->textBoxPrice->Size = System::Drawing::Size(185, 26);
			this->textBoxPrice->TabIndex = 3;
			this->textBoxPrice->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxPrice_TextChanged);
			// 
			// tab10Min
			// 
			this->tab10Min->Controls->Add(this->listBox10MinMADir6);
			this->tab10Min->Controls->Add(this->label10MinMADir6);
			this->tab10Min->Controls->Add(this->textBox10MinMA6);
			this->tab10Min->Controls->Add(this->textBox10MinMA5);
			this->tab10Min->Controls->Add(this->label10MinMA6);
			this->tab10Min->Controls->Add(this->label10MinMA5);
			this->tab10Min->Controls->Add(this->label10MinMADir5);
			this->tab10Min->Controls->Add(this->listBox10MinMADir5);
			this->tab10Min->Controls->Add(this->label10MinMA56);
			this->tab10Min->Controls->Add(this->label10MinMADir4);
			this->tab10Min->Controls->Add(this->listBox10MinMADir4);
			this->tab10Min->Controls->Add(this->textBox10MinMA4);
			this->tab10Min->Controls->Add(this->textBox10MinMA3);
			this->tab10Min->Controls->Add(this->label10MinMA4);
			this->tab10Min->Controls->Add(this->label10MinMA3);
			this->tab10Min->Controls->Add(this->label10MinMADir3);
			this->tab10Min->Controls->Add(this->listBox10MinMADir3);
			this->tab10Min->Controls->Add(this->label10MinMA34);
			this->tab10Min->Controls->Add(this->label10MinMADir2);
			this->tab10Min->Controls->Add(this->listBox10MinMADir2);
			this->tab10Min->Controls->Add(this->textBox10MinMA2);
			this->tab10Min->Controls->Add(this->textBox10MinMA1);
			this->tab10Min->Controls->Add(this->label10MinMA2);
			this->tab10Min->Controls->Add(this->label10MinMA1);
			this->tab10Min->Controls->Add(this->label10MinMADir1);
			this->tab10Min->Controls->Add(this->listBox10MinMADir1);
			this->tab10Min->Controls->Add(this->label10MinMA12);
			this->tab10Min->Controls->Add(this->textBox10MinCciCci);
			this->tab10Min->Controls->Add(this->label10MinCciCci);
			this->tab10Min->Controls->Add(this->label10MinCciDir);
			this->tab10Min->Controls->Add(this->listBox10MinCciDir);
			this->tab10Min->Controls->Add(this->label10MinCci);
			this->tab10Min->Controls->Add(this->textBox10MinCrC);
			this->tab10Min->Controls->Add(this->label10MinCrC);
			this->tab10Min->Controls->Add(this->textBox10MinCrB);
			this->tab10Min->Controls->Add(this->label10MinCrB);
			this->tab10Min->Controls->Add(this->textBox10MinCrA);
			this->tab10Min->Controls->Add(this->textBox10MinCrCr);
			this->tab10Min->Controls->Add(this->label10MinCrA);
			this->tab10Min->Controls->Add(this->label10MinCrCr);
			this->tab10Min->Controls->Add(this->label10MinCrDir);
			this->tab10Min->Controls->Add(this->listBox10MinCrDir);
			this->tab10Min->Controls->Add(this->label10MinCr);
			this->tab10Min->Controls->Add(this->textBox10MinDmaAma);
			this->tab10Min->Controls->Add(this->textBox10MinDmaDma);
			this->tab10Min->Controls->Add(this->label10MinDmaAma);
			this->tab10Min->Controls->Add(this->label10MinDmaDma);
			this->tab10Min->Controls->Add(this->label10MinDmaDir);
			this->tab10Min->Controls->Add(this->listBox10MinDmaDir);
			this->tab10Min->Controls->Add(this->label10MinDma);
			this->tab10Min->Controls->Add(this->textBox10MinRocRocma);
			this->tab10Min->Controls->Add(this->textBox10MinRocRoc);
			this->tab10Min->Controls->Add(this->label10MinRocRocma);
			this->tab10Min->Controls->Add(this->label10MinRocRoc);
			this->tab10Min->Controls->Add(this->label10MinRocDir);
			this->tab10Min->Controls->Add(this->listBox10MinRocDir);
			this->tab10Min->Controls->Add(this->label10MinRoc);
			this->tab10Min->Controls->Add(this->textBox10MinVrLong);
			this->tab10Min->Controls->Add(this->textBox10MinVrShort);
			this->tab10Min->Controls->Add(this->label10MinVrLong);
			this->tab10Min->Controls->Add(this->label10MinVrShort);
			this->tab10Min->Controls->Add(this->label10MinVrDir);
			this->tab10Min->Controls->Add(this->listBox10MinVrDir);
			this->tab10Min->Controls->Add(this->label10MinVr);
			this->tab10Min->Controls->Add(this->label10MinVolDir2);
			this->tab10Min->Controls->Add(this->listBox10MinVolDir2);
			this->tab10Min->Controls->Add(this->textBox10MinVol2);
			this->tab10Min->Controls->Add(this->textBox10MinVol1);
			this->tab10Min->Controls->Add(this->label10MinVol2);
			this->tab10Min->Controls->Add(this->label10MinVol1);
			this->tab10Min->Controls->Add(this->label10MinVolDir1);
			this->tab10Min->Controls->Add(this->listBox10MinVolDir1);
			this->tab10Min->Controls->Add(this->label10MinVol);
			this->tab10Min->Controls->Add(this->textBox10MinWr2);
			this->tab10Min->Controls->Add(this->textBox10MinWr1);
			this->tab10Min->Controls->Add(this->label10MinWr2);
			this->tab10Min->Controls->Add(this->label10MinWr1);
			this->tab10Min->Controls->Add(this->label10MinWrDir);
			this->tab10Min->Controls->Add(this->listBox10MinWrDir);
			this->tab10Min->Controls->Add(this->label10MinWr);
			this->tab10Min->Controls->Add(this->textBox10MinRsiLong);
			this->tab10Min->Controls->Add(this->textBox10MinRsiMiddle);
			this->tab10Min->Controls->Add(this->textBox10MinRsiShort);
			this->tab10Min->Controls->Add(this->label10MinRsiLong);
			this->tab10Min->Controls->Add(this->label10MinRsiMiddle);
			this->tab10Min->Controls->Add(this->label10MinRsiShort);
			this->tab10Min->Controls->Add(this->label10MinRsiDir);
			this->tab10Min->Controls->Add(this->listBox10MinRsiDir);
			this->tab10Min->Controls->Add(this->label10MinRsi);
			this->tab10Min->Controls->Add(this->textBox10MinKdjJ);
			this->tab10Min->Controls->Add(this->textBox10MinKdjD);
			this->tab10Min->Controls->Add(this->textBox10MinKdjK);
			this->tab10Min->Controls->Add(this->label10MinKdjJ);
			this->tab10Min->Controls->Add(this->label10MinKdjD);
			this->tab10Min->Controls->Add(this->label10MinKdjK);
			this->tab10Min->Controls->Add(this->label10MinKdjDir);
			this->tab10Min->Controls->Add(this->listBox10MinKdjDir);
			this->tab10Min->Controls->Add(this->label10MinKdj);
			this->tab10Min->Controls->Add(this->textBox10MinMacdDea);
			this->tab10Min->Controls->Add(this->textBox10MinMacdDif);
			this->tab10Min->Controls->Add(this->textBox10MinMacdMacd);
			this->tab10Min->Controls->Add(this->label10MinMacdDea);
			this->tab10Min->Controls->Add(this->label10MinMacdDif);
			this->tab10Min->Controls->Add(this->label10MinMacdMacd);
			this->tab10Min->Controls->Add(this->label10MinMacdDir);
			this->tab10Min->Controls->Add(this->listBox10MinMacdDir);
			this->tab10Min->Controls->Add(this->label10MinMacd);
			this->tab10Min->Controls->Add(this->textBox10MinBollUpper);
			this->tab10Min->Controls->Add(this->textBox10MinBollMid);
			this->tab10Min->Controls->Add(this->textBox10MinBollLow);
			this->tab10Min->Controls->Add(this->label10MinBollUpper);
			this->tab10Min->Controls->Add(this->label10MinBollMid);
			this->tab10Min->Controls->Add(this->label10MinBollLow);
			this->tab10Min->Controls->Add(this->label10MinBollDir);
			this->tab10Min->Controls->Add(this->listBox10MinBollDir);
			this->tab10Min->Controls->Add(this->label10MinBoll);
			this->tab10Min->Location = System::Drawing::Point(4, 27);
			this->tab10Min->Name = L"tab10Min";
			this->tab10Min->Padding = System::Windows::Forms::Padding(3);
			this->tab10Min->Size = System::Drawing::Size(1092, 869);
			this->tab10Min->TabIndex = 11;
			this->tab10Min->Text = L"10Min";
			this->tab10Min->UseVisualStyleBackColor = true;
			// 
			// listBox10MinMADir6
			// 
			this->listBox10MinMADir6->FormattingEnabled = true;
			this->listBox10MinMADir6->ItemHeight = 18;
			this->listBox10MinMADir6->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinMADir6->Location = System::Drawing::Point(575, 103);
			this->listBox10MinMADir6->Name = L"listBox10MinMADir6";
			this->listBox10MinMADir6->Size = System::Drawing::Size(106, 22);
			this->listBox10MinMADir6->TabIndex = 269;
			this->listBox10MinMADir6->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinMADir6_SelectedIndexChanged);
			// 
			// label10MinMADir6
			// 
			this->label10MinMADir6->AutoSize = true;
			this->label10MinMADir6->Location = System::Drawing::Point(483, 107);
			this->label10MinMADir6->Name = L"label10MinMADir6";
			this->label10MinMADir6->Size = System::Drawing::Size(80, 18);
			this->label10MinMADir6->TabIndex = 268;
			this->label10MinMADir6->Text = L"MA_Dir6:";
			// 
			// textBox10MinMA6
			// 
			this->textBox10MinMA6->Location = System::Drawing::Point(759, 99);
			this->textBox10MinMA6->Name = L"textBox10MinMA6";
			this->textBox10MinMA6->Size = System::Drawing::Size(124, 26);
			this->textBox10MinMA6->TabIndex = 266;
			this->textBox10MinMA6->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinMA6_TextChanged);
			// 
			// textBox10MinMA5
			// 
			this->textBox10MinMA5->Location = System::Drawing::Point(353, 104);
			this->textBox10MinMA5->Name = L"textBox10MinMA5";
			this->textBox10MinMA5->Size = System::Drawing::Size(124, 26);
			this->textBox10MinMA5->TabIndex = 264;
			this->textBox10MinMA5->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinMA5_TextChanged);
			// 
			// label10MinMA6
			// 
			this->label10MinMA6->AutoSize = true;
			this->label10MinMA6->Location = System::Drawing::Point(695, 107);
			this->label10MinMA6->Name = L"label10MinMA6";
			this->label10MinMA6->Size = System::Drawing::Size(48, 18);
			this->label10MinMA6->TabIndex = 265;
			this->label10MinMA6->Text = L"MA6:";
			// 
			// label10MinMA5
			// 
			this->label10MinMA5->AutoSize = true;
			this->label10MinMA5->Location = System::Drawing::Point(290, 109);
			this->label10MinMA5->Name = L"label10MinMA5";
			this->label10MinMA5->Size = System::Drawing::Size(48, 18);
			this->label10MinMA5->TabIndex = 263;
			this->label10MinMA5->Text = L"MA5:";
			// 
			// label10MinMADir5
			// 
			this->label10MinMADir5->AutoSize = true;
			this->label10MinMADir5->Location = System::Drawing::Point(79, 112);
			this->label10MinMADir5->Name = L"label10MinMADir5";
			this->label10MinMADir5->Size = System::Drawing::Size(80, 18);
			this->label10MinMADir5->TabIndex = 262;
			this->label10MinMADir5->Text = L"MA_Dir5:";
			// 
			// listBox10MinMADir5
			// 
			this->listBox10MinMADir5->FormattingEnabled = true;
			this->listBox10MinMADir5->ItemHeight = 18;
			this->listBox10MinMADir5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinMADir5->Location = System::Drawing::Point(170, 107);
			this->listBox10MinMADir5->Name = L"listBox10MinMADir5";
			this->listBox10MinMADir5->Size = System::Drawing::Size(97, 22);
			this->listBox10MinMADir5->TabIndex = 261;
			this->listBox10MinMADir5->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinMADir5_SelectedIndexChanged);
			// 
			// label10MinMA56
			// 
			this->label10MinMA56->AutoSize = true;
			this->label10MinMA56->Location = System::Drawing::Point(17, 112);
			this->label10MinMA56->Name = L"label10MinMA56";
			this->label10MinMA56->Size = System::Drawing::Size(64, 18);
			this->label10MinMA56->TabIndex = 260;
			this->label10MinMA56->Text = L"MA5-6:";
			// 
			// label10MinMADir4
			// 
			this->label10MinMADir4->AutoSize = true;
			this->label10MinMADir4->Location = System::Drawing::Point(483, 60);
			this->label10MinMADir4->Name = L"label10MinMADir4";
			this->label10MinMADir4->Size = System::Drawing::Size(80, 18);
			this->label10MinMADir4->TabIndex = 259;
			this->label10MinMADir4->Text = L"MA_Dir4:";
			// 
			// listBox10MinMADir4
			// 
			this->listBox10MinMADir4->FormattingEnabled = true;
			this->listBox10MinMADir4->ItemHeight = 18;
			this->listBox10MinMADir4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinMADir4->Location = System::Drawing::Point(575, 57);
			this->listBox10MinMADir4->Name = L"listBox10MinMADir4";
			this->listBox10MinMADir4->Size = System::Drawing::Size(106, 22);
			this->listBox10MinMADir4->TabIndex = 258;
			this->listBox10MinMADir4->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinMADir4_SelectedIndexChanged);
			// 
			// textBox10MinMA4
			// 
			this->textBox10MinMA4->Location = System::Drawing::Point(759, 52);
			this->textBox10MinMA4->Name = L"textBox10MinMA4";
			this->textBox10MinMA4->Size = System::Drawing::Size(124, 26);
			this->textBox10MinMA4->TabIndex = 257;
			this->textBox10MinMA4->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinMA4_TextChanged);
			// 
			// textBox10MinMA3
			// 
			this->textBox10MinMA3->Location = System::Drawing::Point(353, 57);
			this->textBox10MinMA3->Name = L"textBox10MinMA3";
			this->textBox10MinMA3->Size = System::Drawing::Size(124, 26);
			this->textBox10MinMA3->TabIndex = 255;
			this->textBox10MinMA3->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinMA3_TextChanged);
			// 
			// label10MinMA4
			// 
			this->label10MinMA4->AutoSize = true;
			this->label10MinMA4->Location = System::Drawing::Point(695, 60);
			this->label10MinMA4->Name = L"label10MinMA4";
			this->label10MinMA4->Size = System::Drawing::Size(48, 18);
			this->label10MinMA4->TabIndex = 256;
			this->label10MinMA4->Text = L"MA4:";
			// 
			// label10MinMA3
			// 
			this->label10MinMA3->AutoSize = true;
			this->label10MinMA3->Location = System::Drawing::Point(290, 62);
			this->label10MinMA3->Name = L"label10MinMA3";
			this->label10MinMA3->Size = System::Drawing::Size(48, 18);
			this->label10MinMA3->TabIndex = 254;
			this->label10MinMA3->Text = L"MA3:";
			// 
			// label10MinMADir3
			// 
			this->label10MinMADir3->AutoSize = true;
			this->label10MinMADir3->Location = System::Drawing::Point(79, 65);
			this->label10MinMADir3->Name = L"label10MinMADir3";
			this->label10MinMADir3->Size = System::Drawing::Size(80, 18);
			this->label10MinMADir3->TabIndex = 253;
			this->label10MinMADir3->Text = L"MA_Dir3:";
			// 
			// listBox10MinMADir3
			// 
			this->listBox10MinMADir3->FormattingEnabled = true;
			this->listBox10MinMADir3->ItemHeight = 18;
			this->listBox10MinMADir3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinMADir3->Location = System::Drawing::Point(170, 60);
			this->listBox10MinMADir3->Name = L"listBox10MinMADir3";
			this->listBox10MinMADir3->Size = System::Drawing::Size(97, 22);
			this->listBox10MinMADir3->TabIndex = 252;
			this->listBox10MinMADir3->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinMADir3_SelectedIndexChanged);
			// 
			// label10MinMA34
			// 
			this->label10MinMA34->AutoSize = true;
			this->label10MinMA34->Location = System::Drawing::Point(17, 65);
			this->label10MinMA34->Name = L"label10MinMA34";
			this->label10MinMA34->Size = System::Drawing::Size(64, 18);
			this->label10MinMA34->TabIndex = 251;
			this->label10MinMA34->Text = L"MA3-4:";
			// 
			// label10MinMADir2
			// 
			this->label10MinMADir2->AutoSize = true;
			this->label10MinMADir2->Location = System::Drawing::Point(483, 19);
			this->label10MinMADir2->Name = L"label10MinMADir2";
			this->label10MinMADir2->Size = System::Drawing::Size(80, 18);
			this->label10MinMADir2->TabIndex = 250;
			this->label10MinMADir2->Text = L"MA_Dir2:";
			// 
			// listBox10MinMADir2
			// 
			this->listBox10MinMADir2->FormattingEnabled = true;
			this->listBox10MinMADir2->ItemHeight = 18;
			this->listBox10MinMADir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinMADir2->Location = System::Drawing::Point(575, 16);
			this->listBox10MinMADir2->Name = L"listBox10MinMADir2";
			this->listBox10MinMADir2->Size = System::Drawing::Size(106, 22);
			this->listBox10MinMADir2->TabIndex = 249;
			this->listBox10MinMADir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinMADir2_SelectedIndexChanged);
			// 
			// textBox10MinMA2
			// 
			this->textBox10MinMA2->Location = System::Drawing::Point(759, 11);
			this->textBox10MinMA2->Name = L"textBox10MinMA2";
			this->textBox10MinMA2->Size = System::Drawing::Size(124, 26);
			this->textBox10MinMA2->TabIndex = 248;
			this->textBox10MinMA2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinMA2_TextChanged);
			// 
			// textBox10MinMA1
			// 
			this->textBox10MinMA1->Location = System::Drawing::Point(353, 16);
			this->textBox10MinMA1->Name = L"textBox10MinMA1";
			this->textBox10MinMA1->Size = System::Drawing::Size(124, 26);
			this->textBox10MinMA1->TabIndex = 246;
			this->textBox10MinMA1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinMA1_TextChanged);
			// 
			// label10MinMA2
			// 
			this->label10MinMA2->AutoSize = true;
			this->label10MinMA2->Location = System::Drawing::Point(695, 19);
			this->label10MinMA2->Name = L"label10MinMA2";
			this->label10MinMA2->Size = System::Drawing::Size(48, 18);
			this->label10MinMA2->TabIndex = 247;
			this->label10MinMA2->Text = L"MA2:";
			// 
			// label10MinMA1
			// 
			this->label10MinMA1->AutoSize = true;
			this->label10MinMA1->Location = System::Drawing::Point(290, 21);
			this->label10MinMA1->Name = L"label10MinMA1";
			this->label10MinMA1->Size = System::Drawing::Size(47, 18);
			this->label10MinMA1->TabIndex = 245;
			this->label10MinMA1->Text = L"MA1:";
			// 
			// label10MinMADir1
			// 
			this->label10MinMADir1->AutoSize = true;
			this->label10MinMADir1->Location = System::Drawing::Point(79, 21);
			this->label10MinMADir1->Name = L"label10MinMADir1";
			this->label10MinMADir1->Size = System::Drawing::Size(79, 18);
			this->label10MinMADir1->TabIndex = 244;
			this->label10MinMADir1->Text = L"MA_Dir1:";
			// 
			// listBox10MinMADir1
			// 
			this->listBox10MinMADir1->FormattingEnabled = true;
			this->listBox10MinMADir1->ItemHeight = 18;
			this->listBox10MinMADir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinMADir1->Location = System::Drawing::Point(170, 19);
			this->listBox10MinMADir1->Name = L"listBox10MinMADir1";
			this->listBox10MinMADir1->Size = System::Drawing::Size(97, 22);
			this->listBox10MinMADir1->TabIndex = 243;
			this->listBox10MinMADir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinMADir1_SelectedIndexChanged);
			// 
			// label10MinMA12
			// 
			this->label10MinMA12->AutoSize = true;
			this->label10MinMA12->Location = System::Drawing::Point(16, 24);
			this->label10MinMA12->Name = L"label10MinMA12";
			this->label10MinMA12->Size = System::Drawing::Size(63, 18);
			this->label10MinMA12->TabIndex = 242;
			this->label10MinMA12->Text = L"MA1-2:";
			// 
			// textBox10MinCciCci
			// 
			this->textBox10MinCciCci->Location = System::Drawing::Point(353, 601);
			this->textBox10MinCciCci->Name = L"textBox10MinCciCci";
			this->textBox10MinCciCci->Size = System::Drawing::Size(124, 26);
			this->textBox10MinCciCci->TabIndex = 241;
			this->textBox10MinCciCci->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinCciCci_TextChanged);
			// 
			// label10MinCciCci
			// 
			this->label10MinCciCci->AutoSize = true;
			this->label10MinCciCci->Location = System::Drawing::Point(286, 608);
			this->label10MinCciCci->Name = L"label10MinCciCci";
			this->label10MinCciCci->Size = System::Drawing::Size(34, 18);
			this->label10MinCciCci->TabIndex = 240;
			this->label10MinCciCci->Text = L"Cci:";
			// 
			// label10MinCciDir
			// 
			this->label10MinCciDir->AutoSize = true;
			this->label10MinCciDir->Location = System::Drawing::Point(87, 608);
			this->label10MinCciDir->Name = L"label10MinCciDir";
			this->label10MinCciDir->Size = System::Drawing::Size(77, 18);
			this->label10MinCciDir->TabIndex = 239;
			this->label10MinCciDir->Text = L"Direction:";
			// 
			// listBox10MinCciDir
			// 
			this->listBox10MinCciDir->FormattingEnabled = true;
			this->listBox10MinCciDir->ItemHeight = 18;
			this->listBox10MinCciDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinCciDir->Location = System::Drawing::Point(170, 604);
			this->listBox10MinCciDir->Name = L"listBox10MinCciDir";
			this->listBox10MinCciDir->Size = System::Drawing::Size(97, 22);
			this->listBox10MinCciDir->TabIndex = 238;
			this->listBox10MinCciDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinCciDir_SelectedIndexChanged);
			// 
			// label10MinCci
			// 
			this->label10MinCci->AutoSize = true;
			this->label10MinCci->Location = System::Drawing::Point(26, 608);
			this->label10MinCci->Name = L"label10MinCci";
			this->label10MinCci->Size = System::Drawing::Size(40, 18);
			this->label10MinCci->TabIndex = 237;
			this->label10MinCci->Text = L"CCI:";
			// 
			// textBox10MinCrC
			// 
			this->textBox10MinCrC->Location = System::Drawing::Point(961, 555);
			this->textBox10MinCrC->Name = L"textBox10MinCrC";
			this->textBox10MinCrC->Size = System::Drawing::Size(124, 26);
			this->textBox10MinCrC->TabIndex = 236;
			this->textBox10MinCrC->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinCrC_TextChanged);
			// 
			// label10MinCrC
			// 
			this->label10MinCrC->AutoSize = true;
			this->label10MinCrC->Location = System::Drawing::Point(900, 563);
			this->label10MinCrC->Name = L"label10MinCrC";
			this->label10MinCrC->Size = System::Drawing::Size(23, 18);
			this->label10MinCrC->TabIndex = 235;
			this->label10MinCrC->Text = L"C:";
			// 
			// textBox10MinCrB
			// 
			this->textBox10MinCrB->Location = System::Drawing::Point(755, 555);
			this->textBox10MinCrB->Name = L"textBox10MinCrB";
			this->textBox10MinCrB->Size = System::Drawing::Size(124, 26);
			this->textBox10MinCrB->TabIndex = 234;
			this->textBox10MinCrB->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinCrB_TextChanged);
			// 
			// label10MinCrB
			// 
			this->label10MinCrB->AutoSize = true;
			this->label10MinCrB->Location = System::Drawing::Point(694, 563);
			this->label10MinCrB->Name = L"label10MinCrB";
			this->label10MinCrB->Size = System::Drawing::Size(23, 18);
			this->label10MinCrB->TabIndex = 233;
			this->label10MinCrB->Text = L"B:";
			// 
			// textBox10MinCrA
			// 
			this->textBox10MinCrA->Location = System::Drawing::Point(557, 555);
			this->textBox10MinCrA->Name = L"textBox10MinCrA";
			this->textBox10MinCrA->Size = System::Drawing::Size(124, 26);
			this->textBox10MinCrA->TabIndex = 232;
			this->textBox10MinCrA->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinCrA_TextChanged);
			// 
			// textBox10MinCrCr
			// 
			this->textBox10MinCrCr->Location = System::Drawing::Point(353, 560);
			this->textBox10MinCrCr->Name = L"textBox10MinCrCr";
			this->textBox10MinCrCr->Size = System::Drawing::Size(124, 26);
			this->textBox10MinCrCr->TabIndex = 230;
			this->textBox10MinCrCr->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinCrCr_TextChanged);
			// 
			// label10MinCrA
			// 
			this->label10MinCrA->AutoSize = true;
			this->label10MinCrA->Location = System::Drawing::Point(496, 563);
			this->label10MinCrA->Name = L"label10MinCrA";
			this->label10MinCrA->Size = System::Drawing::Size(24, 18);
			this->label10MinCrA->TabIndex = 231;
			this->label10MinCrA->Text = L"A:";
			// 
			// label10MinCrCr
			// 
			this->label10MinCrCr->AutoSize = true;
			this->label10MinCrCr->Location = System::Drawing::Point(286, 567);
			this->label10MinCrCr->Name = L"label10MinCrCr";
			this->label10MinCrCr->Size = System::Drawing::Size(30, 18);
			this->label10MinCrCr->TabIndex = 229;
			this->label10MinCrCr->Text = L"Cr:";
			// 
			// label10MinCrDir
			// 
			this->label10MinCrDir->AutoSize = true;
			this->label10MinCrDir->Location = System::Drawing::Point(87, 567);
			this->label10MinCrDir->Name = L"label10MinCrDir";
			this->label10MinCrDir->Size = System::Drawing::Size(77, 18);
			this->label10MinCrDir->TabIndex = 228;
			this->label10MinCrDir->Text = L"Direction:";
			// 
			// listBox10MinCrDir
			// 
			this->listBox10MinCrDir->FormattingEnabled = true;
			this->listBox10MinCrDir->ItemHeight = 18;
			this->listBox10MinCrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinCrDir->Location = System::Drawing::Point(170, 563);
			this->listBox10MinCrDir->Name = L"listBox10MinCrDir";
			this->listBox10MinCrDir->Size = System::Drawing::Size(97, 22);
			this->listBox10MinCrDir->TabIndex = 227;
			this->listBox10MinCrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinCrDir_SelectedIndexChanged);
			// 
			// label10MinCr
			// 
			this->label10MinCr->AutoSize = true;
			this->label10MinCr->Location = System::Drawing::Point(26, 567);
			this->label10MinCr->Name = L"label10MinCr";
			this->label10MinCr->Size = System::Drawing::Size(34, 18);
			this->label10MinCr->TabIndex = 226;
			this->label10MinCr->Text = L"CR:";
			// 
			// textBox10MinDmaAma
			// 
			this->textBox10MinDmaAma->Location = System::Drawing::Point(557, 513);
			this->textBox10MinDmaAma->Name = L"textBox10MinDmaAma";
			this->textBox10MinDmaAma->Size = System::Drawing::Size(124, 26);
			this->textBox10MinDmaAma->TabIndex = 225;
			this->textBox10MinDmaAma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinDmaAma_TextChanged);
			// 
			// textBox10MinDmaDma
			// 
			this->textBox10MinDmaDma->Location = System::Drawing::Point(353, 518);
			this->textBox10MinDmaDma->Name = L"textBox10MinDmaDma";
			this->textBox10MinDmaDma->Size = System::Drawing::Size(124, 26);
			this->textBox10MinDmaDma->TabIndex = 223;
			this->textBox10MinDmaDma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinDmaDma_TextChanged);
			// 
			// label10MinDmaAma
			// 
			this->label10MinDmaAma->AutoSize = true;
			this->label10MinDmaAma->Location = System::Drawing::Point(483, 521);
			this->label10MinDmaAma->Name = L"label10MinDmaAma";
			this->label10MinDmaAma->Size = System::Drawing::Size(46, 18);
			this->label10MinDmaAma->TabIndex = 224;
			this->label10MinDmaAma->Text = L"Ama:";
			// 
			// label10MinDmaDma
			// 
			this->label10MinDmaDma->AutoSize = true;
			this->label10MinDmaDma->Location = System::Drawing::Point(286, 525);
			this->label10MinDmaDma->Name = L"label10MinDmaDma";
			this->label10MinDmaDma->Size = System::Drawing::Size(46, 18);
			this->label10MinDmaDma->TabIndex = 222;
			this->label10MinDmaDma->Text = L"Dma:";
			// 
			// label10MinDmaDir
			// 
			this->label10MinDmaDir->AutoSize = true;
			this->label10MinDmaDir->Location = System::Drawing::Point(87, 525);
			this->label10MinDmaDir->Name = L"label10MinDmaDir";
			this->label10MinDmaDir->Size = System::Drawing::Size(77, 18);
			this->label10MinDmaDir->TabIndex = 221;
			this->label10MinDmaDir->Text = L"Direction:";
			// 
			// listBox10MinDmaDir
			// 
			this->listBox10MinDmaDir->FormattingEnabled = true;
			this->listBox10MinDmaDir->ItemHeight = 18;
			this->listBox10MinDmaDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinDmaDir->Location = System::Drawing::Point(170, 521);
			this->listBox10MinDmaDir->Name = L"listBox10MinDmaDir";
			this->listBox10MinDmaDir->Size = System::Drawing::Size(97, 22);
			this->listBox10MinDmaDir->TabIndex = 220;
			this->listBox10MinDmaDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinDmaDir_SelectedIndexChanged);
			// 
			// label10MinDma
			// 
			this->label10MinDma->AutoSize = true;
			this->label10MinDma->Location = System::Drawing::Point(26, 525);
			this->label10MinDma->Name = L"label10MinDma";
			this->label10MinDma->Size = System::Drawing::Size(50, 18);
			this->label10MinDma->TabIndex = 219;
			this->label10MinDma->Text = L"DMA:";
			// 
			// textBox10MinRocRocma
			// 
			this->textBox10MinRocRocma->Location = System::Drawing::Point(557, 427);
			this->textBox10MinRocRocma->Name = L"textBox10MinRocRocma";
			this->textBox10MinRocRocma->Size = System::Drawing::Size(124, 26);
			this->textBox10MinRocRocma->TabIndex = 218;
			this->textBox10MinRocRocma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinRocRocma_TextChanged);
			// 
			// textBox10MinRocRoc
			// 
			this->textBox10MinRocRoc->Location = System::Drawing::Point(353, 432);
			this->textBox10MinRocRoc->Name = L"textBox10MinRocRoc";
			this->textBox10MinRocRoc->Size = System::Drawing::Size(124, 26);
			this->textBox10MinRocRoc->TabIndex = 216;
			this->textBox10MinRocRoc->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinRocRoc_TextChanged);
			// 
			// label10MinRocRocma
			// 
			this->label10MinRocRocma->AutoSize = true;
			this->label10MinRocRocma->Location = System::Drawing::Point(483, 435);
			this->label10MinRocRocma->Name = L"label10MinRocRocma";
			this->label10MinRocRocma->Size = System::Drawing::Size(71, 18);
			this->label10MinRocRocma->TabIndex = 217;
			this->label10MinRocRocma->Text = L"Roc_ma:";
			// 
			// label10MinRocRoc
			// 
			this->label10MinRocRoc->AutoSize = true;
			this->label10MinRocRoc->Location = System::Drawing::Point(286, 439);
			this->label10MinRocRoc->Name = L"label10MinRocRoc";
			this->label10MinRocRoc->Size = System::Drawing::Size(39, 18);
			this->label10MinRocRoc->TabIndex = 215;
			this->label10MinRocRoc->Text = L"Roc:";
			// 
			// label10MinRocDir
			// 
			this->label10MinRocDir->AutoSize = true;
			this->label10MinRocDir->Location = System::Drawing::Point(87, 439);
			this->label10MinRocDir->Name = L"label10MinRocDir";
			this->label10MinRocDir->Size = System::Drawing::Size(77, 18);
			this->label10MinRocDir->TabIndex = 214;
			this->label10MinRocDir->Text = L"Direction:";
			// 
			// listBox10MinRocDir
			// 
			this->listBox10MinRocDir->FormattingEnabled = true;
			this->listBox10MinRocDir->ItemHeight = 18;
			this->listBox10MinRocDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinRocDir->Location = System::Drawing::Point(170, 435);
			this->listBox10MinRocDir->Name = L"listBox10MinRocDir";
			this->listBox10MinRocDir->Size = System::Drawing::Size(97, 22);
			this->listBox10MinRocDir->TabIndex = 213;
			this->listBox10MinRocDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinRocDir_SelectedIndexChanged);
			// 
			// label10MinRoc
			// 
			this->label10MinRoc->AutoSize = true;
			this->label10MinRoc->Location = System::Drawing::Point(26, 439);
			this->label10MinRoc->Name = L"label10MinRoc";
			this->label10MinRoc->Size = System::Drawing::Size(46, 18);
			this->label10MinRoc->TabIndex = 212;
			this->label10MinRoc->Text = L"ROC:";
			// 
			// textBox10MinVrLong
			// 
			this->textBox10MinVrLong->Location = System::Drawing::Point(557, 470);
			this->textBox10MinVrLong->Name = L"textBox10MinVrLong";
			this->textBox10MinVrLong->Size = System::Drawing::Size(124, 26);
			this->textBox10MinVrLong->TabIndex = 211;
			this->textBox10MinVrLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinVrLong_TextChanged);
			// 
			// textBox10MinVrShort
			// 
			this->textBox10MinVrShort->Location = System::Drawing::Point(353, 475);
			this->textBox10MinVrShort->Name = L"textBox10MinVrShort";
			this->textBox10MinVrShort->Size = System::Drawing::Size(124, 26);
			this->textBox10MinVrShort->TabIndex = 209;
			this->textBox10MinVrShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinVrShort_TextChanged);
			// 
			// label10MinVrLong
			// 
			this->label10MinVrLong->AutoSize = true;
			this->label10MinVrLong->Location = System::Drawing::Point(483, 478);
			this->label10MinVrLong->Name = L"label10MinVrLong";
			this->label10MinVrLong->Size = System::Drawing::Size(48, 18);
			this->label10MinVrLong->TabIndex = 210;
			this->label10MinVrLong->Text = L"Long:";
			// 
			// label10MinVrShort
			// 
			this->label10MinVrShort->AutoSize = true;
			this->label10MinVrShort->Location = System::Drawing::Point(281, 483);
			this->label10MinVrShort->Name = L"label10MinVrShort";
			this->label10MinVrShort->Size = System::Drawing::Size(52, 18);
			this->label10MinVrShort->TabIndex = 208;
			this->label10MinVrShort->Text = L"Short:";
			// 
			// label10MinVrDir
			// 
			this->label10MinVrDir->AutoSize = true;
			this->label10MinVrDir->Location = System::Drawing::Point(87, 482);
			this->label10MinVrDir->Name = L"label10MinVrDir";
			this->label10MinVrDir->Size = System::Drawing::Size(77, 18);
			this->label10MinVrDir->TabIndex = 207;
			this->label10MinVrDir->Text = L"Direction:";
			// 
			// listBox10MinVrDir
			// 
			this->listBox10MinVrDir->FormattingEnabled = true;
			this->listBox10MinVrDir->ItemHeight = 18;
			this->listBox10MinVrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinVrDir->Location = System::Drawing::Point(170, 478);
			this->listBox10MinVrDir->Name = L"listBox10MinVrDir";
			this->listBox10MinVrDir->Size = System::Drawing::Size(97, 22);
			this->listBox10MinVrDir->TabIndex = 206;
			this->listBox10MinVrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinVrDir_SelectedIndexChanged);
			// 
			// label10MinVr
			// 
			this->label10MinVr->AutoSize = true;
			this->label10MinVr->Location = System::Drawing::Point(26, 482);
			this->label10MinVr->Name = L"label10MinVr";
			this->label10MinVr->Size = System::Drawing::Size(35, 18);
			this->label10MinVr->TabIndex = 205;
			this->label10MinVr->Text = L"VR:";
			// 
			// label10MinVolDir2
			// 
			this->label10MinVolDir2->AutoSize = true;
			this->label10MinVolDir2->Location = System::Drawing::Point(483, 154);
			this->label10MinVolDir2->Name = L"label10MinVolDir2";
			this->label10MinVolDir2->Size = System::Drawing::Size(86, 18);
			this->label10MinVolDir2->TabIndex = 204;
			this->label10MinVolDir2->Text = L"Direction2:";
			// 
			// listBox10MinVolDir2
			// 
			this->listBox10MinVolDir2->FormattingEnabled = true;
			this->listBox10MinVolDir2->ItemHeight = 18;
			this->listBox10MinVolDir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinVolDir2->Location = System::Drawing::Point(575, 151);
			this->listBox10MinVolDir2->Name = L"listBox10MinVolDir2";
			this->listBox10MinVolDir2->Size = System::Drawing::Size(106, 22);
			this->listBox10MinVolDir2->TabIndex = 203;
			this->listBox10MinVolDir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinVolDir2_SelectedIndexChanged);
			// 
			// textBox10MinVol2
			// 
			this->textBox10MinVol2->Location = System::Drawing::Point(759, 146);
			this->textBox10MinVol2->Name = L"textBox10MinVol2";
			this->textBox10MinVol2->Size = System::Drawing::Size(124, 26);
			this->textBox10MinVol2->TabIndex = 202;
			this->textBox10MinVol2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinVol2_TextChanged);
			// 
			// textBox10MinVol1
			// 
			this->textBox10MinVol1->Location = System::Drawing::Point(353, 151);
			this->textBox10MinVol1->Name = L"textBox10MinVol1";
			this->textBox10MinVol1->Size = System::Drawing::Size(124, 26);
			this->textBox10MinVol1->TabIndex = 200;
			this->textBox10MinVol1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinVol1_TextChanged);
			// 
			// label10MinVol2
			// 
			this->label10MinVol2->AutoSize = true;
			this->label10MinVol2->Location = System::Drawing::Point(695, 154);
			this->label10MinVol2->Name = L"label10MinVol2";
			this->label10MinVol2->Size = System::Drawing::Size(55, 18);
			this->label10MinVol2->TabIndex = 201;
			this->label10MinVol2->Text = L"VOL2:";
			// 
			// label10MinVol1
			// 
			this->label10MinVol1->AutoSize = true;
			this->label10MinVol1->Location = System::Drawing::Point(290, 156);
			this->label10MinVol1->Name = L"label10MinVol1";
			this->label10MinVol1->Size = System::Drawing::Size(54, 18);
			this->label10MinVol1->TabIndex = 199;
			this->label10MinVol1->Text = L"VOL1:";
			// 
			// label10MinVolDir1
			// 
			this->label10MinVolDir1->AutoSize = true;
			this->label10MinVolDir1->Location = System::Drawing::Point(79, 156);
			this->label10MinVolDir1->Name = L"label10MinVolDir1";
			this->label10MinVolDir1->Size = System::Drawing::Size(85, 18);
			this->label10MinVolDir1->TabIndex = 198;
			this->label10MinVolDir1->Text = L"Direction1:";
			// 
			// listBox10MinVolDir1
			// 
			this->listBox10MinVolDir1->FormattingEnabled = true;
			this->listBox10MinVolDir1->ItemHeight = 18;
			this->listBox10MinVolDir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinVolDir1->Location = System::Drawing::Point(170, 154);
			this->listBox10MinVolDir1->Name = L"listBox10MinVolDir1";
			this->listBox10MinVolDir1->Size = System::Drawing::Size(97, 22);
			this->listBox10MinVolDir1->TabIndex = 197;
			this->listBox10MinVolDir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinVolDir1_SelectedIndexChanged);
			// 
			// label10MinVol
			// 
			this->label10MinVol->AutoSize = true;
			this->label10MinVol->Location = System::Drawing::Point(26, 158);
			this->label10MinVol->Name = L"label10MinVol";
			this->label10MinVol->Size = System::Drawing::Size(46, 18);
			this->label10MinVol->TabIndex = 196;
			this->label10MinVol->Text = L"VOL:";
			// 
			// textBox10MinWr2
			// 
			this->textBox10MinWr2->Location = System::Drawing::Point(557, 382);
			this->textBox10MinWr2->Name = L"textBox10MinWr2";
			this->textBox10MinWr2->Size = System::Drawing::Size(124, 26);
			this->textBox10MinWr2->TabIndex = 195;
			this->textBox10MinWr2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinWr2_TextChanged);
			// 
			// textBox10MinWr1
			// 
			this->textBox10MinWr1->Location = System::Drawing::Point(353, 387);
			this->textBox10MinWr1->Name = L"textBox10MinWr1";
			this->textBox10MinWr1->Size = System::Drawing::Size(124, 26);
			this->textBox10MinWr1->TabIndex = 193;
			this->textBox10MinWr1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinWr1_TextChanged);
			// 
			// label10MinWr2
			// 
			this->label10MinWr2->AutoSize = true;
			this->label10MinWr2->Location = System::Drawing::Point(483, 390);
			this->label10MinWr2->Name = L"label10MinWr2";
			this->label10MinWr2->Size = System::Drawing::Size(48, 18);
			this->label10MinWr2->TabIndex = 194;
			this->label10MinWr2->Text = L"WR2:";
			// 
			// label10MinWr1
			// 
			this->label10MinWr1->AutoSize = true;
			this->label10MinWr1->Location = System::Drawing::Point(286, 394);
			this->label10MinWr1->Name = L"label10MinWr1";
			this->label10MinWr1->Size = System::Drawing::Size(47, 18);
			this->label10MinWr1->TabIndex = 192;
			this->label10MinWr1->Text = L"WR1:";
			// 
			// label10MinWrDir
			// 
			this->label10MinWrDir->AutoSize = true;
			this->label10MinWrDir->Location = System::Drawing::Point(87, 394);
			this->label10MinWrDir->Name = L"label10MinWrDir";
			this->label10MinWrDir->Size = System::Drawing::Size(77, 18);
			this->label10MinWrDir->TabIndex = 191;
			this->label10MinWrDir->Text = L"Direction:";
			// 
			// listBox10MinWrDir
			// 
			this->listBox10MinWrDir->FormattingEnabled = true;
			this->listBox10MinWrDir->ItemHeight = 18;
			this->listBox10MinWrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinWrDir->Location = System::Drawing::Point(170, 390);
			this->listBox10MinWrDir->Name = L"listBox10MinWrDir";
			this->listBox10MinWrDir->Size = System::Drawing::Size(97, 22);
			this->listBox10MinWrDir->TabIndex = 190;
			this->listBox10MinWrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinWrDir_SelectedIndexChanged);
			// 
			// label10MinWr
			// 
			this->label10MinWr->AutoSize = true;
			this->label10MinWr->Location = System::Drawing::Point(26, 394);
			this->label10MinWr->Name = L"label10MinWr";
			this->label10MinWr->Size = System::Drawing::Size(39, 18);
			this->label10MinWr->TabIndex = 189;
			this->label10MinWr->Text = L"WR:";
			// 
			// textBox10MinRsiLong
			// 
			this->textBox10MinRsiLong->Location = System::Drawing::Point(759, 335);
			this->textBox10MinRsiLong->Name = L"textBox10MinRsiLong";
			this->textBox10MinRsiLong->Size = System::Drawing::Size(124, 26);
			this->textBox10MinRsiLong->TabIndex = 188;
			this->textBox10MinRsiLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinRsiLong_TextChanged);
			// 
			// textBox10MinRsiMiddle
			// 
			this->textBox10MinRsiMiddle->Location = System::Drawing::Point(557, 335);
			this->textBox10MinRsiMiddle->Name = L"textBox10MinRsiMiddle";
			this->textBox10MinRsiMiddle->Size = System::Drawing::Size(124, 26);
			this->textBox10MinRsiMiddle->TabIndex = 186;
			this->textBox10MinRsiMiddle->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinRsiMiddle_TextChanged);
			// 
			// textBox10MinRsiShort
			// 
			this->textBox10MinRsiShort->Location = System::Drawing::Point(353, 340);
			this->textBox10MinRsiShort->Name = L"textBox10MinRsiShort";
			this->textBox10MinRsiShort->Size = System::Drawing::Size(124, 26);
			this->textBox10MinRsiShort->TabIndex = 184;
			this->textBox10MinRsiShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinRsiShort_TextChanged);
			// 
			// label10MinRsiLong
			// 
			this->label10MinRsiLong->AutoSize = true;
			this->label10MinRsiLong->Location = System::Drawing::Point(695, 340);
			this->label10MinRsiLong->Name = L"label10MinRsiLong";
			this->label10MinRsiLong->Size = System::Drawing::Size(48, 18);
			this->label10MinRsiLong->TabIndex = 187;
			this->label10MinRsiLong->Text = L"Long:";
			// 
			// label10MinRsiMiddle
			// 
			this->label10MinRsiMiddle->AutoSize = true;
			this->label10MinRsiMiddle->Location = System::Drawing::Point(483, 343);
			this->label10MinRsiMiddle->Name = L"label10MinRsiMiddle";
			this->label10MinRsiMiddle->Size = System::Drawing::Size(62, 18);
			this->label10MinRsiMiddle->TabIndex = 185;
			this->label10MinRsiMiddle->Text = L"Middle:";
			// 
			// label10MinRsiShort
			// 
			this->label10MinRsiShort->AutoSize = true;
			this->label10MinRsiShort->Location = System::Drawing::Point(286, 347);
			this->label10MinRsiShort->Name = L"label10MinRsiShort";
			this->label10MinRsiShort->Size = System::Drawing::Size(52, 18);
			this->label10MinRsiShort->TabIndex = 183;
			this->label10MinRsiShort->Text = L"Short:";
			// 
			// label10MinRsiDir
			// 
			this->label10MinRsiDir->AutoSize = true;
			this->label10MinRsiDir->Location = System::Drawing::Point(87, 347);
			this->label10MinRsiDir->Name = L"label10MinRsiDir";
			this->label10MinRsiDir->Size = System::Drawing::Size(77, 18);
			this->label10MinRsiDir->TabIndex = 182;
			this->label10MinRsiDir->Text = L"Direction:";
			// 
			// listBox10MinRsiDir
			// 
			this->listBox10MinRsiDir->FormattingEnabled = true;
			this->listBox10MinRsiDir->ItemHeight = 18;
			this->listBox10MinRsiDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinRsiDir->Location = System::Drawing::Point(170, 343);
			this->listBox10MinRsiDir->Name = L"listBox10MinRsiDir";
			this->listBox10MinRsiDir->Size = System::Drawing::Size(97, 22);
			this->listBox10MinRsiDir->TabIndex = 181;
			this->listBox10MinRsiDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinRsiDir_SelectedIndexChanged);
			// 
			// label10MinRsi
			// 
			this->label10MinRsi->AutoSize = true;
			this->label10MinRsi->Location = System::Drawing::Point(26, 347);
			this->label10MinRsi->Name = L"label10MinRsi";
			this->label10MinRsi->Size = System::Drawing::Size(40, 18);
			this->label10MinRsi->TabIndex = 180;
			this->label10MinRsi->Text = L"RSI:";
			// 
			// textBox10MinKdjJ
			// 
			this->textBox10MinKdjJ->Location = System::Drawing::Point(759, 290);
			this->textBox10MinKdjJ->Name = L"textBox10MinKdjJ";
			this->textBox10MinKdjJ->Size = System::Drawing::Size(124, 26);
			this->textBox10MinKdjJ->TabIndex = 179;
			this->textBox10MinKdjJ->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinKdjJ_TextChanged);
			// 
			// textBox10MinKdjD
			// 
			this->textBox10MinKdjD->Location = System::Drawing::Point(557, 290);
			this->textBox10MinKdjD->Name = L"textBox10MinKdjD";
			this->textBox10MinKdjD->Size = System::Drawing::Size(124, 26);
			this->textBox10MinKdjD->TabIndex = 177;
			this->textBox10MinKdjD->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinKdjD_TextChanged);
			// 
			// textBox10MinKdjK
			// 
			this->textBox10MinKdjK->Location = System::Drawing::Point(353, 295);
			this->textBox10MinKdjK->Name = L"textBox10MinKdjK";
			this->textBox10MinKdjK->Size = System::Drawing::Size(124, 26);
			this->textBox10MinKdjK->TabIndex = 175;
			this->textBox10MinKdjK->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinKdjK_TextChanged);
			// 
			// label10MinKdjJ
			// 
			this->label10MinKdjJ->AutoSize = true;
			this->label10MinKdjJ->Location = System::Drawing::Point(695, 298);
			this->label10MinKdjJ->Name = L"label10MinKdjJ";
			this->label10MinKdjJ->Size = System::Drawing::Size(21, 18);
			this->label10MinKdjJ->TabIndex = 178;
			this->label10MinKdjJ->Text = L"J:";
			// 
			// label10MinKdjD
			// 
			this->label10MinKdjD->AutoSize = true;
			this->label10MinKdjD->Location = System::Drawing::Point(500, 298);
			this->label10MinKdjD->Name = L"label10MinKdjD";
			this->label10MinKdjD->Size = System::Drawing::Size(24, 18);
			this->label10MinKdjD->TabIndex = 176;
			this->label10MinKdjD->Text = L"D:";
			// 
			// label10MinKdjK
			// 
			this->label10MinKdjK->AutoSize = true;
			this->label10MinKdjK->Location = System::Drawing::Point(290, 300);
			this->label10MinKdjK->Name = L"label10MinKdjK";
			this->label10MinKdjK->Size = System::Drawing::Size(24, 18);
			this->label10MinKdjK->TabIndex = 174;
			this->label10MinKdjK->Text = L"K:";
			// 
			// label10MinKdjDir
			// 
			this->label10MinKdjDir->AutoSize = true;
			this->label10MinKdjDir->Location = System::Drawing::Point(87, 302);
			this->label10MinKdjDir->Name = L"label10MinKdjDir";
			this->label10MinKdjDir->Size = System::Drawing::Size(77, 18);
			this->label10MinKdjDir->TabIndex = 173;
			this->label10MinKdjDir->Text = L"Direction:";
			// 
			// listBox10MinKdjDir
			// 
			this->listBox10MinKdjDir->FormattingEnabled = true;
			this->listBox10MinKdjDir->ItemHeight = 18;
			this->listBox10MinKdjDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinKdjDir->Location = System::Drawing::Point(170, 298);
			this->listBox10MinKdjDir->Name = L"listBox10MinKdjDir";
			this->listBox10MinKdjDir->Size = System::Drawing::Size(97, 22);
			this->listBox10MinKdjDir->TabIndex = 172;
			this->listBox10MinKdjDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinKdjDir_SelectedIndexChanged);
			// 
			// label10MinKdj
			// 
			this->label10MinKdj->AutoSize = true;
			this->label10MinKdj->Location = System::Drawing::Point(26, 302);
			this->label10MinKdj->Name = L"label10MinKdj";
			this->label10MinKdj->Size = System::Drawing::Size(43, 18);
			this->label10MinKdj->TabIndex = 171;
			this->label10MinKdj->Text = L"KDJ:";
			// 
			// textBox10MinMacdDea
			// 
			this->textBox10MinMacdDea->Location = System::Drawing::Point(759, 243);
			this->textBox10MinMacdDea->Name = L"textBox10MinMacdDea";
			this->textBox10MinMacdDea->Size = System::Drawing::Size(124, 26);
			this->textBox10MinMacdDea->TabIndex = 170;
			this->textBox10MinMacdDea->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinMacdDea_TextChanged);
			// 
			// textBox10MinMacdDif
			// 
			this->textBox10MinMacdDif->Location = System::Drawing::Point(557, 243);
			this->textBox10MinMacdDif->Name = L"textBox10MinMacdDif";
			this->textBox10MinMacdDif->Size = System::Drawing::Size(124, 26);
			this->textBox10MinMacdDif->TabIndex = 168;
			this->textBox10MinMacdDif->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinMacdDif_TextChanged);
			// 
			// textBox10MinMacdMacd
			// 
			this->textBox10MinMacdMacd->Location = System::Drawing::Point(353, 248);
			this->textBox10MinMacdMacd->Name = L"textBox10MinMacdMacd";
			this->textBox10MinMacdMacd->Size = System::Drawing::Size(124, 26);
			this->textBox10MinMacdMacd->TabIndex = 166;
			this->textBox10MinMacdMacd->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinMacdMacd_TextChanged);
			// 
			// label10MinMacdDea
			// 
			this->label10MinMacdDea->AutoSize = true;
			this->label10MinMacdDea->Location = System::Drawing::Point(695, 251);
			this->label10MinMacdDea->Name = L"label10MinMacdDea";
			this->label10MinMacdDea->Size = System::Drawing::Size(40, 18);
			this->label10MinMacdDea->TabIndex = 169;
			this->label10MinMacdDea->Text = L"Dea:";
			// 
			// label10MinMacdDif
			// 
			this->label10MinMacdDif->AutoSize = true;
			this->label10MinMacdDif->Location = System::Drawing::Point(500, 251);
			this->label10MinMacdDif->Name = L"label10MinMacdDif";
			this->label10MinMacdDif->Size = System::Drawing::Size(33, 18);
			this->label10MinMacdDif->TabIndex = 167;
			this->label10MinMacdDif->Text = L"Dif:";
			// 
			// label10MinMacdMacd
			// 
			this->label10MinMacdMacd->AutoSize = true;
			this->label10MinMacdMacd->Location = System::Drawing::Point(290, 253);
			this->label10MinMacdMacd->Name = L"label10MinMacdMacd";
			this->label10MinMacdMacd->Size = System::Drawing::Size(52, 18);
			this->label10MinMacdMacd->TabIndex = 165;
			this->label10MinMacdMacd->Text = L"Macd:";
			// 
			// label10MinMacdDir
			// 
			this->label10MinMacdDir->AutoSize = true;
			this->label10MinMacdDir->Location = System::Drawing::Point(87, 255);
			this->label10MinMacdDir->Name = L"label10MinMacdDir";
			this->label10MinMacdDir->Size = System::Drawing::Size(77, 18);
			this->label10MinMacdDir->TabIndex = 164;
			this->label10MinMacdDir->Text = L"Direction:";
			// 
			// listBox10MinMacdDir
			// 
			this->listBox10MinMacdDir->FormattingEnabled = true;
			this->listBox10MinMacdDir->ItemHeight = 18;
			this->listBox10MinMacdDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinMacdDir->Location = System::Drawing::Point(170, 251);
			this->listBox10MinMacdDir->Name = L"listBox10MinMacdDir";
			this->listBox10MinMacdDir->Size = System::Drawing::Size(97, 22);
			this->listBox10MinMacdDir->TabIndex = 163;
			this->listBox10MinMacdDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinMacdDir_SelectedIndexChanged);
			// 
			// label10MinMacd
			// 
			this->label10MinMacd->AutoSize = true;
			this->label10MinMacd->Location = System::Drawing::Point(26, 255);
			this->label10MinMacd->Name = L"label10MinMacd";
			this->label10MinMacd->Size = System::Drawing::Size(60, 18);
			this->label10MinMacd->TabIndex = 162;
			this->label10MinMacd->Text = L"MACD:";
			// 
			// textBox10MinBollUpper
			// 
			this->textBox10MinBollUpper->Location = System::Drawing::Point(759, 196);
			this->textBox10MinBollUpper->Name = L"textBox10MinBollUpper";
			this->textBox10MinBollUpper->Size = System::Drawing::Size(124, 26);
			this->textBox10MinBollUpper->TabIndex = 161;
			this->textBox10MinBollUpper->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinBollUpper_TextChanged);
			// 
			// textBox10MinBollMid
			// 
			this->textBox10MinBollMid->Location = System::Drawing::Point(557, 198);
			this->textBox10MinBollMid->Name = L"textBox10MinBollMid";
			this->textBox10MinBollMid->Size = System::Drawing::Size(124, 26);
			this->textBox10MinBollMid->TabIndex = 159;
			this->textBox10MinBollMid->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinBollMid_TextChanged);
			// 
			// textBox10MinBollLow
			// 
			this->textBox10MinBollLow->Location = System::Drawing::Point(353, 200);
			this->textBox10MinBollLow->Name = L"textBox10MinBollLow";
			this->textBox10MinBollLow->Size = System::Drawing::Size(124, 26);
			this->textBox10MinBollLow->TabIndex = 157;
			this->textBox10MinBollLow->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox10MinBollLow_TextChanged);
			// 
			// label10MinBollUpper
			// 
			this->label10MinBollUpper->AutoSize = true;
			this->label10MinBollUpper->Location = System::Drawing::Point(695, 202);
			this->label10MinBollUpper->Name = L"label10MinBollUpper";
			this->label10MinBollUpper->Size = System::Drawing::Size(58, 18);
			this->label10MinBollUpper->TabIndex = 160;
			this->label10MinBollUpper->Text = L"Upper:";
			// 
			// label10MinBollMid
			// 
			this->label10MinBollMid->AutoSize = true;
			this->label10MinBollMid->Location = System::Drawing::Point(500, 204);
			this->label10MinBollMid->Name = L"label10MinBollMid";
			this->label10MinBollMid->Size = System::Drawing::Size(41, 18);
			this->label10MinBollMid->TabIndex = 158;
			this->label10MinBollMid->Text = L"Mid:";
			// 
			// label10MinBollLow
			// 
			this->label10MinBollLow->AutoSize = true;
			this->label10MinBollLow->Location = System::Drawing::Point(295, 206);
			this->label10MinBollLow->Name = L"label10MinBollLow";
			this->label10MinBollLow->Size = System::Drawing::Size(43, 18);
			this->label10MinBollLow->TabIndex = 156;
			this->label10MinBollLow->Text = L"Low:";
			// 
			// label10MinBollDir
			// 
			this->label10MinBollDir->AutoSize = true;
			this->label10MinBollDir->Location = System::Drawing::Point(87, 206);
			this->label10MinBollDir->Name = L"label10MinBollDir";
			this->label10MinBollDir->Size = System::Drawing::Size(77, 18);
			this->label10MinBollDir->TabIndex = 155;
			this->label10MinBollDir->Text = L"Direction:";
			// 
			// listBox10MinBollDir
			// 
			this->listBox10MinBollDir->FormattingEnabled = true;
			this->listBox10MinBollDir->ItemHeight = 18;
			this->listBox10MinBollDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox10MinBollDir->Location = System::Drawing::Point(170, 204);
			this->listBox10MinBollDir->Name = L"listBox10MinBollDir";
			this->listBox10MinBollDir->Size = System::Drawing::Size(97, 22);
			this->listBox10MinBollDir->TabIndex = 154;
			this->listBox10MinBollDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox10MinBollDir_SelectedIndexChanged);
			// 
			// label10MinBoll
			// 
			this->label10MinBoll->AutoSize = true;
			this->label10MinBoll->Location = System::Drawing::Point(26, 210);
			this->label10MinBoll->Name = L"label10MinBoll";
			this->label10MinBoll->Size = System::Drawing::Size(55, 18);
			this->label10MinBoll->TabIndex = 153;
			this->label10MinBoll->Text = L"BOLL:";
			// 
			// tab15Min
			// 
			this->tab15Min->Controls->Add(this->listBox15MinMADir6);
			this->tab15Min->Controls->Add(this->label15MinMADir6);
			this->tab15Min->Controls->Add(this->textBox15MinMA6);
			this->tab15Min->Controls->Add(this->textBox15MinMA5);
			this->tab15Min->Controls->Add(this->label15MinMA6);
			this->tab15Min->Controls->Add(this->label15MinMA5);
			this->tab15Min->Controls->Add(this->label15MinMADir5);
			this->tab15Min->Controls->Add(this->listBox15MinMADir5);
			this->tab15Min->Controls->Add(this->label15MinMA56);
			this->tab15Min->Controls->Add(this->label15MinMADir4);
			this->tab15Min->Controls->Add(this->listBox15MinMADir4);
			this->tab15Min->Controls->Add(this->textBox15MinMA4);
			this->tab15Min->Controls->Add(this->textBox15MinMA3);
			this->tab15Min->Controls->Add(this->label15MinMA4);
			this->tab15Min->Controls->Add(this->label15MinMA3);
			this->tab15Min->Controls->Add(this->label15MinMADir3);
			this->tab15Min->Controls->Add(this->listBox15MinMADir3);
			this->tab15Min->Controls->Add(this->label15MinMA34);
			this->tab15Min->Controls->Add(this->label15MinMADir2);
			this->tab15Min->Controls->Add(this->listBox15MinMADir2);
			this->tab15Min->Controls->Add(this->textBox15MinMA2);
			this->tab15Min->Controls->Add(this->textBox15MinMA1);
			this->tab15Min->Controls->Add(this->label15MinMA2);
			this->tab15Min->Controls->Add(this->label15MinMA1);
			this->tab15Min->Controls->Add(this->label15MinMADir1);
			this->tab15Min->Controls->Add(this->listBox15MinMADir1);
			this->tab15Min->Controls->Add(this->label15MinMA12);
			this->tab15Min->Controls->Add(this->textBox15MinCciCci);
			this->tab15Min->Controls->Add(this->label15MinCciCci);
			this->tab15Min->Controls->Add(this->label15MinCciDir);
			this->tab15Min->Controls->Add(this->listBox15MinCciDir);
			this->tab15Min->Controls->Add(this->label15MinCci);
			this->tab15Min->Controls->Add(this->textBox15MinCrC);
			this->tab15Min->Controls->Add(this->label15MinCrC);
			this->tab15Min->Controls->Add(this->textBox15MinCrB);
			this->tab15Min->Controls->Add(this->label15MinCrB);
			this->tab15Min->Controls->Add(this->textBox15MinCrA);
			this->tab15Min->Controls->Add(this->textBox15MinCrCr);
			this->tab15Min->Controls->Add(this->label15MinCrA);
			this->tab15Min->Controls->Add(this->label15MinCrCr);
			this->tab15Min->Controls->Add(this->label15MinCrDir);
			this->tab15Min->Controls->Add(this->listBox15MinCrDir);
			this->tab15Min->Controls->Add(this->label15MinCr);
			this->tab15Min->Controls->Add(this->textBox15MinDmaAma);
			this->tab15Min->Controls->Add(this->textBox15MinDmaDma);
			this->tab15Min->Controls->Add(this->label15MinDmaAma);
			this->tab15Min->Controls->Add(this->label15MinDmaDma);
			this->tab15Min->Controls->Add(this->label15MinDmaDir);
			this->tab15Min->Controls->Add(this->listBox15MinDmaDir);
			this->tab15Min->Controls->Add(this->label15MinDma);
			this->tab15Min->Controls->Add(this->textBox15MinRocRocma);
			this->tab15Min->Controls->Add(this->textBox15MinRocRoc);
			this->tab15Min->Controls->Add(this->label15MinRocRocma);
			this->tab15Min->Controls->Add(this->label15MinRocRoc);
			this->tab15Min->Controls->Add(this->label15MinRocDir);
			this->tab15Min->Controls->Add(this->listBox15MinRocDir);
			this->tab15Min->Controls->Add(this->label15MinRoc);
			this->tab15Min->Controls->Add(this->textBox15MinVrLong);
			this->tab15Min->Controls->Add(this->textBox15MinVrShort);
			this->tab15Min->Controls->Add(this->label15MinVrLong);
			this->tab15Min->Controls->Add(this->label15MinVrShort);
			this->tab15Min->Controls->Add(this->label15MinVrDir);
			this->tab15Min->Controls->Add(this->listBox15MinVrDir);
			this->tab15Min->Controls->Add(this->label15MinVr);
			this->tab15Min->Controls->Add(this->label15MinVolDir2);
			this->tab15Min->Controls->Add(this->listBox15MinVolDir2);
			this->tab15Min->Controls->Add(this->textBox15MinVol2);
			this->tab15Min->Controls->Add(this->textBox15MinVol1);
			this->tab15Min->Controls->Add(this->label15MinVol2);
			this->tab15Min->Controls->Add(this->label15MinVol1);
			this->tab15Min->Controls->Add(this->label15MinVolDir1);
			this->tab15Min->Controls->Add(this->listBox15MinVolDir1);
			this->tab15Min->Controls->Add(this->label15MinVol);
			this->tab15Min->Controls->Add(this->textBox15MinWr2);
			this->tab15Min->Controls->Add(this->textBox15MinWr1);
			this->tab15Min->Controls->Add(this->label15MinWr2);
			this->tab15Min->Controls->Add(this->label15MinWr1);
			this->tab15Min->Controls->Add(this->label15MinWrDir);
			this->tab15Min->Controls->Add(this->listBox15MinWrDir);
			this->tab15Min->Controls->Add(this->label15MinWr);
			this->tab15Min->Controls->Add(this->textBox15MinRsiLong);
			this->tab15Min->Controls->Add(this->textBox15MinRsiMiddle);
			this->tab15Min->Controls->Add(this->textBox15MinRsiShort);
			this->tab15Min->Controls->Add(this->label15MinRsiLong);
			this->tab15Min->Controls->Add(this->label15MinRsiMiddle);
			this->tab15Min->Controls->Add(this->label15MinRsiShort);
			this->tab15Min->Controls->Add(this->label15MinRsiDir);
			this->tab15Min->Controls->Add(this->listBox15MinRsiDir);
			this->tab15Min->Controls->Add(this->label15MinRsi);
			this->tab15Min->Controls->Add(this->textBox15MinKdjJ);
			this->tab15Min->Controls->Add(this->textBox15MinKdjD);
			this->tab15Min->Controls->Add(this->textBox15MinKdjK);
			this->tab15Min->Controls->Add(this->label15MinKdjJ);
			this->tab15Min->Controls->Add(this->label15MinKdjD);
			this->tab15Min->Controls->Add(this->label15MinKdjK);
			this->tab15Min->Controls->Add(this->label15MinKdjDir);
			this->tab15Min->Controls->Add(this->listBox15MinKdjDir);
			this->tab15Min->Controls->Add(this->label15MinKdj);
			this->tab15Min->Controls->Add(this->textBox15MinMacdDea);
			this->tab15Min->Controls->Add(this->textBox15MinMacdDif);
			this->tab15Min->Controls->Add(this->textBox15MinMacdMacd);
			this->tab15Min->Controls->Add(this->label15MinMacdDea);
			this->tab15Min->Controls->Add(this->label15MinMacdDif);
			this->tab15Min->Controls->Add(this->label15MinMacdMacd);
			this->tab15Min->Controls->Add(this->label15MinMacdDir);
			this->tab15Min->Controls->Add(this->listBox15MinMacdDir);
			this->tab15Min->Controls->Add(this->label15MinMacd);
			this->tab15Min->Controls->Add(this->textBox15MinBollUpper);
			this->tab15Min->Controls->Add(this->textBox15MinBollMid);
			this->tab15Min->Controls->Add(this->textBox15MinBollLow);
			this->tab15Min->Controls->Add(this->label15MinBollUpper);
			this->tab15Min->Controls->Add(this->label15MinBollMid);
			this->tab15Min->Controls->Add(this->label15MinBollLow);
			this->tab15Min->Controls->Add(this->label15MinBollDir);
			this->tab15Min->Controls->Add(this->listBox15MinBollDir);
			this->tab15Min->Controls->Add(this->label15MinBoll);
			this->tab15Min->Location = System::Drawing::Point(4, 27);
			this->tab15Min->Name = L"tab15Min";
			this->tab15Min->Padding = System::Windows::Forms::Padding(3);
			this->tab15Min->Size = System::Drawing::Size(1092, 869);
			this->tab15Min->TabIndex = 8;
			this->tab15Min->Text = L"15Min";
			this->tab15Min->UseVisualStyleBackColor = true;
			// 
			// listBox15MinMADir6
			// 
			this->listBox15MinMADir6->FormattingEnabled = true;
			this->listBox15MinMADir6->ItemHeight = 18;
			this->listBox15MinMADir6->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinMADir6->Location = System::Drawing::Point(575, 103);
			this->listBox15MinMADir6->Name = L"listBox15MinMADir6";
			this->listBox15MinMADir6->Size = System::Drawing::Size(106, 22);
			this->listBox15MinMADir6->TabIndex = 269;
			this->listBox15MinMADir6->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinMADir6_SelectedIndexChanged);
			// 
			// label15MinMADir6
			// 
			this->label15MinMADir6->AutoSize = true;
			this->label15MinMADir6->Location = System::Drawing::Point(483, 107);
			this->label15MinMADir6->Name = L"label15MinMADir6";
			this->label15MinMADir6->Size = System::Drawing::Size(80, 18);
			this->label15MinMADir6->TabIndex = 268;
			this->label15MinMADir6->Text = L"MA_Dir6:";
			// 
			// textBox15MinMA6
			// 
			this->textBox15MinMA6->Location = System::Drawing::Point(759, 99);
			this->textBox15MinMA6->Name = L"textBox15MinMA6";
			this->textBox15MinMA6->Size = System::Drawing::Size(124, 26);
			this->textBox15MinMA6->TabIndex = 266;
			this->textBox15MinMA6->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinMA6_TextChanged);
			// 
			// textBox15MinMA5
			// 
			this->textBox15MinMA5->Location = System::Drawing::Point(353, 104);
			this->textBox15MinMA5->Name = L"textBox15MinMA5";
			this->textBox15MinMA5->Size = System::Drawing::Size(124, 26);
			this->textBox15MinMA5->TabIndex = 264;
			this->textBox15MinMA5->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinMA5_TextChanged);
			// 
			// label15MinMA6
			// 
			this->label15MinMA6->AutoSize = true;
			this->label15MinMA6->Location = System::Drawing::Point(695, 107);
			this->label15MinMA6->Name = L"label15MinMA6";
			this->label15MinMA6->Size = System::Drawing::Size(48, 18);
			this->label15MinMA6->TabIndex = 265;
			this->label15MinMA6->Text = L"MA6:";
			// 
			// label15MinMA5
			// 
			this->label15MinMA5->AutoSize = true;
			this->label15MinMA5->Location = System::Drawing::Point(290, 109);
			this->label15MinMA5->Name = L"label15MinMA5";
			this->label15MinMA5->Size = System::Drawing::Size(48, 18);
			this->label15MinMA5->TabIndex = 263;
			this->label15MinMA5->Text = L"MA5:";
			// 
			// label15MinMADir5
			// 
			this->label15MinMADir5->AutoSize = true;
			this->label15MinMADir5->Location = System::Drawing::Point(79, 112);
			this->label15MinMADir5->Name = L"label15MinMADir5";
			this->label15MinMADir5->Size = System::Drawing::Size(80, 18);
			this->label15MinMADir5->TabIndex = 262;
			this->label15MinMADir5->Text = L"MA_Dir5:";
			// 
			// listBox15MinMADir5
			// 
			this->listBox15MinMADir5->FormattingEnabled = true;
			this->listBox15MinMADir5->ItemHeight = 18;
			this->listBox15MinMADir5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinMADir5->Location = System::Drawing::Point(170, 107);
			this->listBox15MinMADir5->Name = L"listBox15MinMADir5";
			this->listBox15MinMADir5->Size = System::Drawing::Size(97, 22);
			this->listBox15MinMADir5->TabIndex = 261;
			this->listBox15MinMADir5->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinMADir5_SelectedIndexChanged);
			// 
			// label15MinMA56
			// 
			this->label15MinMA56->AutoSize = true;
			this->label15MinMA56->Location = System::Drawing::Point(17, 112);
			this->label15MinMA56->Name = L"label15MinMA56";
			this->label15MinMA56->Size = System::Drawing::Size(64, 18);
			this->label15MinMA56->TabIndex = 260;
			this->label15MinMA56->Text = L"MA5-6:";
			// 
			// label15MinMADir4
			// 
			this->label15MinMADir4->AutoSize = true;
			this->label15MinMADir4->Location = System::Drawing::Point(483, 60);
			this->label15MinMADir4->Name = L"label15MinMADir4";
			this->label15MinMADir4->Size = System::Drawing::Size(80, 18);
			this->label15MinMADir4->TabIndex = 259;
			this->label15MinMADir4->Text = L"MA_Dir4:";
			// 
			// listBox15MinMADir4
			// 
			this->listBox15MinMADir4->FormattingEnabled = true;
			this->listBox15MinMADir4->ItemHeight = 18;
			this->listBox15MinMADir4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinMADir4->Location = System::Drawing::Point(575, 57);
			this->listBox15MinMADir4->Name = L"listBox15MinMADir4";
			this->listBox15MinMADir4->Size = System::Drawing::Size(106, 22);
			this->listBox15MinMADir4->TabIndex = 258;
			this->listBox15MinMADir4->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinMADir4_SelectedIndexChanged);
			// 
			// textBox15MinMA4
			// 
			this->textBox15MinMA4->Location = System::Drawing::Point(759, 52);
			this->textBox15MinMA4->Name = L"textBox15MinMA4";
			this->textBox15MinMA4->Size = System::Drawing::Size(124, 26);
			this->textBox15MinMA4->TabIndex = 257;
			this->textBox15MinMA4->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinMA4_TextChanged);
			// 
			// textBox15MinMA3
			// 
			this->textBox15MinMA3->Location = System::Drawing::Point(353, 57);
			this->textBox15MinMA3->Name = L"textBox15MinMA3";
			this->textBox15MinMA3->Size = System::Drawing::Size(124, 26);
			this->textBox15MinMA3->TabIndex = 255;
			this->textBox15MinMA3->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinMA3_TextChanged);
			// 
			// label15MinMA4
			// 
			this->label15MinMA4->AutoSize = true;
			this->label15MinMA4->Location = System::Drawing::Point(695, 60);
			this->label15MinMA4->Name = L"label15MinMA4";
			this->label15MinMA4->Size = System::Drawing::Size(48, 18);
			this->label15MinMA4->TabIndex = 256;
			this->label15MinMA4->Text = L"MA4:";
			// 
			// label15MinMA3
			// 
			this->label15MinMA3->AutoSize = true;
			this->label15MinMA3->Location = System::Drawing::Point(290, 62);
			this->label15MinMA3->Name = L"label15MinMA3";
			this->label15MinMA3->Size = System::Drawing::Size(48, 18);
			this->label15MinMA3->TabIndex = 254;
			this->label15MinMA3->Text = L"MA3:";
			// 
			// label15MinMADir3
			// 
			this->label15MinMADir3->AutoSize = true;
			this->label15MinMADir3->Location = System::Drawing::Point(79, 65);
			this->label15MinMADir3->Name = L"label15MinMADir3";
			this->label15MinMADir3->Size = System::Drawing::Size(80, 18);
			this->label15MinMADir3->TabIndex = 253;
			this->label15MinMADir3->Text = L"MA_Dir3:";
			// 
			// listBox15MinMADir3
			// 
			this->listBox15MinMADir3->FormattingEnabled = true;
			this->listBox15MinMADir3->ItemHeight = 18;
			this->listBox15MinMADir3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinMADir3->Location = System::Drawing::Point(170, 60);
			this->listBox15MinMADir3->Name = L"listBox15MinMADir3";
			this->listBox15MinMADir3->Size = System::Drawing::Size(97, 22);
			this->listBox15MinMADir3->TabIndex = 252;
			this->listBox15MinMADir3->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinMADir3_SelectedIndexChanged);
			// 
			// label15MinMA34
			// 
			this->label15MinMA34->AutoSize = true;
			this->label15MinMA34->Location = System::Drawing::Point(17, 65);
			this->label15MinMA34->Name = L"label15MinMA34";
			this->label15MinMA34->Size = System::Drawing::Size(64, 18);
			this->label15MinMA34->TabIndex = 251;
			this->label15MinMA34->Text = L"MA3-4:";
			// 
			// label15MinMADir2
			// 
			this->label15MinMADir2->AutoSize = true;
			this->label15MinMADir2->Location = System::Drawing::Point(483, 19);
			this->label15MinMADir2->Name = L"label15MinMADir2";
			this->label15MinMADir2->Size = System::Drawing::Size(80, 18);
			this->label15MinMADir2->TabIndex = 250;
			this->label15MinMADir2->Text = L"MA_Dir2:";
			// 
			// listBox15MinMADir2
			// 
			this->listBox15MinMADir2->FormattingEnabled = true;
			this->listBox15MinMADir2->ItemHeight = 18;
			this->listBox15MinMADir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinMADir2->Location = System::Drawing::Point(575, 16);
			this->listBox15MinMADir2->Name = L"listBox15MinMADir2";
			this->listBox15MinMADir2->Size = System::Drawing::Size(106, 22);
			this->listBox15MinMADir2->TabIndex = 249;
			this->listBox15MinMADir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinMADir2_SelectedIndexChanged);
			// 
			// textBox15MinMA2
			// 
			this->textBox15MinMA2->Location = System::Drawing::Point(759, 11);
			this->textBox15MinMA2->Name = L"textBox15MinMA2";
			this->textBox15MinMA2->Size = System::Drawing::Size(124, 26);
			this->textBox15MinMA2->TabIndex = 248;
			this->textBox15MinMA2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinMA2_TextChanged);
			// 
			// textBox15MinMA1
			// 
			this->textBox15MinMA1->Location = System::Drawing::Point(353, 16);
			this->textBox15MinMA1->Name = L"textBox15MinMA1";
			this->textBox15MinMA1->Size = System::Drawing::Size(124, 26);
			this->textBox15MinMA1->TabIndex = 246;
			this->textBox15MinMA1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinMA1_TextChanged);
			// 
			// label15MinMA2
			// 
			this->label15MinMA2->AutoSize = true;
			this->label15MinMA2->Location = System::Drawing::Point(695, 19);
			this->label15MinMA2->Name = L"label15MinMA2";
			this->label15MinMA2->Size = System::Drawing::Size(48, 18);
			this->label15MinMA2->TabIndex = 247;
			this->label15MinMA2->Text = L"MA2:";
			// 
			// label15MinMA1
			// 
			this->label15MinMA1->AutoSize = true;
			this->label15MinMA1->Location = System::Drawing::Point(290, 21);
			this->label15MinMA1->Name = L"label15MinMA1";
			this->label15MinMA1->Size = System::Drawing::Size(47, 18);
			this->label15MinMA1->TabIndex = 245;
			this->label15MinMA1->Text = L"MA1:";
			// 
			// label15MinMADir1
			// 
			this->label15MinMADir1->AutoSize = true;
			this->label15MinMADir1->Location = System::Drawing::Point(79, 21);
			this->label15MinMADir1->Name = L"label15MinMADir1";
			this->label15MinMADir1->Size = System::Drawing::Size(79, 18);
			this->label15MinMADir1->TabIndex = 244;
			this->label15MinMADir1->Text = L"MA_Dir1:";
			// 
			// listBox15MinMADir1
			// 
			this->listBox15MinMADir1->FormattingEnabled = true;
			this->listBox15MinMADir1->ItemHeight = 18;
			this->listBox15MinMADir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinMADir1->Location = System::Drawing::Point(170, 19);
			this->listBox15MinMADir1->Name = L"listBox15MinMADir1";
			this->listBox15MinMADir1->Size = System::Drawing::Size(97, 22);
			this->listBox15MinMADir1->TabIndex = 243;
			this->listBox15MinMADir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinMADir1_SelectedIndexChanged);
			// 
			// label15MinMA12
			// 
			this->label15MinMA12->AutoSize = true;
			this->label15MinMA12->Location = System::Drawing::Point(16, 24);
			this->label15MinMA12->Name = L"label15MinMA12";
			this->label15MinMA12->Size = System::Drawing::Size(63, 18);
			this->label15MinMA12->TabIndex = 242;
			this->label15MinMA12->Text = L"MA1-2:";
			// 
			// textBox15MinCciCci
			// 
			this->textBox15MinCciCci->Location = System::Drawing::Point(353, 601);
			this->textBox15MinCciCci->Name = L"textBox15MinCciCci";
			this->textBox15MinCciCci->Size = System::Drawing::Size(124, 26);
			this->textBox15MinCciCci->TabIndex = 241;
			this->textBox15MinCciCci->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinCciCci_TextChanged);
			// 
			// label15MinCciCci
			// 
			this->label15MinCciCci->AutoSize = true;
			this->label15MinCciCci->Location = System::Drawing::Point(286, 608);
			this->label15MinCciCci->Name = L"label15MinCciCci";
			this->label15MinCciCci->Size = System::Drawing::Size(34, 18);
			this->label15MinCciCci->TabIndex = 240;
			this->label15MinCciCci->Text = L"Cci:";
			// 
			// label15MinCciDir
			// 
			this->label15MinCciDir->AutoSize = true;
			this->label15MinCciDir->Location = System::Drawing::Point(87, 608);
			this->label15MinCciDir->Name = L"label15MinCciDir";
			this->label15MinCciDir->Size = System::Drawing::Size(77, 18);
			this->label15MinCciDir->TabIndex = 239;
			this->label15MinCciDir->Text = L"Direction:";
			// 
			// listBox15MinCciDir
			// 
			this->listBox15MinCciDir->FormattingEnabled = true;
			this->listBox15MinCciDir->ItemHeight = 18;
			this->listBox15MinCciDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinCciDir->Location = System::Drawing::Point(170, 604);
			this->listBox15MinCciDir->Name = L"listBox15MinCciDir";
			this->listBox15MinCciDir->Size = System::Drawing::Size(97, 22);
			this->listBox15MinCciDir->TabIndex = 238;
			this->listBox15MinCciDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinCciDir_SelectedIndexChanged);
			// 
			// label15MinCci
			// 
			this->label15MinCci->AutoSize = true;
			this->label15MinCci->Location = System::Drawing::Point(26, 608);
			this->label15MinCci->Name = L"label15MinCci";
			this->label15MinCci->Size = System::Drawing::Size(40, 18);
			this->label15MinCci->TabIndex = 237;
			this->label15MinCci->Text = L"CCI:";
			// 
			// textBox15MinCrC
			// 
			this->textBox15MinCrC->Location = System::Drawing::Point(961, 555);
			this->textBox15MinCrC->Name = L"textBox15MinCrC";
			this->textBox15MinCrC->Size = System::Drawing::Size(124, 26);
			this->textBox15MinCrC->TabIndex = 236;
			this->textBox15MinCrC->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinCrC_TextChanged);
			// 
			// label15MinCrC
			// 
			this->label15MinCrC->AutoSize = true;
			this->label15MinCrC->Location = System::Drawing::Point(900, 563);
			this->label15MinCrC->Name = L"label15MinCrC";
			this->label15MinCrC->Size = System::Drawing::Size(23, 18);
			this->label15MinCrC->TabIndex = 235;
			this->label15MinCrC->Text = L"C:";
			// 
			// textBox15MinCrB
			// 
			this->textBox15MinCrB->Location = System::Drawing::Point(755, 555);
			this->textBox15MinCrB->Name = L"textBox15MinCrB";
			this->textBox15MinCrB->Size = System::Drawing::Size(124, 26);
			this->textBox15MinCrB->TabIndex = 234;
			this->textBox15MinCrB->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinCrB_TextChanged);
			// 
			// label15MinCrB
			// 
			this->label15MinCrB->AutoSize = true;
			this->label15MinCrB->Location = System::Drawing::Point(694, 563);
			this->label15MinCrB->Name = L"label15MinCrB";
			this->label15MinCrB->Size = System::Drawing::Size(23, 18);
			this->label15MinCrB->TabIndex = 233;
			this->label15MinCrB->Text = L"B:";
			// 
			// textBox15MinCrA
			// 
			this->textBox15MinCrA->Location = System::Drawing::Point(557, 555);
			this->textBox15MinCrA->Name = L"textBox15MinCrA";
			this->textBox15MinCrA->Size = System::Drawing::Size(124, 26);
			this->textBox15MinCrA->TabIndex = 232;
			this->textBox15MinCrA->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinCrA_TextChanged);
			// 
			// textBox15MinCrCr
			// 
			this->textBox15MinCrCr->Location = System::Drawing::Point(353, 560);
			this->textBox15MinCrCr->Name = L"textBox15MinCrCr";
			this->textBox15MinCrCr->Size = System::Drawing::Size(124, 26);
			this->textBox15MinCrCr->TabIndex = 230;
			this->textBox15MinCrCr->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinCrCr_TextChanged);
			// 
			// label15MinCrA
			// 
			this->label15MinCrA->AutoSize = true;
			this->label15MinCrA->Location = System::Drawing::Point(496, 563);
			this->label15MinCrA->Name = L"label15MinCrA";
			this->label15MinCrA->Size = System::Drawing::Size(24, 18);
			this->label15MinCrA->TabIndex = 231;
			this->label15MinCrA->Text = L"A:";
			// 
			// label15MinCrCr
			// 
			this->label15MinCrCr->AutoSize = true;
			this->label15MinCrCr->Location = System::Drawing::Point(286, 567);
			this->label15MinCrCr->Name = L"label15MinCrCr";
			this->label15MinCrCr->Size = System::Drawing::Size(30, 18);
			this->label15MinCrCr->TabIndex = 229;
			this->label15MinCrCr->Text = L"Cr:";
			// 
			// label15MinCrDir
			// 
			this->label15MinCrDir->AutoSize = true;
			this->label15MinCrDir->Location = System::Drawing::Point(87, 567);
			this->label15MinCrDir->Name = L"label15MinCrDir";
			this->label15MinCrDir->Size = System::Drawing::Size(77, 18);
			this->label15MinCrDir->TabIndex = 228;
			this->label15MinCrDir->Text = L"Direction:";
			// 
			// listBox15MinCrDir
			// 
			this->listBox15MinCrDir->FormattingEnabled = true;
			this->listBox15MinCrDir->ItemHeight = 18;
			this->listBox15MinCrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinCrDir->Location = System::Drawing::Point(170, 563);
			this->listBox15MinCrDir->Name = L"listBox15MinCrDir";
			this->listBox15MinCrDir->Size = System::Drawing::Size(97, 22);
			this->listBox15MinCrDir->TabIndex = 227;
			this->listBox15MinCrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinCrDir_SelectedIndexChanged);
			// 
			// label15MinCr
			// 
			this->label15MinCr->AutoSize = true;
			this->label15MinCr->Location = System::Drawing::Point(26, 567);
			this->label15MinCr->Name = L"label15MinCr";
			this->label15MinCr->Size = System::Drawing::Size(34, 18);
			this->label15MinCr->TabIndex = 226;
			this->label15MinCr->Text = L"CR:";
			// 
			// textBox15MinDmaAma
			// 
			this->textBox15MinDmaAma->Location = System::Drawing::Point(557, 513);
			this->textBox15MinDmaAma->Name = L"textBox15MinDmaAma";
			this->textBox15MinDmaAma->Size = System::Drawing::Size(124, 26);
			this->textBox15MinDmaAma->TabIndex = 225;
			this->textBox15MinDmaAma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinDmaAma_TextChanged);
			// 
			// textBox15MinDmaDma
			// 
			this->textBox15MinDmaDma->Location = System::Drawing::Point(353, 518);
			this->textBox15MinDmaDma->Name = L"textBox15MinDmaDma";
			this->textBox15MinDmaDma->Size = System::Drawing::Size(124, 26);
			this->textBox15MinDmaDma->TabIndex = 223;
			this->textBox15MinDmaDma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinDmaDma_TextChanged);
			// 
			// label15MinDmaAma
			// 
			this->label15MinDmaAma->AutoSize = true;
			this->label15MinDmaAma->Location = System::Drawing::Point(483, 521);
			this->label15MinDmaAma->Name = L"label15MinDmaAma";
			this->label15MinDmaAma->Size = System::Drawing::Size(46, 18);
			this->label15MinDmaAma->TabIndex = 224;
			this->label15MinDmaAma->Text = L"Ama:";
			// 
			// label15MinDmaDma
			// 
			this->label15MinDmaDma->AutoSize = true;
			this->label15MinDmaDma->Location = System::Drawing::Point(286, 525);
			this->label15MinDmaDma->Name = L"label15MinDmaDma";
			this->label15MinDmaDma->Size = System::Drawing::Size(46, 18);
			this->label15MinDmaDma->TabIndex = 222;
			this->label15MinDmaDma->Text = L"Dma:";
			// 
			// label15MinDmaDir
			// 
			this->label15MinDmaDir->AutoSize = true;
			this->label15MinDmaDir->Location = System::Drawing::Point(87, 525);
			this->label15MinDmaDir->Name = L"label15MinDmaDir";
			this->label15MinDmaDir->Size = System::Drawing::Size(77, 18);
			this->label15MinDmaDir->TabIndex = 221;
			this->label15MinDmaDir->Text = L"Direction:";
			// 
			// listBox15MinDmaDir
			// 
			this->listBox15MinDmaDir->FormattingEnabled = true;
			this->listBox15MinDmaDir->ItemHeight = 18;
			this->listBox15MinDmaDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinDmaDir->Location = System::Drawing::Point(170, 521);
			this->listBox15MinDmaDir->Name = L"listBox15MinDmaDir";
			this->listBox15MinDmaDir->Size = System::Drawing::Size(97, 22);
			this->listBox15MinDmaDir->TabIndex = 220;
			this->listBox15MinDmaDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinDmaDir_SelectedIndexChanged);
			// 
			// label15MinDma
			// 
			this->label15MinDma->AutoSize = true;
			this->label15MinDma->Location = System::Drawing::Point(26, 525);
			this->label15MinDma->Name = L"label15MinDma";
			this->label15MinDma->Size = System::Drawing::Size(50, 18);
			this->label15MinDma->TabIndex = 219;
			this->label15MinDma->Text = L"DMA:";
			// 
			// textBox15MinRocRocma
			// 
			this->textBox15MinRocRocma->Location = System::Drawing::Point(557, 427);
			this->textBox15MinRocRocma->Name = L"textBox15MinRocRocma";
			this->textBox15MinRocRocma->Size = System::Drawing::Size(124, 26);
			this->textBox15MinRocRocma->TabIndex = 218;
			this->textBox15MinRocRocma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinRocRocma_TextChanged);
			// 
			// textBox15MinRocRoc
			// 
			this->textBox15MinRocRoc->Location = System::Drawing::Point(353, 432);
			this->textBox15MinRocRoc->Name = L"textBox15MinRocRoc";
			this->textBox15MinRocRoc->Size = System::Drawing::Size(124, 26);
			this->textBox15MinRocRoc->TabIndex = 216;
			this->textBox15MinRocRoc->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinRocRoc_TextChanged);
			// 
			// label15MinRocRocma
			// 
			this->label15MinRocRocma->AutoSize = true;
			this->label15MinRocRocma->Location = System::Drawing::Point(483, 435);
			this->label15MinRocRocma->Name = L"label15MinRocRocma";
			this->label15MinRocRocma->Size = System::Drawing::Size(71, 18);
			this->label15MinRocRocma->TabIndex = 217;
			this->label15MinRocRocma->Text = L"Roc_ma:";
			// 
			// label15MinRocRoc
			// 
			this->label15MinRocRoc->AutoSize = true;
			this->label15MinRocRoc->Location = System::Drawing::Point(286, 439);
			this->label15MinRocRoc->Name = L"label15MinRocRoc";
			this->label15MinRocRoc->Size = System::Drawing::Size(39, 18);
			this->label15MinRocRoc->TabIndex = 215;
			this->label15MinRocRoc->Text = L"Roc:";
			// 
			// label15MinRocDir
			// 
			this->label15MinRocDir->AutoSize = true;
			this->label15MinRocDir->Location = System::Drawing::Point(87, 439);
			this->label15MinRocDir->Name = L"label15MinRocDir";
			this->label15MinRocDir->Size = System::Drawing::Size(77, 18);
			this->label15MinRocDir->TabIndex = 214;
			this->label15MinRocDir->Text = L"Direction:";
			// 
			// listBox15MinRocDir
			// 
			this->listBox15MinRocDir->FormattingEnabled = true;
			this->listBox15MinRocDir->ItemHeight = 18;
			this->listBox15MinRocDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinRocDir->Location = System::Drawing::Point(170, 435);
			this->listBox15MinRocDir->Name = L"listBox15MinRocDir";
			this->listBox15MinRocDir->Size = System::Drawing::Size(97, 22);
			this->listBox15MinRocDir->TabIndex = 213;
			this->listBox15MinRocDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinRocDir_SelectedIndexChanged);
			// 
			// label15MinRoc
			// 
			this->label15MinRoc->AutoSize = true;
			this->label15MinRoc->Location = System::Drawing::Point(26, 439);
			this->label15MinRoc->Name = L"label15MinRoc";
			this->label15MinRoc->Size = System::Drawing::Size(46, 18);
			this->label15MinRoc->TabIndex = 212;
			this->label15MinRoc->Text = L"ROC:";
			// 
			// textBox15MinVrLong
			// 
			this->textBox15MinVrLong->Location = System::Drawing::Point(557, 470);
			this->textBox15MinVrLong->Name = L"textBox15MinVrLong";
			this->textBox15MinVrLong->Size = System::Drawing::Size(124, 26);
			this->textBox15MinVrLong->TabIndex = 211;
			this->textBox15MinVrLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinVrLong_TextChanged);
			// 
			// textBox15MinVrShort
			// 
			this->textBox15MinVrShort->Location = System::Drawing::Point(353, 475);
			this->textBox15MinVrShort->Name = L"textBox15MinVrShort";
			this->textBox15MinVrShort->Size = System::Drawing::Size(124, 26);
			this->textBox15MinVrShort->TabIndex = 209;
			this->textBox15MinVrShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinVrShort_TextChanged);
			// 
			// label15MinVrLong
			// 
			this->label15MinVrLong->AutoSize = true;
			this->label15MinVrLong->Location = System::Drawing::Point(483, 478);
			this->label15MinVrLong->Name = L"label15MinVrLong";
			this->label15MinVrLong->Size = System::Drawing::Size(48, 18);
			this->label15MinVrLong->TabIndex = 210;
			this->label15MinVrLong->Text = L"Long:";
			// 
			// label15MinVrShort
			// 
			this->label15MinVrShort->AutoSize = true;
			this->label15MinVrShort->Location = System::Drawing::Point(281, 483);
			this->label15MinVrShort->Name = L"label15MinVrShort";
			this->label15MinVrShort->Size = System::Drawing::Size(52, 18);
			this->label15MinVrShort->TabIndex = 208;
			this->label15MinVrShort->Text = L"Short:";
			// 
			// label15MinVrDir
			// 
			this->label15MinVrDir->AutoSize = true;
			this->label15MinVrDir->Location = System::Drawing::Point(87, 482);
			this->label15MinVrDir->Name = L"label15MinVrDir";
			this->label15MinVrDir->Size = System::Drawing::Size(77, 18);
			this->label15MinVrDir->TabIndex = 207;
			this->label15MinVrDir->Text = L"Direction:";
			// 
			// listBox15MinVrDir
			// 
			this->listBox15MinVrDir->FormattingEnabled = true;
			this->listBox15MinVrDir->ItemHeight = 18;
			this->listBox15MinVrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinVrDir->Location = System::Drawing::Point(170, 478);
			this->listBox15MinVrDir->Name = L"listBox15MinVrDir";
			this->listBox15MinVrDir->Size = System::Drawing::Size(97, 22);
			this->listBox15MinVrDir->TabIndex = 206;
			this->listBox15MinVrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinVrDir_SelectedIndexChanged);
			// 
			// label15MinVr
			// 
			this->label15MinVr->AutoSize = true;
			this->label15MinVr->Location = System::Drawing::Point(26, 482);
			this->label15MinVr->Name = L"label15MinVr";
			this->label15MinVr->Size = System::Drawing::Size(35, 18);
			this->label15MinVr->TabIndex = 205;
			this->label15MinVr->Text = L"VR:";
			// 
			// label15MinVolDir2
			// 
			this->label15MinVolDir2->AutoSize = true;
			this->label15MinVolDir2->Location = System::Drawing::Point(483, 154);
			this->label15MinVolDir2->Name = L"label15MinVolDir2";
			this->label15MinVolDir2->Size = System::Drawing::Size(86, 18);
			this->label15MinVolDir2->TabIndex = 204;
			this->label15MinVolDir2->Text = L"Direction2:";
			// 
			// listBox15MinVolDir2
			// 
			this->listBox15MinVolDir2->FormattingEnabled = true;
			this->listBox15MinVolDir2->ItemHeight = 18;
			this->listBox15MinVolDir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinVolDir2->Location = System::Drawing::Point(575, 151);
			this->listBox15MinVolDir2->Name = L"listBox15MinVolDir2";
			this->listBox15MinVolDir2->Size = System::Drawing::Size(106, 22);
			this->listBox15MinVolDir2->TabIndex = 203;
			this->listBox15MinVolDir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinVolDir2_SelectedIndexChanged);
			// 
			// textBox15MinVol2
			// 
			this->textBox15MinVol2->Location = System::Drawing::Point(759, 146);
			this->textBox15MinVol2->Name = L"textBox15MinVol2";
			this->textBox15MinVol2->Size = System::Drawing::Size(124, 26);
			this->textBox15MinVol2->TabIndex = 202;
			this->textBox15MinVol2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinVol2_TextChanged);
			// 
			// textBox15MinVol1
			// 
			this->textBox15MinVol1->Location = System::Drawing::Point(353, 151);
			this->textBox15MinVol1->Name = L"textBox15MinVol1";
			this->textBox15MinVol1->Size = System::Drawing::Size(124, 26);
			this->textBox15MinVol1->TabIndex = 200;
			this->textBox15MinVol1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinVol1_TextChanged);
			// 
			// label15MinVol2
			// 
			this->label15MinVol2->AutoSize = true;
			this->label15MinVol2->Location = System::Drawing::Point(695, 154);
			this->label15MinVol2->Name = L"label15MinVol2";
			this->label15MinVol2->Size = System::Drawing::Size(55, 18);
			this->label15MinVol2->TabIndex = 201;
			this->label15MinVol2->Text = L"VOL2:";
			// 
			// label15MinVol1
			// 
			this->label15MinVol1->AutoSize = true;
			this->label15MinVol1->Location = System::Drawing::Point(290, 156);
			this->label15MinVol1->Name = L"label15MinVol1";
			this->label15MinVol1->Size = System::Drawing::Size(54, 18);
			this->label15MinVol1->TabIndex = 199;
			this->label15MinVol1->Text = L"VOL1:";
			// 
			// label15MinVolDir1
			// 
			this->label15MinVolDir1->AutoSize = true;
			this->label15MinVolDir1->Location = System::Drawing::Point(79, 156);
			this->label15MinVolDir1->Name = L"label15MinVolDir1";
			this->label15MinVolDir1->Size = System::Drawing::Size(85, 18);
			this->label15MinVolDir1->TabIndex = 198;
			this->label15MinVolDir1->Text = L"Direction1:";
			// 
			// listBox15MinVolDir1
			// 
			this->listBox15MinVolDir1->FormattingEnabled = true;
			this->listBox15MinVolDir1->ItemHeight = 18;
			this->listBox15MinVolDir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinVolDir1->Location = System::Drawing::Point(170, 154);
			this->listBox15MinVolDir1->Name = L"listBox15MinVolDir1";
			this->listBox15MinVolDir1->Size = System::Drawing::Size(97, 22);
			this->listBox15MinVolDir1->TabIndex = 197;
			this->listBox15MinVolDir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinVolDir1_SelectedIndexChanged);
			// 
			// label15MinVol
			// 
			this->label15MinVol->AutoSize = true;
			this->label15MinVol->Location = System::Drawing::Point(26, 158);
			this->label15MinVol->Name = L"label15MinVol";
			this->label15MinVol->Size = System::Drawing::Size(46, 18);
			this->label15MinVol->TabIndex = 196;
			this->label15MinVol->Text = L"VOL:";
			// 
			// textBox15MinWr2
			// 
			this->textBox15MinWr2->Location = System::Drawing::Point(557, 382);
			this->textBox15MinWr2->Name = L"textBox15MinWr2";
			this->textBox15MinWr2->Size = System::Drawing::Size(124, 26);
			this->textBox15MinWr2->TabIndex = 195;
			this->textBox15MinWr2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinWr2_TextChanged);
			// 
			// textBox15MinWr1
			// 
			this->textBox15MinWr1->Location = System::Drawing::Point(353, 387);
			this->textBox15MinWr1->Name = L"textBox15MinWr1";
			this->textBox15MinWr1->Size = System::Drawing::Size(124, 26);
			this->textBox15MinWr1->TabIndex = 193;
			this->textBox15MinWr1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinWr1_TextChanged);
			// 
			// label15MinWr2
			// 
			this->label15MinWr2->AutoSize = true;
			this->label15MinWr2->Location = System::Drawing::Point(483, 390);
			this->label15MinWr2->Name = L"label15MinWr2";
			this->label15MinWr2->Size = System::Drawing::Size(48, 18);
			this->label15MinWr2->TabIndex = 194;
			this->label15MinWr2->Text = L"WR2:";
			// 
			// label15MinWr1
			// 
			this->label15MinWr1->AutoSize = true;
			this->label15MinWr1->Location = System::Drawing::Point(286, 394);
			this->label15MinWr1->Name = L"label15MinWr1";
			this->label15MinWr1->Size = System::Drawing::Size(47, 18);
			this->label15MinWr1->TabIndex = 192;
			this->label15MinWr1->Text = L"WR1:";
			// 
			// label15MinWrDir
			// 
			this->label15MinWrDir->AutoSize = true;
			this->label15MinWrDir->Location = System::Drawing::Point(87, 394);
			this->label15MinWrDir->Name = L"label15MinWrDir";
			this->label15MinWrDir->Size = System::Drawing::Size(77, 18);
			this->label15MinWrDir->TabIndex = 191;
			this->label15MinWrDir->Text = L"Direction:";
			// 
			// listBox15MinWrDir
			// 
			this->listBox15MinWrDir->FormattingEnabled = true;
			this->listBox15MinWrDir->ItemHeight = 18;
			this->listBox15MinWrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinWrDir->Location = System::Drawing::Point(170, 390);
			this->listBox15MinWrDir->Name = L"listBox15MinWrDir";
			this->listBox15MinWrDir->Size = System::Drawing::Size(97, 22);
			this->listBox15MinWrDir->TabIndex = 190;
			this->listBox15MinWrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinWrDir_SelectedIndexChanged);
			// 
			// label15MinWr
			// 
			this->label15MinWr->AutoSize = true;
			this->label15MinWr->Location = System::Drawing::Point(26, 394);
			this->label15MinWr->Name = L"label15MinWr";
			this->label15MinWr->Size = System::Drawing::Size(39, 18);
			this->label15MinWr->TabIndex = 189;
			this->label15MinWr->Text = L"WR:";
			// 
			// textBox15MinRsiLong
			// 
			this->textBox15MinRsiLong->Location = System::Drawing::Point(759, 335);
			this->textBox15MinRsiLong->Name = L"textBox15MinRsiLong";
			this->textBox15MinRsiLong->Size = System::Drawing::Size(124, 26);
			this->textBox15MinRsiLong->TabIndex = 188;
			this->textBox15MinRsiLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinRsiLong_TextChanged);
			// 
			// textBox15MinRsiMiddle
			// 
			this->textBox15MinRsiMiddle->Location = System::Drawing::Point(557, 335);
			this->textBox15MinRsiMiddle->Name = L"textBox15MinRsiMiddle";
			this->textBox15MinRsiMiddle->Size = System::Drawing::Size(124, 26);
			this->textBox15MinRsiMiddle->TabIndex = 186;
			this->textBox15MinRsiMiddle->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinRsiMiddle_TextChanged);
			// 
			// textBox15MinRsiShort
			// 
			this->textBox15MinRsiShort->Location = System::Drawing::Point(353, 340);
			this->textBox15MinRsiShort->Name = L"textBox15MinRsiShort";
			this->textBox15MinRsiShort->Size = System::Drawing::Size(124, 26);
			this->textBox15MinRsiShort->TabIndex = 184;
			this->textBox15MinRsiShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinRsiShort_TextChanged);
			// 
			// label15MinRsiLong
			// 
			this->label15MinRsiLong->AutoSize = true;
			this->label15MinRsiLong->Location = System::Drawing::Point(695, 340);
			this->label15MinRsiLong->Name = L"label15MinRsiLong";
			this->label15MinRsiLong->Size = System::Drawing::Size(48, 18);
			this->label15MinRsiLong->TabIndex = 187;
			this->label15MinRsiLong->Text = L"Long:";
			// 
			// label15MinRsiMiddle
			// 
			this->label15MinRsiMiddle->AutoSize = true;
			this->label15MinRsiMiddle->Location = System::Drawing::Point(483, 343);
			this->label15MinRsiMiddle->Name = L"label15MinRsiMiddle";
			this->label15MinRsiMiddle->Size = System::Drawing::Size(62, 18);
			this->label15MinRsiMiddle->TabIndex = 185;
			this->label15MinRsiMiddle->Text = L"Middle:";
			// 
			// label15MinRsiShort
			// 
			this->label15MinRsiShort->AutoSize = true;
			this->label15MinRsiShort->Location = System::Drawing::Point(286, 347);
			this->label15MinRsiShort->Name = L"label15MinRsiShort";
			this->label15MinRsiShort->Size = System::Drawing::Size(52, 18);
			this->label15MinRsiShort->TabIndex = 183;
			this->label15MinRsiShort->Text = L"Short:";
			// 
			// label15MinRsiDir
			// 
			this->label15MinRsiDir->AutoSize = true;
			this->label15MinRsiDir->Location = System::Drawing::Point(87, 347);
			this->label15MinRsiDir->Name = L"label15MinRsiDir";
			this->label15MinRsiDir->Size = System::Drawing::Size(77, 18);
			this->label15MinRsiDir->TabIndex = 182;
			this->label15MinRsiDir->Text = L"Direction:";
			// 
			// listBox15MinRsiDir
			// 
			this->listBox15MinRsiDir->FormattingEnabled = true;
			this->listBox15MinRsiDir->ItemHeight = 18;
			this->listBox15MinRsiDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinRsiDir->Location = System::Drawing::Point(170, 343);
			this->listBox15MinRsiDir->Name = L"listBox15MinRsiDir";
			this->listBox15MinRsiDir->Size = System::Drawing::Size(97, 22);
			this->listBox15MinRsiDir->TabIndex = 181;
			this->listBox15MinRsiDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinRsiDir_SelectedIndexChanged);
			// 
			// label15MinRsi
			// 
			this->label15MinRsi->AutoSize = true;
			this->label15MinRsi->Location = System::Drawing::Point(26, 347);
			this->label15MinRsi->Name = L"label15MinRsi";
			this->label15MinRsi->Size = System::Drawing::Size(40, 18);
			this->label15MinRsi->TabIndex = 180;
			this->label15MinRsi->Text = L"RSI:";
			// 
			// textBox15MinKdjJ
			// 
			this->textBox15MinKdjJ->Location = System::Drawing::Point(759, 290);
			this->textBox15MinKdjJ->Name = L"textBox15MinKdjJ";
			this->textBox15MinKdjJ->Size = System::Drawing::Size(124, 26);
			this->textBox15MinKdjJ->TabIndex = 179;
			this->textBox15MinKdjJ->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinKdjJ_TextChanged);
			// 
			// textBox15MinKdjD
			// 
			this->textBox15MinKdjD->Location = System::Drawing::Point(557, 290);
			this->textBox15MinKdjD->Name = L"textBox15MinKdjD";
			this->textBox15MinKdjD->Size = System::Drawing::Size(124, 26);
			this->textBox15MinKdjD->TabIndex = 177;
			this->textBox15MinKdjD->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinKdjD_TextChanged);
			// 
			// textBox15MinKdjK
			// 
			this->textBox15MinKdjK->Location = System::Drawing::Point(353, 295);
			this->textBox15MinKdjK->Name = L"textBox15MinKdjK";
			this->textBox15MinKdjK->Size = System::Drawing::Size(124, 26);
			this->textBox15MinKdjK->TabIndex = 175;
			this->textBox15MinKdjK->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinKdjK_TextChanged);
			// 
			// label15MinKdjJ
			// 
			this->label15MinKdjJ->AutoSize = true;
			this->label15MinKdjJ->Location = System::Drawing::Point(695, 298);
			this->label15MinKdjJ->Name = L"label15MinKdjJ";
			this->label15MinKdjJ->Size = System::Drawing::Size(21, 18);
			this->label15MinKdjJ->TabIndex = 178;
			this->label15MinKdjJ->Text = L"J:";
			// 
			// label15MinKdjD
			// 
			this->label15MinKdjD->AutoSize = true;
			this->label15MinKdjD->Location = System::Drawing::Point(500, 298);
			this->label15MinKdjD->Name = L"label15MinKdjD";
			this->label15MinKdjD->Size = System::Drawing::Size(24, 18);
			this->label15MinKdjD->TabIndex = 176;
			this->label15MinKdjD->Text = L"D:";
			// 
			// label15MinKdjK
			// 
			this->label15MinKdjK->AutoSize = true;
			this->label15MinKdjK->Location = System::Drawing::Point(290, 300);
			this->label15MinKdjK->Name = L"label15MinKdjK";
			this->label15MinKdjK->Size = System::Drawing::Size(24, 18);
			this->label15MinKdjK->TabIndex = 174;
			this->label15MinKdjK->Text = L"K:";
			// 
			// label15MinKdjDir
			// 
			this->label15MinKdjDir->AutoSize = true;
			this->label15MinKdjDir->Location = System::Drawing::Point(87, 302);
			this->label15MinKdjDir->Name = L"label15MinKdjDir";
			this->label15MinKdjDir->Size = System::Drawing::Size(77, 18);
			this->label15MinKdjDir->TabIndex = 173;
			this->label15MinKdjDir->Text = L"Direction:";
			// 
			// listBox15MinKdjDir
			// 
			this->listBox15MinKdjDir->FormattingEnabled = true;
			this->listBox15MinKdjDir->ItemHeight = 18;
			this->listBox15MinKdjDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinKdjDir->Location = System::Drawing::Point(170, 298);
			this->listBox15MinKdjDir->Name = L"listBox15MinKdjDir";
			this->listBox15MinKdjDir->Size = System::Drawing::Size(97, 22);
			this->listBox15MinKdjDir->TabIndex = 172;
			this->listBox15MinKdjDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinKdjDir_SelectedIndexChanged);
			// 
			// label15MinKdj
			// 
			this->label15MinKdj->AutoSize = true;
			this->label15MinKdj->Location = System::Drawing::Point(26, 302);
			this->label15MinKdj->Name = L"label15MinKdj";
			this->label15MinKdj->Size = System::Drawing::Size(43, 18);
			this->label15MinKdj->TabIndex = 171;
			this->label15MinKdj->Text = L"KDJ:";
			// 
			// textBox15MinMacdDea
			// 
			this->textBox15MinMacdDea->Location = System::Drawing::Point(759, 243);
			this->textBox15MinMacdDea->Name = L"textBox15MinMacdDea";
			this->textBox15MinMacdDea->Size = System::Drawing::Size(124, 26);
			this->textBox15MinMacdDea->TabIndex = 170;
			this->textBox15MinMacdDea->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinMacdDea_TextChanged);
			// 
			// textBox15MinMacdDif
			// 
			this->textBox15MinMacdDif->Location = System::Drawing::Point(557, 243);
			this->textBox15MinMacdDif->Name = L"textBox15MinMacdDif";
			this->textBox15MinMacdDif->Size = System::Drawing::Size(124, 26);
			this->textBox15MinMacdDif->TabIndex = 168;
			this->textBox15MinMacdDif->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinMacdDif_TextChanged);
			// 
			// textBox15MinMacdMacd
			// 
			this->textBox15MinMacdMacd->Location = System::Drawing::Point(353, 248);
			this->textBox15MinMacdMacd->Name = L"textBox15MinMacdMacd";
			this->textBox15MinMacdMacd->Size = System::Drawing::Size(124, 26);
			this->textBox15MinMacdMacd->TabIndex = 166;
			this->textBox15MinMacdMacd->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinMacdMacd_TextChanged);
			// 
			// label15MinMacdDea
			// 
			this->label15MinMacdDea->AutoSize = true;
			this->label15MinMacdDea->Location = System::Drawing::Point(695, 251);
			this->label15MinMacdDea->Name = L"label15MinMacdDea";
			this->label15MinMacdDea->Size = System::Drawing::Size(40, 18);
			this->label15MinMacdDea->TabIndex = 169;
			this->label15MinMacdDea->Text = L"Dea:";
			// 
			// label15MinMacdDif
			// 
			this->label15MinMacdDif->AutoSize = true;
			this->label15MinMacdDif->Location = System::Drawing::Point(500, 251);
			this->label15MinMacdDif->Name = L"label15MinMacdDif";
			this->label15MinMacdDif->Size = System::Drawing::Size(33, 18);
			this->label15MinMacdDif->TabIndex = 167;
			this->label15MinMacdDif->Text = L"Dif:";
			// 
			// label15MinMacdMacd
			// 
			this->label15MinMacdMacd->AutoSize = true;
			this->label15MinMacdMacd->Location = System::Drawing::Point(290, 253);
			this->label15MinMacdMacd->Name = L"label15MinMacdMacd";
			this->label15MinMacdMacd->Size = System::Drawing::Size(52, 18);
			this->label15MinMacdMacd->TabIndex = 165;
			this->label15MinMacdMacd->Text = L"Macd:";
			// 
			// label15MinMacdDir
			// 
			this->label15MinMacdDir->AutoSize = true;
			this->label15MinMacdDir->Location = System::Drawing::Point(87, 255);
			this->label15MinMacdDir->Name = L"label15MinMacdDir";
			this->label15MinMacdDir->Size = System::Drawing::Size(77, 18);
			this->label15MinMacdDir->TabIndex = 164;
			this->label15MinMacdDir->Text = L"Direction:";
			// 
			// listBox15MinMacdDir
			// 
			this->listBox15MinMacdDir->FormattingEnabled = true;
			this->listBox15MinMacdDir->ItemHeight = 18;
			this->listBox15MinMacdDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinMacdDir->Location = System::Drawing::Point(170, 251);
			this->listBox15MinMacdDir->Name = L"listBox15MinMacdDir";
			this->listBox15MinMacdDir->Size = System::Drawing::Size(97, 22);
			this->listBox15MinMacdDir->TabIndex = 163;
			this->listBox15MinMacdDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinMacdDir_SelectedIndexChanged);
			// 
			// label15MinMacd
			// 
			this->label15MinMacd->AutoSize = true;
			this->label15MinMacd->Location = System::Drawing::Point(26, 255);
			this->label15MinMacd->Name = L"label15MinMacd";
			this->label15MinMacd->Size = System::Drawing::Size(60, 18);
			this->label15MinMacd->TabIndex = 162;
			this->label15MinMacd->Text = L"MACD:";
			// 
			// textBox15MinBollUpper
			// 
			this->textBox15MinBollUpper->Location = System::Drawing::Point(759, 196);
			this->textBox15MinBollUpper->Name = L"textBox15MinBollUpper";
			this->textBox15MinBollUpper->Size = System::Drawing::Size(124, 26);
			this->textBox15MinBollUpper->TabIndex = 161;
			this->textBox15MinBollUpper->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinBollUpper_TextChanged);
			// 
			// textBox15MinBollMid
			// 
			this->textBox15MinBollMid->Location = System::Drawing::Point(557, 198);
			this->textBox15MinBollMid->Name = L"textBox15MinBollMid";
			this->textBox15MinBollMid->Size = System::Drawing::Size(124, 26);
			this->textBox15MinBollMid->TabIndex = 159;
			this->textBox15MinBollMid->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinBollMid_TextChanged);
			// 
			// textBox15MinBollLow
			// 
			this->textBox15MinBollLow->Location = System::Drawing::Point(353, 200);
			this->textBox15MinBollLow->Name = L"textBox15MinBollLow";
			this->textBox15MinBollLow->Size = System::Drawing::Size(124, 26);
			this->textBox15MinBollLow->TabIndex = 157;
			this->textBox15MinBollLow->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox15MinBollLow_TextChanged);
			// 
			// label15MinBollUpper
			// 
			this->label15MinBollUpper->AutoSize = true;
			this->label15MinBollUpper->Location = System::Drawing::Point(695, 202);
			this->label15MinBollUpper->Name = L"label15MinBollUpper";
			this->label15MinBollUpper->Size = System::Drawing::Size(58, 18);
			this->label15MinBollUpper->TabIndex = 160;
			this->label15MinBollUpper->Text = L"Upper:";
			// 
			// label15MinBollMid
			// 
			this->label15MinBollMid->AutoSize = true;
			this->label15MinBollMid->Location = System::Drawing::Point(500, 204);
			this->label15MinBollMid->Name = L"label15MinBollMid";
			this->label15MinBollMid->Size = System::Drawing::Size(41, 18);
			this->label15MinBollMid->TabIndex = 158;
			this->label15MinBollMid->Text = L"Mid:";
			// 
			// label15MinBollLow
			// 
			this->label15MinBollLow->AutoSize = true;
			this->label15MinBollLow->Location = System::Drawing::Point(295, 206);
			this->label15MinBollLow->Name = L"label15MinBollLow";
			this->label15MinBollLow->Size = System::Drawing::Size(43, 18);
			this->label15MinBollLow->TabIndex = 156;
			this->label15MinBollLow->Text = L"Low:";
			// 
			// label15MinBollDir
			// 
			this->label15MinBollDir->AutoSize = true;
			this->label15MinBollDir->Location = System::Drawing::Point(87, 206);
			this->label15MinBollDir->Name = L"label15MinBollDir";
			this->label15MinBollDir->Size = System::Drawing::Size(77, 18);
			this->label15MinBollDir->TabIndex = 155;
			this->label15MinBollDir->Text = L"Direction:";
			// 
			// listBox15MinBollDir
			// 
			this->listBox15MinBollDir->FormattingEnabled = true;
			this->listBox15MinBollDir->ItemHeight = 18;
			this->listBox15MinBollDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox15MinBollDir->Location = System::Drawing::Point(170, 204);
			this->listBox15MinBollDir->Name = L"listBox15MinBollDir";
			this->listBox15MinBollDir->Size = System::Drawing::Size(97, 22);
			this->listBox15MinBollDir->TabIndex = 154;
			this->listBox15MinBollDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox15MinBollDir_SelectedIndexChanged);
			// 
			// label15MinBoll
			// 
			this->label15MinBoll->AutoSize = true;
			this->label15MinBoll->Location = System::Drawing::Point(26, 210);
			this->label15MinBoll->Name = L"label15MinBoll";
			this->label15MinBoll->Size = System::Drawing::Size(55, 18);
			this->label15MinBoll->TabIndex = 153;
			this->label15MinBoll->Text = L"BOLL:";
			// 
			// tab30Min
			// 
			this->tab30Min->Controls->Add(this->listBox30MinMADir6);
			this->tab30Min->Controls->Add(this->label30MinMADir6);
			this->tab30Min->Controls->Add(this->textBox30MinMA6);
			this->tab30Min->Controls->Add(this->textBox30MinMA5);
			this->tab30Min->Controls->Add(this->label30MinMA6);
			this->tab30Min->Controls->Add(this->label30MinMA5);
			this->tab30Min->Controls->Add(this->label30MinMADir5);
			this->tab30Min->Controls->Add(this->listBox30MinMADir5);
			this->tab30Min->Controls->Add(this->label30MinMA56);
			this->tab30Min->Controls->Add(this->label30MinMADir4);
			this->tab30Min->Controls->Add(this->listBox30MinMADir4);
			this->tab30Min->Controls->Add(this->textBox30MinMA4);
			this->tab30Min->Controls->Add(this->textBox30MinMA3);
			this->tab30Min->Controls->Add(this->label30MinMA4);
			this->tab30Min->Controls->Add(this->label30MinMA3);
			this->tab30Min->Controls->Add(this->label30MinMADir3);
			this->tab30Min->Controls->Add(this->listBox30MinMADir3);
			this->tab30Min->Controls->Add(this->label30MinMA34);
			this->tab30Min->Controls->Add(this->label30MinMADir2);
			this->tab30Min->Controls->Add(this->listBox30MinMADir2);
			this->tab30Min->Controls->Add(this->textBox30MinMA2);
			this->tab30Min->Controls->Add(this->textBox30MinMA1);
			this->tab30Min->Controls->Add(this->label30MinMA2);
			this->tab30Min->Controls->Add(this->label30MinMA1);
			this->tab30Min->Controls->Add(this->label30MinMADir1);
			this->tab30Min->Controls->Add(this->listBox30MinMADir1);
			this->tab30Min->Controls->Add(this->label30MinMA12);
			this->tab30Min->Controls->Add(this->textBox30MinCciCci);
			this->tab30Min->Controls->Add(this->label30MinCciCci);
			this->tab30Min->Controls->Add(this->label30MinCciDir);
			this->tab30Min->Controls->Add(this->listBox30MinCciDir);
			this->tab30Min->Controls->Add(this->label30MinCci);
			this->tab30Min->Controls->Add(this->textBox30MinCrC);
			this->tab30Min->Controls->Add(this->label30MinCrC);
			this->tab30Min->Controls->Add(this->textBox30MinCrB);
			this->tab30Min->Controls->Add(this->label30MinCrB);
			this->tab30Min->Controls->Add(this->textBox30MinCrA);
			this->tab30Min->Controls->Add(this->textBox30MinCrCr);
			this->tab30Min->Controls->Add(this->label30MinCrA);
			this->tab30Min->Controls->Add(this->label30MinCrCr);
			this->tab30Min->Controls->Add(this->label30MinCrDir);
			this->tab30Min->Controls->Add(this->listBox30MinCrDir);
			this->tab30Min->Controls->Add(this->label30MinCr);
			this->tab30Min->Controls->Add(this->textBox30MinDmaAma);
			this->tab30Min->Controls->Add(this->textBox30MinDmaDma);
			this->tab30Min->Controls->Add(this->label30MinDmaAma);
			this->tab30Min->Controls->Add(this->label30MinDmaDma);
			this->tab30Min->Controls->Add(this->label30MinDmaDir);
			this->tab30Min->Controls->Add(this->listBox30MinDmaDir);
			this->tab30Min->Controls->Add(this->label30MinDma);
			this->tab30Min->Controls->Add(this->textBox30MinRocRocma);
			this->tab30Min->Controls->Add(this->textBox30MinRocRoc);
			this->tab30Min->Controls->Add(this->label30MinRocRocma);
			this->tab30Min->Controls->Add(this->label30MinRocRoc);
			this->tab30Min->Controls->Add(this->label30MinRocDir);
			this->tab30Min->Controls->Add(this->listBox30MinRocDir);
			this->tab30Min->Controls->Add(this->label30MinRoc);
			this->tab30Min->Controls->Add(this->textBox30MinVrLong);
			this->tab30Min->Controls->Add(this->textBox30MinVrShort);
			this->tab30Min->Controls->Add(this->label30MinVrLong);
			this->tab30Min->Controls->Add(this->label30MinVrShort);
			this->tab30Min->Controls->Add(this->label30MinVrDir);
			this->tab30Min->Controls->Add(this->listBox30MinVrDir);
			this->tab30Min->Controls->Add(this->label30MinVr);
			this->tab30Min->Controls->Add(this->label30MinVolDir2);
			this->tab30Min->Controls->Add(this->listBox30MinVolDir2);
			this->tab30Min->Controls->Add(this->textBox30MinVol2);
			this->tab30Min->Controls->Add(this->textBox30MinVol1);
			this->tab30Min->Controls->Add(this->label30MinVol2);
			this->tab30Min->Controls->Add(this->label30MinVol1);
			this->tab30Min->Controls->Add(this->label30MinVolDir1);
			this->tab30Min->Controls->Add(this->listBox30MinVolDir1);
			this->tab30Min->Controls->Add(this->label30MinVol);
			this->tab30Min->Controls->Add(this->textBox30MinWr2);
			this->tab30Min->Controls->Add(this->textBox30MinWr1);
			this->tab30Min->Controls->Add(this->label30MinWr2);
			this->tab30Min->Controls->Add(this->label30MinWr1);
			this->tab30Min->Controls->Add(this->label30MinWrDir);
			this->tab30Min->Controls->Add(this->listBox30MinWrDir);
			this->tab30Min->Controls->Add(this->label30MinWr);
			this->tab30Min->Controls->Add(this->textBox30MinRsiLong);
			this->tab30Min->Controls->Add(this->textBox30MinRsiMiddle);
			this->tab30Min->Controls->Add(this->textBox30MinRsiShort);
			this->tab30Min->Controls->Add(this->label30MinRsiLong);
			this->tab30Min->Controls->Add(this->label30MinRsiMiddle);
			this->tab30Min->Controls->Add(this->label30MinRsiShort);
			this->tab30Min->Controls->Add(this->label30MinRsiDir);
			this->tab30Min->Controls->Add(this->listBox30MinRsiDir);
			this->tab30Min->Controls->Add(this->label30MinRsi);
			this->tab30Min->Controls->Add(this->textBox30MinKdjJ);
			this->tab30Min->Controls->Add(this->textBox30MinKdjD);
			this->tab30Min->Controls->Add(this->textBox30MinKdjK);
			this->tab30Min->Controls->Add(this->label30MinKdjJ);
			this->tab30Min->Controls->Add(this->label30MinKdjD);
			this->tab30Min->Controls->Add(this->label30MinKdjK);
			this->tab30Min->Controls->Add(this->label30MinKdjDir);
			this->tab30Min->Controls->Add(this->listBox30MinKdjDir);
			this->tab30Min->Controls->Add(this->label30MinKdj);
			this->tab30Min->Controls->Add(this->textBox30MinMacdDea);
			this->tab30Min->Controls->Add(this->textBox30MinMacdDif);
			this->tab30Min->Controls->Add(this->textBox30MinMacdMacd);
			this->tab30Min->Controls->Add(this->label30MinMacdDea);
			this->tab30Min->Controls->Add(this->label30MinMacdDif);
			this->tab30Min->Controls->Add(this->label30MinMacdMacd);
			this->tab30Min->Controls->Add(this->label30MinMacdDir);
			this->tab30Min->Controls->Add(this->listBox30MinMacdDir);
			this->tab30Min->Controls->Add(this->label30MinMacd);
			this->tab30Min->Controls->Add(this->textBox30MinBollUpper);
			this->tab30Min->Controls->Add(this->textBox30MinBollMid);
			this->tab30Min->Controls->Add(this->textBox30MinBollLow);
			this->tab30Min->Controls->Add(this->label30MinBollUpper);
			this->tab30Min->Controls->Add(this->label30MinBollMid);
			this->tab30Min->Controls->Add(this->label30MinBollLow);
			this->tab30Min->Controls->Add(this->label30MinBollDir);
			this->tab30Min->Controls->Add(this->listBox30MinBollDir);
			this->tab30Min->Controls->Add(this->label30MinBoll);
			this->tab30Min->Location = System::Drawing::Point(4, 27);
			this->tab30Min->Name = L"tab30Min";
			this->tab30Min->Padding = System::Windows::Forms::Padding(3);
			this->tab30Min->Size = System::Drawing::Size(1092, 869);
			this->tab30Min->TabIndex = 7;
			this->tab30Min->Text = L"30Min";
			this->tab30Min->UseVisualStyleBackColor = true;
			// 
			// listBox30MinMADir6
			// 
			this->listBox30MinMADir6->FormattingEnabled = true;
			this->listBox30MinMADir6->ItemHeight = 18;
			this->listBox30MinMADir6->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinMADir6->Location = System::Drawing::Point(575, 103);
			this->listBox30MinMADir6->Name = L"listBox30MinMADir6";
			this->listBox30MinMADir6->Size = System::Drawing::Size(106, 22);
			this->listBox30MinMADir6->TabIndex = 269;
			this->listBox30MinMADir6->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinMADir6_SelectedIndexChanged);
			// 
			// label30MinMADir6
			// 
			this->label30MinMADir6->AutoSize = true;
			this->label30MinMADir6->Location = System::Drawing::Point(483, 107);
			this->label30MinMADir6->Name = L"label30MinMADir6";
			this->label30MinMADir6->Size = System::Drawing::Size(80, 18);
			this->label30MinMADir6->TabIndex = 268;
			this->label30MinMADir6->Text = L"MA_Dir6:";
			// 
			// textBox30MinMA6
			// 
			this->textBox30MinMA6->Location = System::Drawing::Point(759, 99);
			this->textBox30MinMA6->Name = L"textBox30MinMA6";
			this->textBox30MinMA6->Size = System::Drawing::Size(124, 26);
			this->textBox30MinMA6->TabIndex = 266;
			this->textBox30MinMA6->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinMA6_TextChanged);
			// 
			// textBox30MinMA5
			// 
			this->textBox30MinMA5->Location = System::Drawing::Point(353, 104);
			this->textBox30MinMA5->Name = L"textBox30MinMA5";
			this->textBox30MinMA5->Size = System::Drawing::Size(124, 26);
			this->textBox30MinMA5->TabIndex = 264;
			this->textBox30MinMA5->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinMA5_TextChanged);
			// 
			// label30MinMA6
			// 
			this->label30MinMA6->AutoSize = true;
			this->label30MinMA6->Location = System::Drawing::Point(695, 107);
			this->label30MinMA6->Name = L"label30MinMA6";
			this->label30MinMA6->Size = System::Drawing::Size(48, 18);
			this->label30MinMA6->TabIndex = 265;
			this->label30MinMA6->Text = L"MA6:";
			// 
			// label30MinMA5
			// 
			this->label30MinMA5->AutoSize = true;
			this->label30MinMA5->Location = System::Drawing::Point(290, 109);
			this->label30MinMA5->Name = L"label30MinMA5";
			this->label30MinMA5->Size = System::Drawing::Size(48, 18);
			this->label30MinMA5->TabIndex = 263;
			this->label30MinMA5->Text = L"MA5:";
			// 
			// label30MinMADir5
			// 
			this->label30MinMADir5->AutoSize = true;
			this->label30MinMADir5->Location = System::Drawing::Point(79, 112);
			this->label30MinMADir5->Name = L"label30MinMADir5";
			this->label30MinMADir5->Size = System::Drawing::Size(80, 18);
			this->label30MinMADir5->TabIndex = 262;
			this->label30MinMADir5->Text = L"MA_Dir5:";
			// 
			// listBox30MinMADir5
			// 
			this->listBox30MinMADir5->FormattingEnabled = true;
			this->listBox30MinMADir5->ItemHeight = 18;
			this->listBox30MinMADir5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinMADir5->Location = System::Drawing::Point(170, 107);
			this->listBox30MinMADir5->Name = L"listBox30MinMADir5";
			this->listBox30MinMADir5->Size = System::Drawing::Size(97, 22);
			this->listBox30MinMADir5->TabIndex = 261;
			this->listBox30MinMADir5->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinMADir5_SelectedIndexChanged);
			// 
			// label30MinMA56
			// 
			this->label30MinMA56->AutoSize = true;
			this->label30MinMA56->Location = System::Drawing::Point(17, 112);
			this->label30MinMA56->Name = L"label30MinMA56";
			this->label30MinMA56->Size = System::Drawing::Size(64, 18);
			this->label30MinMA56->TabIndex = 260;
			this->label30MinMA56->Text = L"MA5-6:";
			// 
			// label30MinMADir4
			// 
			this->label30MinMADir4->AutoSize = true;
			this->label30MinMADir4->Location = System::Drawing::Point(483, 60);
			this->label30MinMADir4->Name = L"label30MinMADir4";
			this->label30MinMADir4->Size = System::Drawing::Size(80, 18);
			this->label30MinMADir4->TabIndex = 259;
			this->label30MinMADir4->Text = L"MA_Dir4:";
			// 
			// listBox30MinMADir4
			// 
			this->listBox30MinMADir4->FormattingEnabled = true;
			this->listBox30MinMADir4->ItemHeight = 18;
			this->listBox30MinMADir4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinMADir4->Location = System::Drawing::Point(575, 57);
			this->listBox30MinMADir4->Name = L"listBox30MinMADir4";
			this->listBox30MinMADir4->Size = System::Drawing::Size(106, 22);
			this->listBox30MinMADir4->TabIndex = 258;
			this->listBox30MinMADir4->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinMADir4_SelectedIndexChanged);
			// 
			// textBox30MinMA4
			// 
			this->textBox30MinMA4->Location = System::Drawing::Point(759, 52);
			this->textBox30MinMA4->Name = L"textBox30MinMA4";
			this->textBox30MinMA4->Size = System::Drawing::Size(124, 26);
			this->textBox30MinMA4->TabIndex = 257;
			this->textBox30MinMA4->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinMA4_TextChanged);
			// 
			// textBox30MinMA3
			// 
			this->textBox30MinMA3->Location = System::Drawing::Point(353, 57);
			this->textBox30MinMA3->Name = L"textBox30MinMA3";
			this->textBox30MinMA3->Size = System::Drawing::Size(124, 26);
			this->textBox30MinMA3->TabIndex = 255;
			this->textBox30MinMA3->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinMA3_TextChanged);
			// 
			// label30MinMA4
			// 
			this->label30MinMA4->AutoSize = true;
			this->label30MinMA4->Location = System::Drawing::Point(695, 60);
			this->label30MinMA4->Name = L"label30MinMA4";
			this->label30MinMA4->Size = System::Drawing::Size(48, 18);
			this->label30MinMA4->TabIndex = 256;
			this->label30MinMA4->Text = L"MA4:";
			// 
			// label30MinMA3
			// 
			this->label30MinMA3->AutoSize = true;
			this->label30MinMA3->Location = System::Drawing::Point(290, 62);
			this->label30MinMA3->Name = L"label30MinMA3";
			this->label30MinMA3->Size = System::Drawing::Size(48, 18);
			this->label30MinMA3->TabIndex = 254;
			this->label30MinMA3->Text = L"MA3:";
			// 
			// label30MinMADir3
			// 
			this->label30MinMADir3->AutoSize = true;
			this->label30MinMADir3->Location = System::Drawing::Point(79, 65);
			this->label30MinMADir3->Name = L"label30MinMADir3";
			this->label30MinMADir3->Size = System::Drawing::Size(80, 18);
			this->label30MinMADir3->TabIndex = 253;
			this->label30MinMADir3->Text = L"MA_Dir3:";
			// 
			// listBox30MinMADir3
			// 
			this->listBox30MinMADir3->FormattingEnabled = true;
			this->listBox30MinMADir3->ItemHeight = 18;
			this->listBox30MinMADir3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinMADir3->Location = System::Drawing::Point(170, 60);
			this->listBox30MinMADir3->Name = L"listBox30MinMADir3";
			this->listBox30MinMADir3->Size = System::Drawing::Size(97, 22);
			this->listBox30MinMADir3->TabIndex = 252;
			this->listBox30MinMADir3->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinMADir3_SelectedIndexChanged);
			// 
			// label30MinMA34
			// 
			this->label30MinMA34->AutoSize = true;
			this->label30MinMA34->Location = System::Drawing::Point(17, 65);
			this->label30MinMA34->Name = L"label30MinMA34";
			this->label30MinMA34->Size = System::Drawing::Size(64, 18);
			this->label30MinMA34->TabIndex = 251;
			this->label30MinMA34->Text = L"MA3-4:";
			// 
			// label30MinMADir2
			// 
			this->label30MinMADir2->AutoSize = true;
			this->label30MinMADir2->Location = System::Drawing::Point(483, 19);
			this->label30MinMADir2->Name = L"label30MinMADir2";
			this->label30MinMADir2->Size = System::Drawing::Size(80, 18);
			this->label30MinMADir2->TabIndex = 250;
			this->label30MinMADir2->Text = L"MA_Dir2:";
			// 
			// listBox30MinMADir2
			// 
			this->listBox30MinMADir2->FormattingEnabled = true;
			this->listBox30MinMADir2->ItemHeight = 18;
			this->listBox30MinMADir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinMADir2->Location = System::Drawing::Point(575, 16);
			this->listBox30MinMADir2->Name = L"listBox30MinMADir2";
			this->listBox30MinMADir2->Size = System::Drawing::Size(106, 22);
			this->listBox30MinMADir2->TabIndex = 249;
			this->listBox30MinMADir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinMADir2_SelectedIndexChanged);
			// 
			// textBox30MinMA2
			// 
			this->textBox30MinMA2->Location = System::Drawing::Point(759, 11);
			this->textBox30MinMA2->Name = L"textBox30MinMA2";
			this->textBox30MinMA2->Size = System::Drawing::Size(124, 26);
			this->textBox30MinMA2->TabIndex = 248;
			this->textBox30MinMA2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinMA2_TextChanged);
			// 
			// textBox30MinMA1
			// 
			this->textBox30MinMA1->Location = System::Drawing::Point(353, 16);
			this->textBox30MinMA1->Name = L"textBox30MinMA1";
			this->textBox30MinMA1->Size = System::Drawing::Size(124, 26);
			this->textBox30MinMA1->TabIndex = 246;
			this->textBox30MinMA1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinMA1_TextChanged);
			// 
			// label30MinMA2
			// 
			this->label30MinMA2->AutoSize = true;
			this->label30MinMA2->Location = System::Drawing::Point(695, 19);
			this->label30MinMA2->Name = L"label30MinMA2";
			this->label30MinMA2->Size = System::Drawing::Size(48, 18);
			this->label30MinMA2->TabIndex = 247;
			this->label30MinMA2->Text = L"MA2:";
			// 
			// label30MinMA1
			// 
			this->label30MinMA1->AutoSize = true;
			this->label30MinMA1->Location = System::Drawing::Point(290, 21);
			this->label30MinMA1->Name = L"label30MinMA1";
			this->label30MinMA1->Size = System::Drawing::Size(47, 18);
			this->label30MinMA1->TabIndex = 245;
			this->label30MinMA1->Text = L"MA1:";
			// 
			// label30MinMADir1
			// 
			this->label30MinMADir1->AutoSize = true;
			this->label30MinMADir1->Location = System::Drawing::Point(79, 21);
			this->label30MinMADir1->Name = L"label30MinMADir1";
			this->label30MinMADir1->Size = System::Drawing::Size(79, 18);
			this->label30MinMADir1->TabIndex = 244;
			this->label30MinMADir1->Text = L"MA_Dir1:";
			// 
			// listBox30MinMADir1
			// 
			this->listBox30MinMADir1->FormattingEnabled = true;
			this->listBox30MinMADir1->ItemHeight = 18;
			this->listBox30MinMADir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinMADir1->Location = System::Drawing::Point(170, 19);
			this->listBox30MinMADir1->Name = L"listBox30MinMADir1";
			this->listBox30MinMADir1->Size = System::Drawing::Size(97, 22);
			this->listBox30MinMADir1->TabIndex = 243;
			this->listBox30MinMADir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinMADir1_SelectedIndexChanged);
			// 
			// label30MinMA12
			// 
			this->label30MinMA12->AutoSize = true;
			this->label30MinMA12->Location = System::Drawing::Point(16, 24);
			this->label30MinMA12->Name = L"label30MinMA12";
			this->label30MinMA12->Size = System::Drawing::Size(63, 18);
			this->label30MinMA12->TabIndex = 242;
			this->label30MinMA12->Text = L"MA1-2:";
			// 
			// textBox30MinCciCci
			// 
			this->textBox30MinCciCci->Location = System::Drawing::Point(353, 601);
			this->textBox30MinCciCci->Name = L"textBox30MinCciCci";
			this->textBox30MinCciCci->Size = System::Drawing::Size(124, 26);
			this->textBox30MinCciCci->TabIndex = 241;
			this->textBox30MinCciCci->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinCciCci_TextChanged);
			// 
			// label30MinCciCci
			// 
			this->label30MinCciCci->AutoSize = true;
			this->label30MinCciCci->Location = System::Drawing::Point(286, 608);
			this->label30MinCciCci->Name = L"label30MinCciCci";
			this->label30MinCciCci->Size = System::Drawing::Size(34, 18);
			this->label30MinCciCci->TabIndex = 240;
			this->label30MinCciCci->Text = L"Cci:";
			// 
			// label30MinCciDir
			// 
			this->label30MinCciDir->AutoSize = true;
			this->label30MinCciDir->Location = System::Drawing::Point(87, 608);
			this->label30MinCciDir->Name = L"label30MinCciDir";
			this->label30MinCciDir->Size = System::Drawing::Size(77, 18);
			this->label30MinCciDir->TabIndex = 239;
			this->label30MinCciDir->Text = L"Direction:";
			// 
			// listBox30MinCciDir
			// 
			this->listBox30MinCciDir->FormattingEnabled = true;
			this->listBox30MinCciDir->ItemHeight = 18;
			this->listBox30MinCciDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinCciDir->Location = System::Drawing::Point(170, 604);
			this->listBox30MinCciDir->Name = L"listBox30MinCciDir";
			this->listBox30MinCciDir->Size = System::Drawing::Size(97, 22);
			this->listBox30MinCciDir->TabIndex = 238;
			this->listBox30MinCciDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinCciDir_SelectedIndexChanged);
			// 
			// label30MinCci
			// 
			this->label30MinCci->AutoSize = true;
			this->label30MinCci->Location = System::Drawing::Point(26, 608);
			this->label30MinCci->Name = L"label30MinCci";
			this->label30MinCci->Size = System::Drawing::Size(40, 18);
			this->label30MinCci->TabIndex = 237;
			this->label30MinCci->Text = L"CCI:";
			// 
			// textBox30MinCrC
			// 
			this->textBox30MinCrC->Location = System::Drawing::Point(961, 555);
			this->textBox30MinCrC->Name = L"textBox30MinCrC";
			this->textBox30MinCrC->Size = System::Drawing::Size(124, 26);
			this->textBox30MinCrC->TabIndex = 236;
			this->textBox30MinCrC->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinCrC_TextChanged);
			// 
			// label30MinCrC
			// 
			this->label30MinCrC->AutoSize = true;
			this->label30MinCrC->Location = System::Drawing::Point(900, 563);
			this->label30MinCrC->Name = L"label30MinCrC";
			this->label30MinCrC->Size = System::Drawing::Size(23, 18);
			this->label30MinCrC->TabIndex = 235;
			this->label30MinCrC->Text = L"C:";
			// 
			// textBox30MinCrB
			// 
			this->textBox30MinCrB->Location = System::Drawing::Point(755, 555);
			this->textBox30MinCrB->Name = L"textBox30MinCrB";
			this->textBox30MinCrB->Size = System::Drawing::Size(124, 26);
			this->textBox30MinCrB->TabIndex = 234;
			this->textBox30MinCrB->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinCrB_TextChanged);
			// 
			// label30MinCrB
			// 
			this->label30MinCrB->AutoSize = true;
			this->label30MinCrB->Location = System::Drawing::Point(694, 563);
			this->label30MinCrB->Name = L"label30MinCrB";
			this->label30MinCrB->Size = System::Drawing::Size(23, 18);
			this->label30MinCrB->TabIndex = 233;
			this->label30MinCrB->Text = L"B:";
			// 
			// textBox30MinCrA
			// 
			this->textBox30MinCrA->Location = System::Drawing::Point(557, 555);
			this->textBox30MinCrA->Name = L"textBox30MinCrA";
			this->textBox30MinCrA->Size = System::Drawing::Size(124, 26);
			this->textBox30MinCrA->TabIndex = 232;
			this->textBox30MinCrA->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinCrA_TextChanged);
			// 
			// textBox30MinCrCr
			// 
			this->textBox30MinCrCr->Location = System::Drawing::Point(353, 560);
			this->textBox30MinCrCr->Name = L"textBox30MinCrCr";
			this->textBox30MinCrCr->Size = System::Drawing::Size(124, 26);
			this->textBox30MinCrCr->TabIndex = 230;
			this->textBox30MinCrCr->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinCrCr_TextChanged);
			// 
			// label30MinCrA
			// 
			this->label30MinCrA->AutoSize = true;
			this->label30MinCrA->Location = System::Drawing::Point(496, 563);
			this->label30MinCrA->Name = L"label30MinCrA";
			this->label30MinCrA->Size = System::Drawing::Size(24, 18);
			this->label30MinCrA->TabIndex = 231;
			this->label30MinCrA->Text = L"A:";
			// 
			// label30MinCrCr
			// 
			this->label30MinCrCr->AutoSize = true;
			this->label30MinCrCr->Location = System::Drawing::Point(286, 567);
			this->label30MinCrCr->Name = L"label30MinCrCr";
			this->label30MinCrCr->Size = System::Drawing::Size(30, 18);
			this->label30MinCrCr->TabIndex = 229;
			this->label30MinCrCr->Text = L"Cr:";
			// 
			// label30MinCrDir
			// 
			this->label30MinCrDir->AutoSize = true;
			this->label30MinCrDir->Location = System::Drawing::Point(87, 567);
			this->label30MinCrDir->Name = L"label30MinCrDir";
			this->label30MinCrDir->Size = System::Drawing::Size(77, 18);
			this->label30MinCrDir->TabIndex = 228;
			this->label30MinCrDir->Text = L"Direction:";
			// 
			// listBox30MinCrDir
			// 
			this->listBox30MinCrDir->FormattingEnabled = true;
			this->listBox30MinCrDir->ItemHeight = 18;
			this->listBox30MinCrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinCrDir->Location = System::Drawing::Point(170, 563);
			this->listBox30MinCrDir->Name = L"listBox30MinCrDir";
			this->listBox30MinCrDir->Size = System::Drawing::Size(97, 22);
			this->listBox30MinCrDir->TabIndex = 227;
			this->listBox30MinCrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinCrDir_SelectedIndexChanged);
			// 
			// label30MinCr
			// 
			this->label30MinCr->AutoSize = true;
			this->label30MinCr->Location = System::Drawing::Point(26, 567);
			this->label30MinCr->Name = L"label30MinCr";
			this->label30MinCr->Size = System::Drawing::Size(34, 18);
			this->label30MinCr->TabIndex = 226;
			this->label30MinCr->Text = L"CR:";
			// 
			// textBox30MinDmaAma
			// 
			this->textBox30MinDmaAma->Location = System::Drawing::Point(557, 513);
			this->textBox30MinDmaAma->Name = L"textBox30MinDmaAma";
			this->textBox30MinDmaAma->Size = System::Drawing::Size(124, 26);
			this->textBox30MinDmaAma->TabIndex = 225;
			this->textBox30MinDmaAma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinDmaAma_TextChanged);
			// 
			// textBox30MinDmaDma
			// 
			this->textBox30MinDmaDma->Location = System::Drawing::Point(353, 518);
			this->textBox30MinDmaDma->Name = L"textBox30MinDmaDma";
			this->textBox30MinDmaDma->Size = System::Drawing::Size(124, 26);
			this->textBox30MinDmaDma->TabIndex = 223;
			this->textBox30MinDmaDma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinDmaDma_TextChanged);
			// 
			// label30MinDmaAma
			// 
			this->label30MinDmaAma->AutoSize = true;
			this->label30MinDmaAma->Location = System::Drawing::Point(483, 521);
			this->label30MinDmaAma->Name = L"label30MinDmaAma";
			this->label30MinDmaAma->Size = System::Drawing::Size(46, 18);
			this->label30MinDmaAma->TabIndex = 224;
			this->label30MinDmaAma->Text = L"Ama:";
			// 
			// label30MinDmaDma
			// 
			this->label30MinDmaDma->AutoSize = true;
			this->label30MinDmaDma->Location = System::Drawing::Point(286, 525);
			this->label30MinDmaDma->Name = L"label30MinDmaDma";
			this->label30MinDmaDma->Size = System::Drawing::Size(46, 18);
			this->label30MinDmaDma->TabIndex = 222;
			this->label30MinDmaDma->Text = L"Dma:";
			// 
			// label30MinDmaDir
			// 
			this->label30MinDmaDir->AutoSize = true;
			this->label30MinDmaDir->Location = System::Drawing::Point(87, 525);
			this->label30MinDmaDir->Name = L"label30MinDmaDir";
			this->label30MinDmaDir->Size = System::Drawing::Size(77, 18);
			this->label30MinDmaDir->TabIndex = 221;
			this->label30MinDmaDir->Text = L"Direction:";
			// 
			// listBox30MinDmaDir
			// 
			this->listBox30MinDmaDir->FormattingEnabled = true;
			this->listBox30MinDmaDir->ItemHeight = 18;
			this->listBox30MinDmaDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinDmaDir->Location = System::Drawing::Point(170, 521);
			this->listBox30MinDmaDir->Name = L"listBox30MinDmaDir";
			this->listBox30MinDmaDir->Size = System::Drawing::Size(97, 22);
			this->listBox30MinDmaDir->TabIndex = 220;
			this->listBox30MinDmaDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinDmaDir_SelectedIndexChanged);
			// 
			// label30MinDma
			// 
			this->label30MinDma->AutoSize = true;
			this->label30MinDma->Location = System::Drawing::Point(26, 525);
			this->label30MinDma->Name = L"label30MinDma";
			this->label30MinDma->Size = System::Drawing::Size(50, 18);
			this->label30MinDma->TabIndex = 219;
			this->label30MinDma->Text = L"DMA:";
			// 
			// textBox30MinRocRocma
			// 
			this->textBox30MinRocRocma->Location = System::Drawing::Point(557, 427);
			this->textBox30MinRocRocma->Name = L"textBox30MinRocRocma";
			this->textBox30MinRocRocma->Size = System::Drawing::Size(124, 26);
			this->textBox30MinRocRocma->TabIndex = 218;
			this->textBox30MinRocRocma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinRocRocma_TextChanged);
			// 
			// textBox30MinRocRoc
			// 
			this->textBox30MinRocRoc->Location = System::Drawing::Point(353, 432);
			this->textBox30MinRocRoc->Name = L"textBox30MinRocRoc";
			this->textBox30MinRocRoc->Size = System::Drawing::Size(124, 26);
			this->textBox30MinRocRoc->TabIndex = 216;
			this->textBox30MinRocRoc->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinRocRoc_TextChanged);
			// 
			// label30MinRocRocma
			// 
			this->label30MinRocRocma->AutoSize = true;
			this->label30MinRocRocma->Location = System::Drawing::Point(483, 435);
			this->label30MinRocRocma->Name = L"label30MinRocRocma";
			this->label30MinRocRocma->Size = System::Drawing::Size(71, 18);
			this->label30MinRocRocma->TabIndex = 217;
			this->label30MinRocRocma->Text = L"Roc_ma:";
			// 
			// label30MinRocRoc
			// 
			this->label30MinRocRoc->AutoSize = true;
			this->label30MinRocRoc->Location = System::Drawing::Point(286, 439);
			this->label30MinRocRoc->Name = L"label30MinRocRoc";
			this->label30MinRocRoc->Size = System::Drawing::Size(39, 18);
			this->label30MinRocRoc->TabIndex = 215;
			this->label30MinRocRoc->Text = L"Roc:";
			// 
			// label30MinRocDir
			// 
			this->label30MinRocDir->AutoSize = true;
			this->label30MinRocDir->Location = System::Drawing::Point(87, 439);
			this->label30MinRocDir->Name = L"label30MinRocDir";
			this->label30MinRocDir->Size = System::Drawing::Size(77, 18);
			this->label30MinRocDir->TabIndex = 214;
			this->label30MinRocDir->Text = L"Direction:";
			// 
			// listBox30MinRocDir
			// 
			this->listBox30MinRocDir->FormattingEnabled = true;
			this->listBox30MinRocDir->ItemHeight = 18;
			this->listBox30MinRocDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinRocDir->Location = System::Drawing::Point(170, 435);
			this->listBox30MinRocDir->Name = L"listBox30MinRocDir";
			this->listBox30MinRocDir->Size = System::Drawing::Size(97, 22);
			this->listBox30MinRocDir->TabIndex = 213;
			this->listBox30MinRocDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinRocDir_SelectedIndexChanged);
			// 
			// label30MinRoc
			// 
			this->label30MinRoc->AutoSize = true;
			this->label30MinRoc->Location = System::Drawing::Point(26, 439);
			this->label30MinRoc->Name = L"label30MinRoc";
			this->label30MinRoc->Size = System::Drawing::Size(46, 18);
			this->label30MinRoc->TabIndex = 212;
			this->label30MinRoc->Text = L"ROC:";
			// 
			// textBox30MinVrLong
			// 
			this->textBox30MinVrLong->Location = System::Drawing::Point(557, 470);
			this->textBox30MinVrLong->Name = L"textBox30MinVrLong";
			this->textBox30MinVrLong->Size = System::Drawing::Size(124, 26);
			this->textBox30MinVrLong->TabIndex = 211;
			this->textBox30MinVrLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinVrLong_TextChanged);
			// 
			// textBox30MinVrShort
			// 
			this->textBox30MinVrShort->Location = System::Drawing::Point(353, 475);
			this->textBox30MinVrShort->Name = L"textBox30MinVrShort";
			this->textBox30MinVrShort->Size = System::Drawing::Size(124, 26);
			this->textBox30MinVrShort->TabIndex = 209;
			this->textBox30MinVrShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinVrShort_TextChanged);
			// 
			// label30MinVrLong
			// 
			this->label30MinVrLong->AutoSize = true;
			this->label30MinVrLong->Location = System::Drawing::Point(483, 478);
			this->label30MinVrLong->Name = L"label30MinVrLong";
			this->label30MinVrLong->Size = System::Drawing::Size(48, 18);
			this->label30MinVrLong->TabIndex = 210;
			this->label30MinVrLong->Text = L"Long:";
			// 
			// label30MinVrShort
			// 
			this->label30MinVrShort->AutoSize = true;
			this->label30MinVrShort->Location = System::Drawing::Point(281, 483);
			this->label30MinVrShort->Name = L"label30MinVrShort";
			this->label30MinVrShort->Size = System::Drawing::Size(52, 18);
			this->label30MinVrShort->TabIndex = 208;
			this->label30MinVrShort->Text = L"Short:";
			// 
			// label30MinVrDir
			// 
			this->label30MinVrDir->AutoSize = true;
			this->label30MinVrDir->Location = System::Drawing::Point(87, 482);
			this->label30MinVrDir->Name = L"label30MinVrDir";
			this->label30MinVrDir->Size = System::Drawing::Size(77, 18);
			this->label30MinVrDir->TabIndex = 207;
			this->label30MinVrDir->Text = L"Direction:";
			// 
			// listBox30MinVrDir
			// 
			this->listBox30MinVrDir->FormattingEnabled = true;
			this->listBox30MinVrDir->ItemHeight = 18;
			this->listBox30MinVrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinVrDir->Location = System::Drawing::Point(170, 478);
			this->listBox30MinVrDir->Name = L"listBox30MinVrDir";
			this->listBox30MinVrDir->Size = System::Drawing::Size(97, 22);
			this->listBox30MinVrDir->TabIndex = 206;
			this->listBox30MinVrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinVrDir_SelectedIndexChanged);
			// 
			// label30MinVr
			// 
			this->label30MinVr->AutoSize = true;
			this->label30MinVr->Location = System::Drawing::Point(26, 482);
			this->label30MinVr->Name = L"label30MinVr";
			this->label30MinVr->Size = System::Drawing::Size(35, 18);
			this->label30MinVr->TabIndex = 205;
			this->label30MinVr->Text = L"VR:";
			// 
			// label30MinVolDir2
			// 
			this->label30MinVolDir2->AutoSize = true;
			this->label30MinVolDir2->Location = System::Drawing::Point(483, 154);
			this->label30MinVolDir2->Name = L"label30MinVolDir2";
			this->label30MinVolDir2->Size = System::Drawing::Size(86, 18);
			this->label30MinVolDir2->TabIndex = 204;
			this->label30MinVolDir2->Text = L"Direction2:";
			// 
			// listBox30MinVolDir2
			// 
			this->listBox30MinVolDir2->FormattingEnabled = true;
			this->listBox30MinVolDir2->ItemHeight = 18;
			this->listBox30MinVolDir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinVolDir2->Location = System::Drawing::Point(575, 151);
			this->listBox30MinVolDir2->Name = L"listBox30MinVolDir2";
			this->listBox30MinVolDir2->Size = System::Drawing::Size(106, 22);
			this->listBox30MinVolDir2->TabIndex = 203;
			this->listBox30MinVolDir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinVolDir2_SelectedIndexChanged);
			// 
			// textBox30MinVol2
			// 
			this->textBox30MinVol2->Location = System::Drawing::Point(759, 146);
			this->textBox30MinVol2->Name = L"textBox30MinVol2";
			this->textBox30MinVol2->Size = System::Drawing::Size(124, 26);
			this->textBox30MinVol2->TabIndex = 202;
			this->textBox30MinVol2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinVol2_TextChanged);
			// 
			// textBox30MinVol1
			// 
			this->textBox30MinVol1->Location = System::Drawing::Point(353, 151);
			this->textBox30MinVol1->Name = L"textBox30MinVol1";
			this->textBox30MinVol1->Size = System::Drawing::Size(124, 26);
			this->textBox30MinVol1->TabIndex = 200;
			this->textBox30MinVol1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinVol1_TextChanged);
			// 
			// label30MinVol2
			// 
			this->label30MinVol2->AutoSize = true;
			this->label30MinVol2->Location = System::Drawing::Point(695, 154);
			this->label30MinVol2->Name = L"label30MinVol2";
			this->label30MinVol2->Size = System::Drawing::Size(55, 18);
			this->label30MinVol2->TabIndex = 201;
			this->label30MinVol2->Text = L"VOL2:";
			// 
			// label30MinVol1
			// 
			this->label30MinVol1->AutoSize = true;
			this->label30MinVol1->Location = System::Drawing::Point(290, 156);
			this->label30MinVol1->Name = L"label30MinVol1";
			this->label30MinVol1->Size = System::Drawing::Size(54, 18);
			this->label30MinVol1->TabIndex = 199;
			this->label30MinVol1->Text = L"VOL1:";
			// 
			// label30MinVolDir1
			// 
			this->label30MinVolDir1->AutoSize = true;
			this->label30MinVolDir1->Location = System::Drawing::Point(79, 156);
			this->label30MinVolDir1->Name = L"label30MinVolDir1";
			this->label30MinVolDir1->Size = System::Drawing::Size(85, 18);
			this->label30MinVolDir1->TabIndex = 198;
			this->label30MinVolDir1->Text = L"Direction1:";
			// 
			// listBox30MinVolDir1
			// 
			this->listBox30MinVolDir1->FormattingEnabled = true;
			this->listBox30MinVolDir1->ItemHeight = 18;
			this->listBox30MinVolDir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinVolDir1->Location = System::Drawing::Point(170, 154);
			this->listBox30MinVolDir1->Name = L"listBox30MinVolDir1";
			this->listBox30MinVolDir1->Size = System::Drawing::Size(97, 22);
			this->listBox30MinVolDir1->TabIndex = 197;
			this->listBox30MinVolDir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinVolDir1_SelectedIndexChanged);
			// 
			// label30MinVol
			// 
			this->label30MinVol->AutoSize = true;
			this->label30MinVol->Location = System::Drawing::Point(26, 158);
			this->label30MinVol->Name = L"label30MinVol";
			this->label30MinVol->Size = System::Drawing::Size(46, 18);
			this->label30MinVol->TabIndex = 196;
			this->label30MinVol->Text = L"VOL:";
			// 
			// textBox30MinWr2
			// 
			this->textBox30MinWr2->Location = System::Drawing::Point(557, 382);
			this->textBox30MinWr2->Name = L"textBox30MinWr2";
			this->textBox30MinWr2->Size = System::Drawing::Size(124, 26);
			this->textBox30MinWr2->TabIndex = 195;
			this->textBox30MinWr2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinWr2_TextChanged);
			// 
			// textBox30MinWr1
			// 
			this->textBox30MinWr1->Location = System::Drawing::Point(353, 387);
			this->textBox30MinWr1->Name = L"textBox30MinWr1";
			this->textBox30MinWr1->Size = System::Drawing::Size(124, 26);
			this->textBox30MinWr1->TabIndex = 193;
			this->textBox30MinWr1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinWr1_TextChanged);
			// 
			// label30MinWr2
			// 
			this->label30MinWr2->AutoSize = true;
			this->label30MinWr2->Location = System::Drawing::Point(483, 390);
			this->label30MinWr2->Name = L"label30MinWr2";
			this->label30MinWr2->Size = System::Drawing::Size(48, 18);
			this->label30MinWr2->TabIndex = 194;
			this->label30MinWr2->Text = L"WR2:";
			// 
			// label30MinWr1
			// 
			this->label30MinWr1->AutoSize = true;
			this->label30MinWr1->Location = System::Drawing::Point(286, 394);
			this->label30MinWr1->Name = L"label30MinWr1";
			this->label30MinWr1->Size = System::Drawing::Size(47, 18);
			this->label30MinWr1->TabIndex = 192;
			this->label30MinWr1->Text = L"WR1:";
			// 
			// label30MinWrDir
			// 
			this->label30MinWrDir->AutoSize = true;
			this->label30MinWrDir->Location = System::Drawing::Point(87, 394);
			this->label30MinWrDir->Name = L"label30MinWrDir";
			this->label30MinWrDir->Size = System::Drawing::Size(77, 18);
			this->label30MinWrDir->TabIndex = 191;
			this->label30MinWrDir->Text = L"Direction:";
			// 
			// listBox30MinWrDir
			// 
			this->listBox30MinWrDir->FormattingEnabled = true;
			this->listBox30MinWrDir->ItemHeight = 18;
			this->listBox30MinWrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinWrDir->Location = System::Drawing::Point(170, 390);
			this->listBox30MinWrDir->Name = L"listBox30MinWrDir";
			this->listBox30MinWrDir->Size = System::Drawing::Size(97, 22);
			this->listBox30MinWrDir->TabIndex = 190;
			this->listBox30MinWrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinWrDir_SelectedIndexChanged);
			// 
			// label30MinWr
			// 
			this->label30MinWr->AutoSize = true;
			this->label30MinWr->Location = System::Drawing::Point(26, 394);
			this->label30MinWr->Name = L"label30MinWr";
			this->label30MinWr->Size = System::Drawing::Size(39, 18);
			this->label30MinWr->TabIndex = 189;
			this->label30MinWr->Text = L"WR:";
			// 
			// textBox30MinRsiLong
			// 
			this->textBox30MinRsiLong->Location = System::Drawing::Point(759, 335);
			this->textBox30MinRsiLong->Name = L"textBox30MinRsiLong";
			this->textBox30MinRsiLong->Size = System::Drawing::Size(124, 26);
			this->textBox30MinRsiLong->TabIndex = 188;
			this->textBox30MinRsiLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinRsiLong_TextChanged);
			// 
			// textBox30MinRsiMiddle
			// 
			this->textBox30MinRsiMiddle->Location = System::Drawing::Point(557, 335);
			this->textBox30MinRsiMiddle->Name = L"textBox30MinRsiMiddle";
			this->textBox30MinRsiMiddle->Size = System::Drawing::Size(124, 26);
			this->textBox30MinRsiMiddle->TabIndex = 186;
			this->textBox30MinRsiMiddle->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinRsiMiddle_TextChanged);
			// 
			// textBox30MinRsiShort
			// 
			this->textBox30MinRsiShort->Location = System::Drawing::Point(353, 340);
			this->textBox30MinRsiShort->Name = L"textBox30MinRsiShort";
			this->textBox30MinRsiShort->Size = System::Drawing::Size(124, 26);
			this->textBox30MinRsiShort->TabIndex = 184;
			this->textBox30MinRsiShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinRsiShort_TextChanged);
			// 
			// label30MinRsiLong
			// 
			this->label30MinRsiLong->AutoSize = true;
			this->label30MinRsiLong->Location = System::Drawing::Point(695, 340);
			this->label30MinRsiLong->Name = L"label30MinRsiLong";
			this->label30MinRsiLong->Size = System::Drawing::Size(48, 18);
			this->label30MinRsiLong->TabIndex = 187;
			this->label30MinRsiLong->Text = L"Long:";
			// 
			// label30MinRsiMiddle
			// 
			this->label30MinRsiMiddle->AutoSize = true;
			this->label30MinRsiMiddle->Location = System::Drawing::Point(483, 343);
			this->label30MinRsiMiddle->Name = L"label30MinRsiMiddle";
			this->label30MinRsiMiddle->Size = System::Drawing::Size(62, 18);
			this->label30MinRsiMiddle->TabIndex = 185;
			this->label30MinRsiMiddle->Text = L"Middle:";
			// 
			// label30MinRsiShort
			// 
			this->label30MinRsiShort->AutoSize = true;
			this->label30MinRsiShort->Location = System::Drawing::Point(286, 347);
			this->label30MinRsiShort->Name = L"label30MinRsiShort";
			this->label30MinRsiShort->Size = System::Drawing::Size(52, 18);
			this->label30MinRsiShort->TabIndex = 183;
			this->label30MinRsiShort->Text = L"Short:";
			// 
			// label30MinRsiDir
			// 
			this->label30MinRsiDir->AutoSize = true;
			this->label30MinRsiDir->Location = System::Drawing::Point(87, 347);
			this->label30MinRsiDir->Name = L"label30MinRsiDir";
			this->label30MinRsiDir->Size = System::Drawing::Size(77, 18);
			this->label30MinRsiDir->TabIndex = 182;
			this->label30MinRsiDir->Text = L"Direction:";
			// 
			// listBox30MinRsiDir
			// 
			this->listBox30MinRsiDir->FormattingEnabled = true;
			this->listBox30MinRsiDir->ItemHeight = 18;
			this->listBox30MinRsiDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinRsiDir->Location = System::Drawing::Point(170, 343);
			this->listBox30MinRsiDir->Name = L"listBox30MinRsiDir";
			this->listBox30MinRsiDir->Size = System::Drawing::Size(97, 22);
			this->listBox30MinRsiDir->TabIndex = 181;
			this->listBox30MinRsiDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinRsiDir_SelectedIndexChanged);
			// 
			// label30MinRsi
			// 
			this->label30MinRsi->AutoSize = true;
			this->label30MinRsi->Location = System::Drawing::Point(26, 347);
			this->label30MinRsi->Name = L"label30MinRsi";
			this->label30MinRsi->Size = System::Drawing::Size(40, 18);
			this->label30MinRsi->TabIndex = 180;
			this->label30MinRsi->Text = L"RSI:";
			// 
			// textBox30MinKdjJ
			// 
			this->textBox30MinKdjJ->Location = System::Drawing::Point(759, 290);
			this->textBox30MinKdjJ->Name = L"textBox30MinKdjJ";
			this->textBox30MinKdjJ->Size = System::Drawing::Size(124, 26);
			this->textBox30MinKdjJ->TabIndex = 179;
			this->textBox30MinKdjJ->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinKdjJ_TextChanged);
			// 
			// textBox30MinKdjD
			// 
			this->textBox30MinKdjD->Location = System::Drawing::Point(557, 290);
			this->textBox30MinKdjD->Name = L"textBox30MinKdjD";
			this->textBox30MinKdjD->Size = System::Drawing::Size(124, 26);
			this->textBox30MinKdjD->TabIndex = 177;
			this->textBox30MinKdjD->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinKdjD_TextChanged);
			// 
			// textBox30MinKdjK
			// 
			this->textBox30MinKdjK->Location = System::Drawing::Point(353, 295);
			this->textBox30MinKdjK->Name = L"textBox30MinKdjK";
			this->textBox30MinKdjK->Size = System::Drawing::Size(124, 26);
			this->textBox30MinKdjK->TabIndex = 175;
			this->textBox30MinKdjK->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinKdjK_TextChanged);
			// 
			// label30MinKdjJ
			// 
			this->label30MinKdjJ->AutoSize = true;
			this->label30MinKdjJ->Location = System::Drawing::Point(695, 298);
			this->label30MinKdjJ->Name = L"label30MinKdjJ";
			this->label30MinKdjJ->Size = System::Drawing::Size(21, 18);
			this->label30MinKdjJ->TabIndex = 178;
			this->label30MinKdjJ->Text = L"J:";
			// 
			// label30MinKdjD
			// 
			this->label30MinKdjD->AutoSize = true;
			this->label30MinKdjD->Location = System::Drawing::Point(500, 298);
			this->label30MinKdjD->Name = L"label30MinKdjD";
			this->label30MinKdjD->Size = System::Drawing::Size(24, 18);
			this->label30MinKdjD->TabIndex = 176;
			this->label30MinKdjD->Text = L"D:";
			// 
			// label30MinKdjK
			// 
			this->label30MinKdjK->AutoSize = true;
			this->label30MinKdjK->Location = System::Drawing::Point(290, 300);
			this->label30MinKdjK->Name = L"label30MinKdjK";
			this->label30MinKdjK->Size = System::Drawing::Size(24, 18);
			this->label30MinKdjK->TabIndex = 174;
			this->label30MinKdjK->Text = L"K:";
			// 
			// label30MinKdjDir
			// 
			this->label30MinKdjDir->AutoSize = true;
			this->label30MinKdjDir->Location = System::Drawing::Point(87, 302);
			this->label30MinKdjDir->Name = L"label30MinKdjDir";
			this->label30MinKdjDir->Size = System::Drawing::Size(77, 18);
			this->label30MinKdjDir->TabIndex = 173;
			this->label30MinKdjDir->Text = L"Direction:";
			// 
			// listBox30MinKdjDir
			// 
			this->listBox30MinKdjDir->FormattingEnabled = true;
			this->listBox30MinKdjDir->ItemHeight = 18;
			this->listBox30MinKdjDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinKdjDir->Location = System::Drawing::Point(170, 298);
			this->listBox30MinKdjDir->Name = L"listBox30MinKdjDir";
			this->listBox30MinKdjDir->Size = System::Drawing::Size(97, 22);
			this->listBox30MinKdjDir->TabIndex = 172;
			this->listBox30MinKdjDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinKdjDir_SelectedIndexChanged);
			// 
			// label30MinKdj
			// 
			this->label30MinKdj->AutoSize = true;
			this->label30MinKdj->Location = System::Drawing::Point(26, 302);
			this->label30MinKdj->Name = L"label30MinKdj";
			this->label30MinKdj->Size = System::Drawing::Size(43, 18);
			this->label30MinKdj->TabIndex = 171;
			this->label30MinKdj->Text = L"KDJ:";
			// 
			// textBox30MinMacdDea
			// 
			this->textBox30MinMacdDea->Location = System::Drawing::Point(759, 243);
			this->textBox30MinMacdDea->Name = L"textBox30MinMacdDea";
			this->textBox30MinMacdDea->Size = System::Drawing::Size(124, 26);
			this->textBox30MinMacdDea->TabIndex = 170;
			this->textBox30MinMacdDea->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinMacdDea_TextChanged);
			// 
			// textBox30MinMacdDif
			// 
			this->textBox30MinMacdDif->Location = System::Drawing::Point(557, 243);
			this->textBox30MinMacdDif->Name = L"textBox30MinMacdDif";
			this->textBox30MinMacdDif->Size = System::Drawing::Size(124, 26);
			this->textBox30MinMacdDif->TabIndex = 168;
			this->textBox30MinMacdDif->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinMacdDif_TextChanged);
			// 
			// textBox30MinMacdMacd
			// 
			this->textBox30MinMacdMacd->Location = System::Drawing::Point(353, 248);
			this->textBox30MinMacdMacd->Name = L"textBox30MinMacdMacd";
			this->textBox30MinMacdMacd->Size = System::Drawing::Size(124, 26);
			this->textBox30MinMacdMacd->TabIndex = 166;
			this->textBox30MinMacdMacd->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinMacdMacd_TextChanged);
			// 
			// label30MinMacdDea
			// 
			this->label30MinMacdDea->AutoSize = true;
			this->label30MinMacdDea->Location = System::Drawing::Point(695, 251);
			this->label30MinMacdDea->Name = L"label30MinMacdDea";
			this->label30MinMacdDea->Size = System::Drawing::Size(40, 18);
			this->label30MinMacdDea->TabIndex = 169;
			this->label30MinMacdDea->Text = L"Dea:";
			// 
			// label30MinMacdDif
			// 
			this->label30MinMacdDif->AutoSize = true;
			this->label30MinMacdDif->Location = System::Drawing::Point(500, 251);
			this->label30MinMacdDif->Name = L"label30MinMacdDif";
			this->label30MinMacdDif->Size = System::Drawing::Size(33, 18);
			this->label30MinMacdDif->TabIndex = 167;
			this->label30MinMacdDif->Text = L"Dif:";
			// 
			// label30MinMacdMacd
			// 
			this->label30MinMacdMacd->AutoSize = true;
			this->label30MinMacdMacd->Location = System::Drawing::Point(290, 253);
			this->label30MinMacdMacd->Name = L"label30MinMacdMacd";
			this->label30MinMacdMacd->Size = System::Drawing::Size(52, 18);
			this->label30MinMacdMacd->TabIndex = 165;
			this->label30MinMacdMacd->Text = L"Macd:";
			// 
			// label30MinMacdDir
			// 
			this->label30MinMacdDir->AutoSize = true;
			this->label30MinMacdDir->Location = System::Drawing::Point(87, 255);
			this->label30MinMacdDir->Name = L"label30MinMacdDir";
			this->label30MinMacdDir->Size = System::Drawing::Size(77, 18);
			this->label30MinMacdDir->TabIndex = 164;
			this->label30MinMacdDir->Text = L"Direction:";
			// 
			// listBox30MinMacdDir
			// 
			this->listBox30MinMacdDir->FormattingEnabled = true;
			this->listBox30MinMacdDir->ItemHeight = 18;
			this->listBox30MinMacdDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinMacdDir->Location = System::Drawing::Point(170, 251);
			this->listBox30MinMacdDir->Name = L"listBox30MinMacdDir";
			this->listBox30MinMacdDir->Size = System::Drawing::Size(97, 22);
			this->listBox30MinMacdDir->TabIndex = 163;
			this->listBox30MinMacdDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinMacdDir_SelectedIndexChanged);
			// 
			// label30MinMacd
			// 
			this->label30MinMacd->AutoSize = true;
			this->label30MinMacd->Location = System::Drawing::Point(26, 255);
			this->label30MinMacd->Name = L"label30MinMacd";
			this->label30MinMacd->Size = System::Drawing::Size(60, 18);
			this->label30MinMacd->TabIndex = 162;
			this->label30MinMacd->Text = L"MACD:";
			// 
			// textBox30MinBollUpper
			// 
			this->textBox30MinBollUpper->Location = System::Drawing::Point(759, 196);
			this->textBox30MinBollUpper->Name = L"textBox30MinBollUpper";
			this->textBox30MinBollUpper->Size = System::Drawing::Size(124, 26);
			this->textBox30MinBollUpper->TabIndex = 161;
			this->textBox30MinBollUpper->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinBollUpper_TextChanged);
			// 
			// textBox30MinBollMid
			// 
			this->textBox30MinBollMid->Location = System::Drawing::Point(557, 198);
			this->textBox30MinBollMid->Name = L"textBox30MinBollMid";
			this->textBox30MinBollMid->Size = System::Drawing::Size(124, 26);
			this->textBox30MinBollMid->TabIndex = 159;
			this->textBox30MinBollMid->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinBollMid_TextChanged);
			// 
			// textBox30MinBollLow
			// 
			this->textBox30MinBollLow->Location = System::Drawing::Point(353, 200);
			this->textBox30MinBollLow->Name = L"textBox30MinBollLow";
			this->textBox30MinBollLow->Size = System::Drawing::Size(124, 26);
			this->textBox30MinBollLow->TabIndex = 157;
			this->textBox30MinBollLow->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox30MinBollLow_TextChanged);
			// 
			// label30MinBollUpper
			// 
			this->label30MinBollUpper->AutoSize = true;
			this->label30MinBollUpper->Location = System::Drawing::Point(695, 202);
			this->label30MinBollUpper->Name = L"label30MinBollUpper";
			this->label30MinBollUpper->Size = System::Drawing::Size(58, 18);
			this->label30MinBollUpper->TabIndex = 160;
			this->label30MinBollUpper->Text = L"Upper:";
			// 
			// label30MinBollMid
			// 
			this->label30MinBollMid->AutoSize = true;
			this->label30MinBollMid->Location = System::Drawing::Point(500, 204);
			this->label30MinBollMid->Name = L"label30MinBollMid";
			this->label30MinBollMid->Size = System::Drawing::Size(41, 18);
			this->label30MinBollMid->TabIndex = 158;
			this->label30MinBollMid->Text = L"Mid:";
			// 
			// label30MinBollLow
			// 
			this->label30MinBollLow->AutoSize = true;
			this->label30MinBollLow->Location = System::Drawing::Point(295, 206);
			this->label30MinBollLow->Name = L"label30MinBollLow";
			this->label30MinBollLow->Size = System::Drawing::Size(43, 18);
			this->label30MinBollLow->TabIndex = 156;
			this->label30MinBollLow->Text = L"Low:";
			// 
			// label30MinBollDir
			// 
			this->label30MinBollDir->AutoSize = true;
			this->label30MinBollDir->Location = System::Drawing::Point(87, 206);
			this->label30MinBollDir->Name = L"label30MinBollDir";
			this->label30MinBollDir->Size = System::Drawing::Size(77, 18);
			this->label30MinBollDir->TabIndex = 155;
			this->label30MinBollDir->Text = L"Direction:";
			// 
			// listBox30MinBollDir
			// 
			this->listBox30MinBollDir->FormattingEnabled = true;
			this->listBox30MinBollDir->ItemHeight = 18;
			this->listBox30MinBollDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox30MinBollDir->Location = System::Drawing::Point(170, 204);
			this->listBox30MinBollDir->Name = L"listBox30MinBollDir";
			this->listBox30MinBollDir->Size = System::Drawing::Size(97, 22);
			this->listBox30MinBollDir->TabIndex = 154;
			this->listBox30MinBollDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox30MinBollDir_SelectedIndexChanged);
			// 
			// label30MinBoll
			// 
			this->label30MinBoll->AutoSize = true;
			this->label30MinBoll->Location = System::Drawing::Point(26, 210);
			this->label30MinBoll->Name = L"label30MinBoll";
			this->label30MinBoll->Size = System::Drawing::Size(55, 18);
			this->label30MinBoll->TabIndex = 153;
			this->label30MinBoll->Text = L"BOLL:";
			// 
			// tab45Min
			// 
			this->tab45Min->Controls->Add(this->listBox45MinMADir6);
			this->tab45Min->Controls->Add(this->label45MinMADir6);
			this->tab45Min->Controls->Add(this->textBox45MinMA6);
			this->tab45Min->Controls->Add(this->textBox45MinMA5);
			this->tab45Min->Controls->Add(this->label45MinMA6);
			this->tab45Min->Controls->Add(this->label45MinMA5);
			this->tab45Min->Controls->Add(this->label45MinMADir5);
			this->tab45Min->Controls->Add(this->listBox45MinMADir5);
			this->tab45Min->Controls->Add(this->label45MinMA56);
			this->tab45Min->Controls->Add(this->label45MinMADir4);
			this->tab45Min->Controls->Add(this->listBox45MinMADir4);
			this->tab45Min->Controls->Add(this->textBox45MinMA4);
			this->tab45Min->Controls->Add(this->textBox45MinMA3);
			this->tab45Min->Controls->Add(this->label45MinMA4);
			this->tab45Min->Controls->Add(this->label45MinMA3);
			this->tab45Min->Controls->Add(this->label45MinMADir3);
			this->tab45Min->Controls->Add(this->listBox45MinMADir3);
			this->tab45Min->Controls->Add(this->label45MinMA34);
			this->tab45Min->Controls->Add(this->label45MinMADir2);
			this->tab45Min->Controls->Add(this->listBox45MinMADir2);
			this->tab45Min->Controls->Add(this->textBox45MinMA2);
			this->tab45Min->Controls->Add(this->textBox45MinMA1);
			this->tab45Min->Controls->Add(this->label45MinMA2);
			this->tab45Min->Controls->Add(this->label45MinMA1);
			this->tab45Min->Controls->Add(this->label45MinMADir1);
			this->tab45Min->Controls->Add(this->listBox45MinMADir1);
			this->tab45Min->Controls->Add(this->label45MinMA12);
			this->tab45Min->Controls->Add(this->textBox45MinCciCci);
			this->tab45Min->Controls->Add(this->label45MinCciCci);
			this->tab45Min->Controls->Add(this->label45MinCciDir);
			this->tab45Min->Controls->Add(this->listBox45MinCciDir);
			this->tab45Min->Controls->Add(this->label45MinCci);
			this->tab45Min->Controls->Add(this->textBox45MinCrC);
			this->tab45Min->Controls->Add(this->label45MinCrC);
			this->tab45Min->Controls->Add(this->textBox45MinCrB);
			this->tab45Min->Controls->Add(this->label45MinCrB);
			this->tab45Min->Controls->Add(this->textBox45MinCrA);
			this->tab45Min->Controls->Add(this->textBox45MinCrCr);
			this->tab45Min->Controls->Add(this->label45MinCrA);
			this->tab45Min->Controls->Add(this->label45MinCrCr);
			this->tab45Min->Controls->Add(this->label45MinCrDir);
			this->tab45Min->Controls->Add(this->listBox45MinCrDir);
			this->tab45Min->Controls->Add(this->label45MinCr);
			this->tab45Min->Controls->Add(this->textBox45MinDmaAma);
			this->tab45Min->Controls->Add(this->textBox45MinDmaDma);
			this->tab45Min->Controls->Add(this->label45MinDmaAma);
			this->tab45Min->Controls->Add(this->label45MinDmaDma);
			this->tab45Min->Controls->Add(this->label45MinDmaDir);
			this->tab45Min->Controls->Add(this->listBox45MinDmaDir);
			this->tab45Min->Controls->Add(this->label45MinDma);
			this->tab45Min->Controls->Add(this->textBox45MinRocRocma);
			this->tab45Min->Controls->Add(this->textBox45MinRocRoc);
			this->tab45Min->Controls->Add(this->label45MinRocRocma);
			this->tab45Min->Controls->Add(this->label45MinRocRoc);
			this->tab45Min->Controls->Add(this->label45MinRocDir);
			this->tab45Min->Controls->Add(this->listBox45MinRocDir);
			this->tab45Min->Controls->Add(this->label45MinRoc);
			this->tab45Min->Controls->Add(this->textBox45MinVrLong);
			this->tab45Min->Controls->Add(this->textBox45MinVrShort);
			this->tab45Min->Controls->Add(this->label45MinVrLong);
			this->tab45Min->Controls->Add(this->label45MinVrShort);
			this->tab45Min->Controls->Add(this->label45MinVrDir);
			this->tab45Min->Controls->Add(this->listBox45MinVrDir);
			this->tab45Min->Controls->Add(this->label45MinVr);
			this->tab45Min->Controls->Add(this->label45MinVolDir2);
			this->tab45Min->Controls->Add(this->listBox45MinVolDir2);
			this->tab45Min->Controls->Add(this->textBox45MinVol2);
			this->tab45Min->Controls->Add(this->textBox45MinVol1);
			this->tab45Min->Controls->Add(this->label45MinVol2);
			this->tab45Min->Controls->Add(this->label45MinVol1);
			this->tab45Min->Controls->Add(this->label45MinVolDir1);
			this->tab45Min->Controls->Add(this->listBox45MinVolDir1);
			this->tab45Min->Controls->Add(this->label45MinVol);
			this->tab45Min->Controls->Add(this->textBox45MinWr2);
			this->tab45Min->Controls->Add(this->textBox45MinWr1);
			this->tab45Min->Controls->Add(this->label45MinWr2);
			this->tab45Min->Controls->Add(this->label45MinWr1);
			this->tab45Min->Controls->Add(this->label45MinWrDir);
			this->tab45Min->Controls->Add(this->listBox45MinWrDir);
			this->tab45Min->Controls->Add(this->label45MinWr);
			this->tab45Min->Controls->Add(this->textBox45MinRsiLong);
			this->tab45Min->Controls->Add(this->textBox45MinRsiMiddle);
			this->tab45Min->Controls->Add(this->textBox45MinRsiShort);
			this->tab45Min->Controls->Add(this->label45MinRsiLong);
			this->tab45Min->Controls->Add(this->label45MinRsiMiddle);
			this->tab45Min->Controls->Add(this->label45MinRsiShort);
			this->tab45Min->Controls->Add(this->label45MinRsiDir);
			this->tab45Min->Controls->Add(this->listBox45MinRsiDir);
			this->tab45Min->Controls->Add(this->label45MinRsi);
			this->tab45Min->Controls->Add(this->textBox45MinKdjJ);
			this->tab45Min->Controls->Add(this->textBox45MinKdjD);
			this->tab45Min->Controls->Add(this->textBox45MinKdjK);
			this->tab45Min->Controls->Add(this->label45MinKdjJ);
			this->tab45Min->Controls->Add(this->label45MinKdjD);
			this->tab45Min->Controls->Add(this->label45MinKdjK);
			this->tab45Min->Controls->Add(this->label45MinKdjDir);
			this->tab45Min->Controls->Add(this->listBox45MinKdjDir);
			this->tab45Min->Controls->Add(this->label45MinKdj);
			this->tab45Min->Controls->Add(this->textBox45MinMacdDea);
			this->tab45Min->Controls->Add(this->textBox45MinMacdDif);
			this->tab45Min->Controls->Add(this->textBox45MinMacdMacd);
			this->tab45Min->Controls->Add(this->label45MinMacdDea);
			this->tab45Min->Controls->Add(this->label45MinMacdDif);
			this->tab45Min->Controls->Add(this->label45MinMacdMacd);
			this->tab45Min->Controls->Add(this->label45MinMacdDir);
			this->tab45Min->Controls->Add(this->listBox45MinMacdDir);
			this->tab45Min->Controls->Add(this->label45MinMacd);
			this->tab45Min->Controls->Add(this->textBox45MinBollUpper);
			this->tab45Min->Controls->Add(this->textBox45MinBollMid);
			this->tab45Min->Controls->Add(this->textBox45MinBollLow);
			this->tab45Min->Controls->Add(this->label45MinBollUpper);
			this->tab45Min->Controls->Add(this->label45MinBollMid);
			this->tab45Min->Controls->Add(this->label45MinBollLow);
			this->tab45Min->Controls->Add(this->label45MinBollDir);
			this->tab45Min->Controls->Add(this->listBox45MinBollDir);
			this->tab45Min->Controls->Add(this->label45MinBoll);
			this->tab45Min->Location = System::Drawing::Point(4, 27);
			this->tab45Min->Name = L"tab45Min";
			this->tab45Min->Padding = System::Windows::Forms::Padding(3);
			this->tab45Min->Size = System::Drawing::Size(1092, 869);
			this->tab45Min->TabIndex = 6;
			this->tab45Min->Text = L"45Min";
			this->tab45Min->UseVisualStyleBackColor = true;
			// 
			// listBox45MinMADir6
			// 
			this->listBox45MinMADir6->FormattingEnabled = true;
			this->listBox45MinMADir6->ItemHeight = 18;
			this->listBox45MinMADir6->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinMADir6->Location = System::Drawing::Point(575, 103);
			this->listBox45MinMADir6->Name = L"listBox45MinMADir6";
			this->listBox45MinMADir6->Size = System::Drawing::Size(106, 22);
			this->listBox45MinMADir6->TabIndex = 269;
			this->listBox45MinMADir6->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinMADir6_SelectedIndexChanged);
			// 
			// label45MinMADir6
			// 
			this->label45MinMADir6->AutoSize = true;
			this->label45MinMADir6->Location = System::Drawing::Point(483, 107);
			this->label45MinMADir6->Name = L"label45MinMADir6";
			this->label45MinMADir6->Size = System::Drawing::Size(80, 18);
			this->label45MinMADir6->TabIndex = 268;
			this->label45MinMADir6->Text = L"MA_Dir6:";
			// 
			// textBox45MinMA6
			// 
			this->textBox45MinMA6->Location = System::Drawing::Point(759, 99);
			this->textBox45MinMA6->Name = L"textBox45MinMA6";
			this->textBox45MinMA6->Size = System::Drawing::Size(124, 26);
			this->textBox45MinMA6->TabIndex = 266;
			this->textBox45MinMA6->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinMA6_TextChanged);
			// 
			// textBox45MinMA5
			// 
			this->textBox45MinMA5->Location = System::Drawing::Point(353, 104);
			this->textBox45MinMA5->Name = L"textBox45MinMA5";
			this->textBox45MinMA5->Size = System::Drawing::Size(124, 26);
			this->textBox45MinMA5->TabIndex = 264;
			this->textBox45MinMA5->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinMA5_TextChanged);
			// 
			// label45MinMA6
			// 
			this->label45MinMA6->AutoSize = true;
			this->label45MinMA6->Location = System::Drawing::Point(695, 107);
			this->label45MinMA6->Name = L"label45MinMA6";
			this->label45MinMA6->Size = System::Drawing::Size(48, 18);
			this->label45MinMA6->TabIndex = 265;
			this->label45MinMA6->Text = L"MA6:";
			// 
			// label45MinMA5
			// 
			this->label45MinMA5->AutoSize = true;
			this->label45MinMA5->Location = System::Drawing::Point(290, 109);
			this->label45MinMA5->Name = L"label45MinMA5";
			this->label45MinMA5->Size = System::Drawing::Size(48, 18);
			this->label45MinMA5->TabIndex = 263;
			this->label45MinMA5->Text = L"MA5:";
			// 
			// label45MinMADir5
			// 
			this->label45MinMADir5->AutoSize = true;
			this->label45MinMADir5->Location = System::Drawing::Point(79, 112);
			this->label45MinMADir5->Name = L"label45MinMADir5";
			this->label45MinMADir5->Size = System::Drawing::Size(80, 18);
			this->label45MinMADir5->TabIndex = 262;
			this->label45MinMADir5->Text = L"MA_Dir5:";
			// 
			// listBox45MinMADir5
			// 
			this->listBox45MinMADir5->FormattingEnabled = true;
			this->listBox45MinMADir5->ItemHeight = 18;
			this->listBox45MinMADir5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinMADir5->Location = System::Drawing::Point(170, 107);
			this->listBox45MinMADir5->Name = L"listBox45MinMADir5";
			this->listBox45MinMADir5->Size = System::Drawing::Size(97, 22);
			this->listBox45MinMADir5->TabIndex = 261;
			this->listBox45MinMADir5->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinMADir5_SelectedIndexChanged);
			// 
			// label45MinMA56
			// 
			this->label45MinMA56->AutoSize = true;
			this->label45MinMA56->Location = System::Drawing::Point(17, 112);
			this->label45MinMA56->Name = L"label45MinMA56";
			this->label45MinMA56->Size = System::Drawing::Size(64, 18);
			this->label45MinMA56->TabIndex = 260;
			this->label45MinMA56->Text = L"MA5-6:";
			// 
			// label45MinMADir4
			// 
			this->label45MinMADir4->AutoSize = true;
			this->label45MinMADir4->Location = System::Drawing::Point(483, 60);
			this->label45MinMADir4->Name = L"label45MinMADir4";
			this->label45MinMADir4->Size = System::Drawing::Size(80, 18);
			this->label45MinMADir4->TabIndex = 259;
			this->label45MinMADir4->Text = L"MA_Dir4:";
			// 
			// listBox45MinMADir4
			// 
			this->listBox45MinMADir4->FormattingEnabled = true;
			this->listBox45MinMADir4->ItemHeight = 18;
			this->listBox45MinMADir4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinMADir4->Location = System::Drawing::Point(575, 57);
			this->listBox45MinMADir4->Name = L"listBox45MinMADir4";
			this->listBox45MinMADir4->Size = System::Drawing::Size(106, 22);
			this->listBox45MinMADir4->TabIndex = 258;
			this->listBox45MinMADir4->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinMADir4_SelectedIndexChanged);
			// 
			// textBox45MinMA4
			// 
			this->textBox45MinMA4->Location = System::Drawing::Point(759, 52);
			this->textBox45MinMA4->Name = L"textBox45MinMA4";
			this->textBox45MinMA4->Size = System::Drawing::Size(124, 26);
			this->textBox45MinMA4->TabIndex = 257;
			this->textBox45MinMA4->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinMA4_TextChanged);
			// 
			// textBox45MinMA3
			// 
			this->textBox45MinMA3->Location = System::Drawing::Point(353, 57);
			this->textBox45MinMA3->Name = L"textBox45MinMA3";
			this->textBox45MinMA3->Size = System::Drawing::Size(124, 26);
			this->textBox45MinMA3->TabIndex = 255;
			this->textBox45MinMA3->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinMA3_TextChanged);
			// 
			// label45MinMA4
			// 
			this->label45MinMA4->AutoSize = true;
			this->label45MinMA4->Location = System::Drawing::Point(695, 60);
			this->label45MinMA4->Name = L"label45MinMA4";
			this->label45MinMA4->Size = System::Drawing::Size(48, 18);
			this->label45MinMA4->TabIndex = 256;
			this->label45MinMA4->Text = L"MA4:";
			// 
			// label45MinMA3
			// 
			this->label45MinMA3->AutoSize = true;
			this->label45MinMA3->Location = System::Drawing::Point(290, 62);
			this->label45MinMA3->Name = L"label45MinMA3";
			this->label45MinMA3->Size = System::Drawing::Size(48, 18);
			this->label45MinMA3->TabIndex = 254;
			this->label45MinMA3->Text = L"MA3:";
			// 
			// label45MinMADir3
			// 
			this->label45MinMADir3->AutoSize = true;
			this->label45MinMADir3->Location = System::Drawing::Point(79, 65);
			this->label45MinMADir3->Name = L"label45MinMADir3";
			this->label45MinMADir3->Size = System::Drawing::Size(80, 18);
			this->label45MinMADir3->TabIndex = 253;
			this->label45MinMADir3->Text = L"MA_Dir3:";
			// 
			// listBox45MinMADir3
			// 
			this->listBox45MinMADir3->FormattingEnabled = true;
			this->listBox45MinMADir3->ItemHeight = 18;
			this->listBox45MinMADir3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinMADir3->Location = System::Drawing::Point(170, 60);
			this->listBox45MinMADir3->Name = L"listBox45MinMADir3";
			this->listBox45MinMADir3->Size = System::Drawing::Size(97, 22);
			this->listBox45MinMADir3->TabIndex = 252;
			this->listBox45MinMADir3->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinMADir3_SelectedIndexChanged);
			// 
			// label45MinMA34
			// 
			this->label45MinMA34->AutoSize = true;
			this->label45MinMA34->Location = System::Drawing::Point(17, 65);
			this->label45MinMA34->Name = L"label45MinMA34";
			this->label45MinMA34->Size = System::Drawing::Size(64, 18);
			this->label45MinMA34->TabIndex = 251;
			this->label45MinMA34->Text = L"MA3-4:";
			// 
			// label45MinMADir2
			// 
			this->label45MinMADir2->AutoSize = true;
			this->label45MinMADir2->Location = System::Drawing::Point(483, 19);
			this->label45MinMADir2->Name = L"label45MinMADir2";
			this->label45MinMADir2->Size = System::Drawing::Size(80, 18);
			this->label45MinMADir2->TabIndex = 250;
			this->label45MinMADir2->Text = L"MA_Dir2:";
			// 
			// listBox45MinMADir2
			// 
			this->listBox45MinMADir2->FormattingEnabled = true;
			this->listBox45MinMADir2->ItemHeight = 18;
			this->listBox45MinMADir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinMADir2->Location = System::Drawing::Point(575, 16);
			this->listBox45MinMADir2->Name = L"listBox45MinMADir2";
			this->listBox45MinMADir2->Size = System::Drawing::Size(106, 22);
			this->listBox45MinMADir2->TabIndex = 249;
			this->listBox45MinMADir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinMADir2_SelectedIndexChanged);
			// 
			// textBox45MinMA2
			// 
			this->textBox45MinMA2->Location = System::Drawing::Point(759, 11);
			this->textBox45MinMA2->Name = L"textBox45MinMA2";
			this->textBox45MinMA2->Size = System::Drawing::Size(124, 26);
			this->textBox45MinMA2->TabIndex = 248;
			this->textBox45MinMA2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinMA2_TextChanged);
			// 
			// textBox45MinMA1
			// 
			this->textBox45MinMA1->Location = System::Drawing::Point(353, 16);
			this->textBox45MinMA1->Name = L"textBox45MinMA1";
			this->textBox45MinMA1->Size = System::Drawing::Size(124, 26);
			this->textBox45MinMA1->TabIndex = 246;
			this->textBox45MinMA1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinMA1_TextChanged);
			// 
			// label45MinMA2
			// 
			this->label45MinMA2->AutoSize = true;
			this->label45MinMA2->Location = System::Drawing::Point(695, 19);
			this->label45MinMA2->Name = L"label45MinMA2";
			this->label45MinMA2->Size = System::Drawing::Size(48, 18);
			this->label45MinMA2->TabIndex = 247;
			this->label45MinMA2->Text = L"MA2:";
			// 
			// label45MinMA1
			// 
			this->label45MinMA1->AutoSize = true;
			this->label45MinMA1->Location = System::Drawing::Point(290, 21);
			this->label45MinMA1->Name = L"label45MinMA1";
			this->label45MinMA1->Size = System::Drawing::Size(47, 18);
			this->label45MinMA1->TabIndex = 245;
			this->label45MinMA1->Text = L"MA1:";
			// 
			// label45MinMADir1
			// 
			this->label45MinMADir1->AutoSize = true;
			this->label45MinMADir1->Location = System::Drawing::Point(79, 21);
			this->label45MinMADir1->Name = L"label45MinMADir1";
			this->label45MinMADir1->Size = System::Drawing::Size(79, 18);
			this->label45MinMADir1->TabIndex = 244;
			this->label45MinMADir1->Text = L"MA_Dir1:";
			// 
			// listBox45MinMADir1
			// 
			this->listBox45MinMADir1->FormattingEnabled = true;
			this->listBox45MinMADir1->ItemHeight = 18;
			this->listBox45MinMADir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinMADir1->Location = System::Drawing::Point(170, 19);
			this->listBox45MinMADir1->Name = L"listBox45MinMADir1";
			this->listBox45MinMADir1->Size = System::Drawing::Size(97, 22);
			this->listBox45MinMADir1->TabIndex = 243;
			this->listBox45MinMADir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinMADir1_SelectedIndexChanged);
			// 
			// label45MinMA12
			// 
			this->label45MinMA12->AutoSize = true;
			this->label45MinMA12->Location = System::Drawing::Point(16, 24);
			this->label45MinMA12->Name = L"label45MinMA12";
			this->label45MinMA12->Size = System::Drawing::Size(63, 18);
			this->label45MinMA12->TabIndex = 242;
			this->label45MinMA12->Text = L"MA1-2:";
			// 
			// textBox45MinCciCci
			// 
			this->textBox45MinCciCci->Location = System::Drawing::Point(353, 601);
			this->textBox45MinCciCci->Name = L"textBox45MinCciCci";
			this->textBox45MinCciCci->Size = System::Drawing::Size(124, 26);
			this->textBox45MinCciCci->TabIndex = 241;
			this->textBox45MinCciCci->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinCciCci_TextChanged);
			// 
			// label45MinCciCci
			// 
			this->label45MinCciCci->AutoSize = true;
			this->label45MinCciCci->Location = System::Drawing::Point(286, 608);
			this->label45MinCciCci->Name = L"label45MinCciCci";
			this->label45MinCciCci->Size = System::Drawing::Size(34, 18);
			this->label45MinCciCci->TabIndex = 240;
			this->label45MinCciCci->Text = L"Cci:";
			// 
			// label45MinCciDir
			// 
			this->label45MinCciDir->AutoSize = true;
			this->label45MinCciDir->Location = System::Drawing::Point(87, 608);
			this->label45MinCciDir->Name = L"label45MinCciDir";
			this->label45MinCciDir->Size = System::Drawing::Size(77, 18);
			this->label45MinCciDir->TabIndex = 239;
			this->label45MinCciDir->Text = L"Direction:";
			// 
			// listBox45MinCciDir
			// 
			this->listBox45MinCciDir->FormattingEnabled = true;
			this->listBox45MinCciDir->ItemHeight = 18;
			this->listBox45MinCciDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinCciDir->Location = System::Drawing::Point(170, 604);
			this->listBox45MinCciDir->Name = L"listBox45MinCciDir";
			this->listBox45MinCciDir->Size = System::Drawing::Size(97, 22);
			this->listBox45MinCciDir->TabIndex = 238;
			this->listBox45MinCciDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinCciDir_SelectedIndexChanged);
			// 
			// label45MinCci
			// 
			this->label45MinCci->AutoSize = true;
			this->label45MinCci->Location = System::Drawing::Point(26, 608);
			this->label45MinCci->Name = L"label45MinCci";
			this->label45MinCci->Size = System::Drawing::Size(40, 18);
			this->label45MinCci->TabIndex = 237;
			this->label45MinCci->Text = L"CCI:";
			// 
			// textBox45MinCrC
			// 
			this->textBox45MinCrC->Location = System::Drawing::Point(961, 555);
			this->textBox45MinCrC->Name = L"textBox45MinCrC";
			this->textBox45MinCrC->Size = System::Drawing::Size(124, 26);
			this->textBox45MinCrC->TabIndex = 236;
			this->textBox45MinCrC->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinCrC_TextChanged);
			// 
			// label45MinCrC
			// 
			this->label45MinCrC->AutoSize = true;
			this->label45MinCrC->Location = System::Drawing::Point(900, 563);
			this->label45MinCrC->Name = L"label45MinCrC";
			this->label45MinCrC->Size = System::Drawing::Size(23, 18);
			this->label45MinCrC->TabIndex = 235;
			this->label45MinCrC->Text = L"C:";
			// 
			// textBox45MinCrB
			// 
			this->textBox45MinCrB->Location = System::Drawing::Point(755, 555);
			this->textBox45MinCrB->Name = L"textBox45MinCrB";
			this->textBox45MinCrB->Size = System::Drawing::Size(124, 26);
			this->textBox45MinCrB->TabIndex = 234;
			this->textBox45MinCrB->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinCrB_TextChanged);
			// 
			// label45MinCrB
			// 
			this->label45MinCrB->AutoSize = true;
			this->label45MinCrB->Location = System::Drawing::Point(694, 563);
			this->label45MinCrB->Name = L"label45MinCrB";
			this->label45MinCrB->Size = System::Drawing::Size(23, 18);
			this->label45MinCrB->TabIndex = 233;
			this->label45MinCrB->Text = L"B:";
			// 
			// textBox45MinCrA
			// 
			this->textBox45MinCrA->Location = System::Drawing::Point(557, 555);
			this->textBox45MinCrA->Name = L"textBox45MinCrA";
			this->textBox45MinCrA->Size = System::Drawing::Size(124, 26);
			this->textBox45MinCrA->TabIndex = 232;
			this->textBox45MinCrA->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinCrA_TextChanged);
			// 
			// textBox45MinCrCr
			// 
			this->textBox45MinCrCr->Location = System::Drawing::Point(353, 560);
			this->textBox45MinCrCr->Name = L"textBox45MinCrCr";
			this->textBox45MinCrCr->Size = System::Drawing::Size(124, 26);
			this->textBox45MinCrCr->TabIndex = 230;
			this->textBox45MinCrCr->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinCrCr_TextChanged);
			// 
			// label45MinCrA
			// 
			this->label45MinCrA->AutoSize = true;
			this->label45MinCrA->Location = System::Drawing::Point(496, 563);
			this->label45MinCrA->Name = L"label45MinCrA";
			this->label45MinCrA->Size = System::Drawing::Size(24, 18);
			this->label45MinCrA->TabIndex = 231;
			this->label45MinCrA->Text = L"A:";
			// 
			// label45MinCrCr
			// 
			this->label45MinCrCr->AutoSize = true;
			this->label45MinCrCr->Location = System::Drawing::Point(286, 567);
			this->label45MinCrCr->Name = L"label45MinCrCr";
			this->label45MinCrCr->Size = System::Drawing::Size(30, 18);
			this->label45MinCrCr->TabIndex = 229;
			this->label45MinCrCr->Text = L"Cr:";
			// 
			// label45MinCrDir
			// 
			this->label45MinCrDir->AutoSize = true;
			this->label45MinCrDir->Location = System::Drawing::Point(87, 567);
			this->label45MinCrDir->Name = L"label45MinCrDir";
			this->label45MinCrDir->Size = System::Drawing::Size(77, 18);
			this->label45MinCrDir->TabIndex = 228;
			this->label45MinCrDir->Text = L"Direction:";
			// 
			// listBox45MinCrDir
			// 
			this->listBox45MinCrDir->FormattingEnabled = true;
			this->listBox45MinCrDir->ItemHeight = 18;
			this->listBox45MinCrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinCrDir->Location = System::Drawing::Point(170, 563);
			this->listBox45MinCrDir->Name = L"listBox45MinCrDir";
			this->listBox45MinCrDir->Size = System::Drawing::Size(97, 22);
			this->listBox45MinCrDir->TabIndex = 227;
			this->listBox45MinCrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinCrDir_SelectedIndexChanged);
			// 
			// label45MinCr
			// 
			this->label45MinCr->AutoSize = true;
			this->label45MinCr->Location = System::Drawing::Point(26, 567);
			this->label45MinCr->Name = L"label45MinCr";
			this->label45MinCr->Size = System::Drawing::Size(34, 18);
			this->label45MinCr->TabIndex = 226;
			this->label45MinCr->Text = L"CR:";
			// 
			// textBox45MinDmaAma
			// 
			this->textBox45MinDmaAma->Location = System::Drawing::Point(557, 513);
			this->textBox45MinDmaAma->Name = L"textBox45MinDmaAma";
			this->textBox45MinDmaAma->Size = System::Drawing::Size(124, 26);
			this->textBox45MinDmaAma->TabIndex = 225;
			this->textBox45MinDmaAma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinDmaAma_TextChanged);
			// 
			// textBox45MinDmaDma
			// 
			this->textBox45MinDmaDma->Location = System::Drawing::Point(353, 518);
			this->textBox45MinDmaDma->Name = L"textBox45MinDmaDma";
			this->textBox45MinDmaDma->Size = System::Drawing::Size(124, 26);
			this->textBox45MinDmaDma->TabIndex = 223;
			this->textBox45MinDmaDma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinDmaDma_TextChanged);
			// 
			// label45MinDmaAma
			// 
			this->label45MinDmaAma->AutoSize = true;
			this->label45MinDmaAma->Location = System::Drawing::Point(483, 521);
			this->label45MinDmaAma->Name = L"label45MinDmaAma";
			this->label45MinDmaAma->Size = System::Drawing::Size(46, 18);
			this->label45MinDmaAma->TabIndex = 224;
			this->label45MinDmaAma->Text = L"Ama:";
			// 
			// label45MinDmaDma
			// 
			this->label45MinDmaDma->AutoSize = true;
			this->label45MinDmaDma->Location = System::Drawing::Point(286, 525);
			this->label45MinDmaDma->Name = L"label45MinDmaDma";
			this->label45MinDmaDma->Size = System::Drawing::Size(46, 18);
			this->label45MinDmaDma->TabIndex = 222;
			this->label45MinDmaDma->Text = L"Dma:";
			// 
			// label45MinDmaDir
			// 
			this->label45MinDmaDir->AutoSize = true;
			this->label45MinDmaDir->Location = System::Drawing::Point(87, 525);
			this->label45MinDmaDir->Name = L"label45MinDmaDir";
			this->label45MinDmaDir->Size = System::Drawing::Size(77, 18);
			this->label45MinDmaDir->TabIndex = 221;
			this->label45MinDmaDir->Text = L"Direction:";
			// 
			// listBox45MinDmaDir
			// 
			this->listBox45MinDmaDir->FormattingEnabled = true;
			this->listBox45MinDmaDir->ItemHeight = 18;
			this->listBox45MinDmaDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinDmaDir->Location = System::Drawing::Point(170, 521);
			this->listBox45MinDmaDir->Name = L"listBox45MinDmaDir";
			this->listBox45MinDmaDir->Size = System::Drawing::Size(97, 22);
			this->listBox45MinDmaDir->TabIndex = 220;
			this->listBox45MinDmaDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinDmaDir_SelectedIndexChanged);
			// 
			// label45MinDma
			// 
			this->label45MinDma->AutoSize = true;
			this->label45MinDma->Location = System::Drawing::Point(26, 525);
			this->label45MinDma->Name = L"label45MinDma";
			this->label45MinDma->Size = System::Drawing::Size(50, 18);
			this->label45MinDma->TabIndex = 219;
			this->label45MinDma->Text = L"DMA:";
			// 
			// textBox45MinRocRocma
			// 
			this->textBox45MinRocRocma->Location = System::Drawing::Point(557, 427);
			this->textBox45MinRocRocma->Name = L"textBox45MinRocRocma";
			this->textBox45MinRocRocma->Size = System::Drawing::Size(124, 26);
			this->textBox45MinRocRocma->TabIndex = 218;
			this->textBox45MinRocRocma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinRocRocma_TextChanged);
			// 
			// textBox45MinRocRoc
			// 
			this->textBox45MinRocRoc->Location = System::Drawing::Point(353, 432);
			this->textBox45MinRocRoc->Name = L"textBox45MinRocRoc";
			this->textBox45MinRocRoc->Size = System::Drawing::Size(124, 26);
			this->textBox45MinRocRoc->TabIndex = 216;
			this->textBox45MinRocRoc->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinRocRoc_TextChanged);
			// 
			// label45MinRocRocma
			// 
			this->label45MinRocRocma->AutoSize = true;
			this->label45MinRocRocma->Location = System::Drawing::Point(483, 435);
			this->label45MinRocRocma->Name = L"label45MinRocRocma";
			this->label45MinRocRocma->Size = System::Drawing::Size(71, 18);
			this->label45MinRocRocma->TabIndex = 217;
			this->label45MinRocRocma->Text = L"Roc_ma:";
			// 
			// label45MinRocRoc
			// 
			this->label45MinRocRoc->AutoSize = true;
			this->label45MinRocRoc->Location = System::Drawing::Point(286, 439);
			this->label45MinRocRoc->Name = L"label45MinRocRoc";
			this->label45MinRocRoc->Size = System::Drawing::Size(39, 18);
			this->label45MinRocRoc->TabIndex = 215;
			this->label45MinRocRoc->Text = L"Roc:";
			// 
			// label45MinRocDir
			// 
			this->label45MinRocDir->AutoSize = true;
			this->label45MinRocDir->Location = System::Drawing::Point(87, 439);
			this->label45MinRocDir->Name = L"label45MinRocDir";
			this->label45MinRocDir->Size = System::Drawing::Size(77, 18);
			this->label45MinRocDir->TabIndex = 214;
			this->label45MinRocDir->Text = L"Direction:";
			// 
			// listBox45MinRocDir
			// 
			this->listBox45MinRocDir->FormattingEnabled = true;
			this->listBox45MinRocDir->ItemHeight = 18;
			this->listBox45MinRocDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinRocDir->Location = System::Drawing::Point(170, 435);
			this->listBox45MinRocDir->Name = L"listBox45MinRocDir";
			this->listBox45MinRocDir->Size = System::Drawing::Size(97, 22);
			this->listBox45MinRocDir->TabIndex = 213;
			this->listBox45MinRocDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinRocDir_SelectedIndexChanged);
			// 
			// label45MinRoc
			// 
			this->label45MinRoc->AutoSize = true;
			this->label45MinRoc->Location = System::Drawing::Point(26, 439);
			this->label45MinRoc->Name = L"label45MinRoc";
			this->label45MinRoc->Size = System::Drawing::Size(46, 18);
			this->label45MinRoc->TabIndex = 212;
			this->label45MinRoc->Text = L"ROC:";
			// 
			// textBox45MinVrLong
			// 
			this->textBox45MinVrLong->Location = System::Drawing::Point(557, 470);
			this->textBox45MinVrLong->Name = L"textBox45MinVrLong";
			this->textBox45MinVrLong->Size = System::Drawing::Size(124, 26);
			this->textBox45MinVrLong->TabIndex = 211;
			this->textBox45MinVrLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinVrLong_TextChanged);
			// 
			// textBox45MinVrShort
			// 
			this->textBox45MinVrShort->Location = System::Drawing::Point(353, 475);
			this->textBox45MinVrShort->Name = L"textBox45MinVrShort";
			this->textBox45MinVrShort->Size = System::Drawing::Size(124, 26);
			this->textBox45MinVrShort->TabIndex = 209;
			this->textBox45MinVrShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinVrShort_TextChanged);
			// 
			// label45MinVrLong
			// 
			this->label45MinVrLong->AutoSize = true;
			this->label45MinVrLong->Location = System::Drawing::Point(483, 478);
			this->label45MinVrLong->Name = L"label45MinVrLong";
			this->label45MinVrLong->Size = System::Drawing::Size(48, 18);
			this->label45MinVrLong->TabIndex = 210;
			this->label45MinVrLong->Text = L"Long:";
			// 
			// label45MinVrShort
			// 
			this->label45MinVrShort->AutoSize = true;
			this->label45MinVrShort->Location = System::Drawing::Point(281, 483);
			this->label45MinVrShort->Name = L"label45MinVrShort";
			this->label45MinVrShort->Size = System::Drawing::Size(52, 18);
			this->label45MinVrShort->TabIndex = 208;
			this->label45MinVrShort->Text = L"Short:";
			// 
			// label45MinVrDir
			// 
			this->label45MinVrDir->AutoSize = true;
			this->label45MinVrDir->Location = System::Drawing::Point(87, 482);
			this->label45MinVrDir->Name = L"label45MinVrDir";
			this->label45MinVrDir->Size = System::Drawing::Size(77, 18);
			this->label45MinVrDir->TabIndex = 207;
			this->label45MinVrDir->Text = L"Direction:";
			// 
			// listBox45MinVrDir
			// 
			this->listBox45MinVrDir->FormattingEnabled = true;
			this->listBox45MinVrDir->ItemHeight = 18;
			this->listBox45MinVrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinVrDir->Location = System::Drawing::Point(170, 478);
			this->listBox45MinVrDir->Name = L"listBox45MinVrDir";
			this->listBox45MinVrDir->Size = System::Drawing::Size(97, 22);
			this->listBox45MinVrDir->TabIndex = 206;
			this->listBox45MinVrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinVrDir_SelectedIndexChanged);
			// 
			// label45MinVr
			// 
			this->label45MinVr->AutoSize = true;
			this->label45MinVr->Location = System::Drawing::Point(26, 482);
			this->label45MinVr->Name = L"label45MinVr";
			this->label45MinVr->Size = System::Drawing::Size(35, 18);
			this->label45MinVr->TabIndex = 205;
			this->label45MinVr->Text = L"VR:";
			// 
			// label45MinVolDir2
			// 
			this->label45MinVolDir2->AutoSize = true;
			this->label45MinVolDir2->Location = System::Drawing::Point(483, 154);
			this->label45MinVolDir2->Name = L"label45MinVolDir2";
			this->label45MinVolDir2->Size = System::Drawing::Size(86, 18);
			this->label45MinVolDir2->TabIndex = 204;
			this->label45MinVolDir2->Text = L"Direction2:";
			// 
			// listBox45MinVolDir2
			// 
			this->listBox45MinVolDir2->FormattingEnabled = true;
			this->listBox45MinVolDir2->ItemHeight = 18;
			this->listBox45MinVolDir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinVolDir2->Location = System::Drawing::Point(575, 151);
			this->listBox45MinVolDir2->Name = L"listBox45MinVolDir2";
			this->listBox45MinVolDir2->Size = System::Drawing::Size(106, 22);
			this->listBox45MinVolDir2->TabIndex = 203;
			this->listBox45MinVolDir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinVolDir2_SelectedIndexChanged);
			// 
			// textBox45MinVol2
			// 
			this->textBox45MinVol2->Location = System::Drawing::Point(759, 146);
			this->textBox45MinVol2->Name = L"textBox45MinVol2";
			this->textBox45MinVol2->Size = System::Drawing::Size(124, 26);
			this->textBox45MinVol2->TabIndex = 202;
			this->textBox45MinVol2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinVol2_TextChanged);
			// 
			// textBox45MinVol1
			// 
			this->textBox45MinVol1->Location = System::Drawing::Point(353, 151);
			this->textBox45MinVol1->Name = L"textBox45MinVol1";
			this->textBox45MinVol1->Size = System::Drawing::Size(124, 26);
			this->textBox45MinVol1->TabIndex = 200;
			this->textBox45MinVol1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinVol1_TextChanged);
			// 
			// label45MinVol2
			// 
			this->label45MinVol2->AutoSize = true;
			this->label45MinVol2->Location = System::Drawing::Point(695, 154);
			this->label45MinVol2->Name = L"label45MinVol2";
			this->label45MinVol2->Size = System::Drawing::Size(55, 18);
			this->label45MinVol2->TabIndex = 201;
			this->label45MinVol2->Text = L"VOL2:";
			// 
			// label45MinVol1
			// 
			this->label45MinVol1->AutoSize = true;
			this->label45MinVol1->Location = System::Drawing::Point(290, 156);
			this->label45MinVol1->Name = L"label45MinVol1";
			this->label45MinVol1->Size = System::Drawing::Size(54, 18);
			this->label45MinVol1->TabIndex = 199;
			this->label45MinVol1->Text = L"VOL1:";
			// 
			// label45MinVolDir1
			// 
			this->label45MinVolDir1->AutoSize = true;
			this->label45MinVolDir1->Location = System::Drawing::Point(79, 156);
			this->label45MinVolDir1->Name = L"label45MinVolDir1";
			this->label45MinVolDir1->Size = System::Drawing::Size(85, 18);
			this->label45MinVolDir1->TabIndex = 198;
			this->label45MinVolDir1->Text = L"Direction1:";
			// 
			// listBox45MinVolDir1
			// 
			this->listBox45MinVolDir1->FormattingEnabled = true;
			this->listBox45MinVolDir1->ItemHeight = 18;
			this->listBox45MinVolDir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinVolDir1->Location = System::Drawing::Point(170, 154);
			this->listBox45MinVolDir1->Name = L"listBox45MinVolDir1";
			this->listBox45MinVolDir1->Size = System::Drawing::Size(97, 22);
			this->listBox45MinVolDir1->TabIndex = 197;
			this->listBox45MinVolDir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinVolDir1_SelectedIndexChanged);
			// 
			// label45MinVol
			// 
			this->label45MinVol->AutoSize = true;
			this->label45MinVol->Location = System::Drawing::Point(26, 158);
			this->label45MinVol->Name = L"label45MinVol";
			this->label45MinVol->Size = System::Drawing::Size(46, 18);
			this->label45MinVol->TabIndex = 196;
			this->label45MinVol->Text = L"VOL:";
			// 
			// textBox45MinWr2
			// 
			this->textBox45MinWr2->Location = System::Drawing::Point(557, 382);
			this->textBox45MinWr2->Name = L"textBox45MinWr2";
			this->textBox45MinWr2->Size = System::Drawing::Size(124, 26);
			this->textBox45MinWr2->TabIndex = 195;
			this->textBox45MinWr2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinWr2_TextChanged);
			// 
			// textBox45MinWr1
			// 
			this->textBox45MinWr1->Location = System::Drawing::Point(353, 387);
			this->textBox45MinWr1->Name = L"textBox45MinWr1";
			this->textBox45MinWr1->Size = System::Drawing::Size(124, 26);
			this->textBox45MinWr1->TabIndex = 193;
			this->textBox45MinWr1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinWr1_TextChanged);
			// 
			// label45MinWr2
			// 
			this->label45MinWr2->AutoSize = true;
			this->label45MinWr2->Location = System::Drawing::Point(483, 390);
			this->label45MinWr2->Name = L"label45MinWr2";
			this->label45MinWr2->Size = System::Drawing::Size(48, 18);
			this->label45MinWr2->TabIndex = 194;
			this->label45MinWr2->Text = L"WR2:";
			// 
			// label45MinWr1
			// 
			this->label45MinWr1->AutoSize = true;
			this->label45MinWr1->Location = System::Drawing::Point(286, 394);
			this->label45MinWr1->Name = L"label45MinWr1";
			this->label45MinWr1->Size = System::Drawing::Size(47, 18);
			this->label45MinWr1->TabIndex = 192;
			this->label45MinWr1->Text = L"WR1:";
			// 
			// label45MinWrDir
			// 
			this->label45MinWrDir->AutoSize = true;
			this->label45MinWrDir->Location = System::Drawing::Point(87, 394);
			this->label45MinWrDir->Name = L"label45MinWrDir";
			this->label45MinWrDir->Size = System::Drawing::Size(77, 18);
			this->label45MinWrDir->TabIndex = 191;
			this->label45MinWrDir->Text = L"Direction:";
			// 
			// listBox45MinWrDir
			// 
			this->listBox45MinWrDir->FormattingEnabled = true;
			this->listBox45MinWrDir->ItemHeight = 18;
			this->listBox45MinWrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinWrDir->Location = System::Drawing::Point(170, 390);
			this->listBox45MinWrDir->Name = L"listBox45MinWrDir";
			this->listBox45MinWrDir->Size = System::Drawing::Size(97, 22);
			this->listBox45MinWrDir->TabIndex = 190;
			this->listBox45MinWrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinWrDir_SelectedIndexChanged);
			// 
			// label45MinWr
			// 
			this->label45MinWr->AutoSize = true;
			this->label45MinWr->Location = System::Drawing::Point(26, 394);
			this->label45MinWr->Name = L"label45MinWr";
			this->label45MinWr->Size = System::Drawing::Size(39, 18);
			this->label45MinWr->TabIndex = 189;
			this->label45MinWr->Text = L"WR:";
			// 
			// textBox45MinRsiLong
			// 
			this->textBox45MinRsiLong->Location = System::Drawing::Point(759, 335);
			this->textBox45MinRsiLong->Name = L"textBox45MinRsiLong";
			this->textBox45MinRsiLong->Size = System::Drawing::Size(124, 26);
			this->textBox45MinRsiLong->TabIndex = 188;
			this->textBox45MinRsiLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinRsiLong_TextChanged);
			// 
			// textBox45MinRsiMiddle
			// 
			this->textBox45MinRsiMiddle->Location = System::Drawing::Point(557, 335);
			this->textBox45MinRsiMiddle->Name = L"textBox45MinRsiMiddle";
			this->textBox45MinRsiMiddle->Size = System::Drawing::Size(124, 26);
			this->textBox45MinRsiMiddle->TabIndex = 186;
			this->textBox45MinRsiMiddle->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinRsiMiddle_TextChanged);
			// 
			// textBox45MinRsiShort
			// 
			this->textBox45MinRsiShort->Location = System::Drawing::Point(353, 340);
			this->textBox45MinRsiShort->Name = L"textBox45MinRsiShort";
			this->textBox45MinRsiShort->Size = System::Drawing::Size(124, 26);
			this->textBox45MinRsiShort->TabIndex = 184;
			this->textBox45MinRsiShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinRsiShort_TextChanged);
			// 
			// label45MinRsiLong
			// 
			this->label45MinRsiLong->AutoSize = true;
			this->label45MinRsiLong->Location = System::Drawing::Point(695, 340);
			this->label45MinRsiLong->Name = L"label45MinRsiLong";
			this->label45MinRsiLong->Size = System::Drawing::Size(48, 18);
			this->label45MinRsiLong->TabIndex = 187;
			this->label45MinRsiLong->Text = L"Long:";
			// 
			// label45MinRsiMiddle
			// 
			this->label45MinRsiMiddle->AutoSize = true;
			this->label45MinRsiMiddle->Location = System::Drawing::Point(483, 343);
			this->label45MinRsiMiddle->Name = L"label45MinRsiMiddle";
			this->label45MinRsiMiddle->Size = System::Drawing::Size(62, 18);
			this->label45MinRsiMiddle->TabIndex = 185;
			this->label45MinRsiMiddle->Text = L"Middle:";
			// 
			// label45MinRsiShort
			// 
			this->label45MinRsiShort->AutoSize = true;
			this->label45MinRsiShort->Location = System::Drawing::Point(286, 347);
			this->label45MinRsiShort->Name = L"label45MinRsiShort";
			this->label45MinRsiShort->Size = System::Drawing::Size(52, 18);
			this->label45MinRsiShort->TabIndex = 183;
			this->label45MinRsiShort->Text = L"Short:";
			// 
			// label45MinRsiDir
			// 
			this->label45MinRsiDir->AutoSize = true;
			this->label45MinRsiDir->Location = System::Drawing::Point(87, 347);
			this->label45MinRsiDir->Name = L"label45MinRsiDir";
			this->label45MinRsiDir->Size = System::Drawing::Size(77, 18);
			this->label45MinRsiDir->TabIndex = 182;
			this->label45MinRsiDir->Text = L"Direction:";
			// 
			// listBox45MinRsiDir
			// 
			this->listBox45MinRsiDir->FormattingEnabled = true;
			this->listBox45MinRsiDir->ItemHeight = 18;
			this->listBox45MinRsiDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinRsiDir->Location = System::Drawing::Point(170, 343);
			this->listBox45MinRsiDir->Name = L"listBox45MinRsiDir";
			this->listBox45MinRsiDir->Size = System::Drawing::Size(97, 22);
			this->listBox45MinRsiDir->TabIndex = 181;
			this->listBox45MinRsiDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinRsiDir_SelectedIndexChanged);
			// 
			// label45MinRsi
			// 
			this->label45MinRsi->AutoSize = true;
			this->label45MinRsi->Location = System::Drawing::Point(26, 347);
			this->label45MinRsi->Name = L"label45MinRsi";
			this->label45MinRsi->Size = System::Drawing::Size(40, 18);
			this->label45MinRsi->TabIndex = 180;
			this->label45MinRsi->Text = L"RSI:";
			// 
			// textBox45MinKdjJ
			// 
			this->textBox45MinKdjJ->Location = System::Drawing::Point(759, 290);
			this->textBox45MinKdjJ->Name = L"textBox45MinKdjJ";
			this->textBox45MinKdjJ->Size = System::Drawing::Size(124, 26);
			this->textBox45MinKdjJ->TabIndex = 179;
			this->textBox45MinKdjJ->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinKdjJ_TextChanged);
			// 
			// textBox45MinKdjD
			// 
			this->textBox45MinKdjD->Location = System::Drawing::Point(557, 290);
			this->textBox45MinKdjD->Name = L"textBox45MinKdjD";
			this->textBox45MinKdjD->Size = System::Drawing::Size(124, 26);
			this->textBox45MinKdjD->TabIndex = 177;
			this->textBox45MinKdjD->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinKdjD_TextChanged);
			// 
			// textBox45MinKdjK
			// 
			this->textBox45MinKdjK->Location = System::Drawing::Point(353, 295);
			this->textBox45MinKdjK->Name = L"textBox45MinKdjK";
			this->textBox45MinKdjK->Size = System::Drawing::Size(124, 26);
			this->textBox45MinKdjK->TabIndex = 175;
			this->textBox45MinKdjK->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinKdjK_TextChanged);
			// 
			// label45MinKdjJ
			// 
			this->label45MinKdjJ->AutoSize = true;
			this->label45MinKdjJ->Location = System::Drawing::Point(695, 298);
			this->label45MinKdjJ->Name = L"label45MinKdjJ";
			this->label45MinKdjJ->Size = System::Drawing::Size(21, 18);
			this->label45MinKdjJ->TabIndex = 178;
			this->label45MinKdjJ->Text = L"J:";
			// 
			// label45MinKdjD
			// 
			this->label45MinKdjD->AutoSize = true;
			this->label45MinKdjD->Location = System::Drawing::Point(500, 298);
			this->label45MinKdjD->Name = L"label45MinKdjD";
			this->label45MinKdjD->Size = System::Drawing::Size(24, 18);
			this->label45MinKdjD->TabIndex = 176;
			this->label45MinKdjD->Text = L"D:";
			// 
			// label45MinKdjK
			// 
			this->label45MinKdjK->AutoSize = true;
			this->label45MinKdjK->Location = System::Drawing::Point(290, 300);
			this->label45MinKdjK->Name = L"label45MinKdjK";
			this->label45MinKdjK->Size = System::Drawing::Size(24, 18);
			this->label45MinKdjK->TabIndex = 174;
			this->label45MinKdjK->Text = L"K:";
			// 
			// label45MinKdjDir
			// 
			this->label45MinKdjDir->AutoSize = true;
			this->label45MinKdjDir->Location = System::Drawing::Point(87, 302);
			this->label45MinKdjDir->Name = L"label45MinKdjDir";
			this->label45MinKdjDir->Size = System::Drawing::Size(77, 18);
			this->label45MinKdjDir->TabIndex = 173;
			this->label45MinKdjDir->Text = L"Direction:";
			// 
			// listBox45MinKdjDir
			// 
			this->listBox45MinKdjDir->FormattingEnabled = true;
			this->listBox45MinKdjDir->ItemHeight = 18;
			this->listBox45MinKdjDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinKdjDir->Location = System::Drawing::Point(170, 298);
			this->listBox45MinKdjDir->Name = L"listBox45MinKdjDir";
			this->listBox45MinKdjDir->Size = System::Drawing::Size(97, 22);
			this->listBox45MinKdjDir->TabIndex = 172;
			this->listBox45MinKdjDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinKdjDir_SelectedIndexChanged);
			// 
			// label45MinKdj
			// 
			this->label45MinKdj->AutoSize = true;
			this->label45MinKdj->Location = System::Drawing::Point(26, 302);
			this->label45MinKdj->Name = L"label45MinKdj";
			this->label45MinKdj->Size = System::Drawing::Size(43, 18);
			this->label45MinKdj->TabIndex = 171;
			this->label45MinKdj->Text = L"KDJ:";
			// 
			// textBox45MinMacdDea
			// 
			this->textBox45MinMacdDea->Location = System::Drawing::Point(759, 243);
			this->textBox45MinMacdDea->Name = L"textBox45MinMacdDea";
			this->textBox45MinMacdDea->Size = System::Drawing::Size(124, 26);
			this->textBox45MinMacdDea->TabIndex = 170;
			this->textBox45MinMacdDea->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinMacdDea_TextChanged);
			// 
			// textBox45MinMacdDif
			// 
			this->textBox45MinMacdDif->Location = System::Drawing::Point(557, 243);
			this->textBox45MinMacdDif->Name = L"textBox45MinMacdDif";
			this->textBox45MinMacdDif->Size = System::Drawing::Size(124, 26);
			this->textBox45MinMacdDif->TabIndex = 168;
			this->textBox45MinMacdDif->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinMacdDif_TextChanged);
			// 
			// textBox45MinMacdMacd
			// 
			this->textBox45MinMacdMacd->Location = System::Drawing::Point(353, 248);
			this->textBox45MinMacdMacd->Name = L"textBox45MinMacdMacd";
			this->textBox45MinMacdMacd->Size = System::Drawing::Size(124, 26);
			this->textBox45MinMacdMacd->TabIndex = 166;
			this->textBox45MinMacdMacd->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinMacdMacd_TextChanged);
			// 
			// label45MinMacdDea
			// 
			this->label45MinMacdDea->AutoSize = true;
			this->label45MinMacdDea->Location = System::Drawing::Point(695, 251);
			this->label45MinMacdDea->Name = L"label45MinMacdDea";
			this->label45MinMacdDea->Size = System::Drawing::Size(40, 18);
			this->label45MinMacdDea->TabIndex = 169;
			this->label45MinMacdDea->Text = L"Dea:";
			// 
			// label45MinMacdDif
			// 
			this->label45MinMacdDif->AutoSize = true;
			this->label45MinMacdDif->Location = System::Drawing::Point(500, 251);
			this->label45MinMacdDif->Name = L"label45MinMacdDif";
			this->label45MinMacdDif->Size = System::Drawing::Size(33, 18);
			this->label45MinMacdDif->TabIndex = 167;
			this->label45MinMacdDif->Text = L"Dif:";
			// 
			// label45MinMacdMacd
			// 
			this->label45MinMacdMacd->AutoSize = true;
			this->label45MinMacdMacd->Location = System::Drawing::Point(290, 253);
			this->label45MinMacdMacd->Name = L"label45MinMacdMacd";
			this->label45MinMacdMacd->Size = System::Drawing::Size(52, 18);
			this->label45MinMacdMacd->TabIndex = 165;
			this->label45MinMacdMacd->Text = L"Macd:";
			// 
			// label45MinMacdDir
			// 
			this->label45MinMacdDir->AutoSize = true;
			this->label45MinMacdDir->Location = System::Drawing::Point(87, 255);
			this->label45MinMacdDir->Name = L"label45MinMacdDir";
			this->label45MinMacdDir->Size = System::Drawing::Size(77, 18);
			this->label45MinMacdDir->TabIndex = 164;
			this->label45MinMacdDir->Text = L"Direction:";
			// 
			// listBox45MinMacdDir
			// 
			this->listBox45MinMacdDir->FormattingEnabled = true;
			this->listBox45MinMacdDir->ItemHeight = 18;
			this->listBox45MinMacdDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinMacdDir->Location = System::Drawing::Point(170, 251);
			this->listBox45MinMacdDir->Name = L"listBox45MinMacdDir";
			this->listBox45MinMacdDir->Size = System::Drawing::Size(97, 22);
			this->listBox45MinMacdDir->TabIndex = 163;
			this->listBox45MinMacdDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinMacdDir_SelectedIndexChanged);
			// 
			// label45MinMacd
			// 
			this->label45MinMacd->AutoSize = true;
			this->label45MinMacd->Location = System::Drawing::Point(26, 255);
			this->label45MinMacd->Name = L"label45MinMacd";
			this->label45MinMacd->Size = System::Drawing::Size(60, 18);
			this->label45MinMacd->TabIndex = 162;
			this->label45MinMacd->Text = L"MACD:";
			// 
			// textBox45MinBollUpper
			// 
			this->textBox45MinBollUpper->Location = System::Drawing::Point(759, 196);
			this->textBox45MinBollUpper->Name = L"textBox45MinBollUpper";
			this->textBox45MinBollUpper->Size = System::Drawing::Size(124, 26);
			this->textBox45MinBollUpper->TabIndex = 161;
			this->textBox45MinBollUpper->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinBollUpper_TextChanged);
			// 
			// textBox45MinBollMid
			// 
			this->textBox45MinBollMid->Location = System::Drawing::Point(557, 198);
			this->textBox45MinBollMid->Name = L"textBox45MinBollMid";
			this->textBox45MinBollMid->Size = System::Drawing::Size(124, 26);
			this->textBox45MinBollMid->TabIndex = 159;
			this->textBox45MinBollMid->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinBollMid_TextChanged);
			// 
			// textBox45MinBollLow
			// 
			this->textBox45MinBollLow->Location = System::Drawing::Point(353, 200);
			this->textBox45MinBollLow->Name = L"textBox45MinBollLow";
			this->textBox45MinBollLow->Size = System::Drawing::Size(124, 26);
			this->textBox45MinBollLow->TabIndex = 157;
			this->textBox45MinBollLow->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox45MinBollLow_TextChanged);
			// 
			// label45MinBollUpper
			// 
			this->label45MinBollUpper->AutoSize = true;
			this->label45MinBollUpper->Location = System::Drawing::Point(695, 202);
			this->label45MinBollUpper->Name = L"label45MinBollUpper";
			this->label45MinBollUpper->Size = System::Drawing::Size(58, 18);
			this->label45MinBollUpper->TabIndex = 160;
			this->label45MinBollUpper->Text = L"Upper:";
			// 
			// label45MinBollMid
			// 
			this->label45MinBollMid->AutoSize = true;
			this->label45MinBollMid->Location = System::Drawing::Point(500, 204);
			this->label45MinBollMid->Name = L"label45MinBollMid";
			this->label45MinBollMid->Size = System::Drawing::Size(41, 18);
			this->label45MinBollMid->TabIndex = 158;
			this->label45MinBollMid->Text = L"Mid:";
			// 
			// label45MinBollLow
			// 
			this->label45MinBollLow->AutoSize = true;
			this->label45MinBollLow->Location = System::Drawing::Point(295, 206);
			this->label45MinBollLow->Name = L"label45MinBollLow";
			this->label45MinBollLow->Size = System::Drawing::Size(43, 18);
			this->label45MinBollLow->TabIndex = 156;
			this->label45MinBollLow->Text = L"Low:";
			// 
			// label45MinBollDir
			// 
			this->label45MinBollDir->AutoSize = true;
			this->label45MinBollDir->Location = System::Drawing::Point(87, 206);
			this->label45MinBollDir->Name = L"label45MinBollDir";
			this->label45MinBollDir->Size = System::Drawing::Size(77, 18);
			this->label45MinBollDir->TabIndex = 155;
			this->label45MinBollDir->Text = L"Direction:";
			// 
			// listBox45MinBollDir
			// 
			this->listBox45MinBollDir->FormattingEnabled = true;
			this->listBox45MinBollDir->ItemHeight = 18;
			this->listBox45MinBollDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox45MinBollDir->Location = System::Drawing::Point(170, 204);
			this->listBox45MinBollDir->Name = L"listBox45MinBollDir";
			this->listBox45MinBollDir->Size = System::Drawing::Size(97, 22);
			this->listBox45MinBollDir->TabIndex = 154;
			this->listBox45MinBollDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox45MinBollDir_SelectedIndexChanged);
			// 
			// label45MinBoll
			// 
			this->label45MinBoll->AutoSize = true;
			this->label45MinBoll->Location = System::Drawing::Point(26, 210);
			this->label45MinBoll->Name = L"label45MinBoll";
			this->label45MinBoll->Size = System::Drawing::Size(55, 18);
			this->label45MinBoll->TabIndex = 153;
			this->label45MinBoll->Text = L"BOLL:";
			// 
			// tabHour
			// 
			this->tabHour->Controls->Add(this->listBoxHourMADir6);
			this->tabHour->Controls->Add(this->labelHourMADir6);
			this->tabHour->Controls->Add(this->textBoxHourMA6);
			this->tabHour->Controls->Add(this->textBoxHourMA5);
			this->tabHour->Controls->Add(this->labelHourMA6);
			this->tabHour->Controls->Add(this->labelHourMA5);
			this->tabHour->Controls->Add(this->labelHourMADir5);
			this->tabHour->Controls->Add(this->listBoxHourMADir5);
			this->tabHour->Controls->Add(this->labelHourMA56);
			this->tabHour->Controls->Add(this->labelHourMADir4);
			this->tabHour->Controls->Add(this->listBoxHourMADir4);
			this->tabHour->Controls->Add(this->textBoxHourMA4);
			this->tabHour->Controls->Add(this->textBoxHourMA3);
			this->tabHour->Controls->Add(this->labelHourMA4);
			this->tabHour->Controls->Add(this->labelHourMA3);
			this->tabHour->Controls->Add(this->labelHourMADir3);
			this->tabHour->Controls->Add(this->listBoxHourMADir3);
			this->tabHour->Controls->Add(this->labelHourMA34);
			this->tabHour->Controls->Add(this->labelHourMADir2);
			this->tabHour->Controls->Add(this->listBoxHourMADir2);
			this->tabHour->Controls->Add(this->textBoxHourMA2);
			this->tabHour->Controls->Add(this->textBoxHourMA1);
			this->tabHour->Controls->Add(this->labelHourMA2);
			this->tabHour->Controls->Add(this->labelHourMA1);
			this->tabHour->Controls->Add(this->labelHourMADir1);
			this->tabHour->Controls->Add(this->listBoxHourMADir1);
			this->tabHour->Controls->Add(this->labelHourMA12);
			this->tabHour->Controls->Add(this->textBoxHourCciCci);
			this->tabHour->Controls->Add(this->labelHourCciCci);
			this->tabHour->Controls->Add(this->labelHourCciDir);
			this->tabHour->Controls->Add(this->listBoxHourCciDir);
			this->tabHour->Controls->Add(this->labelHourCci);
			this->tabHour->Controls->Add(this->textBoxHourCrC);
			this->tabHour->Controls->Add(this->labelHourCrC);
			this->tabHour->Controls->Add(this->textBoxHourCrB);
			this->tabHour->Controls->Add(this->labelHourCrB);
			this->tabHour->Controls->Add(this->textBoxHourCrA);
			this->tabHour->Controls->Add(this->textBoxHourCrCr);
			this->tabHour->Controls->Add(this->labelHourCrA);
			this->tabHour->Controls->Add(this->labelHourCrCr);
			this->tabHour->Controls->Add(this->labelHourCrDir);
			this->tabHour->Controls->Add(this->listBoxHourCrDir);
			this->tabHour->Controls->Add(this->labelHourCr);
			this->tabHour->Controls->Add(this->textBoxHourDmaAma);
			this->tabHour->Controls->Add(this->textBoxHourDmaDma);
			this->tabHour->Controls->Add(this->labelHourDmaAma);
			this->tabHour->Controls->Add(this->labelHourDmaDma);
			this->tabHour->Controls->Add(this->labelHourDmaDir);
			this->tabHour->Controls->Add(this->listBoxHourDmaDir);
			this->tabHour->Controls->Add(this->labelHourDma);
			this->tabHour->Controls->Add(this->textBoxHourRocRocma);
			this->tabHour->Controls->Add(this->textBoxHourRocRoc);
			this->tabHour->Controls->Add(this->labelHourRocRocma);
			this->tabHour->Controls->Add(this->labelHourRocRoc);
			this->tabHour->Controls->Add(this->labelHourRocDir);
			this->tabHour->Controls->Add(this->listBoxHourRocDir);
			this->tabHour->Controls->Add(this->labelHourRoc);
			this->tabHour->Controls->Add(this->textBoxHourVrLong);
			this->tabHour->Controls->Add(this->textBoxHourVrShort);
			this->tabHour->Controls->Add(this->labelHourVrLong);
			this->tabHour->Controls->Add(this->labelHourVrShort);
			this->tabHour->Controls->Add(this->labelHourVrDir);
			this->tabHour->Controls->Add(this->listBoxHourVrDir);
			this->tabHour->Controls->Add(this->labelHourVr);
			this->tabHour->Controls->Add(this->labelHourVolDir2);
			this->tabHour->Controls->Add(this->listBoxHourVolDir2);
			this->tabHour->Controls->Add(this->textBoxHourVol2);
			this->tabHour->Controls->Add(this->textBoxHourVol1);
			this->tabHour->Controls->Add(this->labelHourVol2);
			this->tabHour->Controls->Add(this->labelHourVol1);
			this->tabHour->Controls->Add(this->labelHourVolDir1);
			this->tabHour->Controls->Add(this->listBoxHourVolDir1);
			this->tabHour->Controls->Add(this->labelHourVol);
			this->tabHour->Controls->Add(this->textBoxHourWr2);
			this->tabHour->Controls->Add(this->textBoxHourWr1);
			this->tabHour->Controls->Add(this->labelHourWr2);
			this->tabHour->Controls->Add(this->labelHourWr1);
			this->tabHour->Controls->Add(this->labelHourWrDir);
			this->tabHour->Controls->Add(this->listBoxHourWrDir);
			this->tabHour->Controls->Add(this->labelHourWr);
			this->tabHour->Controls->Add(this->textBoxHourRsiLong);
			this->tabHour->Controls->Add(this->textBoxHourRsiMiddle);
			this->tabHour->Controls->Add(this->textBoxHourRsiShort);
			this->tabHour->Controls->Add(this->labelHourRsiLong);
			this->tabHour->Controls->Add(this->labelHourRsiMiddle);
			this->tabHour->Controls->Add(this->labelHourRsiShort);
			this->tabHour->Controls->Add(this->labelHourRsiDir);
			this->tabHour->Controls->Add(this->listBoxHourRsiDir);
			this->tabHour->Controls->Add(this->labelHourRsi);
			this->tabHour->Controls->Add(this->textBoxHourKdjJ);
			this->tabHour->Controls->Add(this->textBoxHourKdjD);
			this->tabHour->Controls->Add(this->textBoxHourKdjK);
			this->tabHour->Controls->Add(this->labelHourKdjJ);
			this->tabHour->Controls->Add(this->labelHourKdjD);
			this->tabHour->Controls->Add(this->labelHourKdjK);
			this->tabHour->Controls->Add(this->labelHourKdjDir);
			this->tabHour->Controls->Add(this->listBoxHourKdjDir);
			this->tabHour->Controls->Add(this->labelHourKdj);
			this->tabHour->Controls->Add(this->textBoxHourMacdDea);
			this->tabHour->Controls->Add(this->textBoxHourMacdDif);
			this->tabHour->Controls->Add(this->textBoxHourMacdMacd);
			this->tabHour->Controls->Add(this->labelHourMacdDea);
			this->tabHour->Controls->Add(this->labelHourMacdDif);
			this->tabHour->Controls->Add(this->labelHourMacdMacd);
			this->tabHour->Controls->Add(this->labelHourMacdDir);
			this->tabHour->Controls->Add(this->listBoxHourMacdDir);
			this->tabHour->Controls->Add(this->labelHourMacd);
			this->tabHour->Controls->Add(this->textBoxHourBollUpper);
			this->tabHour->Controls->Add(this->textBoxHourBollMid);
			this->tabHour->Controls->Add(this->textBoxHourBollLow);
			this->tabHour->Controls->Add(this->labelHourBollUpper);
			this->tabHour->Controls->Add(this->labelHourBollMid);
			this->tabHour->Controls->Add(this->labelHourBollLow);
			this->tabHour->Controls->Add(this->labelHourBollDir);
			this->tabHour->Controls->Add(this->listBoxHourBollDir);
			this->tabHour->Controls->Add(this->labelHourBoll);
			this->tabHour->Location = System::Drawing::Point(4, 27);
			this->tabHour->Name = L"tabHour";
			this->tabHour->Padding = System::Windows::Forms::Padding(3);
			this->tabHour->Size = System::Drawing::Size(1092, 869);
			this->tabHour->TabIndex = 5;
			this->tabHour->Text = L"Hour";
			this->tabHour->UseVisualStyleBackColor = true;
			// 
			// listBoxHourMADir6
			// 
			this->listBoxHourMADir6->FormattingEnabled = true;
			this->listBoxHourMADir6->ItemHeight = 18;
			this->listBoxHourMADir6->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourMADir6->Location = System::Drawing::Point(575, 103);
			this->listBoxHourMADir6->Name = L"listBoxHourMADir6";
			this->listBoxHourMADir6->Size = System::Drawing::Size(106, 22);
			this->listBoxHourMADir6->TabIndex = 269;
			this->listBoxHourMADir6->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourMADir6_SelectedIndexChanged);
			// 
			// labelHourMADir6
			// 
			this->labelHourMADir6->AutoSize = true;
			this->labelHourMADir6->Location = System::Drawing::Point(483, 107);
			this->labelHourMADir6->Name = L"labelHourMADir6";
			this->labelHourMADir6->Size = System::Drawing::Size(80, 18);
			this->labelHourMADir6->TabIndex = 268;
			this->labelHourMADir6->Text = L"MA_Dir6:";
			// 
			// textBoxHourMA6
			// 
			this->textBoxHourMA6->Location = System::Drawing::Point(759, 99);
			this->textBoxHourMA6->Name = L"textBoxHourMA6";
			this->textBoxHourMA6->Size = System::Drawing::Size(124, 26);
			this->textBoxHourMA6->TabIndex = 266;
			this->textBoxHourMA6->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourMA6_TextChanged);
			// 
			// textBoxHourMA5
			// 
			this->textBoxHourMA5->Location = System::Drawing::Point(353, 104);
			this->textBoxHourMA5->Name = L"textBoxHourMA5";
			this->textBoxHourMA5->Size = System::Drawing::Size(124, 26);
			this->textBoxHourMA5->TabIndex = 264;
			this->textBoxHourMA5->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourMA5_TextChanged);
			// 
			// labelHourMA6
			// 
			this->labelHourMA6->AutoSize = true;
			this->labelHourMA6->Location = System::Drawing::Point(695, 107);
			this->labelHourMA6->Name = L"labelHourMA6";
			this->labelHourMA6->Size = System::Drawing::Size(48, 18);
			this->labelHourMA6->TabIndex = 265;
			this->labelHourMA6->Text = L"MA6:";
			// 
			// labelHourMA5
			// 
			this->labelHourMA5->AutoSize = true;
			this->labelHourMA5->Location = System::Drawing::Point(290, 109);
			this->labelHourMA5->Name = L"labelHourMA5";
			this->labelHourMA5->Size = System::Drawing::Size(48, 18);
			this->labelHourMA5->TabIndex = 263;
			this->labelHourMA5->Text = L"MA5:";
			// 
			// labelHourMADir5
			// 
			this->labelHourMADir5->AutoSize = true;
			this->labelHourMADir5->Location = System::Drawing::Point(79, 112);
			this->labelHourMADir5->Name = L"labelHourMADir5";
			this->labelHourMADir5->Size = System::Drawing::Size(80, 18);
			this->labelHourMADir5->TabIndex = 262;
			this->labelHourMADir5->Text = L"MA_Dir5:";
			// 
			// listBoxHourMADir5
			// 
			this->listBoxHourMADir5->FormattingEnabled = true;
			this->listBoxHourMADir5->ItemHeight = 18;
			this->listBoxHourMADir5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourMADir5->Location = System::Drawing::Point(170, 107);
			this->listBoxHourMADir5->Name = L"listBoxHourMADir5";
			this->listBoxHourMADir5->Size = System::Drawing::Size(97, 22);
			this->listBoxHourMADir5->TabIndex = 261;
			this->listBoxHourMADir5->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourMADir5_SelectedIndexChanged);
			// 
			// labelHourMA56
			// 
			this->labelHourMA56->AutoSize = true;
			this->labelHourMA56->Location = System::Drawing::Point(17, 112);
			this->labelHourMA56->Name = L"labelHourMA56";
			this->labelHourMA56->Size = System::Drawing::Size(64, 18);
			this->labelHourMA56->TabIndex = 260;
			this->labelHourMA56->Text = L"MA5-6:";
			// 
			// labelHourMADir4
			// 
			this->labelHourMADir4->AutoSize = true;
			this->labelHourMADir4->Location = System::Drawing::Point(483, 60);
			this->labelHourMADir4->Name = L"labelHourMADir4";
			this->labelHourMADir4->Size = System::Drawing::Size(80, 18);
			this->labelHourMADir4->TabIndex = 259;
			this->labelHourMADir4->Text = L"MA_Dir4:";
			// 
			// listBoxHourMADir4
			// 
			this->listBoxHourMADir4->FormattingEnabled = true;
			this->listBoxHourMADir4->ItemHeight = 18;
			this->listBoxHourMADir4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourMADir4->Location = System::Drawing::Point(575, 57);
			this->listBoxHourMADir4->Name = L"listBoxHourMADir4";
			this->listBoxHourMADir4->Size = System::Drawing::Size(106, 22);
			this->listBoxHourMADir4->TabIndex = 258;
			this->listBoxHourMADir4->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourMADir4_SelectedIndexChanged);
			// 
			// textBoxHourMA4
			// 
			this->textBoxHourMA4->Location = System::Drawing::Point(759, 52);
			this->textBoxHourMA4->Name = L"textBoxHourMA4";
			this->textBoxHourMA4->Size = System::Drawing::Size(124, 26);
			this->textBoxHourMA4->TabIndex = 257;
			this->textBoxHourMA4->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourMA4_TextChanged);
			// 
			// textBoxHourMA3
			// 
			this->textBoxHourMA3->Location = System::Drawing::Point(353, 57);
			this->textBoxHourMA3->Name = L"textBoxHourMA3";
			this->textBoxHourMA3->Size = System::Drawing::Size(124, 26);
			this->textBoxHourMA3->TabIndex = 255;
			this->textBoxHourMA3->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourMA3_TextChanged);
			// 
			// labelHourMA4
			// 
			this->labelHourMA4->AutoSize = true;
			this->labelHourMA4->Location = System::Drawing::Point(695, 60);
			this->labelHourMA4->Name = L"labelHourMA4";
			this->labelHourMA4->Size = System::Drawing::Size(48, 18);
			this->labelHourMA4->TabIndex = 256;
			this->labelHourMA4->Text = L"MA4:";
			// 
			// labelHourMA3
			// 
			this->labelHourMA3->AutoSize = true;
			this->labelHourMA3->Location = System::Drawing::Point(290, 62);
			this->labelHourMA3->Name = L"labelHourMA3";
			this->labelHourMA3->Size = System::Drawing::Size(48, 18);
			this->labelHourMA3->TabIndex = 254;
			this->labelHourMA3->Text = L"MA3:";
			// 
			// labelHourMADir3
			// 
			this->labelHourMADir3->AutoSize = true;
			this->labelHourMADir3->Location = System::Drawing::Point(79, 65);
			this->labelHourMADir3->Name = L"labelHourMADir3";
			this->labelHourMADir3->Size = System::Drawing::Size(80, 18);
			this->labelHourMADir3->TabIndex = 253;
			this->labelHourMADir3->Text = L"MA_Dir3:";
			// 
			// listBoxHourMADir3
			// 
			this->listBoxHourMADir3->FormattingEnabled = true;
			this->listBoxHourMADir3->ItemHeight = 18;
			this->listBoxHourMADir3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourMADir3->Location = System::Drawing::Point(170, 60);
			this->listBoxHourMADir3->Name = L"listBoxHourMADir3";
			this->listBoxHourMADir3->Size = System::Drawing::Size(97, 22);
			this->listBoxHourMADir3->TabIndex = 252;
			this->listBoxHourMADir3->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourMADir3_SelectedIndexChanged);
			// 
			// labelHourMA34
			// 
			this->labelHourMA34->AutoSize = true;
			this->labelHourMA34->Location = System::Drawing::Point(17, 65);
			this->labelHourMA34->Name = L"labelHourMA34";
			this->labelHourMA34->Size = System::Drawing::Size(64, 18);
			this->labelHourMA34->TabIndex = 251;
			this->labelHourMA34->Text = L"MA3-4:";
			// 
			// labelHourMADir2
			// 
			this->labelHourMADir2->AutoSize = true;
			this->labelHourMADir2->Location = System::Drawing::Point(483, 19);
			this->labelHourMADir2->Name = L"labelHourMADir2";
			this->labelHourMADir2->Size = System::Drawing::Size(80, 18);
			this->labelHourMADir2->TabIndex = 250;
			this->labelHourMADir2->Text = L"MA_Dir2:";
			// 
			// listBoxHourMADir2
			// 
			this->listBoxHourMADir2->FormattingEnabled = true;
			this->listBoxHourMADir2->ItemHeight = 18;
			this->listBoxHourMADir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourMADir2->Location = System::Drawing::Point(575, 16);
			this->listBoxHourMADir2->Name = L"listBoxHourMADir2";
			this->listBoxHourMADir2->Size = System::Drawing::Size(106, 22);
			this->listBoxHourMADir2->TabIndex = 249;
			this->listBoxHourMADir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourMADir2_SelectedIndexChanged);
			// 
			// textBoxHourMA2
			// 
			this->textBoxHourMA2->Location = System::Drawing::Point(759, 11);
			this->textBoxHourMA2->Name = L"textBoxHourMA2";
			this->textBoxHourMA2->Size = System::Drawing::Size(124, 26);
			this->textBoxHourMA2->TabIndex = 248;
			this->textBoxHourMA2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourMA2_TextChanged);
			// 
			// textBoxHourMA1
			// 
			this->textBoxHourMA1->Location = System::Drawing::Point(353, 16);
			this->textBoxHourMA1->Name = L"textBoxHourMA1";
			this->textBoxHourMA1->Size = System::Drawing::Size(124, 26);
			this->textBoxHourMA1->TabIndex = 246;
			this->textBoxHourMA1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourMA1_TextChanged);
			// 
			// labelHourMA2
			// 
			this->labelHourMA2->AutoSize = true;
			this->labelHourMA2->Location = System::Drawing::Point(695, 19);
			this->labelHourMA2->Name = L"labelHourMA2";
			this->labelHourMA2->Size = System::Drawing::Size(48, 18);
			this->labelHourMA2->TabIndex = 247;
			this->labelHourMA2->Text = L"MA2:";
			// 
			// labelHourMA1
			// 
			this->labelHourMA1->AutoSize = true;
			this->labelHourMA1->Location = System::Drawing::Point(290, 21);
			this->labelHourMA1->Name = L"labelHourMA1";
			this->labelHourMA1->Size = System::Drawing::Size(47, 18);
			this->labelHourMA1->TabIndex = 245;
			this->labelHourMA1->Text = L"MA1:";
			// 
			// labelHourMADir1
			// 
			this->labelHourMADir1->AutoSize = true;
			this->labelHourMADir1->Location = System::Drawing::Point(79, 21);
			this->labelHourMADir1->Name = L"labelHourMADir1";
			this->labelHourMADir1->Size = System::Drawing::Size(79, 18);
			this->labelHourMADir1->TabIndex = 244;
			this->labelHourMADir1->Text = L"MA_Dir1:";
			// 
			// listBoxHourMADir1
			// 
			this->listBoxHourMADir1->FormattingEnabled = true;
			this->listBoxHourMADir1->ItemHeight = 18;
			this->listBoxHourMADir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourMADir1->Location = System::Drawing::Point(170, 19);
			this->listBoxHourMADir1->Name = L"listBoxHourMADir1";
			this->listBoxHourMADir1->Size = System::Drawing::Size(97, 22);
			this->listBoxHourMADir1->TabIndex = 243;
			this->listBoxHourMADir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourMADir1_SelectedIndexChanged);
			// 
			// labelHourMA12
			// 
			this->labelHourMA12->AutoSize = true;
			this->labelHourMA12->Location = System::Drawing::Point(16, 24);
			this->labelHourMA12->Name = L"labelHourMA12";
			this->labelHourMA12->Size = System::Drawing::Size(63, 18);
			this->labelHourMA12->TabIndex = 242;
			this->labelHourMA12->Text = L"MA1-2:";
			// 
			// textBoxHourCciCci
			// 
			this->textBoxHourCciCci->Location = System::Drawing::Point(353, 601);
			this->textBoxHourCciCci->Name = L"textBoxHourCciCci";
			this->textBoxHourCciCci->Size = System::Drawing::Size(124, 26);
			this->textBoxHourCciCci->TabIndex = 241;
			this->textBoxHourCciCci->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourCciCci_TextChanged);
			// 
			// labelHourCciCci
			// 
			this->labelHourCciCci->AutoSize = true;
			this->labelHourCciCci->Location = System::Drawing::Point(286, 608);
			this->labelHourCciCci->Name = L"labelHourCciCci";
			this->labelHourCciCci->Size = System::Drawing::Size(34, 18);
			this->labelHourCciCci->TabIndex = 240;
			this->labelHourCciCci->Text = L"Cci:";
			// 
			// labelHourCciDir
			// 
			this->labelHourCciDir->AutoSize = true;
			this->labelHourCciDir->Location = System::Drawing::Point(87, 608);
			this->labelHourCciDir->Name = L"labelHourCciDir";
			this->labelHourCciDir->Size = System::Drawing::Size(77, 18);
			this->labelHourCciDir->TabIndex = 239;
			this->labelHourCciDir->Text = L"Direction:";
			// 
			// listBoxHourCciDir
			// 
			this->listBoxHourCciDir->FormattingEnabled = true;
			this->listBoxHourCciDir->ItemHeight = 18;
			this->listBoxHourCciDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourCciDir->Location = System::Drawing::Point(170, 604);
			this->listBoxHourCciDir->Name = L"listBoxHourCciDir";
			this->listBoxHourCciDir->Size = System::Drawing::Size(97, 22);
			this->listBoxHourCciDir->TabIndex = 238;
			this->listBoxHourCciDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourCciDir_SelectedIndexChanged);
			// 
			// labelHourCci
			// 
			this->labelHourCci->AutoSize = true;
			this->labelHourCci->Location = System::Drawing::Point(26, 608);
			this->labelHourCci->Name = L"labelHourCci";
			this->labelHourCci->Size = System::Drawing::Size(40, 18);
			this->labelHourCci->TabIndex = 237;
			this->labelHourCci->Text = L"CCI:";
			// 
			// textBoxHourCrC
			// 
			this->textBoxHourCrC->Location = System::Drawing::Point(961, 555);
			this->textBoxHourCrC->Name = L"textBoxHourCrC";
			this->textBoxHourCrC->Size = System::Drawing::Size(124, 26);
			this->textBoxHourCrC->TabIndex = 236;
			this->textBoxHourCrC->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourCrC_TextChanged);
			// 
			// labelHourCrC
			// 
			this->labelHourCrC->AutoSize = true;
			this->labelHourCrC->Location = System::Drawing::Point(900, 563);
			this->labelHourCrC->Name = L"labelHourCrC";
			this->labelHourCrC->Size = System::Drawing::Size(23, 18);
			this->labelHourCrC->TabIndex = 235;
			this->labelHourCrC->Text = L"C:";
			// 
			// textBoxHourCrB
			// 
			this->textBoxHourCrB->Location = System::Drawing::Point(755, 555);
			this->textBoxHourCrB->Name = L"textBoxHourCrB";
			this->textBoxHourCrB->Size = System::Drawing::Size(124, 26);
			this->textBoxHourCrB->TabIndex = 234;
			this->textBoxHourCrB->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourCrB_TextChanged);
			// 
			// labelHourCrB
			// 
			this->labelHourCrB->AutoSize = true;
			this->labelHourCrB->Location = System::Drawing::Point(694, 563);
			this->labelHourCrB->Name = L"labelHourCrB";
			this->labelHourCrB->Size = System::Drawing::Size(23, 18);
			this->labelHourCrB->TabIndex = 233;
			this->labelHourCrB->Text = L"B:";
			// 
			// textBoxHourCrA
			// 
			this->textBoxHourCrA->Location = System::Drawing::Point(557, 555);
			this->textBoxHourCrA->Name = L"textBoxHourCrA";
			this->textBoxHourCrA->Size = System::Drawing::Size(124, 26);
			this->textBoxHourCrA->TabIndex = 232;
			this->textBoxHourCrA->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourCrA_TextChanged);
			// 
			// textBoxHourCrCr
			// 
			this->textBoxHourCrCr->Location = System::Drawing::Point(353, 560);
			this->textBoxHourCrCr->Name = L"textBoxHourCrCr";
			this->textBoxHourCrCr->Size = System::Drawing::Size(124, 26);
			this->textBoxHourCrCr->TabIndex = 230;
			this->textBoxHourCrCr->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourCrCr_TextChanged);
			// 
			// labelHourCrA
			// 
			this->labelHourCrA->AutoSize = true;
			this->labelHourCrA->Location = System::Drawing::Point(496, 563);
			this->labelHourCrA->Name = L"labelHourCrA";
			this->labelHourCrA->Size = System::Drawing::Size(24, 18);
			this->labelHourCrA->TabIndex = 231;
			this->labelHourCrA->Text = L"A:";
			// 
			// labelHourCrCr
			// 
			this->labelHourCrCr->AutoSize = true;
			this->labelHourCrCr->Location = System::Drawing::Point(286, 567);
			this->labelHourCrCr->Name = L"labelHourCrCr";
			this->labelHourCrCr->Size = System::Drawing::Size(30, 18);
			this->labelHourCrCr->TabIndex = 229;
			this->labelHourCrCr->Text = L"Cr:";
			// 
			// labelHourCrDir
			// 
			this->labelHourCrDir->AutoSize = true;
			this->labelHourCrDir->Location = System::Drawing::Point(87, 567);
			this->labelHourCrDir->Name = L"labelHourCrDir";
			this->labelHourCrDir->Size = System::Drawing::Size(77, 18);
			this->labelHourCrDir->TabIndex = 228;
			this->labelHourCrDir->Text = L"Direction:";
			// 
			// listBoxHourCrDir
			// 
			this->listBoxHourCrDir->FormattingEnabled = true;
			this->listBoxHourCrDir->ItemHeight = 18;
			this->listBoxHourCrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourCrDir->Location = System::Drawing::Point(170, 563);
			this->listBoxHourCrDir->Name = L"listBoxHourCrDir";
			this->listBoxHourCrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxHourCrDir->TabIndex = 227;
			this->listBoxHourCrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourCrDir_SelectedIndexChanged);
			// 
			// labelHourCr
			// 
			this->labelHourCr->AutoSize = true;
			this->labelHourCr->Location = System::Drawing::Point(26, 567);
			this->labelHourCr->Name = L"labelHourCr";
			this->labelHourCr->Size = System::Drawing::Size(34, 18);
			this->labelHourCr->TabIndex = 226;
			this->labelHourCr->Text = L"CR:";
			// 
			// textBoxHourDmaAma
			// 
			this->textBoxHourDmaAma->Location = System::Drawing::Point(557, 513);
			this->textBoxHourDmaAma->Name = L"textBoxHourDmaAma";
			this->textBoxHourDmaAma->Size = System::Drawing::Size(124, 26);
			this->textBoxHourDmaAma->TabIndex = 225;
			this->textBoxHourDmaAma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourDmaAma_TextChanged);
			// 
			// textBoxHourDmaDma
			// 
			this->textBoxHourDmaDma->Location = System::Drawing::Point(353, 518);
			this->textBoxHourDmaDma->Name = L"textBoxHourDmaDma";
			this->textBoxHourDmaDma->Size = System::Drawing::Size(124, 26);
			this->textBoxHourDmaDma->TabIndex = 223;
			this->textBoxHourDmaDma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourDmaDma_TextChanged);
			// 
			// labelHourDmaAma
			// 
			this->labelHourDmaAma->AutoSize = true;
			this->labelHourDmaAma->Location = System::Drawing::Point(483, 521);
			this->labelHourDmaAma->Name = L"labelHourDmaAma";
			this->labelHourDmaAma->Size = System::Drawing::Size(46, 18);
			this->labelHourDmaAma->TabIndex = 224;
			this->labelHourDmaAma->Text = L"Ama:";
			// 
			// labelHourDmaDma
			// 
			this->labelHourDmaDma->AutoSize = true;
			this->labelHourDmaDma->Location = System::Drawing::Point(286, 525);
			this->labelHourDmaDma->Name = L"labelHourDmaDma";
			this->labelHourDmaDma->Size = System::Drawing::Size(46, 18);
			this->labelHourDmaDma->TabIndex = 222;
			this->labelHourDmaDma->Text = L"Dma:";
			// 
			// labelHourDmaDir
			// 
			this->labelHourDmaDir->AutoSize = true;
			this->labelHourDmaDir->Location = System::Drawing::Point(87, 525);
			this->labelHourDmaDir->Name = L"labelHourDmaDir";
			this->labelHourDmaDir->Size = System::Drawing::Size(77, 18);
			this->labelHourDmaDir->TabIndex = 221;
			this->labelHourDmaDir->Text = L"Direction:";
			// 
			// listBoxHourDmaDir
			// 
			this->listBoxHourDmaDir->FormattingEnabled = true;
			this->listBoxHourDmaDir->ItemHeight = 18;
			this->listBoxHourDmaDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourDmaDir->Location = System::Drawing::Point(170, 521);
			this->listBoxHourDmaDir->Name = L"listBoxHourDmaDir";
			this->listBoxHourDmaDir->Size = System::Drawing::Size(97, 22);
			this->listBoxHourDmaDir->TabIndex = 220;
			this->listBoxHourDmaDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourDmaDir_SelectedIndexChanged);
			// 
			// labelHourDma
			// 
			this->labelHourDma->AutoSize = true;
			this->labelHourDma->Location = System::Drawing::Point(26, 525);
			this->labelHourDma->Name = L"labelHourDma";
			this->labelHourDma->Size = System::Drawing::Size(50, 18);
			this->labelHourDma->TabIndex = 219;
			this->labelHourDma->Text = L"DMA:";
			// 
			// textBoxHourRocRocma
			// 
			this->textBoxHourRocRocma->Location = System::Drawing::Point(557, 427);
			this->textBoxHourRocRocma->Name = L"textBoxHourRocRocma";
			this->textBoxHourRocRocma->Size = System::Drawing::Size(124, 26);
			this->textBoxHourRocRocma->TabIndex = 218;
			this->textBoxHourRocRocma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourRocRocma_TextChanged);
			// 
			// textBoxHourRocRoc
			// 
			this->textBoxHourRocRoc->Location = System::Drawing::Point(353, 432);
			this->textBoxHourRocRoc->Name = L"textBoxHourRocRoc";
			this->textBoxHourRocRoc->Size = System::Drawing::Size(124, 26);
			this->textBoxHourRocRoc->TabIndex = 216;
			this->textBoxHourRocRoc->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourRocRoc_TextChanged);
			// 
			// labelHourRocRocma
			// 
			this->labelHourRocRocma->AutoSize = true;
			this->labelHourRocRocma->Location = System::Drawing::Point(483, 435);
			this->labelHourRocRocma->Name = L"labelHourRocRocma";
			this->labelHourRocRocma->Size = System::Drawing::Size(71, 18);
			this->labelHourRocRocma->TabIndex = 217;
			this->labelHourRocRocma->Text = L"Roc_ma:";
			// 
			// labelHourRocRoc
			// 
			this->labelHourRocRoc->AutoSize = true;
			this->labelHourRocRoc->Location = System::Drawing::Point(286, 439);
			this->labelHourRocRoc->Name = L"labelHourRocRoc";
			this->labelHourRocRoc->Size = System::Drawing::Size(39, 18);
			this->labelHourRocRoc->TabIndex = 215;
			this->labelHourRocRoc->Text = L"Roc:";
			// 
			// labelHourRocDir
			// 
			this->labelHourRocDir->AutoSize = true;
			this->labelHourRocDir->Location = System::Drawing::Point(87, 439);
			this->labelHourRocDir->Name = L"labelHourRocDir";
			this->labelHourRocDir->Size = System::Drawing::Size(77, 18);
			this->labelHourRocDir->TabIndex = 214;
			this->labelHourRocDir->Text = L"Direction:";
			// 
			// listBoxHourRocDir
			// 
			this->listBoxHourRocDir->FormattingEnabled = true;
			this->listBoxHourRocDir->ItemHeight = 18;
			this->listBoxHourRocDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourRocDir->Location = System::Drawing::Point(170, 435);
			this->listBoxHourRocDir->Name = L"listBoxHourRocDir";
			this->listBoxHourRocDir->Size = System::Drawing::Size(97, 22);
			this->listBoxHourRocDir->TabIndex = 213;
			this->listBoxHourRocDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourRocDir_SelectedIndexChanged);
			// 
			// labelHourRoc
			// 
			this->labelHourRoc->AutoSize = true;
			this->labelHourRoc->Location = System::Drawing::Point(26, 439);
			this->labelHourRoc->Name = L"labelHourRoc";
			this->labelHourRoc->Size = System::Drawing::Size(46, 18);
			this->labelHourRoc->TabIndex = 212;
			this->labelHourRoc->Text = L"ROC:";
			// 
			// textBoxHourVrLong
			// 
			this->textBoxHourVrLong->Location = System::Drawing::Point(557, 470);
			this->textBoxHourVrLong->Name = L"textBoxHourVrLong";
			this->textBoxHourVrLong->Size = System::Drawing::Size(124, 26);
			this->textBoxHourVrLong->TabIndex = 211;
			this->textBoxHourVrLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourVrLong_TextChanged);
			// 
			// textBoxHourVrShort
			// 
			this->textBoxHourVrShort->Location = System::Drawing::Point(353, 475);
			this->textBoxHourVrShort->Name = L"textBoxHourVrShort";
			this->textBoxHourVrShort->Size = System::Drawing::Size(124, 26);
			this->textBoxHourVrShort->TabIndex = 209;
			this->textBoxHourVrShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourVrShort_TextChanged);
			// 
			// labelHourVrLong
			// 
			this->labelHourVrLong->AutoSize = true;
			this->labelHourVrLong->Location = System::Drawing::Point(483, 478);
			this->labelHourVrLong->Name = L"labelHourVrLong";
			this->labelHourVrLong->Size = System::Drawing::Size(48, 18);
			this->labelHourVrLong->TabIndex = 210;
			this->labelHourVrLong->Text = L"Long:";
			// 
			// labelHourVrShort
			// 
			this->labelHourVrShort->AutoSize = true;
			this->labelHourVrShort->Location = System::Drawing::Point(281, 483);
			this->labelHourVrShort->Name = L"labelHourVrShort";
			this->labelHourVrShort->Size = System::Drawing::Size(52, 18);
			this->labelHourVrShort->TabIndex = 208;
			this->labelHourVrShort->Text = L"Short:";
			// 
			// labelHourVrDir
			// 
			this->labelHourVrDir->AutoSize = true;
			this->labelHourVrDir->Location = System::Drawing::Point(87, 482);
			this->labelHourVrDir->Name = L"labelHourVrDir";
			this->labelHourVrDir->Size = System::Drawing::Size(77, 18);
			this->labelHourVrDir->TabIndex = 207;
			this->labelHourVrDir->Text = L"Direction:";
			// 
			// listBoxHourVrDir
			// 
			this->listBoxHourVrDir->FormattingEnabled = true;
			this->listBoxHourVrDir->ItemHeight = 18;
			this->listBoxHourVrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourVrDir->Location = System::Drawing::Point(170, 478);
			this->listBoxHourVrDir->Name = L"listBoxHourVrDir";
			this->listBoxHourVrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxHourVrDir->TabIndex = 206;
			this->listBoxHourVrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourVrDir_SelectedIndexChanged);
			// 
			// labelHourVr
			// 
			this->labelHourVr->AutoSize = true;
			this->labelHourVr->Location = System::Drawing::Point(26, 482);
			this->labelHourVr->Name = L"labelHourVr";
			this->labelHourVr->Size = System::Drawing::Size(35, 18);
			this->labelHourVr->TabIndex = 205;
			this->labelHourVr->Text = L"VR:";
			// 
			// labelHourVolDir2
			// 
			this->labelHourVolDir2->AutoSize = true;
			this->labelHourVolDir2->Location = System::Drawing::Point(483, 154);
			this->labelHourVolDir2->Name = L"labelHourVolDir2";
			this->labelHourVolDir2->Size = System::Drawing::Size(86, 18);
			this->labelHourVolDir2->TabIndex = 204;
			this->labelHourVolDir2->Text = L"Direction2:";
			// 
			// listBoxHourVolDir2
			// 
			this->listBoxHourVolDir2->FormattingEnabled = true;
			this->listBoxHourVolDir2->ItemHeight = 18;
			this->listBoxHourVolDir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourVolDir2->Location = System::Drawing::Point(575, 151);
			this->listBoxHourVolDir2->Name = L"listBoxHourVolDir2";
			this->listBoxHourVolDir2->Size = System::Drawing::Size(106, 22);
			this->listBoxHourVolDir2->TabIndex = 203;
			this->listBoxHourVolDir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourVolDir2_SelectedIndexChanged);
			// 
			// textBoxHourVol2
			// 
			this->textBoxHourVol2->Location = System::Drawing::Point(759, 146);
			this->textBoxHourVol2->Name = L"textBoxHourVol2";
			this->textBoxHourVol2->Size = System::Drawing::Size(124, 26);
			this->textBoxHourVol2->TabIndex = 202;
			this->textBoxHourVol2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourVol2_TextChanged);
			// 
			// textBoxHourVol1
			// 
			this->textBoxHourVol1->Location = System::Drawing::Point(353, 151);
			this->textBoxHourVol1->Name = L"textBoxHourVol1";
			this->textBoxHourVol1->Size = System::Drawing::Size(124, 26);
			this->textBoxHourVol1->TabIndex = 200;
			this->textBoxHourVol1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourVol1_TextChanged);
			// 
			// labelHourVol2
			// 
			this->labelHourVol2->AutoSize = true;
			this->labelHourVol2->Location = System::Drawing::Point(695, 154);
			this->labelHourVol2->Name = L"labelHourVol2";
			this->labelHourVol2->Size = System::Drawing::Size(55, 18);
			this->labelHourVol2->TabIndex = 201;
			this->labelHourVol2->Text = L"VOL2:";
			// 
			// labelHourVol1
			// 
			this->labelHourVol1->AutoSize = true;
			this->labelHourVol1->Location = System::Drawing::Point(290, 156);
			this->labelHourVol1->Name = L"labelHourVol1";
			this->labelHourVol1->Size = System::Drawing::Size(54, 18);
			this->labelHourVol1->TabIndex = 199;
			this->labelHourVol1->Text = L"VOL1:";
			// 
			// labelHourVolDir1
			// 
			this->labelHourVolDir1->AutoSize = true;
			this->labelHourVolDir1->Location = System::Drawing::Point(79, 156);
			this->labelHourVolDir1->Name = L"labelHourVolDir1";
			this->labelHourVolDir1->Size = System::Drawing::Size(85, 18);
			this->labelHourVolDir1->TabIndex = 198;
			this->labelHourVolDir1->Text = L"Direction1:";
			// 
			// listBoxHourVolDir1
			// 
			this->listBoxHourVolDir1->FormattingEnabled = true;
			this->listBoxHourVolDir1->ItemHeight = 18;
			this->listBoxHourVolDir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourVolDir1->Location = System::Drawing::Point(170, 154);
			this->listBoxHourVolDir1->Name = L"listBoxHourVolDir1";
			this->listBoxHourVolDir1->Size = System::Drawing::Size(97, 22);
			this->listBoxHourVolDir1->TabIndex = 197;
			this->listBoxHourVolDir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourVolDir1_SelectedIndexChanged);
			// 
			// labelHourVol
			// 
			this->labelHourVol->AutoSize = true;
			this->labelHourVol->Location = System::Drawing::Point(26, 158);
			this->labelHourVol->Name = L"labelHourVol";
			this->labelHourVol->Size = System::Drawing::Size(46, 18);
			this->labelHourVol->TabIndex = 196;
			this->labelHourVol->Text = L"VOL:";
			// 
			// textBoxHourWr2
			// 
			this->textBoxHourWr2->Location = System::Drawing::Point(557, 382);
			this->textBoxHourWr2->Name = L"textBoxHourWr2";
			this->textBoxHourWr2->Size = System::Drawing::Size(124, 26);
			this->textBoxHourWr2->TabIndex = 195;
			this->textBoxHourWr2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourWr2_TextChanged);
			// 
			// textBoxHourWr1
			// 
			this->textBoxHourWr1->Location = System::Drawing::Point(353, 387);
			this->textBoxHourWr1->Name = L"textBoxHourWr1";
			this->textBoxHourWr1->Size = System::Drawing::Size(124, 26);
			this->textBoxHourWr1->TabIndex = 193;
			this->textBoxHourWr1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourWr1_TextChanged);
			// 
			// labelHourWr2
			// 
			this->labelHourWr2->AutoSize = true;
			this->labelHourWr2->Location = System::Drawing::Point(483, 390);
			this->labelHourWr2->Name = L"labelHourWr2";
			this->labelHourWr2->Size = System::Drawing::Size(48, 18);
			this->labelHourWr2->TabIndex = 194;
			this->labelHourWr2->Text = L"WR2:";
			// 
			// labelHourWr1
			// 
			this->labelHourWr1->AutoSize = true;
			this->labelHourWr1->Location = System::Drawing::Point(286, 394);
			this->labelHourWr1->Name = L"labelHourWr1";
			this->labelHourWr1->Size = System::Drawing::Size(47, 18);
			this->labelHourWr1->TabIndex = 192;
			this->labelHourWr1->Text = L"WR1:";
			// 
			// labelHourWrDir
			// 
			this->labelHourWrDir->AutoSize = true;
			this->labelHourWrDir->Location = System::Drawing::Point(87, 394);
			this->labelHourWrDir->Name = L"labelHourWrDir";
			this->labelHourWrDir->Size = System::Drawing::Size(77, 18);
			this->labelHourWrDir->TabIndex = 191;
			this->labelHourWrDir->Text = L"Direction:";
			// 
			// listBoxHourWrDir
			// 
			this->listBoxHourWrDir->FormattingEnabled = true;
			this->listBoxHourWrDir->ItemHeight = 18;
			this->listBoxHourWrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourWrDir->Location = System::Drawing::Point(170, 390);
			this->listBoxHourWrDir->Name = L"listBoxHourWrDir";
			this->listBoxHourWrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxHourWrDir->TabIndex = 190;
			this->listBoxHourWrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourWrDir_SelectedIndexChanged);
			// 
			// labelHourWr
			// 
			this->labelHourWr->AutoSize = true;
			this->labelHourWr->Location = System::Drawing::Point(26, 394);
			this->labelHourWr->Name = L"labelHourWr";
			this->labelHourWr->Size = System::Drawing::Size(39, 18);
			this->labelHourWr->TabIndex = 189;
			this->labelHourWr->Text = L"WR:";
			// 
			// textBoxHourRsiLong
			// 
			this->textBoxHourRsiLong->Location = System::Drawing::Point(759, 335);
			this->textBoxHourRsiLong->Name = L"textBoxHourRsiLong";
			this->textBoxHourRsiLong->Size = System::Drawing::Size(124, 26);
			this->textBoxHourRsiLong->TabIndex = 188;
			this->textBoxHourRsiLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourRsiLong_TextChanged);
			// 
			// textBoxHourRsiMiddle
			// 
			this->textBoxHourRsiMiddle->Location = System::Drawing::Point(557, 335);
			this->textBoxHourRsiMiddle->Name = L"textBoxHourRsiMiddle";
			this->textBoxHourRsiMiddle->Size = System::Drawing::Size(124, 26);
			this->textBoxHourRsiMiddle->TabIndex = 186;
			this->textBoxHourRsiMiddle->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourRsiMiddle_TextChanged);
			// 
			// textBoxHourRsiShort
			// 
			this->textBoxHourRsiShort->Location = System::Drawing::Point(353, 340);
			this->textBoxHourRsiShort->Name = L"textBoxHourRsiShort";
			this->textBoxHourRsiShort->Size = System::Drawing::Size(124, 26);
			this->textBoxHourRsiShort->TabIndex = 184;
			this->textBoxHourRsiShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourRsiShort_TextChanged);
			// 
			// labelHourRsiLong
			// 
			this->labelHourRsiLong->AutoSize = true;
			this->labelHourRsiLong->Location = System::Drawing::Point(695, 340);
			this->labelHourRsiLong->Name = L"labelHourRsiLong";
			this->labelHourRsiLong->Size = System::Drawing::Size(48, 18);
			this->labelHourRsiLong->TabIndex = 187;
			this->labelHourRsiLong->Text = L"Long:";
			// 
			// labelHourRsiMiddle
			// 
			this->labelHourRsiMiddle->AutoSize = true;
			this->labelHourRsiMiddle->Location = System::Drawing::Point(483, 343);
			this->labelHourRsiMiddle->Name = L"labelHourRsiMiddle";
			this->labelHourRsiMiddle->Size = System::Drawing::Size(62, 18);
			this->labelHourRsiMiddle->TabIndex = 185;
			this->labelHourRsiMiddle->Text = L"Middle:";
			// 
			// labelHourRsiShort
			// 
			this->labelHourRsiShort->AutoSize = true;
			this->labelHourRsiShort->Location = System::Drawing::Point(286, 347);
			this->labelHourRsiShort->Name = L"labelHourRsiShort";
			this->labelHourRsiShort->Size = System::Drawing::Size(52, 18);
			this->labelHourRsiShort->TabIndex = 183;
			this->labelHourRsiShort->Text = L"Short:";
			// 
			// labelHourRsiDir
			// 
			this->labelHourRsiDir->AutoSize = true;
			this->labelHourRsiDir->Location = System::Drawing::Point(87, 347);
			this->labelHourRsiDir->Name = L"labelHourRsiDir";
			this->labelHourRsiDir->Size = System::Drawing::Size(77, 18);
			this->labelHourRsiDir->TabIndex = 182;
			this->labelHourRsiDir->Text = L"Direction:";
			// 
			// listBoxHourRsiDir
			// 
			this->listBoxHourRsiDir->FormattingEnabled = true;
			this->listBoxHourRsiDir->ItemHeight = 18;
			this->listBoxHourRsiDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourRsiDir->Location = System::Drawing::Point(170, 343);
			this->listBoxHourRsiDir->Name = L"listBoxHourRsiDir";
			this->listBoxHourRsiDir->Size = System::Drawing::Size(97, 22);
			this->listBoxHourRsiDir->TabIndex = 181;
			this->listBoxHourRsiDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourRsiDir_SelectedIndexChanged);
			// 
			// labelHourRsi
			// 
			this->labelHourRsi->AutoSize = true;
			this->labelHourRsi->Location = System::Drawing::Point(26, 347);
			this->labelHourRsi->Name = L"labelHourRsi";
			this->labelHourRsi->Size = System::Drawing::Size(40, 18);
			this->labelHourRsi->TabIndex = 180;
			this->labelHourRsi->Text = L"RSI:";
			// 
			// textBoxHourKdjJ
			// 
			this->textBoxHourKdjJ->Location = System::Drawing::Point(759, 290);
			this->textBoxHourKdjJ->Name = L"textBoxHourKdjJ";
			this->textBoxHourKdjJ->Size = System::Drawing::Size(124, 26);
			this->textBoxHourKdjJ->TabIndex = 179;
			this->textBoxHourKdjJ->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourKdjJ_TextChanged);
			// 
			// textBoxHourKdjD
			// 
			this->textBoxHourKdjD->Location = System::Drawing::Point(557, 290);
			this->textBoxHourKdjD->Name = L"textBoxHourKdjD";
			this->textBoxHourKdjD->Size = System::Drawing::Size(124, 26);
			this->textBoxHourKdjD->TabIndex = 177;
			this->textBoxHourKdjD->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourKdjD_TextChanged);
			// 
			// textBoxHourKdjK
			// 
			this->textBoxHourKdjK->Location = System::Drawing::Point(353, 295);
			this->textBoxHourKdjK->Name = L"textBoxHourKdjK";
			this->textBoxHourKdjK->Size = System::Drawing::Size(124, 26);
			this->textBoxHourKdjK->TabIndex = 175;
			this->textBoxHourKdjK->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourKdjK_TextChanged);
			// 
			// labelHourKdjJ
			// 
			this->labelHourKdjJ->AutoSize = true;
			this->labelHourKdjJ->Location = System::Drawing::Point(695, 298);
			this->labelHourKdjJ->Name = L"labelHourKdjJ";
			this->labelHourKdjJ->Size = System::Drawing::Size(21, 18);
			this->labelHourKdjJ->TabIndex = 178;
			this->labelHourKdjJ->Text = L"J:";
			// 
			// labelHourKdjD
			// 
			this->labelHourKdjD->AutoSize = true;
			this->labelHourKdjD->Location = System::Drawing::Point(500, 298);
			this->labelHourKdjD->Name = L"labelHourKdjD";
			this->labelHourKdjD->Size = System::Drawing::Size(24, 18);
			this->labelHourKdjD->TabIndex = 176;
			this->labelHourKdjD->Text = L"D:";
			// 
			// labelHourKdjK
			// 
			this->labelHourKdjK->AutoSize = true;
			this->labelHourKdjK->Location = System::Drawing::Point(290, 300);
			this->labelHourKdjK->Name = L"labelHourKdjK";
			this->labelHourKdjK->Size = System::Drawing::Size(24, 18);
			this->labelHourKdjK->TabIndex = 174;
			this->labelHourKdjK->Text = L"K:";
			// 
			// labelHourKdjDir
			// 
			this->labelHourKdjDir->AutoSize = true;
			this->labelHourKdjDir->Location = System::Drawing::Point(87, 302);
			this->labelHourKdjDir->Name = L"labelHourKdjDir";
			this->labelHourKdjDir->Size = System::Drawing::Size(77, 18);
			this->labelHourKdjDir->TabIndex = 173;
			this->labelHourKdjDir->Text = L"Direction:";
			// 
			// listBoxHourKdjDir
			// 
			this->listBoxHourKdjDir->FormattingEnabled = true;
			this->listBoxHourKdjDir->ItemHeight = 18;
			this->listBoxHourKdjDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourKdjDir->Location = System::Drawing::Point(170, 298);
			this->listBoxHourKdjDir->Name = L"listBoxHourKdjDir";
			this->listBoxHourKdjDir->Size = System::Drawing::Size(97, 22);
			this->listBoxHourKdjDir->TabIndex = 172;
			this->listBoxHourKdjDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourKdjDir_SelectedIndexChanged);
			// 
			// labelHourKdj
			// 
			this->labelHourKdj->AutoSize = true;
			this->labelHourKdj->Location = System::Drawing::Point(26, 302);
			this->labelHourKdj->Name = L"labelHourKdj";
			this->labelHourKdj->Size = System::Drawing::Size(43, 18);
			this->labelHourKdj->TabIndex = 171;
			this->labelHourKdj->Text = L"KDJ:";
			// 
			// textBoxHourMacdDea
			// 
			this->textBoxHourMacdDea->Location = System::Drawing::Point(759, 243);
			this->textBoxHourMacdDea->Name = L"textBoxHourMacdDea";
			this->textBoxHourMacdDea->Size = System::Drawing::Size(124, 26);
			this->textBoxHourMacdDea->TabIndex = 170;
			this->textBoxHourMacdDea->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourMacdDea_TextChanged);
			// 
			// textBoxHourMacdDif
			// 
			this->textBoxHourMacdDif->Location = System::Drawing::Point(557, 243);
			this->textBoxHourMacdDif->Name = L"textBoxHourMacdDif";
			this->textBoxHourMacdDif->Size = System::Drawing::Size(124, 26);
			this->textBoxHourMacdDif->TabIndex = 168;
			this->textBoxHourMacdDif->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourMacdDif_TextChanged);
			// 
			// textBoxHourMacdMacd
			// 
			this->textBoxHourMacdMacd->Location = System::Drawing::Point(353, 248);
			this->textBoxHourMacdMacd->Name = L"textBoxHourMacdMacd";
			this->textBoxHourMacdMacd->Size = System::Drawing::Size(124, 26);
			this->textBoxHourMacdMacd->TabIndex = 166;
			this->textBoxHourMacdMacd->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourMacdMacd_TextChanged);
			// 
			// labelHourMacdDea
			// 
			this->labelHourMacdDea->AutoSize = true;
			this->labelHourMacdDea->Location = System::Drawing::Point(695, 251);
			this->labelHourMacdDea->Name = L"labelHourMacdDea";
			this->labelHourMacdDea->Size = System::Drawing::Size(40, 18);
			this->labelHourMacdDea->TabIndex = 169;
			this->labelHourMacdDea->Text = L"Dea:";
			// 
			// labelHourMacdDif
			// 
			this->labelHourMacdDif->AutoSize = true;
			this->labelHourMacdDif->Location = System::Drawing::Point(500, 251);
			this->labelHourMacdDif->Name = L"labelHourMacdDif";
			this->labelHourMacdDif->Size = System::Drawing::Size(33, 18);
			this->labelHourMacdDif->TabIndex = 167;
			this->labelHourMacdDif->Text = L"Dif:";
			// 
			// labelHourMacdMacd
			// 
			this->labelHourMacdMacd->AutoSize = true;
			this->labelHourMacdMacd->Location = System::Drawing::Point(290, 253);
			this->labelHourMacdMacd->Name = L"labelHourMacdMacd";
			this->labelHourMacdMacd->Size = System::Drawing::Size(52, 18);
			this->labelHourMacdMacd->TabIndex = 165;
			this->labelHourMacdMacd->Text = L"Macd:";
			// 
			// labelHourMacdDir
			// 
			this->labelHourMacdDir->AutoSize = true;
			this->labelHourMacdDir->Location = System::Drawing::Point(87, 255);
			this->labelHourMacdDir->Name = L"labelHourMacdDir";
			this->labelHourMacdDir->Size = System::Drawing::Size(77, 18);
			this->labelHourMacdDir->TabIndex = 164;
			this->labelHourMacdDir->Text = L"Direction:";
			// 
			// listBoxHourMacdDir
			// 
			this->listBoxHourMacdDir->FormattingEnabled = true;
			this->listBoxHourMacdDir->ItemHeight = 18;
			this->listBoxHourMacdDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourMacdDir->Location = System::Drawing::Point(170, 251);
			this->listBoxHourMacdDir->Name = L"listBoxHourMacdDir";
			this->listBoxHourMacdDir->Size = System::Drawing::Size(97, 22);
			this->listBoxHourMacdDir->TabIndex = 163;
			this->listBoxHourMacdDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourMacdDir_SelectedIndexChanged);
			// 
			// labelHourMacd
			// 
			this->labelHourMacd->AutoSize = true;
			this->labelHourMacd->Location = System::Drawing::Point(26, 255);
			this->labelHourMacd->Name = L"labelHourMacd";
			this->labelHourMacd->Size = System::Drawing::Size(60, 18);
			this->labelHourMacd->TabIndex = 162;
			this->labelHourMacd->Text = L"MACD:";
			// 
			// textBoxHourBollUpper
			// 
			this->textBoxHourBollUpper->Location = System::Drawing::Point(759, 196);
			this->textBoxHourBollUpper->Name = L"textBoxHourBollUpper";
			this->textBoxHourBollUpper->Size = System::Drawing::Size(124, 26);
			this->textBoxHourBollUpper->TabIndex = 161;
			this->textBoxHourBollUpper->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourBollUpper_TextChanged);
			// 
			// textBoxHourBollMid
			// 
			this->textBoxHourBollMid->Location = System::Drawing::Point(557, 198);
			this->textBoxHourBollMid->Name = L"textBoxHourBollMid";
			this->textBoxHourBollMid->Size = System::Drawing::Size(124, 26);
			this->textBoxHourBollMid->TabIndex = 159;
			this->textBoxHourBollMid->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourBollMid_TextChanged);
			// 
			// textBoxHourBollLow
			// 
			this->textBoxHourBollLow->Location = System::Drawing::Point(353, 200);
			this->textBoxHourBollLow->Name = L"textBoxHourBollLow";
			this->textBoxHourBollLow->Size = System::Drawing::Size(124, 26);
			this->textBoxHourBollLow->TabIndex = 157;
			this->textBoxHourBollLow->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxHourBollLow_TextChanged);
			// 
			// labelHourBollUpper
			// 
			this->labelHourBollUpper->AutoSize = true;
			this->labelHourBollUpper->Location = System::Drawing::Point(695, 202);
			this->labelHourBollUpper->Name = L"labelHourBollUpper";
			this->labelHourBollUpper->Size = System::Drawing::Size(58, 18);
			this->labelHourBollUpper->TabIndex = 160;
			this->labelHourBollUpper->Text = L"Upper:";
			// 
			// labelHourBollMid
			// 
			this->labelHourBollMid->AutoSize = true;
			this->labelHourBollMid->Location = System::Drawing::Point(500, 204);
			this->labelHourBollMid->Name = L"labelHourBollMid";
			this->labelHourBollMid->Size = System::Drawing::Size(41, 18);
			this->labelHourBollMid->TabIndex = 158;
			this->labelHourBollMid->Text = L"Mid:";
			// 
			// labelHourBollLow
			// 
			this->labelHourBollLow->AutoSize = true;
			this->labelHourBollLow->Location = System::Drawing::Point(295, 206);
			this->labelHourBollLow->Name = L"labelHourBollLow";
			this->labelHourBollLow->Size = System::Drawing::Size(43, 18);
			this->labelHourBollLow->TabIndex = 156;
			this->labelHourBollLow->Text = L"Low:";
			// 
			// labelHourBollDir
			// 
			this->labelHourBollDir->AutoSize = true;
			this->labelHourBollDir->Location = System::Drawing::Point(87, 206);
			this->labelHourBollDir->Name = L"labelHourBollDir";
			this->labelHourBollDir->Size = System::Drawing::Size(77, 18);
			this->labelHourBollDir->TabIndex = 155;
			this->labelHourBollDir->Text = L"Direction:";
			// 
			// listBoxHourBollDir
			// 
			this->listBoxHourBollDir->FormattingEnabled = true;
			this->listBoxHourBollDir->ItemHeight = 18;
			this->listBoxHourBollDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxHourBollDir->Location = System::Drawing::Point(170, 204);
			this->listBoxHourBollDir->Name = L"listBoxHourBollDir";
			this->listBoxHourBollDir->Size = System::Drawing::Size(97, 22);
			this->listBoxHourBollDir->TabIndex = 154;
			this->listBoxHourBollDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxHourBollDir_SelectedIndexChanged);
			// 
			// labelHourBoll
			// 
			this->labelHourBoll->AutoSize = true;
			this->labelHourBoll->Location = System::Drawing::Point(26, 210);
			this->labelHourBoll->Name = L"labelHourBoll";
			this->labelHourBoll->Size = System::Drawing::Size(55, 18);
			this->labelHourBoll->TabIndex = 153;
			this->labelHourBoll->Text = L"BOLL:";
			// 
			// tab4Hour
			// 
			this->tab4Hour->Controls->Add(this->listBox4HourMADir6);
			this->tab4Hour->Controls->Add(this->label4HourMADir6);
			this->tab4Hour->Controls->Add(this->textBox4HourMA6);
			this->tab4Hour->Controls->Add(this->textBox4HourMA5);
			this->tab4Hour->Controls->Add(this->label4HourMA6);
			this->tab4Hour->Controls->Add(this->label4HourMA5);
			this->tab4Hour->Controls->Add(this->label4HourMADir5);
			this->tab4Hour->Controls->Add(this->listBox4HourMADir5);
			this->tab4Hour->Controls->Add(this->label4HourMA56);
			this->tab4Hour->Controls->Add(this->label4HourMADir4);
			this->tab4Hour->Controls->Add(this->listBox4HourMADir4);
			this->tab4Hour->Controls->Add(this->textBox4HourMA4);
			this->tab4Hour->Controls->Add(this->textBox4HourMA3);
			this->tab4Hour->Controls->Add(this->label4HourMA4);
			this->tab4Hour->Controls->Add(this->label4HourMA3);
			this->tab4Hour->Controls->Add(this->label4HourMADir3);
			this->tab4Hour->Controls->Add(this->listBox4HourMADir3);
			this->tab4Hour->Controls->Add(this->label4HourMA34);
			this->tab4Hour->Controls->Add(this->label4HourMADir2);
			this->tab4Hour->Controls->Add(this->listBox4HourMADir2);
			this->tab4Hour->Controls->Add(this->textBox4HourMA2);
			this->tab4Hour->Controls->Add(this->textBox4HourMA1);
			this->tab4Hour->Controls->Add(this->label4HourMA2);
			this->tab4Hour->Controls->Add(this->label4HourMA1);
			this->tab4Hour->Controls->Add(this->label4HourMADir1);
			this->tab4Hour->Controls->Add(this->listBox4HourMADir1);
			this->tab4Hour->Controls->Add(this->label4HourMA12);
			this->tab4Hour->Controls->Add(this->textBox4HourCciCci);
			this->tab4Hour->Controls->Add(this->label4HourCciCci);
			this->tab4Hour->Controls->Add(this->label4HourCciDir);
			this->tab4Hour->Controls->Add(this->listBox4HourCciDir);
			this->tab4Hour->Controls->Add(this->label4HourCci);
			this->tab4Hour->Controls->Add(this->textBox4HourCrC);
			this->tab4Hour->Controls->Add(this->label4HourCrC);
			this->tab4Hour->Controls->Add(this->textBox4HourCrB);
			this->tab4Hour->Controls->Add(this->label4HourCrB);
			this->tab4Hour->Controls->Add(this->textBox4HourCrA);
			this->tab4Hour->Controls->Add(this->textBox4HourCrCr);
			this->tab4Hour->Controls->Add(this->label4HourCrA);
			this->tab4Hour->Controls->Add(this->label4HourCrCr);
			this->tab4Hour->Controls->Add(this->label4HourCrDir);
			this->tab4Hour->Controls->Add(this->listBox4HourCrDir);
			this->tab4Hour->Controls->Add(this->label4HourCr);
			this->tab4Hour->Controls->Add(this->textBox4HourDmaAma);
			this->tab4Hour->Controls->Add(this->textBox4HourDmaDma);
			this->tab4Hour->Controls->Add(this->label4HourDmaAma);
			this->tab4Hour->Controls->Add(this->label4HourDmaDma);
			this->tab4Hour->Controls->Add(this->label4HourDmaDir);
			this->tab4Hour->Controls->Add(this->listBox4HourDmaDir);
			this->tab4Hour->Controls->Add(this->label4HourDma);
			this->tab4Hour->Controls->Add(this->textBox4HourRocRocma);
			this->tab4Hour->Controls->Add(this->textBox4HourRocRoc);
			this->tab4Hour->Controls->Add(this->label4HourRocRocma);
			this->tab4Hour->Controls->Add(this->label4HourRocRoc);
			this->tab4Hour->Controls->Add(this->label4HourRocDir);
			this->tab4Hour->Controls->Add(this->listBox4HourRocDir);
			this->tab4Hour->Controls->Add(this->label4HourRoc);
			this->tab4Hour->Controls->Add(this->textBox4HourVrLong);
			this->tab4Hour->Controls->Add(this->textBox4HourVrShort);
			this->tab4Hour->Controls->Add(this->label4HourVrLong);
			this->tab4Hour->Controls->Add(this->label4HourVrShort);
			this->tab4Hour->Controls->Add(this->label4HourVrDir);
			this->tab4Hour->Controls->Add(this->listBox4HourVrDir);
			this->tab4Hour->Controls->Add(this->label4HourVr);
			this->tab4Hour->Controls->Add(this->label4HourVolDir2);
			this->tab4Hour->Controls->Add(this->listBox4HourVolDir2);
			this->tab4Hour->Controls->Add(this->textBox4HourVol2);
			this->tab4Hour->Controls->Add(this->textBox4HourVol1);
			this->tab4Hour->Controls->Add(this->label4HourVol2);
			this->tab4Hour->Controls->Add(this->label4HourVol1);
			this->tab4Hour->Controls->Add(this->label4HourVolDir1);
			this->tab4Hour->Controls->Add(this->listBox4HourVolDir1);
			this->tab4Hour->Controls->Add(this->label4HourVol);
			this->tab4Hour->Controls->Add(this->textBox4HourWr2);
			this->tab4Hour->Controls->Add(this->textBox4HourWr1);
			this->tab4Hour->Controls->Add(this->label4HourWr2);
			this->tab4Hour->Controls->Add(this->label4HourWr1);
			this->tab4Hour->Controls->Add(this->label4HourWrDir);
			this->tab4Hour->Controls->Add(this->listBox4HourWrDir);
			this->tab4Hour->Controls->Add(this->label4HourWr);
			this->tab4Hour->Controls->Add(this->textBox4HourRsiLong);
			this->tab4Hour->Controls->Add(this->textBox4HourRsiMiddle);
			this->tab4Hour->Controls->Add(this->textBox4HourRsiShort);
			this->tab4Hour->Controls->Add(this->label4HourRsiLong);
			this->tab4Hour->Controls->Add(this->label4HourRsiMiddle);
			this->tab4Hour->Controls->Add(this->label4HourRsiShort);
			this->tab4Hour->Controls->Add(this->label4HourRsiDir);
			this->tab4Hour->Controls->Add(this->listBox4HourRsiDir);
			this->tab4Hour->Controls->Add(this->label4HourRsi);
			this->tab4Hour->Controls->Add(this->textBox4HourKdjJ);
			this->tab4Hour->Controls->Add(this->textBox4HourKdjD);
			this->tab4Hour->Controls->Add(this->textBox4HourKdjK);
			this->tab4Hour->Controls->Add(this->label4HourKdjJ);
			this->tab4Hour->Controls->Add(this->label4HourKdjD);
			this->tab4Hour->Controls->Add(this->label4HourKdjK);
			this->tab4Hour->Controls->Add(this->label4HourKdjDir);
			this->tab4Hour->Controls->Add(this->listBox4HourKdjDir);
			this->tab4Hour->Controls->Add(this->label4HourKdj);
			this->tab4Hour->Controls->Add(this->textBox4HourMacdDea);
			this->tab4Hour->Controls->Add(this->textBox4HourMacdDif);
			this->tab4Hour->Controls->Add(this->textBox4HourMacdMacd);
			this->tab4Hour->Controls->Add(this->label4HourMacdDea);
			this->tab4Hour->Controls->Add(this->label4HourMacdDif);
			this->tab4Hour->Controls->Add(this->label4HourMacdMacd);
			this->tab4Hour->Controls->Add(this->label4HourMacdDir);
			this->tab4Hour->Controls->Add(this->listBox4HourMacdDir);
			this->tab4Hour->Controls->Add(this->label4HourMacd);
			this->tab4Hour->Controls->Add(this->textBox4HourBollUpper);
			this->tab4Hour->Controls->Add(this->textBox4HourBollMid);
			this->tab4Hour->Controls->Add(this->textBox4HourBollLow);
			this->tab4Hour->Controls->Add(this->label4HourBollUpper);
			this->tab4Hour->Controls->Add(this->label4HourBollMid);
			this->tab4Hour->Controls->Add(this->label4HourBollLow);
			this->tab4Hour->Controls->Add(this->label4HourBollDir);
			this->tab4Hour->Controls->Add(this->listBox4HourBollDir);
			this->tab4Hour->Controls->Add(this->label4HourBoll);
			this->tab4Hour->Location = System::Drawing::Point(4, 27);
			this->tab4Hour->Name = L"tab4Hour";
			this->tab4Hour->Padding = System::Windows::Forms::Padding(3);
			this->tab4Hour->Size = System::Drawing::Size(1092, 869);
			this->tab4Hour->TabIndex = 4;
			this->tab4Hour->Text = L"4 Hour";
			this->tab4Hour->UseVisualStyleBackColor = true;
			// 
			// listBox4HourMADir6
			// 
			this->listBox4HourMADir6->FormattingEnabled = true;
			this->listBox4HourMADir6->ItemHeight = 18;
			this->listBox4HourMADir6->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourMADir6->Location = System::Drawing::Point(575, 103);
			this->listBox4HourMADir6->Name = L"listBox4HourMADir6";
			this->listBox4HourMADir6->Size = System::Drawing::Size(106, 22);
			this->listBox4HourMADir6->TabIndex = 269;
			this->listBox4HourMADir6->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourMADir6_SelectedIndexChanged);
			// 
			// label4HourMADir6
			// 
			this->label4HourMADir6->AutoSize = true;
			this->label4HourMADir6->Location = System::Drawing::Point(483, 107);
			this->label4HourMADir6->Name = L"label4HourMADir6";
			this->label4HourMADir6->Size = System::Drawing::Size(80, 18);
			this->label4HourMADir6->TabIndex = 268;
			this->label4HourMADir6->Text = L"MA_Dir6:";
			// 
			// textBox4HourMA6
			// 
			this->textBox4HourMA6->Location = System::Drawing::Point(759, 99);
			this->textBox4HourMA6->Name = L"textBox4HourMA6";
			this->textBox4HourMA6->Size = System::Drawing::Size(124, 26);
			this->textBox4HourMA6->TabIndex = 266;
			this->textBox4HourMA6->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourMA6_TextChanged);
			// 
			// textBox4HourMA5
			// 
			this->textBox4HourMA5->Location = System::Drawing::Point(353, 104);
			this->textBox4HourMA5->Name = L"textBox4HourMA5";
			this->textBox4HourMA5->Size = System::Drawing::Size(124, 26);
			this->textBox4HourMA5->TabIndex = 264;
			this->textBox4HourMA5->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourMA5_TextChanged);
			// 
			// label4HourMA6
			// 
			this->label4HourMA6->AutoSize = true;
			this->label4HourMA6->Location = System::Drawing::Point(695, 107);
			this->label4HourMA6->Name = L"label4HourMA6";
			this->label4HourMA6->Size = System::Drawing::Size(48, 18);
			this->label4HourMA6->TabIndex = 265;
			this->label4HourMA6->Text = L"MA6:";
			// 
			// label4HourMA5
			// 
			this->label4HourMA5->AutoSize = true;
			this->label4HourMA5->Location = System::Drawing::Point(290, 109);
			this->label4HourMA5->Name = L"label4HourMA5";
			this->label4HourMA5->Size = System::Drawing::Size(48, 18);
			this->label4HourMA5->TabIndex = 263;
			this->label4HourMA5->Text = L"MA5:";
			// 
			// label4HourMADir5
			// 
			this->label4HourMADir5->AutoSize = true;
			this->label4HourMADir5->Location = System::Drawing::Point(79, 112);
			this->label4HourMADir5->Name = L"label4HourMADir5";
			this->label4HourMADir5->Size = System::Drawing::Size(80, 18);
			this->label4HourMADir5->TabIndex = 262;
			this->label4HourMADir5->Text = L"MA_Dir5:";
			// 
			// listBox4HourMADir5
			// 
			this->listBox4HourMADir5->FormattingEnabled = true;
			this->listBox4HourMADir5->ItemHeight = 18;
			this->listBox4HourMADir5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourMADir5->Location = System::Drawing::Point(170, 107);
			this->listBox4HourMADir5->Name = L"listBox4HourMADir5";
			this->listBox4HourMADir5->Size = System::Drawing::Size(97, 22);
			this->listBox4HourMADir5->TabIndex = 261;
			this->listBox4HourMADir5->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourMADir5_SelectedIndexChanged);
			// 
			// label4HourMA56
			// 
			this->label4HourMA56->AutoSize = true;
			this->label4HourMA56->Location = System::Drawing::Point(17, 112);
			this->label4HourMA56->Name = L"label4HourMA56";
			this->label4HourMA56->Size = System::Drawing::Size(64, 18);
			this->label4HourMA56->TabIndex = 260;
			this->label4HourMA56->Text = L"MA5-6:";
			// 
			// label4HourMADir4
			// 
			this->label4HourMADir4->AutoSize = true;
			this->label4HourMADir4->Location = System::Drawing::Point(483, 60);
			this->label4HourMADir4->Name = L"label4HourMADir4";
			this->label4HourMADir4->Size = System::Drawing::Size(80, 18);
			this->label4HourMADir4->TabIndex = 259;
			this->label4HourMADir4->Text = L"MA_Dir4:";
			// 
			// listBox4HourMADir4
			// 
			this->listBox4HourMADir4->FormattingEnabled = true;
			this->listBox4HourMADir4->ItemHeight = 18;
			this->listBox4HourMADir4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourMADir4->Location = System::Drawing::Point(575, 57);
			this->listBox4HourMADir4->Name = L"listBox4HourMADir4";
			this->listBox4HourMADir4->Size = System::Drawing::Size(106, 22);
			this->listBox4HourMADir4->TabIndex = 258;
			this->listBox4HourMADir4->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourMADir4_SelectedIndexChanged);
			// 
			// textBox4HourMA4
			// 
			this->textBox4HourMA4->Location = System::Drawing::Point(759, 52);
			this->textBox4HourMA4->Name = L"textBox4HourMA4";
			this->textBox4HourMA4->Size = System::Drawing::Size(124, 26);
			this->textBox4HourMA4->TabIndex = 257;
			this->textBox4HourMA4->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourMA4_TextChanged);
			// 
			// textBox4HourMA3
			// 
			this->textBox4HourMA3->Location = System::Drawing::Point(353, 57);
			this->textBox4HourMA3->Name = L"textBox4HourMA3";
			this->textBox4HourMA3->Size = System::Drawing::Size(124, 26);
			this->textBox4HourMA3->TabIndex = 255;
			this->textBox4HourMA3->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourMA3_TextChanged);
			// 
			// label4HourMA4
			// 
			this->label4HourMA4->AutoSize = true;
			this->label4HourMA4->Location = System::Drawing::Point(695, 60);
			this->label4HourMA4->Name = L"label4HourMA4";
			this->label4HourMA4->Size = System::Drawing::Size(48, 18);
			this->label4HourMA4->TabIndex = 256;
			this->label4HourMA4->Text = L"MA4:";
			// 
			// label4HourMA3
			// 
			this->label4HourMA3->AutoSize = true;
			this->label4HourMA3->Location = System::Drawing::Point(290, 62);
			this->label4HourMA3->Name = L"label4HourMA3";
			this->label4HourMA3->Size = System::Drawing::Size(48, 18);
			this->label4HourMA3->TabIndex = 254;
			this->label4HourMA3->Text = L"MA3:";
			// 
			// label4HourMADir3
			// 
			this->label4HourMADir3->AutoSize = true;
			this->label4HourMADir3->Location = System::Drawing::Point(79, 65);
			this->label4HourMADir3->Name = L"label4HourMADir3";
			this->label4HourMADir3->Size = System::Drawing::Size(80, 18);
			this->label4HourMADir3->TabIndex = 253;
			this->label4HourMADir3->Text = L"MA_Dir3:";
			// 
			// listBox4HourMADir3
			// 
			this->listBox4HourMADir3->FormattingEnabled = true;
			this->listBox4HourMADir3->ItemHeight = 18;
			this->listBox4HourMADir3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourMADir3->Location = System::Drawing::Point(170, 60);
			this->listBox4HourMADir3->Name = L"listBox4HourMADir3";
			this->listBox4HourMADir3->Size = System::Drawing::Size(97, 22);
			this->listBox4HourMADir3->TabIndex = 252;
			this->listBox4HourMADir3->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourMADir3_SelectedIndexChanged);
			// 
			// label4HourMA34
			// 
			this->label4HourMA34->AutoSize = true;
			this->label4HourMA34->Location = System::Drawing::Point(17, 65);
			this->label4HourMA34->Name = L"label4HourMA34";
			this->label4HourMA34->Size = System::Drawing::Size(64, 18);
			this->label4HourMA34->TabIndex = 251;
			this->label4HourMA34->Text = L"MA3-4:";
			// 
			// label4HourMADir2
			// 
			this->label4HourMADir2->AutoSize = true;
			this->label4HourMADir2->Location = System::Drawing::Point(483, 19);
			this->label4HourMADir2->Name = L"label4HourMADir2";
			this->label4HourMADir2->Size = System::Drawing::Size(80, 18);
			this->label4HourMADir2->TabIndex = 250;
			this->label4HourMADir2->Text = L"MA_Dir2:";
			// 
			// listBox4HourMADir2
			// 
			this->listBox4HourMADir2->FormattingEnabled = true;
			this->listBox4HourMADir2->ItemHeight = 18;
			this->listBox4HourMADir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourMADir2->Location = System::Drawing::Point(575, 16);
			this->listBox4HourMADir2->Name = L"listBox4HourMADir2";
			this->listBox4HourMADir2->Size = System::Drawing::Size(106, 22);
			this->listBox4HourMADir2->TabIndex = 249;
			this->listBox4HourMADir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourMADir2_SelectedIndexChanged);
			// 
			// textBox4HourMA2
			// 
			this->textBox4HourMA2->Location = System::Drawing::Point(759, 11);
			this->textBox4HourMA2->Name = L"textBox4HourMA2";
			this->textBox4HourMA2->Size = System::Drawing::Size(124, 26);
			this->textBox4HourMA2->TabIndex = 248;
			this->textBox4HourMA2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourMA2_TextChanged);
			// 
			// textBox4HourMA1
			// 
			this->textBox4HourMA1->Location = System::Drawing::Point(353, 16);
			this->textBox4HourMA1->Name = L"textBox4HourMA1";
			this->textBox4HourMA1->Size = System::Drawing::Size(124, 26);
			this->textBox4HourMA1->TabIndex = 246;
			this->textBox4HourMA1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourMA1_TextChanged);
			// 
			// label4HourMA2
			// 
			this->label4HourMA2->AutoSize = true;
			this->label4HourMA2->Location = System::Drawing::Point(695, 19);
			this->label4HourMA2->Name = L"label4HourMA2";
			this->label4HourMA2->Size = System::Drawing::Size(48, 18);
			this->label4HourMA2->TabIndex = 247;
			this->label4HourMA2->Text = L"MA2:";
			// 
			// label4HourMA1
			// 
			this->label4HourMA1->AutoSize = true;
			this->label4HourMA1->Location = System::Drawing::Point(290, 21);
			this->label4HourMA1->Name = L"label4HourMA1";
			this->label4HourMA1->Size = System::Drawing::Size(47, 18);
			this->label4HourMA1->TabIndex = 245;
			this->label4HourMA1->Text = L"MA1:";
			// 
			// label4HourMADir1
			// 
			this->label4HourMADir1->AutoSize = true;
			this->label4HourMADir1->Location = System::Drawing::Point(79, 21);
			this->label4HourMADir1->Name = L"label4HourMADir1";
			this->label4HourMADir1->Size = System::Drawing::Size(79, 18);
			this->label4HourMADir1->TabIndex = 244;
			this->label4HourMADir1->Text = L"MA_Dir1:";
			// 
			// listBox4HourMADir1
			// 
			this->listBox4HourMADir1->FormattingEnabled = true;
			this->listBox4HourMADir1->ItemHeight = 18;
			this->listBox4HourMADir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourMADir1->Location = System::Drawing::Point(170, 19);
			this->listBox4HourMADir1->Name = L"listBox4HourMADir1";
			this->listBox4HourMADir1->Size = System::Drawing::Size(97, 22);
			this->listBox4HourMADir1->TabIndex = 243;
			this->listBox4HourMADir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourMADir_SelectedIndexChanged);
			// 
			// label4HourMA12
			// 
			this->label4HourMA12->AutoSize = true;
			this->label4HourMA12->Location = System::Drawing::Point(16, 24);
			this->label4HourMA12->Name = L"label4HourMA12";
			this->label4HourMA12->Size = System::Drawing::Size(63, 18);
			this->label4HourMA12->TabIndex = 242;
			this->label4HourMA12->Text = L"MA1-2:";
			// 
			// textBox4HourCciCci
			// 
			this->textBox4HourCciCci->Location = System::Drawing::Point(353, 601);
			this->textBox4HourCciCci->Name = L"textBox4HourCciCci";
			this->textBox4HourCciCci->Size = System::Drawing::Size(124, 26);
			this->textBox4HourCciCci->TabIndex = 241;
			this->textBox4HourCciCci->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourCciCci_TextChanged);
			// 
			// label4HourCciCci
			// 
			this->label4HourCciCci->AutoSize = true;
			this->label4HourCciCci->Location = System::Drawing::Point(286, 608);
			this->label4HourCciCci->Name = L"label4HourCciCci";
			this->label4HourCciCci->Size = System::Drawing::Size(34, 18);
			this->label4HourCciCci->TabIndex = 240;
			this->label4HourCciCci->Text = L"Cci:";
			// 
			// label4HourCciDir
			// 
			this->label4HourCciDir->AutoSize = true;
			this->label4HourCciDir->Location = System::Drawing::Point(87, 608);
			this->label4HourCciDir->Name = L"label4HourCciDir";
			this->label4HourCciDir->Size = System::Drawing::Size(77, 18);
			this->label4HourCciDir->TabIndex = 239;
			this->label4HourCciDir->Text = L"Direction:";
			// 
			// listBox4HourCciDir
			// 
			this->listBox4HourCciDir->FormattingEnabled = true;
			this->listBox4HourCciDir->ItemHeight = 18;
			this->listBox4HourCciDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourCciDir->Location = System::Drawing::Point(170, 604);
			this->listBox4HourCciDir->Name = L"listBox4HourCciDir";
			this->listBox4HourCciDir->Size = System::Drawing::Size(97, 22);
			this->listBox4HourCciDir->TabIndex = 238;
			this->listBox4HourCciDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourCciDir_SelectedIndexChanged);
			// 
			// label4HourCci
			// 
			this->label4HourCci->AutoSize = true;
			this->label4HourCci->Location = System::Drawing::Point(26, 608);
			this->label4HourCci->Name = L"label4HourCci";
			this->label4HourCci->Size = System::Drawing::Size(40, 18);
			this->label4HourCci->TabIndex = 237;
			this->label4HourCci->Text = L"CCI:";
			// 
			// textBox4HourCrC
			// 
			this->textBox4HourCrC->Location = System::Drawing::Point(961, 555);
			this->textBox4HourCrC->Name = L"textBox4HourCrC";
			this->textBox4HourCrC->Size = System::Drawing::Size(124, 26);
			this->textBox4HourCrC->TabIndex = 236;
			this->textBox4HourCrC->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourCrC_TextChanged);
			// 
			// label4HourCrC
			// 
			this->label4HourCrC->AutoSize = true;
			this->label4HourCrC->Location = System::Drawing::Point(900, 563);
			this->label4HourCrC->Name = L"label4HourCrC";
			this->label4HourCrC->Size = System::Drawing::Size(23, 18);
			this->label4HourCrC->TabIndex = 235;
			this->label4HourCrC->Text = L"C:";
			// 
			// textBox4HourCrB
			// 
			this->textBox4HourCrB->Location = System::Drawing::Point(755, 555);
			this->textBox4HourCrB->Name = L"textBox4HourCrB";
			this->textBox4HourCrB->Size = System::Drawing::Size(124, 26);
			this->textBox4HourCrB->TabIndex = 234;
			this->textBox4HourCrB->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourCrB_TextChanged);
			// 
			// label4HourCrB
			// 
			this->label4HourCrB->AutoSize = true;
			this->label4HourCrB->Location = System::Drawing::Point(694, 563);
			this->label4HourCrB->Name = L"label4HourCrB";
			this->label4HourCrB->Size = System::Drawing::Size(23, 18);
			this->label4HourCrB->TabIndex = 233;
			this->label4HourCrB->Text = L"B:";
			// 
			// textBox4HourCrA
			// 
			this->textBox4HourCrA->Location = System::Drawing::Point(557, 555);
			this->textBox4HourCrA->Name = L"textBox4HourCrA";
			this->textBox4HourCrA->Size = System::Drawing::Size(124, 26);
			this->textBox4HourCrA->TabIndex = 232;
			this->textBox4HourCrA->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourCrA_TextChanged);
			// 
			// textBox4HourCrCr
			// 
			this->textBox4HourCrCr->Location = System::Drawing::Point(353, 560);
			this->textBox4HourCrCr->Name = L"textBox4HourCrCr";
			this->textBox4HourCrCr->Size = System::Drawing::Size(124, 26);
			this->textBox4HourCrCr->TabIndex = 230;
			this->textBox4HourCrCr->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourCrCr_TextChanged);
			// 
			// label4HourCrA
			// 
			this->label4HourCrA->AutoSize = true;
			this->label4HourCrA->Location = System::Drawing::Point(496, 563);
			this->label4HourCrA->Name = L"label4HourCrA";
			this->label4HourCrA->Size = System::Drawing::Size(24, 18);
			this->label4HourCrA->TabIndex = 231;
			this->label4HourCrA->Text = L"A:";
			// 
			// label4HourCrCr
			// 
			this->label4HourCrCr->AutoSize = true;
			this->label4HourCrCr->Location = System::Drawing::Point(286, 567);
			this->label4HourCrCr->Name = L"label4HourCrCr";
			this->label4HourCrCr->Size = System::Drawing::Size(30, 18);
			this->label4HourCrCr->TabIndex = 229;
			this->label4HourCrCr->Text = L"Cr:";
			// 
			// label4HourCrDir
			// 
			this->label4HourCrDir->AutoSize = true;
			this->label4HourCrDir->Location = System::Drawing::Point(87, 567);
			this->label4HourCrDir->Name = L"label4HourCrDir";
			this->label4HourCrDir->Size = System::Drawing::Size(77, 18);
			this->label4HourCrDir->TabIndex = 228;
			this->label4HourCrDir->Text = L"Direction:";
			// 
			// listBox4HourCrDir
			// 
			this->listBox4HourCrDir->FormattingEnabled = true;
			this->listBox4HourCrDir->ItemHeight = 18;
			this->listBox4HourCrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourCrDir->Location = System::Drawing::Point(170, 563);
			this->listBox4HourCrDir->Name = L"listBox4HourCrDir";
			this->listBox4HourCrDir->Size = System::Drawing::Size(97, 22);
			this->listBox4HourCrDir->TabIndex = 227;
			this->listBox4HourCrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourCrDir_SelectedIndexChanged);
			// 
			// label4HourCr
			// 
			this->label4HourCr->AutoSize = true;
			this->label4HourCr->Location = System::Drawing::Point(26, 567);
			this->label4HourCr->Name = L"label4HourCr";
			this->label4HourCr->Size = System::Drawing::Size(34, 18);
			this->label4HourCr->TabIndex = 226;
			this->label4HourCr->Text = L"CR:";
			// 
			// textBox4HourDmaAma
			// 
			this->textBox4HourDmaAma->Location = System::Drawing::Point(557, 513);
			this->textBox4HourDmaAma->Name = L"textBox4HourDmaAma";
			this->textBox4HourDmaAma->Size = System::Drawing::Size(124, 26);
			this->textBox4HourDmaAma->TabIndex = 225;
			this->textBox4HourDmaAma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourDmaAma_TextChanged);
			// 
			// textBox4HourDmaDma
			// 
			this->textBox4HourDmaDma->Location = System::Drawing::Point(353, 518);
			this->textBox4HourDmaDma->Name = L"textBox4HourDmaDma";
			this->textBox4HourDmaDma->Size = System::Drawing::Size(124, 26);
			this->textBox4HourDmaDma->TabIndex = 223;
			this->textBox4HourDmaDma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourDmaDma_TextChanged);
			// 
			// label4HourDmaAma
			// 
			this->label4HourDmaAma->AutoSize = true;
			this->label4HourDmaAma->Location = System::Drawing::Point(483, 521);
			this->label4HourDmaAma->Name = L"label4HourDmaAma";
			this->label4HourDmaAma->Size = System::Drawing::Size(46, 18);
			this->label4HourDmaAma->TabIndex = 224;
			this->label4HourDmaAma->Text = L"Ama:";
			// 
			// label4HourDmaDma
			// 
			this->label4HourDmaDma->AutoSize = true;
			this->label4HourDmaDma->Location = System::Drawing::Point(286, 525);
			this->label4HourDmaDma->Name = L"label4HourDmaDma";
			this->label4HourDmaDma->Size = System::Drawing::Size(46, 18);
			this->label4HourDmaDma->TabIndex = 222;
			this->label4HourDmaDma->Text = L"Dma:";
			// 
			// label4HourDmaDir
			// 
			this->label4HourDmaDir->AutoSize = true;
			this->label4HourDmaDir->Location = System::Drawing::Point(87, 525);
			this->label4HourDmaDir->Name = L"label4HourDmaDir";
			this->label4HourDmaDir->Size = System::Drawing::Size(77, 18);
			this->label4HourDmaDir->TabIndex = 221;
			this->label4HourDmaDir->Text = L"Direction:";
			// 
			// listBox4HourDmaDir
			// 
			this->listBox4HourDmaDir->FormattingEnabled = true;
			this->listBox4HourDmaDir->ItemHeight = 18;
			this->listBox4HourDmaDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourDmaDir->Location = System::Drawing::Point(170, 521);
			this->listBox4HourDmaDir->Name = L"listBox4HourDmaDir";
			this->listBox4HourDmaDir->Size = System::Drawing::Size(97, 22);
			this->listBox4HourDmaDir->TabIndex = 220;
			this->listBox4HourDmaDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourDmaDir_SelectedIndexChanged);
			// 
			// label4HourDma
			// 
			this->label4HourDma->AutoSize = true;
			this->label4HourDma->Location = System::Drawing::Point(26, 525);
			this->label4HourDma->Name = L"label4HourDma";
			this->label4HourDma->Size = System::Drawing::Size(50, 18);
			this->label4HourDma->TabIndex = 219;
			this->label4HourDma->Text = L"DMA:";
			// 
			// textBox4HourRocRocma
			// 
			this->textBox4HourRocRocma->Location = System::Drawing::Point(557, 427);
			this->textBox4HourRocRocma->Name = L"textBox4HourRocRocma";
			this->textBox4HourRocRocma->Size = System::Drawing::Size(124, 26);
			this->textBox4HourRocRocma->TabIndex = 218;
			this->textBox4HourRocRocma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourRocRocma_TextChanged);
			// 
			// textBox4HourRocRoc
			// 
			this->textBox4HourRocRoc->Location = System::Drawing::Point(353, 432);
			this->textBox4HourRocRoc->Name = L"textBox4HourRocRoc";
			this->textBox4HourRocRoc->Size = System::Drawing::Size(124, 26);
			this->textBox4HourRocRoc->TabIndex = 216;
			this->textBox4HourRocRoc->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourRocRoc_TextChanged);
			// 
			// label4HourRocRocma
			// 
			this->label4HourRocRocma->AutoSize = true;
			this->label4HourRocRocma->Location = System::Drawing::Point(483, 435);
			this->label4HourRocRocma->Name = L"label4HourRocRocma";
			this->label4HourRocRocma->Size = System::Drawing::Size(71, 18);
			this->label4HourRocRocma->TabIndex = 217;
			this->label4HourRocRocma->Text = L"Roc_ma:";
			// 
			// label4HourRocRoc
			// 
			this->label4HourRocRoc->AutoSize = true;
			this->label4HourRocRoc->Location = System::Drawing::Point(286, 439);
			this->label4HourRocRoc->Name = L"label4HourRocRoc";
			this->label4HourRocRoc->Size = System::Drawing::Size(39, 18);
			this->label4HourRocRoc->TabIndex = 215;
			this->label4HourRocRoc->Text = L"Roc:";
			// 
			// label4HourRocDir
			// 
			this->label4HourRocDir->AutoSize = true;
			this->label4HourRocDir->Location = System::Drawing::Point(87, 439);
			this->label4HourRocDir->Name = L"label4HourRocDir";
			this->label4HourRocDir->Size = System::Drawing::Size(77, 18);
			this->label4HourRocDir->TabIndex = 214;
			this->label4HourRocDir->Text = L"Direction:";
			// 
			// listBox4HourRocDir
			// 
			this->listBox4HourRocDir->FormattingEnabled = true;
			this->listBox4HourRocDir->ItemHeight = 18;
			this->listBox4HourRocDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourRocDir->Location = System::Drawing::Point(170, 435);
			this->listBox4HourRocDir->Name = L"listBox4HourRocDir";
			this->listBox4HourRocDir->Size = System::Drawing::Size(97, 22);
			this->listBox4HourRocDir->TabIndex = 213;
			this->listBox4HourRocDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourRocDir_SelectedIndexChanged);
			// 
			// label4HourRoc
			// 
			this->label4HourRoc->AutoSize = true;
			this->label4HourRoc->Location = System::Drawing::Point(26, 439);
			this->label4HourRoc->Name = L"label4HourRoc";
			this->label4HourRoc->Size = System::Drawing::Size(46, 18);
			this->label4HourRoc->TabIndex = 212;
			this->label4HourRoc->Text = L"ROC:";
			// 
			// textBox4HourVrLong
			// 
			this->textBox4HourVrLong->Location = System::Drawing::Point(557, 470);
			this->textBox4HourVrLong->Name = L"textBox4HourVrLong";
			this->textBox4HourVrLong->Size = System::Drawing::Size(124, 26);
			this->textBox4HourVrLong->TabIndex = 211;
			this->textBox4HourVrLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourVrLong_TextChanged);
			// 
			// textBox4HourVrShort
			// 
			this->textBox4HourVrShort->Location = System::Drawing::Point(353, 475);
			this->textBox4HourVrShort->Name = L"textBox4HourVrShort";
			this->textBox4HourVrShort->Size = System::Drawing::Size(124, 26);
			this->textBox4HourVrShort->TabIndex = 209;
			this->textBox4HourVrShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourVrShort_TextChanged);
			// 
			// label4HourVrLong
			// 
			this->label4HourVrLong->AutoSize = true;
			this->label4HourVrLong->Location = System::Drawing::Point(483, 478);
			this->label4HourVrLong->Name = L"label4HourVrLong";
			this->label4HourVrLong->Size = System::Drawing::Size(48, 18);
			this->label4HourVrLong->TabIndex = 210;
			this->label4HourVrLong->Text = L"Long:";
			// 
			// label4HourVrShort
			// 
			this->label4HourVrShort->AutoSize = true;
			this->label4HourVrShort->Location = System::Drawing::Point(281, 483);
			this->label4HourVrShort->Name = L"label4HourVrShort";
			this->label4HourVrShort->Size = System::Drawing::Size(52, 18);
			this->label4HourVrShort->TabIndex = 208;
			this->label4HourVrShort->Text = L"Short:";
			// 
			// label4HourVrDir
			// 
			this->label4HourVrDir->AutoSize = true;
			this->label4HourVrDir->Location = System::Drawing::Point(87, 482);
			this->label4HourVrDir->Name = L"label4HourVrDir";
			this->label4HourVrDir->Size = System::Drawing::Size(77, 18);
			this->label4HourVrDir->TabIndex = 207;
			this->label4HourVrDir->Text = L"Direction:";
			// 
			// listBox4HourVrDir
			// 
			this->listBox4HourVrDir->FormattingEnabled = true;
			this->listBox4HourVrDir->ItemHeight = 18;
			this->listBox4HourVrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourVrDir->Location = System::Drawing::Point(170, 478);
			this->listBox4HourVrDir->Name = L"listBox4HourVrDir";
			this->listBox4HourVrDir->Size = System::Drawing::Size(97, 22);
			this->listBox4HourVrDir->TabIndex = 206;
			this->listBox4HourVrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourVrDir_SelectedIndexChanged);
			// 
			// label4HourVr
			// 
			this->label4HourVr->AutoSize = true;
			this->label4HourVr->Location = System::Drawing::Point(26, 482);
			this->label4HourVr->Name = L"label4HourVr";
			this->label4HourVr->Size = System::Drawing::Size(35, 18);
			this->label4HourVr->TabIndex = 205;
			this->label4HourVr->Text = L"VR:";
			// 
			// label4HourVolDir2
			// 
			this->label4HourVolDir2->AutoSize = true;
			this->label4HourVolDir2->Location = System::Drawing::Point(483, 154);
			this->label4HourVolDir2->Name = L"label4HourVolDir2";
			this->label4HourVolDir2->Size = System::Drawing::Size(86, 18);
			this->label4HourVolDir2->TabIndex = 204;
			this->label4HourVolDir2->Text = L"Direction2:";
			// 
			// listBox4HourVolDir2
			// 
			this->listBox4HourVolDir2->FormattingEnabled = true;
			this->listBox4HourVolDir2->ItemHeight = 18;
			this->listBox4HourVolDir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourVolDir2->Location = System::Drawing::Point(575, 151);
			this->listBox4HourVolDir2->Name = L"listBox4HourVolDir2";
			this->listBox4HourVolDir2->Size = System::Drawing::Size(106, 22);
			this->listBox4HourVolDir2->TabIndex = 203;
			this->listBox4HourVolDir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourVolDir2_SelectedIndexChanged);
			// 
			// textBox4HourVol2
			// 
			this->textBox4HourVol2->Location = System::Drawing::Point(759, 146);
			this->textBox4HourVol2->Name = L"textBox4HourVol2";
			this->textBox4HourVol2->Size = System::Drawing::Size(124, 26);
			this->textBox4HourVol2->TabIndex = 202;
			this->textBox4HourVol2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourVol2_TextChanged);
			// 
			// textBox4HourVol1
			// 
			this->textBox4HourVol1->Location = System::Drawing::Point(353, 151);
			this->textBox4HourVol1->Name = L"textBox4HourVol1";
			this->textBox4HourVol1->Size = System::Drawing::Size(124, 26);
			this->textBox4HourVol1->TabIndex = 200;
			this->textBox4HourVol1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourVol1_TextChanged);
			// 
			// label4HourVol2
			// 
			this->label4HourVol2->AutoSize = true;
			this->label4HourVol2->Location = System::Drawing::Point(695, 154);
			this->label4HourVol2->Name = L"label4HourVol2";
			this->label4HourVol2->Size = System::Drawing::Size(55, 18);
			this->label4HourVol2->TabIndex = 201;
			this->label4HourVol2->Text = L"VOL2:";
			// 
			// label4HourVol1
			// 
			this->label4HourVol1->AutoSize = true;
			this->label4HourVol1->Location = System::Drawing::Point(290, 156);
			this->label4HourVol1->Name = L"label4HourVol1";
			this->label4HourVol1->Size = System::Drawing::Size(54, 18);
			this->label4HourVol1->TabIndex = 199;
			this->label4HourVol1->Text = L"VOL1:";
			// 
			// label4HourVolDir1
			// 
			this->label4HourVolDir1->AutoSize = true;
			this->label4HourVolDir1->Location = System::Drawing::Point(79, 156);
			this->label4HourVolDir1->Name = L"label4HourVolDir1";
			this->label4HourVolDir1->Size = System::Drawing::Size(85, 18);
			this->label4HourVolDir1->TabIndex = 198;
			this->label4HourVolDir1->Text = L"Direction1:";
			// 
			// listBox4HourVolDir1
			// 
			this->listBox4HourVolDir1->FormattingEnabled = true;
			this->listBox4HourVolDir1->ItemHeight = 18;
			this->listBox4HourVolDir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourVolDir1->Location = System::Drawing::Point(170, 154);
			this->listBox4HourVolDir1->Name = L"listBox4HourVolDir1";
			this->listBox4HourVolDir1->Size = System::Drawing::Size(97, 22);
			this->listBox4HourVolDir1->TabIndex = 197;
			this->listBox4HourVolDir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourVolDir1_SelectedIndexChanged);
			// 
			// label4HourVol
			// 
			this->label4HourVol->AutoSize = true;
			this->label4HourVol->Location = System::Drawing::Point(26, 158);
			this->label4HourVol->Name = L"label4HourVol";
			this->label4HourVol->Size = System::Drawing::Size(46, 18);
			this->label4HourVol->TabIndex = 196;
			this->label4HourVol->Text = L"VOL:";
			// 
			// textBox4HourWr2
			// 
			this->textBox4HourWr2->Location = System::Drawing::Point(557, 382);
			this->textBox4HourWr2->Name = L"textBox4HourWr2";
			this->textBox4HourWr2->Size = System::Drawing::Size(124, 26);
			this->textBox4HourWr2->TabIndex = 195;
			this->textBox4HourWr2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourWr2_TextChanged);
			// 
			// textBox4HourWr1
			// 
			this->textBox4HourWr1->Location = System::Drawing::Point(353, 387);
			this->textBox4HourWr1->Name = L"textBox4HourWr1";
			this->textBox4HourWr1->Size = System::Drawing::Size(124, 26);
			this->textBox4HourWr1->TabIndex = 193;
			this->textBox4HourWr1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourWr1_TextChanged);
			// 
			// label4HourWr2
			// 
			this->label4HourWr2->AutoSize = true;
			this->label4HourWr2->Location = System::Drawing::Point(483, 390);
			this->label4HourWr2->Name = L"label4HourWr2";
			this->label4HourWr2->Size = System::Drawing::Size(48, 18);
			this->label4HourWr2->TabIndex = 194;
			this->label4HourWr2->Text = L"WR2:";
			// 
			// label4HourWr1
			// 
			this->label4HourWr1->AutoSize = true;
			this->label4HourWr1->Location = System::Drawing::Point(286, 394);
			this->label4HourWr1->Name = L"label4HourWr1";
			this->label4HourWr1->Size = System::Drawing::Size(47, 18);
			this->label4HourWr1->TabIndex = 192;
			this->label4HourWr1->Text = L"WR1:";
			// 
			// label4HourWrDir
			// 
			this->label4HourWrDir->AutoSize = true;
			this->label4HourWrDir->Location = System::Drawing::Point(87, 394);
			this->label4HourWrDir->Name = L"label4HourWrDir";
			this->label4HourWrDir->Size = System::Drawing::Size(77, 18);
			this->label4HourWrDir->TabIndex = 191;
			this->label4HourWrDir->Text = L"Direction:";
			// 
			// listBox4HourWrDir
			// 
			this->listBox4HourWrDir->FormattingEnabled = true;
			this->listBox4HourWrDir->ItemHeight = 18;
			this->listBox4HourWrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourWrDir->Location = System::Drawing::Point(170, 390);
			this->listBox4HourWrDir->Name = L"listBox4HourWrDir";
			this->listBox4HourWrDir->Size = System::Drawing::Size(97, 22);
			this->listBox4HourWrDir->TabIndex = 190;
			this->listBox4HourWrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourWrDir_SelectedIndexChanged);
			// 
			// label4HourWr
			// 
			this->label4HourWr->AutoSize = true;
			this->label4HourWr->Location = System::Drawing::Point(26, 394);
			this->label4HourWr->Name = L"label4HourWr";
			this->label4HourWr->Size = System::Drawing::Size(39, 18);
			this->label4HourWr->TabIndex = 189;
			this->label4HourWr->Text = L"WR:";
			// 
			// textBox4HourRsiLong
			// 
			this->textBox4HourRsiLong->Location = System::Drawing::Point(759, 335);
			this->textBox4HourRsiLong->Name = L"textBox4HourRsiLong";
			this->textBox4HourRsiLong->Size = System::Drawing::Size(124, 26);
			this->textBox4HourRsiLong->TabIndex = 188;
			this->textBox4HourRsiLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourRsiLong_TextChanged);
			// 
			// textBox4HourRsiMiddle
			// 
			this->textBox4HourRsiMiddle->Location = System::Drawing::Point(557, 335);
			this->textBox4HourRsiMiddle->Name = L"textBox4HourRsiMiddle";
			this->textBox4HourRsiMiddle->Size = System::Drawing::Size(124, 26);
			this->textBox4HourRsiMiddle->TabIndex = 186;
			this->textBox4HourRsiMiddle->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourRsiMiddle_TextChanged);
			// 
			// textBox4HourRsiShort
			// 
			this->textBox4HourRsiShort->Location = System::Drawing::Point(353, 340);
			this->textBox4HourRsiShort->Name = L"textBox4HourRsiShort";
			this->textBox4HourRsiShort->Size = System::Drawing::Size(124, 26);
			this->textBox4HourRsiShort->TabIndex = 184;
			this->textBox4HourRsiShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourRsiShort_TextChanged);
			// 
			// label4HourRsiLong
			// 
			this->label4HourRsiLong->AutoSize = true;
			this->label4HourRsiLong->Location = System::Drawing::Point(695, 340);
			this->label4HourRsiLong->Name = L"label4HourRsiLong";
			this->label4HourRsiLong->Size = System::Drawing::Size(48, 18);
			this->label4HourRsiLong->TabIndex = 187;
			this->label4HourRsiLong->Text = L"Long:";
			// 
			// label4HourRsiMiddle
			// 
			this->label4HourRsiMiddle->AutoSize = true;
			this->label4HourRsiMiddle->Location = System::Drawing::Point(483, 343);
			this->label4HourRsiMiddle->Name = L"label4HourRsiMiddle";
			this->label4HourRsiMiddle->Size = System::Drawing::Size(62, 18);
			this->label4HourRsiMiddle->TabIndex = 185;
			this->label4HourRsiMiddle->Text = L"Middle:";
			// 
			// label4HourRsiShort
			// 
			this->label4HourRsiShort->AutoSize = true;
			this->label4HourRsiShort->Location = System::Drawing::Point(286, 347);
			this->label4HourRsiShort->Name = L"label4HourRsiShort";
			this->label4HourRsiShort->Size = System::Drawing::Size(52, 18);
			this->label4HourRsiShort->TabIndex = 183;
			this->label4HourRsiShort->Text = L"Short:";
			// 
			// label4HourRsiDir
			// 
			this->label4HourRsiDir->AutoSize = true;
			this->label4HourRsiDir->Location = System::Drawing::Point(87, 347);
			this->label4HourRsiDir->Name = L"label4HourRsiDir";
			this->label4HourRsiDir->Size = System::Drawing::Size(77, 18);
			this->label4HourRsiDir->TabIndex = 182;
			this->label4HourRsiDir->Text = L"Direction:";
			// 
			// listBox4HourRsiDir
			// 
			this->listBox4HourRsiDir->FormattingEnabled = true;
			this->listBox4HourRsiDir->ItemHeight = 18;
			this->listBox4HourRsiDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourRsiDir->Location = System::Drawing::Point(170, 343);
			this->listBox4HourRsiDir->Name = L"listBox4HourRsiDir";
			this->listBox4HourRsiDir->Size = System::Drawing::Size(97, 22);
			this->listBox4HourRsiDir->TabIndex = 181;
			this->listBox4HourRsiDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourRsiDir_SelectedIndexChanged);
			// 
			// label4HourRsi
			// 
			this->label4HourRsi->AutoSize = true;
			this->label4HourRsi->Location = System::Drawing::Point(26, 347);
			this->label4HourRsi->Name = L"label4HourRsi";
			this->label4HourRsi->Size = System::Drawing::Size(40, 18);
			this->label4HourRsi->TabIndex = 180;
			this->label4HourRsi->Text = L"RSI:";
			// 
			// textBox4HourKdjJ
			// 
			this->textBox4HourKdjJ->Location = System::Drawing::Point(759, 290);
			this->textBox4HourKdjJ->Name = L"textBox4HourKdjJ";
			this->textBox4HourKdjJ->Size = System::Drawing::Size(124, 26);
			this->textBox4HourKdjJ->TabIndex = 179;
			this->textBox4HourKdjJ->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourKdjJ_TextChanged);
			// 
			// textBox4HourKdjD
			// 
			this->textBox4HourKdjD->Location = System::Drawing::Point(557, 290);
			this->textBox4HourKdjD->Name = L"textBox4HourKdjD";
			this->textBox4HourKdjD->Size = System::Drawing::Size(124, 26);
			this->textBox4HourKdjD->TabIndex = 177;
			this->textBox4HourKdjD->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourKdjD_TextChanged);
			// 
			// textBox4HourKdjK
			// 
			this->textBox4HourKdjK->Location = System::Drawing::Point(353, 295);
			this->textBox4HourKdjK->Name = L"textBox4HourKdjK";
			this->textBox4HourKdjK->Size = System::Drawing::Size(124, 26);
			this->textBox4HourKdjK->TabIndex = 175;
			this->textBox4HourKdjK->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourKdjK_TextChanged);
			// 
			// label4HourKdjJ
			// 
			this->label4HourKdjJ->AutoSize = true;
			this->label4HourKdjJ->Location = System::Drawing::Point(695, 298);
			this->label4HourKdjJ->Name = L"label4HourKdjJ";
			this->label4HourKdjJ->Size = System::Drawing::Size(21, 18);
			this->label4HourKdjJ->TabIndex = 178;
			this->label4HourKdjJ->Text = L"J:";
			// 
			// label4HourKdjD
			// 
			this->label4HourKdjD->AutoSize = true;
			this->label4HourKdjD->Location = System::Drawing::Point(500, 298);
			this->label4HourKdjD->Name = L"label4HourKdjD";
			this->label4HourKdjD->Size = System::Drawing::Size(24, 18);
			this->label4HourKdjD->TabIndex = 176;
			this->label4HourKdjD->Text = L"D:";
			// 
			// label4HourKdjK
			// 
			this->label4HourKdjK->AutoSize = true;
			this->label4HourKdjK->Location = System::Drawing::Point(290, 300);
			this->label4HourKdjK->Name = L"label4HourKdjK";
			this->label4HourKdjK->Size = System::Drawing::Size(24, 18);
			this->label4HourKdjK->TabIndex = 174;
			this->label4HourKdjK->Text = L"K:";
			// 
			// label4HourKdjDir
			// 
			this->label4HourKdjDir->AutoSize = true;
			this->label4HourKdjDir->Location = System::Drawing::Point(87, 302);
			this->label4HourKdjDir->Name = L"label4HourKdjDir";
			this->label4HourKdjDir->Size = System::Drawing::Size(77, 18);
			this->label4HourKdjDir->TabIndex = 173;
			this->label4HourKdjDir->Text = L"Direction:";
			// 
			// listBox4HourKdjDir
			// 
			this->listBox4HourKdjDir->FormattingEnabled = true;
			this->listBox4HourKdjDir->ItemHeight = 18;
			this->listBox4HourKdjDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourKdjDir->Location = System::Drawing::Point(170, 298);
			this->listBox4HourKdjDir->Name = L"listBox4HourKdjDir";
			this->listBox4HourKdjDir->Size = System::Drawing::Size(97, 22);
			this->listBox4HourKdjDir->TabIndex = 172;
			this->listBox4HourKdjDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourKdjDir_SelectedIndexChanged);
			// 
			// label4HourKdj
			// 
			this->label4HourKdj->AutoSize = true;
			this->label4HourKdj->Location = System::Drawing::Point(26, 302);
			this->label4HourKdj->Name = L"label4HourKdj";
			this->label4HourKdj->Size = System::Drawing::Size(43, 18);
			this->label4HourKdj->TabIndex = 171;
			this->label4HourKdj->Text = L"KDJ:";
			// 
			// textBox4HourMacdDea
			// 
			this->textBox4HourMacdDea->Location = System::Drawing::Point(759, 243);
			this->textBox4HourMacdDea->Name = L"textBox4HourMacdDea";
			this->textBox4HourMacdDea->Size = System::Drawing::Size(124, 26);
			this->textBox4HourMacdDea->TabIndex = 170;
			this->textBox4HourMacdDea->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourMacdDea_TextChanged);
			// 
			// textBox4HourMacdDif
			// 
			this->textBox4HourMacdDif->Location = System::Drawing::Point(557, 243);
			this->textBox4HourMacdDif->Name = L"textBox4HourMacdDif";
			this->textBox4HourMacdDif->Size = System::Drawing::Size(124, 26);
			this->textBox4HourMacdDif->TabIndex = 168;
			this->textBox4HourMacdDif->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourMacdDif_TextChanged);
			// 
			// textBox4HourMacdMacd
			// 
			this->textBox4HourMacdMacd->Location = System::Drawing::Point(353, 248);
			this->textBox4HourMacdMacd->Name = L"textBox4HourMacdMacd";
			this->textBox4HourMacdMacd->Size = System::Drawing::Size(124, 26);
			this->textBox4HourMacdMacd->TabIndex = 166;
			this->textBox4HourMacdMacd->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourMacdMacd_TextChanged);
			// 
			// label4HourMacdDea
			// 
			this->label4HourMacdDea->AutoSize = true;
			this->label4HourMacdDea->Location = System::Drawing::Point(695, 251);
			this->label4HourMacdDea->Name = L"label4HourMacdDea";
			this->label4HourMacdDea->Size = System::Drawing::Size(40, 18);
			this->label4HourMacdDea->TabIndex = 169;
			this->label4HourMacdDea->Text = L"Dea:";
			// 
			// label4HourMacdDif
			// 
			this->label4HourMacdDif->AutoSize = true;
			this->label4HourMacdDif->Location = System::Drawing::Point(500, 251);
			this->label4HourMacdDif->Name = L"label4HourMacdDif";
			this->label4HourMacdDif->Size = System::Drawing::Size(33, 18);
			this->label4HourMacdDif->TabIndex = 167;
			this->label4HourMacdDif->Text = L"Dif:";
			// 
			// label4HourMacdMacd
			// 
			this->label4HourMacdMacd->AutoSize = true;
			this->label4HourMacdMacd->Location = System::Drawing::Point(290, 253);
			this->label4HourMacdMacd->Name = L"label4HourMacdMacd";
			this->label4HourMacdMacd->Size = System::Drawing::Size(52, 18);
			this->label4HourMacdMacd->TabIndex = 165;
			this->label4HourMacdMacd->Text = L"Macd:";
			// 
			// label4HourMacdDir
			// 
			this->label4HourMacdDir->AutoSize = true;
			this->label4HourMacdDir->Location = System::Drawing::Point(87, 255);
			this->label4HourMacdDir->Name = L"label4HourMacdDir";
			this->label4HourMacdDir->Size = System::Drawing::Size(77, 18);
			this->label4HourMacdDir->TabIndex = 164;
			this->label4HourMacdDir->Text = L"Direction:";
			// 
			// listBox4HourMacdDir
			// 
			this->listBox4HourMacdDir->FormattingEnabled = true;
			this->listBox4HourMacdDir->ItemHeight = 18;
			this->listBox4HourMacdDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourMacdDir->Location = System::Drawing::Point(170, 251);
			this->listBox4HourMacdDir->Name = L"listBox4HourMacdDir";
			this->listBox4HourMacdDir->Size = System::Drawing::Size(97, 22);
			this->listBox4HourMacdDir->TabIndex = 163;
			this->listBox4HourMacdDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourMacdDir_SelectedIndexChanged);
			// 
			// label4HourMacd
			// 
			this->label4HourMacd->AutoSize = true;
			this->label4HourMacd->Location = System::Drawing::Point(26, 255);
			this->label4HourMacd->Name = L"label4HourMacd";
			this->label4HourMacd->Size = System::Drawing::Size(60, 18);
			this->label4HourMacd->TabIndex = 162;
			this->label4HourMacd->Text = L"MACD:";
			// 
			// textBox4HourBollUpper
			// 
			this->textBox4HourBollUpper->Location = System::Drawing::Point(759, 196);
			this->textBox4HourBollUpper->Name = L"textBox4HourBollUpper";
			this->textBox4HourBollUpper->Size = System::Drawing::Size(124, 26);
			this->textBox4HourBollUpper->TabIndex = 161;
			this->textBox4HourBollUpper->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourBollUpper_TextChanged);
			// 
			// textBox4HourBollMid
			// 
			this->textBox4HourBollMid->Location = System::Drawing::Point(557, 198);
			this->textBox4HourBollMid->Name = L"textBox4HourBollMid";
			this->textBox4HourBollMid->Size = System::Drawing::Size(124, 26);
			this->textBox4HourBollMid->TabIndex = 159;
			this->textBox4HourBollMid->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourBollMid_TextChanged);
			// 
			// textBox4HourBollLow
			// 
			this->textBox4HourBollLow->Location = System::Drawing::Point(353, 200);
			this->textBox4HourBollLow->Name = L"textBox4HourBollLow";
			this->textBox4HourBollLow->Size = System::Drawing::Size(124, 26);
			this->textBox4HourBollLow->TabIndex = 157;
			this->textBox4HourBollLow->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox4HourBollLow_TextChanged);
			// 
			// label4HourBollUpper
			// 
			this->label4HourBollUpper->AutoSize = true;
			this->label4HourBollUpper->Location = System::Drawing::Point(695, 202);
			this->label4HourBollUpper->Name = L"label4HourBollUpper";
			this->label4HourBollUpper->Size = System::Drawing::Size(58, 18);
			this->label4HourBollUpper->TabIndex = 160;
			this->label4HourBollUpper->Text = L"Upper:";
			// 
			// label4HourBollMid
			// 
			this->label4HourBollMid->AutoSize = true;
			this->label4HourBollMid->Location = System::Drawing::Point(500, 204);
			this->label4HourBollMid->Name = L"label4HourBollMid";
			this->label4HourBollMid->Size = System::Drawing::Size(41, 18);
			this->label4HourBollMid->TabIndex = 158;
			this->label4HourBollMid->Text = L"Mid:";
			// 
			// label4HourBollLow
			// 
			this->label4HourBollLow->AutoSize = true;
			this->label4HourBollLow->Location = System::Drawing::Point(295, 206);
			this->label4HourBollLow->Name = L"label4HourBollLow";
			this->label4HourBollLow->Size = System::Drawing::Size(43, 18);
			this->label4HourBollLow->TabIndex = 156;
			this->label4HourBollLow->Text = L"Low:";
			// 
			// label4HourBollDir
			// 
			this->label4HourBollDir->AutoSize = true;
			this->label4HourBollDir->Location = System::Drawing::Point(87, 206);
			this->label4HourBollDir->Name = L"label4HourBollDir";
			this->label4HourBollDir->Size = System::Drawing::Size(77, 18);
			this->label4HourBollDir->TabIndex = 155;
			this->label4HourBollDir->Text = L"Direction:";
			// 
			// listBox4HourBollDir
			// 
			this->listBox4HourBollDir->FormattingEnabled = true;
			this->listBox4HourBollDir->ItemHeight = 18;
			this->listBox4HourBollDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox4HourBollDir->Location = System::Drawing::Point(170, 204);
			this->listBox4HourBollDir->Name = L"listBox4HourBollDir";
			this->listBox4HourBollDir->Size = System::Drawing::Size(97, 22);
			this->listBox4HourBollDir->TabIndex = 154;
			this->listBox4HourBollDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox4HourBollDir_SelectedIndexChanged);
			// 
			// label4HourBoll
			// 
			this->label4HourBoll->AutoSize = true;
			this->label4HourBoll->Location = System::Drawing::Point(26, 210);
			this->label4HourBoll->Name = L"label4HourBoll";
			this->label4HourBoll->Size = System::Drawing::Size(55, 18);
			this->label4HourBoll->TabIndex = 153;
			this->label4HourBoll->Text = L"BOLL:";
			// 
			// tabDay
			// 
			this->tabDay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->tabDay->Controls->Add(this->listBoxDayMADir6);
			this->tabDay->Controls->Add(this->labelDayMADir6);
			this->tabDay->Controls->Add(this->textBoxDayMA6);
			this->tabDay->Controls->Add(this->textBoxDayMA5);
			this->tabDay->Controls->Add(this->labelDayMA6);
			this->tabDay->Controls->Add(this->labelDayMA5);
			this->tabDay->Controls->Add(this->labelDayMADir5);
			this->tabDay->Controls->Add(this->listBoxDayMADir5);
			this->tabDay->Controls->Add(this->labelDayMA56);
			this->tabDay->Controls->Add(this->labelDayMADir4);
			this->tabDay->Controls->Add(this->listBoxDayMADir4);
			this->tabDay->Controls->Add(this->textBoxDayMA4);
			this->tabDay->Controls->Add(this->textBoxDayMA3);
			this->tabDay->Controls->Add(this->labelDayMA4);
			this->tabDay->Controls->Add(this->labelDayMA3);
			this->tabDay->Controls->Add(this->labelDayMADir3);
			this->tabDay->Controls->Add(this->listBoxDayMADir3);
			this->tabDay->Controls->Add(this->labelDayMA34);
			this->tabDay->Controls->Add(this->label1DayMADir2);
			this->tabDay->Controls->Add(this->listBoxDayMADir2);
			this->tabDay->Controls->Add(this->textBoxDayMA2);
			this->tabDay->Controls->Add(this->textBoxDayMA1);
			this->tabDay->Controls->Add(this->labelDayMA2);
			this->tabDay->Controls->Add(this->labelDayMa1);
			this->tabDay->Controls->Add(this->labelDayMaDir1);
			this->tabDay->Controls->Add(this->listBoxDayMADir1);
			this->tabDay->Controls->Add(this->labelDayMa12);
			this->tabDay->Controls->Add(this->textBoxDayCciCci);
			this->tabDay->Controls->Add(this->labelDayCciCci);
			this->tabDay->Controls->Add(this->labelDayCciDir);
			this->tabDay->Controls->Add(this->listBoxDayCciDir);
			this->tabDay->Controls->Add(this->labelDayCci);
			this->tabDay->Controls->Add(this->textBoxDayCrC);
			this->tabDay->Controls->Add(this->labelDayCrC);
			this->tabDay->Controls->Add(this->textBoxDayCrB);
			this->tabDay->Controls->Add(this->labelDayCrB);
			this->tabDay->Controls->Add(this->textBoxDayCrA);
			this->tabDay->Controls->Add(this->textBoxDayCrCr);
			this->tabDay->Controls->Add(this->labelDayCrA);
			this->tabDay->Controls->Add(this->labelDayCrCr);
			this->tabDay->Controls->Add(this->labelDayCrDir);
			this->tabDay->Controls->Add(this->listBoxDayCrDir);
			this->tabDay->Controls->Add(this->labelDayCr);
			this->tabDay->Controls->Add(this->textBoxDayDmaAma);
			this->tabDay->Controls->Add(this->textBoxDayDmaDma);
			this->tabDay->Controls->Add(this->labelDayDmaAma);
			this->tabDay->Controls->Add(this->labelDayDmaDma);
			this->tabDay->Controls->Add(this->labelDayDmaDir);
			this->tabDay->Controls->Add(this->listBoxDayDmaDir);
			this->tabDay->Controls->Add(this->labelDayDma);
			this->tabDay->Controls->Add(this->textBoxDayRocRocma);
			this->tabDay->Controls->Add(this->textBoxDayRocRoc);
			this->tabDay->Controls->Add(this->labelDayRocMa);
			this->tabDay->Controls->Add(this->labelDayRocRoc);
			this->tabDay->Controls->Add(this->labelDayRocDir);
			this->tabDay->Controls->Add(this->listBoxDayRocDir);
			this->tabDay->Controls->Add(this->labelDayRoc);
			this->tabDay->Controls->Add(this->textBoxDayVrLong);
			this->tabDay->Controls->Add(this->textBoxDayVrShort);
			this->tabDay->Controls->Add(this->labelDayVrLong);
			this->tabDay->Controls->Add(this->labelDayVrShort);
			this->tabDay->Controls->Add(this->labelDayVrDir);
			this->tabDay->Controls->Add(this->listBoxDayVrDir);
			this->tabDay->Controls->Add(this->labelDayVr);
			this->tabDay->Controls->Add(this->labelDayVolDir2);
			this->tabDay->Controls->Add(this->listBoxDayVolDir2);
			this->tabDay->Controls->Add(this->textBoxDayVol2);
			this->tabDay->Controls->Add(this->textBoxDayVol1);
			this->tabDay->Controls->Add(this->labelDayVol2);
			this->tabDay->Controls->Add(this->labelDayVol1);
			this->tabDay->Controls->Add(this->labelDayVolDir1);
			this->tabDay->Controls->Add(this->listBoxDayVolDir1);
			this->tabDay->Controls->Add(this->labelDayVol);
			this->tabDay->Controls->Add(this->textBoxDayWr2);
			this->tabDay->Controls->Add(this->textBoxDayWr1);
			this->tabDay->Controls->Add(this->labelDayWrLong);
			this->tabDay->Controls->Add(this->labelDayWrShort);
			this->tabDay->Controls->Add(this->labelDayWrDir);
			this->tabDay->Controls->Add(this->listBoxDayWrDir);
			this->tabDay->Controls->Add(this->labelDayWr);
			this->tabDay->Controls->Add(this->textBoxDayRsiLong);
			this->tabDay->Controls->Add(this->textBoxDayRsiMiddle);
			this->tabDay->Controls->Add(this->textBoxDayRsiShort);
			this->tabDay->Controls->Add(this->labelDayRsiLong);
			this->tabDay->Controls->Add(this->labelDayRsiMiddle);
			this->tabDay->Controls->Add(this->labelDayRsiShort);
			this->tabDay->Controls->Add(this->labelDayRsiDir);
			this->tabDay->Controls->Add(this->listBoxDayRsiDir);
			this->tabDay->Controls->Add(this->labelDayRsi);
			this->tabDay->Controls->Add(this->textBoxDayKdjJ);
			this->tabDay->Controls->Add(this->textBoxDayKdjD);
			this->tabDay->Controls->Add(this->textBoxDayKdjK);
			this->tabDay->Controls->Add(this->labelDayKdjJ);
			this->tabDay->Controls->Add(this->labelDayKdjD);
			this->tabDay->Controls->Add(this->labelDayKdjK);
			this->tabDay->Controls->Add(this->labelDayKdjDir);
			this->tabDay->Controls->Add(this->listBoxDayKdjDir);
			this->tabDay->Controls->Add(this->labelDayKdj);
			this->tabDay->Controls->Add(this->textBoxDayMacdDea);
			this->tabDay->Controls->Add(this->textBoxDayMacdDif);
			this->tabDay->Controls->Add(this->textBoxDayMacdMacd);
			this->tabDay->Controls->Add(this->labelDayMacdDea);
			this->tabDay->Controls->Add(this->labelDayMacdDif);
			this->tabDay->Controls->Add(this->labelDayMacdMacd);
			this->tabDay->Controls->Add(this->labelDayMacdDir);
			this->tabDay->Controls->Add(this->listBoxDayMacdDir);
			this->tabDay->Controls->Add(this->labelDayMacd);
			this->tabDay->Controls->Add(this->textBoxDayBollUpper);
			this->tabDay->Controls->Add(this->textBoxDayBollMid);
			this->tabDay->Controls->Add(this->textBoxDayBollLow);
			this->tabDay->Controls->Add(this->labelDayBollUpper);
			this->tabDay->Controls->Add(this->labelDayBollMid);
			this->tabDay->Controls->Add(this->labelDayBollLow);
			this->tabDay->Controls->Add(this->labelDayBollDir);
			this->tabDay->Controls->Add(this->listBoxDayBollDir);
			this->tabDay->Controls->Add(this->labelDayBoll);
			this->tabDay->Location = System::Drawing::Point(4, 27);
			this->tabDay->Name = L"tabDay";
			this->tabDay->Padding = System::Windows::Forms::Padding(3);
			this->tabDay->Size = System::Drawing::Size(1092, 869);
			this->tabDay->TabIndex = 3;
			this->tabDay->Text = L"Day";
			this->tabDay->UseVisualStyleBackColor = true;
			// 
			// listBoxDayMADir6
			// 
			this->listBoxDayMADir6->FormattingEnabled = true;
			this->listBoxDayMADir6->ItemHeight = 18;
			this->listBoxDayMADir6->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayMADir6->Location = System::Drawing::Point(575, 104);
			this->listBoxDayMADir6->Name = L"listBoxDayMADir6";
			this->listBoxDayMADir6->Size = System::Drawing::Size(106, 22);
			this->listBoxDayMADir6->TabIndex = 269;
			this->listBoxDayMADir6->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayMADir6_SelectedIndexChanged);
			// 
			// labelDayMADir6
			// 
			this->labelDayMADir6->AutoSize = true;
			this->labelDayMADir6->Location = System::Drawing::Point(483, 107);
			this->labelDayMADir6->Name = L"labelDayMADir6";
			this->labelDayMADir6->Size = System::Drawing::Size(80, 18);
			this->labelDayMADir6->TabIndex = 268;
			this->labelDayMADir6->Text = L"MA_Dir6:";
			// 
			// textBoxDayMA6
			// 
			this->textBoxDayMA6->Location = System::Drawing::Point(759, 99);
			this->textBoxDayMA6->Name = L"textBoxDayMA6";
			this->textBoxDayMA6->Size = System::Drawing::Size(124, 26);
			this->textBoxDayMA6->TabIndex = 266;
			this->textBoxDayMA6->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayMA6_TextChanged);
			// 
			// textBoxDayMA5
			// 
			this->textBoxDayMA5->Location = System::Drawing::Point(353, 104);
			this->textBoxDayMA5->Name = L"textBoxDayMA5";
			this->textBoxDayMA5->Size = System::Drawing::Size(124, 26);
			this->textBoxDayMA5->TabIndex = 264;
			this->textBoxDayMA5->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayMA5_TextChanged);
			// 
			// labelDayMA6
			// 
			this->labelDayMA6->AutoSize = true;
			this->labelDayMA6->Location = System::Drawing::Point(695, 107);
			this->labelDayMA6->Name = L"labelDayMA6";
			this->labelDayMA6->Size = System::Drawing::Size(48, 18);
			this->labelDayMA6->TabIndex = 265;
			this->labelDayMA6->Text = L"MA6:";
			// 
			// labelDayMA5
			// 
			this->labelDayMA5->AutoSize = true;
			this->labelDayMA5->Location = System::Drawing::Point(290, 109);
			this->labelDayMA5->Name = L"labelDayMA5";
			this->labelDayMA5->Size = System::Drawing::Size(48, 18);
			this->labelDayMA5->TabIndex = 263;
			this->labelDayMA5->Text = L"MA5:";
			// 
			// labelDayMADir5
			// 
			this->labelDayMADir5->AutoSize = true;
			this->labelDayMADir5->Location = System::Drawing::Point(79, 112);
			this->labelDayMADir5->Name = L"labelDayMADir5";
			this->labelDayMADir5->Size = System::Drawing::Size(80, 18);
			this->labelDayMADir5->TabIndex = 262;
			this->labelDayMADir5->Text = L"MA_Dir5:";
			// 
			// listBoxDayMADir5
			// 
			this->listBoxDayMADir5->FormattingEnabled = true;
			this->listBoxDayMADir5->ItemHeight = 18;
			this->listBoxDayMADir5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayMADir5->Location = System::Drawing::Point(170, 107);
			this->listBoxDayMADir5->Name = L"listBoxDayMADir5";
			this->listBoxDayMADir5->Size = System::Drawing::Size(97, 22);
			this->listBoxDayMADir5->TabIndex = 261;
			this->listBoxDayMADir5->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayMADir5_SelectedIndexChanged);
			// 
			// labelDayMA56
			// 
			this->labelDayMA56->AutoSize = true;
			this->labelDayMA56->Location = System::Drawing::Point(17, 112);
			this->labelDayMA56->Name = L"labelDayMA56";
			this->labelDayMA56->Size = System::Drawing::Size(64, 18);
			this->labelDayMA56->TabIndex = 260;
			this->labelDayMA56->Text = L"MA5-6:";
			// 
			// labelDayMADir4
			// 
			this->labelDayMADir4->AutoSize = true;
			this->labelDayMADir4->Location = System::Drawing::Point(483, 60);
			this->labelDayMADir4->Name = L"labelDayMADir4";
			this->labelDayMADir4->Size = System::Drawing::Size(80, 18);
			this->labelDayMADir4->TabIndex = 259;
			this->labelDayMADir4->Text = L"MA_Dir4:";
			// 
			// listBoxDayMADir4
			// 
			this->listBoxDayMADir4->FormattingEnabled = true;
			this->listBoxDayMADir4->ItemHeight = 18;
			this->listBoxDayMADir4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayMADir4->Location = System::Drawing::Point(575, 57);
			this->listBoxDayMADir4->Name = L"listBoxDayMADir4";
			this->listBoxDayMADir4->Size = System::Drawing::Size(106, 22);
			this->listBoxDayMADir4->TabIndex = 258;
			this->listBoxDayMADir4->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayMADir4_SelectedIndexChanged);
			// 
			// textBoxDayMA4
			// 
			this->textBoxDayMA4->Location = System::Drawing::Point(759, 52);
			this->textBoxDayMA4->Name = L"textBoxDayMA4";
			this->textBoxDayMA4->Size = System::Drawing::Size(124, 26);
			this->textBoxDayMA4->TabIndex = 257;
			this->textBoxDayMA4->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayMA4_TextChanged);
			// 
			// textBoxDayMA3
			// 
			this->textBoxDayMA3->Location = System::Drawing::Point(353, 57);
			this->textBoxDayMA3->Name = L"textBoxDayMA3";
			this->textBoxDayMA3->Size = System::Drawing::Size(124, 26);
			this->textBoxDayMA3->TabIndex = 255;
			this->textBoxDayMA3->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayMA3_TextChanged);
			// 
			// labelDayMA4
			// 
			this->labelDayMA4->AutoSize = true;
			this->labelDayMA4->Location = System::Drawing::Point(695, 60);
			this->labelDayMA4->Name = L"labelDayMA4";
			this->labelDayMA4->Size = System::Drawing::Size(48, 18);
			this->labelDayMA4->TabIndex = 256;
			this->labelDayMA4->Text = L"MA4:";
			// 
			// labelDayMA3
			// 
			this->labelDayMA3->AutoSize = true;
			this->labelDayMA3->Location = System::Drawing::Point(290, 62);
			this->labelDayMA3->Name = L"labelDayMA3";
			this->labelDayMA3->Size = System::Drawing::Size(48, 18);
			this->labelDayMA3->TabIndex = 254;
			this->labelDayMA3->Text = L"MA3:";
			// 
			// labelDayMADir3
			// 
			this->labelDayMADir3->AutoSize = true;
			this->labelDayMADir3->Location = System::Drawing::Point(79, 65);
			this->labelDayMADir3->Name = L"labelDayMADir3";
			this->labelDayMADir3->Size = System::Drawing::Size(80, 18);
			this->labelDayMADir3->TabIndex = 253;
			this->labelDayMADir3->Text = L"MA_Dir3:";
			// 
			// listBoxDayMADir3
			// 
			this->listBoxDayMADir3->FormattingEnabled = true;
			this->listBoxDayMADir3->ItemHeight = 18;
			this->listBoxDayMADir3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayMADir3->Location = System::Drawing::Point(170, 60);
			this->listBoxDayMADir3->Name = L"listBoxDayMADir3";
			this->listBoxDayMADir3->Size = System::Drawing::Size(97, 22);
			this->listBoxDayMADir3->TabIndex = 252;
			this->listBoxDayMADir3->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayMADir3_SelectedIndexChanged);
			// 
			// labelDayMA34
			// 
			this->labelDayMA34->AutoSize = true;
			this->labelDayMA34->Location = System::Drawing::Point(17, 65);
			this->labelDayMA34->Name = L"labelDayMA34";
			this->labelDayMA34->Size = System::Drawing::Size(64, 18);
			this->labelDayMA34->TabIndex = 251;
			this->labelDayMA34->Text = L"MA3-4:";
			// 
			// label1DayMADir2
			// 
			this->label1DayMADir2->AutoSize = true;
			this->label1DayMADir2->Location = System::Drawing::Point(483, 19);
			this->label1DayMADir2->Name = L"label1DayMADir2";
			this->label1DayMADir2->Size = System::Drawing::Size(80, 18);
			this->label1DayMADir2->TabIndex = 250;
			this->label1DayMADir2->Text = L"MA_Dir2:";
			// 
			// listBoxDayMADir2
			// 
			this->listBoxDayMADir2->FormattingEnabled = true;
			this->listBoxDayMADir2->ItemHeight = 18;
			this->listBoxDayMADir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayMADir2->Location = System::Drawing::Point(575, 16);
			this->listBoxDayMADir2->Name = L"listBoxDayMADir2";
			this->listBoxDayMADir2->Size = System::Drawing::Size(106, 22);
			this->listBoxDayMADir2->TabIndex = 249;
			this->listBoxDayMADir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayMADir2_SelectedIndexChanged);
			// 
			// textBoxDayMA2
			// 
			this->textBoxDayMA2->Location = System::Drawing::Point(759, 11);
			this->textBoxDayMA2->Name = L"textBoxDayMA2";
			this->textBoxDayMA2->Size = System::Drawing::Size(124, 26);
			this->textBoxDayMA2->TabIndex = 248;
			this->textBoxDayMA2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayMA2_TextChanged);
			// 
			// textBoxDayMA1
			// 
			this->textBoxDayMA1->Location = System::Drawing::Point(353, 16);
			this->textBoxDayMA1->Name = L"textBoxDayMA1";
			this->textBoxDayMA1->Size = System::Drawing::Size(124, 26);
			this->textBoxDayMA1->TabIndex = 246;
			this->textBoxDayMA1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayMA1_TextChanged);
			// 
			// labelDayMA2
			// 
			this->labelDayMA2->AutoSize = true;
			this->labelDayMA2->Location = System::Drawing::Point(695, 19);
			this->labelDayMA2->Name = L"labelDayMA2";
			this->labelDayMA2->Size = System::Drawing::Size(48, 18);
			this->labelDayMA2->TabIndex = 247;
			this->labelDayMA2->Text = L"MA2:";
			// 
			// labelDayMa1
			// 
			this->labelDayMa1->AutoSize = true;
			this->labelDayMa1->Location = System::Drawing::Point(290, 21);
			this->labelDayMa1->Name = L"labelDayMa1";
			this->labelDayMa1->Size = System::Drawing::Size(47, 18);
			this->labelDayMa1->TabIndex = 245;
			this->labelDayMa1->Text = L"MA1:";
			// 
			// labelDayMaDir1
			// 
			this->labelDayMaDir1->AutoSize = true;
			this->labelDayMaDir1->Location = System::Drawing::Point(79, 21);
			this->labelDayMaDir1->Name = L"labelDayMaDir1";
			this->labelDayMaDir1->Size = System::Drawing::Size(79, 18);
			this->labelDayMaDir1->TabIndex = 244;
			this->labelDayMaDir1->Text = L"MA_Dir1:";
			// 
			// listBoxDayMADir1
			// 
			this->listBoxDayMADir1->FormattingEnabled = true;
			this->listBoxDayMADir1->ItemHeight = 18;
			this->listBoxDayMADir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayMADir1->Location = System::Drawing::Point(170, 19);
			this->listBoxDayMADir1->Name = L"listBoxDayMADir1";
			this->listBoxDayMADir1->Size = System::Drawing::Size(97, 22);
			this->listBoxDayMADir1->TabIndex = 243;
			this->listBoxDayMADir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayMADir1_SelectedIndexChanged);
			// 
			// labelDayMa12
			// 
			this->labelDayMa12->AutoSize = true;
			this->labelDayMa12->Location = System::Drawing::Point(16, 24);
			this->labelDayMa12->Name = L"labelDayMa12";
			this->labelDayMa12->Size = System::Drawing::Size(63, 18);
			this->labelDayMa12->TabIndex = 242;
			this->labelDayMa12->Text = L"MA1-2:";
			// 
			// textBoxDayCciCci
			// 
			this->textBoxDayCciCci->Location = System::Drawing::Point(353, 601);
			this->textBoxDayCciCci->Name = L"textBoxDayCciCci";
			this->textBoxDayCciCci->Size = System::Drawing::Size(124, 26);
			this->textBoxDayCciCci->TabIndex = 241;
			this->textBoxDayCciCci->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayCciCci_TextChanged);
			// 
			// labelDayCciCci
			// 
			this->labelDayCciCci->AutoSize = true;
			this->labelDayCciCci->Location = System::Drawing::Point(286, 608);
			this->labelDayCciCci->Name = L"labelDayCciCci";
			this->labelDayCciCci->Size = System::Drawing::Size(34, 18);
			this->labelDayCciCci->TabIndex = 240;
			this->labelDayCciCci->Text = L"Cci:";
			// 
			// labelDayCciDir
			// 
			this->labelDayCciDir->AutoSize = true;
			this->labelDayCciDir->Location = System::Drawing::Point(87, 608);
			this->labelDayCciDir->Name = L"labelDayCciDir";
			this->labelDayCciDir->Size = System::Drawing::Size(77, 18);
			this->labelDayCciDir->TabIndex = 239;
			this->labelDayCciDir->Text = L"Direction:";
			// 
			// listBoxDayCciDir
			// 
			this->listBoxDayCciDir->FormattingEnabled = true;
			this->listBoxDayCciDir->ItemHeight = 18;
			this->listBoxDayCciDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayCciDir->Location = System::Drawing::Point(170, 604);
			this->listBoxDayCciDir->Name = L"listBoxDayCciDir";
			this->listBoxDayCciDir->Size = System::Drawing::Size(97, 22);
			this->listBoxDayCciDir->TabIndex = 238;
			this->listBoxDayCciDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayCciDir_SelectedIndexChanged);
			// 
			// labelDayCci
			// 
			this->labelDayCci->AutoSize = true;
			this->labelDayCci->Location = System::Drawing::Point(26, 608);
			this->labelDayCci->Name = L"labelDayCci";
			this->labelDayCci->Size = System::Drawing::Size(40, 18);
			this->labelDayCci->TabIndex = 237;
			this->labelDayCci->Text = L"CCI:";
			// 
			// textBoxDayCrC
			// 
			this->textBoxDayCrC->Location = System::Drawing::Point(961, 555);
			this->textBoxDayCrC->Name = L"textBoxDayCrC";
			this->textBoxDayCrC->Size = System::Drawing::Size(124, 26);
			this->textBoxDayCrC->TabIndex = 236;
			this->textBoxDayCrC->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayCrC_TextChanged);
			// 
			// labelDayCrC
			// 
			this->labelDayCrC->AutoSize = true;
			this->labelDayCrC->Location = System::Drawing::Point(900, 563);
			this->labelDayCrC->Name = L"labelDayCrC";
			this->labelDayCrC->Size = System::Drawing::Size(23, 18);
			this->labelDayCrC->TabIndex = 235;
			this->labelDayCrC->Text = L"C:";
			// 
			// textBoxDayCrB
			// 
			this->textBoxDayCrB->Location = System::Drawing::Point(755, 555);
			this->textBoxDayCrB->Name = L"textBoxDayCrB";
			this->textBoxDayCrB->Size = System::Drawing::Size(124, 26);
			this->textBoxDayCrB->TabIndex = 234;
			this->textBoxDayCrB->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayCrB_TextChanged);
			// 
			// labelDayCrB
			// 
			this->labelDayCrB->AutoSize = true;
			this->labelDayCrB->Location = System::Drawing::Point(694, 563);
			this->labelDayCrB->Name = L"labelDayCrB";
			this->labelDayCrB->Size = System::Drawing::Size(23, 18);
			this->labelDayCrB->TabIndex = 233;
			this->labelDayCrB->Text = L"B:";
			// 
			// textBoxDayCrA
			// 
			this->textBoxDayCrA->Location = System::Drawing::Point(557, 555);
			this->textBoxDayCrA->Name = L"textBoxDayCrA";
			this->textBoxDayCrA->Size = System::Drawing::Size(124, 26);
			this->textBoxDayCrA->TabIndex = 232;
			this->textBoxDayCrA->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayCrA_TextChanged);
			// 
			// textBoxDayCrCr
			// 
			this->textBoxDayCrCr->Location = System::Drawing::Point(353, 560);
			this->textBoxDayCrCr->Name = L"textBoxDayCrCr";
			this->textBoxDayCrCr->Size = System::Drawing::Size(124, 26);
			this->textBoxDayCrCr->TabIndex = 230;
			this->textBoxDayCrCr->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayCrCr_TextChanged);
			// 
			// labelDayCrA
			// 
			this->labelDayCrA->AutoSize = true;
			this->labelDayCrA->Location = System::Drawing::Point(496, 563);
			this->labelDayCrA->Name = L"labelDayCrA";
			this->labelDayCrA->Size = System::Drawing::Size(24, 18);
			this->labelDayCrA->TabIndex = 231;
			this->labelDayCrA->Text = L"A:";
			// 
			// labelDayCrCr
			// 
			this->labelDayCrCr->AutoSize = true;
			this->labelDayCrCr->Location = System::Drawing::Point(286, 567);
			this->labelDayCrCr->Name = L"labelDayCrCr";
			this->labelDayCrCr->Size = System::Drawing::Size(30, 18);
			this->labelDayCrCr->TabIndex = 229;
			this->labelDayCrCr->Text = L"Cr:";
			// 
			// labelDayCrDir
			// 
			this->labelDayCrDir->AutoSize = true;
			this->labelDayCrDir->Location = System::Drawing::Point(87, 567);
			this->labelDayCrDir->Name = L"labelDayCrDir";
			this->labelDayCrDir->Size = System::Drawing::Size(77, 18);
			this->labelDayCrDir->TabIndex = 228;
			this->labelDayCrDir->Text = L"Direction:";
			// 
			// listBoxDayCrDir
			// 
			this->listBoxDayCrDir->FormattingEnabled = true;
			this->listBoxDayCrDir->ItemHeight = 18;
			this->listBoxDayCrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayCrDir->Location = System::Drawing::Point(170, 563);
			this->listBoxDayCrDir->Name = L"listBoxDayCrDir";
			this->listBoxDayCrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxDayCrDir->TabIndex = 227;
			this->listBoxDayCrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayCrDir_SelectedIndexChanged);
			// 
			// labelDayCr
			// 
			this->labelDayCr->AutoSize = true;
			this->labelDayCr->Location = System::Drawing::Point(26, 567);
			this->labelDayCr->Name = L"labelDayCr";
			this->labelDayCr->Size = System::Drawing::Size(34, 18);
			this->labelDayCr->TabIndex = 226;
			this->labelDayCr->Text = L"CR:";
			// 
			// textBoxDayDmaAma
			// 
			this->textBoxDayDmaAma->Location = System::Drawing::Point(557, 513);
			this->textBoxDayDmaAma->Name = L"textBoxDayDmaAma";
			this->textBoxDayDmaAma->Size = System::Drawing::Size(124, 26);
			this->textBoxDayDmaAma->TabIndex = 225;
			this->textBoxDayDmaAma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayDmaAma_TextChanged);
			// 
			// textBoxDayDmaDma
			// 
			this->textBoxDayDmaDma->Location = System::Drawing::Point(353, 518);
			this->textBoxDayDmaDma->Name = L"textBoxDayDmaDma";
			this->textBoxDayDmaDma->Size = System::Drawing::Size(124, 26);
			this->textBoxDayDmaDma->TabIndex = 223;
			this->textBoxDayDmaDma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayDmaDma_TextChanged);
			// 
			// labelDayDmaAma
			// 
			this->labelDayDmaAma->AutoSize = true;
			this->labelDayDmaAma->Location = System::Drawing::Point(483, 521);
			this->labelDayDmaAma->Name = L"labelDayDmaAma";
			this->labelDayDmaAma->Size = System::Drawing::Size(46, 18);
			this->labelDayDmaAma->TabIndex = 224;
			this->labelDayDmaAma->Text = L"Ama:";
			// 
			// labelDayDmaDma
			// 
			this->labelDayDmaDma->AutoSize = true;
			this->labelDayDmaDma->Location = System::Drawing::Point(286, 525);
			this->labelDayDmaDma->Name = L"labelDayDmaDma";
			this->labelDayDmaDma->Size = System::Drawing::Size(46, 18);
			this->labelDayDmaDma->TabIndex = 222;
			this->labelDayDmaDma->Text = L"Dma:";
			// 
			// labelDayDmaDir
			// 
			this->labelDayDmaDir->AutoSize = true;
			this->labelDayDmaDir->Location = System::Drawing::Point(87, 525);
			this->labelDayDmaDir->Name = L"labelDayDmaDir";
			this->labelDayDmaDir->Size = System::Drawing::Size(77, 18);
			this->labelDayDmaDir->TabIndex = 221;
			this->labelDayDmaDir->Text = L"Direction:";
			// 
			// listBoxDayDmaDir
			// 
			this->listBoxDayDmaDir->FormattingEnabled = true;
			this->listBoxDayDmaDir->ItemHeight = 18;
			this->listBoxDayDmaDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayDmaDir->Location = System::Drawing::Point(170, 521);
			this->listBoxDayDmaDir->Name = L"listBoxDayDmaDir";
			this->listBoxDayDmaDir->Size = System::Drawing::Size(97, 22);
			this->listBoxDayDmaDir->TabIndex = 220;
			this->listBoxDayDmaDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayDmaDir_SelectedIndexChanged);
			// 
			// labelDayDma
			// 
			this->labelDayDma->AutoSize = true;
			this->labelDayDma->Location = System::Drawing::Point(26, 525);
			this->labelDayDma->Name = L"labelDayDma";
			this->labelDayDma->Size = System::Drawing::Size(50, 18);
			this->labelDayDma->TabIndex = 219;
			this->labelDayDma->Text = L"DMA:";
			// 
			// textBoxDayRocRocma
			// 
			this->textBoxDayRocRocma->Location = System::Drawing::Point(557, 427);
			this->textBoxDayRocRocma->Name = L"textBoxDayRocRocma";
			this->textBoxDayRocRocma->Size = System::Drawing::Size(124, 26);
			this->textBoxDayRocRocma->TabIndex = 218;
			this->textBoxDayRocRocma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayRocRocma_TextChanged);
			// 
			// textBoxDayRocRoc
			// 
			this->textBoxDayRocRoc->Location = System::Drawing::Point(353, 432);
			this->textBoxDayRocRoc->Name = L"textBoxDayRocRoc";
			this->textBoxDayRocRoc->Size = System::Drawing::Size(124, 26);
			this->textBoxDayRocRoc->TabIndex = 216;
			this->textBoxDayRocRoc->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayRocRoc_TextChanged);
			// 
			// labelDayRocMa
			// 
			this->labelDayRocMa->AutoSize = true;
			this->labelDayRocMa->Location = System::Drawing::Point(483, 435);
			this->labelDayRocMa->Name = L"labelDayRocMa";
			this->labelDayRocMa->Size = System::Drawing::Size(71, 18);
			this->labelDayRocMa->TabIndex = 217;
			this->labelDayRocMa->Text = L"Roc_ma:";
			// 
			// labelDayRocRoc
			// 
			this->labelDayRocRoc->AutoSize = true;
			this->labelDayRocRoc->Location = System::Drawing::Point(286, 439);
			this->labelDayRocRoc->Name = L"labelDayRocRoc";
			this->labelDayRocRoc->Size = System::Drawing::Size(39, 18);
			this->labelDayRocRoc->TabIndex = 215;
			this->labelDayRocRoc->Text = L"Roc:";
			// 
			// labelDayRocDir
			// 
			this->labelDayRocDir->AutoSize = true;
			this->labelDayRocDir->Location = System::Drawing::Point(87, 439);
			this->labelDayRocDir->Name = L"labelDayRocDir";
			this->labelDayRocDir->Size = System::Drawing::Size(77, 18);
			this->labelDayRocDir->TabIndex = 214;
			this->labelDayRocDir->Text = L"Direction:";
			// 
			// listBoxDayRocDir
			// 
			this->listBoxDayRocDir->FormattingEnabled = true;
			this->listBoxDayRocDir->ItemHeight = 18;
			this->listBoxDayRocDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayRocDir->Location = System::Drawing::Point(170, 435);
			this->listBoxDayRocDir->Name = L"listBoxDayRocDir";
			this->listBoxDayRocDir->Size = System::Drawing::Size(97, 22);
			this->listBoxDayRocDir->TabIndex = 213;
			this->listBoxDayRocDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayRocDir_SelectedIndexChanged);
			// 
			// labelDayRoc
			// 
			this->labelDayRoc->AutoSize = true;
			this->labelDayRoc->Location = System::Drawing::Point(26, 439);
			this->labelDayRoc->Name = L"labelDayRoc";
			this->labelDayRoc->Size = System::Drawing::Size(46, 18);
			this->labelDayRoc->TabIndex = 212;
			this->labelDayRoc->Text = L"ROC:";
			// 
			// textBoxDayVrLong
			// 
			this->textBoxDayVrLong->Location = System::Drawing::Point(557, 470);
			this->textBoxDayVrLong->Name = L"textBoxDayVrLong";
			this->textBoxDayVrLong->Size = System::Drawing::Size(124, 26);
			this->textBoxDayVrLong->TabIndex = 211;
			this->textBoxDayVrLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayVrLong_TextChanged);
			// 
			// textBoxDayVrShort
			// 
			this->textBoxDayVrShort->Location = System::Drawing::Point(353, 475);
			this->textBoxDayVrShort->Name = L"textBoxDayVrShort";
			this->textBoxDayVrShort->Size = System::Drawing::Size(124, 26);
			this->textBoxDayVrShort->TabIndex = 209;
			this->textBoxDayVrShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayVrShort_TextChanged);
			// 
			// labelDayVrLong
			// 
			this->labelDayVrLong->AutoSize = true;
			this->labelDayVrLong->Location = System::Drawing::Point(483, 478);
			this->labelDayVrLong->Name = L"labelDayVrLong";
			this->labelDayVrLong->Size = System::Drawing::Size(48, 18);
			this->labelDayVrLong->TabIndex = 210;
			this->labelDayVrLong->Text = L"Long:";
			// 
			// labelDayVrShort
			// 
			this->labelDayVrShort->AutoSize = true;
			this->labelDayVrShort->Location = System::Drawing::Point(281, 483);
			this->labelDayVrShort->Name = L"labelDayVrShort";
			this->labelDayVrShort->Size = System::Drawing::Size(52, 18);
			this->labelDayVrShort->TabIndex = 208;
			this->labelDayVrShort->Text = L"Short:";
			// 
			// labelDayVrDir
			// 
			this->labelDayVrDir->AutoSize = true;
			this->labelDayVrDir->Location = System::Drawing::Point(87, 482);
			this->labelDayVrDir->Name = L"labelDayVrDir";
			this->labelDayVrDir->Size = System::Drawing::Size(77, 18);
			this->labelDayVrDir->TabIndex = 207;
			this->labelDayVrDir->Text = L"Direction:";
			// 
			// listBoxDayVrDir
			// 
			this->listBoxDayVrDir->FormattingEnabled = true;
			this->listBoxDayVrDir->ItemHeight = 18;
			this->listBoxDayVrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayVrDir->Location = System::Drawing::Point(170, 478);
			this->listBoxDayVrDir->Name = L"listBoxDayVrDir";
			this->listBoxDayVrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxDayVrDir->TabIndex = 206;
			this->listBoxDayVrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayVrDir_SelectedIndexChanged);
			// 
			// labelDayVr
			// 
			this->labelDayVr->AutoSize = true;
			this->labelDayVr->Location = System::Drawing::Point(26, 482);
			this->labelDayVr->Name = L"labelDayVr";
			this->labelDayVr->Size = System::Drawing::Size(35, 18);
			this->labelDayVr->TabIndex = 205;
			this->labelDayVr->Text = L"VR:";
			// 
			// labelDayVolDir2
			// 
			this->labelDayVolDir2->AutoSize = true;
			this->labelDayVolDir2->Location = System::Drawing::Point(483, 154);
			this->labelDayVolDir2->Name = L"labelDayVolDir2";
			this->labelDayVolDir2->Size = System::Drawing::Size(86, 18);
			this->labelDayVolDir2->TabIndex = 204;
			this->labelDayVolDir2->Text = L"Direction2:";
			// 
			// listBoxDayVolDir2
			// 
			this->listBoxDayVolDir2->FormattingEnabled = true;
			this->listBoxDayVolDir2->ItemHeight = 18;
			this->listBoxDayVolDir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayVolDir2->Location = System::Drawing::Point(575, 151);
			this->listBoxDayVolDir2->Name = L"listBoxDayVolDir2";
			this->listBoxDayVolDir2->Size = System::Drawing::Size(106, 22);
			this->listBoxDayVolDir2->TabIndex = 203;
			this->listBoxDayVolDir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayVolDir2_SelectedIndexChanged);
			// 
			// textBoxDayVol2
			// 
			this->textBoxDayVol2->Location = System::Drawing::Point(759, 146);
			this->textBoxDayVol2->Name = L"textBoxDayVol2";
			this->textBoxDayVol2->Size = System::Drawing::Size(124, 26);
			this->textBoxDayVol2->TabIndex = 202;
			this->textBoxDayVol2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayVol2_TextChanged);
			// 
			// textBoxDayVol1
			// 
			this->textBoxDayVol1->Location = System::Drawing::Point(353, 151);
			this->textBoxDayVol1->Name = L"textBoxDayVol1";
			this->textBoxDayVol1->Size = System::Drawing::Size(124, 26);
			this->textBoxDayVol1->TabIndex = 200;
			this->textBoxDayVol1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayVol1_TextChanged);
			// 
			// labelDayVol2
			// 
			this->labelDayVol2->AutoSize = true;
			this->labelDayVol2->Location = System::Drawing::Point(695, 154);
			this->labelDayVol2->Name = L"labelDayVol2";
			this->labelDayVol2->Size = System::Drawing::Size(55, 18);
			this->labelDayVol2->TabIndex = 201;
			this->labelDayVol2->Text = L"VOL2:";
			// 
			// labelDayVol1
			// 
			this->labelDayVol1->AutoSize = true;
			this->labelDayVol1->Location = System::Drawing::Point(290, 156);
			this->labelDayVol1->Name = L"labelDayVol1";
			this->labelDayVol1->Size = System::Drawing::Size(54, 18);
			this->labelDayVol1->TabIndex = 199;
			this->labelDayVol1->Text = L"VOL1:";
			// 
			// labelDayVolDir1
			// 
			this->labelDayVolDir1->AutoSize = true;
			this->labelDayVolDir1->Location = System::Drawing::Point(79, 156);
			this->labelDayVolDir1->Name = L"labelDayVolDir1";
			this->labelDayVolDir1->Size = System::Drawing::Size(85, 18);
			this->labelDayVolDir1->TabIndex = 198;
			this->labelDayVolDir1->Text = L"Direction1:";
			// 
			// listBoxDayVolDir1
			// 
			this->listBoxDayVolDir1->FormattingEnabled = true;
			this->listBoxDayVolDir1->ItemHeight = 18;
			this->listBoxDayVolDir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayVolDir1->Location = System::Drawing::Point(170, 154);
			this->listBoxDayVolDir1->Name = L"listBoxDayVolDir1";
			this->listBoxDayVolDir1->Size = System::Drawing::Size(97, 22);
			this->listBoxDayVolDir1->TabIndex = 197;
			this->listBoxDayVolDir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayVolDir1_SelectedIndexChanged);
			// 
			// labelDayVol
			// 
			this->labelDayVol->AutoSize = true;
			this->labelDayVol->Location = System::Drawing::Point(26, 158);
			this->labelDayVol->Name = L"labelDayVol";
			this->labelDayVol->Size = System::Drawing::Size(46, 18);
			this->labelDayVol->TabIndex = 196;
			this->labelDayVol->Text = L"VOL:";
			// 
			// textBoxDayWr2
			// 
			this->textBoxDayWr2->Location = System::Drawing::Point(557, 382);
			this->textBoxDayWr2->Name = L"textBoxDayWr2";
			this->textBoxDayWr2->Size = System::Drawing::Size(124, 26);
			this->textBoxDayWr2->TabIndex = 195;
			this->textBoxDayWr2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayWr2_TextChanged);
			// 
			// textBoxDayWr1
			// 
			this->textBoxDayWr1->Location = System::Drawing::Point(353, 387);
			this->textBoxDayWr1->Name = L"textBoxDayWr1";
			this->textBoxDayWr1->Size = System::Drawing::Size(124, 26);
			this->textBoxDayWr1->TabIndex = 193;
			this->textBoxDayWr1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayWr1_TextChanged);
			// 
			// labelDayWrLong
			// 
			this->labelDayWrLong->AutoSize = true;
			this->labelDayWrLong->Location = System::Drawing::Point(483, 390);
			this->labelDayWrLong->Name = L"labelDayWrLong";
			this->labelDayWrLong->Size = System::Drawing::Size(48, 18);
			this->labelDayWrLong->TabIndex = 194;
			this->labelDayWrLong->Text = L"WR2:";
			// 
			// labelDayWrShort
			// 
			this->labelDayWrShort->AutoSize = true;
			this->labelDayWrShort->Location = System::Drawing::Point(286, 394);
			this->labelDayWrShort->Name = L"labelDayWrShort";
			this->labelDayWrShort->Size = System::Drawing::Size(47, 18);
			this->labelDayWrShort->TabIndex = 192;
			this->labelDayWrShort->Text = L"WR1:";
			// 
			// labelDayWrDir
			// 
			this->labelDayWrDir->AutoSize = true;
			this->labelDayWrDir->Location = System::Drawing::Point(87, 394);
			this->labelDayWrDir->Name = L"labelDayWrDir";
			this->labelDayWrDir->Size = System::Drawing::Size(77, 18);
			this->labelDayWrDir->TabIndex = 191;
			this->labelDayWrDir->Text = L"Direction:";
			// 
			// listBoxDayWrDir
			// 
			this->listBoxDayWrDir->FormattingEnabled = true;
			this->listBoxDayWrDir->ItemHeight = 18;
			this->listBoxDayWrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayWrDir->Location = System::Drawing::Point(170, 390);
			this->listBoxDayWrDir->Name = L"listBoxDayWrDir";
			this->listBoxDayWrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxDayWrDir->TabIndex = 190;
			this->listBoxDayWrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayWrDir_SelectedIndexChanged);
			// 
			// labelDayWr
			// 
			this->labelDayWr->AutoSize = true;
			this->labelDayWr->Location = System::Drawing::Point(26, 394);
			this->labelDayWr->Name = L"labelDayWr";
			this->labelDayWr->Size = System::Drawing::Size(39, 18);
			this->labelDayWr->TabIndex = 189;
			this->labelDayWr->Text = L"WR:";
			// 
			// textBoxDayRsiLong
			// 
			this->textBoxDayRsiLong->Location = System::Drawing::Point(759, 335);
			this->textBoxDayRsiLong->Name = L"textBoxDayRsiLong";
			this->textBoxDayRsiLong->Size = System::Drawing::Size(124, 26);
			this->textBoxDayRsiLong->TabIndex = 188;
			this->textBoxDayRsiLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayRsiLong_TextChanged);
			// 
			// textBoxDayRsiMiddle
			// 
			this->textBoxDayRsiMiddle->Location = System::Drawing::Point(557, 335);
			this->textBoxDayRsiMiddle->Name = L"textBoxDayRsiMiddle";
			this->textBoxDayRsiMiddle->Size = System::Drawing::Size(124, 26);
			this->textBoxDayRsiMiddle->TabIndex = 186;
			this->textBoxDayRsiMiddle->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayRsiMiddle_TextChanged);
			// 
			// textBoxDayRsiShort
			// 
			this->textBoxDayRsiShort->Location = System::Drawing::Point(353, 340);
			this->textBoxDayRsiShort->Name = L"textBoxDayRsiShort";
			this->textBoxDayRsiShort->Size = System::Drawing::Size(124, 26);
			this->textBoxDayRsiShort->TabIndex = 184;
			this->textBoxDayRsiShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayRsiShort_TextChanged);
			// 
			// labelDayRsiLong
			// 
			this->labelDayRsiLong->AutoSize = true;
			this->labelDayRsiLong->Location = System::Drawing::Point(695, 340);
			this->labelDayRsiLong->Name = L"labelDayRsiLong";
			this->labelDayRsiLong->Size = System::Drawing::Size(48, 18);
			this->labelDayRsiLong->TabIndex = 187;
			this->labelDayRsiLong->Text = L"Long:";
			// 
			// labelDayRsiMiddle
			// 
			this->labelDayRsiMiddle->AutoSize = true;
			this->labelDayRsiMiddle->Location = System::Drawing::Point(483, 343);
			this->labelDayRsiMiddle->Name = L"labelDayRsiMiddle";
			this->labelDayRsiMiddle->Size = System::Drawing::Size(62, 18);
			this->labelDayRsiMiddle->TabIndex = 185;
			this->labelDayRsiMiddle->Text = L"Middle:";
			// 
			// labelDayRsiShort
			// 
			this->labelDayRsiShort->AutoSize = true;
			this->labelDayRsiShort->Location = System::Drawing::Point(286, 347);
			this->labelDayRsiShort->Name = L"labelDayRsiShort";
			this->labelDayRsiShort->Size = System::Drawing::Size(52, 18);
			this->labelDayRsiShort->TabIndex = 183;
			this->labelDayRsiShort->Text = L"Short:";
			// 
			// labelDayRsiDir
			// 
			this->labelDayRsiDir->AutoSize = true;
			this->labelDayRsiDir->Location = System::Drawing::Point(87, 347);
			this->labelDayRsiDir->Name = L"labelDayRsiDir";
			this->labelDayRsiDir->Size = System::Drawing::Size(77, 18);
			this->labelDayRsiDir->TabIndex = 182;
			this->labelDayRsiDir->Text = L"Direction:";
			// 
			// listBoxDayRsiDir
			// 
			this->listBoxDayRsiDir->FormattingEnabled = true;
			this->listBoxDayRsiDir->ItemHeight = 18;
			this->listBoxDayRsiDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayRsiDir->Location = System::Drawing::Point(170, 343);
			this->listBoxDayRsiDir->Name = L"listBoxDayRsiDir";
			this->listBoxDayRsiDir->Size = System::Drawing::Size(97, 22);
			this->listBoxDayRsiDir->TabIndex = 181;
			this->listBoxDayRsiDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayRsiDir_SelectedIndexChanged);
			// 
			// labelDayRsi
			// 
			this->labelDayRsi->AutoSize = true;
			this->labelDayRsi->Location = System::Drawing::Point(26, 347);
			this->labelDayRsi->Name = L"labelDayRsi";
			this->labelDayRsi->Size = System::Drawing::Size(40, 18);
			this->labelDayRsi->TabIndex = 180;
			this->labelDayRsi->Text = L"RSI:";
			// 
			// textBoxDayKdjJ
			// 
			this->textBoxDayKdjJ->Location = System::Drawing::Point(759, 290);
			this->textBoxDayKdjJ->Name = L"textBoxDayKdjJ";
			this->textBoxDayKdjJ->Size = System::Drawing::Size(124, 26);
			this->textBoxDayKdjJ->TabIndex = 179;
			this->textBoxDayKdjJ->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayKdjJ_TextChanged);
			// 
			// textBoxDayKdjD
			// 
			this->textBoxDayKdjD->Location = System::Drawing::Point(557, 290);
			this->textBoxDayKdjD->Name = L"textBoxDayKdjD";
			this->textBoxDayKdjD->Size = System::Drawing::Size(124, 26);
			this->textBoxDayKdjD->TabIndex = 177;
			this->textBoxDayKdjD->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayKdjD_TextChanged);
			// 
			// textBoxDayKdjK
			// 
			this->textBoxDayKdjK->Location = System::Drawing::Point(353, 295);
			this->textBoxDayKdjK->Name = L"textBoxDayKdjK";
			this->textBoxDayKdjK->Size = System::Drawing::Size(124, 26);
			this->textBoxDayKdjK->TabIndex = 175;
			this->textBoxDayKdjK->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayKdjK_TextChanged);
			// 
			// labelDayKdjJ
			// 
			this->labelDayKdjJ->AutoSize = true;
			this->labelDayKdjJ->Location = System::Drawing::Point(695, 298);
			this->labelDayKdjJ->Name = L"labelDayKdjJ";
			this->labelDayKdjJ->Size = System::Drawing::Size(21, 18);
			this->labelDayKdjJ->TabIndex = 178;
			this->labelDayKdjJ->Text = L"J:";
			// 
			// labelDayKdjD
			// 
			this->labelDayKdjD->AutoSize = true;
			this->labelDayKdjD->Location = System::Drawing::Point(500, 298);
			this->labelDayKdjD->Name = L"labelDayKdjD";
			this->labelDayKdjD->Size = System::Drawing::Size(24, 18);
			this->labelDayKdjD->TabIndex = 176;
			this->labelDayKdjD->Text = L"D:";
			// 
			// labelDayKdjK
			// 
			this->labelDayKdjK->AutoSize = true;
			this->labelDayKdjK->Location = System::Drawing::Point(290, 300);
			this->labelDayKdjK->Name = L"labelDayKdjK";
			this->labelDayKdjK->Size = System::Drawing::Size(24, 18);
			this->labelDayKdjK->TabIndex = 174;
			this->labelDayKdjK->Text = L"K:";
			// 
			// labelDayKdjDir
			// 
			this->labelDayKdjDir->AutoSize = true;
			this->labelDayKdjDir->Location = System::Drawing::Point(87, 302);
			this->labelDayKdjDir->Name = L"labelDayKdjDir";
			this->labelDayKdjDir->Size = System::Drawing::Size(77, 18);
			this->labelDayKdjDir->TabIndex = 173;
			this->labelDayKdjDir->Text = L"Direction:";
			// 
			// listBoxDayKdjDir
			// 
			this->listBoxDayKdjDir->FormattingEnabled = true;
			this->listBoxDayKdjDir->ItemHeight = 18;
			this->listBoxDayKdjDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayKdjDir->Location = System::Drawing::Point(170, 298);
			this->listBoxDayKdjDir->Name = L"listBoxDayKdjDir";
			this->listBoxDayKdjDir->Size = System::Drawing::Size(97, 22);
			this->listBoxDayKdjDir->TabIndex = 172;
			this->listBoxDayKdjDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayKdjDir_SelectedIndexChanged);
			// 
			// labelDayKdj
			// 
			this->labelDayKdj->AutoSize = true;
			this->labelDayKdj->Location = System::Drawing::Point(26, 302);
			this->labelDayKdj->Name = L"labelDayKdj";
			this->labelDayKdj->Size = System::Drawing::Size(43, 18);
			this->labelDayKdj->TabIndex = 171;
			this->labelDayKdj->Text = L"KDJ:";
			// 
			// textBoxDayMacdDea
			// 
			this->textBoxDayMacdDea->Location = System::Drawing::Point(759, 243);
			this->textBoxDayMacdDea->Name = L"textBoxDayMacdDea";
			this->textBoxDayMacdDea->Size = System::Drawing::Size(124, 26);
			this->textBoxDayMacdDea->TabIndex = 170;
			this->textBoxDayMacdDea->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayMacdDea_TextChanged);
			// 
			// textBoxDayMacdDif
			// 
			this->textBoxDayMacdDif->Location = System::Drawing::Point(557, 243);
			this->textBoxDayMacdDif->Name = L"textBoxDayMacdDif";
			this->textBoxDayMacdDif->Size = System::Drawing::Size(124, 26);
			this->textBoxDayMacdDif->TabIndex = 168;
			this->textBoxDayMacdDif->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayMacdDif_TextChanged);
			// 
			// textBoxDayMacdMacd
			// 
			this->textBoxDayMacdMacd->Location = System::Drawing::Point(353, 248);
			this->textBoxDayMacdMacd->Name = L"textBoxDayMacdMacd";
			this->textBoxDayMacdMacd->Size = System::Drawing::Size(124, 26);
			this->textBoxDayMacdMacd->TabIndex = 166;
			this->textBoxDayMacdMacd->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayMacdMacd_TextChanged);
			// 
			// labelDayMacdDea
			// 
			this->labelDayMacdDea->AutoSize = true;
			this->labelDayMacdDea->Location = System::Drawing::Point(695, 251);
			this->labelDayMacdDea->Name = L"labelDayMacdDea";
			this->labelDayMacdDea->Size = System::Drawing::Size(40, 18);
			this->labelDayMacdDea->TabIndex = 169;
			this->labelDayMacdDea->Text = L"Dea:";
			// 
			// labelDayMacdDif
			// 
			this->labelDayMacdDif->AutoSize = true;
			this->labelDayMacdDif->Location = System::Drawing::Point(500, 251);
			this->labelDayMacdDif->Name = L"labelDayMacdDif";
			this->labelDayMacdDif->Size = System::Drawing::Size(33, 18);
			this->labelDayMacdDif->TabIndex = 167;
			this->labelDayMacdDif->Text = L"Dif:";
			// 
			// labelDayMacdMacd
			// 
			this->labelDayMacdMacd->AutoSize = true;
			this->labelDayMacdMacd->Location = System::Drawing::Point(290, 253);
			this->labelDayMacdMacd->Name = L"labelDayMacdMacd";
			this->labelDayMacdMacd->Size = System::Drawing::Size(52, 18);
			this->labelDayMacdMacd->TabIndex = 165;
			this->labelDayMacdMacd->Text = L"Macd:";
			// 
			// labelDayMacdDir
			// 
			this->labelDayMacdDir->AutoSize = true;
			this->labelDayMacdDir->Location = System::Drawing::Point(87, 255);
			this->labelDayMacdDir->Name = L"labelDayMacdDir";
			this->labelDayMacdDir->Size = System::Drawing::Size(77, 18);
			this->labelDayMacdDir->TabIndex = 164;
			this->labelDayMacdDir->Text = L"Direction:";
			// 
			// listBoxDayMacdDir
			// 
			this->listBoxDayMacdDir->FormattingEnabled = true;
			this->listBoxDayMacdDir->ItemHeight = 18;
			this->listBoxDayMacdDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayMacdDir->Location = System::Drawing::Point(170, 251);
			this->listBoxDayMacdDir->Name = L"listBoxDayMacdDir";
			this->listBoxDayMacdDir->Size = System::Drawing::Size(97, 22);
			this->listBoxDayMacdDir->TabIndex = 163;
			this->listBoxDayMacdDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayMacdDir_SelectedIndexChanged);
			// 
			// labelDayMacd
			// 
			this->labelDayMacd->AutoSize = true;
			this->labelDayMacd->Location = System::Drawing::Point(26, 255);
			this->labelDayMacd->Name = L"labelDayMacd";
			this->labelDayMacd->Size = System::Drawing::Size(60, 18);
			this->labelDayMacd->TabIndex = 162;
			this->labelDayMacd->Text = L"MACD:";
			// 
			// textBoxDayBollUpper
			// 
			this->textBoxDayBollUpper->Location = System::Drawing::Point(759, 196);
			this->textBoxDayBollUpper->Name = L"textBoxDayBollUpper";
			this->textBoxDayBollUpper->Size = System::Drawing::Size(124, 26);
			this->textBoxDayBollUpper->TabIndex = 161;
			this->textBoxDayBollUpper->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayBollUpper_TextChanged);
			// 
			// textBoxDayBollMid
			// 
			this->textBoxDayBollMid->Location = System::Drawing::Point(557, 198);
			this->textBoxDayBollMid->Name = L"textBoxDayBollMid";
			this->textBoxDayBollMid->Size = System::Drawing::Size(124, 26);
			this->textBoxDayBollMid->TabIndex = 159;
			this->textBoxDayBollMid->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayBollMid_TextChanged);
			// 
			// textBoxDayBollLow
			// 
			this->textBoxDayBollLow->Location = System::Drawing::Point(353, 200);
			this->textBoxDayBollLow->Name = L"textBoxDayBollLow";
			this->textBoxDayBollLow->Size = System::Drawing::Size(124, 26);
			this->textBoxDayBollLow->TabIndex = 157;
			this->textBoxDayBollLow->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxDayBollLow_TextChanged);
			// 
			// labelDayBollUpper
			// 
			this->labelDayBollUpper->AutoSize = true;
			this->labelDayBollUpper->Location = System::Drawing::Point(695, 202);
			this->labelDayBollUpper->Name = L"labelDayBollUpper";
			this->labelDayBollUpper->Size = System::Drawing::Size(58, 18);
			this->labelDayBollUpper->TabIndex = 160;
			this->labelDayBollUpper->Text = L"Upper:";
			// 
			// labelDayBollMid
			// 
			this->labelDayBollMid->AutoSize = true;
			this->labelDayBollMid->Location = System::Drawing::Point(500, 204);
			this->labelDayBollMid->Name = L"labelDayBollMid";
			this->labelDayBollMid->Size = System::Drawing::Size(41, 18);
			this->labelDayBollMid->TabIndex = 158;
			this->labelDayBollMid->Text = L"Mid:";
			// 
			// labelDayBollLow
			// 
			this->labelDayBollLow->AutoSize = true;
			this->labelDayBollLow->Location = System::Drawing::Point(295, 206);
			this->labelDayBollLow->Name = L"labelDayBollLow";
			this->labelDayBollLow->Size = System::Drawing::Size(43, 18);
			this->labelDayBollLow->TabIndex = 156;
			this->labelDayBollLow->Text = L"Low:";
			// 
			// labelDayBollDir
			// 
			this->labelDayBollDir->AutoSize = true;
			this->labelDayBollDir->Location = System::Drawing::Point(87, 206);
			this->labelDayBollDir->Name = L"labelDayBollDir";
			this->labelDayBollDir->Size = System::Drawing::Size(77, 18);
			this->labelDayBollDir->TabIndex = 155;
			this->labelDayBollDir->Text = L"Direction:";
			// 
			// listBoxDayBollDir
			// 
			this->listBoxDayBollDir->FormattingEnabled = true;
			this->listBoxDayBollDir->ItemHeight = 18;
			this->listBoxDayBollDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxDayBollDir->Location = System::Drawing::Point(170, 204);
			this->listBoxDayBollDir->Name = L"listBoxDayBollDir";
			this->listBoxDayBollDir->Size = System::Drawing::Size(97, 22);
			this->listBoxDayBollDir->TabIndex = 154;
			this->listBoxDayBollDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxDayBollDir_SelectedIndexChanged);
			// 
			// labelDayBoll
			// 
			this->labelDayBoll->AutoSize = true;
			this->labelDayBoll->Location = System::Drawing::Point(26, 210);
			this->labelDayBoll->Name = L"labelDayBoll";
			this->labelDayBoll->Size = System::Drawing::Size(55, 18);
			this->labelDayBoll->TabIndex = 153;
			this->labelDayBoll->Text = L"BOLL:";
			// 
			// tabWeek
			// 
			this->tabWeek->Controls->Add(this->listBoxWeekMADir6);
			this->tabWeek->Controls->Add(this->labelWeekMADir6);
			this->tabWeek->Controls->Add(this->textBoxWeekMA6);
			this->tabWeek->Controls->Add(this->textBoxWeekMA5);
			this->tabWeek->Controls->Add(this->labelWeekMA6);
			this->tabWeek->Controls->Add(this->labelWeekMA5);
			this->tabWeek->Controls->Add(this->labelWeekMADir5);
			this->tabWeek->Controls->Add(this->listBoxWeekMADir5);
			this->tabWeek->Controls->Add(this->labelWeekMADir56);
			this->tabWeek->Controls->Add(this->labelWeekMADir4);
			this->tabWeek->Controls->Add(this->listBoxWeekMADir4);
			this->tabWeek->Controls->Add(this->textBoxWeekMA4);
			this->tabWeek->Controls->Add(this->textBoxWeekMA3);
			this->tabWeek->Controls->Add(this->labelWeekMA4);
			this->tabWeek->Controls->Add(this->labelWeekMA3);
			this->tabWeek->Controls->Add(this->labelWeekMADir3);
			this->tabWeek->Controls->Add(this->listBoxWeekMADir3);
			this->tabWeek->Controls->Add(this->labelWeekMADir34);
			this->tabWeek->Controls->Add(this->labelWeekMADir2);
			this->tabWeek->Controls->Add(this->listBoxWeekMADir2);
			this->tabWeek->Controls->Add(this->textBoxWeekMA2);
			this->tabWeek->Controls->Add(this->textBoxWeekMA1);
			this->tabWeek->Controls->Add(this->labelWeekMA2);
			this->tabWeek->Controls->Add(this->labelWeekMA1);
			this->tabWeek->Controls->Add(this->labelWeekMADir1);
			this->tabWeek->Controls->Add(this->listBoxWeekMADir1);
			this->tabWeek->Controls->Add(this->labelWeekMA12);
			this->tabWeek->Controls->Add(this->textBoxWeekCciCci);
			this->tabWeek->Controls->Add(this->labelWeekCciCci);
			this->tabWeek->Controls->Add(this->labelWeekCciDir);
			this->tabWeek->Controls->Add(this->listBoxWeekCciDir);
			this->tabWeek->Controls->Add(this->labelWeekCci);
			this->tabWeek->Controls->Add(this->textBoxWeekCrC);
			this->tabWeek->Controls->Add(this->labelWeekCrC);
			this->tabWeek->Controls->Add(this->textBoxWeekCrB);
			this->tabWeek->Controls->Add(this->labelWeekCrB);
			this->tabWeek->Controls->Add(this->textBoxWeekCrA);
			this->tabWeek->Controls->Add(this->textBoxWeekCrCr);
			this->tabWeek->Controls->Add(this->labelWeekCrA);
			this->tabWeek->Controls->Add(this->labelWeekCrCr);
			this->tabWeek->Controls->Add(this->labelWeekCrDir);
			this->tabWeek->Controls->Add(this->listBoxWeekCrDir);
			this->tabWeek->Controls->Add(this->labelWeekCr);
			this->tabWeek->Controls->Add(this->textBoxWeekDmaAma);
			this->tabWeek->Controls->Add(this->textBoxWeekDmaDma);
			this->tabWeek->Controls->Add(this->labelWeekDmaAma);
			this->tabWeek->Controls->Add(this->labelWeekDmaDma);
			this->tabWeek->Controls->Add(this->labelWeekDmaDir);
			this->tabWeek->Controls->Add(this->listBoxWeekDmaDir);
			this->tabWeek->Controls->Add(this->labelWeekDma);
			this->tabWeek->Controls->Add(this->textBoxWeekRocRocma);
			this->tabWeek->Controls->Add(this->textBoxWeekRocRoc);
			this->tabWeek->Controls->Add(this->labelWeekRocRocma);
			this->tabWeek->Controls->Add(this->labelWeekRocRoc);
			this->tabWeek->Controls->Add(this->labelWeekRocDir);
			this->tabWeek->Controls->Add(this->listBoxWeekRocDir);
			this->tabWeek->Controls->Add(this->labelWeekRoc);
			this->tabWeek->Controls->Add(this->textBoxWeekVrLong);
			this->tabWeek->Controls->Add(this->textBoxWeekVrShort);
			this->tabWeek->Controls->Add(this->labelWeekVrLong);
			this->tabWeek->Controls->Add(this->labelWeekVrShort);
			this->tabWeek->Controls->Add(this->labelWeekVrDir);
			this->tabWeek->Controls->Add(this->listBoxWeekVrDir);
			this->tabWeek->Controls->Add(this->labelWeekVr);
			this->tabWeek->Controls->Add(this->labelWeekVolDir2);
			this->tabWeek->Controls->Add(this->listBoxWeekVolDir2);
			this->tabWeek->Controls->Add(this->textBoxWeekVol2);
			this->tabWeek->Controls->Add(this->textBoxWeekVol1);
			this->tabWeek->Controls->Add(this->labelWeekVol2);
			this->tabWeek->Controls->Add(this->labelWeekVol1);
			this->tabWeek->Controls->Add(this->labelWeekVolDir1);
			this->tabWeek->Controls->Add(this->listBoxWeekVolDir1);
			this->tabWeek->Controls->Add(this->labelWeekVol);
			this->tabWeek->Controls->Add(this->textBoxWeekWr2);
			this->tabWeek->Controls->Add(this->textBoxWeekWr1);
			this->tabWeek->Controls->Add(this->labelWeekWr2);
			this->tabWeek->Controls->Add(this->labelWeekWr1);
			this->tabWeek->Controls->Add(this->labelWeekWrDir);
			this->tabWeek->Controls->Add(this->listBoxWeekWrDir);
			this->tabWeek->Controls->Add(this->labelWeekWr);
			this->tabWeek->Controls->Add(this->textBoxWeekRsiLong);
			this->tabWeek->Controls->Add(this->textBoxWeekRsiMiddle);
			this->tabWeek->Controls->Add(this->textBoxWeekRsiShort);
			this->tabWeek->Controls->Add(this->labelWeekRsiLong);
			this->tabWeek->Controls->Add(this->labelWeekRsiMiddle);
			this->tabWeek->Controls->Add(this->labelWeekRsiShort);
			this->tabWeek->Controls->Add(this->labelWeekRsiDir);
			this->tabWeek->Controls->Add(this->listBoxWeekRsiDir);
			this->tabWeek->Controls->Add(this->labelWeekRsi);
			this->tabWeek->Controls->Add(this->textBoxWeekKdjJ);
			this->tabWeek->Controls->Add(this->textBoxWeekKdjD);
			this->tabWeek->Controls->Add(this->textBoxWeekKdjK);
			this->tabWeek->Controls->Add(this->labelWeekKdjJ);
			this->tabWeek->Controls->Add(this->labelWeekKdjD);
			this->tabWeek->Controls->Add(this->labelWeekKdjK);
			this->tabWeek->Controls->Add(this->labelWeekKdjDir);
			this->tabWeek->Controls->Add(this->listBoxWeekKdjDir);
			this->tabWeek->Controls->Add(this->labelWeekKdj);
			this->tabWeek->Controls->Add(this->textBoxWeekMacdDea);
			this->tabWeek->Controls->Add(this->textBoxWeekMacdDif);
			this->tabWeek->Controls->Add(this->textBoxWeekMacdMacd);
			this->tabWeek->Controls->Add(this->labelWeekMacdDea);
			this->tabWeek->Controls->Add(this->labelWeekMacdDif);
			this->tabWeek->Controls->Add(this->labelWeekMacdMacd);
			this->tabWeek->Controls->Add(this->labelWeekMacdDir);
			this->tabWeek->Controls->Add(this->listBoxWeekMacdDir);
			this->tabWeek->Controls->Add(this->labelWeekMacd);
			this->tabWeek->Controls->Add(this->textBoxWeekBollUpper);
			this->tabWeek->Controls->Add(this->textBoxWeekBollMid);
			this->tabWeek->Controls->Add(this->textBoxWeekBollLow);
			this->tabWeek->Controls->Add(this->labelWeekBollUpper);
			this->tabWeek->Controls->Add(this->labelWeekBollMid);
			this->tabWeek->Controls->Add(this->labelWeekBollLow);
			this->tabWeek->Controls->Add(this->labelWeekBollDir);
			this->tabWeek->Controls->Add(this->listBoxWeekBollDir);
			this->tabWeek->Controls->Add(this->labelWeekBoll);
			this->tabWeek->Location = System::Drawing::Point(4, 27);
			this->tabWeek->Name = L"tabWeek";
			this->tabWeek->Padding = System::Windows::Forms::Padding(3);
			this->tabWeek->Size = System::Drawing::Size(1092, 869);
			this->tabWeek->TabIndex = 2;
			this->tabWeek->Text = L"Week";
			this->tabWeek->UseVisualStyleBackColor = true;
			// 
			// listBoxWeekMADir6
			// 
			this->listBoxWeekMADir6->FormattingEnabled = true;
			this->listBoxWeekMADir6->ItemHeight = 18;
			this->listBoxWeekMADir6->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekMADir6->Location = System::Drawing::Point(575, 103);
			this->listBoxWeekMADir6->Name = L"listBoxWeekMADir6";
			this->listBoxWeekMADir6->Size = System::Drawing::Size(106, 22);
			this->listBoxWeekMADir6->TabIndex = 269;
			this->listBoxWeekMADir6->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekMADir6_SelectedIndexChanged);
			// 
			// labelWeekMADir6
			// 
			this->labelWeekMADir6->AutoSize = true;
			this->labelWeekMADir6->Location = System::Drawing::Point(483, 107);
			this->labelWeekMADir6->Name = L"labelWeekMADir6";
			this->labelWeekMADir6->Size = System::Drawing::Size(80, 18);
			this->labelWeekMADir6->TabIndex = 268;
			this->labelWeekMADir6->Text = L"MA_Dir6:";
			// 
			// textBoxWeekMA6
			// 
			this->textBoxWeekMA6->Location = System::Drawing::Point(759, 99);
			this->textBoxWeekMA6->Name = L"textBoxWeekMA6";
			this->textBoxWeekMA6->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekMA6->TabIndex = 266;
			this->textBoxWeekMA6->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekMA6_TextChanged);
			// 
			// textBoxWeekMA5
			// 
			this->textBoxWeekMA5->Location = System::Drawing::Point(353, 104);
			this->textBoxWeekMA5->Name = L"textBoxWeekMA5";
			this->textBoxWeekMA5->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekMA5->TabIndex = 264;
			this->textBoxWeekMA5->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekMA5_TextChanged);
			// 
			// labelWeekMA6
			// 
			this->labelWeekMA6->AutoSize = true;
			this->labelWeekMA6->Location = System::Drawing::Point(695, 107);
			this->labelWeekMA6->Name = L"labelWeekMA6";
			this->labelWeekMA6->Size = System::Drawing::Size(48, 18);
			this->labelWeekMA6->TabIndex = 265;
			this->labelWeekMA6->Text = L"MA6:";
			// 
			// labelWeekMA5
			// 
			this->labelWeekMA5->AutoSize = true;
			this->labelWeekMA5->Location = System::Drawing::Point(290, 109);
			this->labelWeekMA5->Name = L"labelWeekMA5";
			this->labelWeekMA5->Size = System::Drawing::Size(48, 18);
			this->labelWeekMA5->TabIndex = 263;
			this->labelWeekMA5->Text = L"MA5:";
			// 
			// labelWeekMADir5
			// 
			this->labelWeekMADir5->AutoSize = true;
			this->labelWeekMADir5->Location = System::Drawing::Point(79, 112);
			this->labelWeekMADir5->Name = L"labelWeekMADir5";
			this->labelWeekMADir5->Size = System::Drawing::Size(80, 18);
			this->labelWeekMADir5->TabIndex = 262;
			this->labelWeekMADir5->Text = L"MA_Dir5:";
			// 
			// listBoxWeekMADir5
			// 
			this->listBoxWeekMADir5->FormattingEnabled = true;
			this->listBoxWeekMADir5->ItemHeight = 18;
			this->listBoxWeekMADir5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekMADir5->Location = System::Drawing::Point(170, 107);
			this->listBoxWeekMADir5->Name = L"listBoxWeekMADir5";
			this->listBoxWeekMADir5->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekMADir5->TabIndex = 261;
			this->listBoxWeekMADir5->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekMADir_SelectedIndexChanged);
			// 
			// labelWeekMADir56
			// 
			this->labelWeekMADir56->AutoSize = true;
			this->labelWeekMADir56->Location = System::Drawing::Point(17, 112);
			this->labelWeekMADir56->Name = L"labelWeekMADir56";
			this->labelWeekMADir56->Size = System::Drawing::Size(64, 18);
			this->labelWeekMADir56->TabIndex = 260;
			this->labelWeekMADir56->Text = L"MA5-6:";
			// 
			// labelWeekMADir4
			// 
			this->labelWeekMADir4->AutoSize = true;
			this->labelWeekMADir4->Location = System::Drawing::Point(483, 60);
			this->labelWeekMADir4->Name = L"labelWeekMADir4";
			this->labelWeekMADir4->Size = System::Drawing::Size(80, 18);
			this->labelWeekMADir4->TabIndex = 259;
			this->labelWeekMADir4->Text = L"MA_Dir4:";
			// 
			// listBoxWeekMADir4
			// 
			this->listBoxWeekMADir4->FormattingEnabled = true;
			this->listBoxWeekMADir4->ItemHeight = 18;
			this->listBoxWeekMADir4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekMADir4->Location = System::Drawing::Point(575, 57);
			this->listBoxWeekMADir4->Name = L"listBoxWeekMADir4";
			this->listBoxWeekMADir4->Size = System::Drawing::Size(106, 22);
			this->listBoxWeekMADir4->TabIndex = 258;
			this->listBoxWeekMADir4->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekMADir4_SelectedIndexChanged);
			// 
			// textBoxWeekMA4
			// 
			this->textBoxWeekMA4->Location = System::Drawing::Point(759, 52);
			this->textBoxWeekMA4->Name = L"textBoxWeekMA4";
			this->textBoxWeekMA4->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekMA4->TabIndex = 257;
			this->textBoxWeekMA4->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekMA4_TextChanged);
			// 
			// textBoxWeekMA3
			// 
			this->textBoxWeekMA3->Location = System::Drawing::Point(353, 57);
			this->textBoxWeekMA3->Name = L"textBoxWeekMA3";
			this->textBoxWeekMA3->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekMA3->TabIndex = 255;
			this->textBoxWeekMA3->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekMA3_TextChanged);
			// 
			// labelWeekMA4
			// 
			this->labelWeekMA4->AutoSize = true;
			this->labelWeekMA4->Location = System::Drawing::Point(695, 60);
			this->labelWeekMA4->Name = L"labelWeekMA4";
			this->labelWeekMA4->Size = System::Drawing::Size(48, 18);
			this->labelWeekMA4->TabIndex = 256;
			this->labelWeekMA4->Text = L"MA4:";
			// 
			// labelWeekMA3
			// 
			this->labelWeekMA3->AutoSize = true;
			this->labelWeekMA3->Location = System::Drawing::Point(290, 62);
			this->labelWeekMA3->Name = L"labelWeekMA3";
			this->labelWeekMA3->Size = System::Drawing::Size(48, 18);
			this->labelWeekMA3->TabIndex = 254;
			this->labelWeekMA3->Text = L"MA3:";
			// 
			// labelWeekMADir3
			// 
			this->labelWeekMADir3->AutoSize = true;
			this->labelWeekMADir3->Location = System::Drawing::Point(79, 65);
			this->labelWeekMADir3->Name = L"labelWeekMADir3";
			this->labelWeekMADir3->Size = System::Drawing::Size(80, 18);
			this->labelWeekMADir3->TabIndex = 253;
			this->labelWeekMADir3->Text = L"MA_Dir3:";
			// 
			// listBoxWeekMADir3
			// 
			this->listBoxWeekMADir3->FormattingEnabled = true;
			this->listBoxWeekMADir3->ItemHeight = 18;
			this->listBoxWeekMADir3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekMADir3->Location = System::Drawing::Point(170, 60);
			this->listBoxWeekMADir3->Name = L"listBoxWeekMADir3";
			this->listBoxWeekMADir3->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekMADir3->TabIndex = 252;
			this->listBoxWeekMADir3->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekMADir3_SelectedIndexChanged);
			// 
			// labelWeekMADir34
			// 
			this->labelWeekMADir34->AutoSize = true;
			this->labelWeekMADir34->Location = System::Drawing::Point(17, 65);
			this->labelWeekMADir34->Name = L"labelWeekMADir34";
			this->labelWeekMADir34->Size = System::Drawing::Size(64, 18);
			this->labelWeekMADir34->TabIndex = 251;
			this->labelWeekMADir34->Text = L"MA3-4:";
			// 
			// labelWeekMADir2
			// 
			this->labelWeekMADir2->AutoSize = true;
			this->labelWeekMADir2->Location = System::Drawing::Point(483, 19);
			this->labelWeekMADir2->Name = L"labelWeekMADir2";
			this->labelWeekMADir2->Size = System::Drawing::Size(80, 18);
			this->labelWeekMADir2->TabIndex = 250;
			this->labelWeekMADir2->Text = L"MA_Dir2:";
			// 
			// listBoxWeekMADir2
			// 
			this->listBoxWeekMADir2->FormattingEnabled = true;
			this->listBoxWeekMADir2->ItemHeight = 18;
			this->listBoxWeekMADir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekMADir2->Location = System::Drawing::Point(575, 16);
			this->listBoxWeekMADir2->Name = L"listBoxWeekMADir2";
			this->listBoxWeekMADir2->Size = System::Drawing::Size(106, 22);
			this->listBoxWeekMADir2->TabIndex = 249;
			this->listBoxWeekMADir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekMADir2_SelectedIndexChanged);
			// 
			// textBoxWeekMA2
			// 
			this->textBoxWeekMA2->Location = System::Drawing::Point(759, 11);
			this->textBoxWeekMA2->Name = L"textBoxWeekMA2";
			this->textBoxWeekMA2->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekMA2->TabIndex = 248;
			this->textBoxWeekMA2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekMA2_TextChanged);
			// 
			// textBoxWeekMA1
			// 
			this->textBoxWeekMA1->Location = System::Drawing::Point(353, 16);
			this->textBoxWeekMA1->Name = L"textBoxWeekMA1";
			this->textBoxWeekMA1->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekMA1->TabIndex = 246;
			this->textBoxWeekMA1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekMA1_TextChanged);
			// 
			// labelWeekMA2
			// 
			this->labelWeekMA2->AutoSize = true;
			this->labelWeekMA2->Location = System::Drawing::Point(695, 19);
			this->labelWeekMA2->Name = L"labelWeekMA2";
			this->labelWeekMA2->Size = System::Drawing::Size(48, 18);
			this->labelWeekMA2->TabIndex = 247;
			this->labelWeekMA2->Text = L"MA2:";
			// 
			// labelWeekMA1
			// 
			this->labelWeekMA1->AutoSize = true;
			this->labelWeekMA1->Location = System::Drawing::Point(290, 21);
			this->labelWeekMA1->Name = L"labelWeekMA1";
			this->labelWeekMA1->Size = System::Drawing::Size(47, 18);
			this->labelWeekMA1->TabIndex = 245;
			this->labelWeekMA1->Text = L"MA1:";
			// 
			// labelWeekMADir1
			// 
			this->labelWeekMADir1->AutoSize = true;
			this->labelWeekMADir1->Location = System::Drawing::Point(79, 21);
			this->labelWeekMADir1->Name = L"labelWeekMADir1";
			this->labelWeekMADir1->Size = System::Drawing::Size(79, 18);
			this->labelWeekMADir1->TabIndex = 244;
			this->labelWeekMADir1->Text = L"MA_Dir1:";
			// 
			// listBoxWeekMADir1
			// 
			this->listBoxWeekMADir1->FormattingEnabled = true;
			this->listBoxWeekMADir1->ItemHeight = 18;
			this->listBoxWeekMADir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekMADir1->Location = System::Drawing::Point(170, 19);
			this->listBoxWeekMADir1->Name = L"listBoxWeekMADir1";
			this->listBoxWeekMADir1->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekMADir1->TabIndex = 243;
			this->listBoxWeekMADir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekMADir1_SelectedIndexChanged);
			// 
			// labelWeekMA12
			// 
			this->labelWeekMA12->AutoSize = true;
			this->labelWeekMA12->Location = System::Drawing::Point(16, 24);
			this->labelWeekMA12->Name = L"labelWeekMA12";
			this->labelWeekMA12->Size = System::Drawing::Size(63, 18);
			this->labelWeekMA12->TabIndex = 242;
			this->labelWeekMA12->Text = L"MA1-2:";
			// 
			// textBoxWeekCciCci
			// 
			this->textBoxWeekCciCci->Location = System::Drawing::Point(353, 601);
			this->textBoxWeekCciCci->Name = L"textBoxWeekCciCci";
			this->textBoxWeekCciCci->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekCciCci->TabIndex = 241;
			this->textBoxWeekCciCci->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekCciCci_TextChanged);
			// 
			// labelWeekCciCci
			// 
			this->labelWeekCciCci->AutoSize = true;
			this->labelWeekCciCci->Location = System::Drawing::Point(286, 608);
			this->labelWeekCciCci->Name = L"labelWeekCciCci";
			this->labelWeekCciCci->Size = System::Drawing::Size(34, 18);
			this->labelWeekCciCci->TabIndex = 240;
			this->labelWeekCciCci->Text = L"Cci:";
			// 
			// labelWeekCciDir
			// 
			this->labelWeekCciDir->AutoSize = true;
			this->labelWeekCciDir->Location = System::Drawing::Point(87, 608);
			this->labelWeekCciDir->Name = L"labelWeekCciDir";
			this->labelWeekCciDir->Size = System::Drawing::Size(77, 18);
			this->labelWeekCciDir->TabIndex = 239;
			this->labelWeekCciDir->Text = L"Direction:";
			// 
			// listBoxWeekCciDir
			// 
			this->listBoxWeekCciDir->FormattingEnabled = true;
			this->listBoxWeekCciDir->ItemHeight = 18;
			this->listBoxWeekCciDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekCciDir->Location = System::Drawing::Point(170, 604);
			this->listBoxWeekCciDir->Name = L"listBoxWeekCciDir";
			this->listBoxWeekCciDir->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekCciDir->TabIndex = 238;
			this->listBoxWeekCciDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekCciDir_SelectedIndexChanged);
			// 
			// labelWeekCci
			// 
			this->labelWeekCci->AutoSize = true;
			this->labelWeekCci->Location = System::Drawing::Point(26, 608);
			this->labelWeekCci->Name = L"labelWeekCci";
			this->labelWeekCci->Size = System::Drawing::Size(40, 18);
			this->labelWeekCci->TabIndex = 237;
			this->labelWeekCci->Text = L"CCI:";
			// 
			// textBoxWeekCrC
			// 
			this->textBoxWeekCrC->Location = System::Drawing::Point(961, 555);
			this->textBoxWeekCrC->Name = L"textBoxWeekCrC";
			this->textBoxWeekCrC->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekCrC->TabIndex = 236;
			this->textBoxWeekCrC->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekCrC_TextChanged);
			// 
			// labelWeekCrC
			// 
			this->labelWeekCrC->AutoSize = true;
			this->labelWeekCrC->Location = System::Drawing::Point(900, 563);
			this->labelWeekCrC->Name = L"labelWeekCrC";
			this->labelWeekCrC->Size = System::Drawing::Size(23, 18);
			this->labelWeekCrC->TabIndex = 235;
			this->labelWeekCrC->Text = L"C:";
			// 
			// textBoxWeekCrB
			// 
			this->textBoxWeekCrB->Location = System::Drawing::Point(755, 555);
			this->textBoxWeekCrB->Name = L"textBoxWeekCrB";
			this->textBoxWeekCrB->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekCrB->TabIndex = 234;
			this->textBoxWeekCrB->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekCrB_TextChanged);
			// 
			// labelWeekCrB
			// 
			this->labelWeekCrB->AutoSize = true;
			this->labelWeekCrB->Location = System::Drawing::Point(694, 563);
			this->labelWeekCrB->Name = L"labelWeekCrB";
			this->labelWeekCrB->Size = System::Drawing::Size(23, 18);
			this->labelWeekCrB->TabIndex = 233;
			this->labelWeekCrB->Text = L"B:";
			// 
			// textBoxWeekCrA
			// 
			this->textBoxWeekCrA->Location = System::Drawing::Point(557, 555);
			this->textBoxWeekCrA->Name = L"textBoxWeekCrA";
			this->textBoxWeekCrA->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekCrA->TabIndex = 232;
			this->textBoxWeekCrA->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekCrA_TextChanged);
			// 
			// textBoxWeekCrCr
			// 
			this->textBoxWeekCrCr->Location = System::Drawing::Point(353, 560);
			this->textBoxWeekCrCr->Name = L"textBoxWeekCrCr";
			this->textBoxWeekCrCr->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekCrCr->TabIndex = 230;
			this->textBoxWeekCrCr->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekCrCr_TextChanged);
			// 
			// labelWeekCrA
			// 
			this->labelWeekCrA->AutoSize = true;
			this->labelWeekCrA->Location = System::Drawing::Point(496, 563);
			this->labelWeekCrA->Name = L"labelWeekCrA";
			this->labelWeekCrA->Size = System::Drawing::Size(24, 18);
			this->labelWeekCrA->TabIndex = 231;
			this->labelWeekCrA->Text = L"A:";
			// 
			// labelWeekCrCr
			// 
			this->labelWeekCrCr->AutoSize = true;
			this->labelWeekCrCr->Location = System::Drawing::Point(286, 567);
			this->labelWeekCrCr->Name = L"labelWeekCrCr";
			this->labelWeekCrCr->Size = System::Drawing::Size(30, 18);
			this->labelWeekCrCr->TabIndex = 229;
			this->labelWeekCrCr->Text = L"Cr:";
			// 
			// labelWeekCrDir
			// 
			this->labelWeekCrDir->AutoSize = true;
			this->labelWeekCrDir->Location = System::Drawing::Point(87, 567);
			this->labelWeekCrDir->Name = L"labelWeekCrDir";
			this->labelWeekCrDir->Size = System::Drawing::Size(77, 18);
			this->labelWeekCrDir->TabIndex = 228;
			this->labelWeekCrDir->Text = L"Direction:";
			// 
			// listBoxWeekCrDir
			// 
			this->listBoxWeekCrDir->FormattingEnabled = true;
			this->listBoxWeekCrDir->ItemHeight = 18;
			this->listBoxWeekCrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekCrDir->Location = System::Drawing::Point(170, 563);
			this->listBoxWeekCrDir->Name = L"listBoxWeekCrDir";
			this->listBoxWeekCrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekCrDir->TabIndex = 227;
			this->listBoxWeekCrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekCrDir_SelectedIndexChanged);
			// 
			// labelWeekCr
			// 
			this->labelWeekCr->AutoSize = true;
			this->labelWeekCr->Location = System::Drawing::Point(26, 567);
			this->labelWeekCr->Name = L"labelWeekCr";
			this->labelWeekCr->Size = System::Drawing::Size(34, 18);
			this->labelWeekCr->TabIndex = 226;
			this->labelWeekCr->Text = L"CR:";
			// 
			// textBoxWeekDmaAma
			// 
			this->textBoxWeekDmaAma->Location = System::Drawing::Point(557, 513);
			this->textBoxWeekDmaAma->Name = L"textBoxWeekDmaAma";
			this->textBoxWeekDmaAma->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekDmaAma->TabIndex = 225;
			this->textBoxWeekDmaAma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekDmaAma_TextChanged);
			// 
			// textBoxWeekDmaDma
			// 
			this->textBoxWeekDmaDma->Location = System::Drawing::Point(353, 518);
			this->textBoxWeekDmaDma->Name = L"textBoxWeekDmaDma";
			this->textBoxWeekDmaDma->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekDmaDma->TabIndex = 223;
			this->textBoxWeekDmaDma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekDmaDma_TextChanged);
			// 
			// labelWeekDmaAma
			// 
			this->labelWeekDmaAma->AutoSize = true;
			this->labelWeekDmaAma->Location = System::Drawing::Point(483, 521);
			this->labelWeekDmaAma->Name = L"labelWeekDmaAma";
			this->labelWeekDmaAma->Size = System::Drawing::Size(46, 18);
			this->labelWeekDmaAma->TabIndex = 224;
			this->labelWeekDmaAma->Text = L"Ama:";
			// 
			// labelWeekDmaDma
			// 
			this->labelWeekDmaDma->AutoSize = true;
			this->labelWeekDmaDma->Location = System::Drawing::Point(286, 525);
			this->labelWeekDmaDma->Name = L"labelWeekDmaDma";
			this->labelWeekDmaDma->Size = System::Drawing::Size(46, 18);
			this->labelWeekDmaDma->TabIndex = 222;
			this->labelWeekDmaDma->Text = L"Dma:";
			// 
			// labelWeekDmaDir
			// 
			this->labelWeekDmaDir->AutoSize = true;
			this->labelWeekDmaDir->Location = System::Drawing::Point(87, 525);
			this->labelWeekDmaDir->Name = L"labelWeekDmaDir";
			this->labelWeekDmaDir->Size = System::Drawing::Size(77, 18);
			this->labelWeekDmaDir->TabIndex = 221;
			this->labelWeekDmaDir->Text = L"Direction:";
			// 
			// listBoxWeekDmaDir
			// 
			this->listBoxWeekDmaDir->FormattingEnabled = true;
			this->listBoxWeekDmaDir->ItemHeight = 18;
			this->listBoxWeekDmaDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekDmaDir->Location = System::Drawing::Point(170, 521);
			this->listBoxWeekDmaDir->Name = L"listBoxWeekDmaDir";
			this->listBoxWeekDmaDir->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekDmaDir->TabIndex = 220;
			this->listBoxWeekDmaDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekDmaDir_SelectedIndexChanged);
			// 
			// labelWeekDma
			// 
			this->labelWeekDma->AutoSize = true;
			this->labelWeekDma->Location = System::Drawing::Point(26, 525);
			this->labelWeekDma->Name = L"labelWeekDma";
			this->labelWeekDma->Size = System::Drawing::Size(50, 18);
			this->labelWeekDma->TabIndex = 219;
			this->labelWeekDma->Text = L"DMA:";
			// 
			// textBoxWeekRocRocma
			// 
			this->textBoxWeekRocRocma->Location = System::Drawing::Point(557, 427);
			this->textBoxWeekRocRocma->Name = L"textBoxWeekRocRocma";
			this->textBoxWeekRocRocma->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekRocRocma->TabIndex = 218;
			this->textBoxWeekRocRocma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekRocRocma_TextChanged);
			// 
			// textBoxWeekRocRoc
			// 
			this->textBoxWeekRocRoc->Location = System::Drawing::Point(353, 432);
			this->textBoxWeekRocRoc->Name = L"textBoxWeekRocRoc";
			this->textBoxWeekRocRoc->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekRocRoc->TabIndex = 216;
			this->textBoxWeekRocRoc->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekRocRoc_TextChanged);
			// 
			// labelWeekRocRocma
			// 
			this->labelWeekRocRocma->AutoSize = true;
			this->labelWeekRocRocma->Location = System::Drawing::Point(483, 435);
			this->labelWeekRocRocma->Name = L"labelWeekRocRocma";
			this->labelWeekRocRocma->Size = System::Drawing::Size(71, 18);
			this->labelWeekRocRocma->TabIndex = 217;
			this->labelWeekRocRocma->Text = L"Roc_ma:";
			// 
			// labelWeekRocRoc
			// 
			this->labelWeekRocRoc->AutoSize = true;
			this->labelWeekRocRoc->Location = System::Drawing::Point(286, 439);
			this->labelWeekRocRoc->Name = L"labelWeekRocRoc";
			this->labelWeekRocRoc->Size = System::Drawing::Size(39, 18);
			this->labelWeekRocRoc->TabIndex = 215;
			this->labelWeekRocRoc->Text = L"Roc:";
			// 
			// labelWeekRocDir
			// 
			this->labelWeekRocDir->AutoSize = true;
			this->labelWeekRocDir->Location = System::Drawing::Point(87, 439);
			this->labelWeekRocDir->Name = L"labelWeekRocDir";
			this->labelWeekRocDir->Size = System::Drawing::Size(77, 18);
			this->labelWeekRocDir->TabIndex = 214;
			this->labelWeekRocDir->Text = L"Direction:";
			// 
			// listBoxWeekRocDir
			// 
			this->listBoxWeekRocDir->FormattingEnabled = true;
			this->listBoxWeekRocDir->ItemHeight = 18;
			this->listBoxWeekRocDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekRocDir->Location = System::Drawing::Point(170, 435);
			this->listBoxWeekRocDir->Name = L"listBoxWeekRocDir";
			this->listBoxWeekRocDir->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekRocDir->TabIndex = 213;
			this->listBoxWeekRocDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekRocDir_SelectedIndexChanged);
			// 
			// labelWeekRoc
			// 
			this->labelWeekRoc->AutoSize = true;
			this->labelWeekRoc->Location = System::Drawing::Point(26, 439);
			this->labelWeekRoc->Name = L"labelWeekRoc";
			this->labelWeekRoc->Size = System::Drawing::Size(46, 18);
			this->labelWeekRoc->TabIndex = 212;
			this->labelWeekRoc->Text = L"ROC:";
			// 
			// textBoxWeekVrLong
			// 
			this->textBoxWeekVrLong->Location = System::Drawing::Point(557, 470);
			this->textBoxWeekVrLong->Name = L"textBoxWeekVrLong";
			this->textBoxWeekVrLong->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekVrLong->TabIndex = 211;
			this->textBoxWeekVrLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekVrLong_TextChanged);
			// 
			// textBoxWeekVrShort
			// 
			this->textBoxWeekVrShort->Location = System::Drawing::Point(353, 475);
			this->textBoxWeekVrShort->Name = L"textBoxWeekVrShort";
			this->textBoxWeekVrShort->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekVrShort->TabIndex = 209;
			this->textBoxWeekVrShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekVrShort_TextChanged);
			// 
			// labelWeekVrLong
			// 
			this->labelWeekVrLong->AutoSize = true;
			this->labelWeekVrLong->Location = System::Drawing::Point(483, 478);
			this->labelWeekVrLong->Name = L"labelWeekVrLong";
			this->labelWeekVrLong->Size = System::Drawing::Size(48, 18);
			this->labelWeekVrLong->TabIndex = 210;
			this->labelWeekVrLong->Text = L"Long:";
			// 
			// labelWeekVrShort
			// 
			this->labelWeekVrShort->AutoSize = true;
			this->labelWeekVrShort->Location = System::Drawing::Point(281, 483);
			this->labelWeekVrShort->Name = L"labelWeekVrShort";
			this->labelWeekVrShort->Size = System::Drawing::Size(52, 18);
			this->labelWeekVrShort->TabIndex = 208;
			this->labelWeekVrShort->Text = L"Short:";
			// 
			// labelWeekVrDir
			// 
			this->labelWeekVrDir->AutoSize = true;
			this->labelWeekVrDir->Location = System::Drawing::Point(87, 482);
			this->labelWeekVrDir->Name = L"labelWeekVrDir";
			this->labelWeekVrDir->Size = System::Drawing::Size(77, 18);
			this->labelWeekVrDir->TabIndex = 207;
			this->labelWeekVrDir->Text = L"Direction:";
			// 
			// listBoxWeekVrDir
			// 
			this->listBoxWeekVrDir->FormattingEnabled = true;
			this->listBoxWeekVrDir->ItemHeight = 18;
			this->listBoxWeekVrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekVrDir->Location = System::Drawing::Point(170, 478);
			this->listBoxWeekVrDir->Name = L"listBoxWeekVrDir";
			this->listBoxWeekVrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekVrDir->TabIndex = 206;
			this->listBoxWeekVrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekVrDir_SelectedIndexChanged);
			// 
			// labelWeekVr
			// 
			this->labelWeekVr->AutoSize = true;
			this->labelWeekVr->Location = System::Drawing::Point(26, 482);
			this->labelWeekVr->Name = L"labelWeekVr";
			this->labelWeekVr->Size = System::Drawing::Size(35, 18);
			this->labelWeekVr->TabIndex = 205;
			this->labelWeekVr->Text = L"VR:";
			// 
			// labelWeekVolDir2
			// 
			this->labelWeekVolDir2->AutoSize = true;
			this->labelWeekVolDir2->Location = System::Drawing::Point(483, 154);
			this->labelWeekVolDir2->Name = L"labelWeekVolDir2";
			this->labelWeekVolDir2->Size = System::Drawing::Size(86, 18);
			this->labelWeekVolDir2->TabIndex = 204;
			this->labelWeekVolDir2->Text = L"Direction2:";
			// 
			// listBoxWeekVolDir2
			// 
			this->listBoxWeekVolDir2->FormattingEnabled = true;
			this->listBoxWeekVolDir2->ItemHeight = 18;
			this->listBoxWeekVolDir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekVolDir2->Location = System::Drawing::Point(575, 151);
			this->listBoxWeekVolDir2->Name = L"listBoxWeekVolDir2";
			this->listBoxWeekVolDir2->Size = System::Drawing::Size(106, 22);
			this->listBoxWeekVolDir2->TabIndex = 203;
			this->listBoxWeekVolDir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekVolDir2_SelectedIndexChanged);
			// 
			// textBoxWeekVol2
			// 
			this->textBoxWeekVol2->Location = System::Drawing::Point(759, 146);
			this->textBoxWeekVol2->Name = L"textBoxWeekVol2";
			this->textBoxWeekVol2->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekVol2->TabIndex = 202;
			this->textBoxWeekVol2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekVol2_TextChanged);
			// 
			// textBoxWeekVol1
			// 
			this->textBoxWeekVol1->Location = System::Drawing::Point(353, 151);
			this->textBoxWeekVol1->Name = L"textBoxWeekVol1";
			this->textBoxWeekVol1->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekVol1->TabIndex = 200;
			this->textBoxWeekVol1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekVol1_TextChanged);
			// 
			// labelWeekVol2
			// 
			this->labelWeekVol2->AutoSize = true;
			this->labelWeekVol2->Location = System::Drawing::Point(695, 154);
			this->labelWeekVol2->Name = L"labelWeekVol2";
			this->labelWeekVol2->Size = System::Drawing::Size(55, 18);
			this->labelWeekVol2->TabIndex = 201;
			this->labelWeekVol2->Text = L"VOL2:";
			// 
			// labelWeekVol1
			// 
			this->labelWeekVol1->AutoSize = true;
			this->labelWeekVol1->Location = System::Drawing::Point(290, 156);
			this->labelWeekVol1->Name = L"labelWeekVol1";
			this->labelWeekVol1->Size = System::Drawing::Size(54, 18);
			this->labelWeekVol1->TabIndex = 199;
			this->labelWeekVol1->Text = L"VOL1:";
			// 
			// labelWeekVolDir1
			// 
			this->labelWeekVolDir1->AutoSize = true;
			this->labelWeekVolDir1->Location = System::Drawing::Point(79, 156);
			this->labelWeekVolDir1->Name = L"labelWeekVolDir1";
			this->labelWeekVolDir1->Size = System::Drawing::Size(85, 18);
			this->labelWeekVolDir1->TabIndex = 198;
			this->labelWeekVolDir1->Text = L"Direction1:";
			// 
			// listBoxWeekVolDir1
			// 
			this->listBoxWeekVolDir1->FormattingEnabled = true;
			this->listBoxWeekVolDir1->ItemHeight = 18;
			this->listBoxWeekVolDir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekVolDir1->Location = System::Drawing::Point(170, 154);
			this->listBoxWeekVolDir1->Name = L"listBoxWeekVolDir1";
			this->listBoxWeekVolDir1->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekVolDir1->TabIndex = 197;
			this->listBoxWeekVolDir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekVolDir1_SelectedIndexChanged);
			// 
			// labelWeekVol
			// 
			this->labelWeekVol->AutoSize = true;
			this->labelWeekVol->Location = System::Drawing::Point(26, 158);
			this->labelWeekVol->Name = L"labelWeekVol";
			this->labelWeekVol->Size = System::Drawing::Size(46, 18);
			this->labelWeekVol->TabIndex = 196;
			this->labelWeekVol->Text = L"VOL:";
			// 
			// textBoxWeekWr2
			// 
			this->textBoxWeekWr2->Location = System::Drawing::Point(557, 382);
			this->textBoxWeekWr2->Name = L"textBoxWeekWr2";
			this->textBoxWeekWr2->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekWr2->TabIndex = 195;
			this->textBoxWeekWr2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekWr2_TextChanged);
			// 
			// textBoxWeekWr1
			// 
			this->textBoxWeekWr1->Location = System::Drawing::Point(353, 387);
			this->textBoxWeekWr1->Name = L"textBoxWeekWr1";
			this->textBoxWeekWr1->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekWr1->TabIndex = 193;
			this->textBoxWeekWr1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekWr1_TextChanged);
			// 
			// labelWeekWr2
			// 
			this->labelWeekWr2->AutoSize = true;
			this->labelWeekWr2->Location = System::Drawing::Point(483, 390);
			this->labelWeekWr2->Name = L"labelWeekWr2";
			this->labelWeekWr2->Size = System::Drawing::Size(48, 18);
			this->labelWeekWr2->TabIndex = 194;
			this->labelWeekWr2->Text = L"WR2:";
			// 
			// labelWeekWr1
			// 
			this->labelWeekWr1->AutoSize = true;
			this->labelWeekWr1->Location = System::Drawing::Point(286, 394);
			this->labelWeekWr1->Name = L"labelWeekWr1";
			this->labelWeekWr1->Size = System::Drawing::Size(47, 18);
			this->labelWeekWr1->TabIndex = 192;
			this->labelWeekWr1->Text = L"WR1:";
			// 
			// labelWeekWrDir
			// 
			this->labelWeekWrDir->AutoSize = true;
			this->labelWeekWrDir->Location = System::Drawing::Point(87, 394);
			this->labelWeekWrDir->Name = L"labelWeekWrDir";
			this->labelWeekWrDir->Size = System::Drawing::Size(77, 18);
			this->labelWeekWrDir->TabIndex = 191;
			this->labelWeekWrDir->Text = L"Direction:";
			// 
			// listBoxWeekWrDir
			// 
			this->listBoxWeekWrDir->FormattingEnabled = true;
			this->listBoxWeekWrDir->ItemHeight = 18;
			this->listBoxWeekWrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekWrDir->Location = System::Drawing::Point(170, 390);
			this->listBoxWeekWrDir->Name = L"listBoxWeekWrDir";
			this->listBoxWeekWrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekWrDir->TabIndex = 190;
			this->listBoxWeekWrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekWrDir_SelectedIndexChanged);
			// 
			// labelWeekWr
			// 
			this->labelWeekWr->AutoSize = true;
			this->labelWeekWr->Location = System::Drawing::Point(26, 394);
			this->labelWeekWr->Name = L"labelWeekWr";
			this->labelWeekWr->Size = System::Drawing::Size(39, 18);
			this->labelWeekWr->TabIndex = 189;
			this->labelWeekWr->Text = L"WR:";
			// 
			// textBoxWeekRsiLong
			// 
			this->textBoxWeekRsiLong->Location = System::Drawing::Point(759, 335);
			this->textBoxWeekRsiLong->Name = L"textBoxWeekRsiLong";
			this->textBoxWeekRsiLong->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekRsiLong->TabIndex = 188;
			this->textBoxWeekRsiLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekRsiLong_TextChanged);
			// 
			// textBoxWeekRsiMiddle
			// 
			this->textBoxWeekRsiMiddle->Location = System::Drawing::Point(557, 335);
			this->textBoxWeekRsiMiddle->Name = L"textBoxWeekRsiMiddle";
			this->textBoxWeekRsiMiddle->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekRsiMiddle->TabIndex = 186;
			this->textBoxWeekRsiMiddle->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekRsiMiddle_TextChanged);
			// 
			// textBoxWeekRsiShort
			// 
			this->textBoxWeekRsiShort->Location = System::Drawing::Point(353, 340);
			this->textBoxWeekRsiShort->Name = L"textBoxWeekRsiShort";
			this->textBoxWeekRsiShort->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekRsiShort->TabIndex = 184;
			this->textBoxWeekRsiShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekRsiShort_TextChanged);
			// 
			// labelWeekRsiLong
			// 
			this->labelWeekRsiLong->AutoSize = true;
			this->labelWeekRsiLong->Location = System::Drawing::Point(695, 340);
			this->labelWeekRsiLong->Name = L"labelWeekRsiLong";
			this->labelWeekRsiLong->Size = System::Drawing::Size(48, 18);
			this->labelWeekRsiLong->TabIndex = 187;
			this->labelWeekRsiLong->Text = L"Long:";
			// 
			// labelWeekRsiMiddle
			// 
			this->labelWeekRsiMiddle->AutoSize = true;
			this->labelWeekRsiMiddle->Location = System::Drawing::Point(483, 343);
			this->labelWeekRsiMiddle->Name = L"labelWeekRsiMiddle";
			this->labelWeekRsiMiddle->Size = System::Drawing::Size(62, 18);
			this->labelWeekRsiMiddle->TabIndex = 185;
			this->labelWeekRsiMiddle->Text = L"Middle:";
			// 
			// labelWeekRsiShort
			// 
			this->labelWeekRsiShort->AutoSize = true;
			this->labelWeekRsiShort->Location = System::Drawing::Point(286, 347);
			this->labelWeekRsiShort->Name = L"labelWeekRsiShort";
			this->labelWeekRsiShort->Size = System::Drawing::Size(52, 18);
			this->labelWeekRsiShort->TabIndex = 183;
			this->labelWeekRsiShort->Text = L"Short:";
			// 
			// labelWeekRsiDir
			// 
			this->labelWeekRsiDir->AutoSize = true;
			this->labelWeekRsiDir->Location = System::Drawing::Point(87, 347);
			this->labelWeekRsiDir->Name = L"labelWeekRsiDir";
			this->labelWeekRsiDir->Size = System::Drawing::Size(77, 18);
			this->labelWeekRsiDir->TabIndex = 182;
			this->labelWeekRsiDir->Text = L"Direction:";
			// 
			// listBoxWeekRsiDir
			// 
			this->listBoxWeekRsiDir->FormattingEnabled = true;
			this->listBoxWeekRsiDir->ItemHeight = 18;
			this->listBoxWeekRsiDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekRsiDir->Location = System::Drawing::Point(170, 343);
			this->listBoxWeekRsiDir->Name = L"listBoxWeekRsiDir";
			this->listBoxWeekRsiDir->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekRsiDir->TabIndex = 181;
			this->listBoxWeekRsiDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekRsiDir_SelectedIndexChanged);
			// 
			// labelWeekRsi
			// 
			this->labelWeekRsi->AutoSize = true;
			this->labelWeekRsi->Location = System::Drawing::Point(26, 347);
			this->labelWeekRsi->Name = L"labelWeekRsi";
			this->labelWeekRsi->Size = System::Drawing::Size(40, 18);
			this->labelWeekRsi->TabIndex = 180;
			this->labelWeekRsi->Text = L"RSI:";
			// 
			// textBoxWeekKdjJ
			// 
			this->textBoxWeekKdjJ->Location = System::Drawing::Point(759, 290);
			this->textBoxWeekKdjJ->Name = L"textBoxWeekKdjJ";
			this->textBoxWeekKdjJ->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekKdjJ->TabIndex = 179;
			this->textBoxWeekKdjJ->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekKdjJ_TextChanged);
			// 
			// textBoxWeekKdjD
			// 
			this->textBoxWeekKdjD->Location = System::Drawing::Point(557, 290);
			this->textBoxWeekKdjD->Name = L"textBoxWeekKdjD";
			this->textBoxWeekKdjD->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekKdjD->TabIndex = 177;
			this->textBoxWeekKdjD->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekKdjD_TextChanged);
			// 
			// textBoxWeekKdjK
			// 
			this->textBoxWeekKdjK->Location = System::Drawing::Point(353, 295);
			this->textBoxWeekKdjK->Name = L"textBoxWeekKdjK";
			this->textBoxWeekKdjK->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekKdjK->TabIndex = 175;
			this->textBoxWeekKdjK->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekKdjK_TextChanged);
			// 
			// labelWeekKdjJ
			// 
			this->labelWeekKdjJ->AutoSize = true;
			this->labelWeekKdjJ->Location = System::Drawing::Point(695, 298);
			this->labelWeekKdjJ->Name = L"labelWeekKdjJ";
			this->labelWeekKdjJ->Size = System::Drawing::Size(21, 18);
			this->labelWeekKdjJ->TabIndex = 178;
			this->labelWeekKdjJ->Text = L"J:";
			// 
			// labelWeekKdjD
			// 
			this->labelWeekKdjD->AutoSize = true;
			this->labelWeekKdjD->Location = System::Drawing::Point(500, 298);
			this->labelWeekKdjD->Name = L"labelWeekKdjD";
			this->labelWeekKdjD->Size = System::Drawing::Size(24, 18);
			this->labelWeekKdjD->TabIndex = 176;
			this->labelWeekKdjD->Text = L"D:";
			// 
			// labelWeekKdjK
			// 
			this->labelWeekKdjK->AutoSize = true;
			this->labelWeekKdjK->Location = System::Drawing::Point(290, 300);
			this->labelWeekKdjK->Name = L"labelWeekKdjK";
			this->labelWeekKdjK->Size = System::Drawing::Size(24, 18);
			this->labelWeekKdjK->TabIndex = 174;
			this->labelWeekKdjK->Text = L"K:";
			// 
			// labelWeekKdjDir
			// 
			this->labelWeekKdjDir->AutoSize = true;
			this->labelWeekKdjDir->Location = System::Drawing::Point(87, 302);
			this->labelWeekKdjDir->Name = L"labelWeekKdjDir";
			this->labelWeekKdjDir->Size = System::Drawing::Size(77, 18);
			this->labelWeekKdjDir->TabIndex = 173;
			this->labelWeekKdjDir->Text = L"Direction:";
			// 
			// listBoxWeekKdjDir
			// 
			this->listBoxWeekKdjDir->FormattingEnabled = true;
			this->listBoxWeekKdjDir->ItemHeight = 18;
			this->listBoxWeekKdjDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekKdjDir->Location = System::Drawing::Point(170, 298);
			this->listBoxWeekKdjDir->Name = L"listBoxWeekKdjDir";
			this->listBoxWeekKdjDir->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekKdjDir->TabIndex = 172;
			this->listBoxWeekKdjDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekKdjDir_SelectedIndexChanged);
			// 
			// labelWeekKdj
			// 
			this->labelWeekKdj->AutoSize = true;
			this->labelWeekKdj->Location = System::Drawing::Point(26, 302);
			this->labelWeekKdj->Name = L"labelWeekKdj";
			this->labelWeekKdj->Size = System::Drawing::Size(43, 18);
			this->labelWeekKdj->TabIndex = 171;
			this->labelWeekKdj->Text = L"KDJ:";
			// 
			// textBoxWeekMacdDea
			// 
			this->textBoxWeekMacdDea->Location = System::Drawing::Point(759, 243);
			this->textBoxWeekMacdDea->Name = L"textBoxWeekMacdDea";
			this->textBoxWeekMacdDea->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekMacdDea->TabIndex = 170;
			this->textBoxWeekMacdDea->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekMacdDea_TextChanged);
			// 
			// textBoxWeekMacdDif
			// 
			this->textBoxWeekMacdDif->Location = System::Drawing::Point(557, 243);
			this->textBoxWeekMacdDif->Name = L"textBoxWeekMacdDif";
			this->textBoxWeekMacdDif->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekMacdDif->TabIndex = 168;
			this->textBoxWeekMacdDif->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekMacdDif_TextChanged);
			// 
			// textBoxWeekMacdMacd
			// 
			this->textBoxWeekMacdMacd->Location = System::Drawing::Point(353, 248);
			this->textBoxWeekMacdMacd->Name = L"textBoxWeekMacdMacd";
			this->textBoxWeekMacdMacd->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekMacdMacd->TabIndex = 166;
			this->textBoxWeekMacdMacd->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekMacdMacd_TextChanged);
			// 
			// labelWeekMacdDea
			// 
			this->labelWeekMacdDea->AutoSize = true;
			this->labelWeekMacdDea->Location = System::Drawing::Point(695, 251);
			this->labelWeekMacdDea->Name = L"labelWeekMacdDea";
			this->labelWeekMacdDea->Size = System::Drawing::Size(40, 18);
			this->labelWeekMacdDea->TabIndex = 169;
			this->labelWeekMacdDea->Text = L"Dea:";
			// 
			// labelWeekMacdDif
			// 
			this->labelWeekMacdDif->AutoSize = true;
			this->labelWeekMacdDif->Location = System::Drawing::Point(500, 251);
			this->labelWeekMacdDif->Name = L"labelWeekMacdDif";
			this->labelWeekMacdDif->Size = System::Drawing::Size(33, 18);
			this->labelWeekMacdDif->TabIndex = 167;
			this->labelWeekMacdDif->Text = L"Dif:";
			// 
			// labelWeekMacdMacd
			// 
			this->labelWeekMacdMacd->AutoSize = true;
			this->labelWeekMacdMacd->Location = System::Drawing::Point(290, 253);
			this->labelWeekMacdMacd->Name = L"labelWeekMacdMacd";
			this->labelWeekMacdMacd->Size = System::Drawing::Size(52, 18);
			this->labelWeekMacdMacd->TabIndex = 165;
			this->labelWeekMacdMacd->Text = L"Macd:";
			// 
			// labelWeekMacdDir
			// 
			this->labelWeekMacdDir->AutoSize = true;
			this->labelWeekMacdDir->Location = System::Drawing::Point(87, 255);
			this->labelWeekMacdDir->Name = L"labelWeekMacdDir";
			this->labelWeekMacdDir->Size = System::Drawing::Size(77, 18);
			this->labelWeekMacdDir->TabIndex = 164;
			this->labelWeekMacdDir->Text = L"Direction:";
			// 
			// listBoxWeekMacdDir
			// 
			this->listBoxWeekMacdDir->FormattingEnabled = true;
			this->listBoxWeekMacdDir->ItemHeight = 18;
			this->listBoxWeekMacdDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekMacdDir->Location = System::Drawing::Point(170, 251);
			this->listBoxWeekMacdDir->Name = L"listBoxWeekMacdDir";
			this->listBoxWeekMacdDir->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekMacdDir->TabIndex = 163;
			this->listBoxWeekMacdDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekMacdDir_SelectedIndexChanged);
			// 
			// labelWeekMacd
			// 
			this->labelWeekMacd->AutoSize = true;
			this->labelWeekMacd->Location = System::Drawing::Point(26, 255);
			this->labelWeekMacd->Name = L"labelWeekMacd";
			this->labelWeekMacd->Size = System::Drawing::Size(60, 18);
			this->labelWeekMacd->TabIndex = 162;
			this->labelWeekMacd->Text = L"MACD:";
			// 
			// textBoxWeekBollUpper
			// 
			this->textBoxWeekBollUpper->Location = System::Drawing::Point(759, 196);
			this->textBoxWeekBollUpper->Name = L"textBoxWeekBollUpper";
			this->textBoxWeekBollUpper->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekBollUpper->TabIndex = 161;
			this->textBoxWeekBollUpper->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekBollUpper_TextChanged);
			// 
			// textBoxWeekBollMid
			// 
			this->textBoxWeekBollMid->Location = System::Drawing::Point(557, 198);
			this->textBoxWeekBollMid->Name = L"textBoxWeekBollMid";
			this->textBoxWeekBollMid->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekBollMid->TabIndex = 159;
			this->textBoxWeekBollMid->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekBollMid_TextChanged);
			// 
			// textBoxWeekBollLow
			// 
			this->textBoxWeekBollLow->Location = System::Drawing::Point(353, 200);
			this->textBoxWeekBollLow->Name = L"textBoxWeekBollLow";
			this->textBoxWeekBollLow->Size = System::Drawing::Size(124, 26);
			this->textBoxWeekBollLow->TabIndex = 157;
			this->textBoxWeekBollLow->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxWeekBollLow_TextChanged);
			// 
			// labelWeekBollUpper
			// 
			this->labelWeekBollUpper->AutoSize = true;
			this->labelWeekBollUpper->Location = System::Drawing::Point(695, 202);
			this->labelWeekBollUpper->Name = L"labelWeekBollUpper";
			this->labelWeekBollUpper->Size = System::Drawing::Size(58, 18);
			this->labelWeekBollUpper->TabIndex = 160;
			this->labelWeekBollUpper->Text = L"Upper:";
			// 
			// labelWeekBollMid
			// 
			this->labelWeekBollMid->AutoSize = true;
			this->labelWeekBollMid->Location = System::Drawing::Point(500, 204);
			this->labelWeekBollMid->Name = L"labelWeekBollMid";
			this->labelWeekBollMid->Size = System::Drawing::Size(41, 18);
			this->labelWeekBollMid->TabIndex = 158;
			this->labelWeekBollMid->Text = L"Mid:";
			// 
			// labelWeekBollLow
			// 
			this->labelWeekBollLow->AutoSize = true;
			this->labelWeekBollLow->Location = System::Drawing::Point(295, 206);
			this->labelWeekBollLow->Name = L"labelWeekBollLow";
			this->labelWeekBollLow->Size = System::Drawing::Size(43, 18);
			this->labelWeekBollLow->TabIndex = 156;
			this->labelWeekBollLow->Text = L"Low:";
			// 
			// labelWeekBollDir
			// 
			this->labelWeekBollDir->AutoSize = true;
			this->labelWeekBollDir->Location = System::Drawing::Point(87, 206);
			this->labelWeekBollDir->Name = L"labelWeekBollDir";
			this->labelWeekBollDir->Size = System::Drawing::Size(77, 18);
			this->labelWeekBollDir->TabIndex = 155;
			this->labelWeekBollDir->Text = L"Direction:";
			// 
			// listBoxWeekBollDir
			// 
			this->listBoxWeekBollDir->FormattingEnabled = true;
			this->listBoxWeekBollDir->ItemHeight = 18;
			this->listBoxWeekBollDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxWeekBollDir->Location = System::Drawing::Point(170, 204);
			this->listBoxWeekBollDir->Name = L"listBoxWeekBollDir";
			this->listBoxWeekBollDir->Size = System::Drawing::Size(97, 22);
			this->listBoxWeekBollDir->TabIndex = 154;
			this->listBoxWeekBollDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxWeekBollDir_SelectedIndexChanged);
			// 
			// labelWeekBoll
			// 
			this->labelWeekBoll->AutoSize = true;
			this->labelWeekBoll->Location = System::Drawing::Point(26, 210);
			this->labelWeekBoll->Name = L"labelWeekBoll";
			this->labelWeekBoll->Size = System::Drawing::Size(55, 18);
			this->labelWeekBoll->TabIndex = 153;
			this->labelWeekBoll->Text = L"BOLL:";
			// 
			// tabMonth
			// 
			this->tabMonth->BackColor = System::Drawing::Color::White;
			this->tabMonth->Controls->Add(this->listBoxMonthMADir6);
			this->tabMonth->Controls->Add(this->labelMonthMADir6);
			this->tabMonth->Controls->Add(this->textBoxMonthMA6);
			this->tabMonth->Controls->Add(this->textBoxMonthMA5);
			this->tabMonth->Controls->Add(this->labelMonthMA6);
			this->tabMonth->Controls->Add(this->labelMonthMA5);
			this->tabMonth->Controls->Add(this->labelMonthMADir5);
			this->tabMonth->Controls->Add(this->listBoxMonthMADir5);
			this->tabMonth->Controls->Add(this->labelMonthMA56);
			this->tabMonth->Controls->Add(this->labelMonthMADir4);
			this->tabMonth->Controls->Add(this->listBoxMonthMADir4);
			this->tabMonth->Controls->Add(this->textBoxMonthMA4);
			this->tabMonth->Controls->Add(this->textBoxMonthMA3);
			this->tabMonth->Controls->Add(this->labelMonthMA4);
			this->tabMonth->Controls->Add(this->labelMonthMA3);
			this->tabMonth->Controls->Add(this->labelMonthMADir3);
			this->tabMonth->Controls->Add(this->listBoxMonthMADir3);
			this->tabMonth->Controls->Add(this->labelMonthMA34);
			this->tabMonth->Controls->Add(this->labelMonthMADir2);
			this->tabMonth->Controls->Add(this->listBoxMonthMADir2);
			this->tabMonth->Controls->Add(this->textBoxMonthMA2);
			this->tabMonth->Controls->Add(this->textBoxMonthMA1);
			this->tabMonth->Controls->Add(this->labelMonthMA2);
			this->tabMonth->Controls->Add(this->labelMonthMA1);
			this->tabMonth->Controls->Add(this->labelMonthMADir1);
			this->tabMonth->Controls->Add(this->listBoxMonthMADir1);
			this->tabMonth->Controls->Add(this->labelMonthMA12);
			this->tabMonth->Controls->Add(this->textBoxMonthCciCci);
			this->tabMonth->Controls->Add(this->labelMonthCciCci);
			this->tabMonth->Controls->Add(this->labelMonthCciDir);
			this->tabMonth->Controls->Add(this->listBoxMonthCciDir);
			this->tabMonth->Controls->Add(this->labelMonthCci);
			this->tabMonth->Controls->Add(this->textBoxMonthCrC);
			this->tabMonth->Controls->Add(this->labelMonthCrC);
			this->tabMonth->Controls->Add(this->textBoxMonthCrB);
			this->tabMonth->Controls->Add(this->labelMonthCrB);
			this->tabMonth->Controls->Add(this->textBoxMonthCrA);
			this->tabMonth->Controls->Add(this->textBoxMonthCrCr);
			this->tabMonth->Controls->Add(this->labelMonthCrA);
			this->tabMonth->Controls->Add(this->labelMonthCrCr);
			this->tabMonth->Controls->Add(this->labelMonthCrDir);
			this->tabMonth->Controls->Add(this->listBoxMonthCrDir);
			this->tabMonth->Controls->Add(this->labelMonthCr);
			this->tabMonth->Controls->Add(this->textBoxMonthDmaAma);
			this->tabMonth->Controls->Add(this->textBoxMonthDmaDma);
			this->tabMonth->Controls->Add(this->labelMonthDmaAma);
			this->tabMonth->Controls->Add(this->labelMonthDmaDma);
			this->tabMonth->Controls->Add(this->labelMonthDmaDir);
			this->tabMonth->Controls->Add(this->listBoxMonthDmaDir);
			this->tabMonth->Controls->Add(this->labelMonthDma);
			this->tabMonth->Controls->Add(this->textBoxMonthRocRocma);
			this->tabMonth->Controls->Add(this->textBoxMonthRocRoc);
			this->tabMonth->Controls->Add(this->labelMonthRocRocma);
			this->tabMonth->Controls->Add(this->labelMonthRocRoc);
			this->tabMonth->Controls->Add(this->labelMonthRocDir);
			this->tabMonth->Controls->Add(this->listBoxMonthRocDir);
			this->tabMonth->Controls->Add(this->labelMonthRoc);
			this->tabMonth->Controls->Add(this->textBoxMonthVrLong);
			this->tabMonth->Controls->Add(this->textBoxMonthVrShort);
			this->tabMonth->Controls->Add(this->labelMonthVrLong);
			this->tabMonth->Controls->Add(this->labelMonthVrShort);
			this->tabMonth->Controls->Add(this->labelMonthVrDir);
			this->tabMonth->Controls->Add(this->listBoxMonthVrDir);
			this->tabMonth->Controls->Add(this->labelMonthVr);
			this->tabMonth->Controls->Add(this->labelMonthVolDir2);
			this->tabMonth->Controls->Add(this->listBoxMonthVolDir2);
			this->tabMonth->Controls->Add(this->textBoxMonthVol2);
			this->tabMonth->Controls->Add(this->textBoxMonthVol1);
			this->tabMonth->Controls->Add(this->labelMonthVol2);
			this->tabMonth->Controls->Add(this->labelMonthVol1);
			this->tabMonth->Controls->Add(this->labelMonthVolDir1);
			this->tabMonth->Controls->Add(this->listBoxMonthVolDir1);
			this->tabMonth->Controls->Add(this->labelMonthVol);
			this->tabMonth->Controls->Add(this->textBoxMonthWr2);
			this->tabMonth->Controls->Add(this->textBoxMonthWr1);
			this->tabMonth->Controls->Add(this->labelMonthWr2);
			this->tabMonth->Controls->Add(this->labelMonthWr1);
			this->tabMonth->Controls->Add(this->labelMonthWrDir);
			this->tabMonth->Controls->Add(this->listBoxMonthWrDir);
			this->tabMonth->Controls->Add(this->labelMonthWr);
			this->tabMonth->Controls->Add(this->textBoxMonthRsiLong);
			this->tabMonth->Controls->Add(this->textBoxMonthRsiMiddle);
			this->tabMonth->Controls->Add(this->textBoxMonthRsiShort);
			this->tabMonth->Controls->Add(this->labelMonthRsiLong);
			this->tabMonth->Controls->Add(this->labelMonthRsiMiddle);
			this->tabMonth->Controls->Add(this->labelMonthRsiShort);
			this->tabMonth->Controls->Add(this->labelMonthRsiDir);
			this->tabMonth->Controls->Add(this->listBoxMonthRsiDir);
			this->tabMonth->Controls->Add(this->labelMonthRsi);
			this->tabMonth->Controls->Add(this->textBoxMonthKdjJ);
			this->tabMonth->Controls->Add(this->textBoxMonthKdjD);
			this->tabMonth->Controls->Add(this->textBoxMonthKdjK);
			this->tabMonth->Controls->Add(this->labelMonthKdjJ);
			this->tabMonth->Controls->Add(this->labelMonthKdjD);
			this->tabMonth->Controls->Add(this->labelMonthKdjK);
			this->tabMonth->Controls->Add(this->labelMonthKdjDir);
			this->tabMonth->Controls->Add(this->listBoxMonthKdjDir);
			this->tabMonth->Controls->Add(this->labelMonthKdj);
			this->tabMonth->Controls->Add(this->textBoxMonthMacdDea);
			this->tabMonth->Controls->Add(this->textBoxMonthMacdDif);
			this->tabMonth->Controls->Add(this->textBoxMonthMacdMacd);
			this->tabMonth->Controls->Add(this->labelMonthMacdDea);
			this->tabMonth->Controls->Add(this->labelMonthMacdDif);
			this->tabMonth->Controls->Add(this->labelMonthMacdMacd);
			this->tabMonth->Controls->Add(this->labelMonthMacdDir);
			this->tabMonth->Controls->Add(this->listBoxMonthMacdDir);
			this->tabMonth->Controls->Add(this->labelMonthMacd);
			this->tabMonth->Controls->Add(this->textBoxMonthBollUpper);
			this->tabMonth->Controls->Add(this->textBoxMonthBollMid);
			this->tabMonth->Controls->Add(this->textBoxMonthBollLow);
			this->tabMonth->Controls->Add(this->labelMonthBollUpper);
			this->tabMonth->Controls->Add(this->labelMonthBollMid);
			this->tabMonth->Controls->Add(this->labelMonthBollLow);
			this->tabMonth->Controls->Add(this->labelMonthBollDir);
			this->tabMonth->Controls->Add(this->listBoxMonthBollDir);
			this->tabMonth->Controls->Add(this->labelMonthBoll);
			this->tabMonth->Location = System::Drawing::Point(4, 27);
			this->tabMonth->Name = L"tabMonth";
			this->tabMonth->Padding = System::Windows::Forms::Padding(3);
			this->tabMonth->Size = System::Drawing::Size(1092, 869);
			this->tabMonth->TabIndex = 1;
			this->tabMonth->Text = L"Month";
			// 
			// listBoxMonthMADir6
			// 
			this->listBoxMonthMADir6->FormattingEnabled = true;
			this->listBoxMonthMADir6->ItemHeight = 18;
			this->listBoxMonthMADir6->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthMADir6->Location = System::Drawing::Point(575, 103);
			this->listBoxMonthMADir6->Name = L"listBoxMonthMADir6";
			this->listBoxMonthMADir6->Size = System::Drawing::Size(106, 22);
			this->listBoxMonthMADir6->TabIndex = 269;
			this->listBoxMonthMADir6->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthMADir6_SelectedIndexChanged);
			// 
			// labelMonthMADir6
			// 
			this->labelMonthMADir6->AutoSize = true;
			this->labelMonthMADir6->Location = System::Drawing::Point(483, 107);
			this->labelMonthMADir6->Name = L"labelMonthMADir6";
			this->labelMonthMADir6->Size = System::Drawing::Size(80, 18);
			this->labelMonthMADir6->TabIndex = 268;
			this->labelMonthMADir6->Text = L"MA_Dir6:";
			// 
			// textBoxMonthMA6
			// 
			this->textBoxMonthMA6->Location = System::Drawing::Point(759, 99);
			this->textBoxMonthMA6->Name = L"textBoxMonthMA6";
			this->textBoxMonthMA6->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthMA6->TabIndex = 266;
			this->textBoxMonthMA6->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthMA6_TextChanged);
			// 
			// textBoxMonthMA5
			// 
			this->textBoxMonthMA5->Location = System::Drawing::Point(353, 104);
			this->textBoxMonthMA5->Name = L"textBoxMonthMA5";
			this->textBoxMonthMA5->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthMA5->TabIndex = 264;
			this->textBoxMonthMA5->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthMA5_TextChanged);
			// 
			// labelMonthMA6
			// 
			this->labelMonthMA6->AutoSize = true;
			this->labelMonthMA6->Location = System::Drawing::Point(695, 107);
			this->labelMonthMA6->Name = L"labelMonthMA6";
			this->labelMonthMA6->Size = System::Drawing::Size(48, 18);
			this->labelMonthMA6->TabIndex = 265;
			this->labelMonthMA6->Text = L"MA6:";
			// 
			// labelMonthMA5
			// 
			this->labelMonthMA5->AutoSize = true;
			this->labelMonthMA5->Location = System::Drawing::Point(290, 109);
			this->labelMonthMA5->Name = L"labelMonthMA5";
			this->labelMonthMA5->Size = System::Drawing::Size(48, 18);
			this->labelMonthMA5->TabIndex = 263;
			this->labelMonthMA5->Text = L"MA5:";
			// 
			// labelMonthMADir5
			// 
			this->labelMonthMADir5->AutoSize = true;
			this->labelMonthMADir5->Location = System::Drawing::Point(79, 112);
			this->labelMonthMADir5->Name = L"labelMonthMADir5";
			this->labelMonthMADir5->Size = System::Drawing::Size(80, 18);
			this->labelMonthMADir5->TabIndex = 262;
			this->labelMonthMADir5->Text = L"MA_Dir5:";
			// 
			// listBoxMonthMADir5
			// 
			this->listBoxMonthMADir5->FormattingEnabled = true;
			this->listBoxMonthMADir5->ItemHeight = 18;
			this->listBoxMonthMADir5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthMADir5->Location = System::Drawing::Point(170, 107);
			this->listBoxMonthMADir5->Name = L"listBoxMonthMADir5";
			this->listBoxMonthMADir5->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthMADir5->TabIndex = 261;
			this->listBoxMonthMADir5->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthMADir5_SelectedIndexChanged);
			// 
			// labelMonthMA56
			// 
			this->labelMonthMA56->AutoSize = true;
			this->labelMonthMA56->Location = System::Drawing::Point(17, 112);
			this->labelMonthMA56->Name = L"labelMonthMA56";
			this->labelMonthMA56->Size = System::Drawing::Size(64, 18);
			this->labelMonthMA56->TabIndex = 260;
			this->labelMonthMA56->Text = L"MA5-6:";
			// 
			// labelMonthMADir4
			// 
			this->labelMonthMADir4->AutoSize = true;
			this->labelMonthMADir4->Location = System::Drawing::Point(483, 60);
			this->labelMonthMADir4->Name = L"labelMonthMADir4";
			this->labelMonthMADir4->Size = System::Drawing::Size(80, 18);
			this->labelMonthMADir4->TabIndex = 259;
			this->labelMonthMADir4->Text = L"MA_Dir4:";
			// 
			// listBoxMonthMADir4
			// 
			this->listBoxMonthMADir4->FormattingEnabled = true;
			this->listBoxMonthMADir4->ItemHeight = 18;
			this->listBoxMonthMADir4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthMADir4->Location = System::Drawing::Point(575, 57);
			this->listBoxMonthMADir4->Name = L"listBoxMonthMADir4";
			this->listBoxMonthMADir4->Size = System::Drawing::Size(106, 22);
			this->listBoxMonthMADir4->TabIndex = 258;
			this->listBoxMonthMADir4->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthMADir4_SelectedIndexChanged);
			// 
			// textBoxMonthMA4
			// 
			this->textBoxMonthMA4->Location = System::Drawing::Point(759, 52);
			this->textBoxMonthMA4->Name = L"textBoxMonthMA4";
			this->textBoxMonthMA4->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthMA4->TabIndex = 257;
			this->textBoxMonthMA4->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthMA4_TextChanged);
			// 
			// textBoxMonthMA3
			// 
			this->textBoxMonthMA3->Location = System::Drawing::Point(353, 57);
			this->textBoxMonthMA3->Name = L"textBoxMonthMA3";
			this->textBoxMonthMA3->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthMA3->TabIndex = 255;
			this->textBoxMonthMA3->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthMA3_TextChanged);
			// 
			// labelMonthMA4
			// 
			this->labelMonthMA4->AutoSize = true;
			this->labelMonthMA4->Location = System::Drawing::Point(695, 60);
			this->labelMonthMA4->Name = L"labelMonthMA4";
			this->labelMonthMA4->Size = System::Drawing::Size(48, 18);
			this->labelMonthMA4->TabIndex = 256;
			this->labelMonthMA4->Text = L"MA4:";
			// 
			// labelMonthMA3
			// 
			this->labelMonthMA3->AutoSize = true;
			this->labelMonthMA3->Location = System::Drawing::Point(290, 62);
			this->labelMonthMA3->Name = L"labelMonthMA3";
			this->labelMonthMA3->Size = System::Drawing::Size(48, 18);
			this->labelMonthMA3->TabIndex = 254;
			this->labelMonthMA3->Text = L"MA3:";
			// 
			// labelMonthMADir3
			// 
			this->labelMonthMADir3->AutoSize = true;
			this->labelMonthMADir3->Location = System::Drawing::Point(79, 65);
			this->labelMonthMADir3->Name = L"labelMonthMADir3";
			this->labelMonthMADir3->Size = System::Drawing::Size(80, 18);
			this->labelMonthMADir3->TabIndex = 253;
			this->labelMonthMADir3->Text = L"MA_Dir3:";
			// 
			// listBoxMonthMADir3
			// 
			this->listBoxMonthMADir3->FormattingEnabled = true;
			this->listBoxMonthMADir3->ItemHeight = 18;
			this->listBoxMonthMADir3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthMADir3->Location = System::Drawing::Point(170, 60);
			this->listBoxMonthMADir3->Name = L"listBoxMonthMADir3";
			this->listBoxMonthMADir3->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthMADir3->TabIndex = 252;
			this->listBoxMonthMADir3->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthMADir3_SelectedIndexChanged);
			// 
			// labelMonthMA34
			// 
			this->labelMonthMA34->AutoSize = true;
			this->labelMonthMA34->Location = System::Drawing::Point(17, 65);
			this->labelMonthMA34->Name = L"labelMonthMA34";
			this->labelMonthMA34->Size = System::Drawing::Size(64, 18);
			this->labelMonthMA34->TabIndex = 251;
			this->labelMonthMA34->Text = L"MA3-4:";
			// 
			// labelMonthMADir2
			// 
			this->labelMonthMADir2->AutoSize = true;
			this->labelMonthMADir2->Location = System::Drawing::Point(483, 19);
			this->labelMonthMADir2->Name = L"labelMonthMADir2";
			this->labelMonthMADir2->Size = System::Drawing::Size(80, 18);
			this->labelMonthMADir2->TabIndex = 250;
			this->labelMonthMADir2->Text = L"MA_Dir2:";
			// 
			// listBoxMonthMADir2
			// 
			this->listBoxMonthMADir2->FormattingEnabled = true;
			this->listBoxMonthMADir2->ItemHeight = 18;
			this->listBoxMonthMADir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthMADir2->Location = System::Drawing::Point(575, 16);
			this->listBoxMonthMADir2->Name = L"listBoxMonthMADir2";
			this->listBoxMonthMADir2->Size = System::Drawing::Size(106, 22);
			this->listBoxMonthMADir2->TabIndex = 249;
			this->listBoxMonthMADir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthMADir2_SelectedIndexChanged);
			// 
			// textBoxMonthMA2
			// 
			this->textBoxMonthMA2->Location = System::Drawing::Point(759, 11);
			this->textBoxMonthMA2->Name = L"textBoxMonthMA2";
			this->textBoxMonthMA2->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthMA2->TabIndex = 248;
			this->textBoxMonthMA2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthMA2_TextChanged);
			// 
			// textBoxMonthMA1
			// 
			this->textBoxMonthMA1->Location = System::Drawing::Point(353, 16);
			this->textBoxMonthMA1->Name = L"textBoxMonthMA1";
			this->textBoxMonthMA1->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthMA1->TabIndex = 246;
			this->textBoxMonthMA1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthMA1_TextChanged);
			// 
			// labelMonthMA2
			// 
			this->labelMonthMA2->AutoSize = true;
			this->labelMonthMA2->Location = System::Drawing::Point(695, 19);
			this->labelMonthMA2->Name = L"labelMonthMA2";
			this->labelMonthMA2->Size = System::Drawing::Size(48, 18);
			this->labelMonthMA2->TabIndex = 247;
			this->labelMonthMA2->Text = L"MA2:";
			// 
			// labelMonthMA1
			// 
			this->labelMonthMA1->AutoSize = true;
			this->labelMonthMA1->Location = System::Drawing::Point(290, 21);
			this->labelMonthMA1->Name = L"labelMonthMA1";
			this->labelMonthMA1->Size = System::Drawing::Size(47, 18);
			this->labelMonthMA1->TabIndex = 245;
			this->labelMonthMA1->Text = L"MA1:";
			// 
			// labelMonthMADir1
			// 
			this->labelMonthMADir1->AutoSize = true;
			this->labelMonthMADir1->Location = System::Drawing::Point(79, 21);
			this->labelMonthMADir1->Name = L"labelMonthMADir1";
			this->labelMonthMADir1->Size = System::Drawing::Size(79, 18);
			this->labelMonthMADir1->TabIndex = 244;
			this->labelMonthMADir1->Text = L"MA_Dir1:";
			// 
			// listBoxMonthMADir1
			// 
			this->listBoxMonthMADir1->FormattingEnabled = true;
			this->listBoxMonthMADir1->ItemHeight = 18;
			this->listBoxMonthMADir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthMADir1->Location = System::Drawing::Point(170, 19);
			this->listBoxMonthMADir1->Name = L"listBoxMonthMADir1";
			this->listBoxMonthMADir1->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthMADir1->TabIndex = 243;
			this->listBoxMonthMADir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxlMonthMA12Dir_SelectedIndexChanged);
			// 
			// labelMonthMA12
			// 
			this->labelMonthMA12->AutoSize = true;
			this->labelMonthMA12->Location = System::Drawing::Point(16, 24);
			this->labelMonthMA12->Name = L"labelMonthMA12";
			this->labelMonthMA12->Size = System::Drawing::Size(63, 18);
			this->labelMonthMA12->TabIndex = 242;
			this->labelMonthMA12->Text = L"MA1-2:";
			// 
			// textBoxMonthCciCci
			// 
			this->textBoxMonthCciCci->Location = System::Drawing::Point(353, 601);
			this->textBoxMonthCciCci->Name = L"textBoxMonthCciCci";
			this->textBoxMonthCciCci->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthCciCci->TabIndex = 241;
			this->textBoxMonthCciCci->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthCciCci_TextChanged);
			// 
			// labelMonthCciCci
			// 
			this->labelMonthCciCci->AutoSize = true;
			this->labelMonthCciCci->Location = System::Drawing::Point(286, 608);
			this->labelMonthCciCci->Name = L"labelMonthCciCci";
			this->labelMonthCciCci->Size = System::Drawing::Size(34, 18);
			this->labelMonthCciCci->TabIndex = 240;
			this->labelMonthCciCci->Text = L"Cci:";
			// 
			// labelMonthCciDir
			// 
			this->labelMonthCciDir->AutoSize = true;
			this->labelMonthCciDir->Location = System::Drawing::Point(87, 608);
			this->labelMonthCciDir->Name = L"labelMonthCciDir";
			this->labelMonthCciDir->Size = System::Drawing::Size(77, 18);
			this->labelMonthCciDir->TabIndex = 239;
			this->labelMonthCciDir->Text = L"Direction:";
			// 
			// listBoxMonthCciDir
			// 
			this->listBoxMonthCciDir->FormattingEnabled = true;
			this->listBoxMonthCciDir->ItemHeight = 18;
			this->listBoxMonthCciDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthCciDir->Location = System::Drawing::Point(170, 604);
			this->listBoxMonthCciDir->Name = L"listBoxMonthCciDir";
			this->listBoxMonthCciDir->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthCciDir->TabIndex = 238;
			this->listBoxMonthCciDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthCciDir_SelectedIndexChanged);
			// 
			// labelMonthCci
			// 
			this->labelMonthCci->AutoSize = true;
			this->labelMonthCci->Location = System::Drawing::Point(26, 608);
			this->labelMonthCci->Name = L"labelMonthCci";
			this->labelMonthCci->Size = System::Drawing::Size(40, 18);
			this->labelMonthCci->TabIndex = 237;
			this->labelMonthCci->Text = L"CCI:";
			// 
			// textBoxMonthCrC
			// 
			this->textBoxMonthCrC->Location = System::Drawing::Point(961, 555);
			this->textBoxMonthCrC->Name = L"textBoxMonthCrC";
			this->textBoxMonthCrC->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthCrC->TabIndex = 236;
			this->textBoxMonthCrC->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthCrC_TextChanged);
			// 
			// labelMonthCrC
			// 
			this->labelMonthCrC->AutoSize = true;
			this->labelMonthCrC->Location = System::Drawing::Point(900, 563);
			this->labelMonthCrC->Name = L"labelMonthCrC";
			this->labelMonthCrC->Size = System::Drawing::Size(23, 18);
			this->labelMonthCrC->TabIndex = 235;
			this->labelMonthCrC->Text = L"C:";
			// 
			// textBoxMonthCrB
			// 
			this->textBoxMonthCrB->Location = System::Drawing::Point(755, 555);
			this->textBoxMonthCrB->Name = L"textBoxMonthCrB";
			this->textBoxMonthCrB->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthCrB->TabIndex = 234;
			this->textBoxMonthCrB->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthCrB_TextChanged);
			// 
			// labelMonthCrB
			// 
			this->labelMonthCrB->AutoSize = true;
			this->labelMonthCrB->Location = System::Drawing::Point(694, 563);
			this->labelMonthCrB->Name = L"labelMonthCrB";
			this->labelMonthCrB->Size = System::Drawing::Size(23, 18);
			this->labelMonthCrB->TabIndex = 233;
			this->labelMonthCrB->Text = L"B:";
			// 
			// textBoxMonthCrA
			// 
			this->textBoxMonthCrA->Location = System::Drawing::Point(557, 555);
			this->textBoxMonthCrA->Name = L"textBoxMonthCrA";
			this->textBoxMonthCrA->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthCrA->TabIndex = 232;
			this->textBoxMonthCrA->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthCrA_TextChanged);
			// 
			// textBoxMonthCrCr
			// 
			this->textBoxMonthCrCr->Location = System::Drawing::Point(353, 560);
			this->textBoxMonthCrCr->Name = L"textBoxMonthCrCr";
			this->textBoxMonthCrCr->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthCrCr->TabIndex = 230;
			this->textBoxMonthCrCr->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthCrCr_TextChanged);
			// 
			// labelMonthCrA
			// 
			this->labelMonthCrA->AutoSize = true;
			this->labelMonthCrA->Location = System::Drawing::Point(496, 563);
			this->labelMonthCrA->Name = L"labelMonthCrA";
			this->labelMonthCrA->Size = System::Drawing::Size(24, 18);
			this->labelMonthCrA->TabIndex = 231;
			this->labelMonthCrA->Text = L"A:";
			// 
			// labelMonthCrCr
			// 
			this->labelMonthCrCr->AutoSize = true;
			this->labelMonthCrCr->Location = System::Drawing::Point(286, 567);
			this->labelMonthCrCr->Name = L"labelMonthCrCr";
			this->labelMonthCrCr->Size = System::Drawing::Size(30, 18);
			this->labelMonthCrCr->TabIndex = 229;
			this->labelMonthCrCr->Text = L"Cr:";
			// 
			// labelMonthCrDir
			// 
			this->labelMonthCrDir->AutoSize = true;
			this->labelMonthCrDir->Location = System::Drawing::Point(87, 567);
			this->labelMonthCrDir->Name = L"labelMonthCrDir";
			this->labelMonthCrDir->Size = System::Drawing::Size(77, 18);
			this->labelMonthCrDir->TabIndex = 228;
			this->labelMonthCrDir->Text = L"Direction:";
			// 
			// listBoxMonthCrDir
			// 
			this->listBoxMonthCrDir->FormattingEnabled = true;
			this->listBoxMonthCrDir->ItemHeight = 18;
			this->listBoxMonthCrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthCrDir->Location = System::Drawing::Point(170, 563);
			this->listBoxMonthCrDir->Name = L"listBoxMonthCrDir";
			this->listBoxMonthCrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthCrDir->TabIndex = 227;
			this->listBoxMonthCrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthCrDir_SelectedIndexChanged);
			// 
			// labelMonthCr
			// 
			this->labelMonthCr->AutoSize = true;
			this->labelMonthCr->Location = System::Drawing::Point(26, 567);
			this->labelMonthCr->Name = L"labelMonthCr";
			this->labelMonthCr->Size = System::Drawing::Size(34, 18);
			this->labelMonthCr->TabIndex = 226;
			this->labelMonthCr->Text = L"CR:";
			// 
			// textBoxMonthDmaAma
			// 
			this->textBoxMonthDmaAma->Location = System::Drawing::Point(557, 513);
			this->textBoxMonthDmaAma->Name = L"textBoxMonthDmaAma";
			this->textBoxMonthDmaAma->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthDmaAma->TabIndex = 225;
			this->textBoxMonthDmaAma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthDmaAma_TextChanged);
			// 
			// textBoxMonthDmaDma
			// 
			this->textBoxMonthDmaDma->Location = System::Drawing::Point(353, 518);
			this->textBoxMonthDmaDma->Name = L"textBoxMonthDmaDma";
			this->textBoxMonthDmaDma->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthDmaDma->TabIndex = 223;
			this->textBoxMonthDmaDma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthDmaDma_TextChanged);
			// 
			// labelMonthDmaAma
			// 
			this->labelMonthDmaAma->AutoSize = true;
			this->labelMonthDmaAma->Location = System::Drawing::Point(483, 521);
			this->labelMonthDmaAma->Name = L"labelMonthDmaAma";
			this->labelMonthDmaAma->Size = System::Drawing::Size(46, 18);
			this->labelMonthDmaAma->TabIndex = 224;
			this->labelMonthDmaAma->Text = L"Ama:";
			// 
			// labelMonthDmaDma
			// 
			this->labelMonthDmaDma->AutoSize = true;
			this->labelMonthDmaDma->Location = System::Drawing::Point(286, 525);
			this->labelMonthDmaDma->Name = L"labelMonthDmaDma";
			this->labelMonthDmaDma->Size = System::Drawing::Size(46, 18);
			this->labelMonthDmaDma->TabIndex = 222;
			this->labelMonthDmaDma->Text = L"Dma:";
			// 
			// labelMonthDmaDir
			// 
			this->labelMonthDmaDir->AutoSize = true;
			this->labelMonthDmaDir->Location = System::Drawing::Point(87, 525);
			this->labelMonthDmaDir->Name = L"labelMonthDmaDir";
			this->labelMonthDmaDir->Size = System::Drawing::Size(77, 18);
			this->labelMonthDmaDir->TabIndex = 221;
			this->labelMonthDmaDir->Text = L"Direction:";
			// 
			// listBoxMonthDmaDir
			// 
			this->listBoxMonthDmaDir->FormattingEnabled = true;
			this->listBoxMonthDmaDir->ItemHeight = 18;
			this->listBoxMonthDmaDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthDmaDir->Location = System::Drawing::Point(170, 521);
			this->listBoxMonthDmaDir->Name = L"listBoxMonthDmaDir";
			this->listBoxMonthDmaDir->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthDmaDir->TabIndex = 220;
			this->listBoxMonthDmaDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthDmaDir_SelectedIndexChanged);
			// 
			// labelMonthDma
			// 
			this->labelMonthDma->AutoSize = true;
			this->labelMonthDma->Location = System::Drawing::Point(26, 525);
			this->labelMonthDma->Name = L"labelMonthDma";
			this->labelMonthDma->Size = System::Drawing::Size(50, 18);
			this->labelMonthDma->TabIndex = 219;
			this->labelMonthDma->Text = L"DMA:";
			// 
			// textBoxMonthRocRocma
			// 
			this->textBoxMonthRocRocma->Location = System::Drawing::Point(557, 427);
			this->textBoxMonthRocRocma->Name = L"textBoxMonthRocRocma";
			this->textBoxMonthRocRocma->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthRocRocma->TabIndex = 218;
			this->textBoxMonthRocRocma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthRocRocma_TextChanged);
			// 
			// textBoxMonthRocRoc
			// 
			this->textBoxMonthRocRoc->Location = System::Drawing::Point(353, 432);
			this->textBoxMonthRocRoc->Name = L"textBoxMonthRocRoc";
			this->textBoxMonthRocRoc->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthRocRoc->TabIndex = 216;
			this->textBoxMonthRocRoc->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthRocRoc_TextChanged);
			// 
			// labelMonthRocRocma
			// 
			this->labelMonthRocRocma->AutoSize = true;
			this->labelMonthRocRocma->Location = System::Drawing::Point(483, 435);
			this->labelMonthRocRocma->Name = L"labelMonthRocRocma";
			this->labelMonthRocRocma->Size = System::Drawing::Size(71, 18);
			this->labelMonthRocRocma->TabIndex = 217;
			this->labelMonthRocRocma->Text = L"Roc_ma:";
			// 
			// labelMonthRocRoc
			// 
			this->labelMonthRocRoc->AutoSize = true;
			this->labelMonthRocRoc->Location = System::Drawing::Point(286, 439);
			this->labelMonthRocRoc->Name = L"labelMonthRocRoc";
			this->labelMonthRocRoc->Size = System::Drawing::Size(39, 18);
			this->labelMonthRocRoc->TabIndex = 215;
			this->labelMonthRocRoc->Text = L"Roc:";
			// 
			// labelMonthRocDir
			// 
			this->labelMonthRocDir->AutoSize = true;
			this->labelMonthRocDir->Location = System::Drawing::Point(87, 439);
			this->labelMonthRocDir->Name = L"labelMonthRocDir";
			this->labelMonthRocDir->Size = System::Drawing::Size(77, 18);
			this->labelMonthRocDir->TabIndex = 214;
			this->labelMonthRocDir->Text = L"Direction:";
			// 
			// listBoxMonthRocDir
			// 
			this->listBoxMonthRocDir->FormattingEnabled = true;
			this->listBoxMonthRocDir->ItemHeight = 18;
			this->listBoxMonthRocDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthRocDir->Location = System::Drawing::Point(170, 435);
			this->listBoxMonthRocDir->Name = L"listBoxMonthRocDir";
			this->listBoxMonthRocDir->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthRocDir->TabIndex = 213;
			this->listBoxMonthRocDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthRocDir_SelectedIndexChanged);
			// 
			// labelMonthRoc
			// 
			this->labelMonthRoc->AutoSize = true;
			this->labelMonthRoc->Location = System::Drawing::Point(26, 439);
			this->labelMonthRoc->Name = L"labelMonthRoc";
			this->labelMonthRoc->Size = System::Drawing::Size(46, 18);
			this->labelMonthRoc->TabIndex = 212;
			this->labelMonthRoc->Text = L"ROC:";
			// 
			// textBoxMonthVrLong
			// 
			this->textBoxMonthVrLong->Location = System::Drawing::Point(557, 470);
			this->textBoxMonthVrLong->Name = L"textBoxMonthVrLong";
			this->textBoxMonthVrLong->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthVrLong->TabIndex = 211;
			this->textBoxMonthVrLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthVrLong_TextChanged);
			// 
			// textBoxMonthVrShort
			// 
			this->textBoxMonthVrShort->Location = System::Drawing::Point(353, 475);
			this->textBoxMonthVrShort->Name = L"textBoxMonthVrShort";
			this->textBoxMonthVrShort->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthVrShort->TabIndex = 209;
			this->textBoxMonthVrShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthVrShort_TextChanged);
			// 
			// labelMonthVrLong
			// 
			this->labelMonthVrLong->AutoSize = true;
			this->labelMonthVrLong->Location = System::Drawing::Point(483, 478);
			this->labelMonthVrLong->Name = L"labelMonthVrLong";
			this->labelMonthVrLong->Size = System::Drawing::Size(48, 18);
			this->labelMonthVrLong->TabIndex = 210;
			this->labelMonthVrLong->Text = L"Long:";
			// 
			// labelMonthVrShort
			// 
			this->labelMonthVrShort->AutoSize = true;
			this->labelMonthVrShort->Location = System::Drawing::Point(281, 483);
			this->labelMonthVrShort->Name = L"labelMonthVrShort";
			this->labelMonthVrShort->Size = System::Drawing::Size(52, 18);
			this->labelMonthVrShort->TabIndex = 208;
			this->labelMonthVrShort->Text = L"Short:";
			// 
			// labelMonthVrDir
			// 
			this->labelMonthVrDir->AutoSize = true;
			this->labelMonthVrDir->Location = System::Drawing::Point(87, 482);
			this->labelMonthVrDir->Name = L"labelMonthVrDir";
			this->labelMonthVrDir->Size = System::Drawing::Size(77, 18);
			this->labelMonthVrDir->TabIndex = 207;
			this->labelMonthVrDir->Text = L"Direction:";
			// 
			// listBoxMonthVrDir
			// 
			this->listBoxMonthVrDir->FormattingEnabled = true;
			this->listBoxMonthVrDir->ItemHeight = 18;
			this->listBoxMonthVrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthVrDir->Location = System::Drawing::Point(170, 478);
			this->listBoxMonthVrDir->Name = L"listBoxMonthVrDir";
			this->listBoxMonthVrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthVrDir->TabIndex = 206;
			this->listBoxMonthVrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthVrDir_SelectedIndexChanged);
			// 
			// labelMonthVr
			// 
			this->labelMonthVr->AutoSize = true;
			this->labelMonthVr->Location = System::Drawing::Point(26, 482);
			this->labelMonthVr->Name = L"labelMonthVr";
			this->labelMonthVr->Size = System::Drawing::Size(35, 18);
			this->labelMonthVr->TabIndex = 205;
			this->labelMonthVr->Text = L"VR:";
			// 
			// labelMonthVolDir2
			// 
			this->labelMonthVolDir2->AutoSize = true;
			this->labelMonthVolDir2->Location = System::Drawing::Point(483, 154);
			this->labelMonthVolDir2->Name = L"labelMonthVolDir2";
			this->labelMonthVolDir2->Size = System::Drawing::Size(86, 18);
			this->labelMonthVolDir2->TabIndex = 204;
			this->labelMonthVolDir2->Text = L"Direction2:";
			// 
			// listBoxMonthVolDir2
			// 
			this->listBoxMonthVolDir2->FormattingEnabled = true;
			this->listBoxMonthVolDir2->ItemHeight = 18;
			this->listBoxMonthVolDir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthVolDir2->Location = System::Drawing::Point(575, 151);
			this->listBoxMonthVolDir2->Name = L"listBoxMonthVolDir2";
			this->listBoxMonthVolDir2->Size = System::Drawing::Size(106, 22);
			this->listBoxMonthVolDir2->TabIndex = 203;
			this->listBoxMonthVolDir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthVolDir2_SelectedIndexChanged);
			// 
			// textBoxMonthVol2
			// 
			this->textBoxMonthVol2->Location = System::Drawing::Point(759, 146);
			this->textBoxMonthVol2->Name = L"textBoxMonthVol2";
			this->textBoxMonthVol2->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthVol2->TabIndex = 202;
			this->textBoxMonthVol2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthVol2_TextChanged);
			// 
			// textBoxMonthVol1
			// 
			this->textBoxMonthVol1->Location = System::Drawing::Point(353, 151);
			this->textBoxMonthVol1->Name = L"textBoxMonthVol1";
			this->textBoxMonthVol1->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthVol1->TabIndex = 200;
			this->textBoxMonthVol1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthVol1_TextChanged);
			// 
			// labelMonthVol2
			// 
			this->labelMonthVol2->AutoSize = true;
			this->labelMonthVol2->Location = System::Drawing::Point(695, 154);
			this->labelMonthVol2->Name = L"labelMonthVol2";
			this->labelMonthVol2->Size = System::Drawing::Size(55, 18);
			this->labelMonthVol2->TabIndex = 201;
			this->labelMonthVol2->Text = L"VOL2:";
			// 
			// labelMonthVol1
			// 
			this->labelMonthVol1->AutoSize = true;
			this->labelMonthVol1->Location = System::Drawing::Point(290, 156);
			this->labelMonthVol1->Name = L"labelMonthVol1";
			this->labelMonthVol1->Size = System::Drawing::Size(54, 18);
			this->labelMonthVol1->TabIndex = 199;
			this->labelMonthVol1->Text = L"VOL1:";
			// 
			// labelMonthVolDir1
			// 
			this->labelMonthVolDir1->AutoSize = true;
			this->labelMonthVolDir1->Location = System::Drawing::Point(79, 156);
			this->labelMonthVolDir1->Name = L"labelMonthVolDir1";
			this->labelMonthVolDir1->Size = System::Drawing::Size(85, 18);
			this->labelMonthVolDir1->TabIndex = 198;
			this->labelMonthVolDir1->Text = L"Direction1:";
			// 
			// listBoxMonthVolDir1
			// 
			this->listBoxMonthVolDir1->FormattingEnabled = true;
			this->listBoxMonthVolDir1->ItemHeight = 18;
			this->listBoxMonthVolDir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthVolDir1->Location = System::Drawing::Point(170, 154);
			this->listBoxMonthVolDir1->Name = L"listBoxMonthVolDir1";
			this->listBoxMonthVolDir1->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthVolDir1->TabIndex = 197;
			this->listBoxMonthVolDir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthVolDir1_SelectedIndexChanged);
			// 
			// labelMonthVol
			// 
			this->labelMonthVol->AutoSize = true;
			this->labelMonthVol->Location = System::Drawing::Point(26, 158);
			this->labelMonthVol->Name = L"labelMonthVol";
			this->labelMonthVol->Size = System::Drawing::Size(46, 18);
			this->labelMonthVol->TabIndex = 196;
			this->labelMonthVol->Text = L"VOL:";
			// 
			// textBoxMonthWr2
			// 
			this->textBoxMonthWr2->Location = System::Drawing::Point(557, 382);
			this->textBoxMonthWr2->Name = L"textBoxMonthWr2";
			this->textBoxMonthWr2->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthWr2->TabIndex = 195;
			this->textBoxMonthWr2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthWr2_TextChanged);
			// 
			// textBoxMonthWr1
			// 
			this->textBoxMonthWr1->Location = System::Drawing::Point(353, 387);
			this->textBoxMonthWr1->Name = L"textBoxMonthWr1";
			this->textBoxMonthWr1->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthWr1->TabIndex = 193;
			this->textBoxMonthWr1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthWr1_TextChanged);
			// 
			// labelMonthWr2
			// 
			this->labelMonthWr2->AutoSize = true;
			this->labelMonthWr2->Location = System::Drawing::Point(483, 390);
			this->labelMonthWr2->Name = L"labelMonthWr2";
			this->labelMonthWr2->Size = System::Drawing::Size(48, 18);
			this->labelMonthWr2->TabIndex = 194;
			this->labelMonthWr2->Text = L"WR2:";
			// 
			// labelMonthWr1
			// 
			this->labelMonthWr1->AutoSize = true;
			this->labelMonthWr1->Location = System::Drawing::Point(286, 394);
			this->labelMonthWr1->Name = L"labelMonthWr1";
			this->labelMonthWr1->Size = System::Drawing::Size(47, 18);
			this->labelMonthWr1->TabIndex = 192;
			this->labelMonthWr1->Text = L"WR1:";
			// 
			// labelMonthWrDir
			// 
			this->labelMonthWrDir->AutoSize = true;
			this->labelMonthWrDir->Location = System::Drawing::Point(87, 394);
			this->labelMonthWrDir->Name = L"labelMonthWrDir";
			this->labelMonthWrDir->Size = System::Drawing::Size(77, 18);
			this->labelMonthWrDir->TabIndex = 191;
			this->labelMonthWrDir->Text = L"Direction:";
			// 
			// listBoxMonthWrDir
			// 
			this->listBoxMonthWrDir->FormattingEnabled = true;
			this->listBoxMonthWrDir->ItemHeight = 18;
			this->listBoxMonthWrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthWrDir->Location = System::Drawing::Point(170, 390);
			this->listBoxMonthWrDir->Name = L"listBoxMonthWrDir";
			this->listBoxMonthWrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthWrDir->TabIndex = 190;
			this->listBoxMonthWrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthWrDir_SelectedIndexChanged);
			// 
			// labelMonthWr
			// 
			this->labelMonthWr->AutoSize = true;
			this->labelMonthWr->Location = System::Drawing::Point(26, 394);
			this->labelMonthWr->Name = L"labelMonthWr";
			this->labelMonthWr->Size = System::Drawing::Size(39, 18);
			this->labelMonthWr->TabIndex = 189;
			this->labelMonthWr->Text = L"WR:";
			// 
			// textBoxMonthRsiLong
			// 
			this->textBoxMonthRsiLong->Location = System::Drawing::Point(759, 335);
			this->textBoxMonthRsiLong->Name = L"textBoxMonthRsiLong";
			this->textBoxMonthRsiLong->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthRsiLong->TabIndex = 188;
			this->textBoxMonthRsiLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthRsiLong_TextChanged);
			// 
			// textBoxMonthRsiMiddle
			// 
			this->textBoxMonthRsiMiddle->Location = System::Drawing::Point(557, 335);
			this->textBoxMonthRsiMiddle->Name = L"textBoxMonthRsiMiddle";
			this->textBoxMonthRsiMiddle->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthRsiMiddle->TabIndex = 186;
			this->textBoxMonthRsiMiddle->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthRsiMiddle_TextChanged);
			// 
			// textBoxMonthRsiShort
			// 
			this->textBoxMonthRsiShort->Location = System::Drawing::Point(353, 340);
			this->textBoxMonthRsiShort->Name = L"textBoxMonthRsiShort";
			this->textBoxMonthRsiShort->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthRsiShort->TabIndex = 184;
			this->textBoxMonthRsiShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthRsiShort_TextChanged);
			// 
			// labelMonthRsiLong
			// 
			this->labelMonthRsiLong->AutoSize = true;
			this->labelMonthRsiLong->Location = System::Drawing::Point(695, 340);
			this->labelMonthRsiLong->Name = L"labelMonthRsiLong";
			this->labelMonthRsiLong->Size = System::Drawing::Size(48, 18);
			this->labelMonthRsiLong->TabIndex = 187;
			this->labelMonthRsiLong->Text = L"Long:";
			// 
			// labelMonthRsiMiddle
			// 
			this->labelMonthRsiMiddle->AutoSize = true;
			this->labelMonthRsiMiddle->Location = System::Drawing::Point(483, 343);
			this->labelMonthRsiMiddle->Name = L"labelMonthRsiMiddle";
			this->labelMonthRsiMiddle->Size = System::Drawing::Size(62, 18);
			this->labelMonthRsiMiddle->TabIndex = 185;
			this->labelMonthRsiMiddle->Text = L"Middle:";
			// 
			// labelMonthRsiShort
			// 
			this->labelMonthRsiShort->AutoSize = true;
			this->labelMonthRsiShort->Location = System::Drawing::Point(286, 347);
			this->labelMonthRsiShort->Name = L"labelMonthRsiShort";
			this->labelMonthRsiShort->Size = System::Drawing::Size(52, 18);
			this->labelMonthRsiShort->TabIndex = 183;
			this->labelMonthRsiShort->Text = L"Short:";
			// 
			// labelMonthRsiDir
			// 
			this->labelMonthRsiDir->AutoSize = true;
			this->labelMonthRsiDir->Location = System::Drawing::Point(87, 347);
			this->labelMonthRsiDir->Name = L"labelMonthRsiDir";
			this->labelMonthRsiDir->Size = System::Drawing::Size(77, 18);
			this->labelMonthRsiDir->TabIndex = 182;
			this->labelMonthRsiDir->Text = L"Direction:";
			// 
			// listBoxMonthRsiDir
			// 
			this->listBoxMonthRsiDir->FormattingEnabled = true;
			this->listBoxMonthRsiDir->ItemHeight = 18;
			this->listBoxMonthRsiDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthRsiDir->Location = System::Drawing::Point(170, 343);
			this->listBoxMonthRsiDir->Name = L"listBoxMonthRsiDir";
			this->listBoxMonthRsiDir->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthRsiDir->TabIndex = 181;
			this->listBoxMonthRsiDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthRsiDir_SelectedIndexChanged);
			// 
			// labelMonthRsi
			// 
			this->labelMonthRsi->AutoSize = true;
			this->labelMonthRsi->Location = System::Drawing::Point(26, 347);
			this->labelMonthRsi->Name = L"labelMonthRsi";
			this->labelMonthRsi->Size = System::Drawing::Size(40, 18);
			this->labelMonthRsi->TabIndex = 180;
			this->labelMonthRsi->Text = L"RSI:";
			// 
			// textBoxMonthKdjJ
			// 
			this->textBoxMonthKdjJ->Location = System::Drawing::Point(759, 290);
			this->textBoxMonthKdjJ->Name = L"textBoxMonthKdjJ";
			this->textBoxMonthKdjJ->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthKdjJ->TabIndex = 179;
			this->textBoxMonthKdjJ->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthKdjJ_TextChanged);
			// 
			// textBoxMonthKdjD
			// 
			this->textBoxMonthKdjD->Location = System::Drawing::Point(557, 290);
			this->textBoxMonthKdjD->Name = L"textBoxMonthKdjD";
			this->textBoxMonthKdjD->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthKdjD->TabIndex = 177;
			this->textBoxMonthKdjD->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthKdjD_TextChanged);
			// 
			// textBoxMonthKdjK
			// 
			this->textBoxMonthKdjK->Location = System::Drawing::Point(353, 295);
			this->textBoxMonthKdjK->Name = L"textBoxMonthKdjK";
			this->textBoxMonthKdjK->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthKdjK->TabIndex = 175;
			this->textBoxMonthKdjK->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthKdjK_TextChanged);
			// 
			// labelMonthKdjJ
			// 
			this->labelMonthKdjJ->AutoSize = true;
			this->labelMonthKdjJ->Location = System::Drawing::Point(695, 298);
			this->labelMonthKdjJ->Name = L"labelMonthKdjJ";
			this->labelMonthKdjJ->Size = System::Drawing::Size(21, 18);
			this->labelMonthKdjJ->TabIndex = 178;
			this->labelMonthKdjJ->Text = L"J:";
			// 
			// labelMonthKdjD
			// 
			this->labelMonthKdjD->AutoSize = true;
			this->labelMonthKdjD->Location = System::Drawing::Point(500, 298);
			this->labelMonthKdjD->Name = L"labelMonthKdjD";
			this->labelMonthKdjD->Size = System::Drawing::Size(24, 18);
			this->labelMonthKdjD->TabIndex = 176;
			this->labelMonthKdjD->Text = L"D:";
			// 
			// labelMonthKdjK
			// 
			this->labelMonthKdjK->AutoSize = true;
			this->labelMonthKdjK->Location = System::Drawing::Point(290, 300);
			this->labelMonthKdjK->Name = L"labelMonthKdjK";
			this->labelMonthKdjK->Size = System::Drawing::Size(24, 18);
			this->labelMonthKdjK->TabIndex = 174;
			this->labelMonthKdjK->Text = L"K:";
			// 
			// labelMonthKdjDir
			// 
			this->labelMonthKdjDir->AutoSize = true;
			this->labelMonthKdjDir->Location = System::Drawing::Point(87, 302);
			this->labelMonthKdjDir->Name = L"labelMonthKdjDir";
			this->labelMonthKdjDir->Size = System::Drawing::Size(77, 18);
			this->labelMonthKdjDir->TabIndex = 173;
			this->labelMonthKdjDir->Text = L"Direction:";
			// 
			// listBoxMonthKdjDir
			// 
			this->listBoxMonthKdjDir->FormattingEnabled = true;
			this->listBoxMonthKdjDir->ItemHeight = 18;
			this->listBoxMonthKdjDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthKdjDir->Location = System::Drawing::Point(170, 298);
			this->listBoxMonthKdjDir->Name = L"listBoxMonthKdjDir";
			this->listBoxMonthKdjDir->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthKdjDir->TabIndex = 172;
			this->listBoxMonthKdjDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthKdjDir_SelectedIndexChanged);
			// 
			// labelMonthKdj
			// 
			this->labelMonthKdj->AutoSize = true;
			this->labelMonthKdj->Location = System::Drawing::Point(26, 302);
			this->labelMonthKdj->Name = L"labelMonthKdj";
			this->labelMonthKdj->Size = System::Drawing::Size(43, 18);
			this->labelMonthKdj->TabIndex = 171;
			this->labelMonthKdj->Text = L"KDJ:";
			// 
			// textBoxMonthMacdDea
			// 
			this->textBoxMonthMacdDea->Location = System::Drawing::Point(759, 243);
			this->textBoxMonthMacdDea->Name = L"textBoxMonthMacdDea";
			this->textBoxMonthMacdDea->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthMacdDea->TabIndex = 170;
			this->textBoxMonthMacdDea->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthMacdDea_TextChanged);
			// 
			// textBoxMonthMacdDif
			// 
			this->textBoxMonthMacdDif->Location = System::Drawing::Point(557, 243);
			this->textBoxMonthMacdDif->Name = L"textBoxMonthMacdDif";
			this->textBoxMonthMacdDif->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthMacdDif->TabIndex = 168;
			this->textBoxMonthMacdDif->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthMacdDif_TextChanged);
			// 
			// textBoxMonthMacdMacd
			// 
			this->textBoxMonthMacdMacd->Location = System::Drawing::Point(353, 248);
			this->textBoxMonthMacdMacd->Name = L"textBoxMonthMacdMacd";
			this->textBoxMonthMacdMacd->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthMacdMacd->TabIndex = 166;
			this->textBoxMonthMacdMacd->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthMacdMacd_TextChanged);
			// 
			// labelMonthMacdDea
			// 
			this->labelMonthMacdDea->AutoSize = true;
			this->labelMonthMacdDea->Location = System::Drawing::Point(695, 251);
			this->labelMonthMacdDea->Name = L"labelMonthMacdDea";
			this->labelMonthMacdDea->Size = System::Drawing::Size(40, 18);
			this->labelMonthMacdDea->TabIndex = 169;
			this->labelMonthMacdDea->Text = L"Dea:";
			// 
			// labelMonthMacdDif
			// 
			this->labelMonthMacdDif->AutoSize = true;
			this->labelMonthMacdDif->Location = System::Drawing::Point(500, 251);
			this->labelMonthMacdDif->Name = L"labelMonthMacdDif";
			this->labelMonthMacdDif->Size = System::Drawing::Size(33, 18);
			this->labelMonthMacdDif->TabIndex = 167;
			this->labelMonthMacdDif->Text = L"Dif:";
			// 
			// labelMonthMacdMacd
			// 
			this->labelMonthMacdMacd->AutoSize = true;
			this->labelMonthMacdMacd->Location = System::Drawing::Point(290, 253);
			this->labelMonthMacdMacd->Name = L"labelMonthMacdMacd";
			this->labelMonthMacdMacd->Size = System::Drawing::Size(52, 18);
			this->labelMonthMacdMacd->TabIndex = 165;
			this->labelMonthMacdMacd->Text = L"Macd:";
			// 
			// labelMonthMacdDir
			// 
			this->labelMonthMacdDir->AutoSize = true;
			this->labelMonthMacdDir->Location = System::Drawing::Point(87, 255);
			this->labelMonthMacdDir->Name = L"labelMonthMacdDir";
			this->labelMonthMacdDir->Size = System::Drawing::Size(77, 18);
			this->labelMonthMacdDir->TabIndex = 164;
			this->labelMonthMacdDir->Text = L"Direction:";
			// 
			// listBoxMonthMacdDir
			// 
			this->listBoxMonthMacdDir->FormattingEnabled = true;
			this->listBoxMonthMacdDir->ItemHeight = 18;
			this->listBoxMonthMacdDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthMacdDir->Location = System::Drawing::Point(170, 251);
			this->listBoxMonthMacdDir->Name = L"listBoxMonthMacdDir";
			this->listBoxMonthMacdDir->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthMacdDir->TabIndex = 163;
			this->listBoxMonthMacdDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthMacdDir_SelectedIndexChanged);
			// 
			// labelMonthMacd
			// 
			this->labelMonthMacd->AutoSize = true;
			this->labelMonthMacd->Location = System::Drawing::Point(26, 255);
			this->labelMonthMacd->Name = L"labelMonthMacd";
			this->labelMonthMacd->Size = System::Drawing::Size(60, 18);
			this->labelMonthMacd->TabIndex = 162;
			this->labelMonthMacd->Text = L"MACD:";
			// 
			// textBoxMonthBollUpper
			// 
			this->textBoxMonthBollUpper->Location = System::Drawing::Point(759, 196);
			this->textBoxMonthBollUpper->Name = L"textBoxMonthBollUpper";
			this->textBoxMonthBollUpper->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthBollUpper->TabIndex = 161;
			this->textBoxMonthBollUpper->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthBollUpper_TextChanged);
			// 
			// textBoxMonthBollMid
			// 
			this->textBoxMonthBollMid->Location = System::Drawing::Point(557, 198);
			this->textBoxMonthBollMid->Name = L"textBoxMonthBollMid";
			this->textBoxMonthBollMid->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthBollMid->TabIndex = 159;
			this->textBoxMonthBollMid->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthBollMid_TextChanged);
			// 
			// textBoxMonthBollLow
			// 
			this->textBoxMonthBollLow->Location = System::Drawing::Point(353, 200);
			this->textBoxMonthBollLow->Name = L"textBoxMonthBollLow";
			this->textBoxMonthBollLow->Size = System::Drawing::Size(124, 26);
			this->textBoxMonthBollLow->TabIndex = 157;
			this->textBoxMonthBollLow->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxMonthBollLow_TextChanged);
			// 
			// labelMonthBollUpper
			// 
			this->labelMonthBollUpper->AutoSize = true;
			this->labelMonthBollUpper->Location = System::Drawing::Point(695, 202);
			this->labelMonthBollUpper->Name = L"labelMonthBollUpper";
			this->labelMonthBollUpper->Size = System::Drawing::Size(58, 18);
			this->labelMonthBollUpper->TabIndex = 160;
			this->labelMonthBollUpper->Text = L"Upper:";
			// 
			// labelMonthBollMid
			// 
			this->labelMonthBollMid->AutoSize = true;
			this->labelMonthBollMid->Location = System::Drawing::Point(500, 204);
			this->labelMonthBollMid->Name = L"labelMonthBollMid";
			this->labelMonthBollMid->Size = System::Drawing::Size(41, 18);
			this->labelMonthBollMid->TabIndex = 158;
			this->labelMonthBollMid->Text = L"Mid:";
			// 
			// labelMonthBollLow
			// 
			this->labelMonthBollLow->AutoSize = true;
			this->labelMonthBollLow->Location = System::Drawing::Point(295, 206);
			this->labelMonthBollLow->Name = L"labelMonthBollLow";
			this->labelMonthBollLow->Size = System::Drawing::Size(43, 18);
			this->labelMonthBollLow->TabIndex = 156;
			this->labelMonthBollLow->Text = L"Low:";
			// 
			// labelMonthBollDir
			// 
			this->labelMonthBollDir->AutoSize = true;
			this->labelMonthBollDir->Location = System::Drawing::Point(87, 206);
			this->labelMonthBollDir->Name = L"labelMonthBollDir";
			this->labelMonthBollDir->Size = System::Drawing::Size(77, 18);
			this->labelMonthBollDir->TabIndex = 155;
			this->labelMonthBollDir->Text = L"Direction:";
			// 
			// listBoxMonthBollDir
			// 
			this->listBoxMonthBollDir->FormattingEnabled = true;
			this->listBoxMonthBollDir->ItemHeight = 18;
			this->listBoxMonthBollDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxMonthBollDir->Location = System::Drawing::Point(170, 204);
			this->listBoxMonthBollDir->Name = L"listBoxMonthBollDir";
			this->listBoxMonthBollDir->Size = System::Drawing::Size(97, 22);
			this->listBoxMonthBollDir->TabIndex = 154;
			this->listBoxMonthBollDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxMonthBollDir_SelectedIndexChanged);
			// 
			// labelMonthBoll
			// 
			this->labelMonthBoll->AutoSize = true;
			this->labelMonthBoll->Location = System::Drawing::Point(26, 210);
			this->labelMonthBoll->Name = L"labelMonthBoll";
			this->labelMonthBoll->Size = System::Drawing::Size(55, 18);
			this->labelMonthBoll->TabIndex = 153;
			this->labelMonthBoll->Text = L"BOLL:";
			// 
			// tabYear
			// 
			this->tabYear->AutoScroll = true;
			this->tabYear->Controls->Add(this->listBoxYearMADir6);
			this->tabYear->Controls->Add(this->labelYearMADir6);
			this->tabYear->Controls->Add(this->textBoxYearMA6);
			this->tabYear->Controls->Add(this->textBoxYearMA5);
			this->tabYear->Controls->Add(this->labelYearMA6);
			this->tabYear->Controls->Add(this->labelYearMA5);
			this->tabYear->Controls->Add(this->labelYearMADir5);
			this->tabYear->Controls->Add(this->listBoxYearMADir5);
			this->tabYear->Controls->Add(this->labelYearMA56);
			this->tabYear->Controls->Add(this->labelYearMADir4);
			this->tabYear->Controls->Add(this->listBoxYearMADir4);
			this->tabYear->Controls->Add(this->textBoxYearMA4);
			this->tabYear->Controls->Add(this->textBoxYearMA3);
			this->tabYear->Controls->Add(this->labelYearMA4);
			this->tabYear->Controls->Add(this->labelYearMA3);
			this->tabYear->Controls->Add(this->labelYearMADir3);
			this->tabYear->Controls->Add(this->listBoxYearMADir3);
			this->tabYear->Controls->Add(this->labelYearMA34);
			this->tabYear->Controls->Add(this->labelYearMADir2);
			this->tabYear->Controls->Add(this->listBoxYearMADir2);
			this->tabYear->Controls->Add(this->textBoxYearMA2);
			this->tabYear->Controls->Add(this->textBoxYearMA1);
			this->tabYear->Controls->Add(this->labelYearMA2);
			this->tabYear->Controls->Add(this->labelYearMA1);
			this->tabYear->Controls->Add(this->labelYearMADir1);
			this->tabYear->Controls->Add(this->listBoxYearMADir1);
			this->tabYear->Controls->Add(this->labelYearMA12);
			this->tabYear->Controls->Add(this->textBoxYearCciCci);
			this->tabYear->Controls->Add(this->labelYearCciCci);
			this->tabYear->Controls->Add(this->labelYearCciDir);
			this->tabYear->Controls->Add(this->listBoxYearCciDir);
			this->tabYear->Controls->Add(this->labelYearCci);
			this->tabYear->Controls->Add(this->textBoxYearCrC);
			this->tabYear->Controls->Add(this->labelYearCrC);
			this->tabYear->Controls->Add(this->textBoxYearCrB);
			this->tabYear->Controls->Add(this->labelYearCrB);
			this->tabYear->Controls->Add(this->textBoxYearCrA);
			this->tabYear->Controls->Add(this->textBoxYearCrCr);
			this->tabYear->Controls->Add(this->labelYearCrA);
			this->tabYear->Controls->Add(this->labelYearCrCr);
			this->tabYear->Controls->Add(this->labeYearCrDir);
			this->tabYear->Controls->Add(this->listBoxYearCrDir);
			this->tabYear->Controls->Add(this->labelYearCr);
			this->tabYear->Controls->Add(this->textBoxYearDmaAma);
			this->tabYear->Controls->Add(this->textBoxYearDmaDma);
			this->tabYear->Controls->Add(this->labelYearDmaAma);
			this->tabYear->Controls->Add(this->labelYearDmaDma);
			this->tabYear->Controls->Add(this->labelYearDmaDir);
			this->tabYear->Controls->Add(this->listBoxYearDmaDir);
			this->tabYear->Controls->Add(this->labelYearDma);
			this->tabYear->Controls->Add(this->textBoxYearRocRocma);
			this->tabYear->Controls->Add(this->textBoxYearRocRoc);
			this->tabYear->Controls->Add(this->labelYearRocRoc_ma);
			this->tabYear->Controls->Add(this->labelYearRocRoc);
			this->tabYear->Controls->Add(this->labelYearRocDir);
			this->tabYear->Controls->Add(this->listBoxYearRocDir);
			this->tabYear->Controls->Add(this->labelYearRoc);
			this->tabYear->Controls->Add(this->textBoxYearVrLong);
			this->tabYear->Controls->Add(this->textBoxYearVrShort);
			this->tabYear->Controls->Add(this->labelYearVrLong);
			this->tabYear->Controls->Add(this->labelYearVrShort);
			this->tabYear->Controls->Add(this->labelYearVrDir);
			this->tabYear->Controls->Add(this->listBoxYearVrDir);
			this->tabYear->Controls->Add(this->labelYearVr);
			this->tabYear->Controls->Add(this->labelYearVolDir2);
			this->tabYear->Controls->Add(this->listBoxYearVolDir2);
			this->tabYear->Controls->Add(this->textBoxYearVol2);
			this->tabYear->Controls->Add(this->textBoxYearVol1);
			this->tabYear->Controls->Add(this->labelYearVol2);
			this->tabYear->Controls->Add(this->labelYearVol1);
			this->tabYear->Controls->Add(this->labelYearVolDir1);
			this->tabYear->Controls->Add(this->listBoxYearVolDir1);
			this->tabYear->Controls->Add(this->labelYearVol);
			this->tabYear->Controls->Add(this->textBoxYearWr2);
			this->tabYear->Controls->Add(this->textBoxYearWr1);
			this->tabYear->Controls->Add(this->labelYearWr2);
			this->tabYear->Controls->Add(this->labelYearWr1);
			this->tabYear->Controls->Add(this->labelYearWrDir);
			this->tabYear->Controls->Add(this->listBoxYearWrDir);
			this->tabYear->Controls->Add(this->labelYearWr);
			this->tabYear->Controls->Add(this->textBoxYearRsiLong);
			this->tabYear->Controls->Add(this->textBoxYearRsiMiddle);
			this->tabYear->Controls->Add(this->textBoxYearRsiShort);
			this->tabYear->Controls->Add(this->labelYearRsiLong);
			this->tabYear->Controls->Add(this->labelYearRsiMiddle);
			this->tabYear->Controls->Add(this->labelYearRsiShort);
			this->tabYear->Controls->Add(this->labelYearRsiDir);
			this->tabYear->Controls->Add(this->listBoxYearRsiDir);
			this->tabYear->Controls->Add(this->labelYearRsi);
			this->tabYear->Controls->Add(this->textBoxYearKdjJ);
			this->tabYear->Controls->Add(this->textBoxYearKdjD);
			this->tabYear->Controls->Add(this->textBoxYearKdjK);
			this->tabYear->Controls->Add(this->labelYearKdjJ);
			this->tabYear->Controls->Add(this->labelYearKdjD);
			this->tabYear->Controls->Add(this->labelYearKdjK);
			this->tabYear->Controls->Add(this->labelYearKdjDir);
			this->tabYear->Controls->Add(this->listBoxYearKdjDir);
			this->tabYear->Controls->Add(this->labelYearKdj);
			this->tabYear->Controls->Add(this->textBoxYearMacdDea);
			this->tabYear->Controls->Add(this->textBoxYearMacdDif);
			this->tabYear->Controls->Add(this->textBoxYearMacdMacd);
			this->tabYear->Controls->Add(this->labelYearMacdDea);
			this->tabYear->Controls->Add(this->labelYearMacdDif);
			this->tabYear->Controls->Add(this->labelYearMacdMacd);
			this->tabYear->Controls->Add(this->labelYearMacdDir);
			this->tabYear->Controls->Add(this->listBoxYearMacdDir);
			this->tabYear->Controls->Add(this->labelYearMacd);
			this->tabYear->Controls->Add(this->textBoxYearBollUpper);
			this->tabYear->Controls->Add(this->textBoxYearBollMid);
			this->tabYear->Controls->Add(this->textBoxYearBollLow);
			this->tabYear->Controls->Add(this->labelYearBollUpper);
			this->tabYear->Controls->Add(this->labelYearBollMid);
			this->tabYear->Controls->Add(this->labelYearBollLow);
			this->tabYear->Controls->Add(this->labelYearBollDir);
			this->tabYear->Controls->Add(this->listBoxYearBollDir);
			this->tabYear->Controls->Add(this->labelYearBoll);
			this->tabYear->Location = System::Drawing::Point(4, 27);
			this->tabYear->Name = L"tabYear";
			this->tabYear->Padding = System::Windows::Forms::Padding(3);
			this->tabYear->Size = System::Drawing::Size(1092, 869);
			this->tabYear->TabIndex = 0;
			this->tabYear->Text = L"Year";
			this->tabYear->UseVisualStyleBackColor = true;
			// 
			// listBoxYearMADir6
			// 
			this->listBoxYearMADir6->FormattingEnabled = true;
			this->listBoxYearMADir6->ItemHeight = 18;
			this->listBoxYearMADir6->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearMADir6->Location = System::Drawing::Point(575, 103);
			this->listBoxYearMADir6->Name = L"listBoxYearMADir6";
			this->listBoxYearMADir6->Size = System::Drawing::Size(106, 22);
			this->listBoxYearMADir6->TabIndex = 269;
			this->listBoxYearMADir6->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearMADir6_SelectedIndexChanged);
			// 
			// labelYearMADir6
			// 
			this->labelYearMADir6->AutoSize = true;
			this->labelYearMADir6->Location = System::Drawing::Point(483, 107);
			this->labelYearMADir6->Name = L"labelYearMADir6";
			this->labelYearMADir6->Size = System::Drawing::Size(80, 18);
			this->labelYearMADir6->TabIndex = 268;
			this->labelYearMADir6->Text = L"MA_Dir6:";
			// 
			// textBoxYearMA6
			// 
			this->textBoxYearMA6->Location = System::Drawing::Point(759, 99);
			this->textBoxYearMA6->Name = L"textBoxYearMA6";
			this->textBoxYearMA6->Size = System::Drawing::Size(124, 26);
			this->textBoxYearMA6->TabIndex = 266;
			this->textBoxYearMA6->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearMA6_TextChanged);
			// 
			// textBoxYearMA5
			// 
			this->textBoxYearMA5->Location = System::Drawing::Point(353, 104);
			this->textBoxYearMA5->Name = L"textBoxYearMA5";
			this->textBoxYearMA5->Size = System::Drawing::Size(124, 26);
			this->textBoxYearMA5->TabIndex = 264;
			this->textBoxYearMA5->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearMA5_TextChanged);
			// 
			// labelYearMA6
			// 
			this->labelYearMA6->AutoSize = true;
			this->labelYearMA6->Location = System::Drawing::Point(695, 107);
			this->labelYearMA6->Name = L"labelYearMA6";
			this->labelYearMA6->Size = System::Drawing::Size(48, 18);
			this->labelYearMA6->TabIndex = 265;
			this->labelYearMA6->Text = L"MA6:";
			// 
			// labelYearMA5
			// 
			this->labelYearMA5->AutoSize = true;
			this->labelYearMA5->Location = System::Drawing::Point(290, 109);
			this->labelYearMA5->Name = L"labelYearMA5";
			this->labelYearMA5->Size = System::Drawing::Size(48, 18);
			this->labelYearMA5->TabIndex = 263;
			this->labelYearMA5->Text = L"MA5:";
			// 
			// labelYearMADir5
			// 
			this->labelYearMADir5->AutoSize = true;
			this->labelYearMADir5->Location = System::Drawing::Point(79, 112);
			this->labelYearMADir5->Name = L"labelYearMADir5";
			this->labelYearMADir5->Size = System::Drawing::Size(80, 18);
			this->labelYearMADir5->TabIndex = 262;
			this->labelYearMADir5->Text = L"MA_Dir5:";
			// 
			// listBoxYearMADir5
			// 
			this->listBoxYearMADir5->FormattingEnabled = true;
			this->listBoxYearMADir5->ItemHeight = 18;
			this->listBoxYearMADir5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearMADir5->Location = System::Drawing::Point(170, 107);
			this->listBoxYearMADir5->Name = L"listBoxYearMADir5";
			this->listBoxYearMADir5->Size = System::Drawing::Size(97, 22);
			this->listBoxYearMADir5->TabIndex = 261;
			this->listBoxYearMADir5->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearMADir5_SelectedIndexChanged);
			// 
			// labelYearMA56
			// 
			this->labelYearMA56->AutoSize = true;
			this->labelYearMA56->Location = System::Drawing::Point(17, 112);
			this->labelYearMA56->Name = L"labelYearMA56";
			this->labelYearMA56->Size = System::Drawing::Size(64, 18);
			this->labelYearMA56->TabIndex = 260;
			this->labelYearMA56->Text = L"MA5-6:";
			// 
			// labelYearMADir4
			// 
			this->labelYearMADir4->AutoSize = true;
			this->labelYearMADir4->Location = System::Drawing::Point(483, 60);
			this->labelYearMADir4->Name = L"labelYearMADir4";
			this->labelYearMADir4->Size = System::Drawing::Size(80, 18);
			this->labelYearMADir4->TabIndex = 259;
			this->labelYearMADir4->Text = L"MA_Dir4:";
			// 
			// listBoxYearMADir4
			// 
			this->listBoxYearMADir4->FormattingEnabled = true;
			this->listBoxYearMADir4->ItemHeight = 18;
			this->listBoxYearMADir4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearMADir4->Location = System::Drawing::Point(575, 57);
			this->listBoxYearMADir4->Name = L"listBoxYearMADir4";
			this->listBoxYearMADir4->Size = System::Drawing::Size(106, 22);
			this->listBoxYearMADir4->TabIndex = 258;
			this->listBoxYearMADir4->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearMADir4_SelectedIndexChanged);
			// 
			// textBoxYearMA4
			// 
			this->textBoxYearMA4->Location = System::Drawing::Point(759, 52);
			this->textBoxYearMA4->Name = L"textBoxYearMA4";
			this->textBoxYearMA4->Size = System::Drawing::Size(124, 26);
			this->textBoxYearMA4->TabIndex = 257;
			this->textBoxYearMA4->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearMA4_TextChanged);
			// 
			// textBoxYearMA3
			// 
			this->textBoxYearMA3->Location = System::Drawing::Point(353, 57);
			this->textBoxYearMA3->Name = L"textBoxYearMA3";
			this->textBoxYearMA3->Size = System::Drawing::Size(124, 26);
			this->textBoxYearMA3->TabIndex = 255;
			this->textBoxYearMA3->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearMA3_TextChanged);
			// 
			// labelYearMA4
			// 
			this->labelYearMA4->AutoSize = true;
			this->labelYearMA4->Location = System::Drawing::Point(695, 60);
			this->labelYearMA4->Name = L"labelYearMA4";
			this->labelYearMA4->Size = System::Drawing::Size(48, 18);
			this->labelYearMA4->TabIndex = 256;
			this->labelYearMA4->Text = L"MA4:";
			// 
			// labelYearMA3
			// 
			this->labelYearMA3->AutoSize = true;
			this->labelYearMA3->Location = System::Drawing::Point(290, 62);
			this->labelYearMA3->Name = L"labelYearMA3";
			this->labelYearMA3->Size = System::Drawing::Size(48, 18);
			this->labelYearMA3->TabIndex = 254;
			this->labelYearMA3->Text = L"MA3:";
			// 
			// labelYearMADir3
			// 
			this->labelYearMADir3->AutoSize = true;
			this->labelYearMADir3->Location = System::Drawing::Point(79, 65);
			this->labelYearMADir3->Name = L"labelYearMADir3";
			this->labelYearMADir3->Size = System::Drawing::Size(80, 18);
			this->labelYearMADir3->TabIndex = 253;
			this->labelYearMADir3->Text = L"MA_Dir3:";
			// 
			// listBoxYearMADir3
			// 
			this->listBoxYearMADir3->FormattingEnabled = true;
			this->listBoxYearMADir3->ItemHeight = 18;
			this->listBoxYearMADir3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearMADir3->Location = System::Drawing::Point(170, 60);
			this->listBoxYearMADir3->Name = L"listBoxYearMADir3";
			this->listBoxYearMADir3->Size = System::Drawing::Size(97, 22);
			this->listBoxYearMADir3->TabIndex = 252;
			this->listBoxYearMADir3->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearMADir3_SelectedIndexChanged);
			// 
			// labelYearMA34
			// 
			this->labelYearMA34->AutoSize = true;
			this->labelYearMA34->Location = System::Drawing::Point(17, 65);
			this->labelYearMA34->Name = L"labelYearMA34";
			this->labelYearMA34->Size = System::Drawing::Size(64, 18);
			this->labelYearMA34->TabIndex = 251;
			this->labelYearMA34->Text = L"MA3-4:";
			// 
			// labelYearMADir2
			// 
			this->labelYearMADir2->AutoSize = true;
			this->labelYearMADir2->Location = System::Drawing::Point(483, 19);
			this->labelYearMADir2->Name = L"labelYearMADir2";
			this->labelYearMADir2->Size = System::Drawing::Size(80, 18);
			this->labelYearMADir2->TabIndex = 250;
			this->labelYearMADir2->Text = L"MA_Dir2:";
			// 
			// listBoxYearMADir2
			// 
			this->listBoxYearMADir2->FormattingEnabled = true;
			this->listBoxYearMADir2->ItemHeight = 18;
			this->listBoxYearMADir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearMADir2->Location = System::Drawing::Point(575, 16);
			this->listBoxYearMADir2->Name = L"listBoxYearMADir2";
			this->listBoxYearMADir2->Size = System::Drawing::Size(106, 22);
			this->listBoxYearMADir2->TabIndex = 249;
			this->listBoxYearMADir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearMADir2_SelectedIndexChanged);
			// 
			// textBoxYearMA2
			// 
			this->textBoxYearMA2->Location = System::Drawing::Point(759, 11);
			this->textBoxYearMA2->Name = L"textBoxYearMA2";
			this->textBoxYearMA2->Size = System::Drawing::Size(124, 26);
			this->textBoxYearMA2->TabIndex = 248;
			this->textBoxYearMA2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearMA2_TextChanged);
			// 
			// textBoxYearMA1
			// 
			this->textBoxYearMA1->Location = System::Drawing::Point(353, 16);
			this->textBoxYearMA1->Name = L"textBoxYearMA1";
			this->textBoxYearMA1->Size = System::Drawing::Size(124, 26);
			this->textBoxYearMA1->TabIndex = 246;
			this->textBoxYearMA1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearMA1_TextChanged);
			// 
			// labelYearMA2
			// 
			this->labelYearMA2->AutoSize = true;
			this->labelYearMA2->Location = System::Drawing::Point(695, 19);
			this->labelYearMA2->Name = L"labelYearMA2";
			this->labelYearMA2->Size = System::Drawing::Size(48, 18);
			this->labelYearMA2->TabIndex = 247;
			this->labelYearMA2->Text = L"MA2:";
			// 
			// labelYearMA1
			// 
			this->labelYearMA1->AutoSize = true;
			this->labelYearMA1->Location = System::Drawing::Point(290, 21);
			this->labelYearMA1->Name = L"labelYearMA1";
			this->labelYearMA1->Size = System::Drawing::Size(47, 18);
			this->labelYearMA1->TabIndex = 245;
			this->labelYearMA1->Text = L"MA1:";
			// 
			// labelYearMADir1
			// 
			this->labelYearMADir1->AutoSize = true;
			this->labelYearMADir1->Location = System::Drawing::Point(79, 21);
			this->labelYearMADir1->Name = L"labelYearMADir1";
			this->labelYearMADir1->Size = System::Drawing::Size(79, 18);
			this->labelYearMADir1->TabIndex = 244;
			this->labelYearMADir1->Text = L"MA_Dir1:";
			// 
			// listBoxYearMADir1
			// 
			this->listBoxYearMADir1->FormattingEnabled = true;
			this->listBoxYearMADir1->ItemHeight = 18;
			this->listBoxYearMADir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearMADir1->Location = System::Drawing::Point(170, 19);
			this->listBoxYearMADir1->Name = L"listBoxYearMADir1";
			this->listBoxYearMADir1->Size = System::Drawing::Size(97, 22);
			this->listBoxYearMADir1->TabIndex = 243;
			this->listBoxYearMADir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearMADir1_SelectedIndexChanged);
			// 
			// labelYearMA12
			// 
			this->labelYearMA12->AutoSize = true;
			this->labelYearMA12->Location = System::Drawing::Point(16, 24);
			this->labelYearMA12->Name = L"labelYearMA12";
			this->labelYearMA12->Size = System::Drawing::Size(63, 18);
			this->labelYearMA12->TabIndex = 242;
			this->labelYearMA12->Text = L"MA1-2:";
			// 
			// textBoxYearCciCci
			// 
			this->textBoxYearCciCci->Location = System::Drawing::Point(353, 601);
			this->textBoxYearCciCci->Name = L"textBoxYearCciCci";
			this->textBoxYearCciCci->Size = System::Drawing::Size(124, 26);
			this->textBoxYearCciCci->TabIndex = 241;
			this->textBoxYearCciCci->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearCciCci_TextChanged);
			// 
			// labelYearCciCci
			// 
			this->labelYearCciCci->AutoSize = true;
			this->labelYearCciCci->Location = System::Drawing::Point(286, 608);
			this->labelYearCciCci->Name = L"labelYearCciCci";
			this->labelYearCciCci->Size = System::Drawing::Size(34, 18);
			this->labelYearCciCci->TabIndex = 240;
			this->labelYearCciCci->Text = L"Cci:";
			// 
			// labelYearCciDir
			// 
			this->labelYearCciDir->AutoSize = true;
			this->labelYearCciDir->Location = System::Drawing::Point(87, 608);
			this->labelYearCciDir->Name = L"labelYearCciDir";
			this->labelYearCciDir->Size = System::Drawing::Size(77, 18);
			this->labelYearCciDir->TabIndex = 239;
			this->labelYearCciDir->Text = L"Direction:";
			// 
			// listBoxYearCciDir
			// 
			this->listBoxYearCciDir->FormattingEnabled = true;
			this->listBoxYearCciDir->ItemHeight = 18;
			this->listBoxYearCciDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearCciDir->Location = System::Drawing::Point(170, 604);
			this->listBoxYearCciDir->Name = L"listBoxYearCciDir";
			this->listBoxYearCciDir->Size = System::Drawing::Size(97, 22);
			this->listBoxYearCciDir->TabIndex = 238;
			this->listBoxYearCciDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearCciDir_SelectedIndexChanged);
			// 
			// labelYearCci
			// 
			this->labelYearCci->AutoSize = true;
			this->labelYearCci->Location = System::Drawing::Point(26, 608);
			this->labelYearCci->Name = L"labelYearCci";
			this->labelYearCci->Size = System::Drawing::Size(40, 18);
			this->labelYearCci->TabIndex = 237;
			this->labelYearCci->Text = L"CCI:";
			// 
			// textBoxYearCrC
			// 
			this->textBoxYearCrC->Location = System::Drawing::Point(961, 555);
			this->textBoxYearCrC->Name = L"textBoxYearCrC";
			this->textBoxYearCrC->Size = System::Drawing::Size(124, 26);
			this->textBoxYearCrC->TabIndex = 236;
			this->textBoxYearCrC->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearCrC_TextChanged);
			// 
			// labelYearCrC
			// 
			this->labelYearCrC->AutoSize = true;
			this->labelYearCrC->Location = System::Drawing::Point(900, 563);
			this->labelYearCrC->Name = L"labelYearCrC";
			this->labelYearCrC->Size = System::Drawing::Size(23, 18);
			this->labelYearCrC->TabIndex = 235;
			this->labelYearCrC->Text = L"C:";
			// 
			// textBoxYearCrB
			// 
			this->textBoxYearCrB->Location = System::Drawing::Point(755, 555);
			this->textBoxYearCrB->Name = L"textBoxYearCrB";
			this->textBoxYearCrB->Size = System::Drawing::Size(124, 26);
			this->textBoxYearCrB->TabIndex = 234;
			this->textBoxYearCrB->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearCrB_TextChanged);
			// 
			// labelYearCrB
			// 
			this->labelYearCrB->AutoSize = true;
			this->labelYearCrB->Location = System::Drawing::Point(694, 563);
			this->labelYearCrB->Name = L"labelYearCrB";
			this->labelYearCrB->Size = System::Drawing::Size(23, 18);
			this->labelYearCrB->TabIndex = 233;
			this->labelYearCrB->Text = L"B:";
			// 
			// textBoxYearCrA
			// 
			this->textBoxYearCrA->Location = System::Drawing::Point(557, 555);
			this->textBoxYearCrA->Name = L"textBoxYearCrA";
			this->textBoxYearCrA->Size = System::Drawing::Size(124, 26);
			this->textBoxYearCrA->TabIndex = 232;
			this->textBoxYearCrA->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearCrA_TextChanged);
			// 
			// textBoxYearCrCr
			// 
			this->textBoxYearCrCr->Location = System::Drawing::Point(353, 560);
			this->textBoxYearCrCr->Name = L"textBoxYearCrCr";
			this->textBoxYearCrCr->Size = System::Drawing::Size(124, 26);
			this->textBoxYearCrCr->TabIndex = 230;
			this->textBoxYearCrCr->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearCrCr_TextChanged);
			// 
			// labelYearCrA
			// 
			this->labelYearCrA->AutoSize = true;
			this->labelYearCrA->Location = System::Drawing::Point(496, 563);
			this->labelYearCrA->Name = L"labelYearCrA";
			this->labelYearCrA->Size = System::Drawing::Size(24, 18);
			this->labelYearCrA->TabIndex = 231;
			this->labelYearCrA->Text = L"A:";
			// 
			// labelYearCrCr
			// 
			this->labelYearCrCr->AutoSize = true;
			this->labelYearCrCr->Location = System::Drawing::Point(286, 567);
			this->labelYearCrCr->Name = L"labelYearCrCr";
			this->labelYearCrCr->Size = System::Drawing::Size(30, 18);
			this->labelYearCrCr->TabIndex = 229;
			this->labelYearCrCr->Text = L"Cr:";
			// 
			// labeYearCrDir
			// 
			this->labeYearCrDir->AutoSize = true;
			this->labeYearCrDir->Location = System::Drawing::Point(87, 567);
			this->labeYearCrDir->Name = L"labeYearCrDir";
			this->labeYearCrDir->Size = System::Drawing::Size(77, 18);
			this->labeYearCrDir->TabIndex = 228;
			this->labeYearCrDir->Text = L"Direction:";
			// 
			// listBoxYearCrDir
			// 
			this->listBoxYearCrDir->FormattingEnabled = true;
			this->listBoxYearCrDir->ItemHeight = 18;
			this->listBoxYearCrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearCrDir->Location = System::Drawing::Point(170, 563);
			this->listBoxYearCrDir->Name = L"listBoxYearCrDir";
			this->listBoxYearCrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxYearCrDir->TabIndex = 227;
			this->listBoxYearCrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearCrDir_SelectedIndexChanged);
			// 
			// labelYearCr
			// 
			this->labelYearCr->AutoSize = true;
			this->labelYearCr->Location = System::Drawing::Point(26, 567);
			this->labelYearCr->Name = L"labelYearCr";
			this->labelYearCr->Size = System::Drawing::Size(34, 18);
			this->labelYearCr->TabIndex = 226;
			this->labelYearCr->Text = L"CR:";
			// 
			// textBoxYearDmaAma
			// 
			this->textBoxYearDmaAma->Location = System::Drawing::Point(557, 513);
			this->textBoxYearDmaAma->Name = L"textBoxYearDmaAma";
			this->textBoxYearDmaAma->Size = System::Drawing::Size(124, 26);
			this->textBoxYearDmaAma->TabIndex = 225;
			this->textBoxYearDmaAma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearDmaAma_TextChanged);
			// 
			// textBoxYearDmaDma
			// 
			this->textBoxYearDmaDma->Location = System::Drawing::Point(353, 518);
			this->textBoxYearDmaDma->Name = L"textBoxYearDmaDma";
			this->textBoxYearDmaDma->Size = System::Drawing::Size(124, 26);
			this->textBoxYearDmaDma->TabIndex = 223;
			this->textBoxYearDmaDma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearDmaDma_TextChanged);
			// 
			// labelYearDmaAma
			// 
			this->labelYearDmaAma->AutoSize = true;
			this->labelYearDmaAma->Location = System::Drawing::Point(483, 521);
			this->labelYearDmaAma->Name = L"labelYearDmaAma";
			this->labelYearDmaAma->Size = System::Drawing::Size(46, 18);
			this->labelYearDmaAma->TabIndex = 224;
			this->labelYearDmaAma->Text = L"Ama:";
			// 
			// labelYearDmaDma
			// 
			this->labelYearDmaDma->AutoSize = true;
			this->labelYearDmaDma->Location = System::Drawing::Point(286, 525);
			this->labelYearDmaDma->Name = L"labelYearDmaDma";
			this->labelYearDmaDma->Size = System::Drawing::Size(46, 18);
			this->labelYearDmaDma->TabIndex = 222;
			this->labelYearDmaDma->Text = L"Dma:";
			// 
			// labelYearDmaDir
			// 
			this->labelYearDmaDir->AutoSize = true;
			this->labelYearDmaDir->Location = System::Drawing::Point(87, 525);
			this->labelYearDmaDir->Name = L"labelYearDmaDir";
			this->labelYearDmaDir->Size = System::Drawing::Size(77, 18);
			this->labelYearDmaDir->TabIndex = 221;
			this->labelYearDmaDir->Text = L"Direction:";
			// 
			// listBoxYearDmaDir
			// 
			this->listBoxYearDmaDir->FormattingEnabled = true;
			this->listBoxYearDmaDir->ItemHeight = 18;
			this->listBoxYearDmaDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearDmaDir->Location = System::Drawing::Point(170, 521);
			this->listBoxYearDmaDir->Name = L"listBoxYearDmaDir";
			this->listBoxYearDmaDir->Size = System::Drawing::Size(97, 22);
			this->listBoxYearDmaDir->TabIndex = 220;
			this->listBoxYearDmaDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearDmaDir_SelectedIndexChanged);
			// 
			// labelYearDma
			// 
			this->labelYearDma->AutoSize = true;
			this->labelYearDma->Location = System::Drawing::Point(26, 525);
			this->labelYearDma->Name = L"labelYearDma";
			this->labelYearDma->Size = System::Drawing::Size(50, 18);
			this->labelYearDma->TabIndex = 219;
			this->labelYearDma->Text = L"DMA:";
			// 
			// textBoxYearRocRocma
			// 
			this->textBoxYearRocRocma->Location = System::Drawing::Point(557, 427);
			this->textBoxYearRocRocma->Name = L"textBoxYearRocRocma";
			this->textBoxYearRocRocma->Size = System::Drawing::Size(124, 26);
			this->textBoxYearRocRocma->TabIndex = 218;
			this->textBoxYearRocRocma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearRocRocma_TextChanged);
			// 
			// textBoxYearRocRoc
			// 
			this->textBoxYearRocRoc->Location = System::Drawing::Point(353, 432);
			this->textBoxYearRocRoc->Name = L"textBoxYearRocRoc";
			this->textBoxYearRocRoc->Size = System::Drawing::Size(124, 26);
			this->textBoxYearRocRoc->TabIndex = 216;
			this->textBoxYearRocRoc->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearRocRoc_TextChanged);
			// 
			// labelYearRocRoc_ma
			// 
			this->labelYearRocRoc_ma->AutoSize = true;
			this->labelYearRocRoc_ma->Location = System::Drawing::Point(483, 435);
			this->labelYearRocRoc_ma->Name = L"labelYearRocRoc_ma";
			this->labelYearRocRoc_ma->Size = System::Drawing::Size(71, 18);
			this->labelYearRocRoc_ma->TabIndex = 217;
			this->labelYearRocRoc_ma->Text = L"Roc_ma:";
			// 
			// labelYearRocRoc
			// 
			this->labelYearRocRoc->AutoSize = true;
			this->labelYearRocRoc->Location = System::Drawing::Point(286, 439);
			this->labelYearRocRoc->Name = L"labelYearRocRoc";
			this->labelYearRocRoc->Size = System::Drawing::Size(39, 18);
			this->labelYearRocRoc->TabIndex = 215;
			this->labelYearRocRoc->Text = L"Roc:";
			// 
			// labelYearRocDir
			// 
			this->labelYearRocDir->AutoSize = true;
			this->labelYearRocDir->Location = System::Drawing::Point(87, 439);
			this->labelYearRocDir->Name = L"labelYearRocDir";
			this->labelYearRocDir->Size = System::Drawing::Size(77, 18);
			this->labelYearRocDir->TabIndex = 214;
			this->labelYearRocDir->Text = L"Direction:";
			// 
			// listBoxYearRocDir
			// 
			this->listBoxYearRocDir->FormattingEnabled = true;
			this->listBoxYearRocDir->ItemHeight = 18;
			this->listBoxYearRocDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearRocDir->Location = System::Drawing::Point(170, 435);
			this->listBoxYearRocDir->Name = L"listBoxYearRocDir";
			this->listBoxYearRocDir->Size = System::Drawing::Size(97, 22);
			this->listBoxYearRocDir->TabIndex = 213;
			this->listBoxYearRocDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearRocDir_SelectedIndexChanged);
			// 
			// labelYearRoc
			// 
			this->labelYearRoc->AutoSize = true;
			this->labelYearRoc->Location = System::Drawing::Point(26, 439);
			this->labelYearRoc->Name = L"labelYearRoc";
			this->labelYearRoc->Size = System::Drawing::Size(46, 18);
			this->labelYearRoc->TabIndex = 212;
			this->labelYearRoc->Text = L"ROC:";
			// 
			// textBoxYearVrLong
			// 
			this->textBoxYearVrLong->Location = System::Drawing::Point(557, 470);
			this->textBoxYearVrLong->Name = L"textBoxYearVrLong";
			this->textBoxYearVrLong->Size = System::Drawing::Size(124, 26);
			this->textBoxYearVrLong->TabIndex = 211;
			this->textBoxYearVrLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearVrLong_TextChanged);
			// 
			// textBoxYearVrShort
			// 
			this->textBoxYearVrShort->Location = System::Drawing::Point(353, 475);
			this->textBoxYearVrShort->Name = L"textBoxYearVrShort";
			this->textBoxYearVrShort->Size = System::Drawing::Size(124, 26);
			this->textBoxYearVrShort->TabIndex = 209;
			this->textBoxYearVrShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearVrShort_TextChanged);
			// 
			// labelYearVrLong
			// 
			this->labelYearVrLong->AutoSize = true;
			this->labelYearVrLong->Location = System::Drawing::Point(483, 478);
			this->labelYearVrLong->Name = L"labelYearVrLong";
			this->labelYearVrLong->Size = System::Drawing::Size(48, 18);
			this->labelYearVrLong->TabIndex = 210;
			this->labelYearVrLong->Text = L"Long:";
			// 
			// labelYearVrShort
			// 
			this->labelYearVrShort->AutoSize = true;
			this->labelYearVrShort->Location = System::Drawing::Point(281, 483);
			this->labelYearVrShort->Name = L"labelYearVrShort";
			this->labelYearVrShort->Size = System::Drawing::Size(52, 18);
			this->labelYearVrShort->TabIndex = 208;
			this->labelYearVrShort->Text = L"Short:";
			// 
			// labelYearVrDir
			// 
			this->labelYearVrDir->AutoSize = true;
			this->labelYearVrDir->Location = System::Drawing::Point(87, 482);
			this->labelYearVrDir->Name = L"labelYearVrDir";
			this->labelYearVrDir->Size = System::Drawing::Size(77, 18);
			this->labelYearVrDir->TabIndex = 207;
			this->labelYearVrDir->Text = L"Direction:";
			// 
			// listBoxYearVrDir
			// 
			this->listBoxYearVrDir->FormattingEnabled = true;
			this->listBoxYearVrDir->ItemHeight = 18;
			this->listBoxYearVrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearVrDir->Location = System::Drawing::Point(170, 478);
			this->listBoxYearVrDir->Name = L"listBoxYearVrDir";
			this->listBoxYearVrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxYearVrDir->TabIndex = 206;
			this->listBoxYearVrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearVrDir_SelectedIndexChanged);
			// 
			// labelYearVr
			// 
			this->labelYearVr->AutoSize = true;
			this->labelYearVr->Location = System::Drawing::Point(26, 482);
			this->labelYearVr->Name = L"labelYearVr";
			this->labelYearVr->Size = System::Drawing::Size(35, 18);
			this->labelYearVr->TabIndex = 205;
			this->labelYearVr->Text = L"VR:";
			// 
			// labelYearVolDir2
			// 
			this->labelYearVolDir2->AutoSize = true;
			this->labelYearVolDir2->Location = System::Drawing::Point(483, 154);
			this->labelYearVolDir2->Name = L"labelYearVolDir2";
			this->labelYearVolDir2->Size = System::Drawing::Size(86, 18);
			this->labelYearVolDir2->TabIndex = 204;
			this->labelYearVolDir2->Text = L"Direction2:";
			// 
			// listBoxYearVolDir2
			// 
			this->listBoxYearVolDir2->FormattingEnabled = true;
			this->listBoxYearVolDir2->ItemHeight = 18;
			this->listBoxYearVolDir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearVolDir2->Location = System::Drawing::Point(575, 151);
			this->listBoxYearVolDir2->Name = L"listBoxYearVolDir2";
			this->listBoxYearVolDir2->Size = System::Drawing::Size(106, 22);
			this->listBoxYearVolDir2->TabIndex = 203;
			this->listBoxYearVolDir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearVolDir2_SelectedIndexChanged);
			// 
			// textBoxYearVol2
			// 
			this->textBoxYearVol2->Location = System::Drawing::Point(759, 146);
			this->textBoxYearVol2->Name = L"textBoxYearVol2";
			this->textBoxYearVol2->Size = System::Drawing::Size(124, 26);
			this->textBoxYearVol2->TabIndex = 202;
			this->textBoxYearVol2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearVol2_TextChanged);
			// 
			// textBoxYearVol1
			// 
			this->textBoxYearVol1->Location = System::Drawing::Point(353, 151);
			this->textBoxYearVol1->Name = L"textBoxYearVol1";
			this->textBoxYearVol1->Size = System::Drawing::Size(124, 26);
			this->textBoxYearVol1->TabIndex = 200;
			this->textBoxYearVol1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearVol1_TextChanged);
			// 
			// labelYearVol2
			// 
			this->labelYearVol2->AutoSize = true;
			this->labelYearVol2->Location = System::Drawing::Point(695, 154);
			this->labelYearVol2->Name = L"labelYearVol2";
			this->labelYearVol2->Size = System::Drawing::Size(55, 18);
			this->labelYearVol2->TabIndex = 201;
			this->labelYearVol2->Text = L"VOL2:";
			// 
			// labelYearVol1
			// 
			this->labelYearVol1->AutoSize = true;
			this->labelYearVol1->Location = System::Drawing::Point(290, 156);
			this->labelYearVol1->Name = L"labelYearVol1";
			this->labelYearVol1->Size = System::Drawing::Size(54, 18);
			this->labelYearVol1->TabIndex = 199;
			this->labelYearVol1->Text = L"VOL1:";
			// 
			// labelYearVolDir1
			// 
			this->labelYearVolDir1->AutoSize = true;
			this->labelYearVolDir1->Location = System::Drawing::Point(79, 156);
			this->labelYearVolDir1->Name = L"labelYearVolDir1";
			this->labelYearVolDir1->Size = System::Drawing::Size(85, 18);
			this->labelYearVolDir1->TabIndex = 198;
			this->labelYearVolDir1->Text = L"Direction1:";
			// 
			// listBoxYearVolDir1
			// 
			this->listBoxYearVolDir1->FormattingEnabled = true;
			this->listBoxYearVolDir1->ItemHeight = 18;
			this->listBoxYearVolDir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearVolDir1->Location = System::Drawing::Point(170, 154);
			this->listBoxYearVolDir1->Name = L"listBoxYearVolDir1";
			this->listBoxYearVolDir1->Size = System::Drawing::Size(97, 22);
			this->listBoxYearVolDir1->TabIndex = 197;
			this->listBoxYearVolDir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearVolDir1_SelectedIndexChanged);
			// 
			// labelYearVol
			// 
			this->labelYearVol->AutoSize = true;
			this->labelYearVol->Location = System::Drawing::Point(26, 158);
			this->labelYearVol->Name = L"labelYearVol";
			this->labelYearVol->Size = System::Drawing::Size(46, 18);
			this->labelYearVol->TabIndex = 196;
			this->labelYearVol->Text = L"VOL:";
			// 
			// textBoxYearWr2
			// 
			this->textBoxYearWr2->Location = System::Drawing::Point(557, 382);
			this->textBoxYearWr2->Name = L"textBoxYearWr2";
			this->textBoxYearWr2->Size = System::Drawing::Size(124, 26);
			this->textBoxYearWr2->TabIndex = 195;
			this->textBoxYearWr2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearWr2_TextChanged);
			// 
			// textBoxYearWr1
			// 
			this->textBoxYearWr1->Location = System::Drawing::Point(353, 387);
			this->textBoxYearWr1->Name = L"textBoxYearWr1";
			this->textBoxYearWr1->Size = System::Drawing::Size(124, 26);
			this->textBoxYearWr1->TabIndex = 193;
			this->textBoxYearWr1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearWr1_TextChanged);
			// 
			// labelYearWr2
			// 
			this->labelYearWr2->AutoSize = true;
			this->labelYearWr2->Location = System::Drawing::Point(483, 390);
			this->labelYearWr2->Name = L"labelYearWr2";
			this->labelYearWr2->Size = System::Drawing::Size(48, 18);
			this->labelYearWr2->TabIndex = 194;
			this->labelYearWr2->Text = L"WR2:";
			// 
			// labelYearWr1
			// 
			this->labelYearWr1->AutoSize = true;
			this->labelYearWr1->Location = System::Drawing::Point(286, 394);
			this->labelYearWr1->Name = L"labelYearWr1";
			this->labelYearWr1->Size = System::Drawing::Size(47, 18);
			this->labelYearWr1->TabIndex = 192;
			this->labelYearWr1->Text = L"WR1:";
			// 
			// labelYearWrDir
			// 
			this->labelYearWrDir->AutoSize = true;
			this->labelYearWrDir->Location = System::Drawing::Point(87, 394);
			this->labelYearWrDir->Name = L"labelYearWrDir";
			this->labelYearWrDir->Size = System::Drawing::Size(77, 18);
			this->labelYearWrDir->TabIndex = 191;
			this->labelYearWrDir->Text = L"Direction:";
			// 
			// listBoxYearWrDir
			// 
			this->listBoxYearWrDir->FormattingEnabled = true;
			this->listBoxYearWrDir->ItemHeight = 18;
			this->listBoxYearWrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearWrDir->Location = System::Drawing::Point(170, 390);
			this->listBoxYearWrDir->Name = L"listBoxYearWrDir";
			this->listBoxYearWrDir->Size = System::Drawing::Size(97, 22);
			this->listBoxYearWrDir->TabIndex = 190;
			this->listBoxYearWrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearWrDir_SelectedIndexChanged);
			// 
			// labelYearWr
			// 
			this->labelYearWr->AutoSize = true;
			this->labelYearWr->Location = System::Drawing::Point(26, 394);
			this->labelYearWr->Name = L"labelYearWr";
			this->labelYearWr->Size = System::Drawing::Size(39, 18);
			this->labelYearWr->TabIndex = 189;
			this->labelYearWr->Text = L"WR:";
			// 
			// textBoxYearRsiLong
			// 
			this->textBoxYearRsiLong->Location = System::Drawing::Point(759, 335);
			this->textBoxYearRsiLong->Name = L"textBoxYearRsiLong";
			this->textBoxYearRsiLong->Size = System::Drawing::Size(124, 26);
			this->textBoxYearRsiLong->TabIndex = 188;
			this->textBoxYearRsiLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearRsiLong_TextChanged);
			// 
			// textBoxYearRsiMiddle
			// 
			this->textBoxYearRsiMiddle->Location = System::Drawing::Point(557, 335);
			this->textBoxYearRsiMiddle->Name = L"textBoxYearRsiMiddle";
			this->textBoxYearRsiMiddle->Size = System::Drawing::Size(124, 26);
			this->textBoxYearRsiMiddle->TabIndex = 186;
			this->textBoxYearRsiMiddle->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearRsiMiddle_TextChanged);
			// 
			// textBoxYearRsiShort
			// 
			this->textBoxYearRsiShort->Location = System::Drawing::Point(353, 340);
			this->textBoxYearRsiShort->Name = L"textBoxYearRsiShort";
			this->textBoxYearRsiShort->Size = System::Drawing::Size(124, 26);
			this->textBoxYearRsiShort->TabIndex = 184;
			this->textBoxYearRsiShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearRsiShort_TextChanged);
			// 
			// labelYearRsiLong
			// 
			this->labelYearRsiLong->AutoSize = true;
			this->labelYearRsiLong->Location = System::Drawing::Point(695, 340);
			this->labelYearRsiLong->Name = L"labelYearRsiLong";
			this->labelYearRsiLong->Size = System::Drawing::Size(48, 18);
			this->labelYearRsiLong->TabIndex = 187;
			this->labelYearRsiLong->Text = L"Long:";
			// 
			// labelYearRsiMiddle
			// 
			this->labelYearRsiMiddle->AutoSize = true;
			this->labelYearRsiMiddle->Location = System::Drawing::Point(483, 343);
			this->labelYearRsiMiddle->Name = L"labelYearRsiMiddle";
			this->labelYearRsiMiddle->Size = System::Drawing::Size(62, 18);
			this->labelYearRsiMiddle->TabIndex = 185;
			this->labelYearRsiMiddle->Text = L"Middle:";
			// 
			// labelYearRsiShort
			// 
			this->labelYearRsiShort->AutoSize = true;
			this->labelYearRsiShort->Location = System::Drawing::Point(286, 347);
			this->labelYearRsiShort->Name = L"labelYearRsiShort";
			this->labelYearRsiShort->Size = System::Drawing::Size(52, 18);
			this->labelYearRsiShort->TabIndex = 183;
			this->labelYearRsiShort->Text = L"Short:";
			// 
			// labelYearRsiDir
			// 
			this->labelYearRsiDir->AutoSize = true;
			this->labelYearRsiDir->Location = System::Drawing::Point(87, 347);
			this->labelYearRsiDir->Name = L"labelYearRsiDir";
			this->labelYearRsiDir->Size = System::Drawing::Size(77, 18);
			this->labelYearRsiDir->TabIndex = 182;
			this->labelYearRsiDir->Text = L"Direction:";
			// 
			// listBoxYearRsiDir
			// 
			this->listBoxYearRsiDir->FormattingEnabled = true;
			this->listBoxYearRsiDir->ItemHeight = 18;
			this->listBoxYearRsiDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearRsiDir->Location = System::Drawing::Point(170, 343);
			this->listBoxYearRsiDir->Name = L"listBoxYearRsiDir";
			this->listBoxYearRsiDir->Size = System::Drawing::Size(97, 22);
			this->listBoxYearRsiDir->TabIndex = 181;
			this->listBoxYearRsiDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearRsiDir_SelectedIndexChanged);
			// 
			// labelYearRsi
			// 
			this->labelYearRsi->AutoSize = true;
			this->labelYearRsi->Location = System::Drawing::Point(26, 347);
			this->labelYearRsi->Name = L"labelYearRsi";
			this->labelYearRsi->Size = System::Drawing::Size(40, 18);
			this->labelYearRsi->TabIndex = 180;
			this->labelYearRsi->Text = L"RSI:";
			// 
			// textBoxYearKdjJ
			// 
			this->textBoxYearKdjJ->Location = System::Drawing::Point(759, 290);
			this->textBoxYearKdjJ->Name = L"textBoxYearKdjJ";
			this->textBoxYearKdjJ->Size = System::Drawing::Size(124, 26);
			this->textBoxYearKdjJ->TabIndex = 179;
			this->textBoxYearKdjJ->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearKdjJ_TextChanged);
			// 
			// textBoxYearKdjD
			// 
			this->textBoxYearKdjD->Location = System::Drawing::Point(557, 290);
			this->textBoxYearKdjD->Name = L"textBoxYearKdjD";
			this->textBoxYearKdjD->Size = System::Drawing::Size(124, 26);
			this->textBoxYearKdjD->TabIndex = 177;
			this->textBoxYearKdjD->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearKdjD_TextChanged);
			// 
			// textBoxYearKdjK
			// 
			this->textBoxYearKdjK->Location = System::Drawing::Point(353, 295);
			this->textBoxYearKdjK->Name = L"textBoxYearKdjK";
			this->textBoxYearKdjK->Size = System::Drawing::Size(124, 26);
			this->textBoxYearKdjK->TabIndex = 175;
			this->textBoxYearKdjK->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearKdjK_TextChanged);
			// 
			// labelYearKdjJ
			// 
			this->labelYearKdjJ->AutoSize = true;
			this->labelYearKdjJ->Location = System::Drawing::Point(695, 298);
			this->labelYearKdjJ->Name = L"labelYearKdjJ";
			this->labelYearKdjJ->Size = System::Drawing::Size(21, 18);
			this->labelYearKdjJ->TabIndex = 178;
			this->labelYearKdjJ->Text = L"J:";
			// 
			// labelYearKdjD
			// 
			this->labelYearKdjD->AutoSize = true;
			this->labelYearKdjD->Location = System::Drawing::Point(500, 298);
			this->labelYearKdjD->Name = L"labelYearKdjD";
			this->labelYearKdjD->Size = System::Drawing::Size(24, 18);
			this->labelYearKdjD->TabIndex = 176;
			this->labelYearKdjD->Text = L"D:";
			// 
			// labelYearKdjK
			// 
			this->labelYearKdjK->AutoSize = true;
			this->labelYearKdjK->Location = System::Drawing::Point(290, 300);
			this->labelYearKdjK->Name = L"labelYearKdjK";
			this->labelYearKdjK->Size = System::Drawing::Size(24, 18);
			this->labelYearKdjK->TabIndex = 174;
			this->labelYearKdjK->Text = L"K:";
			// 
			// labelYearKdjDir
			// 
			this->labelYearKdjDir->AutoSize = true;
			this->labelYearKdjDir->Location = System::Drawing::Point(87, 302);
			this->labelYearKdjDir->Name = L"labelYearKdjDir";
			this->labelYearKdjDir->Size = System::Drawing::Size(77, 18);
			this->labelYearKdjDir->TabIndex = 173;
			this->labelYearKdjDir->Text = L"Direction:";
			// 
			// listBoxYearKdjDir
			// 
			this->listBoxYearKdjDir->FormattingEnabled = true;
			this->listBoxYearKdjDir->ItemHeight = 18;
			this->listBoxYearKdjDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearKdjDir->Location = System::Drawing::Point(170, 298);
			this->listBoxYearKdjDir->Name = L"listBoxYearKdjDir";
			this->listBoxYearKdjDir->Size = System::Drawing::Size(97, 22);
			this->listBoxYearKdjDir->TabIndex = 172;
			this->listBoxYearKdjDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearKdjDir_SelectedIndexChanged);
			// 
			// labelYearKdj
			// 
			this->labelYearKdj->AutoSize = true;
			this->labelYearKdj->Location = System::Drawing::Point(26, 302);
			this->labelYearKdj->Name = L"labelYearKdj";
			this->labelYearKdj->Size = System::Drawing::Size(43, 18);
			this->labelYearKdj->TabIndex = 171;
			this->labelYearKdj->Text = L"KDJ:";
			// 
			// textBoxYearMacdDea
			// 
			this->textBoxYearMacdDea->Location = System::Drawing::Point(759, 243);
			this->textBoxYearMacdDea->Name = L"textBoxYearMacdDea";
			this->textBoxYearMacdDea->Size = System::Drawing::Size(124, 26);
			this->textBoxYearMacdDea->TabIndex = 170;
			this->textBoxYearMacdDea->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearMacdDea_TextChanged);
			// 
			// textBoxYearMacdDif
			// 
			this->textBoxYearMacdDif->Location = System::Drawing::Point(557, 243);
			this->textBoxYearMacdDif->Name = L"textBoxYearMacdDif";
			this->textBoxYearMacdDif->Size = System::Drawing::Size(124, 26);
			this->textBoxYearMacdDif->TabIndex = 168;
			this->textBoxYearMacdDif->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearMacdDif_TextChanged);
			// 
			// textBoxYearMacdMacd
			// 
			this->textBoxYearMacdMacd->Location = System::Drawing::Point(353, 248);
			this->textBoxYearMacdMacd->Name = L"textBoxYearMacdMacd";
			this->textBoxYearMacdMacd->Size = System::Drawing::Size(124, 26);
			this->textBoxYearMacdMacd->TabIndex = 166;
			this->textBoxYearMacdMacd->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearMacdMacd_TextChanged);
			// 
			// labelYearMacdDea
			// 
			this->labelYearMacdDea->AutoSize = true;
			this->labelYearMacdDea->Location = System::Drawing::Point(695, 251);
			this->labelYearMacdDea->Name = L"labelYearMacdDea";
			this->labelYearMacdDea->Size = System::Drawing::Size(40, 18);
			this->labelYearMacdDea->TabIndex = 169;
			this->labelYearMacdDea->Text = L"Dea:";
			// 
			// labelYearMacdDif
			// 
			this->labelYearMacdDif->AutoSize = true;
			this->labelYearMacdDif->Location = System::Drawing::Point(500, 251);
			this->labelYearMacdDif->Name = L"labelYearMacdDif";
			this->labelYearMacdDif->Size = System::Drawing::Size(33, 18);
			this->labelYearMacdDif->TabIndex = 167;
			this->labelYearMacdDif->Text = L"Dif:";
			// 
			// labelYearMacdMacd
			// 
			this->labelYearMacdMacd->AutoSize = true;
			this->labelYearMacdMacd->Location = System::Drawing::Point(290, 253);
			this->labelYearMacdMacd->Name = L"labelYearMacdMacd";
			this->labelYearMacdMacd->Size = System::Drawing::Size(52, 18);
			this->labelYearMacdMacd->TabIndex = 165;
			this->labelYearMacdMacd->Text = L"Macd:";
			// 
			// labelYearMacdDir
			// 
			this->labelYearMacdDir->AutoSize = true;
			this->labelYearMacdDir->Location = System::Drawing::Point(87, 255);
			this->labelYearMacdDir->Name = L"labelYearMacdDir";
			this->labelYearMacdDir->Size = System::Drawing::Size(77, 18);
			this->labelYearMacdDir->TabIndex = 164;
			this->labelYearMacdDir->Text = L"Direction:";
			// 
			// listBoxYearMacdDir
			// 
			this->listBoxYearMacdDir->FormattingEnabled = true;
			this->listBoxYearMacdDir->ItemHeight = 18;
			this->listBoxYearMacdDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearMacdDir->Location = System::Drawing::Point(170, 251);
			this->listBoxYearMacdDir->Name = L"listBoxYearMacdDir";
			this->listBoxYearMacdDir->Size = System::Drawing::Size(97, 22);
			this->listBoxYearMacdDir->TabIndex = 163;
			this->listBoxYearMacdDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearMacdDir_SelectedIndexChanged);
			// 
			// labelYearMacd
			// 
			this->labelYearMacd->AutoSize = true;
			this->labelYearMacd->Location = System::Drawing::Point(26, 255);
			this->labelYearMacd->Name = L"labelYearMacd";
			this->labelYearMacd->Size = System::Drawing::Size(60, 18);
			this->labelYearMacd->TabIndex = 162;
			this->labelYearMacd->Text = L"MACD:";
			// 
			// textBoxYearBollUpper
			// 
			this->textBoxYearBollUpper->Location = System::Drawing::Point(759, 196);
			this->textBoxYearBollUpper->Name = L"textBoxYearBollUpper";
			this->textBoxYearBollUpper->Size = System::Drawing::Size(124, 26);
			this->textBoxYearBollUpper->TabIndex = 161;
			this->textBoxYearBollUpper->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearBollUpper_TextChanged);
			// 
			// textBoxYearBollMid
			// 
			this->textBoxYearBollMid->Location = System::Drawing::Point(557, 198);
			this->textBoxYearBollMid->Name = L"textBoxYearBollMid";
			this->textBoxYearBollMid->Size = System::Drawing::Size(124, 26);
			this->textBoxYearBollMid->TabIndex = 159;
			this->textBoxYearBollMid->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearBollMid_TextChanged);
			// 
			// textBoxYearBollLow
			// 
			this->textBoxYearBollLow->Location = System::Drawing::Point(353, 200);
			this->textBoxYearBollLow->Name = L"textBoxYearBollLow";
			this->textBoxYearBollLow->Size = System::Drawing::Size(124, 26);
			this->textBoxYearBollLow->TabIndex = 157;
			this->textBoxYearBollLow->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxYearBollLow_TextChanged);
			// 
			// labelYearBollUpper
			// 
			this->labelYearBollUpper->AutoSize = true;
			this->labelYearBollUpper->Location = System::Drawing::Point(695, 202);
			this->labelYearBollUpper->Name = L"labelYearBollUpper";
			this->labelYearBollUpper->Size = System::Drawing::Size(58, 18);
			this->labelYearBollUpper->TabIndex = 160;
			this->labelYearBollUpper->Text = L"Upper:";
			// 
			// labelYearBollMid
			// 
			this->labelYearBollMid->AutoSize = true;
			this->labelYearBollMid->Location = System::Drawing::Point(500, 204);
			this->labelYearBollMid->Name = L"labelYearBollMid";
			this->labelYearBollMid->Size = System::Drawing::Size(41, 18);
			this->labelYearBollMid->TabIndex = 158;
			this->labelYearBollMid->Text = L"Mid:";
			// 
			// labelYearBollLow
			// 
			this->labelYearBollLow->AutoSize = true;
			this->labelYearBollLow->Location = System::Drawing::Point(295, 206);
			this->labelYearBollLow->Name = L"labelYearBollLow";
			this->labelYearBollLow->Size = System::Drawing::Size(43, 18);
			this->labelYearBollLow->TabIndex = 156;
			this->labelYearBollLow->Text = L"Low:";
			// 
			// labelYearBollDir
			// 
			this->labelYearBollDir->AutoSize = true;
			this->labelYearBollDir->Location = System::Drawing::Point(87, 206);
			this->labelYearBollDir->Name = L"labelYearBollDir";
			this->labelYearBollDir->Size = System::Drawing::Size(77, 18);
			this->labelYearBollDir->TabIndex = 155;
			this->labelYearBollDir->Text = L"Direction:";
			// 
			// listBoxYearBollDir
			// 
			this->listBoxYearBollDir->FormattingEnabled = true;
			this->listBoxYearBollDir->ItemHeight = 18;
			this->listBoxYearBollDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBoxYearBollDir->Location = System::Drawing::Point(170, 204);
			this->listBoxYearBollDir->Name = L"listBoxYearBollDir";
			this->listBoxYearBollDir->Size = System::Drawing::Size(97, 22);
			this->listBoxYearBollDir->TabIndex = 154;
			this->listBoxYearBollDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBoxYearBollDir_SelectedIndexChanged);
			// 
			// labelYearBoll
			// 
			this->labelYearBoll->AutoSize = true;
			this->labelYearBoll->Location = System::Drawing::Point(26, 210);
			this->labelYearBoll->Name = L"labelYearBoll";
			this->labelYearBoll->Size = System::Drawing::Size(55, 18);
			this->labelYearBoll->TabIndex = 153;
			this->labelYearBoll->Text = L"BOLL:";
			// 
			// woperateParseTab
			// 
			this->woperateParseTab->Controls->Add(this->tabYear);
			this->woperateParseTab->Controls->Add(this->tabMonth);
			this->woperateParseTab->Controls->Add(this->tabWeek);
			this->woperateParseTab->Controls->Add(this->tabDay);
			this->woperateParseTab->Controls->Add(this->tab4Hour);
			this->woperateParseTab->Controls->Add(this->tabHour);
			this->woperateParseTab->Controls->Add(this->tab45Min);
			this->woperateParseTab->Controls->Add(this->tab30Min);
			this->woperateParseTab->Controls->Add(this->tab15Min);
			this->woperateParseTab->Controls->Add(this->tab10Min);
			this->woperateParseTab->Controls->Add(this->tab5Min);
			this->woperateParseTab->Location = System::Drawing::Point(0, 86);
			this->woperateParseTab->Multiline = true;
			this->woperateParseTab->Name = L"woperateParseTab";
			this->woperateParseTab->SelectedIndex = 0;
			this->woperateParseTab->Size = System::Drawing::Size(1100, 900);
			this->woperateParseTab->TabIndex = 1;
			// 
			// tab5Min
			// 
			this->tab5Min->Controls->Add(this->listBox5MinMADir6);
			this->tab5Min->Controls->Add(this->label5MinMADir6);
			this->tab5Min->Controls->Add(this->textBox5MinMA6);
			this->tab5Min->Controls->Add(this->textBox5MinMA5);
			this->tab5Min->Controls->Add(this->label5MinMA6);
			this->tab5Min->Controls->Add(this->label5MinMA5);
			this->tab5Min->Controls->Add(this->label5MinMADir5);
			this->tab5Min->Controls->Add(this->listBox5MinMADir5);
			this->tab5Min->Controls->Add(this->label5MinMA56);
			this->tab5Min->Controls->Add(this->label5MinMADir4);
			this->tab5Min->Controls->Add(this->listBox5MinMADir4);
			this->tab5Min->Controls->Add(this->textBox5MinMA4);
			this->tab5Min->Controls->Add(this->textBox5MinMA3);
			this->tab5Min->Controls->Add(this->label5MinMA4);
			this->tab5Min->Controls->Add(this->label5MinMA3);
			this->tab5Min->Controls->Add(this->label5MinMADir3);
			this->tab5Min->Controls->Add(this->listBox5MinMADir3);
			this->tab5Min->Controls->Add(this->label5MinMA34);
			this->tab5Min->Controls->Add(this->label5MinMADir2);
			this->tab5Min->Controls->Add(this->listBox5MinMADir2);
			this->tab5Min->Controls->Add(this->textBox5MinMA2);
			this->tab5Min->Controls->Add(this->textBox5MinMA1);
			this->tab5Min->Controls->Add(this->label5MinMA2);
			this->tab5Min->Controls->Add(this->label5MinMA1);
			this->tab5Min->Controls->Add(this->label5MinMADir1);
			this->tab5Min->Controls->Add(this->listBox5MinMADir1);
			this->tab5Min->Controls->Add(this->label5MinMA12);
			this->tab5Min->Controls->Add(this->textBox5MinCciCci);
			this->tab5Min->Controls->Add(this->label5MinCciCci);
			this->tab5Min->Controls->Add(this->label5MinCciDir);
			this->tab5Min->Controls->Add(this->listBox5MinCciDir);
			this->tab5Min->Controls->Add(this->label5MinCci);
			this->tab5Min->Controls->Add(this->textBox5MinCrC);
			this->tab5Min->Controls->Add(this->label5MinCrC);
			this->tab5Min->Controls->Add(this->textBox5MinCrB);
			this->tab5Min->Controls->Add(this->label5MinCrB);
			this->tab5Min->Controls->Add(this->textBox5MinCrA);
			this->tab5Min->Controls->Add(this->textBox5MinCrCr);
			this->tab5Min->Controls->Add(this->label5MinCrA);
			this->tab5Min->Controls->Add(this->label5MinCrCr);
			this->tab5Min->Controls->Add(this->label5MinCrDir);
			this->tab5Min->Controls->Add(this->listBox5MinCrDir);
			this->tab5Min->Controls->Add(this->label5MinCr);
			this->tab5Min->Controls->Add(this->textBox5MinDmaAma);
			this->tab5Min->Controls->Add(this->textBox5MinDmaDma);
			this->tab5Min->Controls->Add(this->label5MinDmaAma);
			this->tab5Min->Controls->Add(this->label5MinDmaDma);
			this->tab5Min->Controls->Add(this->label5MinDmaDir);
			this->tab5Min->Controls->Add(this->listBox5MinDmaDir);
			this->tab5Min->Controls->Add(this->label5MinDma);
			this->tab5Min->Controls->Add(this->textBox5MinRocRocma);
			this->tab5Min->Controls->Add(this->textBox5MinRocRoc);
			this->tab5Min->Controls->Add(this->label5MinRocRocma);
			this->tab5Min->Controls->Add(this->label5MinRocRoc);
			this->tab5Min->Controls->Add(this->label5MinRocDir);
			this->tab5Min->Controls->Add(this->listBox5MinRocDir);
			this->tab5Min->Controls->Add(this->label5MinRoc);
			this->tab5Min->Controls->Add(this->textBox5MinVrLong);
			this->tab5Min->Controls->Add(this->textBox5MinVrShort);
			this->tab5Min->Controls->Add(this->label5MinVrLong);
			this->tab5Min->Controls->Add(this->label5MinVrShort);
			this->tab5Min->Controls->Add(this->label5MinVrDir);
			this->tab5Min->Controls->Add(this->listBox5MinVrDir);
			this->tab5Min->Controls->Add(this->label5MinVr);
			this->tab5Min->Controls->Add(this->label5MinVolDir2);
			this->tab5Min->Controls->Add(this->listBox5MinVolDir2);
			this->tab5Min->Controls->Add(this->textBox5MinVol2);
			this->tab5Min->Controls->Add(this->textBox5MinVol1);
			this->tab5Min->Controls->Add(this->label5MinVol2);
			this->tab5Min->Controls->Add(this->label5MinVol1);
			this->tab5Min->Controls->Add(this->label5MinVolDir1);
			this->tab5Min->Controls->Add(this->listBox5MinVolDir1);
			this->tab5Min->Controls->Add(this->label5MinVol);
			this->tab5Min->Controls->Add(this->textBox5MinWr2);
			this->tab5Min->Controls->Add(this->textBox5MinWr1);
			this->tab5Min->Controls->Add(this->label5MinWr2);
			this->tab5Min->Controls->Add(this->label5MinWr1);
			this->tab5Min->Controls->Add(this->label5MinWrDir);
			this->tab5Min->Controls->Add(this->listBox5MinWrDir);
			this->tab5Min->Controls->Add(this->label5MinWr);
			this->tab5Min->Controls->Add(this->textBox5MinRsiLong);
			this->tab5Min->Controls->Add(this->textBox5MinRsiMiddle);
			this->tab5Min->Controls->Add(this->textBox5MinRsiShort);
			this->tab5Min->Controls->Add(this->label5MinRsiLong);
			this->tab5Min->Controls->Add(this->label5MinRsiMiddle);
			this->tab5Min->Controls->Add(this->label5MinRsiShort);
			this->tab5Min->Controls->Add(this->label5MinRsiDir);
			this->tab5Min->Controls->Add(this->listBox5MinRsiDir);
			this->tab5Min->Controls->Add(this->label5MinRsi);
			this->tab5Min->Controls->Add(this->textBox5MinKdjJ);
			this->tab5Min->Controls->Add(this->textBox5MinKdjD);
			this->tab5Min->Controls->Add(this->textBox5MinKdjK);
			this->tab5Min->Controls->Add(this->label5MinKdjJ);
			this->tab5Min->Controls->Add(this->label5MinKdjD);
			this->tab5Min->Controls->Add(this->label5MinKdjK);
			this->tab5Min->Controls->Add(this->label5MinKdjDir);
			this->tab5Min->Controls->Add(this->listBox5MinKdjDir);
			this->tab5Min->Controls->Add(this->label5MinKdj);
			this->tab5Min->Controls->Add(this->textBox5MinMacdDea);
			this->tab5Min->Controls->Add(this->textBox5MinMacdDif);
			this->tab5Min->Controls->Add(this->textBox5MinMacdMacd);
			this->tab5Min->Controls->Add(this->label5MinMacdDea);
			this->tab5Min->Controls->Add(this->label5MinMacdDif);
			this->tab5Min->Controls->Add(this->label5MinMacdMacd);
			this->tab5Min->Controls->Add(this->label5MinMacdDir);
			this->tab5Min->Controls->Add(this->listBox5MinMacdDir);
			this->tab5Min->Controls->Add(this->label5MinMacd);
			this->tab5Min->Controls->Add(this->textBox5MinBollUpper);
			this->tab5Min->Controls->Add(this->textBox5MinBollMid);
			this->tab5Min->Controls->Add(this->textBox5MinBollLow);
			this->tab5Min->Controls->Add(this->label5MinBollUpper);
			this->tab5Min->Controls->Add(this->label5MinBollMid);
			this->tab5Min->Controls->Add(this->label5MinBollLow);
			this->tab5Min->Controls->Add(this->label5MinBollDir);
			this->tab5Min->Controls->Add(this->listBox5MinBollDir);
			this->tab5Min->Controls->Add(this->label5MinBoll);
			this->tab5Min->Location = System::Drawing::Point(4, 27);
			this->tab5Min->Name = L"tab5Min";
			this->tab5Min->Padding = System::Windows::Forms::Padding(3);
			this->tab5Min->Size = System::Drawing::Size(1092, 869);
			this->tab5Min->TabIndex = 12;
			this->tab5Min->Text = L"5Min";
			this->tab5Min->UseVisualStyleBackColor = true;
			// 
			// listBox5MinMADir6
			// 
			this->listBox5MinMADir6->FormattingEnabled = true;
			this->listBox5MinMADir6->ItemHeight = 18;
			this->listBox5MinMADir6->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinMADir6->Location = System::Drawing::Point(575, 103);
			this->listBox5MinMADir6->Name = L"listBox5MinMADir6";
			this->listBox5MinMADir6->Size = System::Drawing::Size(106, 22);
			this->listBox5MinMADir6->TabIndex = 385;
			this->listBox5MinMADir6->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinMADir6_SelectedIndexChanged);
			// 
			// label5MinMADir6
			// 
			this->label5MinMADir6->AutoSize = true;
			this->label5MinMADir6->Location = System::Drawing::Point(483, 107);
			this->label5MinMADir6->Name = L"label5MinMADir6";
			this->label5MinMADir6->Size = System::Drawing::Size(80, 18);
			this->label5MinMADir6->TabIndex = 384;
			this->label5MinMADir6->Text = L"MA_Dir6:";
			// 
			// textBox5MinMA6
			// 
			this->textBox5MinMA6->Location = System::Drawing::Point(759, 99);
			this->textBox5MinMA6->Name = L"textBox5MinMA6";
			this->textBox5MinMA6->Size = System::Drawing::Size(124, 26);
			this->textBox5MinMA6->TabIndex = 382;
			this->textBox5MinMA6->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinMA6_TextChanged);
			// 
			// textBox5MinMA5
			// 
			this->textBox5MinMA5->Location = System::Drawing::Point(353, 104);
			this->textBox5MinMA5->Name = L"textBox5MinMA5";
			this->textBox5MinMA5->Size = System::Drawing::Size(124, 26);
			this->textBox5MinMA5->TabIndex = 380;
			this->textBox5MinMA5->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinMA5_TextChanged);
			// 
			// label5MinMA6
			// 
			this->label5MinMA6->AutoSize = true;
			this->label5MinMA6->Location = System::Drawing::Point(695, 107);
			this->label5MinMA6->Name = L"label5MinMA6";
			this->label5MinMA6->Size = System::Drawing::Size(48, 18);
			this->label5MinMA6->TabIndex = 381;
			this->label5MinMA6->Text = L"MA6:";
			// 
			// label5MinMA5
			// 
			this->label5MinMA5->AutoSize = true;
			this->label5MinMA5->Location = System::Drawing::Point(290, 109);
			this->label5MinMA5->Name = L"label5MinMA5";
			this->label5MinMA5->Size = System::Drawing::Size(48, 18);
			this->label5MinMA5->TabIndex = 379;
			this->label5MinMA5->Text = L"MA5:";
			// 
			// label5MinMADir5
			// 
			this->label5MinMADir5->AutoSize = true;
			this->label5MinMADir5->Location = System::Drawing::Point(79, 112);
			this->label5MinMADir5->Name = L"label5MinMADir5";
			this->label5MinMADir5->Size = System::Drawing::Size(80, 18);
			this->label5MinMADir5->TabIndex = 378;
			this->label5MinMADir5->Text = L"MA_Dir5:";
			// 
			// listBox5MinMADir5
			// 
			this->listBox5MinMADir5->FormattingEnabled = true;
			this->listBox5MinMADir5->ItemHeight = 18;
			this->listBox5MinMADir5->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinMADir5->Location = System::Drawing::Point(170, 107);
			this->listBox5MinMADir5->Name = L"listBox5MinMADir5";
			this->listBox5MinMADir5->Size = System::Drawing::Size(97, 22);
			this->listBox5MinMADir5->TabIndex = 377;
			this->listBox5MinMADir5->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinMADir5_SelectedIndexChanged);
			// 
			// label5MinMA56
			// 
			this->label5MinMA56->AutoSize = true;
			this->label5MinMA56->Location = System::Drawing::Point(17, 112);
			this->label5MinMA56->Name = L"label5MinMA56";
			this->label5MinMA56->Size = System::Drawing::Size(64, 18);
			this->label5MinMA56->TabIndex = 376;
			this->label5MinMA56->Text = L"MA5-6:";
			// 
			// label5MinMADir4
			// 
			this->label5MinMADir4->AutoSize = true;
			this->label5MinMADir4->Location = System::Drawing::Point(483, 60);
			this->label5MinMADir4->Name = L"label5MinMADir4";
			this->label5MinMADir4->Size = System::Drawing::Size(80, 18);
			this->label5MinMADir4->TabIndex = 375;
			this->label5MinMADir4->Text = L"MA_Dir4:";
			// 
			// listBox5MinMADir4
			// 
			this->listBox5MinMADir4->FormattingEnabled = true;
			this->listBox5MinMADir4->ItemHeight = 18;
			this->listBox5MinMADir4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinMADir4->Location = System::Drawing::Point(575, 57);
			this->listBox5MinMADir4->Name = L"listBox5MinMADir4";
			this->listBox5MinMADir4->Size = System::Drawing::Size(106, 22);
			this->listBox5MinMADir4->TabIndex = 374;
			this->listBox5MinMADir4->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinMADir4_SelectedIndexChanged);
			// 
			// textBox5MinMA4
			// 
			this->textBox5MinMA4->Location = System::Drawing::Point(759, 52);
			this->textBox5MinMA4->Name = L"textBox5MinMA4";
			this->textBox5MinMA4->Size = System::Drawing::Size(124, 26);
			this->textBox5MinMA4->TabIndex = 373;
			this->textBox5MinMA4->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinMA4_TextChanged);
			// 
			// textBox5MinMA3
			// 
			this->textBox5MinMA3->Location = System::Drawing::Point(353, 57);
			this->textBox5MinMA3->Name = L"textBox5MinMA3";
			this->textBox5MinMA3->Size = System::Drawing::Size(124, 26);
			this->textBox5MinMA3->TabIndex = 371;
			this->textBox5MinMA3->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinMA3_TextChanged);
			// 
			// label5MinMA4
			// 
			this->label5MinMA4->AutoSize = true;
			this->label5MinMA4->Location = System::Drawing::Point(695, 60);
			this->label5MinMA4->Name = L"label5MinMA4";
			this->label5MinMA4->Size = System::Drawing::Size(48, 18);
			this->label5MinMA4->TabIndex = 372;
			this->label5MinMA4->Text = L"MA4:";
			// 
			// label5MinMA3
			// 
			this->label5MinMA3->AutoSize = true;
			this->label5MinMA3->Location = System::Drawing::Point(290, 62);
			this->label5MinMA3->Name = L"label5MinMA3";
			this->label5MinMA3->Size = System::Drawing::Size(48, 18);
			this->label5MinMA3->TabIndex = 370;
			this->label5MinMA3->Text = L"MA3:";
			// 
			// label5MinMADir3
			// 
			this->label5MinMADir3->AutoSize = true;
			this->label5MinMADir3->Location = System::Drawing::Point(79, 65);
			this->label5MinMADir3->Name = L"label5MinMADir3";
			this->label5MinMADir3->Size = System::Drawing::Size(80, 18);
			this->label5MinMADir3->TabIndex = 369;
			this->label5MinMADir3->Text = L"MA_Dir3:";
			// 
			// listBox5MinMADir3
			// 
			this->listBox5MinMADir3->FormattingEnabled = true;
			this->listBox5MinMADir3->ItemHeight = 18;
			this->listBox5MinMADir3->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinMADir3->Location = System::Drawing::Point(170, 60);
			this->listBox5MinMADir3->Name = L"listBox5MinMADir3";
			this->listBox5MinMADir3->Size = System::Drawing::Size(97, 22);
			this->listBox5MinMADir3->TabIndex = 368;
			this->listBox5MinMADir3->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinMADir3_SelectedIndexChanged);
			// 
			// label5MinMA34
			// 
			this->label5MinMA34->AutoSize = true;
			this->label5MinMA34->Location = System::Drawing::Point(17, 65);
			this->label5MinMA34->Name = L"label5MinMA34";
			this->label5MinMA34->Size = System::Drawing::Size(64, 18);
			this->label5MinMA34->TabIndex = 367;
			this->label5MinMA34->Text = L"MA3-4:";
			// 
			// label5MinMADir2
			// 
			this->label5MinMADir2->AutoSize = true;
			this->label5MinMADir2->Location = System::Drawing::Point(483, 19);
			this->label5MinMADir2->Name = L"label5MinMADir2";
			this->label5MinMADir2->Size = System::Drawing::Size(80, 18);
			this->label5MinMADir2->TabIndex = 366;
			this->label5MinMADir2->Text = L"MA_Dir2:";
			// 
			// listBox5MinMADir2
			// 
			this->listBox5MinMADir2->FormattingEnabled = true;
			this->listBox5MinMADir2->ItemHeight = 18;
			this->listBox5MinMADir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinMADir2->Location = System::Drawing::Point(575, 16);
			this->listBox5MinMADir2->Name = L"listBox5MinMADir2";
			this->listBox5MinMADir2->Size = System::Drawing::Size(106, 22);
			this->listBox5MinMADir2->TabIndex = 365;
			this->listBox5MinMADir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinMADir2_SelectedIndexChanged);
			// 
			// textBox5MinMA2
			// 
			this->textBox5MinMA2->Location = System::Drawing::Point(759, 11);
			this->textBox5MinMA2->Name = L"textBox5MinMA2";
			this->textBox5MinMA2->Size = System::Drawing::Size(124, 26);
			this->textBox5MinMA2->TabIndex = 364;
			this->textBox5MinMA2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinMA2_TextChanged);
			// 
			// textBox5MinMA1
			// 
			this->textBox5MinMA1->Location = System::Drawing::Point(353, 16);
			this->textBox5MinMA1->Name = L"textBox5MinMA1";
			this->textBox5MinMA1->Size = System::Drawing::Size(124, 26);
			this->textBox5MinMA1->TabIndex = 362;
			this->textBox5MinMA1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinMA1_TextChanged);
			// 
			// label5MinMA2
			// 
			this->label5MinMA2->AutoSize = true;
			this->label5MinMA2->Location = System::Drawing::Point(695, 19);
			this->label5MinMA2->Name = L"label5MinMA2";
			this->label5MinMA2->Size = System::Drawing::Size(48, 18);
			this->label5MinMA2->TabIndex = 363;
			this->label5MinMA2->Text = L"MA2:";
			// 
			// label5MinMA1
			// 
			this->label5MinMA1->AutoSize = true;
			this->label5MinMA1->Location = System::Drawing::Point(290, 21);
			this->label5MinMA1->Name = L"label5MinMA1";
			this->label5MinMA1->Size = System::Drawing::Size(47, 18);
			this->label5MinMA1->TabIndex = 361;
			this->label5MinMA1->Text = L"MA1:";
			// 
			// label5MinMADir1
			// 
			this->label5MinMADir1->AutoSize = true;
			this->label5MinMADir1->Location = System::Drawing::Point(79, 21);
			this->label5MinMADir1->Name = L"label5MinMADir1";
			this->label5MinMADir1->Size = System::Drawing::Size(79, 18);
			this->label5MinMADir1->TabIndex = 360;
			this->label5MinMADir1->Text = L"MA_Dir1:";
			// 
			// listBox5MinMADir1
			// 
			this->listBox5MinMADir1->FormattingEnabled = true;
			this->listBox5MinMADir1->ItemHeight = 18;
			this->listBox5MinMADir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinMADir1->Location = System::Drawing::Point(170, 19);
			this->listBox5MinMADir1->Name = L"listBox5MinMADir1";
			this->listBox5MinMADir1->Size = System::Drawing::Size(97, 22);
			this->listBox5MinMADir1->TabIndex = 359;
			this->listBox5MinMADir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinMADir1_SelectedIndexChanged);
			// 
			// label5MinMA12
			// 
			this->label5MinMA12->AutoSize = true;
			this->label5MinMA12->Location = System::Drawing::Point(16, 24);
			this->label5MinMA12->Name = L"label5MinMA12";
			this->label5MinMA12->Size = System::Drawing::Size(63, 18);
			this->label5MinMA12->TabIndex = 358;
			this->label5MinMA12->Text = L"MA1-2:";
			// 
			// textBox5MinCciCci
			// 
			this->textBox5MinCciCci->Location = System::Drawing::Point(353, 601);
			this->textBox5MinCciCci->Name = L"textBox5MinCciCci";
			this->textBox5MinCciCci->Size = System::Drawing::Size(124, 26);
			this->textBox5MinCciCci->TabIndex = 357;
			this->textBox5MinCciCci->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinCciCci_TextChanged);
			// 
			// label5MinCciCci
			// 
			this->label5MinCciCci->AutoSize = true;
			this->label5MinCciCci->Location = System::Drawing::Point(286, 608);
			this->label5MinCciCci->Name = L"label5MinCciCci";
			this->label5MinCciCci->Size = System::Drawing::Size(34, 18);
			this->label5MinCciCci->TabIndex = 356;
			this->label5MinCciCci->Text = L"Cci:";
			// 
			// label5MinCciDir
			// 
			this->label5MinCciDir->AutoSize = true;
			this->label5MinCciDir->Location = System::Drawing::Point(87, 608);
			this->label5MinCciDir->Name = L"label5MinCciDir";
			this->label5MinCciDir->Size = System::Drawing::Size(77, 18);
			this->label5MinCciDir->TabIndex = 355;
			this->label5MinCciDir->Text = L"Direction:";
			// 
			// listBox5MinCciDir
			// 
			this->listBox5MinCciDir->FormattingEnabled = true;
			this->listBox5MinCciDir->ItemHeight = 18;
			this->listBox5MinCciDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinCciDir->Location = System::Drawing::Point(170, 604);
			this->listBox5MinCciDir->Name = L"listBox5MinCciDir";
			this->listBox5MinCciDir->Size = System::Drawing::Size(97, 22);
			this->listBox5MinCciDir->TabIndex = 354;
			this->listBox5MinCciDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinCciDir_SelectedIndexChanged);
			// 
			// label5MinCci
			// 
			this->label5MinCci->AutoSize = true;
			this->label5MinCci->Location = System::Drawing::Point(26, 608);
			this->label5MinCci->Name = L"label5MinCci";
			this->label5MinCci->Size = System::Drawing::Size(40, 18);
			this->label5MinCci->TabIndex = 353;
			this->label5MinCci->Text = L"CCI:";
			// 
			// textBox5MinCrC
			// 
			this->textBox5MinCrC->Location = System::Drawing::Point(961, 555);
			this->textBox5MinCrC->Name = L"textBox5MinCrC";
			this->textBox5MinCrC->Size = System::Drawing::Size(124, 26);
			this->textBox5MinCrC->TabIndex = 352;
			this->textBox5MinCrC->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinCrC_TextChanged);
			// 
			// label5MinCrC
			// 
			this->label5MinCrC->AutoSize = true;
			this->label5MinCrC->Location = System::Drawing::Point(900, 563);
			this->label5MinCrC->Name = L"label5MinCrC";
			this->label5MinCrC->Size = System::Drawing::Size(23, 18);
			this->label5MinCrC->TabIndex = 351;
			this->label5MinCrC->Text = L"C:";
			// 
			// textBox5MinCrB
			// 
			this->textBox5MinCrB->Location = System::Drawing::Point(755, 555);
			this->textBox5MinCrB->Name = L"textBox5MinCrB";
			this->textBox5MinCrB->Size = System::Drawing::Size(124, 26);
			this->textBox5MinCrB->TabIndex = 350;
			this->textBox5MinCrB->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinCrB_TextChanged);
			// 
			// label5MinCrB
			// 
			this->label5MinCrB->AutoSize = true;
			this->label5MinCrB->Location = System::Drawing::Point(694, 563);
			this->label5MinCrB->Name = L"label5MinCrB";
			this->label5MinCrB->Size = System::Drawing::Size(23, 18);
			this->label5MinCrB->TabIndex = 349;
			this->label5MinCrB->Text = L"B:";
			// 
			// textBox5MinCrA
			// 
			this->textBox5MinCrA->Location = System::Drawing::Point(557, 555);
			this->textBox5MinCrA->Name = L"textBox5MinCrA";
			this->textBox5MinCrA->Size = System::Drawing::Size(124, 26);
			this->textBox5MinCrA->TabIndex = 348;
			this->textBox5MinCrA->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinCrA_TextChanged);
			// 
			// textBox5MinCrCr
			// 
			this->textBox5MinCrCr->Location = System::Drawing::Point(353, 560);
			this->textBox5MinCrCr->Name = L"textBox5MinCrCr";
			this->textBox5MinCrCr->Size = System::Drawing::Size(124, 26);
			this->textBox5MinCrCr->TabIndex = 346;
			this->textBox5MinCrCr->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinCrCr_TextChanged);
			// 
			// label5MinCrA
			// 
			this->label5MinCrA->AutoSize = true;
			this->label5MinCrA->Location = System::Drawing::Point(496, 563);
			this->label5MinCrA->Name = L"label5MinCrA";
			this->label5MinCrA->Size = System::Drawing::Size(24, 18);
			this->label5MinCrA->TabIndex = 347;
			this->label5MinCrA->Text = L"A:";
			// 
			// label5MinCrCr
			// 
			this->label5MinCrCr->AutoSize = true;
			this->label5MinCrCr->Location = System::Drawing::Point(286, 567);
			this->label5MinCrCr->Name = L"label5MinCrCr";
			this->label5MinCrCr->Size = System::Drawing::Size(30, 18);
			this->label5MinCrCr->TabIndex = 345;
			this->label5MinCrCr->Text = L"Cr:";
			// 
			// label5MinCrDir
			// 
			this->label5MinCrDir->AutoSize = true;
			this->label5MinCrDir->Location = System::Drawing::Point(87, 567);
			this->label5MinCrDir->Name = L"label5MinCrDir";
			this->label5MinCrDir->Size = System::Drawing::Size(77, 18);
			this->label5MinCrDir->TabIndex = 344;
			this->label5MinCrDir->Text = L"Direction:";
			// 
			// listBox5MinCrDir
			// 
			this->listBox5MinCrDir->FormattingEnabled = true;
			this->listBox5MinCrDir->ItemHeight = 18;
			this->listBox5MinCrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinCrDir->Location = System::Drawing::Point(170, 563);
			this->listBox5MinCrDir->Name = L"listBox5MinCrDir";
			this->listBox5MinCrDir->Size = System::Drawing::Size(97, 22);
			this->listBox5MinCrDir->TabIndex = 343;
			this->listBox5MinCrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinCrDir_SelectedIndexChanged);
			// 
			// label5MinCr
			// 
			this->label5MinCr->AutoSize = true;
			this->label5MinCr->Location = System::Drawing::Point(26, 567);
			this->label5MinCr->Name = L"label5MinCr";
			this->label5MinCr->Size = System::Drawing::Size(34, 18);
			this->label5MinCr->TabIndex = 342;
			this->label5MinCr->Text = L"CR:";
			// 
			// textBox5MinDmaAma
			// 
			this->textBox5MinDmaAma->Location = System::Drawing::Point(557, 513);
			this->textBox5MinDmaAma->Name = L"textBox5MinDmaAma";
			this->textBox5MinDmaAma->Size = System::Drawing::Size(124, 26);
			this->textBox5MinDmaAma->TabIndex = 341;
			this->textBox5MinDmaAma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinDmaAma_TextChanged);
			// 
			// textBox5MinDmaDma
			// 
			this->textBox5MinDmaDma->Location = System::Drawing::Point(353, 518);
			this->textBox5MinDmaDma->Name = L"textBox5MinDmaDma";
			this->textBox5MinDmaDma->Size = System::Drawing::Size(124, 26);
			this->textBox5MinDmaDma->TabIndex = 339;
			this->textBox5MinDmaDma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinDmaDma_TextChanged);
			// 
			// label5MinDmaAma
			// 
			this->label5MinDmaAma->AutoSize = true;
			this->label5MinDmaAma->Location = System::Drawing::Point(483, 521);
			this->label5MinDmaAma->Name = L"label5MinDmaAma";
			this->label5MinDmaAma->Size = System::Drawing::Size(46, 18);
			this->label5MinDmaAma->TabIndex = 340;
			this->label5MinDmaAma->Text = L"Ama:";
			// 
			// label5MinDmaDma
			// 
			this->label5MinDmaDma->AutoSize = true;
			this->label5MinDmaDma->Location = System::Drawing::Point(286, 525);
			this->label5MinDmaDma->Name = L"label5MinDmaDma";
			this->label5MinDmaDma->Size = System::Drawing::Size(46, 18);
			this->label5MinDmaDma->TabIndex = 338;
			this->label5MinDmaDma->Text = L"Dma:";
			// 
			// label5MinDmaDir
			// 
			this->label5MinDmaDir->AutoSize = true;
			this->label5MinDmaDir->Location = System::Drawing::Point(87, 525);
			this->label5MinDmaDir->Name = L"label5MinDmaDir";
			this->label5MinDmaDir->Size = System::Drawing::Size(77, 18);
			this->label5MinDmaDir->TabIndex = 337;
			this->label5MinDmaDir->Text = L"Direction:";
			// 
			// listBox5MinDmaDir
			// 
			this->listBox5MinDmaDir->FormattingEnabled = true;
			this->listBox5MinDmaDir->ItemHeight = 18;
			this->listBox5MinDmaDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinDmaDir->Location = System::Drawing::Point(170, 521);
			this->listBox5MinDmaDir->Name = L"listBox5MinDmaDir";
			this->listBox5MinDmaDir->Size = System::Drawing::Size(97, 22);
			this->listBox5MinDmaDir->TabIndex = 336;
			this->listBox5MinDmaDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinDmaDir_SelectedIndexChanged);
			// 
			// label5MinDma
			// 
			this->label5MinDma->AutoSize = true;
			this->label5MinDma->Location = System::Drawing::Point(26, 525);
			this->label5MinDma->Name = L"label5MinDma";
			this->label5MinDma->Size = System::Drawing::Size(50, 18);
			this->label5MinDma->TabIndex = 335;
			this->label5MinDma->Text = L"DMA:";
			// 
			// textBox5MinRocRocma
			// 
			this->textBox5MinRocRocma->Location = System::Drawing::Point(557, 427);
			this->textBox5MinRocRocma->Name = L"textBox5MinRocRocma";
			this->textBox5MinRocRocma->Size = System::Drawing::Size(124, 26);
			this->textBox5MinRocRocma->TabIndex = 334;
			this->textBox5MinRocRocma->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinRocRocma_TextChanged);
			// 
			// textBox5MinRocRoc
			// 
			this->textBox5MinRocRoc->Location = System::Drawing::Point(353, 432);
			this->textBox5MinRocRoc->Name = L"textBox5MinRocRoc";
			this->textBox5MinRocRoc->Size = System::Drawing::Size(124, 26);
			this->textBox5MinRocRoc->TabIndex = 332;
			this->textBox5MinRocRoc->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinRocRoc_TextChanged);
			// 
			// label5MinRocRocma
			// 
			this->label5MinRocRocma->AutoSize = true;
			this->label5MinRocRocma->Location = System::Drawing::Point(483, 435);
			this->label5MinRocRocma->Name = L"label5MinRocRocma";
			this->label5MinRocRocma->Size = System::Drawing::Size(71, 18);
			this->label5MinRocRocma->TabIndex = 333;
			this->label5MinRocRocma->Text = L"Roc_ma:";
			// 
			// label5MinRocRoc
			// 
			this->label5MinRocRoc->AutoSize = true;
			this->label5MinRocRoc->Location = System::Drawing::Point(286, 439);
			this->label5MinRocRoc->Name = L"label5MinRocRoc";
			this->label5MinRocRoc->Size = System::Drawing::Size(39, 18);
			this->label5MinRocRoc->TabIndex = 331;
			this->label5MinRocRoc->Text = L"Roc:";
			// 
			// label5MinRocDir
			// 
			this->label5MinRocDir->AutoSize = true;
			this->label5MinRocDir->Location = System::Drawing::Point(87, 439);
			this->label5MinRocDir->Name = L"label5MinRocDir";
			this->label5MinRocDir->Size = System::Drawing::Size(77, 18);
			this->label5MinRocDir->TabIndex = 330;
			this->label5MinRocDir->Text = L"Direction:";
			// 
			// listBox5MinRocDir
			// 
			this->listBox5MinRocDir->FormattingEnabled = true;
			this->listBox5MinRocDir->ItemHeight = 18;
			this->listBox5MinRocDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinRocDir->Location = System::Drawing::Point(170, 435);
			this->listBox5MinRocDir->Name = L"listBox5MinRocDir";
			this->listBox5MinRocDir->Size = System::Drawing::Size(97, 22);
			this->listBox5MinRocDir->TabIndex = 329;
			this->listBox5MinRocDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinRocDir_SelectedIndexChanged);
			// 
			// label5MinRoc
			// 
			this->label5MinRoc->AutoSize = true;
			this->label5MinRoc->Location = System::Drawing::Point(26, 439);
			this->label5MinRoc->Name = L"label5MinRoc";
			this->label5MinRoc->Size = System::Drawing::Size(46, 18);
			this->label5MinRoc->TabIndex = 328;
			this->label5MinRoc->Text = L"ROC:";
			// 
			// textBox5MinVrLong
			// 
			this->textBox5MinVrLong->Location = System::Drawing::Point(557, 470);
			this->textBox5MinVrLong->Name = L"textBox5MinVrLong";
			this->textBox5MinVrLong->Size = System::Drawing::Size(124, 26);
			this->textBox5MinVrLong->TabIndex = 327;
			this->textBox5MinVrLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinVrLong_TextChanged);
			// 
			// textBox5MinVrShort
			// 
			this->textBox5MinVrShort->Location = System::Drawing::Point(353, 475);
			this->textBox5MinVrShort->Name = L"textBox5MinVrShort";
			this->textBox5MinVrShort->Size = System::Drawing::Size(124, 26);
			this->textBox5MinVrShort->TabIndex = 325;
			this->textBox5MinVrShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinVrShort_TextChanged);
			// 
			// label5MinVrLong
			// 
			this->label5MinVrLong->AutoSize = true;
			this->label5MinVrLong->Location = System::Drawing::Point(483, 478);
			this->label5MinVrLong->Name = L"label5MinVrLong";
			this->label5MinVrLong->Size = System::Drawing::Size(48, 18);
			this->label5MinVrLong->TabIndex = 326;
			this->label5MinVrLong->Text = L"Long:";
			// 
			// label5MinVrShort
			// 
			this->label5MinVrShort->AutoSize = true;
			this->label5MinVrShort->Location = System::Drawing::Point(281, 483);
			this->label5MinVrShort->Name = L"label5MinVrShort";
			this->label5MinVrShort->Size = System::Drawing::Size(52, 18);
			this->label5MinVrShort->TabIndex = 324;
			this->label5MinVrShort->Text = L"Short:";
			// 
			// label5MinVrDir
			// 
			this->label5MinVrDir->AutoSize = true;
			this->label5MinVrDir->Location = System::Drawing::Point(87, 482);
			this->label5MinVrDir->Name = L"label5MinVrDir";
			this->label5MinVrDir->Size = System::Drawing::Size(77, 18);
			this->label5MinVrDir->TabIndex = 323;
			this->label5MinVrDir->Text = L"Direction:";
			// 
			// listBox5MinVrDir
			// 
			this->listBox5MinVrDir->FormattingEnabled = true;
			this->listBox5MinVrDir->ItemHeight = 18;
			this->listBox5MinVrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinVrDir->Location = System::Drawing::Point(170, 478);
			this->listBox5MinVrDir->Name = L"listBox5MinVrDir";
			this->listBox5MinVrDir->Size = System::Drawing::Size(97, 22);
			this->listBox5MinVrDir->TabIndex = 322;
			this->listBox5MinVrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinVrDir_SelectedIndexChanged);
			// 
			// label5MinVr
			// 
			this->label5MinVr->AutoSize = true;
			this->label5MinVr->Location = System::Drawing::Point(26, 482);
			this->label5MinVr->Name = L"label5MinVr";
			this->label5MinVr->Size = System::Drawing::Size(35, 18);
			this->label5MinVr->TabIndex = 321;
			this->label5MinVr->Text = L"VR:";
			// 
			// label5MinVolDir2
			// 
			this->label5MinVolDir2->AutoSize = true;
			this->label5MinVolDir2->Location = System::Drawing::Point(483, 154);
			this->label5MinVolDir2->Name = L"label5MinVolDir2";
			this->label5MinVolDir2->Size = System::Drawing::Size(86, 18);
			this->label5MinVolDir2->TabIndex = 320;
			this->label5MinVolDir2->Text = L"Direction2:";
			// 
			// listBox5MinVolDir2
			// 
			this->listBox5MinVolDir2->FormattingEnabled = true;
			this->listBox5MinVolDir2->ItemHeight = 18;
			this->listBox5MinVolDir2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinVolDir2->Location = System::Drawing::Point(575, 151);
			this->listBox5MinVolDir2->Name = L"listBox5MinVolDir2";
			this->listBox5MinVolDir2->Size = System::Drawing::Size(106, 22);
			this->listBox5MinVolDir2->TabIndex = 319;
			this->listBox5MinVolDir2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinVolDir2_SelectedIndexChanged);
			// 
			// textBox5MinVol2
			// 
			this->textBox5MinVol2->Location = System::Drawing::Point(759, 146);
			this->textBox5MinVol2->Name = L"textBox5MinVol2";
			this->textBox5MinVol2->Size = System::Drawing::Size(124, 26);
			this->textBox5MinVol2->TabIndex = 318;
			this->textBox5MinVol2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinVol2_TextChanged);
			// 
			// textBox5MinVol1
			// 
			this->textBox5MinVol1->Location = System::Drawing::Point(353, 151);
			this->textBox5MinVol1->Name = L"textBox5MinVol1";
			this->textBox5MinVol1->Size = System::Drawing::Size(124, 26);
			this->textBox5MinVol1->TabIndex = 316;
			this->textBox5MinVol1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinVol1_TextChanged);
			// 
			// label5MinVol2
			// 
			this->label5MinVol2->AutoSize = true;
			this->label5MinVol2->Location = System::Drawing::Point(695, 154);
			this->label5MinVol2->Name = L"label5MinVol2";
			this->label5MinVol2->Size = System::Drawing::Size(55, 18);
			this->label5MinVol2->TabIndex = 317;
			this->label5MinVol2->Text = L"VOL2:";
			// 
			// label5MinVol1
			// 
			this->label5MinVol1->AutoSize = true;
			this->label5MinVol1->Location = System::Drawing::Point(290, 156);
			this->label5MinVol1->Name = L"label5MinVol1";
			this->label5MinVol1->Size = System::Drawing::Size(54, 18);
			this->label5MinVol1->TabIndex = 315;
			this->label5MinVol1->Text = L"VOL1:";
			// 
			// label5MinVolDir1
			// 
			this->label5MinVolDir1->AutoSize = true;
			this->label5MinVolDir1->Location = System::Drawing::Point(79, 156);
			this->label5MinVolDir1->Name = L"label5MinVolDir1";
			this->label5MinVolDir1->Size = System::Drawing::Size(85, 18);
			this->label5MinVolDir1->TabIndex = 314;
			this->label5MinVolDir1->Text = L"Direction1:";
			// 
			// listBox5MinVolDir1
			// 
			this->listBox5MinVolDir1->FormattingEnabled = true;
			this->listBox5MinVolDir1->ItemHeight = 18;
			this->listBox5MinVolDir1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinVolDir1->Location = System::Drawing::Point(170, 154);
			this->listBox5MinVolDir1->Name = L"listBox5MinVolDir1";
			this->listBox5MinVolDir1->Size = System::Drawing::Size(97, 22);
			this->listBox5MinVolDir1->TabIndex = 313;
			this->listBox5MinVolDir1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinVolDir_SelectedIndexChanged);
			// 
			// label5MinVol
			// 
			this->label5MinVol->AutoSize = true;
			this->label5MinVol->Location = System::Drawing::Point(26, 158);
			this->label5MinVol->Name = L"label5MinVol";
			this->label5MinVol->Size = System::Drawing::Size(46, 18);
			this->label5MinVol->TabIndex = 312;
			this->label5MinVol->Text = L"VOL:";
			// 
			// textBox5MinWr2
			// 
			this->textBox5MinWr2->Location = System::Drawing::Point(557, 382);
			this->textBox5MinWr2->Name = L"textBox5MinWr2";
			this->textBox5MinWr2->Size = System::Drawing::Size(124, 26);
			this->textBox5MinWr2->TabIndex = 311;
			this->textBox5MinWr2->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinWr2_TextChanged);
			// 
			// textBox5MinWr1
			// 
			this->textBox5MinWr1->Location = System::Drawing::Point(353, 387);
			this->textBox5MinWr1->Name = L"textBox5MinWr1";
			this->textBox5MinWr1->Size = System::Drawing::Size(124, 26);
			this->textBox5MinWr1->TabIndex = 309;
			this->textBox5MinWr1->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinWr1_TextChanged);
			// 
			// label5MinWr2
			// 
			this->label5MinWr2->AutoSize = true;
			this->label5MinWr2->Location = System::Drawing::Point(483, 390);
			this->label5MinWr2->Name = L"label5MinWr2";
			this->label5MinWr2->Size = System::Drawing::Size(48, 18);
			this->label5MinWr2->TabIndex = 310;
			this->label5MinWr2->Text = L"WR2:";
			// 
			// label5MinWr1
			// 
			this->label5MinWr1->AutoSize = true;
			this->label5MinWr1->Location = System::Drawing::Point(286, 394);
			this->label5MinWr1->Name = L"label5MinWr1";
			this->label5MinWr1->Size = System::Drawing::Size(47, 18);
			this->label5MinWr1->TabIndex = 308;
			this->label5MinWr1->Text = L"WR1:";
			// 
			// label5MinWrDir
			// 
			this->label5MinWrDir->AutoSize = true;
			this->label5MinWrDir->Location = System::Drawing::Point(87, 394);
			this->label5MinWrDir->Name = L"label5MinWrDir";
			this->label5MinWrDir->Size = System::Drawing::Size(77, 18);
			this->label5MinWrDir->TabIndex = 307;
			this->label5MinWrDir->Text = L"Direction:";
			// 
			// listBox5MinWrDir
			// 
			this->listBox5MinWrDir->FormattingEnabled = true;
			this->listBox5MinWrDir->ItemHeight = 18;
			this->listBox5MinWrDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinWrDir->Location = System::Drawing::Point(170, 390);
			this->listBox5MinWrDir->Name = L"listBox5MinWrDir";
			this->listBox5MinWrDir->Size = System::Drawing::Size(97, 22);
			this->listBox5MinWrDir->TabIndex = 306;
			this->listBox5MinWrDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinWrDir_SelectedIndexChanged);
			// 
			// label5MinWr
			// 
			this->label5MinWr->AutoSize = true;
			this->label5MinWr->Location = System::Drawing::Point(26, 394);
			this->label5MinWr->Name = L"label5MinWr";
			this->label5MinWr->Size = System::Drawing::Size(39, 18);
			this->label5MinWr->TabIndex = 305;
			this->label5MinWr->Text = L"WR:";
			// 
			// textBox5MinRsiLong
			// 
			this->textBox5MinRsiLong->Location = System::Drawing::Point(759, 335);
			this->textBox5MinRsiLong->Name = L"textBox5MinRsiLong";
			this->textBox5MinRsiLong->Size = System::Drawing::Size(124, 26);
			this->textBox5MinRsiLong->TabIndex = 304;
			this->textBox5MinRsiLong->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinRsiLong_TextChanged);
			// 
			// textBox5MinRsiMiddle
			// 
			this->textBox5MinRsiMiddle->Location = System::Drawing::Point(557, 335);
			this->textBox5MinRsiMiddle->Name = L"textBox5MinRsiMiddle";
			this->textBox5MinRsiMiddle->Size = System::Drawing::Size(124, 26);
			this->textBox5MinRsiMiddle->TabIndex = 302;
			this->textBox5MinRsiMiddle->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinRsiMiddle_TextChanged);
			// 
			// textBox5MinRsiShort
			// 
			this->textBox5MinRsiShort->Location = System::Drawing::Point(353, 340);
			this->textBox5MinRsiShort->Name = L"textBox5MinRsiShort";
			this->textBox5MinRsiShort->Size = System::Drawing::Size(124, 26);
			this->textBox5MinRsiShort->TabIndex = 300;
			this->textBox5MinRsiShort->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinRsiShort_TextChanged);
			// 
			// label5MinRsiLong
			// 
			this->label5MinRsiLong->AutoSize = true;
			this->label5MinRsiLong->Location = System::Drawing::Point(695, 340);
			this->label5MinRsiLong->Name = L"label5MinRsiLong";
			this->label5MinRsiLong->Size = System::Drawing::Size(48, 18);
			this->label5MinRsiLong->TabIndex = 303;
			this->label5MinRsiLong->Text = L"Long:";
			// 
			// label5MinRsiMiddle
			// 
			this->label5MinRsiMiddle->AutoSize = true;
			this->label5MinRsiMiddle->Location = System::Drawing::Point(483, 343);
			this->label5MinRsiMiddle->Name = L"label5MinRsiMiddle";
			this->label5MinRsiMiddle->Size = System::Drawing::Size(62, 18);
			this->label5MinRsiMiddle->TabIndex = 301;
			this->label5MinRsiMiddle->Text = L"Middle:";
			// 
			// label5MinRsiShort
			// 
			this->label5MinRsiShort->AutoSize = true;
			this->label5MinRsiShort->Location = System::Drawing::Point(286, 347);
			this->label5MinRsiShort->Name = L"label5MinRsiShort";
			this->label5MinRsiShort->Size = System::Drawing::Size(52, 18);
			this->label5MinRsiShort->TabIndex = 299;
			this->label5MinRsiShort->Text = L"Short:";
			// 
			// label5MinRsiDir
			// 
			this->label5MinRsiDir->AutoSize = true;
			this->label5MinRsiDir->Location = System::Drawing::Point(87, 347);
			this->label5MinRsiDir->Name = L"label5MinRsiDir";
			this->label5MinRsiDir->Size = System::Drawing::Size(77, 18);
			this->label5MinRsiDir->TabIndex = 298;
			this->label5MinRsiDir->Text = L"Direction:";
			// 
			// listBox5MinRsiDir
			// 
			this->listBox5MinRsiDir->FormattingEnabled = true;
			this->listBox5MinRsiDir->ItemHeight = 18;
			this->listBox5MinRsiDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinRsiDir->Location = System::Drawing::Point(170, 343);
			this->listBox5MinRsiDir->Name = L"listBox5MinRsiDir";
			this->listBox5MinRsiDir->Size = System::Drawing::Size(97, 22);
			this->listBox5MinRsiDir->TabIndex = 297;
			this->listBox5MinRsiDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinRsiDir_SelectedIndexChanged);
			// 
			// label5MinRsi
			// 
			this->label5MinRsi->AutoSize = true;
			this->label5MinRsi->Location = System::Drawing::Point(26, 347);
			this->label5MinRsi->Name = L"label5MinRsi";
			this->label5MinRsi->Size = System::Drawing::Size(40, 18);
			this->label5MinRsi->TabIndex = 296;
			this->label5MinRsi->Text = L"RSI:";
			// 
			// textBox5MinKdjJ
			// 
			this->textBox5MinKdjJ->Location = System::Drawing::Point(759, 290);
			this->textBox5MinKdjJ->Name = L"textBox5MinKdjJ";
			this->textBox5MinKdjJ->Size = System::Drawing::Size(124, 26);
			this->textBox5MinKdjJ->TabIndex = 295;
			this->textBox5MinKdjJ->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinKdjJ_TextChanged);
			// 
			// textBox5MinKdjD
			// 
			this->textBox5MinKdjD->Location = System::Drawing::Point(557, 290);
			this->textBox5MinKdjD->Name = L"textBox5MinKdjD";
			this->textBox5MinKdjD->Size = System::Drawing::Size(124, 26);
			this->textBox5MinKdjD->TabIndex = 293;
			this->textBox5MinKdjD->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinKdjD_TextChanged);
			// 
			// textBox5MinKdjK
			// 
			this->textBox5MinKdjK->Location = System::Drawing::Point(353, 295);
			this->textBox5MinKdjK->Name = L"textBox5MinKdjK";
			this->textBox5MinKdjK->Size = System::Drawing::Size(124, 26);
			this->textBox5MinKdjK->TabIndex = 291;
			this->textBox5MinKdjK->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinKdjK_TextChanged);
			// 
			// label5MinKdjJ
			// 
			this->label5MinKdjJ->AutoSize = true;
			this->label5MinKdjJ->Location = System::Drawing::Point(695, 298);
			this->label5MinKdjJ->Name = L"label5MinKdjJ";
			this->label5MinKdjJ->Size = System::Drawing::Size(21, 18);
			this->label5MinKdjJ->TabIndex = 294;
			this->label5MinKdjJ->Text = L"J:";
			// 
			// label5MinKdjD
			// 
			this->label5MinKdjD->AutoSize = true;
			this->label5MinKdjD->Location = System::Drawing::Point(500, 298);
			this->label5MinKdjD->Name = L"label5MinKdjD";
			this->label5MinKdjD->Size = System::Drawing::Size(24, 18);
			this->label5MinKdjD->TabIndex = 292;
			this->label5MinKdjD->Text = L"D:";
			// 
			// label5MinKdjK
			// 
			this->label5MinKdjK->AutoSize = true;
			this->label5MinKdjK->Location = System::Drawing::Point(290, 300);
			this->label5MinKdjK->Name = L"label5MinKdjK";
			this->label5MinKdjK->Size = System::Drawing::Size(24, 18);
			this->label5MinKdjK->TabIndex = 290;
			this->label5MinKdjK->Text = L"K:";
			// 
			// label5MinKdjDir
			// 
			this->label5MinKdjDir->AutoSize = true;
			this->label5MinKdjDir->Location = System::Drawing::Point(87, 302);
			this->label5MinKdjDir->Name = L"label5MinKdjDir";
			this->label5MinKdjDir->Size = System::Drawing::Size(77, 18);
			this->label5MinKdjDir->TabIndex = 289;
			this->label5MinKdjDir->Text = L"Direction:";
			// 
			// listBox5MinKdjDir
			// 
			this->listBox5MinKdjDir->FormattingEnabled = true;
			this->listBox5MinKdjDir->ItemHeight = 18;
			this->listBox5MinKdjDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinKdjDir->Location = System::Drawing::Point(170, 298);
			this->listBox5MinKdjDir->Name = L"listBox5MinKdjDir";
			this->listBox5MinKdjDir->Size = System::Drawing::Size(97, 22);
			this->listBox5MinKdjDir->TabIndex = 288;
			this->listBox5MinKdjDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinKdjDir_SelectedIndexChanged);
			// 
			// label5MinKdj
			// 
			this->label5MinKdj->AutoSize = true;
			this->label5MinKdj->Location = System::Drawing::Point(26, 302);
			this->label5MinKdj->Name = L"label5MinKdj";
			this->label5MinKdj->Size = System::Drawing::Size(43, 18);
			this->label5MinKdj->TabIndex = 287;
			this->label5MinKdj->Text = L"KDJ:";
			// 
			// textBox5MinMacdDea
			// 
			this->textBox5MinMacdDea->Location = System::Drawing::Point(759, 243);
			this->textBox5MinMacdDea->Name = L"textBox5MinMacdDea";
			this->textBox5MinMacdDea->Size = System::Drawing::Size(124, 26);
			this->textBox5MinMacdDea->TabIndex = 286;
			this->textBox5MinMacdDea->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinMacdDea_TextChanged);
			// 
			// textBox5MinMacdDif
			// 
			this->textBox5MinMacdDif->Location = System::Drawing::Point(557, 243);
			this->textBox5MinMacdDif->Name = L"textBox5MinMacdDif";
			this->textBox5MinMacdDif->Size = System::Drawing::Size(124, 26);
			this->textBox5MinMacdDif->TabIndex = 284;
			this->textBox5MinMacdDif->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinMacdDif_TextChanged);
			// 
			// textBox5MinMacdMacd
			// 
			this->textBox5MinMacdMacd->Location = System::Drawing::Point(353, 248);
			this->textBox5MinMacdMacd->Name = L"textBox5MinMacdMacd";
			this->textBox5MinMacdMacd->Size = System::Drawing::Size(124, 26);
			this->textBox5MinMacdMacd->TabIndex = 282;
			this->textBox5MinMacdMacd->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinMacdMacd_TextChanged);
			// 
			// label5MinMacdDea
			// 
			this->label5MinMacdDea->AutoSize = true;
			this->label5MinMacdDea->Location = System::Drawing::Point(695, 251);
			this->label5MinMacdDea->Name = L"label5MinMacdDea";
			this->label5MinMacdDea->Size = System::Drawing::Size(40, 18);
			this->label5MinMacdDea->TabIndex = 285;
			this->label5MinMacdDea->Text = L"Dea:";
			// 
			// label5MinMacdDif
			// 
			this->label5MinMacdDif->AutoSize = true;
			this->label5MinMacdDif->Location = System::Drawing::Point(500, 251);
			this->label5MinMacdDif->Name = L"label5MinMacdDif";
			this->label5MinMacdDif->Size = System::Drawing::Size(33, 18);
			this->label5MinMacdDif->TabIndex = 283;
			this->label5MinMacdDif->Text = L"Dif:";
			// 
			// label5MinMacdMacd
			// 
			this->label5MinMacdMacd->AutoSize = true;
			this->label5MinMacdMacd->Location = System::Drawing::Point(290, 253);
			this->label5MinMacdMacd->Name = L"label5MinMacdMacd";
			this->label5MinMacdMacd->Size = System::Drawing::Size(52, 18);
			this->label5MinMacdMacd->TabIndex = 281;
			this->label5MinMacdMacd->Text = L"Macd:";
			// 
			// label5MinMacdDir
			// 
			this->label5MinMacdDir->AutoSize = true;
			this->label5MinMacdDir->Location = System::Drawing::Point(87, 255);
			this->label5MinMacdDir->Name = L"label5MinMacdDir";
			this->label5MinMacdDir->Size = System::Drawing::Size(77, 18);
			this->label5MinMacdDir->TabIndex = 280;
			this->label5MinMacdDir->Text = L"Direction:";
			// 
			// listBox5MinMacdDir
			// 
			this->listBox5MinMacdDir->FormattingEnabled = true;
			this->listBox5MinMacdDir->ItemHeight = 18;
			this->listBox5MinMacdDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinMacdDir->Location = System::Drawing::Point(170, 251);
			this->listBox5MinMacdDir->Name = L"listBox5MinMacdDir";
			this->listBox5MinMacdDir->Size = System::Drawing::Size(97, 22);
			this->listBox5MinMacdDir->TabIndex = 279;
			this->listBox5MinMacdDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinMacdDir_SelectedIndexChanged);
			// 
			// label5MinMacd
			// 
			this->label5MinMacd->AutoSize = true;
			this->label5MinMacd->Location = System::Drawing::Point(26, 255);
			this->label5MinMacd->Name = L"label5MinMacd";
			this->label5MinMacd->Size = System::Drawing::Size(60, 18);
			this->label5MinMacd->TabIndex = 278;
			this->label5MinMacd->Text = L"MACD:";
			// 
			// textBox5MinBollUpper
			// 
			this->textBox5MinBollUpper->Location = System::Drawing::Point(759, 196);
			this->textBox5MinBollUpper->Name = L"textBox5MinBollUpper";
			this->textBox5MinBollUpper->Size = System::Drawing::Size(124, 26);
			this->textBox5MinBollUpper->TabIndex = 277;
			this->textBox5MinBollUpper->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinBollUpper_TextChanged);
			// 
			// textBox5MinBollMid
			// 
			this->textBox5MinBollMid->Location = System::Drawing::Point(557, 198);
			this->textBox5MinBollMid->Name = L"textBox5MinBollMid";
			this->textBox5MinBollMid->Size = System::Drawing::Size(124, 26);
			this->textBox5MinBollMid->TabIndex = 275;
			this->textBox5MinBollMid->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinBollMid_TextChanged);
			// 
			// textBox5MinBollLow
			// 
			this->textBox5MinBollLow->Location = System::Drawing::Point(353, 200);
			this->textBox5MinBollLow->Name = L"textBox5MinBollLow";
			this->textBox5MinBollLow->Size = System::Drawing::Size(124, 26);
			this->textBox5MinBollLow->TabIndex = 273;
			this->textBox5MinBollLow->TextChanged += gcnew System::EventHandler(this, &FormParse::textBox5MinBollLow_TextChanged);
			// 
			// label5MinBollUpper
			// 
			this->label5MinBollUpper->AutoSize = true;
			this->label5MinBollUpper->Location = System::Drawing::Point(695, 202);
			this->label5MinBollUpper->Name = L"label5MinBollUpper";
			this->label5MinBollUpper->Size = System::Drawing::Size(58, 18);
			this->label5MinBollUpper->TabIndex = 276;
			this->label5MinBollUpper->Text = L"Upper:";
			// 
			// label5MinBollMid
			// 
			this->label5MinBollMid->AutoSize = true;
			this->label5MinBollMid->Location = System::Drawing::Point(500, 204);
			this->label5MinBollMid->Name = L"label5MinBollMid";
			this->label5MinBollMid->Size = System::Drawing::Size(41, 18);
			this->label5MinBollMid->TabIndex = 274;
			this->label5MinBollMid->Text = L"Mid:";
			// 
			// label5MinBollLow
			// 
			this->label5MinBollLow->AutoSize = true;
			this->label5MinBollLow->Location = System::Drawing::Point(295, 206);
			this->label5MinBollLow->Name = L"label5MinBollLow";
			this->label5MinBollLow->Size = System::Drawing::Size(43, 18);
			this->label5MinBollLow->TabIndex = 272;
			this->label5MinBollLow->Text = L"Low:";
			// 
			// label5MinBollDir
			// 
			this->label5MinBollDir->AutoSize = true;
			this->label5MinBollDir->Location = System::Drawing::Point(87, 206);
			this->label5MinBollDir->Name = L"label5MinBollDir";
			this->label5MinBollDir->Size = System::Drawing::Size(77, 18);
			this->label5MinBollDir->TabIndex = 271;
			this->label5MinBollDir->Text = L"Direction:";
			// 
			// listBox5MinBollDir
			// 
			this->listBox5MinBollDir->FormattingEnabled = true;
			this->listBox5MinBollDir->ItemHeight = 18;
			this->listBox5MinBollDir->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"NONE", L"UPER", L"DOWN"});
			this->listBox5MinBollDir->Location = System::Drawing::Point(170, 204);
			this->listBox5MinBollDir->Name = L"listBox5MinBollDir";
			this->listBox5MinBollDir->Size = System::Drawing::Size(97, 22);
			this->listBox5MinBollDir->TabIndex = 270;
			this->listBox5MinBollDir->SelectedIndexChanged += gcnew System::EventHandler(this, &FormParse::listBox5MinBollDir_SelectedIndexChanged);
			// 
			// label5MinBoll
			// 
			this->label5MinBoll->AutoSize = true;
			this->label5MinBoll->Location = System::Drawing::Point(26, 210);
			this->label5MinBoll->Name = L"label5MinBoll";
			this->label5MinBoll->Size = System::Drawing::Size(55, 18);
			this->label5MinBoll->TabIndex = 269;
			this->label5MinBoll->Text = L"BOLL:";
			// 
			// labelObject
			// 
			this->labelObject->AutoSize = true;
			this->labelObject->Location = System::Drawing::Point(1, 43);
			this->labelObject->Name = L"labelObject";
			this->labelObject->Size = System::Drawing::Size(59, 18);
			this->labelObject->TabIndex = 4;
			this->labelObject->Text = L"Object:";
			// 
			// textBoxObject
			// 
			this->textBoxObject->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxObject->Location = System::Drawing::Point(82, 35);
			this->textBoxObject->Name = L"textBoxObject";
			this->textBoxObject->Size = System::Drawing::Size(185, 26);
			this->textBoxObject->TabIndex = 5;
			this->textBoxObject->TextChanged += gcnew System::EventHandler(this, &FormParse::textBoxObject_TextChanged);
			// 
			// buttonStart
			// 
			this->buttonStart->Location = System::Drawing::Point(654, 30);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(164, 31);
			this->buttonStart->TabIndex = 6;
			this->buttonStart->Text = L"Start";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &FormParse::buttonStart_Click);
			// 
			// FormParse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1072, 781);
			this->Controls->Add(this->buttonStart);
			this->Controls->Add(this->textBoxObject);
			this->Controls->Add(this->labelObject);
			this->Controls->Add(this->textBoxPrice);
			this->Controls->Add(this->labelPrice);
			this->Controls->Add(this->woperateParseTab);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"FormParse";
			this->Text = L"WoperateParse";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tab10Min->ResumeLayout(false);
			this->tab10Min->PerformLayout();
			this->tab15Min->ResumeLayout(false);
			this->tab15Min->PerformLayout();
			this->tab30Min->ResumeLayout(false);
			this->tab30Min->PerformLayout();
			this->tab45Min->ResumeLayout(false);
			this->tab45Min->PerformLayout();
			this->tabHour->ResumeLayout(false);
			this->tabHour->PerformLayout();
			this->tab4Hour->ResumeLayout(false);
			this->tab4Hour->PerformLayout();
			this->tabDay->ResumeLayout(false);
			this->tabDay->PerformLayout();
			this->tabWeek->ResumeLayout(false);
			this->tabWeek->PerformLayout();
			this->tabMonth->ResumeLayout(false);
			this->tabMonth->PerformLayout();
			this->tabYear->ResumeLayout(false);
			this->tabYear->PerformLayout();
			this->woperateParseTab->ResumeLayout(false);
			this->tab5Min->ResumeLayout(false);
			this->tab5Min->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonStart_Click(System::Object^  sender, System::EventArgs^  e) {
			/*//test code 
			 Int32 i;
			 Double	 d;
			 i= tabDataYear.ma_dir[5];
			 i=tabData5Min.vol_dir[1];
			 d=tabDataYear.ma[0];
			 d=tabData5Min.cci;
			 d=price;
			 System::Windows::Forms::MessageBox::Show(d.ToString());//test 
			*///test code 
			if(!this->textBoxObject->Text->Length)
			{
				System::Windows::Forms::MessageBox::Show("Error: Object empty!");
				return;
			}

			if(!this->textBoxPrice->Text->Length)
			{
				System::Windows::Forms::MessageBox::Show("Error: Price empty!");
				return;
			}
			system("del.bat");
			char txt[0x50];
			sprintf(txt,"%s.txt",object);
			//year,month,week,day,hour4,hour1,min45,min30,min15,min10,min5,
			tabDataYear.out(txt,object,price,"year");
			tabDataMonth.out(txt,object,price,"month");
			tabDataWeek.out(txt,object,price,"week");
			tabDataDay.out(txt,object,price,"day");
			tabData4Hour.out(txt,object,price,"hour4");
			tabDataHour.out(txt,object,price,"hour1");
			tabData45Min.out(txt,object,price,"min45");
			tabData30Min.out(txt,object,price,"min30");
			tabData15Min.out(txt,object,price,"min15");
			tabData10Min.out(txt,object,price,"min10");
			tabData5Min.out(txt,object,price,"min5");
			char cmd[0x200];
			sprintf(cmd,"parse.bat %s %s.ini  %s operate.log",object,object,txt);
			system(cmd);
			//System::Windows::Forms::MessageBox::Show("Open operate.log see parse result !");
		 }

	private: System::Void listBoxYearMADir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearMADir1->SelectedIndex==1)	tabDataYear.ma_dir[0]=1;
			 if(this->listBoxYearMADir1->SelectedIndex==2)	tabDataYear.ma_dir[0]=-1;	
		 }
	private: System::Void listBoxlMonthMA12Dir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBoxMonthMADir1->SelectedIndex==1)	tabDataMonth.ma_dir[0]=1;
			 if(this->listBoxMonthMADir1->SelectedIndex==2)	tabDataMonth.ma_dir[0]=-1;	
		 }
	private: System::Void listBoxWeekMADir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekMADir1->SelectedIndex==1)	tabDataWeek.ma_dir[0]=1;
			 if(this->listBoxWeekMADir1->SelectedIndex==2)	tabDataWeek.ma_dir[0]=-1;	
		 }
	private: System::Void listBoxDayMADir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayMADir1->SelectedIndex==1)	tabDataDay.ma_dir[0]=1;
			 if(this->listBoxDayMADir1->SelectedIndex==2)	tabDataDay.ma_dir[0]=-1;	
		 }
	private: System::Void listBox4HourMADir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourMADir1->SelectedIndex==1)	tabData4Hour.ma_dir[0]=1;
			 if(this->listBox4HourMADir1->SelectedIndex==2)	tabData4Hour.ma_dir[0]=-1;	
		 }
	private: System::Void listBoxHourMADir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {	
			 if(this->listBoxHourMADir1->SelectedIndex==1)	tabDataHour.ma_dir[0]=1;
			 if(this->listBoxHourMADir1->SelectedIndex==2)	tabDataHour.ma_dir[0]=-1;	
		 }
	private: System::Void listBox45MinMADir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinMADir1->SelectedIndex==1)	tabData45Min.ma_dir[0]=1;
			 if(this->listBox45MinMADir1->SelectedIndex==2)	tabData45Min.ma_dir[0]=-1;	
		 }
	private: System::Void listBox30MinMADir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinMADir1->SelectedIndex==1)	tabData30Min.ma_dir[0]=1;
			 if(this->listBox30MinMADir1->SelectedIndex==2)	tabData30Min.ma_dir[0]=-1;	
		 }
	private: System::Void listBox15MinMADir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinMADir1->SelectedIndex==1)	tabData15Min.ma_dir[0]=1;
			 if(this->listBox15MinMADir1->SelectedIndex==2)	tabData15Min.ma_dir[0]=-1;	
		 }
	private: System::Void listBox10MinMADir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinMADir1->SelectedIndex==1)	tabData10Min.ma_dir[0]=1;
			 if(this->listBox10MinMADir1->SelectedIndex==2)	tabData10Min.ma_dir[0]=-1;	
		 }
	private: System::Void listBox5MinMADir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinMADir1->SelectedIndex==1)	tabData5Min.ma_dir[0]=1;
			 if(this->listBox5MinMADir1->SelectedIndex==2)	tabData5Min.ma_dir[0]=-1;	
		 }
	private: System::Void listBoxYearMADir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearMADir2->SelectedIndex==1)	tabDataYear.ma_dir[1]=1;
			 if(this->listBoxYearMADir2->SelectedIndex==2)	tabDataYear.ma_dir[1]=-1;	
		 }
	private: System::Void listBoxMonthMADir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthMADir2->SelectedIndex==1)	tabDataMonth.ma_dir[1]=1;
			 if(this->listBoxMonthMADir2->SelectedIndex==2)	tabDataMonth.ma_dir[1]=-1;	
		 }
	private: System::Void listBoxWeekMADir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekMADir2->SelectedIndex==1)	tabDataWeek.ma_dir[1]=1;
			 if(this->listBoxWeekMADir2->SelectedIndex==2)	tabDataWeek.ma_dir[1]=-1;	
		 }
	private: System::Void listBoxDayMADir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayMADir2->SelectedIndex==1)	tabDataDay.ma_dir[1]=1;
			 if(this->listBoxDayMADir2->SelectedIndex==2)	tabDataDay.ma_dir[1]=-1;	
		 }
	private: System::Void listBox4HourMADir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourMADir2->SelectedIndex==1)	tabData4Hour.ma_dir[1]=1;
			 if(this->listBox4HourMADir2->SelectedIndex==2)	tabData4Hour.ma_dir[1]=-1;	
		 }
	private: System::Void listBoxHourMADir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourMADir2->SelectedIndex==1)	tabDataHour.ma_dir[1]=1;
			 if(this->listBoxHourMADir2->SelectedIndex==2)	tabDataHour.ma_dir[1]=-1;	
		 }
	private: System::Void listBox45MinMADir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinMADir2->SelectedIndex==1)	tabData45Min.ma_dir[1]=1;
			 if(this->listBox45MinMADir2->SelectedIndex==2)	tabData45Min.ma_dir[1]=-1;	
		 }
	private: System::Void listBox30MinMADir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinMADir2->SelectedIndex==1)	tabData30Min.ma_dir[1]=1;
			 if(this->listBox30MinMADir2->SelectedIndex==2)	tabData30Min.ma_dir[1]=-1;	
		 }
	private: System::Void listBox15MinMADir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinMADir2->SelectedIndex==1)	tabData15Min.ma_dir[1]=1;
			 if(this->listBox15MinMADir2->SelectedIndex==2)	tabData15Min.ma_dir[1]=-1;	
		 }
	private: System::Void listBox10MinMADir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinMADir2->SelectedIndex==1)	tabData10Min.ma_dir[1]=1;
			 if(this->listBox10MinMADir2->SelectedIndex==2)	tabData10Min.ma_dir[1]=-1;	
		 }
	private: System::Void listBox5MinMADir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinMADir2->SelectedIndex==1)	tabData5Min.ma_dir[1]=1;
			 if(this->listBox5MinMADir2->SelectedIndex==2)	tabData5Min.ma_dir[1]=-1;	
		 }
	private: System::Void listBoxYearMADir3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearMADir3->SelectedIndex==1)	tabDataYear.ma_dir[2]=1;
			 if(this->listBoxYearMADir3->SelectedIndex==2)	tabDataYear.ma_dir[2]=-1;	
		 }
	private: System::Void listBoxMonthMADir3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthMADir3->SelectedIndex==1)	tabDataMonth.ma_dir[2]=1;
			 if(this->listBoxMonthMADir3->SelectedIndex==2)	tabDataMonth.ma_dir[2]=-1;	
		 }
	private: System::Void listBoxWeekMADir3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekMADir3->SelectedIndex==1)	tabDataWeek.ma_dir[2]=1;
			 if(this->listBoxWeekMADir3->SelectedIndex==2)	tabDataWeek.ma_dir[2]=-1;	
		 }
	private: System::Void listBoxDayMADir3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayMADir3->SelectedIndex==1)	tabDataDay.ma_dir[2]=1;
			 if(this->listBoxDayMADir3->SelectedIndex==2)	tabDataDay.ma_dir[2]=-1;	
		 }
	private: System::Void listBox4HourMADir3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourMADir3->SelectedIndex==1)	tabData4Hour.ma_dir[2]=1;
			 if(this->listBox4HourMADir3->SelectedIndex==2)	tabData4Hour.ma_dir[2]=-1;	
		 }
	private: System::Void listBoxHourMADir3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourMADir3->SelectedIndex==1)	tabDataHour.ma_dir[2]=1;
			 if(this->listBoxHourMADir3->SelectedIndex==2)	tabDataHour.ma_dir[2]=-1;	
		 }
	private: System::Void listBox45MinMADir3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinMADir3->SelectedIndex==1)	tabData45Min.ma_dir[2]=1;
			 if(this->listBox45MinMADir3->SelectedIndex==2)	tabData45Min.ma_dir[2]=-1;	
		 }
	private: System::Void listBox30MinMADir3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinMADir3->SelectedIndex==1)	tabData30Min.ma_dir[2]=1;
			 if(this->listBox30MinMADir3->SelectedIndex==2)	tabData30Min.ma_dir[2]=-1;	
		 }
	private: System::Void listBox15MinMADir3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinMADir3->SelectedIndex==1)	tabData15Min.ma_dir[2]=1;
			 if(this->listBox15MinMADir3->SelectedIndex==2)	tabData15Min.ma_dir[2]=-1;	
		 }
	private: System::Void listBox10MinMADir3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinMADir3->SelectedIndex==1)	tabData10Min.ma_dir[2]=1;
			 if(this->listBox10MinMADir3->SelectedIndex==2)	tabData10Min.ma_dir[2]=-1;	
		 }
	private: System::Void listBox5MinMADir3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinMADir3->SelectedIndex==1)	tabData5Min.ma_dir[2]=1;
			 if(this->listBox5MinMADir3->SelectedIndex==2)	tabData5Min.ma_dir[2]=-1;	
		 }
	private: System::Void listBoxYearMADir4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearMADir4->SelectedIndex==1)	tabDataYear.ma_dir[3]=1;
			 if(this->listBoxYearMADir4->SelectedIndex==2)	tabDataYear.ma_dir[3]=-1;	
		 }
	private: System::Void listBoxMonthMADir4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthMADir4->SelectedIndex==1)	tabDataMonth.ma_dir[3]=1;
			 if(this->listBoxMonthMADir4->SelectedIndex==2)	tabDataMonth.ma_dir[3]=-1;	
		 }
	private: System::Void listBoxWeekMADir4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekMADir4->SelectedIndex==1)	tabDataWeek.ma_dir[3]=1;
			 if(this->listBoxWeekMADir4->SelectedIndex==2)	tabDataWeek.ma_dir[3]=-1;	
		 }
	private: System::Void listBoxDayMADir4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayMADir4->SelectedIndex==1)	tabDataDay.ma_dir[3]=1;
			 if(this->listBoxDayMADir4->SelectedIndex==2)	tabDataDay.ma_dir[3]=-1;	
		 }
	private: System::Void listBox4HourMADir4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourMADir4->SelectedIndex==1)	tabData4Hour.ma_dir[3]=1;
			 if(this->listBox4HourMADir4->SelectedIndex==2)	tabData4Hour.ma_dir[3]=-1;	
		 }
	private: System::Void listBoxHourMADir4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourMADir4->SelectedIndex==1)	tabDataHour.ma_dir[3]=1;
			 if(this->listBoxHourMADir4->SelectedIndex==2)	tabDataHour.ma_dir[3]=-1;	
		 }
	private: System::Void listBox45MinMADir4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinMADir4->SelectedIndex==1)	tabData45Min.ma_dir[3]=1;
			 if(this->listBox45MinMADir4->SelectedIndex==2)	tabData45Min.ma_dir[3]=-1;	
		 }
	private: System::Void listBox30MinMADir4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinMADir4->SelectedIndex==1)	tabData30Min.ma_dir[3]=1;
			 if(this->listBox30MinMADir4->SelectedIndex==2)	tabData30Min.ma_dir[3]=-1;	
		 }
	private: System::Void listBox15MinMADir4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinMADir4->SelectedIndex==1)	tabData15Min.ma_dir[3]=1;
			 if(this->listBox15MinMADir4->SelectedIndex==2)	tabData15Min.ma_dir[3]=-1;	
		 }
	private: System::Void listBox10MinMADir4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinMADir4->SelectedIndex==1)	tabData10Min.ma_dir[3]=1;
			 if(this->listBox10MinMADir4->SelectedIndex==2)	tabData10Min.ma_dir[3]=-1;	
		 }
	private: System::Void listBox5MinMADir4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinMADir4->SelectedIndex==1)	tabData5Min.ma_dir[3]=1;
			 if(this->listBox5MinMADir4->SelectedIndex==2)	tabData5Min.ma_dir[3]=-1;	
		 }
	private: System::Void listBoxYearMADir5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearMADir5->SelectedIndex==1)	tabDataYear.ma_dir[4]=1;
			 if(this->listBoxYearMADir5->SelectedIndex==2)	tabDataYear.ma_dir[4]=-1;	
		 }
	private: System::Void listBoxMonthMADir5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthMADir5->SelectedIndex==1)	tabDataMonth.ma_dir[4]=1;
			 if(this->listBoxMonthMADir5->SelectedIndex==2)	tabDataMonth.ma_dir[4]=-1;	
		 }
	private: System::Void listBoxWeekMADir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekMADir5->SelectedIndex==1)	tabDataWeek.ma_dir[4]=1;
			 if(this->listBoxWeekMADir5->SelectedIndex==2)	tabDataWeek.ma_dir[4]=-1;	
		 }
	private: System::Void listBoxDayMADir5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayMADir5->SelectedIndex==1)	tabDataDay.ma_dir[4]=1;
			 if(this->listBoxDayMADir5->SelectedIndex==2)	tabDataDay.ma_dir[4]=-1;	
		 }
	private: System::Void listBox4HourMADir5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourMADir5->SelectedIndex==1)	tabData4Hour.ma_dir[4]=1;
			 if(this->listBox4HourMADir5->SelectedIndex==2)	tabData4Hour.ma_dir[4]=-1;	
		 }
	private: System::Void listBoxHourMADir5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourMADir5->SelectedIndex==1)	tabDataHour.ma_dir[4]=1;
			 if(this->listBoxHourMADir5->SelectedIndex==2)	tabDataHour.ma_dir[4]=-1;	
		 }
	private: System::Void listBox45MinMADir5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinMADir5->SelectedIndex==1)	tabData45Min.ma_dir[4]=1;
			 if(this->listBox45MinMADir5->SelectedIndex==2)	tabData45Min.ma_dir[4]=-1;	
		 }
	private: System::Void listBox30MinMADir5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinMADir5->SelectedIndex==1)	tabData30Min.ma_dir[4]=1;
			 if(this->listBox30MinMADir5->SelectedIndex==2)	tabData30Min.ma_dir[4]=-1;	
		 }
	private: System::Void listBox15MinMADir5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinMADir5->SelectedIndex==1)	tabData15Min.ma_dir[4]=1;
			 if(this->listBox15MinMADir5->SelectedIndex==2)	tabData15Min.ma_dir[4]=-1;	
		 }
	private: System::Void listBox10MinMADir5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinMADir5->SelectedIndex==1)	tabData10Min.ma_dir[4]=1;
			 if(this->listBox10MinMADir5->SelectedIndex==2)	tabData10Min.ma_dir[4]=-1;	
		 }
	private: System::Void listBox5MinMADir5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinMADir5->SelectedIndex==1)	tabData5Min.ma_dir[4]=1;
			 if(this->listBox5MinMADir5->SelectedIndex==2)	tabData5Min.ma_dir[4]=-1;	
		}
	private: System::Void listBoxYearMADir6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearMADir6->SelectedIndex==1)	tabDataYear.ma_dir[5]=1;
			 if(this->listBoxYearMADir6->SelectedIndex==2)	tabDataYear.ma_dir[5]=-1;	
		 }
	private: System::Void listBoxMonthMADir6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthMADir6->SelectedIndex==1)	tabDataMonth.ma_dir[5]=1;
			 if(this->listBoxMonthMADir6->SelectedIndex==2)	tabDataMonth.ma_dir[5]=-1;	
		 }
	private: System::Void listBoxWeekMADir6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekMADir6->SelectedIndex==1)	tabDataWeek.ma_dir[5]=1;
			 if(this->listBoxWeekMADir6->SelectedIndex==2)	tabDataWeek.ma_dir[5]=-1;	
		 }
	private: System::Void listBoxDayMADir6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayMADir6->SelectedIndex==1)	tabDataDay.ma_dir[5]=1;
			 if(this->listBoxDayMADir6->SelectedIndex==2)	tabDataDay.ma_dir[5]=-1;	
		 }
	private: System::Void listBox4HourMADir6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourMADir6->SelectedIndex==1)	tabData4Hour.ma_dir[5]=1;
			 if(this->listBox4HourMADir6->SelectedIndex==2)	tabData4Hour.ma_dir[5]=-1;	
		 }
	private: System::Void listBoxHourMADir6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourMADir6->SelectedIndex==1)	tabDataHour.ma_dir[5]=1;
			 if(this->listBoxHourMADir6->SelectedIndex==2)	tabDataHour.ma_dir[5]=-1;	
		 }
	private: System::Void listBox45MinMADir6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinMADir6->SelectedIndex==1)	tabData45Min.ma_dir[5]=1;
			 if(this->listBox45MinMADir6->SelectedIndex==2)	tabData45Min.ma_dir[5]=-1;	
		 }
	private: System::Void listBox30MinMADir6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinMADir6->SelectedIndex==1)	tabData30Min.ma_dir[5]=1;
			 if(this->listBox30MinMADir6->SelectedIndex==2)	tabData30Min.ma_dir[5]=-1;	
		 }
	private: System::Void listBox15MinMADir6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinMADir6->SelectedIndex==1)	tabData15Min.ma_dir[5]=1;
			 if(this->listBox15MinMADir6->SelectedIndex==2)	tabData15Min.ma_dir[5]=-1;	
		 }
	private: System::Void listBox10MinMADir6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinMADir6->SelectedIndex==1)	tabData10Min.ma_dir[5]=1;
			 if(this->listBox10MinMADir6->SelectedIndex==2)	tabData10Min.ma_dir[5]=-1;	
		 }
	private: System::Void listBox5MinMADir6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinMADir6->SelectedIndex==1)	tabData5Min.ma_dir[5]=1;
			 if(this->listBox5MinMADir6->SelectedIndex==2)	tabData5Min.ma_dir[5]=-1;	
		 }
	private: System::Void listBoxYearVolDir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearVolDir1->SelectedIndex==1)	tabDataYear.vol_dir[0]=1;
			 if(this->listBoxYearVolDir1->SelectedIndex==2)	tabDataYear.vol_dir[0]=-1;	
		 }
	private: System::Void listBoxMonthVolDir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthVolDir1->SelectedIndex==1)	tabDataMonth.vol_dir[0]=1;
			 if(this->listBoxMonthVolDir1->SelectedIndex==2)	tabDataMonth.vol_dir[0]=-1;	
		 }
	private: System::Void listBoxWeekVolDir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekVolDir1->SelectedIndex==1)	tabDataWeek.vol_dir[0]=1;
			 if(this->listBoxWeekVolDir1->SelectedIndex==2)	tabDataWeek.vol_dir[0]=-1;
		 }
	private: System::Void listBoxDayVolDir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayVolDir1->SelectedIndex==1)	tabDataDay.vol_dir[0]=1;
			 if(this->listBoxDayVolDir1->SelectedIndex==2)	tabDataDay.vol_dir[0]=-1;	
		 }
	private: System::Void listBox4HourVolDir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourVolDir1->SelectedIndex==1)	tabData4Hour.vol_dir[0]=1;
			 if(this->listBox4HourVolDir1->SelectedIndex==2)	tabData4Hour.vol_dir[0]=-1;
		 }
	private: System::Void listBoxHourVolDir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourVolDir1->SelectedIndex==1)	tabDataHour.vol_dir[0]=1;
			 if(this->listBoxHourVolDir1->SelectedIndex==2)	tabDataHour.vol_dir[0]=-1;
		 }
	private: System::Void listBox45MinVolDir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinVolDir1->SelectedIndex==1)	tabData45Min.vol_dir[0]=1;
			 if(this->listBox45MinVolDir1->SelectedIndex==2)	tabData45Min.vol_dir[0]=-1;
		 }
	private: System::Void listBox30MinVolDir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinVolDir1->SelectedIndex==1)	tabData30Min.vol_dir[0]=1;
			 if(this->listBox30MinVolDir1->SelectedIndex==2)	tabData30Min.vol_dir[0]=-1;
		 }
	private: System::Void listBox15MinVolDir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinVolDir1->SelectedIndex==1)	tabData15Min.vol_dir[0]=1;
			 if(this->listBox15MinVolDir1->SelectedIndex==2)	tabData15Min.vol_dir[0]=-1;
		 }
	private: System::Void listBox10MinVolDir1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinVolDir1->SelectedIndex==1)	tabData10Min.vol_dir[0]=1;
			 if(this->listBox10MinVolDir1->SelectedIndex==2)	tabData10Min.vol_dir[0]=-1;
		 }
	private: System::Void listBox5MinVolDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinVolDir1->SelectedIndex==1)	tabData5Min.vol_dir[0]=1;
			 if(this->listBox5MinVolDir1->SelectedIndex==2)	tabData5Min.vol_dir[0]=-1;
		 }
	private: System::Void listBoxYearVolDir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearVolDir2->SelectedIndex==1)	tabDataYear.vol_dir[1]=1;
			 if(this->listBoxYearVolDir2->SelectedIndex==2)	tabDataYear.vol_dir[1]=-1;	
		 }
	private: System::Void listBoxMonthVolDir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthVolDir2->SelectedIndex==1)	tabDataMonth.vol_dir[1]=1;
			 if(this->listBoxMonthVolDir2->SelectedIndex==2)	tabDataMonth.vol_dir[1]=-1;
		 }
	private: System::Void listBoxWeekVolDir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekVolDir2->SelectedIndex==1)	tabDataWeek.vol_dir[1]=1;
			 if(this->listBoxWeekVolDir2->SelectedIndex==2)	tabDataWeek.vol_dir[1]=-1;
		 }
	private: System::Void listBoxDayVolDir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayVolDir2->SelectedIndex==1)	tabDataDay.vol_dir[1]=1;
			 if(this->listBoxDayVolDir2->SelectedIndex==2)	tabDataDay.vol_dir[1]=-1;
		 }
	private: System::Void listBox4HourVolDir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourVolDir2->SelectedIndex==1)	tabData4Hour.vol_dir[1]=1;
			 if(this->listBox4HourVolDir2->SelectedIndex==2)	tabData4Hour.vol_dir[1]=-1;
		 }
	private: System::Void listBoxHourVolDir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourVolDir2->SelectedIndex==1)	tabDataHour.vol_dir[1]=1;
			 if(this->listBoxHourVolDir2->SelectedIndex==2)	tabDataHour.vol_dir[1]=-1;
		 }
	private: System::Void listBox45MinVolDir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinVolDir2->SelectedIndex==1)	tabData45Min.vol_dir[1]=1;
			 if(this->listBox45MinVolDir2->SelectedIndex==2)	tabData45Min.vol_dir[1]=-1;
		 }
	private: System::Void listBox30MinVolDir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinVolDir2->SelectedIndex==1)	tabData30Min.vol_dir[1]=1;
			 if(this->listBox30MinVolDir2->SelectedIndex==2)	tabData30Min.vol_dir[1]=-1;	
		 }
	private: System::Void listBox15MinVolDir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinVolDir2->SelectedIndex==1)	tabData15Min.vol_dir[1]=1;
			 if(this->listBox15MinVolDir2->SelectedIndex==2)	tabData15Min.vol_dir[1]=-1;	
		 }
	private: System::Void listBox10MinVolDir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinVolDir2->SelectedIndex==1)	tabData10Min.vol_dir[1]=1;
			 if(this->listBox10MinVolDir2->SelectedIndex==2)	tabData10Min.vol_dir[1]=-1;
		 }
	private: System::Void listBox5MinVolDir2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinVolDir2->SelectedIndex==1)	tabData5Min.vol_dir[1]=1;
			 if(this->listBox5MinVolDir2->SelectedIndex==2)	tabData5Min.vol_dir[1]=-1;
		 }
	private: System::Void listBoxYearBollDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearBollDir->SelectedIndex==1)	tabDataYear.boll_dir=1;
			 if(this->listBoxYearBollDir->SelectedIndex==2)	tabDataYear.boll_dir=-1;
		 }
	private: System::Void listBoxMonthBollDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthBollDir->SelectedIndex==1)	tabDataMonth.boll_dir=1;
			 if(this->listBoxMonthBollDir->SelectedIndex==2)	tabDataMonth.boll_dir=-1;
		 }
	private: System::Void listBoxWeekBollDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekBollDir->SelectedIndex==1)	tabDataWeek.boll_dir=1;
			 if(this->listBoxWeekBollDir->SelectedIndex==2)	tabDataWeek.boll_dir=-1;
		 }
	private: System::Void listBoxDayBollDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayBollDir->SelectedIndex==1)	tabDataDay.boll_dir=1;
			 if(this->listBoxDayBollDir->SelectedIndex==2)	tabDataDay.boll_dir=-1;
		 }
	private: System::Void listBox4HourBollDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourBollDir->SelectedIndex==1)	tabData4Hour.boll_dir=1;
			 if(this->listBox4HourBollDir->SelectedIndex==2)	tabData4Hour.boll_dir=-1;
		 }
	private: System::Void listBoxHourBollDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourBollDir->SelectedIndex==1)	tabDataHour.boll_dir=1;
			 if(this->listBoxHourBollDir->SelectedIndex==2)	tabDataHour.boll_dir=-1;
		 }
	private: System::Void listBox45MinBollDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinBollDir->SelectedIndex==1)	tabData45Min.boll_dir=1;
			 if(this->listBox45MinBollDir->SelectedIndex==2)	tabData45Min.boll_dir=-1;
		 }
	private: System::Void listBox30MinBollDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinBollDir->SelectedIndex==1)	tabData30Min.boll_dir=1;
			 if(this->listBox30MinBollDir->SelectedIndex==2)	tabData30Min.boll_dir=-1;
		 }
	private: System::Void listBox15MinBollDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinBollDir->SelectedIndex==1)	tabData15Min.boll_dir=1;
			 if(this->listBox15MinBollDir->SelectedIndex==2)	tabData15Min.boll_dir=-1;
		 }
	private: System::Void listBox10MinBollDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinBollDir->SelectedIndex==1)	tabData10Min.boll_dir=1;
			 if(this->listBox10MinBollDir->SelectedIndex==2)	tabData10Min.boll_dir=-1;
		 }
	private: System::Void listBox5MinBollDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinBollDir->SelectedIndex==1)	tabData5Min.boll_dir=1;
			 if(this->listBox5MinBollDir->SelectedIndex==2)	tabData5Min.boll_dir=-1;
		 }
	private: System::Void listBoxYearMacdDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearMacdDir->SelectedIndex==1)	tabDataYear.macd_dir=1;
			 if(this->listBoxYearMacdDir->SelectedIndex==2)	tabDataYear.macd_dir=-1;
		 }
	private: System::Void listBoxMonthMacdDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthMacdDir->SelectedIndex==1)	tabDataMonth.macd_dir=1;
			 if(this->listBoxMonthMacdDir->SelectedIndex==2)	tabDataMonth.macd_dir=-1;
		 }
	private: System::Void listBoxWeekMacdDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekMacdDir->SelectedIndex==1)	tabDataWeek.macd_dir=1;
			 if(this->listBoxWeekMacdDir->SelectedIndex==2)	tabDataWeek.macd_dir=-1;
		 }
	private: System::Void listBoxDayMacdDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayMacdDir->SelectedIndex==1)	tabDataDay.macd_dir=1;
			 if(this->listBoxDayMacdDir->SelectedIndex==2)	tabDataDay.macd_dir=-1;
		 }
	private: System::Void listBox4HourMacdDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourMacdDir->SelectedIndex==1)	tabData4Hour.macd_dir=1;
			 if(this->listBox4HourMacdDir->SelectedIndex==2)	tabData4Hour.macd_dir=-1;
		 }
	private: System::Void listBoxHourMacdDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourMacdDir->SelectedIndex==1)	tabDataHour.macd_dir=1;
			 if(this->listBoxHourMacdDir->SelectedIndex==2)	tabDataHour.macd_dir=-1;
		 }
	private: System::Void listBox45MinMacdDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinMacdDir->SelectedIndex==1)	tabData45Min.macd_dir=1;
			 if(this->listBox45MinMacdDir->SelectedIndex==2)	tabData45Min.macd_dir=-1;
		 }
	private: System::Void listBox30MinMacdDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinMacdDir->SelectedIndex==1)	tabData30Min.macd_dir=1;
			 if(this->listBox30MinMacdDir->SelectedIndex==2)	tabData30Min.macd_dir=-1;
		 }
	private: System::Void listBox15MinMacdDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinMacdDir->SelectedIndex==1)	tabData15Min.macd_dir=1;
			 if(this->listBox15MinMacdDir->SelectedIndex==2)	tabData15Min.macd_dir=-1;
		 }
	private: System::Void listBox10MinMacdDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinMacdDir->SelectedIndex==1)	tabData10Min.macd_dir=1;
			 if(this->listBox10MinMacdDir->SelectedIndex==2)	tabData10Min.macd_dir=-1;
		 }
	private: System::Void listBox5MinMacdDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinMacdDir->SelectedIndex==1)	tabData5Min.macd_dir=1;
			 if(this->listBox5MinMacdDir->SelectedIndex==2)	tabData5Min.macd_dir=-1;
		 }
	private: System::Void listBoxYearKdjDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearKdjDir->SelectedIndex==1)	tabDataYear.kdj_dir=1;
			 if(this->listBoxYearKdjDir->SelectedIndex==2)	tabDataYear.kdj_dir=-1;
		 }
	private: System::Void listBoxMonthKdjDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthKdjDir->SelectedIndex==1)	tabDataMonth.kdj_dir=1;
			 if(this->listBoxMonthKdjDir->SelectedIndex==2)	tabDataMonth.kdj_dir=-1;
		 }
	private: System::Void listBoxWeekKdjDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekKdjDir->SelectedIndex==1)	tabDataWeek.kdj_dir=1;
			 if(this->listBoxWeekKdjDir->SelectedIndex==2)	tabDataWeek.kdj_dir=-1;
		 }
	private: System::Void listBoxDayKdjDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayKdjDir->SelectedIndex==1)	tabDataDay.kdj_dir=1;
			 if(this->listBoxDayKdjDir->SelectedIndex==2)	tabDataDay.kdj_dir=-1;
		 }
	private: System::Void listBox4HourKdjDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourKdjDir->SelectedIndex==1)	tabData4Hour.kdj_dir=1;
			 if(this->listBox4HourKdjDir->SelectedIndex==2)	tabData4Hour.kdj_dir=-1;
		 }
	private: System::Void listBoxHourKdjDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourKdjDir->SelectedIndex==1)	tabDataHour.kdj_dir=1;
			 if(this->listBoxHourKdjDir->SelectedIndex==2)	tabDataHour.kdj_dir=-1;
		 }
	private: System::Void listBox45MinKdjDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinKdjDir->SelectedIndex==1)	tabData45Min.kdj_dir=1;
			 if(this->listBox45MinKdjDir->SelectedIndex==2)	tabData45Min.kdj_dir=-1;
		 }
	private: System::Void listBox30MinKdjDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinKdjDir->SelectedIndex==1)	tabData30Min.kdj_dir=1;
			 if(this->listBox30MinKdjDir->SelectedIndex==2)	tabData30Min.kdj_dir=-1;
		 }
	private: System::Void listBox15MinKdjDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinKdjDir->SelectedIndex==1)	tabData15Min.kdj_dir=1;
			 if(this->listBox15MinKdjDir->SelectedIndex==2)	tabData15Min.kdj_dir=-1;
		 }
	private: System::Void listBox10MinKdjDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinKdjDir->SelectedIndex==1)	tabData10Min.kdj_dir=1;
			 if(this->listBox10MinKdjDir->SelectedIndex==2)	tabData10Min.kdj_dir=-1;
		 }
	private: System::Void listBox5MinKdjDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinKdjDir->SelectedIndex==1)	tabData5Min.kdj_dir=1;
			 if(this->listBox5MinKdjDir->SelectedIndex==2)	tabData5Min.kdj_dir=-1;
		 }
	private: System::Void listBoxYearRsiDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearRsiDir->SelectedIndex==1)	tabDataYear.rsi_dir=1;
			 if(this->listBoxYearRsiDir->SelectedIndex==2)	tabDataYear.rsi_dir=-1;
		 }
	private: System::Void listBoxMonthRsiDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthRsiDir->SelectedIndex==1)	tabDataMonth.rsi_dir=1;
			 if(this->listBoxMonthRsiDir->SelectedIndex==2)	tabDataMonth.rsi_dir=-1;
		 }
	private: System::Void listBoxWeekRsiDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekRsiDir->SelectedIndex==1)	tabDataWeek.rsi_dir=1;
			 if(this->listBoxWeekRsiDir->SelectedIndex==2)	tabDataWeek.rsi_dir=-1;
		 }
	private: System::Void listBoxDayRsiDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayRsiDir->SelectedIndex==1)	tabDataDay.rsi_dir=1;
			 if(this->listBoxDayRsiDir->SelectedIndex==2)	tabDataDay.rsi_dir=-1;
		 }
	private: System::Void listBox4HourRsiDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourRsiDir->SelectedIndex==1)	tabData4Hour.rsi_dir=1;
			 if(this->listBox4HourRsiDir->SelectedIndex==2)	tabData4Hour.rsi_dir=-1;
		 }
	private: System::Void listBoxHourRsiDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourRsiDir->SelectedIndex==1)	tabDataHour.rsi_dir=1;
			 if(this->listBoxHourRsiDir->SelectedIndex==2)	tabDataHour.rsi_dir=-1;
		 }
	private: System::Void listBox45MinRsiDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinRsiDir->SelectedIndex==1)	tabData45Min.rsi_dir=1;
			 if(this->listBox45MinRsiDir->SelectedIndex==2)	tabData45Min.rsi_dir=-1;
		 }
	private: System::Void listBox30MinRsiDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinRsiDir->SelectedIndex==1)	tabData30Min.rsi_dir=1;
			 if(this->listBox30MinRsiDir->SelectedIndex==2)	tabData30Min.rsi_dir=-1;
		 }
	private: System::Void listBox15MinRsiDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinRsiDir->SelectedIndex==1)	tabData15Min.rsi_dir=1;
			 if(this->listBox15MinRsiDir->SelectedIndex==2)	tabData15Min.rsi_dir=-1;
		 }
	private: System::Void listBox10MinRsiDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinRsiDir->SelectedIndex==1)	tabData10Min.rsi_dir=1;
			 if(this->listBox10MinRsiDir->SelectedIndex==2)	tabData10Min.rsi_dir=-1;
		 }
	private: System::Void listBox5MinRsiDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinRsiDir->SelectedIndex==1)	tabData5Min.rsi_dir=1;
			 if(this->listBox5MinRsiDir->SelectedIndex==2)	tabData5Min.rsi_dir=-1;
		 }
	private: System::Void listBoxYearWrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->listBoxYearWrDir->SelectedIndex==1)	tabDataYear.wr_dir=1;
			 if(this->listBoxYearWrDir->SelectedIndex==2)	tabDataYear.wr_dir=-1;
		 }
	private: System::Void listBoxMonthWrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->listBoxMonthWrDir->SelectedIndex==1)	tabDataMonth.wr_dir=1;
			 if(this->listBoxMonthWrDir->SelectedIndex==2)	tabDataMonth.wr_dir=-1;
		 }
	private: System::Void listBoxWeekWrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->listBoxWeekWrDir->SelectedIndex==1)	tabDataWeek.wr_dir=1;
			 if(this->listBoxWeekWrDir->SelectedIndex==2)	tabDataWeek.wr_dir=-1;
		 }
	private: System::Void listBoxDayWrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->listBoxDayWrDir->SelectedIndex==1)	tabDataDay.wr_dir=1;
			 if(this->listBoxDayWrDir->SelectedIndex==2)	tabDataDay.wr_dir=-1;
		 }
	private: System::Void listBox4HourWrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->listBox4HourWrDir->SelectedIndex==1)	tabData4Hour.wr_dir=1;
			 if(this->listBox4HourWrDir->SelectedIndex==2)	tabData4Hour.wr_dir=-1;
		 }
	private: System::Void listBoxHourWrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->listBoxHourWrDir->SelectedIndex==1)	tabDataHour.wr_dir=1;
			 if(this->listBoxHourWrDir->SelectedIndex==2)	tabDataHour.wr_dir=-1;
		 }
	private: System::Void listBox45MinWrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->listBox45MinWrDir->SelectedIndex==1)	tabData45Min.wr_dir=1;
			 if(this->listBox45MinWrDir->SelectedIndex==2)	tabData45Min.wr_dir=-1;
		 }
	private: System::Void listBox30MinWrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->listBox30MinWrDir->SelectedIndex==1)	tabData30Min.wr_dir=1;
			 if(this->listBox30MinWrDir->SelectedIndex==2)	tabData30Min.wr_dir=-1;
		 }
	private: System::Void listBox15MinWrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->listBox15MinWrDir->SelectedIndex==1)	tabData15Min.wr_dir=1;
			 if(this->listBox15MinWrDir->SelectedIndex==2)	tabData15Min.wr_dir=-1;
		 }
	private: System::Void listBox10MinWrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->listBox10MinWrDir->SelectedIndex==1)	tabData10Min.wr_dir=1;
			 if(this->listBox10MinWrDir->SelectedIndex==2)	tabData10Min.wr_dir=-1;
		 }
	private: System::Void listBox5MinWrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->listBox5MinWrDir->SelectedIndex==1)	tabData5Min.wr_dir=1;
			 if(this->listBox5MinWrDir->SelectedIndex==2)	tabData5Min.wr_dir=-1;
		 }
	private: System::Void listBoxYearRocDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearRocDir->SelectedIndex==1)	tabDataYear.roc_dir=1;
			 if(this->listBoxYearRocDir->SelectedIndex==2)	tabDataYear.roc_dir=-1;
		 }
	private: System::Void listBoxMonthRocDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthRocDir->SelectedIndex==1)	tabDataMonth.roc_dir=1;
			 if(this->listBoxMonthRocDir->SelectedIndex==2)	tabDataMonth.roc_dir=-1;
		 }
	private: System::Void listBoxWeekRocDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekRocDir->SelectedIndex==1)	tabDataWeek.roc_dir=1;
			 if(this->listBoxWeekRocDir->SelectedIndex==2)	tabDataWeek.roc_dir=-1;
		 }
	private: System::Void listBoxDayRocDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayRocDir->SelectedIndex==1)	tabDataDay.roc_dir=1;
			 if(this->listBoxDayRocDir->SelectedIndex==2)	tabDataDay.roc_dir=-1;
		 }
	private: System::Void listBox4HourRocDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourRocDir->SelectedIndex==1)	tabData4Hour.roc_dir=1;
			 if(this->listBox4HourRocDir->SelectedIndex==2)	tabData4Hour.roc_dir=-1;
		 }
	private: System::Void listBoxHourRocDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourRocDir->SelectedIndex==1)	tabDataHour.roc_dir=1;
			 if(this->listBoxHourRocDir->SelectedIndex==2)	tabDataHour.roc_dir=-1;
		 }
	private: System::Void listBox45MinRocDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinRocDir->SelectedIndex==1)	tabData45Min.roc_dir=1;
			 if(this->listBox45MinRocDir->SelectedIndex==2)	tabData45Min.roc_dir=-1;
		 }
	private: System::Void listBox30MinRocDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinRocDir->SelectedIndex==1)	tabData30Min.roc_dir=1;
			 if(this->listBox30MinRocDir->SelectedIndex==2)	tabData30Min.roc_dir=-1;
		 }
	private: System::Void listBox15MinRocDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinRocDir->SelectedIndex==1)	tabData15Min.roc_dir=1;
			 if(this->listBox15MinRocDir->SelectedIndex==2)	tabData15Min.roc_dir=-1;
		 }
	private: System::Void listBox10MinRocDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinRocDir->SelectedIndex==1)	tabData10Min.roc_dir=1;
			 if(this->listBox10MinRocDir->SelectedIndex==2)	tabData10Min.roc_dir=-1;
		 }
	private: System::Void listBox5MinRocDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinRocDir->SelectedIndex==1)	tabData5Min.roc_dir=1;
			 if(this->listBox5MinRocDir->SelectedIndex==2)	tabData5Min.roc_dir=-1;
		 }
	private: System::Void listBoxYearVrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->listBoxYearVrDir->SelectedIndex==1)	tabDataYear.vr_dir=1;
			 if(this->listBoxYearVrDir->SelectedIndex==2)	tabDataYear.vr_dir=-1;
		 }
	private: System::Void listBoxMonthVrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) { 			
			 if(this->listBoxMonthVrDir->SelectedIndex==1)	tabDataMonth.vr_dir=1;
			 if(this->listBoxMonthVrDir->SelectedIndex==2)	tabDataMonth.vr_dir=-1;
		 }
	private: System::Void listBoxWeekVrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekVrDir->SelectedIndex==1)	tabDataWeek.vr_dir=1;
			 if(this->listBoxWeekVrDir->SelectedIndex==2)	tabDataWeek.vr_dir=-1;
		 }
	private: System::Void listBoxDayVrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayVrDir->SelectedIndex==1)	tabDataDay.vr_dir=1;
			 if(this->listBoxDayVrDir->SelectedIndex==2)	tabDataDay.vr_dir=-1;
		 }
	private: System::Void listBox4HourVrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourVrDir->SelectedIndex==1)	tabData4Hour.vr_dir=1;
			 if(this->listBox4HourVrDir->SelectedIndex==2)	tabData4Hour.vr_dir=-1;
		 }
	private: System::Void listBoxHourVrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourVrDir->SelectedIndex==1)	tabDataHour.vr_dir=1;
			 if(this->listBoxHourVrDir->SelectedIndex==2)	tabDataHour.vr_dir=-1;
		 }
	private: System::Void listBox45MinVrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinVrDir->SelectedIndex==1)	tabData45Min.vr_dir=1;
			 if(this->listBox45MinVrDir->SelectedIndex==2)	tabData45Min.vr_dir=-1;
		 }
	private: System::Void listBox30MinVrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinVrDir->SelectedIndex==1)	tabData30Min.vr_dir=1;
			 if(this->listBox30MinVrDir->SelectedIndex==2)	tabData30Min.vr_dir=-1;
		 }
	private: System::Void listBox15MinVrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinVrDir->SelectedIndex==1)	tabData15Min.vr_dir=1;
			 if(this->listBox15MinVrDir->SelectedIndex==2)	tabData15Min.vr_dir=-1;
		 }
	private: System::Void listBox10MinVrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinVrDir->SelectedIndex==1)	tabData10Min.vr_dir=1;
			 if(this->listBox10MinVrDir->SelectedIndex==2)	tabData10Min.vr_dir=-1;
		 }
	private: System::Void listBox5MinVrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinVrDir->SelectedIndex==1)	tabData5Min.vr_dir=1;
			 if(this->listBox5MinVrDir->SelectedIndex==2)	tabData5Min.vr_dir=-1;
		 }
	private: System::Void listBoxYearDmaDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxYearDmaDir->SelectedIndex==1)	tabDataYear.dma_dir=1;
			 if(this->listBoxYearDmaDir->SelectedIndex==2)	tabDataYear.dma_dir=-1;
		 }
	private: System::Void listBoxMonthDmaDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxMonthDmaDir->SelectedIndex==1)	tabDataMonth.dma_dir=1;
			 if(this->listBoxMonthDmaDir->SelectedIndex==2)	tabDataMonth.dma_dir=-1;
		 }
	private: System::Void listBoxWeekDmaDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxWeekDmaDir->SelectedIndex==1)	tabDataWeek.dma_dir=1;
			 if(this->listBoxWeekDmaDir->SelectedIndex==2)	tabDataWeek.dma_dir=-1;
		 }
	private: System::Void listBoxDayDmaDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxDayDmaDir->SelectedIndex==1)	tabDataDay.dma_dir=1;
			 if(this->listBoxDayDmaDir->SelectedIndex==2)	tabDataDay.dma_dir=-1;
		 }
	private: System::Void listBox4HourDmaDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox4HourDmaDir->SelectedIndex==1)	tabData4Hour.dma_dir=1;
			 if(this->listBox4HourDmaDir->SelectedIndex==2)	tabData4Hour.dma_dir=-1;
		 }
	private: System::Void listBoxHourDmaDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBoxHourDmaDir->SelectedIndex==1)	tabDataHour.dma_dir=1;
			 if(this->listBoxHourDmaDir->SelectedIndex==2)	tabDataHour.dma_dir=-1;
		 }
	private: System::Void listBox45MinDmaDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox45MinDmaDir->SelectedIndex==1)	tabData45Min.dma_dir=1;
			 if(this->listBox45MinDmaDir->SelectedIndex==2)	tabData45Min.dma_dir=-1;
		 }
	private: System::Void listBox30MinDmaDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox30MinDmaDir->SelectedIndex==1)	tabData30Min.dma_dir=1;
			 if(this->listBox30MinDmaDir->SelectedIndex==2)	tabData30Min.dma_dir=-1;
		 }
	private: System::Void listBox15MinDmaDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox15MinDmaDir->SelectedIndex==1)	tabData15Min.dma_dir=1;
			 if(this->listBox15MinDmaDir->SelectedIndex==2)	tabData15Min.dma_dir=-1;
		 }
	private: System::Void listBox10MinDmaDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox10MinDmaDir->SelectedIndex==1)	tabData10Min.dma_dir=1;
			 if(this->listBox10MinDmaDir->SelectedIndex==2)	tabData10Min.dma_dir=-1;
		 }
	private: System::Void listBox5MinDmaDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->listBox5MinDmaDir->SelectedIndex==1)	tabData5Min.dma_dir=1;
			 if(this->listBox5MinDmaDir->SelectedIndex==2)	tabData5Min.dma_dir=-1;
		 }
	private: System::Void listBoxYearCrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBoxYearCrDir->SelectedIndex==1)	tabDataYear.cr_dir=1;
			if(this->listBoxYearCrDir->SelectedIndex==2)	tabDataYear.cr_dir=-1;
		 }
	private: System::Void listBoxMonthCrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBoxMonthCrDir->SelectedIndex==1)	tabDataMonth.cr_dir=1;
			if(this->listBoxMonthCrDir->SelectedIndex==2)	tabDataMonth.cr_dir=-1;
		 }
	private: System::Void listBoxWeekCrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBoxWeekCrDir->SelectedIndex==1)	tabDataWeek.cr_dir=1;
			if(this->listBoxWeekCrDir->SelectedIndex==2)	tabDataWeek.cr_dir=-1;
		 }
	private: System::Void listBoxDayCrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBoxDayCrDir->SelectedIndex==1)	tabDataDay.cr_dir=1;
			if(this->listBoxDayCrDir->SelectedIndex==2)	tabDataDay.cr_dir=-1;
		 }
	private: System::Void listBox4HourCrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBox4HourCrDir->SelectedIndex==1)	tabData4Hour.cr_dir=1;
			if(this->listBox4HourCrDir->SelectedIndex==2)	tabData4Hour.cr_dir=-1;
		 }
	private: System::Void listBoxHourCrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBoxHourCrDir->SelectedIndex==1)	tabDataHour.cr_dir=1;
			if(this->listBoxHourCrDir->SelectedIndex==2)	tabDataHour.cr_dir=-1;
		 }
	private: System::Void listBox45MinCrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBox45MinCrDir->SelectedIndex==1)	tabData45Min.cr_dir=1;
			if(this->listBox45MinCrDir->SelectedIndex==2)	tabData45Min.cr_dir=-1;
		 }
	private: System::Void listBox30MinCrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBox30MinCrDir->SelectedIndex==1)	tabData30Min.cr_dir=1;
			if(this->listBox30MinCrDir->SelectedIndex==2)	tabData30Min.cr_dir=-1;
		 }
	private: System::Void listBox15MinCrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBox15MinCrDir->SelectedIndex==1)	tabData15Min.cr_dir=1;
			if(this->listBox15MinCrDir->SelectedIndex==2)	tabData15Min.cr_dir=-1;
		 }
	private: System::Void listBox10MinCrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBox10MinCrDir->SelectedIndex==1)	tabData10Min.cr_dir=1;
			if(this->listBox10MinCrDir->SelectedIndex==2)	tabData10Min.cr_dir=-1;
		 }
	private: System::Void listBox5MinCrDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBox5MinCrDir->SelectedIndex==1)	tabData5Min.cr_dir=1;
			if(this->listBox5MinCrDir->SelectedIndex==2)	tabData5Min.cr_dir=-1;
		 }
	private: System::Void listBoxYearCciDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBoxYearCciDir->SelectedIndex==1)	tabDataYear.cci_dir=1;
			if(this->listBoxYearCciDir->SelectedIndex==2)	tabDataYear.cci_dir=-1;
		 }
	private: System::Void listBoxMonthCciDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBoxMonthCciDir->SelectedIndex==1)	tabDataMonth.cci_dir=1;
			if(this->listBoxMonthCciDir->SelectedIndex==2)	tabDataMonth.cci_dir=-1;
		 }
	private: System::Void listBoxWeekCciDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBoxWeekCciDir->SelectedIndex==1)	tabDataWeek.cci_dir=1;
			if(this->listBoxWeekCciDir->SelectedIndex==2)	tabDataWeek.cci_dir=-1;
		 }
	private: System::Void listBoxDayCciDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBoxDayCciDir->SelectedIndex==1)	tabDataDay.cci_dir=1;
			if(this->listBoxDayCciDir->SelectedIndex==2)	tabDataDay.cci_dir=-1;
		 }
	private: System::Void listBox4HourCciDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBox4HourCciDir->SelectedIndex==1)	tabData4Hour.cci_dir=1;
			if(this->listBox4HourCciDir->SelectedIndex==2)	tabData4Hour.cci_dir=-1;
		 }
	private: System::Void listBoxHourCciDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBoxHourCciDir->SelectedIndex==1)	tabDataHour.cci_dir=1;
			if(this->listBoxHourCciDir->SelectedIndex==2)	tabDataHour.cci_dir=-1;
		 }
	private: System::Void listBox45MinCciDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBox45MinCciDir->SelectedIndex==1)	tabData45Min.cci_dir=1;
			if(this->listBox45MinCciDir->SelectedIndex==2)	tabData45Min.cci_dir=-1;
		 }
	private: System::Void listBox30MinCciDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBox30MinCciDir->SelectedIndex==1)	tabData30Min.cci_dir=1;
			if(this->listBox30MinCciDir->SelectedIndex==2)	tabData30Min.cci_dir=-1;
		 }
	private: System::Void listBox15MinCciDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBox15MinCciDir->SelectedIndex==1)	tabData15Min.cci_dir=1;
			if(this->listBox15MinCciDir->SelectedIndex==2)	tabData15Min.cci_dir=-1;
		 }
	private: System::Void listBox10MinCciDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBox10MinCciDir->SelectedIndex==1)	tabData10Min.cci_dir=1;
			if(this->listBox10MinCciDir->SelectedIndex==2)	tabData10Min.cci_dir=-1;
		 }
	private: System::Void listBox5MinCciDir_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if(this->listBox5MinCciDir->SelectedIndex==1)	tabData5Min.cci_dir=1;
			if(this->listBox5MinCciDir->SelectedIndex==2)	tabData5Min.cci_dir=-1;
		 }
	private: System::Void textBoxYearMA1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearMA1->Text)) return ;
			 tabDataYear.ma[0]=System::Convert::ToDouble(this->textBoxYearMA1->Text);
		 }
	private: System::Void textBoxMonthMA1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthMA1->Text)) return ;
			 tabDataMonth.ma[0]=System::Convert::ToDouble(this->textBoxMonthMA1->Text);
		 }
	private: System::Void textBoxWeekMA1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekMA1->Text)) return ;
			 tabDataWeek.ma[0]=System::Convert::ToDouble(this->textBoxWeekMA1->Text);
		 }
	private: System::Void textBoxDayMA1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayMA1->Text)) return ;
			 tabDataDay.ma[0]=System::Convert::ToDouble(this->textBoxDayMA1->Text);
		 }
	private: System::Void textBox4HourMA1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourMA1->Text)) return ;
			 tabData4Hour.ma[0]=System::Convert::ToDouble(this->textBox4HourMA1->Text);
		 }
	private: System::Void textBoxHourMA1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourMA1->Text)) return ;
			 tabDataHour.ma[0]=System::Convert::ToDouble(this->textBoxHourMA1->Text);
		 }
	private: System::Void textBox45MinMA1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinMA1->Text)) return ;
			 tabData45Min.ma[0]=System::Convert::ToDouble(this->textBox45MinMA1->Text);
		 }
	private: System::Void textBox30MinMA1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinMA1->Text)) return ;
			 tabData30Min.ma[0]=System::Convert::ToDouble(this->textBox30MinMA1->Text);
		 }
	private: System::Void textBox15MinMA1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinMA1->Text)) return ;
			 tabData15Min.ma[0]=System::Convert::ToDouble(this->textBox15MinMA1->Text);
		 }
	private: System::Void textBox10MinMA1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinMA1->Text)) return ;
			 tabData10Min.ma[0]=System::Convert::ToDouble(this->textBox10MinMA1->Text);
		 }
	private: System::Void textBox5MinMA1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinMA1->Text)) return ;
			 tabData5Min.ma[0]=System::Convert::ToDouble(this->textBox5MinMA1->Text);
		 }
	private: System::Void textBoxYearMA2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearMA2->Text)) return ;
		 	tabDataYear.ma[1]=System::Convert::ToDouble(this->textBoxYearMA2->Text);
		 }
	private: System::Void textBoxMonthMA2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthMA2->Text)) return ;
		 	tabDataMonth.ma[1]=System::Convert::ToDouble(this->textBoxMonthMA2->Text);
		 }
	private: System::Void textBoxWeekMA2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekMA2->Text)) return ;
		 	tabDataWeek.ma[1]=System::Convert::ToDouble(this->textBoxWeekMA2->Text);
		 }
	private: System::Void textBoxDayMA2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayMA2->Text)) return ;
		 	tabDataDay.ma[1]=System::Convert::ToDouble(this->textBoxDayMA2->Text);
		 }
	private: System::Void textBox4HourMA2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourMA2->Text)) return ;
		 	tabData4Hour.ma[1]=System::Convert::ToDouble(this->textBox4HourMA2->Text);
		 }
	private: System::Void textBoxHourMA2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourMA2->Text)) return ;
		 	tabDataHour.ma[1]=System::Convert::ToDouble(this->textBoxHourMA2->Text);
		 }
	private: System::Void textBox45MinMA2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinMA2->Text)) return ;
		 	tabData45Min.ma[1]=System::Convert::ToDouble(this->textBox45MinMA2->Text);
		 }
	private: System::Void textBox30MinMA2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinMA2->Text)) return ;
		 	tabData30Min.ma[1]=System::Convert::ToDouble(this->textBox30MinMA2->Text);
		 }
	private: System::Void textBox15MinMA2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinMA2->Text)) return ;
		 	tabData15Min.ma[1]=System::Convert::ToDouble(this->textBox15MinMA2->Text);
		 }
	private: System::Void textBox10MinMA2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinMA2->Text)) return ;
		 	tabData10Min.ma[1]=System::Convert::ToDouble(this->textBox10MinMA2->Text);
		 }
	private: System::Void textBox5MinMA2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinMA2->Text)) return ;
		 	tabData5Min.ma[1]=System::Convert::ToDouble(this->textBox5MinMA2->Text);
		 }
	private: System::Void textBoxYearMA3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearMA3->Text)) return ;
		 	tabDataYear.ma[2]=System::Convert::ToDouble(this->textBoxYearMA3->Text);
		 }
	private: System::Void textBoxMonthMA3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthMA3->Text)) return ;
		 	tabDataMonth.ma[2]=System::Convert::ToDouble(this->textBoxMonthMA3->Text);
		 }
	private: System::Void textBoxWeekMA3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekMA3->Text)) return ;
		 	tabDataWeek.ma[2]=System::Convert::ToDouble(this->textBoxWeekMA3->Text);
		 }
	private: System::Void textBoxDayMA3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayMA3->Text)) return ;
		 	tabDataDay.ma[2]=System::Convert::ToDouble(this->textBoxDayMA3->Text);
		 }
	private: System::Void textBox4HourMA3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourMA3->Text)) return ;
		 	tabData4Hour.ma[2]=System::Convert::ToDouble(this->textBox4HourMA3->Text);
		 }
	private: System::Void textBoxHourMA3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourMA3->Text)) return ;
		 	tabDataHour.ma[2]=System::Convert::ToDouble(this->textBoxHourMA3->Text);
		 }
	private: System::Void textBox45MinMA3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinMA3->Text)) return ;
		 	tabData45Min.ma[2]=System::Convert::ToDouble(this->textBox45MinMA3->Text);
		 }
	private: System::Void textBox30MinMA3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinMA3->Text)) return ;
		 	tabData30Min.ma[2]=System::Convert::ToDouble(this->textBox30MinMA3->Text);
		 }
	private: System::Void textBox15MinMA3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinMA3->Text)) return ;
		 	tabData15Min.ma[2]=System::Convert::ToDouble(this->textBox15MinMA3->Text);
		 }
	private: System::Void textBox10MinMA3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinMA3->Text)) return ;
		 	tabData10Min.ma[2]=System::Convert::ToDouble(this->textBox10MinMA3->Text);
		 }
	private: System::Void textBox5MinMA3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinMA3->Text)) return ;
		 	tabData5Min.ma[2]=System::Convert::ToDouble(this->textBox5MinMA3->Text);
		 }
	private: System::Void textBoxYearMA4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearMA4->Text)) return ;
		 	tabDataYear.ma[3]=System::Convert::ToDouble(this->textBoxYearMA4->Text);
		 }
	private: System::Void textBoxMonthMA4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthMA4->Text)) return ;
		 	tabDataMonth.ma[3]=System::Convert::ToDouble(this->textBoxMonthMA4->Text);
		 }
	private: System::Void textBoxWeekMA4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekMA4->Text)) return ;
		 	tabDataWeek.ma[3]=System::Convert::ToDouble(this->textBoxWeekMA4->Text);
		 }
	private: System::Void textBoxDayMA4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayMA4->Text)) return ;
		 	tabDataDay.ma[3]=System::Convert::ToDouble(this->textBoxDayMA4->Text);
		 }
	private: System::Void textBox4HourMA4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourMA4->Text)) return ;
		 	tabData4Hour.ma[3]=System::Convert::ToDouble(this->textBox4HourMA4->Text);
		 }
	private: System::Void textBoxHourMA4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourMA4->Text)) return ;
		 	tabDataHour.ma[3]=System::Convert::ToDouble(this->textBoxHourMA4->Text);
		 }
	private: System::Void textBox45MinMA4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinMA4->Text)) return ;
		 	tabData45Min.ma[3]=System::Convert::ToDouble(this->textBox45MinMA4->Text);
		 }
	private: System::Void textBox30MinMA4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinMA4->Text)) return ;
		 	tabData30Min.ma[3]=System::Convert::ToDouble(this->textBox30MinMA4->Text);
		 }
	private: System::Void textBox15MinMA4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinMA4->Text)) return ;
		 	tabData15Min.ma[3]=System::Convert::ToDouble(this->textBox15MinMA4->Text);
		 }
	private: System::Void textBox10MinMA4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinMA4->Text)) return ;
		 	tabData10Min.ma[3]=System::Convert::ToDouble(this->textBox10MinMA4->Text);
		 }
	private: System::Void textBox5MinMA4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinMA4->Text)) return ;
		 	tabData5Min.ma[3]=System::Convert::ToDouble(this->textBox5MinMA4->Text);
		 }
 private: System::Void textBoxYearMA5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearMA5->Text)) return ;
		 	tabDataYear.ma[4]=System::Convert::ToDouble(this->textBoxYearMA5->Text);
		 }
	private: System::Void textBoxMonthMA5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthMA5->Text)) return ;
		 	tabDataMonth.ma[4]=System::Convert::ToDouble(this->textBoxMonthMA5->Text);
		 }
	private: System::Void textBoxWeekMA5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekMA5->Text)) return ;
		 	tabDataWeek.ma[4]=System::Convert::ToDouble(this->textBoxWeekMA5->Text);
		 }
	private: System::Void textBoxDayMA5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayMA5->Text)) return ;
		 	tabDataDay.ma[4]=System::Convert::ToDouble(this->textBoxDayMA5->Text);
		 }
	private: System::Void textBox4HourMA5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourMA5->Text)) return ;
		 	tabData4Hour.ma[4]=System::Convert::ToDouble(this->textBox4HourMA5->Text);
		 }
	private: System::Void textBoxHourMA5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourMA5->Text)) return ;
		 	tabDataHour.ma[4]=System::Convert::ToDouble(this->textBoxHourMA5->Text);
		 }
	private: System::Void textBox45MinMA5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinMA5->Text)) return ;
		 	tabData45Min.ma[4]=System::Convert::ToDouble(this->textBox45MinMA5->Text);
		 }
	private: System::Void textBox30MinMA5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinMA5->Text)) return ;
		 	tabData30Min.ma[4]=System::Convert::ToDouble(this->textBox30MinMA5->Text);
		 }
	private: System::Void textBox15MinMA5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinMA5->Text)) return ;
		 	tabData15Min.ma[4]=System::Convert::ToDouble(this->textBox15MinMA5->Text);
		 }
	private: System::Void textBox10MinMA5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinMA5->Text)) return ;
		 	tabData10Min.ma[4]=System::Convert::ToDouble(this->textBox10MinMA5->Text);
		 }
	private: System::Void textBox5MinMA5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinMA5->Text)) return ;
		 	tabData5Min.ma[4]=System::Convert::ToDouble(this->textBox5MinMA5->Text);
		 }
 private: System::Void textBoxYearMA6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearMA6->Text)) return ;
		 	tabDataYear.ma[5]=System::Convert::ToDouble(this->textBoxYearMA6->Text);
		 }
	private: System::Void textBoxMonthMA6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthMA6->Text)) return ;
		 	tabDataMonth.ma[5]=System::Convert::ToDouble(this->textBoxMonthMA6->Text);
		 }
	private: System::Void textBoxWeekMA6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekMA6->Text)) return ;
		 	tabDataWeek.ma[5]=System::Convert::ToDouble(this->textBoxWeekMA6->Text);
		 }
	private: System::Void textBoxDayMA6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayMA6->Text)) return ;
		 	tabDataDay.ma[5]=System::Convert::ToDouble(this->textBoxDayMA6->Text);
		 }
	private: System::Void textBox4HourMA6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourMA6->Text)) return ;
		 	tabData4Hour.ma[5]=System::Convert::ToDouble(this->textBox4HourMA6->Text);
		 }
	private: System::Void textBoxHourMA6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourMA6->Text)) return ;
		 	tabDataHour.ma[5]=System::Convert::ToDouble(this->textBoxHourMA6->Text);
		 }
	private: System::Void textBox45MinMA6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinMA6->Text)) return ;
		 	tabData45Min.ma[5]=System::Convert::ToDouble(this->textBox45MinMA6->Text);
		 }
	private: System::Void textBox30MinMA6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinMA6->Text)) return ;
		 	tabData30Min.ma[5]=System::Convert::ToDouble(this->textBox30MinMA6->Text);
		 }
	private: System::Void textBox15MinMA6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinMA6->Text)) return ;
		 	tabData15Min.ma[5]=System::Convert::ToDouble(this->textBox15MinMA6->Text);
		 }
	private: System::Void textBox10MinMA6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinMA6->Text)) return ;
		 	tabData10Min.ma[5]=System::Convert::ToDouble(this->textBox10MinMA6->Text);
		 }
	private: System::Void textBox5MinMA6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinMA6->Text)) return ;
		 	tabData5Min.ma[5]=System::Convert::ToDouble(this->textBox5MinMA6->Text);
		 }
	private: System::Void textBoxYearVol1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearVol1->Text)) return ;
		 	tabDataYear.vol[0]=System::Convert::ToDouble(this->textBoxYearVol1->Text);
		 }
	private: System::Void textBoxMonthVol1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthVol1->Text)) return ;
		 	tabDataMonth.vol[0]=System::Convert::ToDouble(this->textBoxMonthVol1->Text);
		 }
	private: System::Void textBoxWeekVol1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekVol1->Text)) return ;
		 	tabDataWeek.vol[0]=System::Convert::ToDouble(this->textBoxWeekVol1->Text);
		 }
	private: System::Void textBoxDayVol1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayVol1->Text)) return ;
		 	tabDataDay.vol[0]=System::Convert::ToDouble(this->textBoxDayVol1->Text);
		 }
	private: System::Void textBox4HourVol1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourVol1->Text)) return ;
		 	tabData4Hour.vol[0]=System::Convert::ToDouble(this->textBox4HourVol1->Text);
		 }
	private: System::Void textBoxHourVol1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourVol1->Text)) return ;
		 	tabDataHour.vol[0]=System::Convert::ToDouble(this->textBoxHourVol1->Text);
		 }
	private: System::Void textBox45MinVol1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinVol1->Text)) return ;
		 	tabData45Min.vol[0]=System::Convert::ToDouble(this->textBox45MinVol1->Text);
		 }
	private: System::Void textBox30MinVol1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinVol1->Text)) return ;
		 	tabData30Min.vol[0]=System::Convert::ToDouble(this->textBox30MinVol1->Text);
		 }
	private: System::Void textBox15MinVol1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinVol1->Text)) return ;
		 	tabData15Min.vol[0]=System::Convert::ToDouble(this->textBox15MinVol1->Text);
		 }
	private: System::Void textBox10MinVol1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinVol1->Text)) return ;
		 	tabData10Min.vol[0]=System::Convert::ToDouble(this->textBox10MinVol1->Text);
		 }
	private: System::Void textBox5MinVol1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinVol1->Text)) return ;
		 	tabData5Min.vol[0]=System::Convert::ToDouble(this->textBox5MinVol1->Text);
		 }
	private: System::Void textBoxYearVol2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearVol2->Text)) return ;
		 	tabDataYear.vol[1]=System::Convert::ToDouble(this->textBoxYearVol2->Text);
		 }
	private: System::Void textBoxMonthVol2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthVol2->Text)) return ;
		 	tabDataMonth.vol[1]=System::Convert::ToDouble(this->textBoxMonthVol2->Text);
		 }
	private: System::Void textBoxWeekVol2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekVol2->Text)) return ;
		 	tabDataWeek.vol[1]=System::Convert::ToDouble(this->textBoxWeekVol2->Text);
		 }
	private: System::Void textBoxDayVol2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayVol2->Text)) return ;
		 	tabDataDay.vol[1]=System::Convert::ToDouble(this->textBoxDayVol2->Text);
		 }
	private: System::Void textBox4HourVol2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourVol2->Text)) return ;
		 	tabData4Hour.vol[1]=System::Convert::ToDouble(this->textBox4HourVol2->Text);
		 }
	private: System::Void textBoxHourVol2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourVol2->Text)) return ;
		 	tabDataHour.vol[1]=System::Convert::ToDouble(this->textBoxHourVol2->Text);
		 }
	private: System::Void textBox45MinVol2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinVol2->Text)) return ;
		 	tabData45Min.vol[1]=System::Convert::ToDouble(this->textBox45MinVol2->Text);
		 }
	private: System::Void textBox30MinVol2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinVol2->Text)) return ;
		 	tabData30Min.vol[1]=System::Convert::ToDouble(this->textBox30MinVol2->Text);
		 }
	private: System::Void textBox15MinVol2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinVol2->Text)) return ;
		 	tabData15Min.vol[1]=System::Convert::ToDouble(this->textBox15MinVol2->Text);
		 }
	private: System::Void textBox10MinVol2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinVol2->Text)) return ;
		 	tabData10Min.vol[1]=System::Convert::ToDouble(this->textBox10MinVol2->Text);
		 }
	private: System::Void textBox5MinVol2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinVol2->Text)) return ;
		 	tabData5Min.vol[1]=System::Convert::ToDouble(this->textBox5MinVol2->Text);
		 }
	private: System::Void textBoxYearBollLow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearBollLow->Text)) return ;
		 	tabDataYear.boll_low=System::Convert::ToDouble(this->textBoxYearBollLow->Text);
		 }
	private: System::Void textBoxMonthBollLow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthBollLow->Text)) return ;
		 	tabDataMonth.boll_low=System::Convert::ToDouble(this->textBoxMonthBollLow->Text);
		 }
	private: System::Void textBoxWeekBollLow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekBollLow->Text)) return ;
		 	tabDataWeek.boll_low=System::Convert::ToDouble(this->textBoxWeekBollLow->Text);
		 }
	private: System::Void textBoxDayBollLow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayBollLow->Text)) return ;
		 	tabDataDay.boll_low=System::Convert::ToDouble(this->textBoxDayBollLow->Text);
		 }
	private: System::Void textBox4HourBollLow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourBollLow->Text)) return ;
		 	tabData4Hour.boll_low=System::Convert::ToDouble(this->textBox4HourBollLow->Text);
		 }
	private: System::Void textBoxHourBollLow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourBollLow->Text)) return ;
		 	tabDataHour.boll_low=System::Convert::ToDouble(this->textBoxHourBollLow->Text);
		 }
	private: System::Void textBox45MinBollLow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinBollLow->Text)) return ;
		 	tabData45Min.boll_low=System::Convert::ToDouble(this->textBox45MinBollLow->Text);
		 }
	private: System::Void textBox30MinBollLow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinBollLow->Text)) return ;
		 	tabData30Min.boll_low=System::Convert::ToDouble(this->textBox30MinBollLow->Text);
		 }
	private: System::Void textBox15MinBollLow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinBollLow->Text)) return ;
		 	tabData15Min.boll_low=System::Convert::ToDouble(this->textBox15MinBollLow->Text);
		 }
	private: System::Void textBox10MinBollLow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinBollLow->Text)) return ;
		 	tabData10Min.boll_low=System::Convert::ToDouble(this->textBox10MinBollLow->Text);
		 }
	private: System::Void textBox5MinBollLow_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinBollLow->Text)) return ;
		 	tabData5Min.boll_low=System::Convert::ToDouble(this->textBox5MinBollLow->Text);
		 }
	private: System::Void textBoxYearBollMid_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearBollMid->Text)) return ;
		 	tabDataYear.boll_mid=System::Convert::ToDouble(this->textBoxYearBollMid->Text);
		 }
	private: System::Void textBoxMonthBollMid_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthBollMid->Text)) return ;
		 	tabDataMonth.boll_mid=System::Convert::ToDouble(this->textBoxMonthBollMid->Text);
		 }
	private: System::Void textBoxWeekBollMid_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekBollMid->Text)) return ;
		 	tabDataWeek.boll_mid=System::Convert::ToDouble(this->textBoxWeekBollMid->Text);
		 }
	private: System::Void textBoxDayBollMid_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayBollMid->Text)) return ;
		 	tabDataDay.boll_mid=System::Convert::ToDouble(this->textBoxDayBollMid->Text);
		 }
	private: System::Void textBox4HourBollMid_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourBollMid->Text)) return ;
		 	tabData4Hour.boll_mid=System::Convert::ToDouble(this->textBox4HourBollMid->Text);
		 }
	private: System::Void textBoxHourBollMid_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourBollMid->Text)) return ;
		 	tabDataHour.boll_mid=System::Convert::ToDouble(this->textBoxHourBollMid->Text);
		 }
	private: System::Void textBox45MinBollMid_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinBollMid->Text)) return ;
		 	tabData45Min.boll_mid=System::Convert::ToDouble(this->textBox45MinBollMid->Text);
		 }
	private: System::Void textBox30MinBollMid_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinBollMid->Text)) return ;
		 	tabData30Min.boll_mid=System::Convert::ToDouble(this->textBox30MinBollMid->Text);
		 }
	private: System::Void textBox15MinBollMid_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinBollMid->Text)) return ;
		 	tabData15Min.boll_mid=System::Convert::ToDouble(this->textBox15MinBollMid->Text);
		 }
	private: System::Void textBox10MinBollMid_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinBollMid->Text)) return ;
		 	tabData10Min.boll_mid=System::Convert::ToDouble(this->textBox10MinBollMid->Text);
		 }
	private: System::Void textBox5MinBollMid_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinBollMid->Text)) return ;
		 	tabData5Min.boll_mid=System::Convert::ToDouble(this->textBox5MinBollMid->Text);
		 }
	private: System::Void textBoxYearBollUpper_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearBollUpper->Text)) return ;
		 	tabDataYear.boll_upper=System::Convert::ToDouble(this->textBoxYearBollUpper->Text);
		 }
	private: System::Void textBoxMonthBollUpper_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthBollUpper->Text)) return ;
		 	tabDataMonth.boll_upper=System::Convert::ToDouble(this->textBoxMonthBollUpper->Text);
		 }
	private: System::Void textBoxWeekBollUpper_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekBollUpper->Text)) return ;
		 	tabDataWeek.boll_upper=System::Convert::ToDouble(this->textBoxWeekBollUpper->Text);
		 }
	private: System::Void textBoxDayBollUpper_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayBollUpper->Text)) return ;
		 	tabDataDay.boll_upper=System::Convert::ToDouble(this->textBoxDayBollUpper->Text);
		 }
	private: System::Void textBox4HourBollUpper_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourBollUpper->Text)) return ;
		 	tabData4Hour.boll_upper=System::Convert::ToDouble(this->textBox4HourBollUpper->Text);
		 }
	private: System::Void textBoxHourBollUpper_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourBollUpper->Text)) return ;
		 	tabDataHour.boll_upper=System::Convert::ToDouble(this->textBoxHourBollUpper->Text);
		 }
	private: System::Void textBox45MinBollUpper_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinBollUpper->Text)) return ;
		 	tabData45Min.boll_upper=System::Convert::ToDouble(this->textBox45MinBollUpper->Text);
		 }
	private: System::Void textBox30MinBollUpper_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinBollUpper->Text)) return ;
		 	tabData30Min.boll_upper=System::Convert::ToDouble(this->textBox30MinBollUpper->Text);
		 }
	private: System::Void textBox15MinBollUpper_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinBollUpper->Text)) return ;
		 	tabData15Min.boll_upper=System::Convert::ToDouble(this->textBox15MinBollUpper->Text);
		 }
	private: System::Void textBox10MinBollUpper_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinBollUpper->Text)) return ;
		 	tabData10Min.boll_upper=System::Convert::ToDouble(this->textBox10MinBollUpper->Text);
		 }
	private: System::Void textBox5MinBollUpper_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinBollUpper->Text)) return ;
		 	tabData5Min.boll_upper=System::Convert::ToDouble(this->textBox5MinBollUpper->Text);
		 }
	private: System::Void textBoxYearMacdMacd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearMacdMacd->Text)) return ;
		 	tabDataYear.macd_macd=System::Convert::ToDouble(this->textBoxYearMacdMacd->Text);
		 }
	private: System::Void textBoxMonthMacdMacd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthMacdMacd->Text)) return ;
		 	tabDataMonth.macd_macd=System::Convert::ToDouble(this->textBoxMonthMacdMacd->Text);
		 }
	private: System::Void textBoxWeekMacdMacd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekMacdMacd->Text)) return ;
		 	tabDataWeek.macd_macd=System::Convert::ToDouble(this->textBoxWeekMacdMacd->Text);
		 }
	private: System::Void textBoxDayMacdMacd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayMacdMacd->Text)) return ;
		 	tabDataDay.macd_macd=System::Convert::ToDouble(this->textBoxDayMacdMacd->Text);
		 }
	private: System::Void textBox4HourMacdMacd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourMacdMacd->Text)) return ;
		 	tabData4Hour.macd_macd=System::Convert::ToDouble(this->textBox4HourMacdMacd->Text);
		 }
	private: System::Void textBoxHourMacdMacd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourMacdMacd->Text)) return ;
		 	tabDataHour.macd_macd=System::Convert::ToDouble(this->textBoxHourMacdMacd->Text);
		 }
	private: System::Void textBox45MinMacdMacd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinMacdMacd->Text)) return ;
		 	tabData45Min.macd_macd=System::Convert::ToDouble(this->textBox45MinMacdMacd->Text);
		 }
	private: System::Void textBox30MinMacdMacd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinMacdMacd->Text)) return ;
		 	tabData30Min.macd_macd=System::Convert::ToDouble(this->textBox30MinMacdMacd->Text);
		 }
	private: System::Void textBox15MinMacdMacd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinMacdMacd->Text)) return ;
		 	tabData15Min.macd_macd=System::Convert::ToDouble(this->textBox15MinMacdMacd->Text);
		 }
	private: System::Void textBox10MinMacdMacd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinMacdMacd->Text)) return ;
		 	tabData10Min.macd_macd=System::Convert::ToDouble(this->textBox10MinMacdMacd->Text);
		 }
	private: System::Void textBox5MinMacdMacd_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinMacdMacd->Text)) return ;
		 	tabData5Min.macd_macd=System::Convert::ToDouble(this->textBox5MinMacdMacd->Text);
		 }
	private: System::Void textBoxYearMacdDif_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearMacdDif->Text)) return ;
		 	tabDataYear.macd_dif=System::Convert::ToDouble(this->textBoxYearMacdDif->Text);
		 }
	private: System::Void textBoxMonthMacdDif_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthMacdDif->Text)) return ;
		 	tabDataMonth.macd_dif=System::Convert::ToDouble(this->textBoxMonthMacdDif->Text);
		 }
	private: System::Void textBoxWeekMacdDif_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekMacdDif->Text)) return ;
		 	tabDataWeek.macd_dif=System::Convert::ToDouble(this->textBoxWeekMacdDif->Text);
		 }
	private: System::Void textBoxDayMacdDif_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayMacdDif->Text)) return ;
		 	tabDataDay.macd_dif=System::Convert::ToDouble(this->textBoxDayMacdDif->Text);
		 }
	private: System::Void textBox4HourMacdDif_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourMacdDif->Text)) return ;
		 	tabData4Hour.macd_dif=System::Convert::ToDouble(this->textBox4HourMacdDif->Text);
		 }
	private: System::Void textBoxHourMacdDif_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourMacdDif->Text)) return ;
		 	tabDataHour.macd_dif=System::Convert::ToDouble(this->textBoxHourMacdDif->Text);
		 }
	private: System::Void textBox45MinMacdDif_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinMacdDif->Text)) return ;
		 	tabData45Min.macd_dif=System::Convert::ToDouble(this->textBox45MinMacdDif->Text);
		 }
	private: System::Void textBox30MinMacdDif_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinMacdDif->Text)) return ;
		 	tabData30Min.macd_dif=System::Convert::ToDouble(this->textBox30MinMacdDif->Text);
		 }
	private: System::Void textBox15MinMacdDif_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinMacdDif->Text)) return ;
		 	tabData15Min.macd_dif=System::Convert::ToDouble(this->textBox15MinMacdDif->Text);
		 }
	private: System::Void textBox10MinMacdDif_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinMacdDif->Text)) return ;
		 	tabData10Min.macd_dif=System::Convert::ToDouble(this->textBox10MinMacdDif->Text);
		 }
	private: System::Void textBox5MinMacdDif_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinMacdDif->Text)) return ;
		 	tabData5Min.macd_dif=System::Convert::ToDouble(this->textBox5MinMacdDif->Text);
		 }
	private: System::Void textBoxYearMacdDea_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearMacdDea->Text)) return ;
		 	tabDataYear.macd_dea=System::Convert::ToDouble(this->textBoxYearMacdDea->Text);
		 }
	private: System::Void textBoxMonthMacdDea_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthMacdDea->Text)) return ;
		 	tabDataMonth.macd_dea=System::Convert::ToDouble(this->textBoxMonthMacdDea->Text);
		 }
	private: System::Void textBoxWeekMacdDea_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekMacdDea->Text)) return ;
		 	tabDataWeek.macd_dea=System::Convert::ToDouble(this->textBoxWeekMacdDea->Text);
		 }
	private: System::Void textBoxDayMacdDea_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayMacdDea->Text)) return ;
		 	tabDataDay.macd_dea=System::Convert::ToDouble(this->textBoxDayMacdDea->Text);
		 }
	private: System::Void textBox4HourMacdDea_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourMacdDea->Text)) return ;
		 	tabData4Hour.macd_dea=System::Convert::ToDouble(this->textBox4HourMacdDea->Text);
		 }
	private: System::Void textBoxHourMacdDea_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourMacdDea->Text)) return ;
		 	tabDataHour.macd_dea=System::Convert::ToDouble(this->textBoxHourMacdDea->Text);
		 }
	private: System::Void textBox45MinMacdDea_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinMacdDea->Text)) return ;
		 	tabData45Min.macd_dea=System::Convert::ToDouble(this->textBox45MinMacdDea->Text);
		 }
	private: System::Void textBox30MinMacdDea_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinMacdDea->Text)) return ;
		 	tabData30Min.macd_dea=System::Convert::ToDouble(this->textBox30MinMacdDea->Text);
		 }
	private: System::Void textBox15MinMacdDea_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinMacdDea->Text)) return ;
		 	tabData15Min.macd_dea=System::Convert::ToDouble(this->textBox15MinMacdDea->Text);
		 }
	private: System::Void textBox10MinMacdDea_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinMacdDea->Text)) return ;
		 	tabData10Min.macd_dea=System::Convert::ToDouble(this->textBox10MinMacdDea->Text);
		 }
	private: System::Void textBox5MinMacdDea_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinMacdDea->Text)) return ;
		 	tabData5Min.macd_dea=System::Convert::ToDouble(this->textBox5MinMacdDea->Text);
		 }
	private: System::Void textBoxYearKdjK_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearKdjK->Text)) return ;
		 	tabDataYear.kdj_k=System::Convert::ToDouble(this->textBoxYearKdjK->Text);
		 }
	private: System::Void textBoxMonthKdjK_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthKdjK->Text)) return ;
		 	tabDataMonth.kdj_k=System::Convert::ToDouble(this->textBoxMonthKdjK->Text);
		 }
	private: System::Void textBoxWeekKdjK_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekKdjK->Text)) return ;
		 	tabDataWeek.kdj_k=System::Convert::ToDouble(this->textBoxWeekKdjK->Text);
		 }
	private: System::Void textBoxDayKdjK_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayKdjK->Text)) return ;
		 	tabDataDay.kdj_k=System::Convert::ToDouble(this->textBoxDayKdjK->Text);
		 }
	private: System::Void textBox4HourKdjK_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourKdjK->Text)) return ;
		 	tabData4Hour.kdj_k=System::Convert::ToDouble(this->textBox4HourKdjK->Text);
		 }
	private: System::Void textBoxHourKdjK_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourKdjK->Text)) return ;
		 	tabDataHour.kdj_k=System::Convert::ToDouble(this->textBoxHourKdjK->Text);
		 }
	private: System::Void textBox45MinKdjK_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinKdjK->Text)) return ;
		 	tabData45Min.kdj_k=System::Convert::ToDouble(this->textBox45MinKdjK->Text);
		 }
	private: System::Void textBox30MinKdjK_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinKdjK->Text)) return ;
		 	tabData30Min.kdj_k=System::Convert::ToDouble(this->textBox30MinKdjK->Text);
		 }
	private: System::Void textBox15MinKdjK_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinKdjK->Text)) return ;
		 	tabData15Min.kdj_k=System::Convert::ToDouble(this->textBox15MinKdjK->Text);
		 }
	private: System::Void textBox10MinKdjK_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinKdjK->Text)) return ;
		 	tabData10Min.kdj_k=System::Convert::ToDouble(this->textBox10MinKdjK->Text);
		 }
	private: System::Void textBox5MinKdjK_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinKdjK->Text)) return ;
		 	tabData5Min.kdj_k=System::Convert::ToDouble(this->textBox5MinKdjK->Text);
		 }
	private: System::Void textBoxYearKdjD_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearKdjD->Text)) return ;
		 	tabDataYear.kdj_d=System::Convert::ToDouble(this->textBoxYearKdjD->Text);
		 }
	private: System::Void textBoxMonthKdjD_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthKdjD->Text)) return ;
		 	tabDataMonth.kdj_d=System::Convert::ToDouble(this->textBoxMonthKdjD->Text);
		 }
	private: System::Void textBoxWeekKdjD_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekKdjD->Text)) return ;
		 	tabDataWeek.kdj_d=System::Convert::ToDouble(this->textBoxWeekKdjD->Text);
		 }
	private: System::Void textBoxDayKdjD_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayKdjD->Text)) return ;
		 	tabDataDay.kdj_d=System::Convert::ToDouble(this->textBoxDayKdjD->Text);
		 }
	private: System::Void textBox4HourKdjD_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourKdjD->Text)) return ;
		 	tabData4Hour.kdj_d=System::Convert::ToDouble(this->textBox4HourKdjD->Text);
		 }
	private: System::Void textBoxHourKdjD_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourKdjD->Text)) return ;
		 	tabDataHour.kdj_d=System::Convert::ToDouble(this->textBoxHourKdjD->Text);
		 }
	private: System::Void textBox45MinKdjD_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinKdjD->Text)) return ;
		 	tabData45Min.kdj_d=System::Convert::ToDouble(this->textBox45MinKdjD->Text);
		 }
	private: System::Void textBox30MinKdjD_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinKdjD->Text)) return ;
		 	tabData30Min.kdj_d=System::Convert::ToDouble(this->textBox30MinKdjD->Text);
		 }
	private: System::Void textBox15MinKdjD_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinKdjD->Text)) return ;
		 	tabData15Min.kdj_d=System::Convert::ToDouble(this->textBox15MinKdjD->Text);
		 }
	private: System::Void textBox10MinKdjD_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinKdjD->Text)) return ;
		 	tabData10Min.kdj_d=System::Convert::ToDouble(this->textBox10MinKdjD->Text);
		 }
	private: System::Void textBox5MinKdjD_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinKdjD->Text)) return ;
		 	tabData5Min.kdj_d=System::Convert::ToDouble(this->textBox5MinKdjD->Text);
		 }
	private: System::Void textBoxYearKdjJ_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearKdjJ->Text)) return ;
		 	tabDataYear.kdj_j=System::Convert::ToDouble(this->textBoxYearKdjJ->Text);
		 }
	private: System::Void textBoxMonthKdjJ_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthKdjJ->Text)) return ;
		 	tabDataMonth.kdj_j=System::Convert::ToDouble(this->textBoxMonthKdjJ->Text);
		 }
	private: System::Void textBoxWeekKdjJ_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekKdjJ->Text)) return ;
		 	tabDataWeek.kdj_j=System::Convert::ToDouble(this->textBoxWeekKdjJ->Text);
		 }
	private: System::Void textBoxDayKdjJ_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayKdjJ->Text)) return ;
		 	tabDataDay.kdj_j=System::Convert::ToDouble(this->textBoxDayKdjJ->Text);
		 }
	private: System::Void textBox4HourKdjJ_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourKdjJ->Text)) return ;
		 	tabData4Hour.kdj_j=System::Convert::ToDouble(this->textBox4HourKdjJ->Text);
		 }
	private: System::Void textBoxHourKdjJ_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourKdjJ->Text)) return ;
		 	tabDataHour.kdj_j=System::Convert::ToDouble(this->textBoxHourKdjJ->Text);
		 }
	private: System::Void textBox45MinKdjJ_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinKdjJ->Text)) return ;
		 	tabData45Min.kdj_j=System::Convert::ToDouble(this->textBox45MinKdjJ->Text);
		 }
	private: System::Void textBox30MinKdjJ_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinKdjJ->Text)) return ;
		 	tabData30Min.kdj_j=System::Convert::ToDouble(this->textBox30MinKdjJ->Text);
		 }
	private: System::Void textBox15MinKdjJ_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinKdjJ->Text)) return ;
		 	tabData15Min.kdj_j=System::Convert::ToDouble(this->textBox15MinKdjJ->Text);
		 }
	private: System::Void textBox10MinKdjJ_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinKdjJ->Text)) return ;
		 	tabData10Min.kdj_j=System::Convert::ToDouble(this->textBox10MinKdjJ->Text);
		 }
	private: System::Void textBox5MinKdjJ_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinKdjJ->Text)) return ;
		 	tabData5Min.kdj_j=System::Convert::ToDouble(this->textBox5MinKdjJ->Text);
		 }
	private: System::Void textBoxYearRsiShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearRsiShort->Text)) return ;
		 	tabDataYear.rsi_short=System::Convert::ToDouble(this->textBoxYearRsiShort->Text);
		 }
	private: System::Void textBoxMonthRsiShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthRsiShort->Text)) return ;
		 	tabDataMonth.rsi_short=System::Convert::ToDouble(this->textBoxMonthRsiShort->Text);
		 }
	private: System::Void textBoxWeekRsiShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekRsiShort->Text)) return ;
		 	tabDataWeek.rsi_short=System::Convert::ToDouble(this->textBoxWeekRsiShort->Text);
		 }
	private: System::Void textBoxDayRsiShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayRsiShort->Text)) return ;
		 	tabDataDay.rsi_short=System::Convert::ToDouble(this->textBoxDayRsiShort->Text);
		 }
	private: System::Void textBox4HourRsiShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourRsiShort->Text)) return ;
		 	tabData4Hour.rsi_short=System::Convert::ToDouble(this->textBox4HourRsiShort->Text);
		 }
	private: System::Void textBoxHourRsiShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourRsiShort->Text)) return ;
		 	tabDataHour.rsi_short=System::Convert::ToDouble(this->textBoxHourRsiShort->Text);
		 }
	private: System::Void textBox45MinRsiShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinRsiShort->Text)) return ;
		 	tabData45Min.rsi_short=System::Convert::ToDouble(this->textBox45MinRsiShort->Text);
		 }
	private: System::Void textBox30MinRsiShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinRsiShort->Text)) return ;
		 	tabData30Min.rsi_short=System::Convert::ToDouble(this->textBox30MinRsiShort->Text);
		 }
	private: System::Void textBox15MinRsiShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinRsiShort->Text)) return ;
		 	tabData15Min.rsi_short=System::Convert::ToDouble(this->textBox15MinRsiShort->Text);
		 }
	private: System::Void textBox10MinRsiShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinRsiShort->Text)) return ;
		 	tabData10Min.rsi_short=System::Convert::ToDouble(this->textBox10MinRsiShort->Text);
		 }
	private: System::Void textBox5MinRsiShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinRsiShort->Text)) return ;
		 	tabData5Min.rsi_short=System::Convert::ToDouble(this->textBox5MinRsiShort->Text);
		 }
	private: System::Void textBoxYearRsiMiddle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearRsiMiddle->Text)) return ;
		 	tabDataYear.rsi_middle=System::Convert::ToDouble(this->textBoxYearRsiMiddle->Text);
		 }
	private: System::Void textBoxMonthRsiMiddle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthRsiMiddle->Text)) return ;
		 	tabDataMonth.rsi_middle=System::Convert::ToDouble(this->textBoxMonthRsiMiddle->Text);
		 }
	private: System::Void textBoxWeekRsiMiddle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekRsiMiddle->Text)) return ;
		 	tabDataWeek.rsi_middle=System::Convert::ToDouble(this->textBoxWeekRsiMiddle->Text);
		 }
	private: System::Void textBoxDayRsiMiddle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayRsiMiddle->Text)) return ;
		 	tabDataDay.rsi_middle=System::Convert::ToDouble(this->textBoxDayRsiMiddle->Text);
		 }
	private: System::Void textBox4HourRsiMiddle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourRsiMiddle->Text)) return ;
		 	tabData4Hour.rsi_middle=System::Convert::ToDouble(this->textBox4HourRsiMiddle->Text);
		 }
	private: System::Void textBoxHourRsiMiddle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourRsiMiddle->Text)) return ;
		 	tabDataHour.rsi_middle=System::Convert::ToDouble(this->textBoxHourRsiMiddle->Text);
		 }
	private: System::Void textBox45MinRsiMiddle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinRsiMiddle->Text)) return ;
		 	tabData45Min.rsi_middle=System::Convert::ToDouble(this->textBox45MinRsiMiddle->Text);
		 }
	private: System::Void textBox30MinRsiMiddle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinRsiMiddle->Text)) return ;
		 	tabData30Min.rsi_middle=System::Convert::ToDouble(this->textBox30MinRsiMiddle->Text);
		 }
	private: System::Void textBox15MinRsiMiddle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinRsiMiddle->Text)) return ;
		 	tabData15Min.rsi_middle=System::Convert::ToDouble(this->textBox15MinRsiMiddle->Text);
		 }
	private: System::Void textBox10MinRsiMiddle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinRsiMiddle->Text)) return ;
		 	tabData10Min.rsi_middle=System::Convert::ToDouble(this->textBox10MinRsiMiddle->Text);
		 }
	private: System::Void textBox5MinRsiMiddle_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinRsiMiddle->Text)) return ;
		 	tabData5Min.rsi_middle=System::Convert::ToDouble(this->textBox5MinRsiMiddle->Text);
		 }
	private: System::Void textBoxYearRsiLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearRsiLong->Text)) return ;
		 	tabDataYear.rsi_long=System::Convert::ToDouble(this->textBoxYearRsiLong->Text);
		 }
	private: System::Void textBoxMonthRsiLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthRsiLong->Text)) return ;
		 	tabDataMonth.rsi_long=System::Convert::ToDouble(this->textBoxMonthRsiLong->Text);
		 }
	private: System::Void textBoxWeekRsiLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekRsiLong->Text)) return ;
		 	tabDataWeek.rsi_long=System::Convert::ToDouble(this->textBoxWeekRsiLong->Text);
		 }
	private: System::Void textBoxDayRsiLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayRsiLong->Text)) return ;
		 	tabDataDay.rsi_long=System::Convert::ToDouble(this->textBoxDayRsiLong->Text);
		 }
	private: System::Void textBox4HourRsiLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourRsiLong->Text)) return ;
		 	tabData4Hour.rsi_long=System::Convert::ToDouble(this->textBox4HourRsiLong->Text);
		 }
	private: System::Void textBoxHourRsiLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourRsiLong->Text)) return ;
		 	tabDataHour.rsi_long=System::Convert::ToDouble(this->textBoxHourRsiLong->Text);
		 }
	private: System::Void textBox45MinRsiLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinRsiLong->Text)) return ;
		 	tabData45Min.rsi_long=System::Convert::ToDouble(this->textBox45MinRsiLong->Text);
		 }
	private: System::Void textBox30MinRsiLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinRsiLong->Text)) return ;
		 	tabData30Min.rsi_long=System::Convert::ToDouble(this->textBox30MinRsiLong->Text);
		 }
	private: System::Void textBox15MinRsiLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinRsiLong->Text)) return ;
		 	tabData15Min.rsi_long=System::Convert::ToDouble(this->textBox15MinRsiLong->Text);
		 }
	private: System::Void textBox10MinRsiLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinRsiLong->Text)) return ;
		 	tabData10Min.rsi_long=System::Convert::ToDouble(this->textBox10MinRsiLong->Text);
		 }
	private: System::Void textBox5MinRsiLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinRsiLong->Text)) return ;
		 	tabData5Min.rsi_long=System::Convert::ToDouble(this->textBox5MinRsiLong->Text);
		 }
	private: System::Void textBoxYearWr1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearWr1->Text)) return ;
		 	tabDataYear.wr1=System::Convert::ToDouble(this->textBoxYearWr1->Text);
		 }
	private: System::Void textBoxMonthWr1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthWr1->Text)) return ;
		 	tabDataMonth.wr1=System::Convert::ToDouble(this->textBoxMonthWr1->Text);
		 }
	private: System::Void textBoxWeekWr1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekWr1->Text)) return ;
		 	tabDataWeek.wr1=System::Convert::ToDouble(this->textBoxWeekWr1->Text);
		 }
	private: System::Void textBoxDayWr1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayWr1->Text)) return ;
		 	tabDataDay.wr1=System::Convert::ToDouble(this->textBoxDayWr1->Text);
		 }
	private: System::Void textBox4HourWr1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourWr1->Text)) return ;
		 	tabData4Hour.wr1=System::Convert::ToDouble(this->textBox4HourWr1->Text);
		 }
	private: System::Void textBoxHourWr1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourWr1->Text)) return ;
		 	tabDataHour.wr1=System::Convert::ToDouble(this->textBoxHourWr1->Text);
		 }
	private: System::Void textBox45MinWr1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinWr1->Text)) return ;
		 	tabData45Min.wr1=System::Convert::ToDouble(this->textBox45MinWr1->Text);
		 }
	private: System::Void textBox30MinWr1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinWr1->Text)) return ;
		 	tabData30Min.wr1=System::Convert::ToDouble(this->textBox30MinWr1->Text);
		 }
	private: System::Void textBox15MinWr1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinWr1->Text)) return ;
		 	tabData15Min.wr1=System::Convert::ToDouble(this->textBox15MinWr1->Text);
		 }
	private: System::Void textBox10MinWr1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinWr1->Text)) return ;
		 	tabData10Min.wr1=System::Convert::ToDouble(this->textBox10MinWr1->Text);
		 }
	private: System::Void textBox5MinWr1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinWr1->Text)) return ;
		 	tabData5Min.wr1=System::Convert::ToDouble(this->textBox5MinWr1->Text);
		 }
	private: System::Void textBoxYearWr2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearWr2->Text)) return ;
		 	tabDataYear.wr2=System::Convert::ToDouble(this->textBoxYearWr2->Text);
		 }
	private: System::Void textBoxMonthWr2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthWr2->Text)) return ;
		 	tabDataMonth.wr2=System::Convert::ToDouble(this->textBoxMonthWr2->Text);
		 }
	private: System::Void textBoxWeekWr2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekWr2->Text)) return ;
		 	tabDataWeek.wr2=System::Convert::ToDouble(this->textBoxWeekWr2->Text);
		 }
	private: System::Void textBoxDayWr2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayWr2->Text)) return ;
		 	tabDataDay.wr2=System::Convert::ToDouble(this->textBoxDayWr2->Text);
		 }
	private: System::Void textBox4HourWr2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourWr2->Text)) return ;
		 	tabData4Hour.wr2=System::Convert::ToDouble(this->textBox4HourWr2->Text);
		 }
	private: System::Void textBoxHourWr2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourWr2->Text)) return ;
		 	tabDataHour.wr2=System::Convert::ToDouble(this->textBoxHourWr2->Text);
		 }
	private: System::Void textBox45MinWr2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinWr2->Text)) return ;
		 	tabData45Min.wr2=System::Convert::ToDouble(this->textBox45MinWr2->Text);
		 }
	private: System::Void textBox30MinWr2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinWr2->Text)) return ;
		 	tabData30Min.wr2=System::Convert::ToDouble(this->textBox30MinWr2->Text);
		 }
	private: System::Void textBox15MinWr2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinWr2->Text)) return ;
		 	tabData15Min.wr2=System::Convert::ToDouble(this->textBox15MinWr2->Text);
		 }
	private: System::Void textBox10MinWr2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinWr2->Text)) return ;
		 	tabData10Min.wr2=System::Convert::ToDouble(this->textBox10MinWr2->Text);
		 }
	private: System::Void textBox5MinWr2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinWr2->Text)) return ;
		 	tabData5Min.wr2=System::Convert::ToDouble(this->textBox5MinWr2->Text);
		 }
	private: System::Void textBoxYearRocRoc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearRocRoc->Text)) return ;
		 	tabDataYear.roc=System::Convert::ToDouble(this->textBoxYearRocRoc->Text);
		 }
	private: System::Void textBoxMonthRocRoc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthRocRoc->Text)) return ;
		 	tabDataMonth.roc=System::Convert::ToDouble(this->textBoxMonthRocRoc->Text);
		 }
	private: System::Void textBoxWeekRocRoc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekRocRoc->Text)) return ;
		 	tabDataWeek.roc=System::Convert::ToDouble(this->textBoxWeekRocRoc->Text);
		 }
	private: System::Void textBoxDayRocRoc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayRocRoc->Text)) return ;
		 	tabDataDay.roc=System::Convert::ToDouble(this->textBoxDayRocRoc->Text);
		 }
	private: System::Void textBox4HourRocRoc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourRocRoc->Text)) return ;
		 	tabData4Hour.roc=System::Convert::ToDouble(this->textBox4HourRocRoc->Text);
		 }
	private: System::Void textBoxHourRocRoc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourRocRoc->Text)) return ;
		 	tabDataHour.roc=System::Convert::ToDouble(this->textBoxHourRocRoc->Text);
		 }
	private: System::Void textBox45MinRocRoc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinRocRoc->Text)) return ;
		 	tabData45Min.roc=System::Convert::ToDouble(this->textBox45MinRocRoc->Text);
		 }
	private: System::Void textBox30MinRocRoc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinRocRoc->Text)) return ;
		 	tabData30Min.roc=System::Convert::ToDouble(this->textBox30MinRocRoc->Text);
		 }
	private: System::Void textBox15MinRocRoc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinRocRoc->Text)) return ;
		 	tabData15Min.roc=System::Convert::ToDouble(this->textBox15MinRocRoc->Text);
		 }
	private: System::Void textBox10MinRocRoc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinRocRoc->Text)) return ;
		 	tabData10Min.roc=System::Convert::ToDouble(this->textBox10MinRocRoc->Text);
		 }
	private: System::Void textBox5MinRocRoc_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinRocRoc->Text)) return ;
		 	tabData5Min.roc=System::Convert::ToDouble(this->textBox5MinRocRoc->Text);
		 }
	private: System::Void textBoxYearRocRocma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearRocRocma->Text)) return ;
		 	tabDataYear.roc_ma=System::Convert::ToDouble(this->textBoxYearRocRocma->Text);
		 }
	private: System::Void textBoxMonthRocRocma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthRocRocma->Text)) return ;
		 	tabDataMonth.roc_ma=System::Convert::ToDouble(this->textBoxMonthRocRocma->Text);
		 }
	private: System::Void textBoxWeekRocRocma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekRocRocma->Text)) return ;
		 	tabDataWeek.roc_ma=System::Convert::ToDouble(this->textBoxWeekRocRocma->Text);
		 }
	private: System::Void textBoxDayRocRocma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayRocRocma->Text)) return ;
		 	tabDataDay.roc_ma=System::Convert::ToDouble(this->textBoxDayRocRocma->Text);
		 }
	private: System::Void textBox4HourRocRocma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourRocRocma->Text)) return ;
		 	tabData4Hour.roc_ma=System::Convert::ToDouble(this->textBox4HourRocRocma->Text);
		 }
	private: System::Void textBoxHourRocRocma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourRocRocma->Text)) return ;
		 	tabDataHour.roc_ma=System::Convert::ToDouble(this->textBoxHourRocRocma->Text);
		 }
	private: System::Void textBox45MinRocRocma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinRocRocma->Text)) return ;
		 	tabData45Min.roc_ma=System::Convert::ToDouble(this->textBox45MinRocRocma->Text);
		 }
	private: System::Void textBox30MinRocRocma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinRocRocma->Text)) return ;
		 	tabData30Min.roc_ma=System::Convert::ToDouble(this->textBox30MinRocRocma->Text);
		 }
	private: System::Void textBox15MinRocRocma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinRocRocma->Text)) return ;
		 	tabData15Min.roc_ma=System::Convert::ToDouble(this->textBox15MinRocRocma->Text);
		 }
	private: System::Void textBox10MinRocRocma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinRocRocma->Text)) return ;
		 	tabData10Min.roc_ma=System::Convert::ToDouble(this->textBox10MinRocRocma->Text);
		 }
	private: System::Void textBox5MinRocRocma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinRocRocma->Text)) return ;
		 	tabData5Min.roc_ma=System::Convert::ToDouble(this->textBox5MinRocRocma->Text);
		 }
	private: System::Void textBoxYearVrShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearVrShort->Text)) return ;
		 	tabDataYear.vr_short=System::Convert::ToDouble(this->textBoxYearVrShort->Text);
		 }
	private: System::Void textBoxMonthVrShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthVrShort->Text)) return ;
		 	tabDataMonth.vr_short=System::Convert::ToDouble(this->textBoxMonthVrShort->Text);
		 }
	private: System::Void textBoxWeekVrShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekVrShort->Text)) return ;
		 	tabDataWeek.vr_short=System::Convert::ToDouble(this->textBoxWeekVrShort->Text);
		 }
	private: System::Void textBoxDayVrShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayVrShort->Text)) return ;
		 	tabDataDay.vr_short=System::Convert::ToDouble(this->textBoxDayVrShort->Text);
		 }
	private: System::Void textBox4HourVrShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourVrShort->Text)) return ;
		 	tabData4Hour.vr_short=System::Convert::ToDouble(this->textBox4HourVrShort->Text);
		 }
	private: System::Void textBoxHourVrShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourVrShort->Text)) return ;
		 	tabDataHour.vr_short=System::Convert::ToDouble(this->textBoxHourVrShort->Text);
		 }
	private: System::Void textBox45MinVrShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinVrShort->Text)) return ;
		 	tabData45Min.vr_short=System::Convert::ToDouble(this->textBox45MinVrShort->Text);
		 }
	private: System::Void textBox30MinVrShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinVrShort->Text)) return ;
		 	tabData30Min.vr_short=System::Convert::ToDouble(this->textBox30MinVrShort->Text);
		 }
	private: System::Void textBox15MinVrShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinVrShort->Text)) return ;
		 	tabData15Min.vr_short=System::Convert::ToDouble(this->textBox15MinVrShort->Text);
		 }
	private: System::Void textBox10MinVrShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinVrShort->Text)) return ;
		 	tabData10Min.vr_short=System::Convert::ToDouble(this->textBox10MinVrShort->Text);
		 }
	private: System::Void textBox5MinVrShort_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinVrShort->Text)) return ;
		 	tabData5Min.vr_short=System::Convert::ToDouble(this->textBox5MinVrShort->Text);
		 }
	private: System::Void textBoxYearVrLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearVrLong->Text)) return ;
		 	tabDataYear.vr_long=System::Convert::ToDouble(this->textBoxYearVrLong->Text);
		 }
	private: System::Void textBoxMonthVrLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthVrLong->Text)) return ;
		 	tabDataMonth.vr_long=System::Convert::ToDouble(this->textBoxMonthVrLong->Text);
		 }
	private: System::Void textBoxWeekVrLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekVrLong->Text)) return ;
		 	tabDataWeek.vr_long=System::Convert::ToDouble(this->textBoxWeekVrLong->Text);
		 }
	private: System::Void textBoxDayVrLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayVrLong->Text)) return ;
		 	tabDataDay.vr_long=System::Convert::ToDouble(this->textBoxDayVrLong->Text);
		 }
	private: System::Void textBox4HourVrLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourVrLong->Text)) return ;
		 	tabData4Hour.vr_long=System::Convert::ToDouble(this->textBox4HourVrLong->Text);
		 }
	private: System::Void textBoxHourVrLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourVrLong->Text)) return ;
		 	tabDataHour.vr_long=System::Convert::ToDouble(this->textBoxHourVrLong->Text);
		 }
	private: System::Void textBox45MinVrLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinVrLong->Text)) return ;
		 	tabData45Min.vr_long=System::Convert::ToDouble(this->textBox45MinVrLong->Text);
		 }
	private: System::Void textBox30MinVrLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinVrLong->Text)) return ;
		 	tabData30Min.vr_long=System::Convert::ToDouble(this->textBox30MinVrLong->Text);
		 }
	private: System::Void textBox15MinVrLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinVrLong->Text)) return ;
		 	tabData15Min.vr_long=System::Convert::ToDouble(this->textBox15MinVrLong->Text);
		 }
	private: System::Void textBox10MinVrLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinVrLong->Text)) return ;
		 	tabData10Min.vr_long=System::Convert::ToDouble(this->textBox10MinVrLong->Text);
		 }
	private: System::Void textBox5MinVrLong_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinVrLong->Text)) return ;
		 	tabData5Min.vr_long=System::Convert::ToDouble(this->textBox5MinVrLong->Text);
		 }
	private: System::Void textBoxYearDmaDma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearDmaDma->Text)) return ;
		 	tabDataYear.dma=System::Convert::ToDouble(this->textBoxYearDmaDma->Text);
		 }
	private: System::Void textBoxMonthDmaDma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthDmaDma->Text)) return ;
		 	tabDataMonth.dma=System::Convert::ToDouble(this->textBoxMonthDmaDma->Text);
		 }
	private: System::Void textBoxWeekDmaDma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekDmaDma->Text)) return ;
		 	tabDataWeek.dma=System::Convert::ToDouble(this->textBoxWeekDmaDma->Text);
		 }
	private: System::Void textBoxDayDmaDma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayDmaDma->Text)) return ;
		 	tabDataDay.dma=System::Convert::ToDouble(this->textBoxDayDmaDma->Text);
		 }
	private: System::Void textBox4HourDmaDma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourDmaDma->Text)) return ;
		 	tabData4Hour.dma=System::Convert::ToDouble(this->textBox4HourDmaDma->Text);
		 }
	private: System::Void textBoxHourDmaDma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourDmaDma->Text)) return ;
		 	tabDataHour.dma=System::Convert::ToDouble(this->textBoxHourDmaDma->Text);
		 }
	private: System::Void textBox45MinDmaDma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinDmaDma->Text)) return ;
		 	tabData45Min.dma=System::Convert::ToDouble(this->textBox45MinDmaDma->Text);
		 }
	private: System::Void textBox30MinDmaDma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinDmaDma->Text)) return ;
		 	tabData30Min.dma=System::Convert::ToDouble(this->textBox30MinDmaDma->Text);
		 }
	private: System::Void textBox15MinDmaDma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinDmaDma->Text)) return ;
		 	tabData15Min.dma=System::Convert::ToDouble(this->textBox15MinDmaDma->Text);
		 }
	private: System::Void textBox10MinDmaDma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinDmaDma->Text)) return ;
		 	tabData10Min.dma=System::Convert::ToDouble(this->textBox10MinDmaDma->Text);
		 }
	private: System::Void textBox5MinDmaDma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinDmaDma->Text)) return ;
		 	tabData5Min.dma=System::Convert::ToDouble(this->textBox5MinDmaDma->Text);
		 }
	private: System::Void textBoxYearDmaAma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearDmaAma->Text)) return ;
		 	tabDataYear.dma_ama=System::Convert::ToDouble(this->textBoxYearDmaAma->Text);
		 }
	private: System::Void textBoxMonthDmaAma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthDmaAma->Text)) return ;
		 	tabDataMonth.dma_ama=System::Convert::ToDouble(this->textBoxMonthDmaAma->Text);
		 }
	private: System::Void textBoxWeekDmaAma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekDmaAma->Text)) return ;
		 	tabDataWeek.dma_ama=System::Convert::ToDouble(this->textBoxWeekDmaAma->Text);
		 }
	private: System::Void textBoxDayDmaAma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayDmaAma->Text)) return ;
		 	tabDataDay.dma_ama=System::Convert::ToDouble(this->textBoxDayDmaAma->Text);
		 }
	private: System::Void textBox4HourDmaAma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourDmaAma->Text)) return ;
		 	tabData4Hour.dma_ama=System::Convert::ToDouble(this->textBox4HourDmaAma->Text);
		 }
	private: System::Void textBoxHourDmaAma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourDmaAma->Text)) return ;
		 	tabDataHour.dma_ama=System::Convert::ToDouble(this->textBoxHourDmaAma->Text);
		 }
	private: System::Void textBox45MinDmaAma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinDmaAma->Text)) return ;
		 	tabData45Min.dma_ama=System::Convert::ToDouble(this->textBox45MinDmaAma->Text);
		 }
	private: System::Void textBox30MinDmaAma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinDmaAma->Text)) return ;
		 	tabData30Min.dma_ama=System::Convert::ToDouble(this->textBox30MinDmaAma->Text);
		 }
	private: System::Void textBox15MinDmaAma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinDmaAma->Text)) return ;
		 	tabData15Min.dma_ama=System::Convert::ToDouble(this->textBox15MinDmaAma->Text);
		 }
	private: System::Void textBox10MinDmaAma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinDmaAma->Text)) return ;
		 	tabData10Min.dma_ama=System::Convert::ToDouble(this->textBox10MinDmaAma->Text);
		 }
	private: System::Void textBox5MinDmaAma_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinDmaAma->Text)) return ;
		 	tabData5Min.dma_ama=System::Convert::ToDouble(this->textBox5MinDmaAma->Text);
		 }
	private: System::Void textBoxYearCrCr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearCrCr->Text)) return ;
		 	tabDataYear.cr=System::Convert::ToDouble(this->textBoxYearCrCr->Text);
		 }
	private: System::Void textBoxMonthCrCr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthCrCr->Text)) return ;
		 	tabDataMonth.cr=System::Convert::ToDouble(this->textBoxMonthCrCr->Text);
		 }
	private: System::Void textBoxWeekCrCr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekCrCr->Text)) return ;
		 	tabDataWeek.cr=System::Convert::ToDouble(this->textBoxWeekCrCr->Text);
		 }
	private: System::Void textBoxDayCrCr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayCrCr->Text)) return ;
		 	tabDataDay.cr=System::Convert::ToDouble(this->textBoxDayCrCr->Text);
		 }
	private: System::Void textBox4HourCrCr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourCrCr->Text)) return ;
		 	tabData4Hour.cr=System::Convert::ToDouble(this->textBox4HourCrCr->Text);
		 }
	private: System::Void textBoxHourCrCr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourCrCr->Text)) return ;
		 	tabDataHour.cr=System::Convert::ToDouble(this->textBoxHourCrCr->Text);
		 }
	private: System::Void textBox45MinCrCr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinCrCr->Text)) return ;
		 	tabData45Min.cr=System::Convert::ToDouble(this->textBox45MinCrCr->Text);
		 }
	private: System::Void textBox30MinCrCr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinCrCr->Text)) return ;
		 	tabData30Min.cr=System::Convert::ToDouble(this->textBox30MinCrCr->Text);
		 }
	private: System::Void textBox15MinCrCr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinCrCr->Text)) return ;
		 	tabData15Min.cr=System::Convert::ToDouble(this->textBox15MinCrCr->Text);
		 }
	private: System::Void textBox10MinCrCr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinCrCr->Text)) return ;
		 	tabData10Min.cr=System::Convert::ToDouble(this->textBox10MinCrCr->Text);
		 }
	private: System::Void textBox5MinCrCr_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinCrCr->Text)) return ;
		 	tabData5Min.cr=System::Convert::ToDouble(this->textBox5MinCrCr->Text);
		 }
	private: System::Void textBoxYearCrA_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearCrA->Text)) return ;
		 	tabDataYear.cr_a=System::Convert::ToDouble(this->textBoxYearCrA->Text);
		 }
	private: System::Void textBoxMonthCrA_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthCrA->Text)) return ;
		 	tabDataMonth.cr_a=System::Convert::ToDouble(this->textBoxMonthCrA->Text);
		 }
	private: System::Void textBoxWeekCrA_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekCrA->Text)) return ;
		 	tabDataWeek.cr_a=System::Convert::ToDouble(this->textBoxWeekCrA->Text);
		 }
	private: System::Void textBoxDayCrA_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayCrA->Text)) return ;
		 	tabDataDay.cr_a=System::Convert::ToDouble(this->textBoxDayCrA->Text);
		 }
	private: System::Void textBox4HourCrA_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourCrA->Text)) return ;
		 	tabData4Hour.cr_a=System::Convert::ToDouble(this->textBox4HourCrA->Text);
		 }
	private: System::Void textBoxHourCrA_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourCrA->Text)) return ;
		 	tabDataHour.cr_a=System::Convert::ToDouble(this->textBoxHourCrA->Text);
		 }
	private: System::Void textBox45MinCrA_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinCrA->Text)) return ;
		 	tabData45Min.cr_a=System::Convert::ToDouble(this->textBox45MinCrA->Text);
		 }
	private: System::Void textBox30MinCrA_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinCrA->Text)) return ;
		 	tabData30Min.cr_a=System::Convert::ToDouble(this->textBox30MinCrA->Text);
		 }
	private: System::Void textBox15MinCrA_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinCrA->Text)) return ;
		 	tabData15Min.cr_a=System::Convert::ToDouble(this->textBox15MinCrA->Text);
		 }
	private: System::Void textBox10MinCrA_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinCrA->Text)) return ;
		 	tabData10Min.cr_a=System::Convert::ToDouble(this->textBox10MinCrA->Text);
		 }
	private: System::Void textBox5MinCrA_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinCrA->Text)) return ;
		 	tabData5Min.cr_a=System::Convert::ToDouble(this->textBox5MinCrA->Text);
		 }
	private: System::Void textBoxYearCrB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearCrB->Text)) return ;
		 	tabDataYear.cr_b=System::Convert::ToDouble(this->textBoxYearCrB->Text);
		 }
	private: System::Void textBoxMonthCrB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthCrB->Text)) return ;
		 	tabDataMonth.cr_b=System::Convert::ToDouble(this->textBoxMonthCrB->Text);
		 }
	private: System::Void textBoxWeekCrB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekCrB->Text)) return ;
		 	tabDataWeek.cr_b=System::Convert::ToDouble(this->textBoxWeekCrB->Text);
		 }
	private: System::Void textBoxDayCrB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayCrB->Text)) return ;
		 	tabDataDay.cr_b=System::Convert::ToDouble(this->textBoxDayCrB->Text);
		 }
	private: System::Void textBox4HourCrB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourCrB->Text)) return ;
		 	tabData4Hour.cr_b=System::Convert::ToDouble(this->textBox4HourCrB->Text);
		 }
	private: System::Void textBoxHourCrB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourCrB->Text)) return ;
		 	tabDataHour.cr_b=System::Convert::ToDouble(this->textBoxHourCrB->Text);
		 }
	private: System::Void textBox45MinCrB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinCrB->Text)) return ;
		 	tabData45Min.cr_b=System::Convert::ToDouble(this->textBox45MinCrB->Text);
		 }
	private: System::Void textBox30MinCrB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinCrB->Text)) return ;
		 	tabData30Min.cr_b=System::Convert::ToDouble(this->textBox30MinCrB->Text);
		 }
	private: System::Void textBox15MinCrB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinCrB->Text)) return ;
		 	tabData15Min.cr_b=System::Convert::ToDouble(this->textBox15MinCrB->Text);
		 }
	private: System::Void textBox10MinCrB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinCrB->Text)) return ;
		 	tabData10Min.cr_b=System::Convert::ToDouble(this->textBox10MinCrB->Text);
		 }
	private: System::Void textBox5MinCrB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinCrB->Text)) return ;
		 	tabData5Min.cr_b=System::Convert::ToDouble(this->textBox5MinCrB->Text);
		 }
	private: System::Void textBoxYearCrC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearCrC->Text)) return ;
		 	tabDataYear.cr_c=System::Convert::ToDouble(this->textBoxYearCrC->Text);
		 }
	private: System::Void textBoxMonthCrC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthCrC->Text)) return ;
		 	tabDataMonth.cr_c=System::Convert::ToDouble(this->textBoxMonthCrC->Text);
		 }
	private: System::Void textBoxWeekCrC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekCrC->Text)) return ;
		 	tabDataWeek.cr_c=System::Convert::ToDouble(this->textBoxWeekCrC->Text);
		 }
	private: System::Void textBoxDayCrC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayCrC->Text)) return ;
		 	tabDataDay.cr_c=System::Convert::ToDouble(this->textBoxDayCrC->Text);
		 }
	private: System::Void textBox4HourCrC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourCrC->Text)) return ;
		 	tabData4Hour.cr_c=System::Convert::ToDouble(this->textBox4HourCrC->Text);
		 }
	private: System::Void textBoxHourCrC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourCrC->Text)) return ;
		 	tabDataHour.cr_c=System::Convert::ToDouble(this->textBoxHourCrC->Text);
		 }
	private: System::Void textBox45MinCrC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinCrC->Text)) return ;
		 	tabData45Min.cr_c=System::Convert::ToDouble(this->textBox45MinCrC->Text);
		 }
	private: System::Void textBox30MinCrC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinCrC->Text)) return ;
		 	tabData30Min.cr_c=System::Convert::ToDouble(this->textBox30MinCrC->Text);
		 }
	private: System::Void textBox15MinCrC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinCrC->Text)) return ;
		 	tabData15Min.cr_c=System::Convert::ToDouble(this->textBox15MinCrC->Text);
		 }
	private: System::Void textBox10MinCrC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinCrC->Text)) return ;
		 	tabData10Min.cr_c=System::Convert::ToDouble(this->textBox10MinCrC->Text);
		 }
	private: System::Void textBox5MinCrC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinCrC->Text)) return ;
		 	tabData5Min.cr_c=System::Convert::ToDouble(this->textBox5MinCrC->Text);
		 }
	private: System::Void textBoxYearCciCci_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxYearCciCci->Text)) return ;
		 	tabDataYear.cci=System::Convert::ToDouble(this->textBoxYearCciCci->Text);
		 }
	private: System::Void textBoxMonthCciCci_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxMonthCciCci->Text)) return ;
		 	tabDataMonth.cci=System::Convert::ToDouble(this->textBoxMonthCciCci->Text);
		 }
	private: System::Void textBoxWeekCciCci_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxWeekCciCci->Text)) return ;
		 	tabDataWeek.cci=System::Convert::ToDouble(this->textBoxWeekCciCci->Text);
		 }
	private: System::Void textBoxDayCciCci_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxDayCciCci->Text)) return ;
		 	tabDataDay.cci=System::Convert::ToDouble(this->textBoxDayCciCci->Text);
		 }
	private: System::Void textBox4HourCciCci_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox4HourCciCci->Text)) return ;
		 	tabData4Hour.cci=System::Convert::ToDouble(this->textBox4HourCciCci->Text);
		 }
	private: System::Void textBoxHourCciCci_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxHourCciCci->Text)) return ;
		 	tabDataHour.cci=System::Convert::ToDouble(this->textBoxHourCciCci->Text);
		 }
	private: System::Void textBox45MinCciCci_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox45MinCciCci->Text)) return ;
		 	tabData45Min.cci=System::Convert::ToDouble(this->textBox45MinCciCci->Text);
		 }
	private: System::Void textBox30MinCciCci_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox30MinCciCci->Text)) return ;
		 	tabData30Min.cci=System::Convert::ToDouble(this->textBox30MinCciCci->Text);
		 }
	private: System::Void textBox15MinCciCci_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox15MinCciCci->Text)) return ;
		 	tabData15Min.cci=System::Convert::ToDouble(this->textBox15MinCciCci->Text);
		 }
	private: System::Void textBox10MinCciCci_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox10MinCciCci->Text)) return ;
		 	tabData10Min.cci=System::Convert::ToDouble(this->textBox10MinCciCci->Text);
		 }
	private: System::Void textBox5MinCciCci_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBox5MinCciCci->Text)) return ;
		 	tabData5Min.cci=System::Convert::ToDouble(this->textBox5MinCciCci->Text);
		 }
private: System::Void textBoxPrice_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(0==this->isNumber(this->textBoxPrice->Text)) return ;
			 price=System::Convert::ToDouble(this->textBoxPrice->Text);
		 }
private: System::Void textBoxObject_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 String ^str = this->textBoxObject->Text;

			 // Pin memory so GC can't move it while native function is called
			 pin_ptr<const wchar_t> wch = PtrToStringChars(str);
			 printf_s("%S\n", wch);

			 // Conversion to char* :
			 // Can just convert wchar_t* to char* using one of the 
			 // conversion functions such as: 
			 // WideCharToMultiByte()
			 // wcstombs_s()
			 // ... etc
			 size_t convertedChars = 0;
			 size_t  sizeInBytes = ((str->Length + 1) * 2);
			 errno_t err = 0;
			 char    *ch = object;//(char *)malloc(sizeInBytes);
			 if(sizeInBytes>OBJECT_LEN)sizeInBytes=OBJECT_LEN-2;

			 err = wcstombs_s(&convertedChars, 
				 ch, sizeInBytes,
				 wch, sizeInBytes);
			// if (err != 0)
				 //printf_s("wcstombs_s  failed!\n");

			// printf_s("%s\n", ch);

		 }
private: System::Void settingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				OperateSettingForm opset;
				opset.ShowDialog();
		 }
private: System::Void donateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 DonateForm donate;
			 donate.ShowDialog();
		 }
};
}
