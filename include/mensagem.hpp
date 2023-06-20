#ifndef MENSAGEM_HPP
#define MENSAGEM_HPP

#include <iostream>
#include <string>

using namespace std;

class Mensagem{
	private:
        string dataHora;
        int enviadaPor;
        string conteudo;

	public:
        Mensagem();
        Mensagem(string _dataHora, int _enviadaPor, string _conteudo);
        ~Mensagem();

        string getDataHora();
        int getEnviadaPor();
		string getConteudo();

    protected:
        void setDataHora(string _dataHora);
        void setEnviadaPor(int _enviadaPor);
		void setConteudo(string _conteudo);
};

#endif