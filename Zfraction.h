#ifndef ZFRACTION_H
#define ZFRACTION_H
#include <iostream>
#include <cmath>
int PGCD(int num, int den);

class Zfraction
{
    private:
    int m_num;
    int m_den;

    public:
    Zfraction(const int& num = 0, const int& den = 1);

    int getNum() const { return m_num; }

    int getDen() const { return m_den; }

    double toDouble() const;

    void simplifie();

    void affiche(std::ostream& flux) const;

    bool estEgal(const Zfraction& z) const;

    bool estInferieur(const Zfraction& z) const;

    Zfraction& operator+=(const Zfraction& z);

    Zfraction& operator*=(const Zfraction& z);

    Zfraction& operator-=(const Zfraction& z);

    Zfraction& operator/=(const Zfraction& z);
};

Zfraction operator+(const Zfraction& z1, const Zfraction& z2);

bool operator==(const Zfraction& z1, const Zfraction& z2);

bool operator!=(const Zfraction& z1, const Zfraction& z2);

bool operator<(const Zfraction& z1, const Zfraction& z2);

bool operator>(const Zfraction& z1, const Zfraction& z2);

bool operator<=(const Zfraction& z1, const Zfraction& z2);

bool operator>=(const Zfraction& z1, const Zfraction& z2);

std::ostream& operator<<(std::ostream& flux, const Zfraction& fraction);

Zfraction operator*(const Zfraction& z1, const Zfraction& z2);

Zfraction operator-(const Zfraction& z1, const Zfraction& z2);

Zfraction operator/(const Zfraction& z1, const Zfraction& z2);

Zfraction operator-(const Zfraction& z);

Zfraction abs(const Zfraction& z);
#endif