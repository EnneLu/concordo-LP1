#ifndef CANAL_HPP
#define CANAL_HPP

#include <iostream>
#include <string>
#include <vector>
#include "mensagem.hpp"
#include "usuario.hpp"

using namespace std;

/** Classe de canais no sistema */
class Canal{
	private:
		string nome; /**< Var nome do canal*/

	public:
        Canal(string _nome); /**< Construtor*/
        virtual ~Canal(); /**< Destrutor*/

        string getNome(); /**< Método get para acessar nome do canal*/

        virtual string tipoClasse() = 0; /**< Função virtual onde cada classe informa seu tipo da Classe*/
        virtual void enviarMensagem(Mensagem _mensagem) = 0; /**< Função virtual onde cada classe envia mensagem*/
        virtual string buscarUsuarioId(vector<Usuario> _usuarios, int _id) = 0; /**< Função auxíliar que retorna o nome do usuário de acordo com o Id*/
        virtual string imprimirMensagem(vector<Usuario> _usuarios) = 0; /**< Função virtual onde cada classe imprime mensagem*/
        virtual vector<Mensagem> getMensagem() = 0; /**< Função virtual onde é possível acessar a variável mensagem de cada classe*/

    protected:
        void setNome (string _nome); /**< Método set para alterar valor da variável nome*/
};

#endif