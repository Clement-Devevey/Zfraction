#include "Zfraction.h"

using namespace std;

int PGCD(int num, int den)
{
    /* Il faut que num soit la plus grande valeur */
    num = abs(num);
    den = abs(den);

    if ( den > num && num != 0)
    {
        int *temp = 0;
        temp = new int;

        *temp = den;
        den = num;
        num = *temp;

        delete temp;
    }

    /* On calcul le reste tant qu'il n'est pas = 0, en prenant le numérateur = dénominateur et dénominateur = reste à chaque itération
    Le dernier reste avant = 0 est donc stocké dans num. */

    int reste;
    do
    {
        reste = num % den;
        num = den;
        den = reste;

    } while (reste != 0);

    return num; //contient le dernier reste non nul

}


Zfraction::Zfraction(const int& num, const int& den) : m_num(num), m_den(den)
{
    simplifie();
}

double Zfraction::toDouble() const
{
    return (double)m_num / (double)m_den;
}

void Zfraction::simplifie()
{
    if (m_den<0)
    {
        m_den = -m_den;
        m_num = -m_num;
    }
    int pgcd = PGCD(m_num, m_den);
    m_num /= pgcd;
    m_den /= pgcd;
}

void Zfraction::affiche(ostream& flux) const
{
    cout << m_num << "/" << m_den;
}

bool Zfraction::estEgal(const Zfraction& z) const
{
    return m_den == z.m_den && m_num == z.m_num;
}

bool Zfraction::estInferieur(const Zfraction& z) const
{
    return m_num*z.m_den < z.m_num*m_den; //On met sur le même dénominateur et on compare les numérateurs.
}

Zfraction& Zfraction::operator+=(const Zfraction& z)
{
    if (m_den != z.m_den)
    {
        m_num = m_num * z.m_den + z.m_num * m_den;
        m_den *= z.m_den;
    }

    else
    {
        m_num += z.m_num;
    }

    simplifie();
    return *this;
}

Zfraction& Zfraction::operator*=(const Zfraction& z)
{
    m_num *= z.m_num;
    m_den *= z.m_den;
    simplifie();
    return *this;
}  


Zfraction& Zfraction::operator-=(const Zfraction& z)
{
    // a/b - c/d se résout en mettant tout sur le même dénominateur (b*d en général) -> (a*d - c*b) / b*d
    m_num *= z.m_den; 
    m_num = m_num - (z.m_num * m_den);
    m_den *= z.m_den;
    simplifie();

    return *this;
}

Zfraction& Zfraction::operator/=(const Zfraction& z)
{
    //a/b / c/d <=> a*d / b*c
    m_num *= z.m_den;
    m_den *= z.m_num;
    simplifie();
    return *this;
}

Zfraction operator+(const Zfraction& z1, const Zfraction& z2)
{
    Zfraction temp(z1);
    temp += z2;
    return temp;   
}

bool operator==(const Zfraction& z1, const Zfraction& z2)
{
    return z1.estEgal(z2);
}
    
bool operator!=(const Zfraction& z1, const Zfraction& z2)
{
    return !(z1.estEgal(z2));
}

bool operator<(const Zfraction& z1, const Zfraction& z2)
{
    return z1.estInferieur(z2);
}

bool operator>(const Zfraction& z1, const Zfraction& z2)
{
    return !(z1.estInferieur(z2) && z1.estEgal(z2));
}

bool operator<=(const Zfraction& z1, const Zfraction& z2)
{
    return z1.estInferieur(z2) && z1.estEgal(z2);
}

bool operator>=(const Zfraction& z1, const Zfraction& z2)
{
    return !(z1.estInferieur(z2));
}

ostream& operator<<(ostream& flux, Zfraction const& z)
{
    z.affiche(flux);
    return flux;
}

Zfraction operator*(const Zfraction& z1, const Zfraction& z2)
{
    Zfraction temp(z1);
    temp *= z2;
    return temp;
}

Zfraction operator-(const Zfraction& z1, const Zfraction& z2)
{
    Zfraction temp(z1);
    temp -= z2;
    return temp;
}

Zfraction operator/(const Zfraction& z1, const Zfraction& z2)
{
    Zfraction temp(z1);
    temp/=z2;
    return temp;
}

Zfraction operator-(const Zfraction& z)
{
    Zfraction temp;
    temp -= z;
    return temp;
}

Zfraction abs(const Zfraction& z)
{
    if (z.getNum() <0)
    {
        return -z;
    }
    return z;
}