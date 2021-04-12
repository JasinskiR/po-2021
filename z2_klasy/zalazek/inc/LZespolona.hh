#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
class LZespolona {
 private:
  double re; /*! Pole repezentuje czesc rzeczywista. */
  double im; /*! Pole repezentuje czesc urojona. */
 public:
  double modul() const;
  LZespolona sprzezenie() const;
  LZespolona operator+(const LZespolona& Skl2) const;
  LZespolona operator-(const LZespolona& Skl2) const;
  LZespolona operator*(const LZespolona& Skl2) const;
  LZespolona operator/(const LZespolona& Skl2) const;
  LZespolona operator/(const double& dzielnik) const;
  bool operator==(const LZespolona& Skl2) const;
  bool operator!=(const LZespolona& Skl2) const;
  double get_re() const { return re; };
  double get_im() const { return im; };
  void set_re(double _re) { re = _re; };
  void set_im(double _im) { im = _im; };
  LZespolona(double _re, double _im) : re(_re), im(_im){};
  LZespolona() : re(0.0), im(0.0){};
};

std::ostream& operator<<(std::ostream& strm, const LZespolona& L1);
std::istream& operator>>(std::istream& strm, LZespolona& L1);

#endif
