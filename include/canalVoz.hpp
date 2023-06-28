#ifndef CANALVOZ_HPP
#define CANALVOZ_HPP

#include <iostream>
#include <vector>

#include "canal.hpp"
#include "mensagem.hpp"

using namespace std;

/** Classe de canais de voz que herda de canais*/
class CanalVoz : public Canal{
	private:
                Mensagem ultimaMensagem; /**< Var vetor de mensagens de texto*/

	public:
                CanalVoz(); /**< Construtor zerar valores*/
                CanalVoz(Mensagem _ultimaMensagem); /**< Construtor*/
                ~CanalVoz(); /**< Destrutor*/

        Mensagem getUltimaMensagem(); /**< Método get para acessar a última mensagem*/

        protected:
                void setUltimaMensagem(Mensagem _ultimaMensagem); /**< Método set para alterar valor da var última mensagem*/
};

#endif