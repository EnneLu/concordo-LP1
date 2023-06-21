#include "mensagem.hpp"

Mensagem::Mensagem(){
    this->dataHora = " ";
    this->enviadaPor = 0;
    this->conteudo = " ";
}
Mensagem::Mensagem(string _dataHora, int _enviadaPor, string _conteudo){
    this->dataHora = _dataHora;
    this->enviadaPor = _enviadaPor;
    this->conteudo = _conteudo;
}
Mensagem::~Mensagem(){
    if (dataHora != " " && enviadaPor !=  0 && conteudo !=  " "){
        delete &dataHora;
        delete &enviadaPor;
        delete &conteudo;
    }   
}

string Mensagem::getDataHora(){return this->dataHora;}
int Mensagem::getEnviadaPor(){return this->enviadaPor;}
string Mensagem::getConteudo(){return this->conteudo;}

void Mensagem::setDataHora(string _dataHora){if(_dataHora != " ") {this->dataHora = _dataHora;}}
void Mensagem::setEnviadaPor(int _enviadaPor){if(_enviadaPor != 0) {this->enviadaPor = _enviadaPor;}}
void Mensagem::setConteudo(string _conteudo){if(_conteudo != " ") {this->conteudo = _conteudo;}}