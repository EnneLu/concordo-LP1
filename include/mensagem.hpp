#ifndef MENSAGEM_HPP
#define MENSAGEM_HPP

#include <iostream>
#include <string>

using namespace std;

/** Classe de mensagem do sistema*/
class Mensagem{
	private:
        string dataHora; /**< Var data da mensagem*/
        int enviadaPor; /**< Id do usuário que enviou*/
        string conteudo; /**< Conteúdo da mensagem*/

	public:
        Mensagem(); /**< Construtor zerar valores*/
        Mensagem(string _dataHora, int _enviadaPor, string _conteudo); /**< Construtor*/
        ~Mensagem(); /**< Destrutor*/

        string getDataHora(); /**< Método get para acessar var dataHora*/
        int getEnviadaPor(); /**< Método get para acessar var enviadaPor*/
		string getConteudo(); /**< Método get para acessar var conteudo*/

    protected:
        void setDataHora(string _dataHora); /**< Método set para alterar valor da var dataHora*/
        void setEnviadaPor(int _enviadaPor); /**< Método set para alterar valor da var enviadaPor*/
		void setConteudo(string _conteudo); /**< Método set para alterar valor da var conteudo*/
};

#endif