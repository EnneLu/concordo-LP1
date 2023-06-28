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
        Canal(); /**< Construtor zerar valores*/
        Canal(string _nome); /**< Construtor*/
        ~Canal(); /**< Destrutor*/

        string getNome(); /**< Método get para acessar nome do canal*/

    protected:
        void setNome (string _nome); /**< Método set para alterar valor da variável nome*/
};

#endif