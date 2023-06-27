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
        Sistema(vector<Usuario> _usuarios, vector<Servidor> _servidores, Usuario _usuarioLogado, Servidor _servidorAtivo, Canal _canalAtivo);
        //~Sistema();

		vector<Usuario> getUsuarios();
        vector<Servidor> getServidores();
        Usuario getUsuarioLogado();
        Servidor getServidorAtivo();
        Canal getCanalAtivo();

        void leitor(string &_texto, vector<string>&_comandos); //Função responsável por separar a string de entrada

        //**FUNÇÕES DE USUÁRIO**//
        bool buscarEmail(string _email); //busca na lista se já existe algum usuário com esse email
        void novoUsuario(vector<string> _comandos); //buscar se email ja existe, se não cria novo
        string listUsuarios(); //Listar usuários cadastrados

        //**FUNÇÕES DE LOGIN**//
        bool buscarUsuario(string _email, string _senha); //buscar ID usuário
        void login(vector<string> _comandos); //busca ID e atualizar usuarioLogado para o ID do usuário
        void disconnect(); //Desconectar usuário do sistema

        //**FUNÇÕES DE SERVIDOR**//
        bool buscarNomeServidor(string _nome); //buscar nome do servidor
        void novoServidor(vector<string> _comandos); //buscar nome, caso não exista cadastrar novo servidor
        void mudarDescricao(vector<string> _comandos); //Mudar descrição se ele for seu
        void mudarCodigoConvite(vector<string> _comandos); //Mudar código de convite
        string listServidores(); //Listar servidores cadastrados
        void removeServidor(vector<string> _comandos); //Remover servidor

        void joinServidor(vector<string> _comandos); //Entrar no servidor
        void leaveServidor(); //Sair do servidor
        string buscarUsuarioId(int _id);
        void listParticipantes(); //Listar participantes do servidor

    protected:
		void setUsuarios(vector<Usuario> _usuarios);
        void setServidores(vector<Servidor> _servidores);
        void setUsuarioLogado(Usuario _usuarioLogado);
        void setServidorAtivo(Servidor _servidorAtivo);
        void setCanalAtivo(Canal _canalAtivo);
};

#endif