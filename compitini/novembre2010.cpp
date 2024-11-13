


#include <iostream>
#include "../libclasse/classepila/Pila.hpp"

Pila operator!(Pila p){
    Pila q;
    bool flip = true;
    while( !(p.IsEmpty()) ){
        if(flip){
            p.Pop();
        }
        else{
            q.Push(p.Top());
            p.Pop();
        }
        flip = !flip;
    }
    return q;

}

void read_pila(std::string s, Pila& p){
    int i = 1;
    int start = 1;
    while (s[i] != ')'){
        if(s[i] == ','){
            p.Push(std::stoi(s.substr(start, i - 1)));
            i += 2;
            start = i;
        }
        else if(s[i + 1] == ')'){
            p.Push(std::stoi(s.substr(start, i)));
            i++;
        }
        else
            i++;
    }
}


int main(){
    std::string spila = "(3, 4, 12, 11, 13, 16, 22)";
    Pila p, q;
    read_pila(spila, p);
    std::cout << p << std::endl;
    q = !p;

    std::cout << p << "\n" << q << std::endl;    

    
}










