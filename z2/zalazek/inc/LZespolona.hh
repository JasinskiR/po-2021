#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include<iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct LZespolona {
  double re; /*! Pole repezentuje czesc rzeczywista. */
  double im; /*! Pole repezentuje czesc urojona. */
};

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

LZespolona operator+(LZespolona& Skl1, LZespolona& Skl2);
LZespolona operator-(LZespolona& Skl1, LZespolona& Skl2);
LZespolona operator/(LZespolona& Skl1, LZespolona& Skl2);
LZespolona operator/(LZespolona &Licznik, double dzielnik);
LZespolona operator*(LZespolona Skl1, LZespolona Skl2);
LZespolona sprzezenie(LZespolona& Zespolona);
bool operator==(const LZespolona &Skl1, const LZespolona &Skl2);
bool operator!=(const LZespolona &Skl1, const LZespolona &Skl2);

double modul(LZespolona& Zespolona);

LZespolona inicjuj(LZespolona& L1,int x,int y);
std::ostream& operator<<(std::ostream& strm, LZespolona& L1);
std::istream& operator>>(std::istream& strm, LZespolona& L1);

#endif
