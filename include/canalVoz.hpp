#ifndef CANALVOZ_HPP
#define CANALVOZ_HPP

#include <iostream>
#include <vector>

#include "canal.hpp"
#include "mensagem.hpp"

using namespace std;

/** Classe de canais de voz que herda de canais*/
class CanalVoz : public Canal{
	private:
                Mensagem ultimaMensagem; /**< Var vetor de mensagens de texto*/

	public:
                CanalVoz(string _nome); /**< Construtor*/
                ~CanalVoz(); /**< Destrutor*/
        
        Mensagem getUltimaMensagem(); /**< Método get para acessar a última mensagem*/
        void enviarMensagem(Mensagem _mensagem); /**< Implementação da função virtual para enviar mensagem*/
        string buscarUsuarioId(vector<Usuario> _usuarios, int _id); /**< Implementação da função virtual onde cada classe imprime mensagem*/
        string imprimirMensagem(vector<Usuario> _usuarios); /**< Implementação da função virtual para imprimir mensagem*/
        vector<Mensagem> getMensagem(); /**< Implementação da função virtual onde a classe retorna sua variável mensagem*/
        string tipoClasse(); /**< Implementação da função virtual onde cada classe informa seu tipo da Classe*/

        protected:
                void setUltimaMensagem(Mensagem _ultimaMensagem); /**< Método set para alterar valor da var última mensagem*/
};

#endif