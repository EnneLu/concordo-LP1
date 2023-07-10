#include "sistema.hpp"
#include <sstream>

Sistema::Sistema(){

}
Sistema::Sistema(vector<Usuario> _usuarios, vector<Servidor> _servidores, Usuario _usuarioLogado, Servidor _servidorAtivo, string _nomeCanalAtivo){
    this->usuarios = _usuarios;
    this->servidores = _servidores;
    this->usuarioLogado = _usuarioLogado;
    this->servidorAtivo = _servidorAtivo;
    this->nomeCanalAtivo = _nomeCanalAtivo;
}

vector<Usuario> Sistema::getUsuarios(){return this->usuarios;}
vector<Servidor> Sistema::getServidores(){return this->servidores;}
Usuario Sistema::getUsuarioLogado(){return this->usuarioLogado;}
Servidor Sistema::getServidorAtivo(){return this->servidorAtivo;}
string Sistema::getNomeCanalAtivo(){return this->nomeCanalAtivo;}

void Sistema::setUsuarios(vector<Usuario> _usuarios){this->usuarios = _usuarios;}
void Sistema::setServidores(vector<Servidor> _servidores){this->servidores = _servidores;}
void Sistema::setUsuarioLogado(Usuario _usuarioLogado){this->usuarioLogado = _usuarioLogado;}
void Sistema::setServidorAtivo(Servidor _servidorAtivo){this->servidorAtivo = _servidorAtivo;}
void Sistema::setNomeCanalAtivo(string _nomeCanalAtivo){this->nomeCanalAtivo = _nomeCanalAtivo;}

//**FUNÇÕES TRATAMENTO TEXTO**//

/*Esta função recebe uma variável string e retorna um vector da própria divido por espaço*/
vector<string> Sistema::leitor(string &_texto){ 
    vector<string> result;
    istringstream iss(_texto);
    string word;
    
    while (iss >> word) {
        result.push_back(word);
    }
    
    return result;
}

//**FUNÇÕES DE USUÁRIO**//

/*Esta função recebe o email e percorre a var usuarios,
 se encontrar retorna true, caso não encontre retorna false*/
bool Sistema::buscarEmail(string _email){ 
    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getEmail() == _email){return true;}
    }
    return false;
}

/*Esta função primeiro buscar se o email enviado por 
o vector comandos já está cadastrado utilizando a função buscarEmail,
caso não encontre realiza o cadastro do novo usuário na var usuarios */
void Sistema::novoUsuario(vector<string> _comandos){ 
    int id = usuarios.size()+1, i = 0;
    string email = _comandos[1];
    string senha = _comandos[2];
    string nome = _comandos[3];
    if (this->buscarEmail(email) == false){ //Não existe email cadastrado
        Usuario newUsuario(id, email, senha, nome);
        usuarios.push_back(newUsuario);
        cout << "Usuário criado!" << endl;
    } else {cout << "Usuário já existe!" << endl;}
}

/*Esta função realiza a listagem de usuários cadastrados na ver usuarios*/
string Sistema::listUsuarios(){
  vector<Usuario>::iterator it = usuarios.begin();
  ostringstream output;

  output << it->getId() << endl << it->getEmail() << endl << it->getSenha() << endl << it->getNome();
  ++it;
  while (it != usuarios.end()) {
    output << endl << it->getId() << endl << it->getEmail() << endl << it->getSenha() << endl << it->getNome();
    ++it;
  }

  return output.str();
}

//**FUNÇÕES DE LOGIN**//

/*Esta função recebe o email e senha do usuário, em percorre a var usuarios 
buscando, caso encontre atualiza a var usuarioLogado para o objeto do vector usuarios correspondente*/
bool Sistema::buscarUsuario(string _email, string _senha){
    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getEmail() == _email && usuarios[i].getSenha() == _senha){
            usuarioLogado = usuarios[i];
            return true;
        }
    }
    return false;
}

/*Esta função chama a função buscarUsuario, caso o retorno seja true informa sucesso no login,
caso seja false informa mensagem de erro*/
void Sistema::login(vector<string> _comandos){
    if(this->buscarUsuario(_comandos[1], _comandos[2]) == true){
        cout << "Logado como " << _comandos[1] << endl;
    } else {cout << "Senha ou usuário inválidos!" << endl;}
}

/*Esta função atualizar a var usuarioLogado para um objeto vazio*/
void Sistema::disconnect(){
    Usuario usuarioVazio(0, " ", " ", " ");
    this->usuarioLogado = usuarioVazio;
}

//**FUNÇÕES DE SERVIDOR**//

/*Esta função busca se existe um servidor com o nome informado no vector servidores,
retorna true caso exista, false caso não exista*/
bool Sistema::buscarNomeServidor(string _nome){
    for(int i = 0; i < servidores.size(); i++){
        if(servidores[i].getNome() == _nome){return true;}
    }
    return false;
}

/*Esta função chama a função buscarNomeServidor para verificar se existe um servidor
 com o nome informado no vector servidores, caso não exista realiza o cadastro e insere no vector servidores*/
void Sistema::novoServidor(vector<string> _comandos){
    int usuarioDonoId = this->usuarioLogado.getId();
    string nome = _comandos[1];
    string descricao = " ";
    string codigoConvite = " ";
    vector<Canal *> canais = { };
    vector<int> participantesID = { };
    
    if (this->buscarNomeServidor(nome) == false){ //Não existe servidor com esse nome cadastrado
        Servidor newServidor(usuarioDonoId, nome, descricao, codigoConvite, canais, participantesID);
        servidores.push_back(newServidor);
        cout << "Servidor criado" << endl;
    } else {cout << "Servidor com esse nome já existe" << endl;}    
}

/*Esta função chama a função buscarNomeServidor para verificar se existe um servidor
 com o nome informado no vector servidores, caso exista busca qual o servidor no vector de servidores
 e atualiza sua descrição chamando a função mudarDescricao presente na classe servidor 
 verificando também se a var usuarioLogado é o dono do servidor*/
void Sistema::mudarDescricao(vector<string> _comandos){
    string newDescricao = _comandos[2];
    if (this->buscarNomeServidor(_comandos[1]) == true){
        for(int i = 0; i < servidores.size(); i++){ 
            if(servidores[i].getNome() == _comandos[1] && this->usuarioLogado.getId() == servidores[i].getUsuarioDonoId()){ 
                this->getServidorAtivo().mudarDescricao(newDescricao);
            } else {cout << "Você não pode alterar a descrição de um servidor que não foi criado por você" << endl;}
        }
    } else {cout << "Servidor '" << _comandos[1] << "' não existe" << endl;}
}

/*Esta função chama a função buscarNomeServidor para verificar se existe um servidor
 com o nome informado no vector servidores, caso exista busca qual o servidor no vector de servidores
 e atualiza sua descrição chamando a função mudarCodigoConvite presente na classe servidor 
 verificando também se a var usuarioLogado é o dono do servidor*/
void Sistema::mudarCodigoConvite(vector<string> _comandos){
    string newCodigo = _comandos[2];
    if (this->buscarNomeServidor(_comandos[1]) == true){
        for(int i = 0; i < servidores.size(); i++){ 
            if(servidores[i].getNome() == _comandos[1] && this->usuarioLogado.getId() == servidores[i].getUsuarioDonoId()){ 
                this->getServidorAtivo().mudarCodigoConvite(newCodigo);
            } else {cout << "Você não pode alterar o código de um servidor que não foi criado por você" << endl;}
        }
    } else {cout << "Servidor '" << _comandos[1] << "' não existe" << endl;}
}

/*Esta função lista os servidores no vector servidores*/
string Sistema::listServidores(){
  vector<Servidor>::iterator it = servidores.begin();
  ostringstream output;

  output << it->getNome() << endl;  // Percorre o vector redirecionando os nomes dos servidores para o objeto de saída
  ++it;
  while (it != servidores.end()) {
    output << it->getNome();
    ++it;
  }

  return output.str();  // Retorna o objeto ostringstream convertido para string
}

/*Esta função chama a função buscarNomeServidor para verificar se existe um servidor
 com o nome informado no vector servidores, caso exista realiza a exclusão no vector*/
void Sistema::removeServidor(vector<string> _comandos){
    string nome = _comandos[1];
    if (this->buscarNomeServidor(nome) == true){
        for(int i = 0; i < servidores.size(); i++){
            if(servidores[i].getNome() == nome && this->usuarioLogado.getId() == servidores[i].getUsuarioDonoId()){ //procura o servidor que possui o nome informado e se o dono é o usuário logado               
                servidores.erase(servidores.begin() + i);
                cout << "Servidor '" << _comandos[1] << "' removido" << endl;
            } else {cout << "Você não é o dono do servidor '" << _comandos[1] << "'" << endl;}    
        }
    } else {cout << "Servidor '" << _comandos[1] << "' não encontrado" << endl;}      
}

//**FUNÇÕES DENTRO DO SERVIDOR**//

/*Esta função percorre o vector de servidores buscando se o nome informado existe,
caso sim verifica se o usuário informou o código, caso sim insere o usuário na lista de participantes
e atualiza a var servidorAtivo para o objeto servidor*/
void Sistema::joinServidor(vector<string> _comandos){
    string nome = _comandos[1];
    string codigo = _comandos[2];
    for(int i = 0; i < servidores.size(); i++){
        if(servidores[i].getNome() == nome){ //se o nome informado é o nome na posição atual do vector
            if(servidores[i].getCodigoConvite() ==  " "){ //se o servidor for aberto qualquer usuário entra              
                servidores[i].getParticipantesIDs().push_back(this->usuarioLogado.getId());
                this->getServidorAtivo() = servidores[i];
                cout << "Entrou no servidor com sucesso" << endl;
                break;
            } else if(servidores[i].getCodigoConvite() == codigo || this->usuarioLogado.getId() == servidores[i].getUsuarioDonoId()){ //verifica se o código informado está correto ou se o usuário logado é o dono                
                servidores[i].getParticipantesIDs().push_back(this->usuarioLogado.getId());
                this->getServidorAtivo() = servidores[i];
                cout << "Entrou no servidor com sucesso" << endl;
            } else {cout << "Servidor requer código de convite" << endl;}
        } else {cout << "Servidor '" << nome << "' não existe" << endl;}
    }     
}

/*Esta função verifica se a var servidorAtivo está vazio, caso não esteja preenche com um objeto servidor vazio*/
void Sistema::leaveServidor(){
    if(servidorAtivo.getUsuarioDonoId() != 0){
        Servidor servidorVazio(0, " ", " ", " ", { }, { });
        this->servidorAtivo = servidorVazio;
        cout << "Saindo do servidor '" << servidorAtivo.getNome() << "'" << endl;
    } else {cout << "Você não está visualizando nenhum servidor" << endl;} 
}

/*Esta função chama a função listParticipantes presente na classe Servidor*/
void Sistema::listParticipantes(){
    /*string nome;
    for(int i = 0; i < getParticipantesIDs().size(); i++){
       if(getParticipantesIDs() == _id)
        nome = usuarios[i].getNome();
    }
    return nome;
    
    this->getServidorAtivo().listParticipantes();*/
}

//**FUNÇÕES CANAIS**//
/*Verifica se já existe um canal deste tipo cadastrado no vector*/
bool Sistema::buscarCanal(string _nome){
    vector<Canal*> canais = this->servidorAtivo.getCanais();
    for(const auto& canal : canais){
        if(canal->getNome() == _nome){
            return true; 
        }        
    }return false;       
}

/*Função que cria novo canal e insere no vector de canais do servidor ativo
antes da inserção realiza a busca se já existe canal com o nome informado*/
void Sistema::criarCanal(vector<string> _comandos){
    if(_comandos[2] == "texto"){
        if(buscarCanal(_comandos[1]) == false){
            string nome = _comandos[1];
            CanalTexto newCanal(nome);
            this->servidorAtivo.getCanais().push_back(&newCanal);
            cout << "Canal de voz '"<< _comandos[1] <<"' criado" << endl;
        } else {cout << "Canal de voz '"<< _comandos[1] <<"' já existe!" << endl;}
    }
    if(_comandos[2] == "voz"){
        if(buscarCanal(_comandos[1]) == false){
            string nome = _comandos[1];
            CanalVoz newCanal(nome);
            this->servidorAtivo.getCanais().push_back(&newCanal);
            cout << "Canal de voz '"<< _comandos[1] <<"' criado" << endl;
        } else {cout << "Canal de voz '"<< _comandos[1] <<"' já existe!" << endl;}
    }
}

void Sistema::entrarCanal(vector<string> _comandos){
    string nome = _comandos[1];
    vector<Canal*> canais = this->servidorAtivo.getCanais();
    if(this->buscarCanal(nome) == true && this->getNomeCanalAtivo() != " "){ //se existe canal com esse nome
        for(const auto& canal : canais){
            if(canal->getNome() == nome){
                //this->getCanalAtivo() = /*recerber a posição no vector*/;
                cout << "Entrou no canal '" << nome << "'" << endl;
                break;
            }        
        }        
    } else{cout << "Canal '" << nome << "' não existe" << endl;}
}

void Sistema::sairCanal(vector<string> _comandos){
    /*Canal canalVazio(" ");
    this->getCanalAtivo() = canalVazio;       */
}

string Sistema::listCanais(){
    string nome;


    return nome;    
}

/*Percorre verifica a var canalAtivo e chama a função enviarMensagem
presente na classe Canal e implementada nas classes CanalTexto e CanalVoz*/
void Sistema::enviarMensagem(vector<string> _comandos){
    if(this->getNomeCanalAtivo() != " "){
        string mensagem = _comandos[2];
        //this->getCanalAtivo().enviarMensagem(mensagem);
    }
}

/*Percorre o vector de mensagem, em cada posição realiza a chamada 
da função imprimirMensagem presente na classe Canal e implementada
nas classes CanalTexto e CanalVoz*/
string Sistema::listMensagens(){
    string nome;

    return nome;    
}