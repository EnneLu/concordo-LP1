#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP

#include <iostream>
#include <string>
#include <vector>

#include "canal.hpp"
#include "usuario.hpp"

using namespace std;

/** Classe de usuário do sistema*/
class Servidor{
	private:
        int usuarioDonoId; /**< Var usuarioDonoId do servidor*/
        string nome; /**< Var nome do servidor*/
        string descricao; /**< Var descricao do servidor*/
        string codigoConvite; /**< Var codigo do convite*/
        vector<Canal *> canais; /**< Var vetor de canais do servidor*/
        vector<int> participantesIDs; /**< Var vetor com id dos participantes do servidor*/

	public:
        Servidor(); /**< Construtor zerar valores*/
        Servidor(int _usuarioDonoId, string _nome, string _descricao, string _codigoConvite, vector<Canal *> _canais, vector<int> _participantesIDs); /**< Construtor*/
        ~Servidor(); /**< Destrutor*/

        int getUsuarioDonoId(); /**< Método get para acessar var usuarioDonoId*/
        string getNome(); /**< Método get para acessar var nome*/
		string getDescricao(); /**< Método get para acessar var descricao*/
        string getCodigoConvite(); /**< Método get para acessar var codigoConvite*/
        vector<Canal *> getCanais(); /**< Método get para acessar var canais*/
        vector<int> getParticipantesIDs(); /**< Método get para acessar var participantesIDs*/

        void mudarDescricao(Servidor *_servidor, string _newDescricao); /**< Função responsável por mudar a descrição do servidor*/
        void mudarCodigoConvite(Servidor *_servidor, string _newCodigo); /**< Função responsável por mudar o código de convite do servidor*/
        void addParticipante(int _id);
        void addCanal(Canal *_newCanal);

    protected:
        void setUsuarioDonoId(int _usuarioDonoId); /**< Método set para alterar valor da var usuarioDonoId*/
        void setNome(string _nome); /**< Método set para alterar valor da var nome*/
		void setDescricao(string _descricao); /**< Método set para alterar valor da var descricao*/
        void setCodigoConvite(string _codigoConvite); /**< Método set para alterar valor da var codigoConvite*/
        void setCanais(vector<Canal *> _canais); /**< Método set para alterar valor da var canais*/
        void setParticipantesIDs(vector<int> _participantesIDs); /**< Método set para alterar valor da var participantesIDs*/
};

#endif