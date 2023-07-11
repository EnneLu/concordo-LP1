#include "canalVoz.hpp"
#include <sstream>
#include <fstream>

CanalVoz::CanalVoz(string _nome) : Canal(_nome){
    
}
CanalVoz::~CanalVoz(){
}

Mensagem CanalVoz::getUltimaMensagem(){return this->ultimaMensagem;}

void CanalVoz::setUltimaMensagem(Mensagem _ultimaMensagem){this->ultimaMensagem = _ultimaMensagem;}

void CanalVoz::enviarMensagem(Mensagem _mensagem){
    this->ultimaMensagem = _mensagem;
}

/*Esta função busca o nome do usuário de acordo com seu id e retorna o nome*/
string CanalVoz::buscarUsuarioId(vector<Usuario> _usuarios, int _id){
    string nome;
    for(int i = 0; i < _usuarios.size(); i++){
    if(_usuarios[i].getId() == _id)
        nome = _usuarios[i].getNome();
    }
    return nome;
}

string CanalVoz::imprimirMensagem(vector<Usuario> _usuarios){
    ostringstream mensagem;
    string nome;
    // Buscar nome do usuário de acordo com o id
    if(ultimaMensagem.getEnviadaPor() != 0){
        nome = buscarUsuarioId(_usuarios, ultimaMensagem.getEnviadaPor());
        mensagem << nome << ultimaMensagem.getDataHora() << ultimaMensagem.getConteudo() << endl;
    } else{
        mensagem << "Sem mensagens para exibir" << endl;
        return mensagem.str();
    }
           
    return mensagem.str();
}

vector<Mensagem> CanalVoz::getMensagem(){
    vector<Mensagem> mensagem;
    mensagem.push_back(ultimaMensagem);
    return mensagem;
}

string CanalVoz::tipoClasse(){return "voz";}