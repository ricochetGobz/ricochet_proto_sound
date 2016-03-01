#include "ofMain.h"
#include "ofApp.h"
#include "ricochetCube.h"
#include "echo.h"


bool shouldRemove(echo &e){
    return e.souldRemoved();
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    /// Graphisme init  ///
    ofSetCircleResolution(60);
    
    cubes.push_back(*new ricochetCube(ofPoint(400, 250),0));
}

//--------------------------------------------------------------
void ofApp::update(){
    ofRemove(echoes, shouldRemove);
    for(vector<echo>::iterator it = echoes.begin(); it != echoes.end(); ++it){
        (*it).expand();
    }
    cubes[0].update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cubes[0].draw();
    for(vector<echo>::iterator it = echoes.begin(); it != echoes.end(); ++it){
        (*it).draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int buttona){
    for(vector<button>::iterator it = cubes[0].buttons.begin(); it != cubes[0].buttons.end(); ++it){
        if((*it).isInside(ofPoint(x, y))) {
            mouseDown = true;
            buttonPressed = (*it).buttonId;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int buttona){
    if (!mouseDown) return;
    for(vector<button>::iterator it = cubes[0].buttons.begin(); it != cubes[0].buttons.end(); ++it){
        if((cubes[0].buttons[buttonPressed]).isInside(ofPoint(x, y))) {
            //TODO
            cubes[0].play(buttonPressed);
            createEcho();
        }
    }
    mouseDown = false;
    buttonPressed = -1;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::createEcho(){
    echoes.push_back(*new echo(ofPoint(525, 375)));
}