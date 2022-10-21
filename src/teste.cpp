#include "Item.hpp"
#include "Frigobar.hpp"
#include "FormataDados.hpp"
#include "Quarto.hpp"
#include "Reserva.hpp"
#include "Hotel.hpp"
#include "SistemaReservas.hpp"
#include <iostream>

int main () {

    Sistema::Sistema sistema;

    sistema.fazer_reserva("20122012", "24122012", 1005);
    sistema.consultas_quartos().pesquisar_estado_de_ocupacao(1005);
    sistema.printar_todas_reservas();
    sistema.consultar_reserva(9001);
/*
    int id;
    std::cin >> id; std::cout << std::endl;

    sistema.remover_reserva(id);
    sistema.printar_todas_reservas();
    */
   
    /*
    Hotel::Hotel hotel;

    hotel.preencher_quartos();
    //hotel.print_quartos();
    //hotel.pesquisar_estado_de_ocupacao(1020);
    hotel.pesquisar_estado_de_ocupacao(1021);

    hotel.
    */

    //lista_de_reservas.fazer_reserva("14072022", "16072022", 1020);
/*
    //pensar em mudar os ponteiros para smart_pointers
    Quarto::Quarto* quarto1 = new Quarto::Quarto(1001, Quarto::PADRAO_1_CAMA);
    
    Quarto::Quarto quarto2(1002, Quarto::SUITE_LUXO);
    Quarto::Quarto quarto3(1003, Quarto::SUITE_PREMIUM);
    Quarto::Quarto quarto4(2001, Quarto::PADRAO_2_CAMAS);
    Quarto::Quarto quarto5(2002, Quarto::SUITE_LUXO);
    Quarto::Quarto quarto6(2003, Quarto::SUITE_PREMIUM);
    Quarto::Quarto quarto7(3001, Quarto::PADRAO_3_CAMAS);
    Quarto::Quarto quarto8(3002, Quarto::SUITE_LUXO);
    Quarto::Quarto quarto9(3003, Quarto::SUITE_PREMIUM);
 
    Reserva::Reserva reserva1("20022023", "23022023", quarto1);

    reserva1.print_dados();

    //delete quarto1;
*/

    return 0;
}