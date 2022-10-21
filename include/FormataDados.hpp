#ifndef FORMATA_HPP
#define FORMATA_HPP

#include <string>
#include <cctype>

namespace Formata {

        // Recebe uma string com caracteres alfanumericos e retorna uma string com somente os algasrismos
        std::string so_deixa_numero(std::string alfanumerico);

        // Recebe um CPF com formatação aleatória e formata para o padrao XXX.XXX.XXX-XX
        std::string formata_CPF(std::string CPF_nao_formatado);

        // Recebe um CEP com formatação aleatória e formata para o padrao XXX.XXX.XXX-XX
        std::string formata_CEP(std::string CEP_nao_formatado);

        // Recebe um n° de celular com formatação aleatória e formata para o padrão (XX) XXXXX-XXXX
        std::string formata_celular(std::string celular_nao_formatado);

        // Recebe um valor de salario (INTEIRO) com formatação aleatória e converte para o padrão R$ XXXX,00
        std::string formata_salario(std::string salario_nao_formatado);

        // Recebe um valor aleatório de data (COM ANO COMPLETO) e converte para o padrao XX/XX/XXXX
        std::string formata_data(std::string data_nao_formatada);

        // Recebe um valor de preço (COM CENTAVOS) e converte para o padrao R$ XXXX,XX
        std::string formata_preco(std::string preco_nao_formatado);
}

#endif