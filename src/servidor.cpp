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

/*Esta função chama a função buscarNomeServidor para verificar se existe um servidor
 com o nome informado no vector servidores, caso exista busca qual o servidor no vector de servidores
 e atualiza sua descrição verificando também se a var usuarioLogado é o dono do servidor*/
void Servidor::mudarDescricao(string _newDescricao){
    getDescricao() = _newDescricao;
    cout << "Descrição do servidor '" << getNome() << "' modificada!" << endl;
}

/*Esta função chama a função buscarNomeServidor para verificar se existe um servidor
 com o nome informado no vector servidores, caso exista busca qual o servidor no vector de servidores
 e atualiza seu código de convite verificando também se a var usuarioLogado é o dono do servidor*/
void Servidor::mudarCodigoConvite(string _newCodigo){
    if (_newCodigo ==  " "){
        getCodigoConvite() = _newCodigo;
        cout << "Código de convite do servidor '" << getNome() << "' removido!" << endl;
    } else{
        getCodigoConvite() = _newCodigo;
        cout << "Código de convite do servidor '" << getNome() << "' modificado!" << endl;
    }    
}

/*Esta função busca o nome do usuário de acordo com seu id e retorna o nome*/
string Servidor::buscarUsuarioId(int _id){
    string nome;

    return nome;
}

/*Esta função chama a função buscarUsuarioId para cada id presente no vector participantes Id
em seguida informa o nome*/
void Servidor::listParticipantes(){
    string nome;
    for(int i = 0; i < getParticipantesIDs().size(); i++){
        nome = buscarUsuarioId(getParticipantesIDs()[i]);
        cout << nome << endl;
    }
}