#include "canalTexto.hpp"

CanalTexto::CanalTexto(string _nome) : Canal(_nome){

}
CanalTexto::~CanalTexto(){

}

vector<Mensagem> CanalTexto::getMensagens(){return this->mensagens;}

void CanalTexto::setMensagens(vector<Mensagem> _mensagens){if(!_mensagens.empty()) this->mensagens = _mensagens;}

void CanalTexto::enviarMensagem(string _mensagem){

}

string CanalTexto::imprimirMensagem(){
    string nome;

    return nome;
}