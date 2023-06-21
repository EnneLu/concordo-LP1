#ifndef CANALTEXTO_HPP
#define CANALTEXTO_HPP

#include <iostream>
#include <vector>

#include "canal.hpp"
#include "mensagem.hpp"

using namespace std;

class CanalTexto : public Canal{
        private:
                vector<Mensagem> mensagens;

        public:
                CanalTexto();
                CanalTexto(vector<Mensagem> _mensagens);
                ~CanalTexto();

        vector<Mensagem> getMensagens();

        protected:
                void setMensagens (vector<Mensagem> _mensagens);
};

#endif