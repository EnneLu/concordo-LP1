#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include <string>

using namespace std;

class Usuario{
	private:
        int id;
        string nome;
        string email;
        string senha;

	public:
        Usuario();
        Usuario(int _id, string _nome, string _email, string _senha);
        ~Usuario();

        int getId();
		string getNome();
        string getEmail();
        string getSenha();

    protected:
        void setId(int _id);
		void setNome(string _nome);
        void setEmail(string _email);
        void setSenha(string _senha);
};

#endif