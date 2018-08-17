#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	camera.setup(1280, 720);
	mask.load("mask1.png");
	frontMask.load("frontMask.png");
	
	maskFbo.allocate(mask.getWidth(), mask.getHeight());
	frontFbo.allocate(mask.getWidth(), mask.getHeight());

	
}

//--------------------------------------------------------------
void ofApp::update(){
	maskFbo.begin();
	ofClear(0,0,0);
	mask.draw(0, 0);
	maskFbo.end();
	
	frontFbo.begin();
	frontMask.draw(0, 0);
	frontFbo.end();
	camera.update();
	
	if (camera.isFrameNew()) {
		camera.getTexture().setAlphaMask(maskFbo.getTexture());
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	camera.draw(0, 0);
	
	
//	ofPixels tempPixels;
//	tempPixels.allocate(ofGetWindowWidth(), ofGetWindowHeight(), 4);
//	camera.getTexture().readToPixels(tempPixels);
//
//
//	for (int i = 0; i<tempPixels.getWidth(); i++) {
//		for(int j = 0;j < tempPixels.getHeight();j++){
//			if(tempPixels.getColor(i,j).a == 0){
//				tempPixels.setColor(i,j, ofColor(255,255,255));
//			}
//
//		}
//
//	}
//
//	ofImage img;
//	img.setFromPixels(tempPixels);
//	img.draw(0, 0);
//

	frontMask.draw(0, 0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
