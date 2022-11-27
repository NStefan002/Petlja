#include <iostream>
#define SQR(A) ((A)*(A))
/* 
         1
      2  3  4
   5  6  7  8  9
10 11 12 13 14 15 16
        ...
*/

using namespace std;

unsigned long long zbir_elemenata_reda(unsigned long long redni_br_reda);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    unsigned long long n;
    cin >> n;    
    unsigned long long k;
    for (unsigned long long i = 0; i < n; i++)
    {
        cin >> k;
        cout << zbir_elemenata_reda(k) << '\n';        
    }
    
    return 0;
}


unsigned long long zbir_elemenata_reda(unsigned long long redni_br_reda)
{
    // jednostavnom analizom trougla mozemo zakljuciti da je prvi element reda jednak 2k-1 gde je k redni br. reda
    unsigned long long br_el_reda = 2*redni_br_reda - 1;

    // prvi_el_reda se dobija po formuli: 1 + zbir (redni_br_reda-1) broja neparnih brojeva pocev od 1
    // tj prvi_el_reda = 1 + (1 + 3 + ...)
    // racuna se po formuli za zbir prvih n elemenata aritmetickog niza,
    // gde je n = redni_br_reda-1 a d = 2 (jer uzimamo samo neparne brojeve)
    // prvi_el_reda = 1 + [(n/2) * (2*a_1 + (n-1)*d)]
    //              = 1 + [((redni_br_reda-1)/2) * (2*1 + (redni_br_reda-1 - 1)*2)]
    //              = 1 + [((redni_br_reda-1)/2) * 2*(redni_br_reda-1)]
    //              = 1 + (redni_br_reda-1)*(redni_br_reda-1)
    //              = 1 + (redni_br_reda - 1)^2
    unsigned long long prvi_el_reda = 1 + SQR(redni_br_reda-1);

    // zbir elemenata trenutnog reda je razlika ukupnog zbira svih dosadasnjih elemenata i 
    // zbira svih elemenata koji prethodne trenutnom redu sto je:
    // n*(n+1)/2 - (m)*(m+1)/2, gde je n poslednji element trenutnog reda, a m poslednji element prethodnog reda
    // m mozemo izraziti kao prvi element trenutnog niza umanjen za 1
    // npr. za 3. red je prvi element 5, a poslednji element reda je 9
    // rezultat 1 + 2 + ... + 9 - (1 + 2 + 3 + 4) odnosno 9*(9+1)/2 - 4*(4+1)/2 = 45 - 10 = 35 
    unsigned long long poslednji_el_reda = prvi_el_reda + br_el_reda - 1;
    unsigned long long zbir = poslednji_el_reda * (poslednji_el_reda + 1) / 2 - (prvi_el_reda - 1) * (prvi_el_reda) / 2;

    return zbir;
}