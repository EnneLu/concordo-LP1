#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP

#include <iostream>
#include <string>
#include <vector>

#include "canal.hpp"

using namespace std;

class Servidor{
	private:
        int usuarioDonoId;
        string nome;
        string descricao;
        string codigoConvite; 
        vector<Canal *> canais;
        vector<int> participantesIDs;

	public:
        Servidor();
        Servidor(int _usuarioDonoId, string _nome, string _descricao, string _codigoConvite, vector<Canal *> _canais, vector<int> _participantesIDs);
        ~Servidor();

        int getUsuarioDonoId();
        string getNome();
		string getDescricao();
        string getCodigoConvite();
        vector<Canal> getCanais();
        vector<int> getParticipantesIDs();

    protected:
        void setUsuarioDonoId(int _usuarioDonoId);
        void setNome(string _nome);
		void setDescricao(string _descricao);
        void setCodigoConvite(string _codigoConvite);
        void setCanais(vector<Canal *> _canais);
        void setParticipantesIDs(vector<int> _participantesIDs);
};

#endif