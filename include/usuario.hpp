#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>
#include <string>

using namespace std;

class Usuario{
	private:
        int id;
        string email;
        string senha;
        string nome;

	public:
        Usuario();
        Usuario(int _id, string _email, string _senha, string _nome);
        ~Usuario();

        int getId();
		string getNome();
        string getEmail();
        string getSenha();

    protected:
        void setId(int _id);
        void setEmail(string _email);
        void setSenha(string _senha);
		void setNome(string _nome);
};

#endif