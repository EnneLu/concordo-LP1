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
        comandos = sistema.leitor(texto);
        if (comandos[0] == "create-user"){ //*Criar Usuário
            cout << "Criando usuário " << comandos[3] << "(" << comandos[1] << ")" << endl;
            sistema.novoUsuario(comandos); 
        } 
        if (comandos[0] == "login"){ //*Usuário faz login
            sistema.login(comandos);
            if(sistema.getUsuarioLogado().getId() != 0){ //Funções permitidas para usuários logados
                while(comandos[0] != "disconnect"){
                    comandos.clear();
                    getline(cin, texto);
                    comandos = sistema.leitor(texto);   
                    if (comandos[0] == "create-server"){
                        sistema.novoServidor(comandos);   
                    }
                    if (comandos[0] == "set-server-desc"){
                        sistema.mudarDescricao(comandos);   
                    }
                    if (comandos[0] == "set-server-invite-code"){
                        sistema.mudarCodigoConvite(comandos);
                    }
                    if (comandos[0] == "list-servers"){
                        cout << sistema.listServidores() << endl;   
                    }
                    if (comandos[0] == "remove-server"){
                        sistema.removeServidor(comandos);   
                    }
                    if (comandos[0] == "enter-server"){ 
                        sistema.joinServidor(comandos);
                        if(sistema.getServidorAtivo().getUsuarioDonoId() != 0){//*Funções permitidas para usuários dentro do servidor
                            while(comandos[0] != "leave-server"){
                                comandos.clear();
                                getline(cin, texto);
                                comandos = sistema.leitor(texto);
                                if (comandos[0] == "list-participants"){
                                    sistema.listParticipantes();  
                                }
                                if (comandos[0] == "create-channel"){
                                    sistema.criarCanal(comandos);   
                                }
                                if (comandos[0] == "list-channels"){
                                    cout << sistema.listCanais() << endl;;   
                                }
                                if (comandos[0] == "enter-channel"){
                                    sistema.entrarCanal(comandos); 
                                    if(sistema.getNomeCanalAtivo() != " "){ //*Funções permitidas para usuários dentro de canais
                                        while(comandos[0] != "leave-channel"){
                                            comandos.clear();
                                            getline(cin, texto);
                                            comandos = sistema.leitor(texto);
                                            if (comandos[0] == "send-message"){
                                                sistema.enviarMensagem(comandos);   
                                            }
                                            if (comandos[0] == "list-messages"){
                                                sistema.listMensagens();   
                                            }
                                        }
                                        sistema.sairCanal(comandos);
                                    }
                                }
                            }
                            sistema.leaveServidor();
                        }   
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