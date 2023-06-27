#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>

#include "sistema.hpp"

using namespace std;

int main(){
    Sistema sistema;
    string texto = " ";
    int i = 0;
    vector<string> comandos;

    while(texto != "quit"){
        comandos.clear();
        getline(cin, texto);
        sistema.leitor(texto, comandos);
        if (comandos[0] == "create-user"){
            cout << "Criando usuário " << comandos[3] << "(" << comandos[1] << ")" << endl;
            sistema.novoUsuario(comandos);   
            cout << sistema.listUsuarios() << endl;
        } 
        if (comandos[0] == "login"){
            sistema.login(comandos);
            if(sistema.getUsuarioLogado().getId() != 0){
                while(texto != "disconnect"){
                    getline(cin, texto);
                    sistema.leitor(texto, comandos);
                    if (comandos[0] == "create-server"){
                        sistema.novoServidor(comandos);   
                        cout << sistema.listServidores() << endl;
                    }
                    if (comandos[0] == "set-server-desc"){
                        sistema.mudarCodigoConvite(comandos);   
                    }
                    if (comandos[0] == "list-servers"){
                        sistema.listServidores();   
                    }
                    if (comandos[0] == "remove-server"){
                        sistema.removeServidor(comandos);   
                    }
                    if (comandos[0] == "enter-server"){
                        sistema.joinServidor(comandos);   
                    }
                    if (comandos[0] == "leave-server"){
                        sistema.leaveServidor();   
                    }
                    if (comandos[0] == "list-participants"){
                        sistema.listParticipantes();   
                    }
                }
                cout << "Desconectando usuário " << sistema.getUsuarioLogado().getEmail() << endl;
                sistema.disconnect();
            }
        }
    }     
    cout << "Saindo do concordo" << endl;

    return 0;
}

/*
create-user luennemafra15@gmail.com luenneGatinha123 luenne mafra 
create-user luenne.mafra.017@ufrn.edu.br lMafra luenne.mafra.017
login luennemafra15@gmail.com luenneGatinha1
login luennemafra15@gmail.com luenneGatinha123

else if(sistema.getUsuarioLogado().getId() != 0){
*/