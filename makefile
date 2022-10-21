CC = g++
CFLAGS = -std=c++11 -Wall -g

INCLUDE_DIR = ./include
SRC_DIR = ./src
BUILD_DIR = ./build


ENTIDADES = ${SRC_DIR}/entidades
OBJS =  DadosCadastrais.o FormataDados.o Frigobar.o Item.o Quarto.o Reserva.o teste.o Hotel.o SistemaReservas.o InterfaceUsuario.o

EXECUTABLE = teste

all : ${EXECUTABLE}

%* : %*.o 
	${CC} ${CFLAGS} $< -o $@

%*.o : %*.cpp 
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o ${BUILD_DIR}/$@

# ver depois o pq de ele estar recompilando todas as vezes mesmo sem alterações
${EXECUTABLE} : ${OBJS} ${BUILD_DIR} ${SRC_DIR} ${INCLUDE_DIR}
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o $@

teste.o : ${SRC_DIR}/teste.cpp ${INCLUDE_DIR}
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o ${BUILD_DIR}/$@

DadosCadastrais.o : ${SRC_DIR}/DadosCadastrais.cpp ${INCLUDE_DIR}
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o ${BUILD_DIR}/$@

FormataDados.o : ${SRC_DIR}/FormataDados.cpp ${INCLUDE_DIR}
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o ${BUILD_DIR}/$@

Frigobar.o : ${SRC_DIR}/Frigobar.cpp ${INCLUDE_DIR}
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o ${BUILD_DIR}/$@

Item.o : ${SRC_DIR}/Item.cpp ${INCLUDE_DIR}
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o ${BUILD_DIR}/$@

Quarto.o : ${SRC_DIR}/Quarto.cpp ${INCLUDE_DIR}
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o ${BUILD_DIR}/$@

Reserva.o : ${SRC_DIR}/Reserva.cpp ${INCLUDE_DIR}
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o ${BUILD_DIR}/$@

Hotel.o : ${SRC_DIR}/Hotel.cpp ${INCLUDE_DIR}
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o ${BUILD_DIR}/$@
SistemaReservas.o : ${SRC_DIR}/SistemaReservas.cpp ${INCLUDE_DIR}
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o ${BUILD_DIR}/$@
InterfaceUsuario.o : ${SRC_DIR}/InterfaceUsuario.cpp ${INCLUDE_DIR}
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c $< -o ${BUILD_DIR}/$@

run :
	./${EXECUTABLE}

clean : 
	rm ${BUILD_DIR}/*.o ${EXECUTABLE}