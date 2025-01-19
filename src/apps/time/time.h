#ifndef TIME_H
#define TIME_H

#include "../app.h"

class TimeApp : public App {
   public:
    TimeApp() {
        name = "Time";
        description = "Displays the current time.";
    }

    void setup() override;

    void tick() override;

    void handleButtonPressed(int button, ClickType clickType) override;
};

#endif  // TIME_H
