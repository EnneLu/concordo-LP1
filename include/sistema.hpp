#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <iostream>
#include <vector>

#include "usuario.hpp"
#include "servidor.hpp"
#include "canal.hpp"
#include "canalTexto.hpp"
#include "canalVoz.hpp"

using namespace std;

/** Classe sistema que possui todas as funções necessárias para execução do programa*/
class Sistema{
	private: 
		vector<Usuario> usuarios; /**< Var vetor de usuários cadastrados no sistema*/
        vector<Servidor> servidores; /**< Var vetor de servidores cadastrados no sistema*/
        Usuario usuarioLogado; /**< Var objeto que indica qual usuário está logado*/
        Servidor servidorAtivo; /**< Var objeto que indica qual servidor está ativo*/
        string nomeCanalAtivo; /**< String nome que indica qual canal está ativo. Obs: Decidi mudar esta var pois dava erro ao utilizar a classe Canal como abstrata*/

	public:
        Sistema(); /**< Construtor zerar valores*/
        Sistema(vector<Usuario> _usuarios, vector<Servidor> _servidores, Usuario _usuarioLogado, Servidor _servidorAtivo, string _nomeCanalAtivo); /**< Construtor*/
        //~Sistema(); /**< Destrutor*/

		vector<Usuario> getUsuarios(); /**< Método get para acessar var usuarios*/
        vector<Servidor> getServidores(); /**< Método get para acessar var servidores*/
        Usuario getUsuarioLogado(); /**< Método get para acessar var usuarioLogado*/
        Servidor getServidorAtivo(); /**< Método get para acessar var servidorAtivo*/
        string getNomeCanalAtivo(); /**< Método get para acessar var canalAtivo*/

        ///**FUNÇÕES TRATAMENTO TEXTO**//
        vector<string> leitor(string &_texto); /**< Função responsável por separar string recebida no getline em um vector*/

        //**FUNÇÕES DE USUÁRIO**//
        bool buscarEmail(string _email); /**< Função responsável por busca na lista de usuários se já existe algum usuário com esse email*/
        void novoUsuario(vector<string> _comandos); /**< Função responsável criar novo usuário, primeiro o sistema busca se já existe email cadastrado, caso não, cadastra novo usuário*/
        string listUsuarios(); /**< Função responsável por listar usuários presentes no sistema. Está função não está presente no main, serve como auxílio*/

        //**FUNÇÕES DE LOGIN**//
        bool buscarUsuario(string _email, string _senha); /**< Função responsável por busca se existe id do usuário de acordo com seu email e senha, caso sim, atualizar a var usuarioLogado*/
        void login(vector<string> _comandos); /**< Função responsável por realizar o login do usuário no servidor de acordo com o resultado da função buscarUsuario. Esta função serve apenas como verificador se houve sucesso no login*/
        void disconnect(); /**< Função responsável por desconectar o usuário do sistema*/

        //**FUNÇÕES DE SERVIDOR**//
        bool buscarNomeServidor(string _nome); /**< Função responsável por buscar se existe servidor com esse nome*/
        void novoServidor(vector<string> _comandos); /**< Função responsável por buscar se existe servidor com esse nome, caso não exista realiza o cadastro*/
        void mudarDescricao(vector<string> _comandos); /**< Função responsável por mudar a descrição do servidor*/
        void mudarCodigoConvite(vector<string> _comandos); /**< Função responsável por mudar o código de convite do servidor*/
        string listServidores(); /**< Listar servidores cadastrados*/
        void removeServidor(vector<string> _comandos); /**< Remover servidor da lista de servidores*/

        //**FUNÇÕES DENTRO DO SERVIDOR**//
        void joinServidor(vector<string> _comandos); /**< Entrar no servidor, verifica se existe servidor com o nome informado e verifica o código do servidor */
        void leaveServidor(); /**< Desconecta do servidor e muda a variável servidorAtivo para um objeto vazio*/
        void listParticipantes(); /**< Busca o nome do usuário de acordo com o id presente na var IdParticipantes da classe Servidor e realiza a listagem*/

        //**FUNÇÕES CANAIS**//
        bool buscarCanal(string _nome);
        void criarCanal(vector<string> _comandos);
        void entrarCanal(vector<string> _comandos);
        void sairCanal(vector<string> _comandos);
        string listCanais();
        void enviarMensagem(vector<string> _comandos);
        string listMensagens();

    protected:
		void setUsuarios(vector<Usuario> _usuarios); /**< Método set para alterar valor da var usuarios*/
        void setServidores(vector<Servidor> _servidores); /**< Método set para alterar valor da var servidores*/
        void setUsuarioLogado(Usuario _usuarioLogado); /**< Método set para alterar valor da var usuarioLogado*/
        void setServidorAtivo(Servidor _servidorAtivo); /**< Método set para alterar valor da var servidorAtivo*/
        void setNomeCanalAtivo(string _nomeCanalAtivo); /**< Método set para alterar valor da var canalAtivo*/
};

#endif