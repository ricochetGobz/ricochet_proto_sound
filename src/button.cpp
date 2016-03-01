//
//  Button.cpp
//  ricochet_proto_sound
//
//  Created by Chloé Henaut on 29/02/2016.
//
//

#include <stdio.h>
#include "button.h"

//--------------------------------------------------------------
button::button(ofPoint _pos, int _id){
    pos = _pos;
    buttonId = _id;
}

//--------------------------------------------------------------
void button::draw(){
    ofFill();
    ofSetColor(100,200,100);
    ofPoint posMid;
    posMid.x = pos.x - size /2;
    posMid.y = pos.y - size/2;
    ofDrawRectangle(posMid,size,size/3);
}

bool button::isInside(ofPoint point){
    ofPoint posMid;
    posMid.x = pos.x - size /2;
    posMid.y = pos.y - size/2;
    if(ofRectangle(posMid,size,size/3).inside(point)) return true;
    else return false;
}