#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "../app.h"

class TemperatureApp : public App {
   public:
    TemperatureApp() {
        name = "Temperature";
        description = "Displays the current temperature.";
        icon = {
            {CRGB::Black, CRGB::Black, CRGB::Black, CRGB(230, 230, 230), CRGB(230, 230, 230), CRGB(230, 230, 230), CRGB::Black, CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB::Black, CRGB::Black, CRGB(230, 230, 230), CRGB(70, 70, 70), CRGB(230, 230, 230), CRGB::Black, CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB::Black, CRGB::Black, CRGB(230, 230, 230), CRGB(70, 70, 70), CRGB(230, 230, 230), CRGB::Black, CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB::Black, CRGB::Black, CRGB(230, 230, 230), CRGB(201, 38, 46), CRGB(230, 230, 230), CRGB::Black, CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB::Black, CRGB(230, 230, 230), CRGB(201, 38, 46), CRGB(201, 38, 46), CRGB(201, 38, 46), CRGB(230, 230, 230), CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB::Black, CRGB(230, 230, 230), CRGB(201, 38, 46), CRGB(201, 38, 46), CRGB(201, 38, 46), CRGB(230, 230, 230), CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB::Black, CRGB(230, 230, 230), CRGB(201, 38, 46), CRGB(201, 38, 46), CRGB(201, 38, 46), CRGB(230, 230, 230), CRGB::Black, CRGB::Black},
            {CRGB::Black, CRGB::Black, CRGB::Black, CRGB(230, 230, 230), CRGB(230, 230, 230), CRGB(230, 230, 230), CRGB::Black, CRGB::Black, CRGB::Black}};
    }

    void tick() override;

    void handleButtonPressed(int button, ClickType clickType) override;
};

#endif  // TEMPERATURE_H
