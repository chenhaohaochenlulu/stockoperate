#pragma once
#include "operateSetting.h"
CoperateSetting bollSetting,kdjSetting,rsiSetting,rocSetting,wrSetting,macdSetting,dmaSetting,vrSetting,cciSetting,crSetting,maSetting,volSetting;
#ifndef  OBJECT_LEN
#define OBJECT_LEN	0x100
#endif
char object_setting[OBJECT_LEN];
char fileName[OBJECT_LEN+4];
namespace OperateSetting {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for OperateSettingForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class OperateSettingForm : public System::Windows::Forms::Form
	{
	public:
		OperateSettingForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OperateSettingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxObject;
	protected: 
	protected: 
	private: System::Windows::Forms::Label^  labelObject;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBoxWrTop;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  textBoxWrBottom;
	private: System::Windows::Forms::ListBox^  listBoxWr;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  textBoxRocTop;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  textBoxRocBottom;
	private: System::Windows::Forms::ListBox^  listBoxRoc;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBoxRsiTop;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBoxRsiBottom;
	private: System::Windows::Forms::ListBox^  listBoxRsi;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBoxKdjSellCross;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBoxKdjBuyCross;
	private: System::Windows::Forms::ListBox^  listBoxKdj;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBoxBollSell;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxBollBuy;

	private: System::Windows::Forms::ListBox^  listBoxBoll;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  labelBoll;
	private: System::Windows::Forms::ListBox^  listBoxWrNeg;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::TextBox^  textBoxVrTop;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::TextBox^  textBoxVrBottom;
	private: System::Windows::Forms::ListBox^  listBoxVr;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::TextBox^  textBoxMacdSell;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::TextBox^  textBoxMacdBuy;
	private: System::Windows::Forms::ListBox^  listBoxMacd;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  textBoxDmaTop;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::TextBox^  textBoxDmaBottom;
	private: System::Windows::Forms::ListBox^  listBoxDma;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::TextBox^  textBoxCciTop;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::TextBox^  textBoxCciBottom;
	private: System::Windows::Forms::ListBox^  listBoxCci;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::TextBox^  textBoxCrTop;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::TextBox^  textBoxCrBottom;
	private: System::Windows::Forms::ListBox^  listBoxCr;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::ListBox^  listBoxVol;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::ListBox^  listBoxMa;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::Label^  label45;
	private: System::Windows::Forms::Label^  label46;
	private: System::Windows::Forms::TextBox^  textBoxMacdMiddle;
	private: System::Windows::Forms::Label^  label47;
	private: System::Windows::Forms::TextBox^  textBoxMacdLow;
	private: System::Windows::Forms::Label^  label48;
	private: System::Windows::Forms::TextBox^  textBoxMacdUpper;
	private: System::Windows::Forms::Label^  label49;
	private: System::Windows::Forms::TextBox^  textBoxMacdCrossLine;
	private: System::Windows::Forms::Label^  label50;
	private: System::Windows::Forms::TextBox^  textBoxMacdZeroLine;
	private: System::Windows::Forms::Label^  label52;
	private: System::Windows::Forms::TextBox^  textBoxDmaMiddle;
	private: System::Windows::Forms::Label^  label53;
	private: System::Windows::Forms::TextBox^  textBoxVrMiddle;
	private: System::Windows::Forms::Label^  label54;
	private: System::Windows::Forms::TextBox^  textBoxCciMiddle;
	private: System::Windows::Forms::Label^  label55;
	private: System::Windows::Forms::TextBox^  textBoxCrMiddle;
	private: System::Windows::Forms::Label^  label56;
	private: System::Windows::Forms::TextBox^  textBoxDmaDiff;
	private: System::Windows::Forms::Label^  label57;
	private: System::Windows::Forms::TextBox^  textBoxDmaDirLine;
	private: System::Windows::Forms::Label^  label51;
	private: System::Windows::Forms::TextBox^  textBoxVrDiff;
	private: System::Windows::Forms::Label^  label58;
	private: System::Windows::Forms::TextBox^  textBoxCciDirLine;
	private: System::Windows::Forms::Label^  label59;
	private: System::Windows::Forms::TextBox^  textBoxCrDiff;
	private: System::Windows::Forms::Button^  buttonAddBoll;
	private: System::Windows::Forms::Button^  buttonAddKdj;
	private: System::Windows::Forms::Button^  buttonAddRsi;
	private: System::Windows::Forms::Button^  buttonAddRoc;
	private: System::Windows::Forms::Button^  buttonAddWr;
	private: System::Windows::Forms::Button^  buttonAddMacd;
	private: System::Windows::Forms::Button^  buttonAddDma;
	private: System::Windows::Forms::Button^  buttonAddVr;
	private: System::Windows::Forms::Button^  buttonAddCci;
	private: System::Windows::Forms::Button^  buttonAddCr;
	private: System::Windows::Forms::Button^  buttonAddMA;
	private: System::Windows::Forms::Button^  buttonAddVol;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::TextBox^  textBoxWrMiddle;

	protected: 
	protected: 
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
			this->textBoxObject = (gcnew System::Windows::Forms::TextBox());
			this->labelObject = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBoxWrTop = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBoxWrBottom = (gcnew System::Windows::Forms::TextBox());
			this->listBoxWr = (gcnew System::Windows::Forms::ListBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBoxRocTop = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBoxRocBottom = (gcnew System::Windows::Forms::TextBox());
			this->listBoxRoc = (gcnew System::Windows::Forms::ListBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxRsiTop = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBoxRsiBottom = (gcnew System::Windows::Forms::TextBox());
			this->listBoxRsi = (gcnew System::Windows::Forms::ListBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxKdjSellCross = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxKdjBuyCross = (gcnew System::Windows::Forms::TextBox());
			this->listBoxKdj = (gcnew System::Windows::Forms::ListBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxBollSell = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxBollBuy = (gcnew System::Windows::Forms::TextBox());
			this->listBoxBoll = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelBoll = (gcnew System::Windows::Forms::Label());
			this->listBoxWrNeg = (gcnew System::Windows::Forms::ListBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->textBoxVrTop = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->textBoxVrBottom = (gcnew System::Windows::Forms::TextBox());
			this->listBoxVr = (gcnew System::Windows::Forms::ListBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->textBoxMacdSell = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->textBoxMacdBuy = (gcnew System::Windows::Forms::TextBox());
			this->listBoxMacd = (gcnew System::Windows::Forms::ListBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBoxDmaTop = (gcnew System::Windows::Forms::TextBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBoxDmaBottom = (gcnew System::Windows::Forms::TextBox());
			this->listBoxDma = (gcnew System::Windows::Forms::ListBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->textBoxCciTop = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->textBoxCciBottom = (gcnew System::Windows::Forms::TextBox());
			this->listBoxCci = (gcnew System::Windows::Forms::ListBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->textBoxCrTop = (gcnew System::Windows::Forms::TextBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->textBoxCrBottom = (gcnew System::Windows::Forms::TextBox());
			this->listBoxCr = (gcnew System::Windows::Forms::ListBox());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->listBoxVol = (gcnew System::Windows::Forms::ListBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->listBoxMa = (gcnew System::Windows::Forms::ListBox());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->textBoxMacdMiddle = (gcnew System::Windows::Forms::TextBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->textBoxMacdLow = (gcnew System::Windows::Forms::TextBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->textBoxMacdUpper = (gcnew System::Windows::Forms::TextBox());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->textBoxMacdCrossLine = (gcnew System::Windows::Forms::TextBox());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->textBoxMacdZeroLine = (gcnew System::Windows::Forms::TextBox());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->textBoxDmaMiddle = (gcnew System::Windows::Forms::TextBox());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->textBoxVrMiddle = (gcnew System::Windows::Forms::TextBox());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->textBoxCciMiddle = (gcnew System::Windows::Forms::TextBox());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->textBoxCrMiddle = (gcnew System::Windows::Forms::TextBox());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->textBoxDmaDiff = (gcnew System::Windows::Forms::TextBox());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->textBoxDmaDirLine = (gcnew System::Windows::Forms::TextBox());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->textBoxVrDiff = (gcnew System::Windows::Forms::TextBox());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->textBoxCciDirLine = (gcnew System::Windows::Forms::TextBox());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->textBoxCrDiff = (gcnew System::Windows::Forms::TextBox());
			this->buttonAddBoll = (gcnew System::Windows::Forms::Button());
			this->buttonAddKdj = (gcnew System::Windows::Forms::Button());
			this->buttonAddRsi = (gcnew System::Windows::Forms::Button());
			this->buttonAddRoc = (gcnew System::Windows::Forms::Button());
			this->buttonAddWr = (gcnew System::Windows::Forms::Button());
			this->buttonAddMacd = (gcnew System::Windows::Forms::Button());
			this->buttonAddDma = (gcnew System::Windows::Forms::Button());
			this->buttonAddVr = (gcnew System::Windows::Forms::Button());
			this->buttonAddCci = (gcnew System::Windows::Forms::Button());
			this->buttonAddCr = (gcnew System::Windows::Forms::Button());
			this->buttonAddMA = (gcnew System::Windows::Forms::Button());
			this->buttonAddVol = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxWrMiddle = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBoxObject
			// 
			this->textBoxObject->Location = System::Drawing::Point(99, 8);
			this->textBoxObject->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxObject->Name = L"textBoxObject";
			this->textBoxObject->Size = System::Drawing::Size(162, 26);
			this->textBoxObject->TabIndex = 7;
			this->textBoxObject->TextChanged += gcnew System::EventHandler(this, &OperateSettingForm::textBoxObject_TextChanged);
			// 
			// labelObject
			// 
			this->labelObject->AutoSize = true;
			this->labelObject->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelObject->Location = System::Drawing::Point(18, 15);
			this->labelObject->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelObject->Name = L"labelObject";
			this->labelObject->Size = System::Drawing::Size(56, 19);
			this->labelObject->TabIndex = 6;
			this->labelObject->Text = L"Object:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(528, 267);
			this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(39, 19);
			this->label17->TabIndex = 104;
			this->label17->Text = L"Top:";
			// 
			// textBoxWrTop
			// 
			this->textBoxWrTop->Location = System::Drawing::Point(592, 260);
			this->textBoxWrTop->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxWrTop->Name = L"textBoxWrTop";
			this->textBoxWrTop->Size = System::Drawing::Size(118, 26);
			this->textBoxWrTop->TabIndex = 103;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(301, 270);
			this->label18->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(64, 19);
			this->label18->TabIndex = 102;
			this->label18->Text = L"Bottom:";
			// 
			// textBoxWrBottom
			// 
			this->textBoxWrBottom->Location = System::Drawing::Point(381, 260);
			this->textBoxWrBottom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxWrBottom->Name = L"textBoxWrBottom";
			this->textBoxWrBottom->Size = System::Drawing::Size(119, 26);
			this->textBoxWrBottom->TabIndex = 101;
			// 
			// listBoxWr
			// 
			this->listBoxWr->FormattingEnabled = true;
			this->listBoxWr->ItemHeight = 19;
			this->listBoxWr->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"ALL", L"Year", L"Month", L"Week", L"Day", L"4Hour", 
				L"1Hour", L"45Min", L"30Min", L"15Min", L"10Min", L"5Min"});
			this->listBoxWr->Location = System::Drawing::Point(164, 263);
			this->listBoxWr->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxWr->Name = L"listBoxWr";
			this->listBoxWr->Size = System::Drawing::Size(106, 23);
			this->listBoxWr->TabIndex = 100;
			this->listBoxWr->SelectedIndexChanged += gcnew System::EventHandler(this, &OperateSettingForm::listBoxWr_SelectedIndexChanged);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(84, 267);
			this->label19->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(59, 19);
			this->label19->TabIndex = 99;
			this->label19->Text = L"Period:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(23, 270);
			this->label20->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(38, 19);
			this->label20->TabIndex = 98;
			this->label20->Text = L"WR:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(527, 218);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(39, 19);
			this->label13->TabIndex = 97;
			this->label13->Text = L"Top:";
			// 
			// textBoxRocTop
			// 
			this->textBoxRocTop->Location = System::Drawing::Point(591, 211);
			this->textBoxRocTop->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxRocTop->Name = L"textBoxRocTop";
			this->textBoxRocTop->Size = System::Drawing::Size(119, 26);
			this->textBoxRocTop->TabIndex = 96;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(300, 218);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(64, 19);
			this->label14->TabIndex = 95;
			this->label14->Text = L"Bottom:";
			// 
			// textBoxRocBottom
			// 
			this->textBoxRocBottom->Location = System::Drawing::Point(381, 215);
			this->textBoxRocBottom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxRocBottom->Name = L"textBoxRocBottom";
			this->textBoxRocBottom->Size = System::Drawing::Size(120, 26);
			this->textBoxRocBottom->TabIndex = 94;
			// 
			// listBoxRoc
			// 
			this->listBoxRoc->FormattingEnabled = true;
			this->listBoxRoc->ItemHeight = 19;
			this->listBoxRoc->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"ALL", L"Year", L"Month", L"Week", L"Day", L"4Hour", 
				L"1Hour", L"45Min", L"30Min", L"15Min", L"10Min", L"5Min"});
			this->listBoxRoc->Location = System::Drawing::Point(163, 214);
			this->listBoxRoc->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxRoc->Name = L"listBoxRoc";
			this->listBoxRoc->Size = System::Drawing::Size(107, 23);
			this->listBoxRoc->TabIndex = 93;
			this->listBoxRoc->SelectedIndexChanged += gcnew System::EventHandler(this, &OperateSettingForm::listBoxRoc_SelectedIndexChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(83, 218);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(59, 19);
			this->label15->TabIndex = 92;
			this->label15->Text = L"Period:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(22, 221);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(42, 19);
			this->label16->TabIndex = 91;
			this->label16->Text = L"ROC:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(527, 170);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(39, 19);
			this->label9->TabIndex = 90;
			this->label9->Text = L"Top:";
			// 
			// textBoxRsiTop
			// 
			this->textBoxRsiTop->Location = System::Drawing::Point(591, 163);
			this->textBoxRsiTop->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxRsiTop->Name = L"textBoxRsiTop";
			this->textBoxRsiTop->Size = System::Drawing::Size(119, 26);
			this->textBoxRsiTop->TabIndex = 89;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(301, 170);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(64, 19);
			this->label10->TabIndex = 88;
			this->label10->Text = L"Bottom:";
			// 
			// textBoxRsiBottom
			// 
			this->textBoxRsiBottom->Location = System::Drawing::Point(380, 163);
			this->textBoxRsiBottom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxRsiBottom->Name = L"textBoxRsiBottom";
			this->textBoxRsiBottom->Size = System::Drawing::Size(120, 26);
			this->textBoxRsiBottom->TabIndex = 87;
			// 
			// listBoxRsi
			// 
			this->listBoxRsi->FormattingEnabled = true;
			this->listBoxRsi->ItemHeight = 19;
			this->listBoxRsi->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"ALL", L"Year", L"Month", L"Week", L"Day", L"4Hour", 
				L"1Hour", L"45Min", L"30Min", L"15Min", L"10Min", L"5Min"});
			this->listBoxRsi->Location = System::Drawing::Point(163, 166);
			this->listBoxRsi->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxRsi->Name = L"listBoxRsi";
			this->listBoxRsi->Size = System::Drawing::Size(107, 23);
			this->listBoxRsi->TabIndex = 86;
			this->listBoxRsi->SelectedIndexChanged += gcnew System::EventHandler(this, &OperateSettingForm::listBoxRsi_SelectedIndexChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(83, 170);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(59, 19);
			this->label11->TabIndex = 85;
			this->label11->Text = L"Period:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(22, 173);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(36, 19);
			this->label12->TabIndex = 84;
			this->label12->Text = L"RSI:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(500, 115);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 19);
			this->label5->TabIndex = 83;
			this->label5->Text = L"SellCross:";
			// 
			// textBoxKdjSellCross
			// 
			this->textBoxKdjSellCross->Location = System::Drawing::Point(591, 108);
			this->textBoxKdjSellCross->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxKdjSellCross->Name = L"textBoxKdjSellCross";
			this->textBoxKdjSellCross->Size = System::Drawing::Size(119, 26);
			this->textBoxKdjSellCross->TabIndex = 82;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(282, 115);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(79, 19);
			this->label6->TabIndex = 81;
			this->label6->Text = L"BuyCross:";
			// 
			// textBoxKdjBuyCross
			// 
			this->textBoxKdjBuyCross->Location = System::Drawing::Point(380, 108);
			this->textBoxKdjBuyCross->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxKdjBuyCross->Name = L"textBoxKdjBuyCross";
			this->textBoxKdjBuyCross->Size = System::Drawing::Size(120, 26);
			this->textBoxKdjBuyCross->TabIndex = 80;
			// 
			// listBoxKdj
			// 
			this->listBoxKdj->FormattingEnabled = true;
			this->listBoxKdj->ItemHeight = 19;
			this->listBoxKdj->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"ALL", L"Year", L"Month", L"Week", L"Day", L"4Hour", 
				L"1Hour", L"45Min", L"30Min", L"15Min", L"10Min", L"5Min"});
			this->listBoxKdj->Location = System::Drawing::Point(163, 115);
			this->listBoxKdj->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxKdj->Name = L"listBoxKdj";
			this->listBoxKdj->Size = System::Drawing::Size(107, 23);
			this->listBoxKdj->TabIndex = 79;
			this->listBoxKdj->SelectedIndexChanged += gcnew System::EventHandler(this, &OperateSettingForm::listBoxKdj_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(83, 115);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(59, 19);
			this->label7->TabIndex = 78;
			this->label7->Text = L"Period:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(22, 118);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(39, 19);
			this->label8->TabIndex = 77;
			this->label8->Text = L"KDJ:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(527, 65);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 19);
			this->label4->TabIndex = 76;
			this->label4->Text = L"Sell:";
			// 
			// textBoxBollSell
			// 
			this->textBoxBollSell->Location = System::Drawing::Point(591, 61);
			this->textBoxBollSell->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxBollSell->Name = L"textBoxBollSell";
			this->textBoxBollSell->Size = System::Drawing::Size(119, 26);
			this->textBoxBollSell->TabIndex = 75;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(309, 65);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 19);
			this->label1->TabIndex = 74;
			this->label1->Text = L"Buy:";
			// 
			// textBoxBollBuy
			// 
			this->textBoxBollBuy->Location = System::Drawing::Point(381, 57);
			this->textBoxBollBuy->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxBollBuy->Name = L"textBoxBollBuy";
			this->textBoxBollBuy->Size = System::Drawing::Size(120, 26);
			this->textBoxBollBuy->TabIndex = 73;
			// 
			// listBoxBoll
			// 
			this->listBoxBoll->FormattingEnabled = true;
			this->listBoxBoll->ItemHeight = 19;
			this->listBoxBoll->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"ALL", L"Year", L"Month", L"Week", L"Day", L"4Hour", 
				L"1Hour", L"45Min", L"30Min", L"15Min", L"10Min", L"5Min"});
			this->listBoxBoll->Location = System::Drawing::Point(163, 61);
			this->listBoxBoll->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxBoll->Name = L"listBoxBoll";
			this->listBoxBoll->Size = System::Drawing::Size(107, 23);
			this->listBoxBoll->TabIndex = 72;
			this->listBoxBoll->SelectedIndexChanged += gcnew System::EventHandler(this, &OperateSettingForm::listBoxBoll_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(83, 65);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 19);
			this->label2->TabIndex = 71;
			this->label2->Text = L"Period:";
			// 
			// labelBoll
			// 
			this->labelBoll->AutoSize = true;
			this->labelBoll->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelBoll->Location = System::Drawing::Point(22, 68);
			this->labelBoll->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelBoll->Name = L"labelBoll";
			this->labelBoll->Size = System::Drawing::Size(51, 19);
			this->labelBoll->TabIndex = 70;
			this->labelBoll->Text = L"BOLL:";
			// 
			// listBoxWrNeg
			// 
			this->listBoxWrNeg->FormattingEnabled = true;
			this->listBoxWrNeg->ItemHeight = 19;
			this->listBoxWrNeg->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Yes", L"No"});
			this->listBoxWrNeg->Location = System::Drawing::Point(593, 308);
			this->listBoxWrNeg->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxWrNeg->Name = L"listBoxWrNeg";
			this->listBoxWrNeg->Size = System::Drawing::Size(116, 23);
			this->listBoxWrNeg->TabIndex = 106;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(482, 312);
			this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(98, 19);
			this->label21->TabIndex = 105;
			this->label21->Text = L"WRNegative:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(537, 571);
			this->label23->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(39, 19);
			this->label23->TabIndex = 113;
			this->label23->Text = L"Top:";
			// 
			// textBoxVrTop
			// 
			this->textBoxVrTop->Location = System::Drawing::Point(593, 564);
			this->textBoxVrTop->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxVrTop->Name = L"textBoxVrTop";
			this->textBoxVrTop->Size = System::Drawing::Size(118, 26);
			this->textBoxVrTop->TabIndex = 112;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(311, 571);
			this->label24->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(64, 19);
			this->label24->TabIndex = 111;
			this->label24->Text = L"Bottom:";
			// 
			// textBoxVrBottom
			// 
			this->textBoxVrBottom->Location = System::Drawing::Point(382, 564);
			this->textBoxVrBottom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxVrBottom->Name = L"textBoxVrBottom";
			this->textBoxVrBottom->Size = System::Drawing::Size(119, 26);
			this->textBoxVrBottom->TabIndex = 110;
			// 
			// listBoxVr
			// 
			this->listBoxVr->FormattingEnabled = true;
			this->listBoxVr->ItemHeight = 19;
			this->listBoxVr->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"ALL", L"Year", L"Month", L"Week", L"Day", L"4Hour", 
				L"1Hour", L"45Min", L"30Min", L"15Min", L"10Min", L"5Min"});
			this->listBoxVr->Location = System::Drawing::Point(164, 567);
			this->listBoxVr->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxVr->Name = L"listBoxVr";
			this->listBoxVr->Size = System::Drawing::Size(106, 23);
			this->listBoxVr->TabIndex = 109;
			this->listBoxVr->SelectedIndexChanged += gcnew System::EventHandler(this, &OperateSettingForm::listBoxVr_SelectedIndexChanged);
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(93, 571);
			this->label25->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(59, 19);
			this->label25->TabIndex = 108;
			this->label25->Text = L"Period:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(35, 571);
			this->label26->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(33, 19);
			this->label26->TabIndex = 107;
			this->label26->Text = L"VR:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label28->Location = System::Drawing::Point(540, 357);
			this->label28->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(37, 19);
			this->label28->TabIndex = 122;
			this->label28->Text = L"Sell:";
			// 
			// textBoxMacdSell
			// 
			this->textBoxMacdSell->Location = System::Drawing::Point(592, 350);
			this->textBoxMacdSell->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxMacdSell->Name = L"textBoxMacdSell";
			this->textBoxMacdSell->Size = System::Drawing::Size(118, 26);
			this->textBoxMacdSell->TabIndex = 121;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(312, 357);
			this->label29->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(40, 19);
			this->label29->TabIndex = 120;
			this->label29->Text = L"Buy:";
			// 
			// textBoxMacdBuy
			// 
			this->textBoxMacdBuy->Location = System::Drawing::Point(382, 350);
			this->textBoxMacdBuy->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxMacdBuy->Name = L"textBoxMacdBuy";
			this->textBoxMacdBuy->Size = System::Drawing::Size(119, 26);
			this->textBoxMacdBuy->TabIndex = 119;
			// 
			// listBoxMacd
			// 
			this->listBoxMacd->FormattingEnabled = true;
			this->listBoxMacd->ItemHeight = 19;
			this->listBoxMacd->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"ALL", L"Year", L"Month", L"Week", L"Day", L"4Hour", 
				L"1Hour", L"45Min", L"30Min", L"15Min", L"10Min", L"5Min"});
			this->listBoxMacd->Location = System::Drawing::Point(164, 353);
			this->listBoxMacd->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxMacd->Name = L"listBoxMacd";
			this->listBoxMacd->Size = System::Drawing::Size(106, 23);
			this->listBoxMacd->TabIndex = 118;
			this->listBoxMacd->SelectedIndexChanged += gcnew System::EventHandler(this, &OperateSettingForm::listBoxMacd_SelectedIndexChanged);
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(96, 357);
			this->label30->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(59, 19);
			this->label30->TabIndex = 117;
			this->label30->Text = L"Period:";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(20, 357);
			this->label31->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(56, 19);
			this->label31->TabIndex = 116;
			this->label31->Text = L"MACD:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(539, 467);
			this->label22->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(39, 19);
			this->label22->TabIndex = 129;
			this->label22->Text = L"Top:";
			// 
			// textBoxDmaTop
			// 
			this->textBoxDmaTop->Location = System::Drawing::Point(591, 460);
			this->textBoxDmaTop->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxDmaTop->Name = L"textBoxDmaTop";
			this->textBoxDmaTop->Size = System::Drawing::Size(118, 26);
			this->textBoxDmaTop->TabIndex = 128;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(312, 467);
			this->label27->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(64, 19);
			this->label27->TabIndex = 127;
			this->label27->Text = L"Bottom:";
			// 
			// textBoxDmaBottom
			// 
			this->textBoxDmaBottom->Location = System::Drawing::Point(384, 460);
			this->textBoxDmaBottom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxDmaBottom->Name = L"textBoxDmaBottom";
			this->textBoxDmaBottom->Size = System::Drawing::Size(119, 26);
			this->textBoxDmaBottom->TabIndex = 126;
			// 
			// listBoxDma
			// 
			this->listBoxDma->FormattingEnabled = true;
			this->listBoxDma->ItemHeight = 19;
			this->listBoxDma->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"ALL", L"Year", L"Month", L"Week", L"Day", L"4Hour", 
				L"1Hour", L"45Min", L"30Min", L"15Min", L"10Min", L"5Min"});
			this->listBoxDma->Location = System::Drawing::Point(164, 463);
			this->listBoxDma->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxDma->Name = L"listBoxDma";
			this->listBoxDma->Size = System::Drawing::Size(106, 23);
			this->listBoxDma->TabIndex = 125;
			this->listBoxDma->SelectedIndexChanged += gcnew System::EventHandler(this, &OperateSettingForm::listBoxDma_SelectedIndexChanged);
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label32->Location = System::Drawing::Point(95, 467);
			this->label32->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(59, 19);
			this->label32->TabIndex = 124;
			this->label32->Text = L"Period:";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label33->Location = System::Drawing::Point(28, 467);
			this->label33->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(47, 19);
			this->label33->TabIndex = 123;
			this->label33->Text = L"DMA:";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label34->Location = System::Drawing::Point(541, 659);
			this->label34->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(39, 19);
			this->label34->TabIndex = 136;
			this->label34->Text = L"Top:";
			// 
			// textBoxCciTop
			// 
			this->textBoxCciTop->Location = System::Drawing::Point(591, 652);
			this->textBoxCciTop->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxCciTop->Name = L"textBoxCciTop";
			this->textBoxCciTop->Size = System::Drawing::Size(118, 26);
			this->textBoxCciTop->TabIndex = 135;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label35->Location = System::Drawing::Point(309, 659);
			this->label35->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(64, 19);
			this->label35->TabIndex = 134;
			this->label35->Text = L"Bottom:";
			// 
			// textBoxCciBottom
			// 
			this->textBoxCciBottom->Location = System::Drawing::Point(386, 652);
			this->textBoxCciBottom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxCciBottom->Name = L"textBoxCciBottom";
			this->textBoxCciBottom->Size = System::Drawing::Size(119, 26);
			this->textBoxCciBottom->TabIndex = 133;
			// 
			// listBoxCci
			// 
			this->listBoxCci->FormattingEnabled = true;
			this->listBoxCci->ItemHeight = 19;
			this->listBoxCci->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"ALL", L"Year", L"Month", L"Week", L"Day", L"4Hour", 
				L"1Hour", L"45Min", L"30Min", L"15Min", L"10Min", L"5Min"});
			this->listBoxCci->Location = System::Drawing::Point(163, 655);
			this->listBoxCci->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxCci->Name = L"listBoxCci";
			this->listBoxCci->Size = System::Drawing::Size(111, 23);
			this->listBoxCci->TabIndex = 132;
			this->listBoxCci->SelectedIndexChanged += gcnew System::EventHandler(this, &OperateSettingForm::listBoxCci_SelectedIndexChanged);
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label36->Location = System::Drawing::Point(97, 659);
			this->label36->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(59, 19);
			this->label36->TabIndex = 131;
			this->label36->Text = L"Period:";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label37->Location = System::Drawing::Point(35, 659);
			this->label37->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(36, 19);
			this->label37->TabIndex = 130;
			this->label37->Text = L"CCI:";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label38->Location = System::Drawing::Point(540, 743);
			this->label38->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(39, 19);
			this->label38->TabIndex = 143;
			this->label38->Text = L"Top:";
			// 
			// textBoxCrTop
			// 
			this->textBoxCrTop->Location = System::Drawing::Point(593, 739);
			this->textBoxCrTop->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxCrTop->Name = L"textBoxCrTop";
			this->textBoxCrTop->Size = System::Drawing::Size(118, 26);
			this->textBoxCrTop->TabIndex = 142;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label39->Location = System::Drawing::Point(313, 743);
			this->label39->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(64, 19);
			this->label39->TabIndex = 141;
			this->label39->Text = L"Bottom:";
			// 
			// textBoxCrBottom
			// 
			this->textBoxCrBottom->Location = System::Drawing::Point(385, 736);
			this->textBoxCrBottom->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxCrBottom->Name = L"textBoxCrBottom";
			this->textBoxCrBottom->Size = System::Drawing::Size(119, 26);
			this->textBoxCrBottom->TabIndex = 140;
			// 
			// listBoxCr
			// 
			this->listBoxCr->FormattingEnabled = true;
			this->listBoxCr->ItemHeight = 19;
			this->listBoxCr->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"ALL", L"Year", L"Month", L"Week", L"Day", L"4Hour", 
				L"1Hour", L"45Min", L"30Min", L"15Min", L"10Min", L"5Min"});
			this->listBoxCr->Location = System::Drawing::Point(164, 739);
			this->listBoxCr->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxCr->Name = L"listBoxCr";
			this->listBoxCr->Size = System::Drawing::Size(109, 23);
			this->listBoxCr->TabIndex = 139;
			this->listBoxCr->SelectedIndexChanged += gcnew System::EventHandler(this, &OperateSettingForm::listBoxCr_SelectedIndexChanged);
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label40->Location = System::Drawing::Point(96, 743);
			this->label40->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(59, 19);
			this->label40->TabIndex = 138;
			this->label40->Text = L"Period:";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label41->Location = System::Drawing::Point(34, 743);
			this->label41->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(32, 19);
			this->label41->TabIndex = 137;
			this->label41->Text = L"CR:";
			// 
			// listBoxVol
			// 
			this->listBoxVol->FormattingEnabled = true;
			this->listBoxVol->ItemHeight = 19;
			this->listBoxVol->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"ALL", L"Year", L"Month", L"Week", L"Day", L"4Hour", 
				L"1Hour", L"45Min", L"30Min", L"15Min", L"10Min", L"5Min"});
			this->listBoxVol->Location = System::Drawing::Point(681, 834);
			this->listBoxVol->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxVol->Name = L"listBoxVol";
			this->listBoxVol->Size = System::Drawing::Size(97, 23);
			this->listBoxVol->TabIndex = 149;
			this->listBoxVol->SelectedIndexChanged += gcnew System::EventHandler(this, &OperateSettingForm::listBoxVol_SelectedIndexChanged);
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label42->Location = System::Drawing::Point(588, 838);
			this->label42->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(59, 19);
			this->label42->TabIndex = 148;
			this->label42->Text = L"Period:";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label43->Location = System::Drawing::Point(530, 841);
			this->label43->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(37, 19);
			this->label43->TabIndex = 147;
			this->label43->Text = L"VOl:";
			// 
			// listBoxMa
			// 
			this->listBoxMa->FormattingEnabled = true;
			this->listBoxMa->ItemHeight = 19;
			this->listBoxMa->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"ALL", L"Year", L"Month", L"Week", L"Day", L"4Hour", 
				L"1Hour", L"45Min", L"30Min", L"15Min", L"10Min", L"5Min"});
			this->listBoxMa->Location = System::Drawing::Point(163, 834);
			this->listBoxMa->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBoxMa->Name = L"listBoxMa";
			this->listBoxMa->Size = System::Drawing::Size(110, 23);
			this->listBoxMa->TabIndex = 146;
			this->listBoxMa->SelectedIndexChanged += gcnew System::EventHandler(this, &OperateSettingForm::listBoxMa_SelectedIndexChanged);
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label44->Location = System::Drawing::Point(96, 838);
			this->label44->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(59, 19);
			this->label44->TabIndex = 145;
			this->label44->Text = L"Period:";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label45->Location = System::Drawing::Point(34, 838);
			this->label45->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(36, 19);
			this->label45->TabIndex = 144;
			this->label45->Text = L"MA:";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label46->Location = System::Drawing::Point(314, 402);
			this->label46->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(60, 19);
			this->label46->TabIndex = 153;
			this->label46->Text = L"Middle:";
			// 
			// textBoxMacdMiddle
			// 
			this->textBoxMacdMiddle->Location = System::Drawing::Point(382, 396);
			this->textBoxMacdMiddle->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxMacdMiddle->Name = L"textBoxMacdMiddle";
			this->textBoxMacdMiddle->Size = System::Drawing::Size(118, 26);
			this->textBoxMacdMiddle->TabIndex = 152;
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label47->Location = System::Drawing::Point(100, 402);
			this->label47->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(43, 19);
			this->label47->TabIndex = 151;
			this->label47->Text = L"Low:";
			// 
			// textBoxMacdLow
			// 
			this->textBoxMacdLow->Location = System::Drawing::Point(163, 399);
			this->textBoxMacdLow->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxMacdLow->Name = L"textBoxMacdLow";
			this->textBoxMacdLow->Size = System::Drawing::Size(107, 26);
			this->textBoxMacdLow->TabIndex = 150;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label48->Location = System::Drawing::Point(528, 399);
			this->label48->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(56, 19);
			this->label48->TabIndex = 155;
			this->label48->Text = L"Upper:";
			// 
			// textBoxMacdUpper
			// 
			this->textBoxMacdUpper->Location = System::Drawing::Point(592, 393);
			this->textBoxMacdUpper->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxMacdUpper->Name = L"textBoxMacdUpper";
			this->textBoxMacdUpper->Size = System::Drawing::Size(118, 26);
			this->textBoxMacdUpper->TabIndex = 154;
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label49->Location = System::Drawing::Point(727, 357);
			this->label49->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(81, 19);
			this->label49->TabIndex = 157;
			this->label49->Text = L"cross_line:";
			// 
			// textBoxMacdCrossLine
			// 
			this->textBoxMacdCrossLine->Location = System::Drawing::Point(810, 350);
			this->textBoxMacdCrossLine->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxMacdCrossLine->Name = L"textBoxMacdCrossLine";
			this->textBoxMacdCrossLine->Size = System::Drawing::Size(118, 26);
			this->textBoxMacdCrossLine->TabIndex = 156;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label50->Location = System::Drawing::Point(735, 396);
			this->label50->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(75, 19);
			this->label50->TabIndex = 159;
			this->label50->Text = L"zero_line:";
			// 
			// textBoxMacdZeroLine
			// 
			this->textBoxMacdZeroLine->Location = System::Drawing::Point(812, 390);
			this->textBoxMacdZeroLine->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxMacdZeroLine->Name = L"textBoxMacdZeroLine";
			this->textBoxMacdZeroLine->Size = System::Drawing::Size(118, 26);
			this->textBoxMacdZeroLine->TabIndex = 158;
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label52->Location = System::Drawing::Point(742, 467);
			this->label52->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(60, 19);
			this->label52->TabIndex = 162;
			this->label52->Text = L"Middle:";
			// 
			// textBoxDmaMiddle
			// 
			this->textBoxDmaMiddle->Location = System::Drawing::Point(810, 460);
			this->textBoxDmaMiddle->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxDmaMiddle->Name = L"textBoxDmaMiddle";
			this->textBoxDmaMiddle->Size = System::Drawing::Size(118, 26);
			this->textBoxDmaMiddle->TabIndex = 161;
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label53->Location = System::Drawing::Point(747, 571);
			this->label53->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(60, 19);
			this->label53->TabIndex = 164;
			this->label53->Text = L"Middle:";
			// 
			// textBoxVrMiddle
			// 
			this->textBoxVrMiddle->Location = System::Drawing::Point(809, 564);
			this->textBoxVrMiddle->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxVrMiddle->Name = L"textBoxVrMiddle";
			this->textBoxVrMiddle->Size = System::Drawing::Size(118, 26);
			this->textBoxVrMiddle->TabIndex = 163;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label54->Location = System::Drawing::Point(750, 662);
			this->label54->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(60, 19);
			this->label54->TabIndex = 166;
			this->label54->Text = L"Middle:";
			// 
			// textBoxCciMiddle
			// 
			this->textBoxCciMiddle->Location = System::Drawing::Point(812, 655);
			this->textBoxCciMiddle->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxCciMiddle->Name = L"textBoxCciMiddle";
			this->textBoxCciMiddle->Size = System::Drawing::Size(118, 26);
			this->textBoxCciMiddle->TabIndex = 165;
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label55->Location = System::Drawing::Point(750, 743);
			this->label55->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(60, 19);
			this->label55->TabIndex = 168;
			this->label55->Text = L"Middle:";
			// 
			// textBoxCrMiddle
			// 
			this->textBoxCrMiddle->Location = System::Drawing::Point(812, 736);
			this->textBoxCrMiddle->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxCrMiddle->Name = L"textBoxCrMiddle";
			this->textBoxCrMiddle->Size = System::Drawing::Size(118, 26);
			this->textBoxCrMiddle->TabIndex = 167;
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label56->Location = System::Drawing::Point(299, 518);
			this->label56->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(76, 19);
			this->label56->TabIndex = 170;
			this->label56->Text = L"Dma_Diff:";
			// 
			// textBoxDmaDiff
			// 
			this->textBoxDmaDiff->Location = System::Drawing::Point(384, 511);
			this->textBoxDmaDiff->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxDmaDiff->Name = L"textBoxDmaDiff";
			this->textBoxDmaDiff->Size = System::Drawing::Size(119, 26);
			this->textBoxDmaDiff->TabIndex = 169;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label57->Location = System::Drawing::Point(519, 518);
			this->label57->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(71, 19);
			this->label57->TabIndex = 172;
			this->label57->Text = L"Dir_Line:";
			// 
			// textBoxDmaDirLine
			// 
			this->textBoxDmaDirLine->Location = System::Drawing::Point(592, 514);
			this->textBoxDmaDirLine->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxDmaDirLine->Name = L"textBoxDmaDirLine";
			this->textBoxDmaDirLine->Size = System::Drawing::Size(119, 26);
			this->textBoxDmaDirLine->TabIndex = 171;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label51->Location = System::Drawing::Point(524, 611);
			this->label51->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(60, 19);
			this->label51->TabIndex = 174;
			this->label51->Text = L"Vr_Diff:";
			// 
			// textBoxVrDiff
			// 
			this->textBoxVrDiff->Location = System::Drawing::Point(591, 604);
			this->textBoxVrDiff->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxVrDiff->Name = L"textBoxVrDiff";
			this->textBoxVrDiff->Size = System::Drawing::Size(119, 26);
			this->textBoxVrDiff->TabIndex = 173;
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label58->Location = System::Drawing::Point(498, 702);
			this->label58->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(83, 19);
			this->label58->TabIndex = 176;
			this->label58->Text = L"cciDirLine:";
			// 
			// textBoxCciDirLine
			// 
			this->textBoxCciDirLine->Location = System::Drawing::Point(592, 695);
			this->textBoxCciDirLine->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxCciDirLine->Name = L"textBoxCciDirLine";
			this->textBoxCciDirLine->Size = System::Drawing::Size(119, 26);
			this->textBoxCciDirLine->TabIndex = 175;
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label59->Location = System::Drawing::Point(528, 793);
			this->label59->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(60, 19);
			this->label59->TabIndex = 178;
			this->label59->Text = L"Cr_Diff:";
			// 
			// textBoxCrDiff
			// 
			this->textBoxCrDiff->Location = System::Drawing::Point(593, 787);
			this->textBoxCrDiff->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxCrDiff->Name = L"textBoxCrDiff";
			this->textBoxCrDiff->Size = System::Drawing::Size(119, 26);
			this->textBoxCrDiff->TabIndex = 177;
			// 
			// buttonAddBoll
			// 
			this->buttonAddBoll->Location = System::Drawing::Point(806, 57);
			this->buttonAddBoll->Name = L"buttonAddBoll";
			this->buttonAddBoll->Size = System::Drawing::Size(121, 26);
			this->buttonAddBoll->TabIndex = 179;
			this->buttonAddBoll->Text = L"AddBOLL";
			this->buttonAddBoll->UseVisualStyleBackColor = true;
			this->buttonAddBoll->Click += gcnew System::EventHandler(this, &OperateSettingForm::buttonAddBoll_Click);
			// 
			// buttonAddKdj
			// 
			this->buttonAddKdj->Location = System::Drawing::Point(806, 111);
			this->buttonAddKdj->Name = L"buttonAddKdj";
			this->buttonAddKdj->Size = System::Drawing::Size(121, 26);
			this->buttonAddKdj->TabIndex = 180;
			this->buttonAddKdj->Text = L"Add KDJ";
			this->buttonAddKdj->UseVisualStyleBackColor = true;
			this->buttonAddKdj->Click += gcnew System::EventHandler(this, &OperateSettingForm::buttonAddKdj_Click);
			// 
			// buttonAddRsi
			// 
			this->buttonAddRsi->Location = System::Drawing::Point(806, 166);
			this->buttonAddRsi->Name = L"buttonAddRsi";
			this->buttonAddRsi->Size = System::Drawing::Size(121, 26);
			this->buttonAddRsi->TabIndex = 181;
			this->buttonAddRsi->Text = L"ADD RSI";
			this->buttonAddRsi->UseVisualStyleBackColor = true;
			this->buttonAddRsi->Click += gcnew System::EventHandler(this, &OperateSettingForm::buttonAddRsi_Click);
			// 
			// buttonAddRoc
			// 
			this->buttonAddRoc->Location = System::Drawing::Point(806, 214);
			this->buttonAddRoc->Name = L"buttonAddRoc";
			this->buttonAddRoc->Size = System::Drawing::Size(121, 26);
			this->buttonAddRoc->TabIndex = 182;
			this->buttonAddRoc->Text = L"Add ROC";
			this->buttonAddRoc->UseVisualStyleBackColor = true;
			this->buttonAddRoc->Click += gcnew System::EventHandler(this, &OperateSettingForm::buttonAddRoc_Click);
			// 
			// buttonAddWr
			// 
			this->buttonAddWr->Location = System::Drawing::Point(806, 305);
			this->buttonAddWr->Name = L"buttonAddWr";
			this->buttonAddWr->Size = System::Drawing::Size(121, 26);
			this->buttonAddWr->TabIndex = 183;
			this->buttonAddWr->Text = L"Add WR";
			this->buttonAddWr->UseVisualStyleBackColor = true;
			this->buttonAddWr->Click += gcnew System::EventHandler(this, &OperateSettingForm::buttonAddWr_Click);
			// 
			// buttonAddMacd
			// 
			this->buttonAddMacd->Location = System::Drawing::Point(806, 424);
			this->buttonAddMacd->Name = L"buttonAddMacd";
			this->buttonAddMacd->Size = System::Drawing::Size(121, 26);
			this->buttonAddMacd->TabIndex = 184;
			this->buttonAddMacd->Text = L"Add MACD";
			this->buttonAddMacd->UseVisualStyleBackColor = true;
			this->buttonAddMacd->Click += gcnew System::EventHandler(this, &OperateSettingForm::buttonAddMacd_Click);
			// 
			// buttonAddDma
			// 
			this->buttonAddDma->Location = System::Drawing::Point(807, 514);
			this->buttonAddDma->Name = L"buttonAddDma";
			this->buttonAddDma->Size = System::Drawing::Size(121, 26);
			this->buttonAddDma->TabIndex = 185;
			this->buttonAddDma->Text = L"Add DMA";
			this->buttonAddDma->UseVisualStyleBackColor = true;
			this->buttonAddDma->Click += gcnew System::EventHandler(this, &OperateSettingForm::buttonAddDma_Click);
			// 
			// buttonAddVr
			// 
			this->buttonAddVr->Location = System::Drawing::Point(806, 603);
			this->buttonAddVr->Name = L"buttonAddVr";
			this->buttonAddVr->Size = System::Drawing::Size(121, 26);
			this->buttonAddVr->TabIndex = 186;
			this->buttonAddVr->Text = L"Add VR";
			this->buttonAddVr->UseVisualStyleBackColor = true;
			this->buttonAddVr->Click += gcnew System::EventHandler(this, &OperateSettingForm::buttonAddVr_Click);
			// 
			// buttonAddCci
			// 
			this->buttonAddCci->Location = System::Drawing::Point(806, 694);
			this->buttonAddCci->Name = L"buttonAddCci";
			this->buttonAddCci->Size = System::Drawing::Size(121, 26);
			this->buttonAddCci->TabIndex = 187;
			this->buttonAddCci->Text = L"Add CCI";
			this->buttonAddCci->UseVisualStyleBackColor = true;
			this->buttonAddCci->Click += gcnew System::EventHandler(this, &OperateSettingForm::buttonAddCci_Click);
			// 
			// buttonAddCr
			// 
			this->buttonAddCr->Location = System::Drawing::Point(807, 786);
			this->buttonAddCr->Name = L"buttonAddCr";
			this->buttonAddCr->Size = System::Drawing::Size(121, 26);
			this->buttonAddCr->TabIndex = 188;
			this->buttonAddCr->Text = L"Add CR";
			this->buttonAddCr->UseVisualStyleBackColor = true;
			this->buttonAddCr->Click += gcnew System::EventHandler(this, &OperateSettingForm::buttonAddCr_Click);
			// 
			// buttonAddMA
			// 
			this->buttonAddMA->Location = System::Drawing::Point(313, 834);
			this->buttonAddMA->Name = L"buttonAddMA";
			this->buttonAddMA->Size = System::Drawing::Size(121, 26);
			this->buttonAddMA->TabIndex = 189;
			this->buttonAddMA->Text = L"Add MA[n]";
			this->buttonAddMA->UseVisualStyleBackColor = true;
			this->buttonAddMA->Click += gcnew System::EventHandler(this, &OperateSettingForm::buttonAddMA_Click);
			// 
			// buttonAddVol
			// 
			this->buttonAddVol->Location = System::Drawing::Point(810, 831);
			this->buttonAddVol->Name = L"buttonAddVol";
			this->buttonAddVol->Size = System::Drawing::Size(121, 26);
			this->buttonAddVol->TabIndex = 190;
			this->buttonAddVol->Text = L"Add Vol[n]";
			this->buttonAddVol->UseVisualStyleBackColor = true;
			this->buttonAddVol->Click += gcnew System::EventHandler(this, &OperateSettingForm::buttonAddVol_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(735, 267);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 19);
			this->label3->TabIndex = 192;
			this->label3->Text = L"Middle:";
			// 
			// textBoxWrMiddle
			// 
			this->textBoxWrMiddle->Location = System::Drawing::Point(809, 260);
			this->textBoxWrMiddle->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxWrMiddle->Name = L"textBoxWrMiddle";
			this->textBoxWrMiddle->Size = System::Drawing::Size(118, 26);
			this->textBoxWrMiddle->TabIndex = 191;
			// 
			// OperateSettingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(946, 878);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxWrMiddle);
			this->Controls->Add(this->buttonAddVol);
			this->Controls->Add(this->buttonAddMA);
			this->Controls->Add(this->buttonAddCr);
			this->Controls->Add(this->buttonAddCci);
			this->Controls->Add(this->buttonAddVr);
			this->Controls->Add(this->buttonAddDma);
			this->Controls->Add(this->buttonAddMacd);
			this->Controls->Add(this->buttonAddWr);
			this->Controls->Add(this->buttonAddRoc);
			this->Controls->Add(this->buttonAddRsi);
			this->Controls->Add(this->buttonAddKdj);
			this->Controls->Add(this->buttonAddBoll);
			this->Controls->Add(this->label59);
			this->Controls->Add(this->textBoxCrDiff);
			this->Controls->Add(this->label58);
			this->Controls->Add(this->textBoxCciDirLine);
			this->Controls->Add(this->label51);
			this->Controls->Add(this->textBoxVrDiff);
			this->Controls->Add(this->label57);
			this->Controls->Add(this->textBoxDmaDirLine);
			this->Controls->Add(this->label56);
			this->Controls->Add(this->textBoxDmaDiff);
			this->Controls->Add(this->label55);
			this->Controls->Add(this->textBoxCrMiddle);
			this->Controls->Add(this->label54);
			this->Controls->Add(this->textBoxCciMiddle);
			this->Controls->Add(this->label53);
			this->Controls->Add(this->textBoxVrMiddle);
			this->Controls->Add(this->label52);
			this->Controls->Add(this->textBoxDmaMiddle);
			this->Controls->Add(this->label50);
			this->Controls->Add(this->textBoxMacdZeroLine);
			this->Controls->Add(this->label49);
			this->Controls->Add(this->textBoxMacdCrossLine);
			this->Controls->Add(this->label48);
			this->Controls->Add(this->textBoxMacdUpper);
			this->Controls->Add(this->label46);
			this->Controls->Add(this->textBoxMacdMiddle);
			this->Controls->Add(this->label47);
			this->Controls->Add(this->textBoxMacdLow);
			this->Controls->Add(this->listBoxVol);
			this->Controls->Add(this->label42);
			this->Controls->Add(this->label43);
			this->Controls->Add(this->listBoxMa);
			this->Controls->Add(this->label44);
			this->Controls->Add(this->label45);
			this->Controls->Add(this->label38);
			this->Controls->Add(this->textBoxCrTop);
			this->Controls->Add(this->label39);
			this->Controls->Add(this->textBoxCrBottom);
			this->Controls->Add(this->listBoxCr);
			this->Controls->Add(this->label40);
			this->Controls->Add(this->label41);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->textBoxCciTop);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->textBoxCciBottom);
			this->Controls->Add(this->listBoxCci);
			this->Controls->Add(this->label36);
			this->Controls->Add(this->label37);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->textBoxDmaTop);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->textBoxDmaBottom);
			this->Controls->Add(this->listBoxDma);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->textBoxMacdSell);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->textBoxMacdBuy);
			this->Controls->Add(this->listBoxMacd);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->textBoxVrTop);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->textBoxVrBottom);
			this->Controls->Add(this->listBoxVr);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->listBoxWrNeg);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->textBoxWrTop);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->textBoxWrBottom);
			this->Controls->Add(this->listBoxWr);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->textBoxRocTop);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->textBoxRocBottom);
			this->Controls->Add(this->listBoxRoc);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBoxRsiTop);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBoxRsiBottom);
			this->Controls->Add(this->listBoxRsi);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBoxKdjSellCross);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxKdjBuyCross);
			this->Controls->Add(this->listBoxKdj);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxBollSell);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxBollBuy);
			this->Controls->Add(this->listBoxBoll);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->labelBoll);
			this->Controls->Add(this->textBoxObject);
			this->Controls->Add(this->labelObject);
			this->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"OperateSettingForm";
			this->Text = L"WOpearteSetting";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

/*enum Period
{
	none_period,
	all_period=0x7FF,//all
	year=1,
	month=2,
	week=4,
	day=8,
	hour4=0x10,//4h/H H4 4hour,hour4
	hour1=0x20,//1h/H H/h1 1hour hour1
	min45=0x40,//45m/M M/m45 45min min45
	min30=0x800,//30m/M M/m30 30min min30
	min15=0x100,//15m/M min15 MIN15
	min10=0x200,//10m/M min10 MIN10
	min5=0x400,//5min Min5
};*/
//0:ALL 1:Year 2:Month 3:Week 4:Day 5:4Hour 6:1Hour 7:45Min 8:30Min 9:15Min15 10:10Min 11:5Min
private: System::Void listBoxBoll_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoperateSetting::set_period((int) this->listBoxBoll->SelectedIndex,&bollSetting);
		 }
private: System::Void listBoxKdj_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			  CoperateSetting::set_period((int) this->listBoxKdj->SelectedIndex,&kdjSetting);
		 }
private: System::Void listBoxRsi_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				CoperateSetting::set_period((int) this->listBoxRsi->SelectedIndex,&rsiSetting);
		 }
private: System::Void listBoxRoc_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoperateSetting::set_period((int) this->listBoxRoc->SelectedIndex,&rocSetting);
		 }
private: System::Void listBoxWr_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoperateSetting::set_period((int) this->listBoxWr->SelectedIndex,&wrSetting);
		 }
private: System::Void listBoxMacd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			CoperateSetting::set_period((int) this->listBoxMacd->SelectedIndex,&macdSetting);
		 }
private: System::Void listBoxDma_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			CoperateSetting::set_period((int) this->listBoxDma->SelectedIndex,&dmaSetting);
		 }
private: System::Void listBoxVr_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			CoperateSetting::set_period((int) this->listBoxVr->SelectedIndex,&vrSetting);
		 }
private: System::Void listBoxCci_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			CoperateSetting::set_period((int) this->listBoxCci->SelectedIndex,&cciSetting);
		 }
private: System::Void listBoxCr_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			CoperateSetting::set_period((int) this->listBoxCr->SelectedIndex,&crSetting);
		 }
private: System::Void listBoxMa_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoperateSetting::set_period((int) this->listBoxMa->SelectedIndex,&maSetting);
		 }
private: System::Void listBoxVol_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 CoperateSetting::set_period((int) this->listBoxVol->SelectedIndex,&volSetting);
		 }
private: System::Void buttonAddBoll_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->textBoxObject->Text->Length<2)	return;
			 if(this->textBoxBollBuy->Text->Length<1||this->textBoxBollSell->Text->Length<1) return;
			 //boll-setting: (object,boll,period,setting,buy,sell)	
			 bollSetting.value[0]=System::Convert::ToDouble(this->textBoxBollBuy->Text);
			 bollSetting.value[1]=System::Convert::ToDouble(this->textBoxBollSell->Text);
			CoperateSetting::add(fileName,object_setting,"boll",bollSetting.period,bollSetting.value,2);
			bollSetting.period=none_period;
			this->listBoxBoll->SelectedIndex=-1;
		 }
private: System::Void textBoxObject_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 String ^str = this->textBoxObject->Text;

			 // Pin memory so GC can't move it while native function is called
			 pin_ptr<const wchar_t> wch = PtrToStringChars(str);
			// printf_s("%S\n", wch);

			 // Conversion to char* :
			 // Can just convert wchar_t* to char* using one of the 
			 // conversion functions such as: 
			 // WideCharToMultiByte()
			 // wcstombs_s()
			 // ... etc
			 size_t convertedChars = 0;
			 size_t  sizeInBytes = ((str->Length + 1) * 2);
			 errno_t err = 0;
			 char    *ch = object_setting;//(char *)malloc(sizeInBytes);
			 if(sizeInBytes>OBJECT_LEN)sizeInBytes=OBJECT_LEN-2;

			 err = wcstombs_s(&convertedChars, 
				 ch, sizeInBytes,
				 wch, sizeInBytes);
			// if (err != 0)
				 //printf_s("wcstombs_s  failed!\n");

			// printf_s("%s\n", ch);
			sprintf(fileName,"%s.ini",object_setting);
		 }
private: System::Void buttonAddKdj_Click(System::Object^  sender, System::EventArgs^  e) {			 
			 if(this->textBoxObject->Text->Length<2)	return;
			 if(this->textBoxKdjBuyCross->Text->Length<1||this->textBoxKdjSellCross->Text->Length<1) return;
			 //kdj-setting: (object,kdj,period,setting,buy_cross,sell_cross)	
			 kdjSetting.value[0]=System::Convert::ToDouble(this->textBoxKdjBuyCross->Text);
			 kdjSetting.value[1]=System::Convert::ToDouble(this->textBoxKdjSellCross->Text);
			CoperateSetting::add(fileName,object_setting,"kdj",kdjSetting.period,kdjSetting.value,2);
			kdjSetting.period=none_period;
			this->listBoxKdj->SelectedIndex=-1;
		 }
private: System::Void buttonAddRsi_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->textBoxObject->Text->Length<2)	return;
			 if(this->textBoxRsiBottom->Text->Length<1||this->textBoxRsiTop->Text->Length<1) return;
			//rsi-setting: (object,rsi,period,setting,bottom,top)
			 rsiSetting.value[0]=System::Convert::ToDouble(this->textBoxRsiBottom->Text);
			 rsiSetting.value[1]=System::Convert::ToDouble(this->textBoxRsiTop->Text);
			CoperateSetting::add(fileName,object_setting,"rsi",rsiSetting.period,rsiSetting.value,2);
			rsiSetting.period=none_period;
			this->listBoxRsi->SelectedIndex=-1;
		 }
private: System::Void buttonAddRoc_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->textBoxObject->Text->Length<2)	return;
			 if(this->textBoxRocBottom->Text->Length<1||this->textBoxRocTop->Text->Length<1) return;
			//roc-setting: (object,roc,period,setting,bottom,top)	
			 rocSetting.value[0]=System::Convert::ToDouble(this->textBoxRocBottom->Text);
			 rocSetting.value[1]=System::Convert::ToDouble(this->textBoxRocTop->Text);
			CoperateSetting::add(fileName,object_setting,"roc",rocSetting.period,rocSetting.value,2);
			rocSetting.period=none_period;
			this->listBoxRoc->SelectedIndex=-1;
		 }
private: System::Void buttonAddWr_Click(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->textBoxObject->Text->Length<2)	return;
			 if(this->textBoxWrBottom->Text->Length<1||this->textBoxWrTop->Text->Length<1||this->textBoxWrMiddle->Text->Length<1) return;
			//negative:NO_NEG	1 (oil use ) ,IS_NEG	-1(default) (stock use)
			//wr-setting: (object,wr,period,setting,bottom,middle,top,negative)
			 wrSetting.value[3]=-1;
			 if(this->listBoxWrNeg->SelectedIndex==1)	wrSetting.value[2]=1;
			 wrSetting.value[0]=System::Convert::ToDouble(this->textBoxWrBottom->Text);
		 	 wrSetting.value[1]=System::Convert::ToDouble(this->textBoxWrMiddle->Text);
			 wrSetting.value[2]=System::Convert::ToDouble(this->textBoxWrTop->Text);
			CoperateSetting::add(fileName,object_setting,"wr",wrSetting.period,wrSetting.value,4);
			wrSetting.period=none_period;
			this->listBoxWr->SelectedIndex=-1;
		 }
private: System::Void buttonAddMacd_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->textBoxObject->Text->Length<2)	return;
			 if(this->textBoxMacdBuy->Text->Length<1||this->textBoxMacdSell->Text->Length<1||this->textBoxMacdLow->Text->Length<1||\
				 this->textBoxMacdMiddle->Text->Length<1||this->textBoxMacdUpper->Text->Length<1||this->textBoxMacdCrossLine->Text->Length<1||this->textBoxMacdZeroLine->Text->Length<1) return;
			//macd-setting: (object,macd,period,setting,buy,sell,low,mid,upper,cross_line,zero_line)		
			 macdSetting.value[0]=System::Convert::ToDouble(this->textBoxMacdBuy->Text);
			 macdSetting.value[1]=System::Convert::ToDouble(this->textBoxMacdSell->Text);
			 macdSetting.value[2]=System::Convert::ToDouble(this->textBoxMacdLow->Text);
			 macdSetting.value[3]=System::Convert::ToDouble(this->textBoxMacdMiddle->Text);
			 macdSetting.value[4]=System::Convert::ToDouble(this->textBoxMacdUpper->Text);
			 macdSetting.value[5]=System::Convert::ToDouble(this->textBoxMacdCrossLine->Text);
 			 macdSetting.value[6]=System::Convert::ToDouble(this->textBoxMacdZeroLine->Text);
			CoperateSetting::add(fileName,object_setting,"macd",macdSetting.period,macdSetting.value,7);
			macdSetting.period=none_period;
			this->listBoxMacd->SelectedIndex=-1;
		 }
private: System::Void buttonAddDma_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->textBoxObject->Text->Length<2)	return;
			 if(this->textBoxDmaDiff->Text->Length<1||this->textBoxDmaBottom->Text->Length<1||this->textBoxDmaMiddle->Text->Length<1||\
				 this->textBoxDmaTop->Text->Length<1||this->textBoxDmaDirLine->Text->Length<1) return;
			//dma-setting: (object,dma,period,setting,diff,bottom,middle,top,dir_line)		
			 dmaSetting.value[0]=System::Convert::ToDouble(this->textBoxDmaDiff->Text);
			 dmaSetting.value[1]=System::Convert::ToDouble(this->textBoxDmaBottom->Text);
			 dmaSetting.value[2]=System::Convert::ToDouble(this->textBoxDmaMiddle->Text);
			 dmaSetting.value[3]=System::Convert::ToDouble(this->textBoxDmaTop->Text);
			 dmaSetting.value[4]=System::Convert::ToDouble(this->textBoxDmaDirLine->Text);
			CoperateSetting::add(fileName,object_setting,"dma",dmaSetting.period,dmaSetting.value,5);
			dmaSetting.period=none_period;
			this->listBoxDma->SelectedIndex=-1;
		 }
private: System::Void buttonAddVr_Click(System::Object^  sender, System::EventArgs^  e) {
 			 if(this->textBoxObject->Text->Length<2)	return;
			 if(this->textBoxVrDiff->Text->Length<1||this->textBoxVrBottom->Text->Length<1||this->textBoxVrMiddle->Text->Length<1||this->textBoxVrTop->Text->Length<1) return;
			//vr-setting: (object,vr,period,setting,diff,bottom,middle,top)		
			 vrSetting.value[0]=System::Convert::ToDouble(this->textBoxVrDiff->Text);
			 vrSetting.value[1]=System::Convert::ToDouble(this->textBoxVrBottom->Text);
			 vrSetting.value[2]=System::Convert::ToDouble(this->textBoxVrMiddle->Text);
			 vrSetting.value[3]=System::Convert::ToDouble(this->textBoxVrTop->Text);
			CoperateSetting::add(fileName,object_setting,"vr",vrSetting.period,vrSetting.value,4);
			vrSetting.period=none_period;
			this->listBoxVr->SelectedIndex=-1;
		 }
private: System::Void buttonAddCci_Click(System::Object^  sender, System::EventArgs^  e) {
  			 if(this->textBoxObject->Text->Length<2)	return;
			 if(this->textBoxCciBottom->Text->Length<1||this->textBoxCciMiddle->Text->Length<1||this->textBoxCciTop->Text->Length<1||this->textBoxCciDirLine->Text->Length<1) return;
			//cci-setting: (object,cci,period,setting,bottom,middle,top,dir_line)			
			 cciSetting.value[0]=System::Convert::ToDouble(this->textBoxCciBottom->Text);
			 cciSetting.value[1]=System::Convert::ToDouble(this->textBoxCciMiddle->Text);
			 cciSetting.value[2]=System::Convert::ToDouble(this->textBoxCciTop->Text);
			 cciSetting.value[3]=System::Convert::ToDouble(this->textBoxCciDirLine->Text);
			CoperateSetting::add(fileName,object_setting,"cci",cciSetting.period,cciSetting.value,4);
			cciSetting.period=none_period;
			this->listBoxCci->SelectedIndex=-1;
		 }
private: System::Void buttonAddCr_Click(System::Object^  sender, System::EventArgs^  e) {
   			 if(this->textBoxObject->Text->Length<2)	return;
			 if(this->textBoxCrDiff->Text->Length<1||this->textBoxCrBottom->Text->Length<1||this->textBoxCrMiddle->Text->Length<1||this->textBoxCrTop->Text->Length<1) return;
			//cr-setting: (object,cr,period,setting,diff,bottom,middle,top)				
			 crSetting.value[0]=System::Convert::ToDouble(this->textBoxCrDiff->Text);
			 crSetting.value[1]=System::Convert::ToDouble(this->textBoxCrBottom->Text);
			 crSetting.value[2]=System::Convert::ToDouble(this->textBoxCrMiddle->Text);
			 crSetting.value[3]=System::Convert::ToDouble(this->textBoxCrTop->Text);
			CoperateSetting::add(fileName,object_setting,"cr",crSetting.period,crSetting.value,4);
			crSetting.period=none_period;
			this->listBoxCr->SelectedIndex=-1;
		 }
private: System::Void buttonAddMA_Click(System::Object^  sender, System::EventArgs^  e) {
			  if(this->textBoxObject->Text->Length<2)	return;
			  //ma-setting: (object,ma,all,setting)	
			  if(this->listBoxMa->SelectedIndex<0) maSetting.period=all_period;
			  CoperateSetting::add(fileName,object_setting,"ma",maSetting.period,crSetting.value,0);
			  maSetting.period=none_period;
			  this->listBoxMa->SelectedIndex=-1;
		 }
private: System::Void buttonAddVol_Click(System::Object^  sender, System::EventArgs^  e) {			 
			 if(this->textBoxObject->Text->Length<2)	return;
			 //vol-setting: (object,vol,all,setting)	
			 if(this->listBoxVol->SelectedIndex<0) volSetting.period=all_period;
			 CoperateSetting::add(fileName,object_setting,"vol",volSetting.period,volSetting.value,0);
			volSetting.period=none_period;
			this->listBoxVol->SelectedIndex=-1;
		 }
};
}
