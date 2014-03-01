#include "testApp.h"

using namespace ofxCv;

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
	
	cam.initGrabber(640, 480);
	
	tracker.setup();


}

//--------------------------------------------------------------
void testApp::update(){
    cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
		position = tracker.getPosition();
		scale = tracker.getScale();
		orientation = tracker.getOrientation();
		rotationMatrix = tracker.getRotationMatrix();
	}


}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
	cam.draw(0, 0);
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
	
	if(tracker.getFound()) {
        ofSetColor(0, 255, 0);
		ofSetLineWidth(1);
		//tracker.draw();
		
		//easyCam.begin();
		ofSetupScreenOrtho(640, 480, OF_ORIENTATION_UNKNOWN, true, -1000, 1000);
		ofTranslate(640 /4, 480 / 4);
		applyMatrix(rotationMatrix);
		ofScale(4,4,4);
		//ofDrawAxis(scale);
		tracker.getObjectMesh().drawWireframe();
		//easyCam.end();
	}


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'r') {
		tracker.reset();
	}

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
