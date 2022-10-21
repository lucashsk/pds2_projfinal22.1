#include "FormataDados.hpp"

namespace Formata {

    std::string so_deixa_numero(std::string alfanumerico) {

        std::string::iterator it;
        for (it = alfanumerico.begin(); it < alfanumerico.end(); ++it) {
            if (isalpha(*it)) {
                alfanumerico.erase(it);
                it -= 1; //correçao pra quando o it pula caracteres apos apagar
            }
        }

        return alfanumerico;
    }

    std::string formata_CPF(std::string CPF_nao_formatado) {

        CPF_nao_formatado = so_deixa_numero(CPF_nao_formatado);

        std::string parte1 = CPF_nao_formatado.substr(0, 3);
        std::string parte2 = CPF_nao_formatado.substr(3, 3);
        std::string parte3 = CPF_nao_formatado.substr(6, 3);
        std::string parte4 = CPF_nao_formatado.substr(9, 3);

        std::string CPF_formatado = parte1 + "." + parte2 + "." + parte3 + "-" + parte4;

        return CPF_formatado;
    }

    std::string formata_CEP(std::string CEP_nao_formatado) {

        CEP_nao_formatado = so_deixa_numero(CEP_nao_formatado);

        std::string parte1 = CEP_nao_formatado.substr(0, 5);
        std::string parte2 = CEP_nao_formatado.substr(5, 3);

        std::string CEP_formatado = parte1 + "-" + parte2;

        return CEP_formatado;
    }

    std::string formata_celular(std::string celular_nao_formatado) {

        celular_nao_formatado = so_deixa_numero(celular_nao_formatado);

        std::string parte1 = celular_nao_formatado.substr(0, 2);
        std::string parte2 = celular_nao_formatado.substr(2, 5);
        std::string parte3 = celular_nao_formatado.substr(7, 4);

        std::string celular_formatado = "(" + parte1 + ") " + parte2 + "-" + parte3;

        return celular_formatado;
    }

    std::string formata_salario(std::string salario_nao_formatado) {

       salario_nao_formatado = so_deixa_numero(salario_nao_formatado);

        std::string salario_formatado = "R$ " + salario_nao_formatado + ",00";

        return salario_formatado;
    }

    std::string formata_data(std::string data_nao_formatada) {

        data_nao_formatada = so_deixa_numero(data_nao_formatada);

        std::string parte1 = data_nao_formatada.substr(0, 2);
        std::string parte2 = data_nao_formatada.substr(2, 2);
        std::string parte3 = data_nao_formatada.substr(4, 4);

        std::string data_formatada = parte1 + "/" + parte2 + "/" + parte3;

         return data_formatada;
    }

    std::string formata_preco(std::string preco_nao_formatado) {

       preco_nao_formatado = so_deixa_numero(preco_nao_formatado);

        std::string parte2 = preco_nao_formatado.substr(preco_nao_formatado.length()-2);
        preco_nao_formatado.pop_back(); preco_nao_formatado.pop_back(); 
        std::string parte1 = preco_nao_formatado;

        std::string preco_formatado = "R$ " + parte1 + "," + parte2;

        return preco_formatado;
    }

}