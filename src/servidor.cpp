#include "servidor.hpp"

Servidor::Servidor(){
    this->usuarioDonoId = 0;
    this->nome = " ";
    this->descricao = " ";
    this->codigoConvite = " ";
}
Servidor::Servidor(int _usuarioDonoId, string _nome, string _descricao, string _codigoConvite, vector<Canal *> _canais, vector<int> _participantesIDs){
    this->usuarioDonoId = _usuarioDonoId;
    this->nome = _nome;
    this->descricao = _descricao;
    this->codigoConvite = _codigoConvite;
    this->canais = _canais;
    this->participantesIDs = _participantesIDs;
}
/*Servidor::~Servidor(){
    if (usuarioDonoId != 0 && nome !=  " " && descricao !=  " " && codigoConvite !=  " " && !canais.empty() && !participantesIDs.empty()){
        delete &usuarioDonoId;
        delete &nome;
        delete &descricao;
        delete &codigoConvite; 
        delete &canais;        
        delete &participantesIDs; 
    }   
}*/

int Servidor::getUsuarioDonoId(){return this->usuarioDonoId;}
string Servidor::getNome(){return this->nome;}
string Servidor::getDescricao(){return this->descricao;}
string Servidor::getCodigoConvite(){return this->codigoConvite;}
vector<Canal*> Servidor::getCanais(){return this->canais;}
vector<int> Servidor::getParticipantesIDs(){return this->participantesIDs;}

void Servidor::setUsuarioDonoId(int _usuarioDonoId){if(_usuarioDonoId != 0) {this->usuarioDonoId = _usuarioDonoId;}}
void Servidor::setNome(string _nome){if(_nome != " ") {this->nome = _nome;}}
void Servidor::setDescricao(string _descricao){if(_descricao != " ") {this->descricao = _descricao;}}
void Servidor::setCodigoConvite(string _codigoConvite){if(_codigoConvite != " ") {this->codigoConvite = _codigoConvite;}}
void Servidor::setCanais(vector<Canal *> _canais){if(!canais.empty()) {this->canais = _canais;}}
void Servidor::setParticipantesIDs(vector<int> _participantesIDs){if(!participantesIDs.empty()) {this->participantesIDs = _participantesIDs;}}