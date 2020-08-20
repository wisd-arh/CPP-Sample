//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "stdlib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
log *log1;
cardset *set1;
int stop;

game *game1;
double m;     // game summ

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  log1->mix(100000);
  Memo1->Lines->Clear();
  set1 = new cardset();
  for (int i=0; i<5; i++) {
    set1->addcard(log1->cards[i]);
  }
//  set1->sort();
  if (set1->is2pair()) {
    Memo1->Lines->Add("Game!");
  } else {
    Memo1->Lines->Add("No.");
  }
  for (int i=0; i<set1->n; i++) {
    Memo1->Lines->Add(IntToStr(set1->cards[i].power) + "::" + IntToStr(set1->cards[i].suit));
  }

  delete set1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  log1 = new log();
  log1->mix(100000);
  StatusBar1->SimpleText = "Колода создана и перемешана";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  delete log1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
  Memo1->Lines->Clear();
  for (int i=0; i<log1->n; i++) {
    Memo1->Lines->Add(IntToStr(log1->cards[i].power) + "::" + IntToStr(log1->cards[i].suit));
  }
//
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
//
  double n;
  double g;
  double ng;

  int b;
  int k;

  Series1->Clear();
  n = 0;
  g = 0;
  ng = 0;
  stop = 0;

  switch (RadioGroup2->ItemIndex) {
    case 0: k=5; break;
    case 1: k=6; break;
    case 2: k=7; break;
  }
  for (int i=0; i<10000; i++) {
    Application->ProcessMessages();
    if (stop) {
      return;
    }
    log1->mix(1000);
    set1 = new cardset();

    for (int i=0; i<k; i++) {
      set1->addcard(log1->cards[i]);
    }
    switch (RadioGroup1->ItemIndex) {
      case 0: b = set1->isace_king(); break;
      case 1: b = set1->ispair();  break;
      case 2: b = set1->is2pair();  break;
      case 3: b = set1->istriple();  break;
      case 4: b = set1->isstraight();  break;
      case 5: b = set1->isflash();  break;
      case 6: b = set1->isgame();  break;
      case 7: b = !set1->isgame();  break;
    }

    if (b) {
      g++;
    } else {
      ng++;
    };
    n++;
    Series1->Add(g/n,"", clRed);
    Form1->Update();
    delete set1;
  }
//  Memo1->Lines->Add(FloatToStr(g/n));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
  stop = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
  game1 = new game(log1);
  StatusBar1->SimpleText = "Создана игра";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
  log1->mix(10000);
  game1->addset();

  Memo1->Lines->Clear();
  for (int i=0; i<game1->sets[game1->n-1]->n; i++) {
    Memo1->Lines->Add(IntToStr(game1->sets[game1->n-1]->cards[i].power) + "::" + IntToStr(game1->sets[game1->n-1]->cards[i].suit));
  }
  game1->addset();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
  delete game1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
  game1->addset();
  game1->addset();
  StatusBar1->SimpleText = "Сдано два набора. В колоде " + IntToStr(log1->n) + " карт";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
//
  int y;
  double m;
  y = game1->compareset(0, 1, &m);
  Memo1->Lines->Add(IntToStr(y));

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
  int y;
//  double n;
  double m;

  double mult;

  TeeDefaultCapacity = 10000;
  Series1->Clear();
//  n = 0;
  m = 3000.0;
  stop = 0;

  for (int i=0; i<10000; i++) {
    Application->ProcessMessages();
    if (stop) {
      return;
    }

    log1 = new log();
    log1->mix(10000);
    game1 = new game(log1);
    game1->addset();
    game1->addset();
    switch (RadioGroup3->ItemIndex) {
//      case 0: break;
      case 1: game1->addset(); break;
    }


//    n++;
    y = game1->compareset(0, 1, &mult);

    switch (y) {
      case -3: m = m + 100; break;
      case -2: m = m - 100; break;
      case -1: m = m - 300; break;
//      case 0: m = m + 300; break;
      case 1: m = m + 200.0*mult + 100; break;
    }

    switch (RadioGroup3->ItemIndex) {
//      case 0: break;
      case 1: {
        y = game1->compareset(0, 2, &mult);
        switch (y) {
          case -3: m = m + 100; break;
          case -2: m = m - 100; break;
          case -1: m = m - 300; break;
    //      case 0: m = m + 300; break;
          case 1: m = m + 200.0*mult + 100; break;
        }
      }  break;
    }
//    Memo1->Lines->Add(FloatToStr(m));

    Series1->Add(m,"", clRed);
    Form1->Update();
    delete game1;
    delete log1;

  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  randomize();
  Form1->Image1->Picture->Bitmap->Width = 100;
  Form1->Image1->Picture->Bitmap->Height = 250;

  Form1->Image2->Picture->Bitmap->Width = 100;
  Form1->Image2->Picture->Bitmap->Height = 250;
  m = 3000.0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button13Click(TObject *Sender)
{
  int y;
  double mult;

  int stat;
  double total;
  total = 0.0;

  stat = 5000;
  for (int n=0; n<stat; n++) {
    m = 3000.0;
    for (int i=0; i<100; i++) {

      log1 = new log();
      log1->mix(500);
      game1 = new game(log1);
      game1->addset();
      game1->addset();
      y = game1->compareset(0, 1, &mult);

      switch (y) {
        case -3: m += 100.0; // Label3->Caption = "Нет игры";
        break;
        case -2: m -= 100.0; // Label3->Caption = "Игрок скинул";
        break;
        case -1: m -= 300.0; // Label3->Caption = "Старше у дилера";
        break;
  //      case 0: m = m + 300; break;
        case 1: m += 200.0*mult + 100.0; // Label3->Caption = "Старше у игрока. Выигрыш = " + (AnsiString)FloatToStr(200.0*mult + 100.0);
        break;
      }
/*      ShowCardSet(Form1->Image1, game1->sets[1]);
      ShowCardSet(Form1->Image2, game1->sets[0]);
      Memo1->Lines->Add(FloatToStr(m));
*/      delete game1;
      delete log1;
    }
    total += m;
  }

  Memo1->Lines->Add(FloatToStr(total/stat));
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button14Click(TObject *Sender)
{
  int y;
  double mult;

//  int stat;
//  double total;
//  total = 0.0;

//  stat = 5000;
//  for (int n=0; n<stat; n++) {
//    m = 3000.0;
//    for (int i=0; i<100; i++) {

      log1 = new log();
      log1->mix(1000);
      game1 = new game(log1);
      game1->addset();
      game1->addset();
      y = game1->compareset(0, 1, &mult);

      switch (y) {
        case -3: m += 100.0; Label3->Caption = "Нет игры"; break;
        case -2: m -= 100.0; Label3->Caption = "Игрок скинул"; break;
        case -1: m -= 300.0; Label3->Caption = "Старше у дилера"; break;
  //      case 0: m = m + 300; break;
        case 1: m += 200.0*mult + 100.0; Label3->Caption = "Старше у игрока. Выигрыш = " + (AnsiString)FloatToStr(200.0*mult + 100.0);
        break;
      }
      m-=game1->nchanges*100;
      ShowCardSet(Form1->Image1, game1->sets[1]);
      ShowCardSet(Form1->Image2, game1->sets[0]);
      Memo1->Lines->Add(FloatToStr(m));
      delete game1;
      delete log1;
//    }
//    total += m;
//  }

//  Memo1->Lines->Add(FloatToStr(total/stat));
}
//---------------------------------------------------------------------------

