//
//  ricochetCube.cpp
//  ricochet_proto_sound
//
//  Created by Chloé Henaut on 29/02/2016.
//
//

#include <stdio.h>
#include "ricochetCube.h"
#include "button.h"

//--------------------------------------------------------------
ricochetCube::ricochetCube(ofPoint _pos, int _id){
    pos = _pos;
    cubeId = _id;
    
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    
    nBandsToGet = 128;
    
    /// SOUNDS INIT ////
    //sounds.push_back(*new ofSoundPlayer);
    vector< ofSoundPlayer>::iterator itSounds = sounds.begin();
    
    ///// BUTTONS INIT ////
    for(int i = 0; i< 6; i++){
        buttons.push_back(*new button(ofPoint(100, 120 + i*80), i));
        sounds.push_back(*new ofSoundPlayer());
        if (i < 5)loadSound("./sounds/note_" + std::to_string(i+1) +".wav", i);
        else loadSound("./sounds/note_" + std::to_string(i+1) +".mp3", i);
    }
}

void ricochetCube::draw() {
    ofFill();
    ofSetColor(fftSmoothed[0],fftSmoothed[50]*50,fftSmoothed[100]*100*25);
    ofDrawRectangle(pos,250,250);
    for(vector<button>::iterator it = buttons.begin(); it != buttons.end(); ++it){
        (*it).draw();
    }
}

void ricochetCube::loadSound(string soundPath, int soundId){
    sounds[soundId].load(soundPath);
}

void ricochetCube::play(int soundId){
    sounds[soundId].play();
}

void ricochetCube::update() {
//    float *test = ofSoundGetSpectrum(512);
//    color = floor((float)250*(*test));
//    cout << color << endl;
    
    float * val = ofSoundGetSpectrum(nBandsToGet);		// request 128 values for fft
    for (int i = 0;i < nBandsToGet; i++){
        
        // let the smoothed calue sink to zero:
        fftSmoothed[i] *= 0.96f;
        
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i] * 255;
        
    }
}