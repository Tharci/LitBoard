//
// Created by tmarc on 14/07/2021.
//

#ifndef LITBOARD_AUDIOVISUALIZER_H
#define LITBOARD_AUDIOVISUALIZER_H

#include "Component.h"


namespace lbd::comp {
    class AudioVisualizer : public Component {
    public:
        [[nodiscard]] ComponentId getComponentId() const override;
    };
}



#endif //LITBOARD_AUDIOVISUALIZER_H