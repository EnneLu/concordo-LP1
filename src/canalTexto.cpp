#include "canalTexto.hpp"

CanalTexto::CanalTexto(){

}
CanalTexto::CanalTexto(vector<Mensagem> _mensagens){
    this->mensagens = _mensagens;
}
CanalTexto::~CanalTexto(){
 /*   if(!mensagens.empty()){
        delete &mensagens;
    }*/
}

vector<Mensagem> CanalTexto::getMensagens(){return this->mensagens;}

void CanalTexto::setMensagens(vector<Mensagem> _mensagens){if(!_mensagens.empty()) this->mensagens = _mensagens;}