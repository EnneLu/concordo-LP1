#include "canalVoz.hpp"

CanalVoz::CanalVoz(string _nome) : Canal(_nome){
    
}
CanalVoz::~CanalVoz(){
}

Mensagem CanalVoz::getUltimaMensagem(){return this->ultimaMensagem;}

void CanalVoz::setUltimaMensagem(Mensagem _ultimaMensagem){this->ultimaMensagem = _ultimaMensagem;}

void CanalVoz::enviarMensagem(string _mensagem){

}

string CanalVoz::imprimirMensagem(){
    string nome;

    return nome;
}