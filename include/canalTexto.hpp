#ifndef CANALTEXTO_HPP
#define CANALTEXTO_HPP

#include <iostream>
#include <vector>

#include "canal.hpp"
#include "mensagem.hpp"

using namespace std;

/** Classe de canais de texto que herda de canais*/
class CanalTexto : public Canal{
        private:
                vector<Mensagem> mensagens; /**< Var vetor de mensagens de texto*/

        public:
                CanalTexto(string _nome); /**< Construtor*/
                ~CanalTexto(); /**< Destrutor*/

        vector<Mensagem> getMensagens(); /**< Método get para acessar mensagens*/
        void enviarMensagem(Mensagem _mensagem);
        string buscarUsuarioId(vector<Usuario> _usuarios, int _id);
        string imprimirMensagem(vector<Usuario> _usuarios);
        vector<Mensagem> getMensagem();
        string tipoClasse();

        protected:
                void setMensagens (vector<Mensagem> _mensagens); /**< Método set para alterar valor das mensagens*/
};

#endif