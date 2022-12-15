#include <iostream>
#include <stack>


using namespace std;

bool pravilnoUparene(string izraz);

int main()
{
    string izraz;
    cin >> izraz;
        
    cout << (pravilnoUparene(izraz)? "da" : "ne") << endl;
    
    return 0;
}

bool pravilnoUparene(string izraz)
{
    /* Sve otvorene zagrade stavljamo na stek. Kada naidjemo na zatvorenu
    zagradu ispitujemo da li je zagrada na vrhu steka parnjak trenutne zagrade,
    ako jeste skidamo je sa steka, u suprotnom vracamo false. Kada prodjemo
    kroz ceo izraz potrebno je da proverimo da li je stek prazan (ukoliko nije 
    znaci da zagrade nisu dobro uparene). Npr. moze se desiti da imamo samo
    jednu otvorenu zagradu. Kada bismo prosli kroz ostatak izraza ne bismo naisli
    na gresku, ali cinjenica da stek nije prazan nam daje tacno resenje. */
    stack<char> zagrade;

    for (auto c : izraz)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            zagrade.push(c);
        }
        else if (c == ')')
        {
            if (zagrade.empty() ||  zagrade.top() != '(')
            {
                return false;
            }
            zagrade.pop();
        }
        else if (c == '}')
        {
            if (zagrade.empty() ||  zagrade.top() != '{')
            {
                return false;
            }
            zagrade.pop();
        }
        else if (c == ']')
        {
            if (zagrade.empty() ||  zagrade.top() != '[')
            {
                return false;
            }
            zagrade.pop();
        }
    }

    return zagrade.empty();
}