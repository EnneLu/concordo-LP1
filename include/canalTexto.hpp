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
        void enviarMensagem(Mensagem _mensagem); /**< Implementação da função virtual para enviar mensagem*/
        string buscarUsuarioId(vector<Usuario> _usuarios, int _id); /**< Implementação da função virtual onde cada classe imprime mensagem*/
        string imprimirMensagem(vector<Usuario> _usuarios); /**< Implementação da função virtual para imprimir mensagem*/
        vector<Mensagem> getMensagem(); /**< Implementação da função virtual onde a classe retorna sua variável mensagem*/
        string tipoClasse(); /**< Implementação da função virtual onde cada classe informa seu tipo da Classe*/

        protected:
                void setMensagens (vector<Mensagem> _mensagens); /**< Método set para alterar valor das mensagens*/
};

#endif