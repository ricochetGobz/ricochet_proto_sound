//
//  Button.hpp
//  ricochet_proto_sound
//
//  Created by Chloé Henaut on 29/02/2016.
//
//

#ifndef button_h
#define button_h

#include "ofMain.h"

class button{
public:
    // Constructor
    button(ofPoint _pos, int _id);
    
    // Methods
    void draw();
    bool isInside(ofPoint point);
    
    // Vars
    int buttonId;
    int size = 150;
    
    ofPoint pos;
    ofSoundPlayer faceSound;
};

#endif /* button_h */
