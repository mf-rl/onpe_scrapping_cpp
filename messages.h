#ifndef MESSAGES_H
#define MESSAGES_H

#include <string>

const char SELECT_PROCESS_INPUT[]{"Seleccionar proceso:"};
const char FIRST_STAGE_OPTION[]{"1: Resultados 1ra Vuelta"};
const char SECOND_STAGE_OPTION[]{"2: Resultados 2da Vuelta"};

const char SELECT_PROCESS_TYPE_INPUT[]{"Seleccionar tipo de proceso:"};
const char TOTAL_PROCESS_OPTION[]{"1: Total"};
const char PARTIAL_PROCESS_OPTION[]{"2: Parcial"};

const char SELECT_PARTIAL_OPTION[]{"Seleccionar opción:"};
const char UBIGEO_OPTION[]{"1: Por Ubigeo"};
const char TABLE_OPTION[]{"2: Por Mesa"};

const char INPUT_TABLE_NUMBER[]{"Ingresar número de mesa:"};
const char INPUT_UBIGEO_CODE[]{"Ingresar código de ubigeo:"};

const char SELECT_OPTION_AND_ENTER[]{"Digitar opción y presionar <Enter>:"};
const char WAIT_FOR_ANSWER[]{"Respuesta: "};

const char INITIALIZING_DRIVER[]{"Inicializando ChromeDriver..."};
const char DRIVER_INITIATED[]{"ChromeDriver Iniciado."};
const char PROCESS_FINISHED[]{"Finalizado. :)"};
const char PRESS_ANY_KEY[]{"Pulsar cualquier tecla para continuar..."};
const char READING_DATA[]{"Leyendo datos de web apis..."};
const char READING[]{"Leyendo: {0}"};
const char TABLE_NUMBER[]{"Mesa N° {0}"};

const char UBIGEO_INVALID[]{"Error: código de ubigeo inválido."};
const char UBIGEO_NOT_FOUND[]{"Error: No se encontró ubigeo."};
const char TABLE_NOT_FOUND[]{"Error: No se encontró mesa."};

const std::string DOUBLE_LINE()
{
    std::string str("="); 
    return str.insert(0, 50, '='); 
}

#endif