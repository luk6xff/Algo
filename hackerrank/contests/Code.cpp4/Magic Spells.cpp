#include <iostream>
#include <vector>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) 
{   
    if(spell==nullptr)
        return;   
    if(Fireball* d = dynamic_cast<Fireball*>(spell))
    {
        d->revealFirepower();
    }
    else if(Frostbite* d = dynamic_cast<Frostbite*>(spell))
    {
        d->revealFrostpower();
    }
    else if(Thunderstorm* d = dynamic_cast<Thunderstorm*>(spell))
    {
        d->revealThunderpower();
    }
    else if(Waterbolt* d = dynamic_cast<Waterbolt*>(spell))
    {
        d->revealWaterpower();
    }
    else
    {
        string x =SpellJournal::read();
        string y= spell->revealScrollName();
        int m= SpellJournal::read().size();
        int n= spell->revealScrollName().size();
        int LCS[m+1][n+1];
        for (int i=0; i<=m; i++)
        {
            for (int j=0; j<=n; j++)
            {
                if (i == 0 || j == 0)
                    LCS[i][j] = 0;  
                else if (x[i-1] == y[j-1])
                    LCS[i][j] = LCS[i-1][j-1] + 1;
  
                else
                    LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
        cout<<LCS[m][n]<<'\n';
    }
    delete spell;
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}



/*
Sample Input

3
fire 5
AquaVitae 999 AruTaVae
frost 7
Sample Output

Fireball: 5
6
Frostbite: 7
*/