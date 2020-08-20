//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H

#include "stdlib.h"
#include "stddef.h"
#include "Dialogs.hpp"
//---------------------------------------------------------------------------

struct card {
  char power;
  char suit;

};

class log {
  public:
    card* cards;
    char n;
    log(char v = 52);
    ~log();

    void mix(int v = 1000);
};

log::log(char v) {
  char p;
  char s;
  n = v;
  cards = new card[v];
  s = 1;
  p = 1;
  for (int i=0; i<v; i++) {
    cards[i].power = p;
    cards[i].suit = s;
    s++;
    if (s == 5) {
      s = 1;
      p++;
    }
  }
}

log::~log() {
  delete[] cards;
}

void log::mix(int v) {
  card t;
  int k;
  int p;
  for (int i=0; i<v; i++) {
    k = random(n);
    p = random(n);
    t = cards[k];
    cards[k] = cards[p];
    cards[p] = t;
  }

}

class cardset {
  public:
    int n;
    card *cards;

    cardset(){n = 0; cards = NULL; };
    ~cardset(){if (cards!=NULL) { delete[] cards; cards = NULL; n = 0;}};

    void addcard(card t);
    char ispair();
    char is2pair();
    char istriple();
    char iscare();
    char isflash();
    char isace_king();
    char isstraight();
    char isstraight_flash();
    char isgame();

    char tryflash(int &nc);
  private:
    char isace();
    char isking();
    void sort(card *t, int tn);
    void sortsuit(card *t, int tn);
};

typedef
    cardset *pcardset;
    
int sort_f(const void *a, const void *b);
int sort_s(const void *a, const void *b);

void cardset:: addcard(card t) {
  card* p;
  p = new card[n+1];
  for (int i=0; i<n; i++) {
    p[i] = cards[i];
  }
  p[n] = t;
  if (cards != NULL) {
    delete[] cards;
  }
  cards = new card[n+1];
  for (int i=0; i<n+1; i++) {
    cards[i] = p[i];
  }
  n++;
  delete[] p;
}

char cardset::ispair() {
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      if (cards[i].power == cards[j].power) {
        return 1;
      }
    }
  }
  return 0;
}

char cardset::is2pair() {
  card *t;
  int k;
  if (!ispair()) return 0;

  k = n;
  t = new card[k];
  for (int i=0; i<k; i++) {
    t[i] = cards[i];
  }
//  sort(t, k);
  for (int i=0; i<k; i++) {
    for (int j=i+1; j<k; j++) {
      if (t[i].power == t[j].power) {
        // Первая пара
        t[i].power = -7;
        t[j].power = -8;
        for (int i=0; i<k; i++) {
          for (int j=i+1; j<k; j++) {
            if (t[i].power == t[j].power) {
              delete[] t;
              return 1;
            }
          }
        }
      }
    }
  }
  delete[] t;
  return 0;
}

char cardset::isgame() {
  if (isace_king()) return 1;
  if (ispair()) return 1;
  if (isflash()) return 1;
  if (isstraight()) return 1;
// Дублирующие
//  if (iscare()) return 1;
//  if (is2pair()) return 1;
//  if (istriple()) return 1;
//  if (isstraight_flash()) return 1;
  return 0;
}

char cardset::iscare() {
  card *t;
  int k;
  int q;
  if (!is2pair()) return 0;

  k = n;
  t = new card[k];
  for (int i=0; i<k; i++) {
    t[i] = cards[i];
  }
//  sort(t, k);
  for (int i=0; i<k; i++) {
    for (int j=i+1; j<k; j++) {
      if (t[i].power == t[j].power) {
        // Первая пара
        q = t[i].power;
        t[i].power = -7;
        t[j].power = -8;
        for (int i=0; i<k; i++) {
          for (int j=i+1; j<k; j++) {
            if ((t[i].power == t[j].power)&&(t[i].power == q)) {
              delete[] t;
              return 1;
            }
          }
        }
      }
    }
  }
  delete[] t;
  return 0;
}

char cardset::isflash() {
  char t;
  if (n<=0) return 0;
  t = cards[0].suit;
//  if (n==1) return 1; //? Флеш из одной карты?
  for (int i=1; i<n; i++) {
    if (cards[i].suit != t) return 0;
  }
  return 1;
}

char cardset::isace() {
  for (int i=0; i<n; i++) {
    if (cards[i].power == 13) return 1;
  }
  return 0;
}

char cardset::isking() {
  for (int i=0; i<n; i++) {
    if (cards[i].power == 12) return 1;
  }
  return 0;
}

char cardset::isace_king() {
  if (((isace()&&isking()&&(!ispair()))&&(!isstraight()))&&(!isflash())) return 1;
  return 0;
}

int sort_f(const void *a, const void *b) {
  if (((card *)a)->power < ((card *)b)->power) return -1;
  if (((card *)a)->power == ((card *)b)->power) return 0;
//  if (a.power > b.power)
  return 1;
}

int sort_s(const void *a, const void *b) {
  if (((card *)a)->suit < ((card *)b)->suit) return -1;
  if (((card *)a)->suit == ((card *)b)->suit) return 0;
//  if (a.suit > b.suit)
  return 1;
}


void cardset::sort(card *t, int tn) {
  qsort((void *)t, tn, sizeof(t[0]), sort_f);
}

void cardset::sortsuit(card *t, int tn) {
  qsort((void *)t, tn, sizeof(t[0]), sort_s);
}

char cardset::isstraight() {
  card *t;

  t = new card[n];
  for (int i=0; i< n; i++) {
    t[i] = cards[i];
  }
  sort(t, n);
  for (int i=0; i<n-1; i++) {
    if (t[i].power != t[i+1].power-1) {
      delete[] t;
      return 0;
    }
  }
  delete[] t;
  return 1;
}

char cardset::isstraight_flash() {
  return ((isstraight())&&(isflash()));
}

char cardset::istriple() {
  for (int i=0; i<n; i++)
    for (int j=i+1; j<n; j++)
      for (int k=j+1; k<n; k++)
        if ((cards[i].power == cards[j].power)&&(cards[i].power == cards[k].power)) return 1;
  return 0;      
}

char cardset::tryflash(int &nc){
  char t;
  char y;
  char l; // Число мастей в наборе 
  card *tc; 
  y = 0;
  if (n<=1) return 0;   // Требуется больше чем две

  tc = new card[n];
  for (int i=0; i< n; i++) {
    tc[i] = cards[i];
  }
  sortsuit(tc, n);    /// Возможно не надо???
  t = tc[0].suit;
  l = 1;
  nc = 0;
//  if (n==1) return 1; //? Флеш из одной карты?
  for (int i=1; i<n; i++) {
    if (tc[i].suit != t) y++;
    if (tc[i].suit != tc[i-1].suit) {
      l++;
    }
  }
  if (l == 2) {
    if (y == 1) nc = n-1;
    else if (y == 4) nc = 0;
    for (int i=0; i< n; i++) {
      if ((cards[i].power == tc[nc].power)&&(cards[i].suit == tc[nc].suit)) {
        nc = i;
        break;
      }
    }
  }
  delete[] tc;
  if ((y == 1)||(y == n-1)&&(l == 2)) return 1;
  return 0;
}

void getcardset(log *l, pcardset t, int num) {
  if (num > l->n) return;
  t->cards = new card[num];
  for (int i=0; i<num; i++) {
    t->cards[i] = l->cards[l->n-1 - i];
  }
  t->n = num;
  l->n = l->n - num;
}

class game {
  public:
    int n;
    log *gamelog;
    int nchanges;
    pcardset *sets;
    game(log *l){n = 0; sets = NULL; gamelog = l; nchanges = 0;};
    ~game();
    void addset();
    int compareset(int n1, int n2, double *mult);
    int gamelogic(int n, card dc);
    void change(int nset, int ncard);
};

game::~game() {
  if (sets!=NULL) {
    for (int i=0; i<n; i++) {
      delete sets[i];
    }
    delete[] sets;
    sets = NULL;
    n = 0;
  }
}

void game::addset() {
  pcardset *t;
  t = new pcardset[n+1];
  for (int i=0; i<n; i++) {
//    t[i]. = sets[i];       //~
    t[i] = new cardset();
    t[i]->cards = new card[sets[i]->n];
    for (int j=0; j<sets[i]->n; j++) {
      t[i]->cards[j] = sets[i]->cards[j];
    }
    t[i]->n = sets[i]->n;
  }
  t[n] = new cardset();
  getcardset(gamelog, t[n], 5);

  if (sets!=NULL) {
    for (int i=0; i<n; i++) {
      delete sets[i];
//      sets[i].~cardset();
    }
    delete[] sets;
  }
  sets = new pcardset[n+1];
  for (int i=0; i<n+1; i++) {
//    sets[i] = t[i];
    sets[i] = new cardset();
    sets[i]->cards = new card[t[i]->n];
    for (int j=0; j<t[i]->n; j++) {
      sets[i]->cards[j] = t[i]->cards[j];
    }
    sets[i]->n = t[i]->n;
  }

  n++;
  for (int i=0; i<n; i++) {
     delete t[i];
//     t[i].~cardset();
  }
  delete[] t;
}

int Priority(pcardset t) {
//  if (!t->isgame()) return 0;

  if (t->isstraight_flash()) return 15;
  if (t->iscare()) return 7;
  if (t->isflash()) return 6;
  if (t->isstraight()) return 5;
  if (t->istriple()) return 4;
  if (t->is2pair()) return 3;
  if (t->ispair()) return 2;
  if (t->isace_king()) return 1;
  return 0;
}

int PairPriority(pcardset t) {
  for (int i=0; i<t->n; i++) {
    for (int j=i+1; j<t->n; j++) {
      if (t->cards[i].power == t->cards[j].power) {
        return t->cards[i].power;
      }
    }
  }
  return 0;
}

int game::compareset(int n1, int n2, double *mult){
                                     // -3 - нет игры у дилера
                                     // -2 - нет игры у игрока
                                     // -1 - меньше у игрока
                                     //  0 - равно
                                     //  1 - больше у игрока

  if ((n1 >=n)||(n2 >=n)) {
    ShowMessage("Game::Compareset();" + (AnsiString)0x13 + "Invalid compare operation.");
    return 0;
  }

/*
  if (!sets[n2]->isgame()) {
    return -2;         // Нет игры у игрока.
  }
*/
  if (gamelogic(n2, sets[n1]->cards[4]) == 0) {
    return -2;  // Игрок скинул
  }

  if (sets[n1]->isgame()) {       // есть игра у игрока и дилера
/*     // Скинуть? король_туз.
    if (sets[n2]->isace_king()) {
      return -2;         //
    }
*/
    *mult=1;
    *mult = Priority(sets[n2])-1;
    if ((Priority(sets[n2]) == 2)&&(Priority(sets[n1]) == 2)) {
      if ((sets[n1]->ispair())&&(sets[n2]->ispair())) {
        if ((PairPriority(sets[n1])) == (PairPriority(sets[n2]))) return 0;
        if ((PairPriority(sets[n1])) < (PairPriority(sets[n2]))) return 1;
        if ((PairPriority(sets[n1])) > (PairPriority(sets[n2]))) return -1;
      }
    }
    *mult = Priority(sets[n2])-1;
    if (*mult < 1) *mult=1;
    if ((Priority(sets[n1])) == (Priority(sets[n2]))) return 0;
    if ((Priority(sets[n1])) < (Priority(sets[n2]))) return 1;
    if ((Priority(sets[n1])) > (Priority(sets[n2]))) return -1;
  } else {
    // Есть игра у игрока, но нет у диллера
    return -3;         // Нет игры у дилера.

  }

/*
  if (!sets[n1]->isgame()) {
    return -3;         // Нет игры у дилера.
  }
*/
  ShowMessage("Game::Compareset();" + (AnsiString)0x13 + "Invalid function result.");
  return 0;
}

int game::gamelogic(int n, card dc) {
// Для набора карт игрока.
// n - номер набора игрока (номер бокса)
// dc - открытая карта дилера


// 0 - игрок скинул.
// 1 - игрок закрылся.

  int pp;
  int nc;

  if (sets[n]->tryflash(nc)) {
//    ShowMessage("Game::GameLogic.\nPossible flash.\n" + IntToStr(nc));
    change(n, nc);
/*    if (sets[n]->tryflash(nc)) {
  //    ShowMessage("Game::GameLogic.\nPossible flash.\n" + IntToStr(nc));
      change(n, nc);
      return 1;
    }
*/
  }


  if (!sets[n]->isgame()) {
    return 0;         // Нет игры у игрока.
  }

  // Скинуть? король_туз.
  if (sets[n]->isace_king()) {
    return 0;
  }

/*
//  if (sets[n]->ispair()) {
  if (Priority(sets[n]) == 2) {
    pp = PairPriority(sets[n]);
//    if ((pp < 5)&&(pp >= dc.power)) return 1;
//    if (pp < 5) return 0;
//    if ((pp < dc.power)&&(pp < 7)) return 0;
//    return 1;
  }
*/
  return 1;
}

void game::change(int nset, int ncard) {
// Обмен карты
// nset - номер набора
// ncard - номер карты

  if (gamelog->n < 1) return;
  if (nset >= n) return;
  if (sets[nset]->n <= ncard) return;
  sets[nset]->cards[ncard] = gamelog->cards[gamelog->n - 1];
  gamelog->n--;
  nchanges++;
}


#endif
