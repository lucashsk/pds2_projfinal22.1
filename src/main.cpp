#include "SistemaReservas.hpp"
#include "InterfaceUsuario.hpp"

int main () {

   Interface::print_titulo();
   Interface::print_apresentacao();
   Interface::print_tutorial();

    char escolha;
    std::cin >> escolha;

    Sistema::Sistema simulador;
    char resposta = 's';

    // Parâmetros utilizados;
    std::string data_inicio; std::string data_fim; int num_quarto;
    int id_reserva;

    while (resposta == 's') {

        switch (escolha) {

            case 'F':
                std::cin >> data_inicio >> data_fim >> num_quarto;
                simulador.fazer_reserva(data_inicio, data_fim, num_quarto);
                break;

            case 'C':
                std::cin >> id_reserva;
                simulador.consultar_reserva(id_reserva);
                break;

            case 'R':
                std::cin >> id_reserva;
                simulador.remover_reserva(id_reserva);    
                break;

            case 'T':
                simulador.printar_todas_reservas();
                break;

            default:
            std::cout << "Saindo do programa. Agradecemos o teste.";
                exit(0);
        }
        Interface::nova_interacao();
        std::cin >> resposta;
        system("clear");
    }   

    return 0;
}