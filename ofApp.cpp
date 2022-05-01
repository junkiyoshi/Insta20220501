#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetColor(255);
	ofNoFill();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	int base_radius = (ofGetFrameNum() * 1.5) % 420 + 60;

	for (int i = this->location_list.size() - 1; i >= 0; i--) {

		this->radius_list[i] += this->speed_list[i];

		if (this->radius_list[i] > this->max_radius_list[i]) {

			this->location_list.erase(this->location_list.begin() + i);
			this->radius_list.erase(this->radius_list.begin() + i);
			this->speed_list.erase(this->speed_list.begin() + i);
			this->max_radius_list.erase(this->max_radius_list.begin() + i);
		}
	}

	for (int i = 0; i < 8; i++) {

		int random_deg = ofRandom(360);
		int random_radius = base_radius + ofRandom(-10, 10);

		auto location = glm::vec2(random_radius * cos(random_deg * DEG_TO_RAD), random_radius * sin(random_deg * DEG_TO_RAD));
		this->location_list.push_back(location);
		this->radius_list.push_back(1);
		this->speed_list.push_back(ofRandom(0.2, 1.5));
		this->max_radius_list.push_back(ofRandom(5, 30));
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	for (int i = 0; i < this->location_list.size(); i++) {

		ofSetColor(255, ofMap(this->radius_list[i], 1, this->max_radius_list[i], 255, 30));
		ofDrawCircle(this->location_list[i], this->radius_list[i]);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}