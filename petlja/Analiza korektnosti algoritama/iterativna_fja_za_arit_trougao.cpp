long long zbirRedaTrougla(long long k)
{
    // odredjujemo prvi broj u k-tom redu trougla
    long long pocetak = 1;
    long long brojElemenata = 1;
    for (int i = 1; i < k; i++)
    {
        pocetak += brojElemenata;
        brojElemenata += 2;
    }

    // odredjujemo zbir elemenata u k-tom redu trougla
    long long zbir = 0;
    for (long long i = pocetak; i < pocetak + brojElemenata; i++)
        zbir += i;
    return zbir;
}