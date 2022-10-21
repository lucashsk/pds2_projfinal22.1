#ifndef DADOS_H
#define DADOS_H

#include "FormataDados.hpp"

#include <iostream>

class DadosCadastrais {

    private: 

        std::string* _nome;
        int* _idade;
        std::string* _CPF; //vai receber tratamento especial -> pensar no fixed casas decimais
        std::string* _CEP; // ""
        std::string* _celular;
        
        void set_nome(std::string nome);
        void set_idade(int idade);
        void set_CPF(std::string CPF_nao_formatado); 
        void set_CEP(std::string CEP_nao_formatado);
        void set_celular(std::string celular_nao_formatado);

    public:

        DadosCadastrais();
        DadosCadastrais(std::string nome, int idade, std::string CPF, 
            std::string CEP, std::string celular);
        ~DadosCadastrais();

        std::string get_nome(); 
        int get_idade();
        std::string get_CPF();
        std::string get_CEP();
        std::string get_celular();

        void imprime_dados();

};

#endif