//
//  echo.cpp
//  ricochet_proto_sound
//
//  Created by Chloé Henaut on 29/02/2016.
//
//

#include <stdio.h>
#include "echo.h"

//--------------------------------------------------------------
echo::echo(ofPoint _pos){
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    pos = _pos;
}

//--------------------------------------------------------------
void echo::draw(){
    ofNoFill();
    ofDrawCircle(pos.x, pos.y, size);
}

//--------------------------------------------------------------
void echo::expand(){
    
    expandForce = (sizeMax - size) * vel;
    size += expandForce;
    
    //size += 4;
}

bool echo::souldRemoved() {
    
    return (expandForce < 0.9);
    //return (size > sizeMax);
}