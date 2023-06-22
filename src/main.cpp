#include <iostream>
#include <string>
#include <vector>

#include "sistema.hpp"

using namespace std;

int main(){
    Sistema sistema;
    string texto = " ";
    vector<string> comandos;

    while(texto != "quit"){
        getline(cin, texto);
        sistema.lerTexto(&comandos, texto); //quebrar funcao
        if (comandos[1] == "create-user" && comandos.size() > 4){
            sistema.novoUsuario(&comandos);
        } else {cout << "Algo deu errado!";}
        if (comandos[1] == "login" && comandos.size() > 3){
            sistema.login(&comandos);
        } else {cout << "Algo deu errado!";}

        if(sistema.getUsuarioLogado().getId() != 0){
            
        }else {cout << "Não possui usuário logado!";}
    }
    cout << "saindo do concordo";

    return 0;
}