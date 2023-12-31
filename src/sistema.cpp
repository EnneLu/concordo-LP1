#include "sistema.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <typeinfo>

Sistema::Sistema(){

}
Sistema::Sistema(vector<Usuario> _usuarios, vector<Servidor> _servidores, Usuario _usuarioLogado, Servidor _servidorAtivo, string _nomeCanalAtivo){
    this->usuarios = _usuarios;
    this->servidores = _servidores;
    this->usuarioLogado = _usuarioLogado;
    this->servidorAtivo = _servidorAtivo;
    this->nomeCanalAtivo = _nomeCanalAtivo;
}

Sistema::~Sistema(){

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

/*Esta função recebe uma variável string e retorna um vector da própria divido por espaço,
este vector é utilizado em todas as funções para selecionar os valores em suas posições*/
vector<string> Sistema::leitor(string &_texto){ 
    vector<string> result;
    istringstream iss(_texto);
    string word;
    
    while (iss >> word) {
        result.push_back(word);
    }
    
    return result;
}

//**PERSISTÊNCIA DOS DADOS**//
void Sistema::salvarUsuarios(){
    ofstream usuArq("usuarios.txt");

    int u = usuarios.size();
    usuArq << u << endl; //Informa quantidade de usuários cadastrados
    for (int i = 0; i < u; i++) { //Informa as variáveis de todos os usuários do sistema
        usuArq << usuarios[i].getId() << endl;
        usuArq << usuarios[i].getNome() << endl;
        usuArq << usuarios[i].getEmail() << endl;
        usuArq << usuarios[i].getSenha() << endl;
    }

    usuArq.close();
}
void Sistema::salvarServidores(){
    ofstream serviArq("servidores.txt");

    int s = servidores.size(); //Informa quantidade de servidores cadastrados
    serviArq << s << endl;
    for (int i = 0; i < s; i++) { //Informa as variáveis de todos os servidores do sistema
        serviArq << servidores[i].getUsuarioDonoId() << endl;
        serviArq << servidores[i].getNome() << endl;
        serviArq << servidores[i].getDescricao() << endl;
        serviArq << servidores[i].getCodigoConvite() << endl;

        vector<int> participantesIDs = servidores[i].getParticipantesIDs(); //Informa quantidade de participantes do servidor
        serviArq << participantesIDs.size() << endl;
        for (int j = 0; j < participantesIDs.size(); j++) {serviArq << participantesIDs[j] << endl;} //Informa o id de cada participante

        vector<Canal*> canais = servidores[i].getCanais(); //Informa quantidade de canais do servidor
        serviArq << canais.size() << endl;
        string tipo;
        for (int j = 0; j < canais.size(); j++) { //Percorre todos os canais cadastrados
            serviArq << canais[j]->getNome() << endl; //Informa o nome do canal na posição j
            if(canais[j]->tipoClasse() == "texto"){
                tipo = "TEXTO";
            } else if(canais[j]->tipoClasse() == "voz"){
                tipo = "VOZ";
            }
            serviArq << tipo << endl; //Informa o tipo do canal na posição j

            vector<Mensagem> mensagem = canais[j]->getMensagem(); //Informa quantidade de mensagem do canal na posição j
            serviArq << mensagem.size() << endl;
                for (int k = 0; k < mensagem.size(); k++) { //Informa todas as variáveis da mensagem
                    serviArq << mensagem[k].getEnviadaPor() << endl;
                    serviArq << mensagem[k].getDataHora() << endl;
                    serviArq << mensagem[k].getConteudo() << endl;
                }
            }
        }

    serviArq.close();
}

/*Chama as demais funções para salvar*/
void Sistema::salvar(){
    salvarUsuarios();
    salvarServidores(); 
}

//**RESTAURAÇÃO DOS DADOS**//

/*Esta função recebe o email e percorre a var usuarios,
 se encontrar retorna true, caso não encontre retorna false*/
bool Sistema::buscarEmail(string _email){ 
    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i].getEmail() == _email){return true;}
    }
    return false;
}

void Sistema::carregarUsuarios(){
    ifstream usuArq("usuarios.txt");

    string size, id, nome, email, senha; //Variaveis que serão utilizadas ao cadastrar os dados
    size_t u;
    usuarios.clear();

    usuArq >> size; //Verifica quantidade de usuários disponíveis no arquivo e atualiza a var u
    u = stoi(size);
    usuArq.ignore();

    for (int i = 0; i < u ; ++i) { //Salva as variáveis de todos os usuários do arquivo
        getline(usuArq, id);
        getline(usuArq, nome);
        getline(usuArq, email);
        getline(usuArq, senha);
        int intId = stoi(id);
  
        if (this->buscarEmail(email) == false){ // Verifica se o usuário já existe
            Usuario newUsuario(intId, email, senha, nome);
            usuarios.push_back(newUsuario);
        }
    }

    usuArq.close();
}
void Sistema::carregarServidores(){
    ifstream serviArq("servidores.txt");

    string size, usuarioDonoId, nome, descricao, codigoConvite, idParticipante, nomeCanal, tipoCanal, idMensagem, dataHora, conteudo;
    size_t s, u, c, m;
    int intId;
    servidores.clear(); 

    getline(serviArq, size); //Verifica quantidade de servidores disponíveis no arquivo e atualiza a var s
    s = stoi(size);
    
    for (int i = 0; i < s; i++) { //Salva as variáveis de todos os servidores do arquivo
      getline(serviArq, usuarioDonoId);
      getline(serviArq, nome);
      getline(serviArq, descricao);
      getline(serviArq, codigoConvite);
      intId = stoi(usuarioDonoId);
      
      Servidor newServidor(intId, nome, descricao, codigoConvite, { }, { }); //Cadastra novo servidor com as variáveis informadas

      getline(serviArq, size); //Verifica quantidade de usuários participantes do servidor e atualiza a var u
      u = stoi(size);

      for (int j = 0; j < u; j++) { //Salva as variáveis de todos os participante do servidor
        getline(serviArq, idParticipante);
        intId = stoi(idParticipante);
        newServidor.addParticipante(intId);
      }

      getline(serviArq, size); //Verifica quantidade de canais do servidor e atualiza a var c
      c = stoi(size);

      for (size_t j = 0; j < c; ++j) { //Salva as variáveis de todos os canais do servidor
        getline(serviArq, nomeCanal);
        getline(serviArq, tipoCanal);

        Canal *newCanal; //Cadastra novo canal com as variáveis informadas, é feito primeiro a consulta do tipo do objeto que está na classe
        if(tipoCanal == "TEXTO"){
            newCanal = new CanalTexto(nomeCanal);
        } else if(tipoCanal == "VOZ"){
            newCanal = new CanalVoz(nomeCanal);
        }

        getline(serviArq, size); //Verifica quantidade de mensagens do canal e atualiza a var m
        m = stoi(size);

        for (size_t k = 0; k < m; ++k) { //Salva as variáveis de todos as mensagens do canal
          getline(serviArq, idMensagem);
          intId = stoi(idMensagem);
          getline(serviArq, dataHora);
          getline(serviArq, conteudo);

          Mensagem newMensagem(dataHora, intId, conteudo); //Cadastra nova mensagem com as variáveis informadas
          newCanal->enviarMensagem(newMensagem);
        }
        newServidor.addCanal(newCanal); // Adiciona o canal ao servidor
      }
      servidores.push_back(newServidor); // Adiciona o servidor na lista
    }

    serviArq.close();  
}
/*Chama as demais funções para atualizar os dados do sistema*/
void Sistema::carregar(){
    int fileSize = 0;
    ifstream usuArq("usuarios.txt");
    ifstream serviArq("servidores.txt");

    if (usuArq) { // Verifica se o arquivo de usuários existe e não está vazio
        usuArq.seekg(0, ios::end);
        fileSize = usuArq.tellg();
        if (fileSize > 0) {
            carregarUsuarios();
        }

        usuArq.close();
    }
    
    if (serviArq) { // Verifica se o arquivo de servidores existe e não está vazio
        serviArq.seekg(0, ios::end);
        fileSize = serviArq.tellg();
        if (fileSize > 0) {
        carregarServidores();
        }

        serviArq.close();
    }    
}


//**FUNÇÕES DE USUÁRIO**//

/*Esta função primeiro buscar se o email enviado por 
o vector comandos já está cadastrado utilizando a função buscarEmail,
caso não encontre realiza o cadastro do novo usuário na var usuarios */
void Sistema::novoUsuario(vector<string> _comandos){ 
    carregar();
    int id = usuarios.size()+1, i = 0;
    string email = _comandos[1];
    string senha = _comandos[2];
    string nome;
    for(int i = 3; i < _comandos.size(); i++){nome += _comandos[i] + " ";} 
        if (this->buscarEmail(email) == false){ //Caso não existe email cadastrado, cadastra novo usuário
            Usuario newUsuario(id, email, senha, nome);
            usuarios.push_back(newUsuario);
            cout << "Usuário criado!" << endl;
        } else {cout << "Usuário já existe!" << endl;}
    salvar();
}

/*Esta função realiza a listagem de usuários cadastrados na ver usuarios*/
string Sistema::listUsuarios(){
    carregar();
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

/*Esta função percorre a var usuarios buscando usuario com email e senha informado, 
 caso encontre atualiza a var usuarioLogado para o objeto do vector usuarios correspondente*/
bool Sistema::buscarUsuario(string _email, string _senha){
    carregar();
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
    carregar();
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
    carregar();
    for(int i = 0; i < servidores.size(); i++){
        if(servidores[i].getNome() == _nome){return true;}
    }
    return false;
}

/*Esta função chama a função buscarNomeServidor para verificar se existe um servidor
 com o nome informado no vector servidores, caso não exista realiza o cadastro e insere no vector servidores*/
void Sistema::novoServidor(vector<string> _comandos){
    carregar();
    int usuarioDonoId = this->usuarioLogado.getId();
    string nome = _comandos[1];
    string descricao = " ";
    string codigoConvite = " ";
    vector<Canal *> canais = { };
    vector<int> participantesID = { };
    
    if (this->buscarNomeServidor(nome) == false){ //Caso não exista servidor com esse nome cadastrado é feito o cadastro
        Servidor newServidor(usuarioDonoId, nome, descricao, codigoConvite, canais, participantesID);
        newServidor.addParticipante(this->usuarioLogado.getId());
        servidores.push_back(newServidor);
        cout << "Servidor criado" << endl;
    } else {cout << "Servidor com esse nome já existe" << endl;}  
    salvar();  
}

/*Esta função chama a função buscarNomeServidor para verificar se existe um servidor
 com o nome informado no vector servidores, caso exista busca qual o servidor no vector de servidores
 e atualiza sua descrição chamando a função mudarDescricao presente na classe servidor, 
 verifica também se a var usuarioLogado é o dono do servidor*/
void Sistema::mudarDescricao(vector<string> _comandos){
    carregar();
    string newDescricao;
    for(int i = 2; i < _comandos.size(); i++){newDescricao += _comandos[i] + " ";}
    if (this->buscarNomeServidor(_comandos[1]) == true){
        for(int i = 0; i < servidores.size(); i++){ 
            if(servidores[i].getNome() == _comandos[1]){
            if(this->usuarioLogado.getId() == servidores[i].getUsuarioDonoId()){ 
                this->getServidorAtivo().mudarDescricao(&servidores[i], newDescricao);
                } else {cout << "Você não pode alterar a descrição de um servidor que não foi criado por você" << endl;}
            }
        }
    } else {cout << "Servidor '" << _comandos[1] << "' não existe" << endl;}
    salvar();
}

/*Esta função chama a função buscarNomeServidor para verificar se existe um servidor
 com o nome informado no vector servidores, caso exista busca qual o servidor no vector de servidores
 e atualiza sua descrição chamando a função mudarCodigoConvite presente na classe servidor, 
 verifica também se a var usuarioLogado é o dono do servidor*/
void Sistema::mudarCodigoConvite(vector<string> _comandos){
    carregar();
    string newCodigo = " ";
    if(_comandos.size() == 3) {newCodigo = _comandos[2];}
    if (this->buscarNomeServidor(_comandos[1]) == true){
        for(int i = 0; i < servidores.size(); i++){ 
            if(servidores[i].getNome() == _comandos[1]){
                if(this->usuarioLogado.getId() == servidores[i].getUsuarioDonoId()){ 
                    this->getServidorAtivo().mudarCodigoConvite(&servidores[i], newCodigo);
                }else {cout << "Você não pode alterar o código de um servidor que não foi criado por você" << endl;}
            }            
        }
    } else {cout << "Servidor '" << _comandos[1] << "' não existe" << endl;}
    salvar();
}

/*Esta função lista os servidores no vector servidores*/
string Sistema::listServidores(){
    carregar();
    vector<Servidor>::iterator it = servidores.begin();
    ostringstream output;

    output << it->getNome() << endl;
    ++it;
    while (it != servidores.end()) {
        output << it->getNome();
        ++it;
    }

    return output.str();
}

/*Esta função chama a função buscarNomeServidor para verificar se existe um servidor
 com o nome informado no vector servidores, caso exista realiza a exclusão no vector*/
void Sistema::removeServidor(vector<string> _comandos){
    carregar();
    string nome = _comandos[1];
    if (this->buscarNomeServidor(nome) == true){
        for(int i = 0; i < servidores.size(); i++){
            if(servidores[i].getNome() == nome && this->usuarioLogado.getId() == servidores[i].getUsuarioDonoId()){ //procura o servidor que possui o nome informado e se o dono é o usuário logado               
                servidores.erase(servidores.begin() + i);
                cout << "Servidor '" << _comandos[1] << "' removido" << endl;
            } else {cout << "Você não é o dono do servidor '" << _comandos[1] << "'" << endl;}    
        }
    } else {cout << "Servidor '" << _comandos[1] << "' não encontrado" << endl;}     
    salvar(); 
}

//**FUNÇÕES DENTRO DO SERVIDOR**//

/*Esta função percorre o vector de servidores buscando se o nome informado existe,
caso sim verifica se o usuário informou o código, caso sim insere o usuário na lista de participantes
e atualiza a var servidorAtivo para o objeto servidor*/
void Sistema::joinServidor(vector<string> _comandos){
    carregar();
    string nome = _comandos[1];
    string codigo = _comandos[2];
    for(int i = 0; i < servidores.size(); i++){
        if(servidores[i].getNome() == nome){ //se o nome informado é o nome na posição atual do vector
            if(servidores[i].getCodigoConvite() ==  " "){ //se o servidor for aberto qualquer usuário entra  
                this->setServidorAtivo(servidores[i]);
                servidorAtivo.addParticipante(this->usuarioLogado.getId());
                cout << "Entrou no servidor com sucesso" << endl;
                break;
            } else if(servidores[i].getCodigoConvite() == codigo || this->usuarioLogado.getId() == servidores[i].getUsuarioDonoId()){ //verifica se o código informado está correto ou se o usuário logado é o dono                
                this->setServidorAtivo(servidores[i]);
                servidorAtivo.addParticipante(this->usuarioLogado.getId());
                cout << "Entrou no servidor com sucesso" << endl;
                break;
            } else {cout << "Servidor requer código de convite" << endl;}
        } else {cout << "Servidor '" << nome << "' não existe" << endl;}
    }     
}

/*Esta função verifica se a var servidorAtivo está vazio, caso não esteja preenche com um objeto servidor vazio*/
void Sistema::leaveServidor(){
    carregar();
    if(servidorAtivo.getUsuarioDonoId() != 0){
        Servidor servidorVazio(0, " ", " ", " ", { }, { });
        cout << "Saindo do servidor '" << servidorAtivo.getNome() << "'" << endl;
        this->servidorAtivo = servidorVazio;
    } else {cout << "Você não está visualizando nenhum servidor" << endl;} 
}

/*Esta função busca o nome do usuário de acordo com seu id e retorna o nome*/
string Sistema::buscarUsuarioId(int _id){
    carregar();
    string nome;
    for(int i = 0; i < usuarios.size(); i++){
       if(usuarios[i].getId() == _id)
        nome = usuarios[i].getNome();
    }
    return nome;
}

/*Esta função chama a função buscarUsuarioId para cada id presente no vector participantesIDs
em seguida informa o nome*/
void Sistema::listParticipantes(){
    carregar();
    string nome = "vazio";
    for(int i = 0; i < servidorAtivo.getParticipantesIDs().size(); i++){
        nome = buscarUsuarioId(servidorAtivo.getParticipantesIDs()[i]);
        cout << nome << endl;
    }
}

//**FUNÇÕES CANAIS**//
/*Verifica se já existe um canal deste tipo cadastrado no vector*/
bool Sistema::buscarCanal(string _nome, string _tipo){
    carregar();
    vector<Canal*> canais = this->servidorAtivo.getCanais();
    for(const auto& canal : canais){
        if(canal->getNome() == _nome && canal->tipoClasse() == _tipo){
            return true;
        }   
    }return false;
}

/*Função que cria novo canal e insere no vector de canais do servidor ativo
antes da inserção realiza a busca se já existe canal com o nome informado*/
void Sistema::criarCanal(vector<string> _comandos){
    carregar();
    string nome = _comandos[1];
    Canal* newCanal;
    Servidor* servidor;
    //Busca na lista de servidores o servidor ativo e a var servidor aponta a ele
    for(int i = 0; i < servidores.size(); i++){if(servidores[i].getNome() == getServidorAtivo().getNome()){servidor = &servidores[i];}}

    if(_comandos[2] == "texto"){
        if(buscarCanal(_comandos[1], "texto") == false){
            newCanal = new CanalTexto(nome);
            servidor->addCanal(newCanal);
            cout << "Canal de texto '"<< _comandos[1] <<"' criado" << endl;
        } else {cout << "Canal de texto '"<< _comandos[1] <<"' já existe!" << endl;}
    }
    if(_comandos[2] == "voz"){
        if(buscarCanal(_comandos[1], "voz") == false){
            newCanal = new CanalVoz(nome);
            servidor->addCanal(newCanal);
            cout << "Canal de voz '"<< _comandos[1] <<"' criado" << endl;
        } else {cout << "Canal de voz '"<< _comandos[1] <<"' já existe!" << endl;}
    }
    //Atualiza a var servidorAtivo
    for(int i = 0; i < servidores.size(); i++){if(servidores[i].getNome() == getServidorAtivo().getNome()){servidorAtivo = servidores[i];}}
    salvar();
}

/*Entra no canal informado, antes é feita a busca se existe canal com esse nome*/
void Sistema::entrarCanal(vector<string> _comandos){
    carregar();
    string nome = _comandos[1];
    vector<Canal*> canais = this->servidorAtivo.getCanais();
    for(const auto& canal : canais){
        if(this->buscarCanal(nome, canal->tipoClasse()) == true){ //Se existe canal com esse nome
            if(canal->getNome() == nome){
                this->setNomeCanalAtivo(canal->getNome());
                cout << "Entrou no canal '" << nome << "'" << endl;
                break;
            }       
        } else{cout << "Canal '" << nome << "' não existe" << endl;} 
    }        
}

/*Entra no canal informado e preenche a var nome canal ativo com string vazia*/
void Sistema::sairCanal(vector<string> _comandos){
    carregar();
    string vazio = " ";
    this->setNomeCanalAtivo(vazio);
    cout << "Saindo do canal" << endl;
}

/*Lista canais*/
string Sistema::listCanais(){
    carregar();
    string nome = "vazio";
    Servidor servidor;
    vector<Canal*> listCanal;
    ostringstream outputT;
    ostringstream outputV;
    //Busca na lista de servidores o servidor ativo e a var servidor aponta a ele
    for(int i = 0; i < servidores.size(); i++){if(servidores[i].getNome() == getServidorAtivo().getNome()){servidor = servidores[i];}}
    listCanal = servidorAtivo.getCanais();

    outputT << "#canais de texto";
    outputV << "#canais de voz";
    for(int i = 0; i < listCanal.size(); i++){ //Percorre vector de canais e separa por "texto" e "voz"
        if (listCanal[i]->tipoClasse() == "texto") {
          outputT << endl << listCanal[i]->getNome();
        } else if (listCanal[i]->tipoClasse() == "voz") {
          outputV << endl << listCanal[i]->getNome();
        }
    }

    outputT << endl << outputV.str();
    return outputT.str();   
}

/*Verifica a var canalAtivo e chama a função enviarMensagem
presente na classe Canal e implementada nas classes CanalTexto e CanalVoz*/
void Sistema::enviarMensagem(vector<string> _comandos){
    carregar();
    // Criação objeto mensagem
    string mensagem;
    for(int i = 1; i < _comandos.size(); i++){mensagem += _comandos[i] + " ";}
    struct tm *p;
    time_t seconds;
    time(&seconds);
    p = localtime(&seconds);
    int dia, mes, ano, hora, minuto;
    dia = p->tm_mday;
    mes = p->tm_mon + 1;
    ano = p->tm_year + 1900;
    hora = p->tm_hour;
    minuto = p->tm_min;
    ostringstream dataHora;
    dataHora << "<" << dia << "/" << mes << "/" << ano << " - " << hora << ":" << minuto << ">";
    Mensagem newMessagem(dataHora.str(), usuarioLogado.getId(), mensagem);

    Servidor* servidor;
    //Busca na lista de servidores o servidor ativo e a var servidor aponta a ele
    for(int i = 0; i < servidores.size(); i++){if(servidores[i].getNome() == getServidorAtivo().getNome()){servidor = &servidores[i];}}
    //Busca na lista de canais o canal ativo e a var canalAtivo aponta a ele
    vector<Canal*> listaCanais = servidor->getCanais();
    Canal *canalAtivo;
    for(int i = 0; i < listaCanais.size(); i++){if(listaCanais[i]->getNome() == nomeCanalAtivo){canalAtivo = listaCanais[i];}}

    // Adiciona a nova mensagem ao canal
    canalAtivo->enviarMensagem(newMessagem);

    //Atualiza a var servidorAtivo
    for(int i = 0; i < servidores.size(); i++){if(servidores[i].getNome() == getServidorAtivo().getNome()){servidorAtivo = servidores[i];}}
    salvar();
}

/*Percorre o vector de mensagem, em cada posição realiza a chamada 
da função imprimirMensagem presente na classe Canal e implementada
nas classes CanalTexto e CanalVoz*/
string Sistema::listMensagens(){
    carregar();
    string mensagens;
    Servidor* servidor;
    //Busca na lista de servidores o servidor ativo e a var servidor aponta a ele
    for(int i = 0; i < servidores.size(); i++){if(servidores[i].getNome() == getServidorAtivo().getNome()){servidor = &servidores[i];}}
    //Busca na lista de canais o canal ativo e a var canalAtivo aponta a ele
    vector<Canal*> listaCanais = servidor->getCanais();
    Canal *canalAtivo;
    for(int i = 0; i < listaCanais.size(); i++){if(listaCanais[i]->getNome() == nomeCanalAtivo){canalAtivo = listaCanais[i];}}

    mensagens = canalAtivo->imprimirMensagem(usuarios);
    
    return mensagens;
}