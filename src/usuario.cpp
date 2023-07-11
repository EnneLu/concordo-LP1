#include "usuario.hpp"

Usuario::Usuario(){
    this->id = 0;
    this->email = " ";
    this->senha = " ";
    this->nome = " ";
}
Usuario::Usuario(int _id, string _email, string _senha, string _nome){
    this->id = _id;
    this->email = _email;
    this->senha = _senha;
    this->nome = _nome;
}
Usuario::~Usuario(){

}

int Usuario::getId(){return this->id;}
string Usuario::getEmail(){return this->email;}
string Usuario::getSenha(){return this->senha;}
string Usuario::getNome(){return this->nome;}

void Usuario::setId(int _id){if(_id != 0) {this->id = _id;}}
void Usuario::setEmail(string _email){if(_email != " ") {this->email = _email;}}
void Usuario::setSenha(string _senha){if(_senha != " ") {this->senha = _senha;}}
void Usuario::setNome(string _nome){if(_nome != " ") {this->nome = _nome;}}