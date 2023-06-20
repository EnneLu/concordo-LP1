#ifndef CANAL_HPP
#define CANAL_HPP

#include <iostream>
#include <string>

using namespace std;

class Canal{
	private:
		string nome;

	public:
        Canal();
        Canal(string _nome);
        ~Canal();

        string getNome();

    protected:
        void setNome (string _nome);
};

#endif