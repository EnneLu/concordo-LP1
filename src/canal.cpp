#include "canal.hpp"

Canal::Canal(string _nome){
    nome = _nome;
}

Canal::~Canal(){
}

string Canal::getNome(){return this->nome;}

void Canal::setNome (string _nome){if(_nome != " ") this->nome = _nome;}