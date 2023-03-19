#ifndef MAINPROCESS_H
#define MAINPROCESS_H
#include "functional.h"

class MainProcess{
    public:
        void ExecuteProcess(char opt, char tip_pro, char sel, string mesa_sel);
    private:
        char _opt{'0'};
        char _tip_pro{'0'};
        char _sel{'0'};
        string _mesa_sel{};
};

#endif