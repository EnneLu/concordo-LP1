#include "sistema.hpp"
#include <sstream>

Sistema::Sistema(){

}
Sistema::Sistema(vector<Usuario> _usuarios, vector<Servidor> _servidores, Usuario _usuarioLogado, Servidor _servidorAtivo, Canal _canalAtivo){
    this->usuarios = _usuarios;
    this->servidores = _servidores;
    this->usuarioLogado = _usuarioLogado;
    this->servidorAtivo = _servidorAtivo;
    this->canalAtivo = _canalAtivo;
}

vector<Usuario> Sistema::getUsuarios(){return this->usuarios;}
vector<Servidor> Sistema::getServidores(){return this->servidores;}
Usuario Sistema::getUsuarioLogado(){return this->usuarioLogado;}
Servidor Sistema::getServidorAtivo(){return this->servidorAtivo;}
Canal Sistema::getCanalAtivo(){return this->canalAtivo;}

void Sistema::setUsuarios(vector<Usuario> _usuarios){this->usuarios = _usuarios;}
void Sistema::setServidores(vector<Servidor> _servidores){this->servidores = _servidores;}
void Sistema::setUsuarioLogado(Usuario _usuarioLogado){this->usuarioLogado = _usuarioLogado;}
void Sistema::setServidorAtivo(Servidor _servidorAtivo){this->servidorAtivo = _servidorAtivo;}
void Sistema::setCanalAtivo(Canal _canalAtivo){this->canalAtivo = _canalAtivo;}

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
 e atualiza sua descrição verificando também se a var usuarioLogado é o dono do servidor*/
void Sistema::mudarDescricao(vector<string> _comandos){
    string nome = _comandos[1];
    string descricao = _comandos[2];
    if (this->buscarNomeServidor(nome) == true){ //Existe servidor com esse nome cadastrado
        for(int i = 0; i < servidores.size(); i++){ //pecorre o vetor se servidores
            if(servidores[i].getNome() == nome && this->usuarioLogado.getId() == servidores[i].getUsuarioDonoId()){
                servidores[i].getDescricao() = descricao;
                cout << "Descrição do servidor '" << _comandos[1] << "' modificada!" << endl;
            } else {cout << "Você não pode alterar a descrição de um servidor que não foi criado por você" << endl;}    
        } 
    } else {cout << "Servidor '" << _comandos[1] << "' não existe" << endl;} 
}

/*Esta função chama a função buscarNomeServidor para verificar se existe um servidor
 com o nome informado no vector servidores, caso exista busca qual o servidor no vector de servidores
 e atualiza seu código de convite verificando também se a var usuarioLogado é o dono do servidor*/
void Sistema::mudarCodigoConvite(vector<string> _comandos){
    string nome = _comandos[1];
    if (this->buscarNomeServidor(nome) == true){ //Existe servidor com esse nome cadastrado
        for(int i = 0; i < servidores.size(); i++){ //pecorre o vetor de servidores
            if(servidores[i].getNome() == nome && this->usuarioLogado.getId() == servidores[i].getUsuarioDonoId()){ 
                if (_comandos.size() ==  2){
                    string codigo = _comandos[2];
                    servidores[i].getCodigoConvite() = codigo;
                    cout << "Código de convite do servidor '" << _comandos[1] << "' modificado!" << endl;
                } else{
                    servidores[i].getCodigoConvite() = " ";
                    cout << "Código de convite do servidor '" << _comandos[1] << "' removido!" << endl;
                }
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
    for(int i = 0; i < servidores.size(); i++){
        if(servidores[i].getNome() == nome){
            if(_comandos.size() ==  3){ //se o servidor for aberto qualquer usuário entra              
                servidores[i].getParticipantesIDs().push_back(this->usuarioLogado.getId());
                this->getServidorAtivo() = servidores[i];
                cout << "Entrou no servidor com sucesso" << endl;
            } else if(servidores[i].getCodigoConvite() == _comandos[2] || this->usuarioLogado.getId() == servidores[i].getUsuarioDonoId()){ //verifica se o código informado está correto ou se o usuário logado é o dono                
                servidores[i].getParticipantesIDs().push_back(this->usuarioLogado.getId());
                this->getServidorAtivo() = servidores[i];
                cout << "Entrou no servidor com sucesso" << endl;
            } else {cout << "Servidor requer código de convite" << endl;}
        } else {cout << "Servidor '" << _comandos[1] << "' não existe" << endl;}
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

/*Esta função busca o nome do usuário de acordo com seu id e retorna o nome*/
string Sistema::buscarUsuarioId(int _id){
    string nome;
    for(int i = 0; i < servidorAtivo.getParticipantesIDs().size(); i++){
       if(usuarios[i].getId() == _id)
        nome = usuarios[i].getNome();
    }
    return nome;
}

/*Esta função chama a função buscarUsuarioId para cada id presente no vector participantes Id
em seguida informa o nome*/
void Sistema::listParticipantes(){
    string nome;
    for(int i = 0; i < servidorAtivo.getParticipantesIDs().size(); i++){
        nome = buscarUsuarioId(servidorAtivo.getParticipantesIDs()[i]);
        cout << nome << endl;
    }
}