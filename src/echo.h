//
//  echo.h
//  ricochet_proto_sound
//
//  Created by Chloé Henaut on 29/02/2016.
//
//

#ifndef echo_h
#define echo_h
#include "ofMain.h"

class echo{
    public :
    // Constructor
    echo(ofPoint _pos);
    
    // Methods
    void expand();
    void draw();
    bool souldRemoved();
    
    private :
    // Vars
    float size = 5;
    ofPoint pos;
    ofColor color;
    
    float sizeMax = 300;
    float expandForce = 99;
    float vel = 0.05;
};

#endif /* echo_h */
