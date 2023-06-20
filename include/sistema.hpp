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
        //Sistema(string _titulo, string _nomeArtista);
        ~Sistema();

        //string getTitulo();
		//string getNomeArtista();

    protected:
        //void setTitulo ( string _titulo );
        //void setNomeArtista ( string _nomeArtista );
};

#endif