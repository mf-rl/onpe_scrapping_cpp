#ifndef SCREENS_H
#define SCREENS_H

#include <string>
#include <vector>
#include "constants.h"
#include "messages.h"
using namespace std;
vector<string> titleScreen = {
    APP_TITLE, 
    DOUBLE_LINE()
};
vector<string> optionsScreen = {
    DOUBLE_LINE(),
    SELECT_PROCESS_INPUT,
    FIRST_STAGE_OPTION,
    SECOND_STAGE_OPTION,
    DOUBLE_LINE(),
    SELECT_OPTION_AND_ENTER
};
vector<string> tipProScreen = {
    DOUBLE_LINE(),
    SELECT_PROCESS_TYPE_INPUT,
    TOTAL_PROCESS_OPTION,
    PARTIAL_PROCESS_OPTION,
    DOUBLE_LINE(),
    SELECT_OPTION_AND_ENTER
};
vector<string> selParScreen = {
    DOUBLE_LINE(),
    SELECT_PARTIAL_OPTION,
    UBIGEO_OPTION,
    TABLE_OPTION,
    DOUBLE_LINE(),
    SELECT_OPTION_AND_ENTER
};
vector<string> tableNumberScreen = {
    INPUT_TABLE_NUMBER
};
vector<string> processFinishedScreen = {
    PROCESS_FINISHED,
    PRESS_ANY_KEY
};
vector<string> printSeparator = {
    DOUBLE_LINE(),
};

#endif
