#ifndef __VEC_H
#define __VEC_H

#include <math.h>


typedef float scalar_t;  // skalar


// klasa CVector

class CVector
{
public:
     scalar_t x;
     scalar_t y; // sk³adowe x,y,z 

public:
     // konstruktor
     CVector(const CVector &vec) : x(vec.x), y(vec.y) {}

     // podstawienie wektora
     const CVector &operator=(const CVector &vec)
     {
          x = vec.x;
          y = vec.y;

          return *this;
     }

     // równoœæ wektorów
     const bool operator==(const CVector &vec) const
     {
          return ((x == vec.x) && (y == vec.y));
     }

     // nierównoœæ wektorów
     const bool operator!=(const CVector &vec) const
     {
          return !(*this == vec);
     }

     // dodawanie wektorów
     const CVector operator+(const CVector &vec) const
     {
          return CVector(x + vec.x, y + vec.y);
     }

     // dodawanie wektorów
     const CVector operator+() const
     {    
          return CVector(*this);
     }

     // dodawanie wektorów
     const CVector& operator+=(const CVector& vec)
     {    x += vec.x;
          y += vec.y;
          return *this;
     }

     // odejmowanie wektorów
     const CVector operator-(const CVector& vec) const
     {    
          return CVector(x - vec.x, y - vec.y);
     }
     
     // odejmowanie wektorów
     const CVector operator-() const
     {    
          return CVector(-x, -y);
     }

     // odejmowanie wektorów
     const CVector &operator-=(const CVector& vec)
     {
          x -= vec.x;
          y -= vec.y;

          return *this;
     }

     // mno¿enie wektora przez skalar
     const CVector &operator*=(const scalar_t &s)
     {
          x *= s;
          y *= s;
          
          return *this;
     }

     // dzielenie wektora przez skalar
     const CVector &operator/=(const scalar_t &s)
     {
          const float recip = 1/s; // dla efektywnoœci

          x *= recip;
          y *= recip;

          return *this;
     }

     // mno¿enie wektora przez skalar
     const CVector operator*(const scalar_t &s) const
     {
          return CVector(x*s, y*s);
     }

     // mno¿enie wektora przez skalar
     friend inline const CVector operator*(const scalar_t &s, const CVector &vec)
     {
          return vec*s;
     }


     // dzielenie wektora przez skalar
     const CVector operator/(scalar_t s) const
     {
          s = 1/s;

          return CVector(s*x, s*y);
     }

     // d³ugoœæ wektora
     const scalar_t Length() const
     {
          return (scalar_t)sqrt((double)(x*x + y*y));
     }

     // wektor jednostkowy
     const CVector UnitVector() const
     {
          return (*this) / Length();
     }

     // normalizacja wektora
     void Normalize()
     {
          (*this) /= Length();
     }

// operator modu³u (d³ugoœci) wektora
     const scalar_t operator!() const
     {
          return sqrtf(x*x + y*y);
     }

     // zmienia d³ugoœæ wektora
     const CVector operator | (const scalar_t length) const
     {
          return *this * (length / !(*this));
     }

     // zmienia d³ugoœæ wektora
     const CVector& operator |= (const float length)
     {
          return *this = *this | length;
     }

     // zwraca k¹t, który tworz¹ wektory
     const float inline Angle(const CVector& normal) const
     {
          return acosf(*this % normal);
     }

     // tworzy odbicie wektora wzglêdem powierzchni zdefiniowanej przez normaln¹
     const CVector inline Reflection(const CVector& normal) const
     {    
          const CVector vec(*this | 1);     // normalizuje wektor
          return (vec - normal * 2.0 * (vec % normal)) * !*this;
     }

};

#endif
