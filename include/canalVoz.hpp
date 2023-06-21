#ifndef CANALVOZ_HPP
#define CANALVOZ_HPP

#include <iostream>
#include <vector>

#include "canal.hpp"
#include "mensagem.hpp"

using namespace std;

class CanalVoz : public Canal{
	private:
                Mensagem ultimaMensagem;

	public:
                CanalVoz();
                CanalVoz(Mensagem _ultimaMensagem);
                ~CanalVoz();

        Mensagem getUltimaMensagem();

        protected:
                void setUltimaMensagem(Mensagem _ultimaMensagem);
};

#endif