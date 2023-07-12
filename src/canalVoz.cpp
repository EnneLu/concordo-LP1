#include "canalVoz.hpp"
#include <sstream>
#include <fstream>

CanalVoz::CanalVoz(string _nome) : Canal(_nome){
    
}
CanalVoz::~CanalVoz(){
}

Mensagem CanalVoz::getUltimaMensagem(){return this->ultimaMensagem;}

void CanalVoz::setUltimaMensagem(Mensagem _ultimaMensagem){this->ultimaMensagem = _ultimaMensagem;}

/*Atualiza variável ultimaMensagem*/
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

/*Imprimir última mensagem*/
string CanalVoz::imprimirMensagem(vector<Usuario> _usuarios){
    ostringstream mensagem;
    string nome;
    if(ultimaMensagem.getEnviadaPor() != 0){
        nome = buscarUsuarioId(_usuarios, ultimaMensagem.getEnviadaPor()); // Buscar nome do usuário de acordo com o id
        mensagem << nome << ultimaMensagem.getDataHora() << ultimaMensagem.getConteudo() << endl;
    } else{
        mensagem << "Sem mensagens para exibir" << endl;
        return mensagem.str();
    }
           
    return mensagem.str();
}

vector<Mensagem> CanalVoz::getMensagem(){ /*Retorna a variável mensagem*/
    vector<Mensagem> mensagem; //O tipo da função virtual é vector, portanto é preciso retornar a ultima mensagem dentro do vector
    mensagem.push_back(ultimaMensagem);
    return mensagem;
}

string CanalVoz::tipoClasse(){return "voz";} /*Informa que a classe é canal de voz*/