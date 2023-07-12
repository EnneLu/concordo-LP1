#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include <string>

using namespace std;

/** Classe de usuário do sistema*/
class Usuario{
	private:
        int id; /**< Var id do usuário*/
        string email; /**< Var email do usuário*/
        string senha; /**< Var senha do usuário*/
        string nome; /**< Var nome do usuário*/

	public:
        Usuario(); /**< Construtor zerar valores*/
        Usuario(int _id, string _email, string _senha, string _nome); /**< Construtor*/
        ~Usuario(); /**< Destrutor*/

        int getId(); /**< Método get para acessar var id*/
		string getNome(); /**< Método get para acessar var dataHora*/
        string getEmail(); /**< Método get para acessar var senha*/
        string getSenha(); /**< Método get para acessar var nome*/

    protected:
        void setId(int _id); /**< Método set para alterar valor da var id*/
        void setEmail(string _email); /**< Método set para alterar valor da var email*/
        void setSenha(string _senha); /**< Método set para alterar valor da var senha*/
		void setNome(string _nome); /**< Método set para alterar valor da var nome*/
};

#endif