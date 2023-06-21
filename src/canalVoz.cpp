#include "canalVoz.hpp"

CanalVoz::CanalVoz(){

}
CanalVoz::CanalVoz(Mensagem _ultimaMensagem){
    this->ultimaMensagem = _ultimaMensagem;
}
CanalVoz::~CanalVoz(){
    delete &ultimaMensagem;
}

Mensagem CanalVoz::getUltimaMensagem(){return this->ultimaMensagem;}

void CanalVoz::setUltimaMensagem(Mensagem _ultimaMensagem){this->ultimaMensagem = _ultimaMensagem;}