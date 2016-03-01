//
//  ricochetCube.h
//  ricochet_proto_sound
//
//  Created by Chloé Henaut on 29/02/2016.
//
//

#ifndef ricochetCube_h
#define ricochetCube_h

#include <stdio.h>
#include <ofMain.h>
#include <button.h>

class ricochetCube{
public:
    // Constructor
    ricochetCube(ofPoint _pos, int _id);
    
    // Methods
    void draw(float * fftSmoothed);
    void update();
    void loadSound(string soundPath, int soudId);
    void play(int soundId);
    
    ofPoint pos;
    int cubeId;
    
    /* VECTORS */
    vector<button> buttons;

    /* AUDIO PART */
    vector<ofSoundPlayer> sounds;
};


#endif /* ricochetCube_h */
