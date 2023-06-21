#include "canal.hpp"

Canal::Canal(){
    this->nome = " ";
}
Canal::Canal(string _nome){
    this->nome = _nome;
}
Canal::~Canal(){
    if(nome != " "){
        delete &nome;
    }
}

string Canal::getNome(){return this->nome;}

void Canal::setNome (string _nome){if(_nome != " ") this->nome = _nome;}