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

    while(texto != "quit"){ //Entra em loop até o usuário sair do sistema
        comandos.clear();
        getline(cin, texto);
        comandos = sistema.leitor(texto);
        if (comandos[0] == "create-user"){ //Criar Usuário
            cout << "Criando usuário " << comandos[3] << "(" << comandos[1] << ")" << endl;
            sistema.novoUsuario(comandos); 
        } 
        if (comandos[0] == "login"){ //Usuário faz login
            sistema.login(comandos);
            if(sistema.getUsuarioLogado().getId() != 0){ //Funções permitidas para usuários logados
                while(comandos[0] != "disconnect"){ //Entra em loop até o usuário disconectar
                    comandos.clear();
                    getline(cin, texto);
                    comandos = sistema.leitor(texto);   
                    if (comandos[0] == "create-server"){ //Cria servidor
                        sistema.novoServidor(comandos);   
                    }
                    if (comandos[0] == "set-server-desc"){ //Muda descrição do servidor
                        sistema.mudarDescricao(comandos);   
                    }
                    if (comandos[0] == "set-server-invite-code"){ //Muda código de convite do servidor
                        sistema.mudarCodigoConvite(comandos);
                    }
                    if (comandos[0] == "list-servers"){ //Lista servidores
                        cout << sistema.listServidores() << endl;   
                    }
                    if (comandos[0] == "remove-server"){ //Remove servidor
                        sistema.removeServidor(comandos);   
                    }
                    if (comandos[0] == "enter-server"){ //Entra no servidor
                        sistema.joinServidor(comandos);
                        if(sistema.getServidorAtivo().getUsuarioDonoId() != 0){//Funções permitidas para usuários dentro do servidor
                            while(comandos[0] != "leave-server"){ //Entra em loop até o usuário sair do servidor
                                comandos.clear();
                                getline(cin, texto);
                                comandos = sistema.leitor(texto);
                                if (comandos[0] == "list-participants"){ //Lista participantes do servidor ativo
                                    sistema.listParticipantes();  
                                }
                                if (comandos[0] == "create-channel"){ //Cria novo canal no servidor ativo
                                    sistema.criarCanal(comandos);   
                                }
                                if (comandos[0] == "list-channels"){ //Lista canais do servidor ativo
                                    cout << sistema.listCanais() << endl;   
                                }
                                if (comandos[0] == "enter-channel"){ //Entra no canal
                                    sistema.entrarCanal(comandos); 
                                    if(sistema.getNomeCanalAtivo() != " "){ //*Funções permitidas para usuários dentro de canais
                                        while(comandos[0] != "leave-channel"){ //Entra em loop até o usuário sair do canal
                                            comandos.clear();
                                            getline(cin, texto);
                                            comandos = sistema.leitor(texto);
                                            if (comandos[0] == "send-message"){ //Enviar mensagem no canal ativo
                                                sistema.enviarMensagem(comandos);   
                                            }
                                            if (comandos[0] == "list-messages"){ //Lista mensagens do canal ativo
                                                cout << sistema.listMensagens();   
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