#include <iostream>
#include <array>
#include "Dr3D_gnuplot_api.hh"
#include <cmath>

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

//PRZYKLAD LAMIACY WIELE ZALOZEN OBIEKTOWOSCI, PRZEDSTAWIONY JEDYNIE DLA ZROZUMIENIA ZAGADNIENIA

Point3D operator+ (const Point3D & P1, const Point3D & P2) {
  return Point3D(P1[0]+P2[0],P1[1]+P2[1],P1[2]+P2[2]);
}

Point3D operator* (std::array<std::array<double,3>, 3> MacierzRot3D, const Point3D & Punkt) {
  return Point3D(MacierzRot3D[0][0] * Punkt[0] + MacierzRot3D[0][1] * Punkt[1] + MacierzRot3D[0][2] * Punkt[2],
		 MacierzRot3D[1][0] * Punkt[0] + MacierzRot3D[1][1] * Punkt[1] + MacierzRot3D[1][2] * Punkt[2],
		 MacierzRot3D[2][0] * Punkt[0] + MacierzRot3D[2][1] * Punkt[1] + MacierzRot3D[2][2] * Punkt[2]);
}

std::array<std::array<double,3>, 3> operator*(const std::array<std::array<double,3>, 3> & MacierzL, const std::array<std::array<double,3>, 3> & MacierzP) {
  std::array<std::array<double,3>, 3> MacierzWyn;
  for (int i=0;i<3;++i) {
    for (int j=0;j<3;++j) {
      MacierzWyn[i][j] = 0.0;
      for (int k=0;k<3;++k) {
	MacierzWyn[i][j] += MacierzL[i][k] * MacierzP[k][j];
      }
    }
  }
  return MacierzWyn;
}

std::array<double,3> konwersja(const Point3D & arg) {
  return std::array<double,3>({arg[0],arg[1],arg[2]});
}

Point3D konwersja(const std::array<double,3> & arg) {
  return Point3D(arg[0],arg[1],arg[2]);
}


class UkladW {
public:
  std::array<double,3> srodek;
  std::array<std::array<double,3>, 3> orientacja;
  UkladW() = default;
  UkladW(std::array<double,3> sr, double kat_deg, char os) : srodek(sr) {
    double kat_rad = kat_deg * 3.14159265 / 180.0;
    double c = std::cos(kat_rad);
    double s = std::sin(kat_rad);
    for (int i=0;i<3;++i)
      for (int j=0;j<3;++j)
	orientacja[i][j] = 0.0;
    switch (os) {
    case 'X': {
      orientacja[0][0] = 1.0;
      orientacja[1][1] = c;
      orientacja[2][2] = c;
      orientacja[1][2] = -s;
      orientacja[2][1] = s;
      break;
    }
    case 'Y': {
      orientacja[1][1] = 1.0;
      orientacja[0][0] = c;
      orientacja[2][2] = c;
      orientacja[2][0] = -s;
      orientacja[0][2] = s;
      break;
    }
    case 'Z': {
      orientacja[2][2] = 1.0;
      orientacja[0][0] = c;
      orientacja[1][1] = c;
      orientacja[0][1] = -s;
      orientacja[1][0] = s;
      break;
    }
    }
  }
  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> rysownik, double skala) {
    Point3D sr = konwersja(srodek);
    Point3D X = orientacja * Point3D(skala,0,0) + sr;
    Point3D Y = orientacja * Point3D(0,skala,0) + sr;
    Point3D Z = orientacja * Point3D(0,0,skala) + sr;
    rysownik->draw_line(sr,X,"red");
    rysownik->draw_line(sr,Y,"blue");
    rysownik->draw_line(sr,Z,"green");
    rysownik->redraw();
  }
};

/*
funkcja przyjmuje 2 układy: 1 argument to układ opisany w układzie 2, 2 argument to bazowy układ opisany w swoim bazowym układzie
Przykład: Układ A0 to początek układu współrzędnych
Układ A1 jest opisany w A0 (A10)
Układ A2 jest opisany w A1 (A21)
Żeby otrzymać współrzędne i orientację A2 w A0 (A20) należy wywołać
A20 = przeliczenieUkladu(A21,A10) 
Wzór matematyczny:
Aij = Aik @ Akj 

Aij.srodek = Akj.srodek + (Akj.orientacja * Aik.srodek)
Aij.orientacja = Akj.orientacja * Aik.orientacja 

Oczywiście oprację @ można składać:
Aij = (Aik @ Akl) @ Alj
lub
A30 = przeliczenieUkladu(przeliczenieUkladu(A32,A21),A10);
*/
UkladW przeliczenieUkladu (const UkladW & uklad_przeliczany, const UkladW & stary_uklad_bazowy) {
  UkladW koncowy;
  koncowy.srodek = konwersja(stary_uklad_bazowy.orientacja * konwersja(uklad_przeliczany.srodek) + konwersja(stary_uklad_bazowy.srodek));
  koncowy.orientacja = stary_uklad_bazowy.orientacja * uklad_przeliczany.orientacja;
  return koncowy;
}

int main() {
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-50,50,-50,50,-50,50,-1)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana na zadanie
  UkladW U0({0,0,0},0,'X');
  U0.rysuj(api,25);

  cout << "Układ U0, tożsamy z układem globalnym" << endl; 
  
  wait4key();
  
  UkladW U10({25,15,15},90,'Z'); //opis układu U1 we współrzędnych U0
  U10.rysuj(api,25);
  api->draw_line(Point3D(U0.srodek[0],U0.srodek[1],U0.srodek[2]),
		 Point3D(U10.srodek[0],U10.srodek[1],U10.srodek[2])
		 ,"black");
  api->redraw();
  cout << "Układ U1, przesunięty wobec U0 o [25,15,15] i obrócony w Z o 90 stopni" << endl;
  
  wait4key();

  UkladW U21({-30,20,20},45,'X'); //opis układu U2 we współrzędnych U1
  UkladW U20 = przeliczenieUkladu(U21,U10);
  
  U20.rysuj(api,25);
  
  api->draw_line(Point3D(U10.srodek[0],U10.srodek[1],U10.srodek[2]),
		Point3D(U20.srodek[0],U20.srodek[1],U20.srodek[2])
		,"black");

  cout << "Układ U2, przesunięty wobec U1 o [-30,20,20] i obrócony w X o 45 stopni" << endl;

  api->redraw();
  
  wait4key();

  UkladW U32({0,0,-50},60,'Y'); //opis układu U2 we współrzędnych U1
  UkladW U30 = przeliczenieUkladu(przeliczenieUkladu(U32,U21),U10);
  
  U30.rysuj(api,25);
  
  api->draw_line(Point3D(U20.srodek[0],U20.srodek[1],U20.srodek[2]),
		Point3D(U30.srodek[0],U30.srodek[1],U30.srodek[2])
		,"black");

  cout << "Układ U3, przesunięty wobec U2 o [0,0,-50] i obrócony w Y o 45 stopni" << endl;

  api->redraw();
  
  wait4key();
}
