#ifndef CANAL_HPP
#define CANAL_HPP

#include <iostream>
#include <string>

using namespace std;

/** Classe de canais no sistema */
class Canal{
	private:
		string nome; /**< Var nome do canal*/

	public:
        /*virtual Canal(); /**< Construtor zerar valores*/
        Canal(string _nome); /**< Construtor*/
        virtual ~Canal(); /**< Destrutor*/

        string getNome(); /**< Método get para acessar nome do canal*/

        virtual void enviarMensagem(string _mensagem) = 0;
        virtual string imprimirMensagem() = 0;

    protected:
        void setNome (string _nome); /**< Método set para alterar valor da variável nome*/
};

#endif