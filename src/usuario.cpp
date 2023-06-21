#include "usuario.hpp"

Usuario::Usuario(){
    this->id = 0;
    this->nome = " ";
    this->email = " ";
    this->senha = " ";
}
Usuario::Usuario(int _id, string _nome, string _email, string _senha){
    this->id = _id;
    this->nome = _nome;
    this->email = _email;
    this->senha = _senha;
}
Usuario::~Usuario(){
	if(id != 0 && nome != " " && email != " " && senha != " "){
        delete &id;
        delete &nome;
        delete &email;
        delete &senha;        
    }
}

int Usuario::getId(){return this->id;}
string Usuario::getNome(){return this->nome;}
string Usuario::getEmail(){return this->email;}
string Usuario::getSenha(){return this->senha;}

void Usuario::setId(int _id){if(_id != 0) {this->id = _id;}}
void Usuario::setNome(string _nome){if(_nome != " ") {this->nome = _nome;}}
void Usuario::setEmail(string _email){if(_email != " ") {this->email = _email;}}
void Usuario::setSenha(string _senha){if(_senha != " ") {this->senha = _senha;}}