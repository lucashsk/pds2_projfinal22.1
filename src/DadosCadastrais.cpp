#include "DadosCadastrais.hpp"
#include "FormataDados.hpp"

#include <string>

const std::string espacamento =  " || " ;

void DadosCadastrais::set_nome(std::string nome)    {   this->_nome  = new std::string(nome);    }
void DadosCadastrais::set_idade(int idade)          {   this->_idade = new int(idade);           }

void DadosCadastrais::set_CPF(std::string CPF_nao_formatado) {   
    
    std::string CPF_formatado = Formata::formata_CPF(CPF_nao_formatado);
    this->_CPF = new std::string(CPF_formatado);    
}

void DadosCadastrais::set_CEP(std::string CEP_nao_formatado) {   
    
    std::string CEP_formatado = Formata::formata_CEP(CEP_nao_formatado);
    this->_CEP   = new std::string(CEP_formatado);   
}

void DadosCadastrais::set_celular(std::string celular_nao_formatado) {   
    
    std::string celular_formatado = Formata::formata_celular(celular_nao_formatado);
    this->_celular   = new std::string(celular_formatado);   
}

DadosCadastrais::DadosCadastrais() {}

DadosCadastrais::DadosCadastrais(std::string nome, int idade, std::string CPF,
     std::string CEP, std::string celular) {

    set_nome(nome);
    set_idade(idade);
    set_CPF(Formata::formata_CPF(CPF));
    set_CEP(Formata::formata_CEP(CEP));
    set_celular(Formata::formata_celular(celular));
}

DadosCadastrais::~DadosCadastrais() {

    delete this->_nome;
    delete this->_idade;
    delete this->_CPF;
    delete this->_CEP;
    delete this->_celular;
}

std::string DadosCadastrais::get_nome()     {   return *this->_nome;     } 
int         DadosCadastrais::get_idade()    {   return *this->_idade;    }
std::string DadosCadastrais::get_CPF()      {   return *this->_CPF;      }
std::string DadosCadastrais::get_CEP()      {   return *this->_CEP;      }
std::string DadosCadastrais::get_celular()  {   return *this->_celular;  }

void DadosCadastrais::imprime_dados() {

    std::cout  << "Nome: "      << this->get_nome()     << std::endl
               << "Idade: "     << this->get_idade()    << std::endl
               << "CPF: "       << this->get_CPF()      << std::endl
               << "CEP: "       << this->get_CEP()      << std::endl
               << "Contato: "   << this->get_celular()  << std::endl;  
}