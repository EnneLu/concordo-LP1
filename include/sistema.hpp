#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <iostream>
#include <vector>

#include "usuario.hpp"
#include "servidor.hpp"
#include "canal.hpp"

using namespace std;

class Sistema{
	private:
		vector<Usuario> usuarios;
        vector<Servidor> servidores;
        Usuario usuarioLogado;
        Servidor servidorAtivo;
        Canal canalAtivo;

	public:
        Sistema();
        Sistema(vector<Usuario> usuarios, vector<Servidor> servidores, Usuario usuarioLogado, Servidor servidorAtivo, Canal canalAtivo);
        ~Sistema();

		vector<Usuario> getUsuarios();
        vector<Servidor> getServidores();
        Usuario getUsuarioLogado();
        Servidor getServidorAtivo();
        Canal getCanalAtivo();

        void buscarID(string _nome, string _senha); //buscar ID
        void buscarServidor(string _nome);
        void login(int _id); //atualizar usuarioLogado para o ID do usuário
        void disconnect(int _usuarioLogado);
        void listServidores();
        void removeServidor();


    protected:
		void setUsuarios(vector<Usuario> usuarios);
        void setServidores(vector<Servidor> servidores);
        void setUsuarioLogado(Usuario usuarioLogado);
        void setServidorAtivo(Servidor servidorAtivo);
        void setCanalAtivo(Canal canalAtivo);
};

#endif