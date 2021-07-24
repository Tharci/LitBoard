//
// Created by tmarc on 14/07/2021.
//

#ifndef LITBOARD_KEYBOARDHANDLER_H
#define LITBOARD_KEYBOARDHANDLER_H


#include "HIDDevice.h"

namespace lbd {
    class KeyboardHandler {
    public:
        KeyboardHandler();

        [[noreturn]] void handleKeyboard();
        [[nodiscard]] bool isConnected() const;

    private:
        HIDDevice keyboard;
    };
}


#endif //LITBOARD_KEYBOARDHANDLER_H
