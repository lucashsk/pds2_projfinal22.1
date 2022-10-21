#include "InterfaceUsuario.hpp"

namespace Interface {

void print_titulo() {

    std::cout << "\n ===== BOAS VINDAS À VERSÃO BETA DO SISTEMA DE GESTÃO DE HOTÉIS ===== \n"
        << "autor: lucashsk"
        << std::endl << std::endl;
}

void print_apresentacao() {

    std::cout << "Aqui está um breve resumo sobre a plataforma:\n"
        << "\tO propósito do sistema é contemplar as principais funcionalidades exigidas na gestão de um hotel.\n"
        << "\tSendo assim, esse programa visa oferecer uma ideia geral das funcionalidades presentes,\n"
        << "\tservindo como um esqueleto para a criação de sistemas personalizados.\n"
        << "Os dados estão armazenados em memória, as informações não serão mantidas para execuções futuras." << std::endl;
}

void print_tutorial() {

    std::cout << std::endl << "=== TUTORIAL ===" << std::endl
        << "\nFunções para atendentes e para hóspedes:\n"
        << "\tPara fazer uma reserva, digite [F]\n"
        << "\tPara consultar uma reserva, digite [C] (OBS.: cabem restrições se for pelo usuário)\n"
        << "\tPara cancelar uma reserva, digite [R]\n"
        << "\nFunções para atendentes:\n"
        << "\tPara observar todas as reservas, digite [T]\n\n"
        << "Para sair do sistema, digite qualquer outro caracter."
        << "Por favor, digite a letra relativa a sua escolha: ";
}

void tutorial_reserva() {

    std::cout << "Digite a data incial da reserva, a data final e o n° do quarto desejado:\nComando: ";
}

void tutorial_consulta() {

    std::cout << "Digite o n° do quarto do qual deseja-se sabe o status de ocupação:\nComando: ";
}

void tutorial_cancelamento() {

    std::cout << "Digite o id da reserva que deseja-se cancelar:\n"
        << "*Aconselha-se observar todas as reservas, caso o id tiver sido esquecido.\nComando: ";
} 

void nova_intercao() {

    std::cout << "Para realizar uma nova interação digite [s], caso deseja encerrar, digite qualquer outro caracter:";
}

}