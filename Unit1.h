//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
  TButton *Button1;
  TMemo *Memo1;
  TButton *Button2;
  TButton *Button3;
  TButton *Button4;
  TButton *Button5;
  TButton *Button7;
  TRadioGroup *RadioGroup1;
  TButton *Button6;
  TButton *Button8;
  TButton *Button9;
  TButton *Button10;
  TStatusBar *StatusBar1;
  TButton *Button11;
  TButton *Button12;
  TChart *Chart1;
  TRadioGroup *RadioGroup2;
  TMainMenu *MainMenu1;
  TMenuItem *File1;
  TRadioGroup *RadioGroup3;
  TLineSeries *Series1;
  TButton *Button13;
  TImage *Image1;
  TImage *Image2;
  TLabel *Label1;
  TLabel *Label2;
  TLabel *Label3;
  TButton *Button14;
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall Button2Click(TObject *Sender);
  void __fastcall Button3Click(TObject *Sender);
  void __fastcall Button4Click(TObject *Sender);
  void __fastcall Button5Click(TObject *Sender);
  void __fastcall Button7Click(TObject *Sender);
  void __fastcall Button6Click(TObject *Sender);
  void __fastcall Button8Click(TObject *Sender);
  void __fastcall Button9Click(TObject *Sender);
  void __fastcall Button10Click(TObject *Sender);
  void __fastcall Button11Click(TObject *Sender);
  void __fastcall Button12Click(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall Button13Click(TObject *Sender);
  void __fastcall Button14Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
