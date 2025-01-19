#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "../app.h"

class HumidityApp : public App {
   public:
    HumidityApp() {
        name = "Humidity";
        description = "Displays the current humidity.";
        icon = {
            {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB(28, 164, 232), CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB::Black, CRGB::Black, CRGB(28, 164, 232), CRGB(28, 164, 232), CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB::Black, CRGB::Black, CRGB(28, 164, 232), CRGB(48, 121, 230), CRGB(27, 93, 224), CRGB::Black, CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB::Black, CRGB(28, 164, 232), CRGB(153, 217, 234), CRGB(48, 121, 230), CRGB(27, 93, 224), CRGB::Black, CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB::Black, CRGB(153, 217, 234), CRGB(153, 217, 234), CRGB(48, 121, 230), CRGB(48, 121, 230), CRGB(27, 93, 224), CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB(28, 164, 232), CRGB(153, 217, 234), CRGB(48, 121, 230), CRGB(48, 121, 230), CRGB(31, 109, 224), CRGB(27, 93, 224), CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB(28, 164, 232), CRGB(48, 121, 230), CRGB(48, 121, 230), CRGB(31, 109, 224), CRGB(31, 109, 224), CRGB(12, 67, 176), CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB::Black, CRGB(27, 93, 224), CRGB(12, 67, 176), CRGB(12, 67, 176), CRGB(12, 67, 176), CRGB::Black, CRGB::Black, CRGB::Black},
        };
    }

    void tick() override;

    void handleButtonPressed(int button, ClickType clickType) override;
};

#endif  // HUMIDITY_H
