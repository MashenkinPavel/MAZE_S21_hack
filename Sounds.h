#ifndef SOUNDS_H
#define SOUNDS_H

#include <Arduboy2.h>
#include <ArduboyPlaytune.h>
#include "bach.h"

class SoundManager {
public:
    void init(Arduboy2* arduboyPtr, ArduboyPlaytune *psound) {
        arduboy = arduboyPtr;
        sound = psound;
        soundEnabled = true;
    }
    
    // // Безопасная версия воспроизведения тона
    // void playTone(unsigned int frequency, unsigned long duration) {
    //     if (!soundEnabled || !arduboy || !arduboy->audio.enabled()) return;
        
    //     // Используем встроенную функцию Arduboy2 вместо tone()
    //     playTone(frequency, duration);
    // }
    
    // Фоновая музыка для стартового экрана (короткая и безопасная)
    void playTitleMusic() {
        if (!soundEnabled || !arduboy || !arduboy->audio.enabled()) return;
        
        if(!sound->playing()) sound->playScore(bach);
    }
    

    void muteScore() {
        sound->stopScore();
    }
    
    // Звук нажатия кнопки
    void playButtonPress() {
        sound->tone(800, 40);
        delay(40);
    }
    
    
    // Звук сбора монеты
    void playCoinCollect() {
        sound->tone(1000, 60);
    }
    
    // Звук телепортации (переключения этажей)
    void playTeleportSound() {
        sound->tone(400, 150);delay(160);sound->tone(650, 150);
    }
    
    // Звук достижения выхода
    void playExitReached() {
    sound->tone(700, 380);
     delay(380);
    sound->tone(900, 380);
     delay(380);
    sound->tone(1200, 380);
     delay(380);
    }
    
    // Включить/выключить звук
    void enableSound(bool enable) {
        soundEnabled = enable;
        if (arduboy) {
            if (enable) arduboy->audio.on();
            else arduboy->audio.off();
        }
    }

    // Проверить, включен ли звук
    bool isSoundEnabled() {
        return soundEnabled && arduboy && arduboy->audio.enabled();
    }

        // // Звук смерти
    // void playDeathSound() {
    //     sound->tone(200, 150);
    // }
    
    // // Звук победы
    // void playWinSound() {
    //     sound->tone(700, 100);
    // }
    
    // // Звук удара
    // void playHitSound() {
    //     sound->tone(300, 50);
    // }

private:
    Arduboy2* arduboy;
    ArduboyPlaytune* sound;
    bool soundEnabled;
};

#endif