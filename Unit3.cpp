//---------------------------------------------------------------------------


#pragma hdrstop

#include "Unit3.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


void ShowCardSet(TImage *im, cardset *cs) {
  Graphics::TBitmap *bm;

  bm = new Graphics::TBitmap();
  for (int i = 0; i < cs->n; i++) {

    switch (cs->cards[i].power) {
      case 1: bm->LoadFromFile("2.bmp"); break;
      case 2: bm->LoadFromFile("3.bmp"); break;
      case 3: bm->LoadFromFile("4.bmp"); break;
      case 4: bm->LoadFromFile("5.bmp"); break;
      case 5: bm->LoadFromFile("6.bmp"); break;
      case 6: bm->LoadFromFile("7.bmp"); break;
      case 7: bm->LoadFromFile("8.bmp"); break;
      case 8: bm->LoadFromFile("9.bmp"); break;
      case 9: bm->LoadFromFile("10.bmp"); break;
      case 10: bm->LoadFromFile("J.bmp"); break;
      case 11: bm->LoadFromFile("Q.bmp"); break;
      case 12: bm->LoadFromFile("K.bmp"); break;
      case 13: bm->LoadFromFile("A.bmp"); break;
    }
    im->Picture->Bitmap->Canvas->Draw(0, i*50, bm);
    switch (cs->cards[i].suit) {
      case 1: bm->LoadFromFile("m1.bmp"); break;
      case 2: bm->LoadFromFile("m2.bmp"); break;
      case 3: bm->LoadFromFile("m3.bmp"); break;
      case 4: bm->LoadFromFile("m4.bmp"); break;
    }
    im->Picture->Bitmap->Canvas->Draw(50, i*50, bm);
  }
//  bm->Free();
  delete bm;
}