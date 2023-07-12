#include "canalTexto.hpp"
#include <sstream>
#include <fstream>

CanalTexto::CanalTexto(string _nome) : Canal(_nome){

}
CanalTexto::~CanalTexto(){

}

vector<Mensagem> CanalTexto::getMensagens(){return this->mensagens;}

void CanalTexto::setMensagens(vector<Mensagem> _mensagens){if(!_mensagens.empty()) this->mensagens = _mensagens;}

/*Adicionar mensagem no vector*/
void CanalTexto::enviarMensagem(Mensagem _mensagem){ 
    mensagens.push_back(_mensagem);
}

/*Esta função busca o nome do usuário de acordo com seu id e retorna o nome*/
string CanalTexto::buscarUsuarioId(vector<Usuario> _usuarios, int _id){
    string nome;
    for(int i = 0; i < _usuarios.size(); i++){
    if(_usuarios[i].getId() == _id)
        nome = _usuarios[i].getNome();
    }
    return nome;
}

/*Imprimir mensagens do vector*/
string CanalTexto::imprimirMensagem(vector<Usuario> _usuarios){
    ostringstream mensagem;
    string nome;
    
    if(!mensagens.empty()){
        for(int i = 0; i < mensagens.size(); i++){
            nome = buscarUsuarioId(_usuarios, mensagens[i].getEnviadaPor()); // Buscar nome do usuário de acordo com o id
            mensagem << nome << mensagens[i].getDataHora() << mensagens[i].getConteudo() << endl; 
        }
    } else{
        mensagem << "Sem mensagens para exibir" << endl;
        return mensagem.str();
    }
           
    return mensagem.str();
}

vector<Mensagem> CanalTexto::getMensagem(){return mensagens;} /*Retorna a variável mensagens*/

string CanalTexto::tipoClasse(){return "texto";} /*Informa que a classe é canal de texto*/