
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


struct Latter {
    typedef std::pair<int, int> const& param_type;
    bool operator()(param_type lhs, param_type rhs) const {
        return std::tie(lhs.second, lhs.first) < std::tie(rhs.second, rhs.first);
    };
};

namespace std{
    int CercaSquadra(const vector<pair<string,unsigned>>& v, string sq){ return 0; };

    void AggiornaSquadra(vector<pair<string,unsigned>>& v, string sq, unsigned punteggio){
        int index = CercaSquadra(v, sq);
        if(index >= 0){ v[index].second += punteggio;}
        else{ v.push_back(make_pair(sq, punteggio));}
    }

    int test(){
        vector<pair<string,unsigned>> vec(20);
        string squadra1, squadra2;
        unsigned punti1, punti2;
        char ch;
        int index;
        // apro il file
        // formato
        // Bologna - Roma 2 2
        ifstream is("squadra.txt");
        if(!is) throw runtime_error("Failed to open file");
        while( is >> squadra1 >> ch >> squadra2 >> punti1 >> punti2){
            if(punti1 > punti2){
                AggiornaSquadra(vec, squadra1, 3);
                AggiornaSquadra(vec, squadra2, 0);
            }
            else if(punti1 == punti2){
                AggiornaSquadra(vec, squadra1, 1);
                AggiornaSquadra(vec, squadra2, 1);
            } else{
                AggiornaSquadra(vec, squadra1, 0);
                AggiornaSquadra(vec, squadra2, 3);
            }
        }

        sort(vec.begin(), vec.end(), Latter{});
        return 0;
    }
}

int main(){
    std::test();
    return 0;
}





















