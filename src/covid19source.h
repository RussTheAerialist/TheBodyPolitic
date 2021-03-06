#pragma once

#include "FboSource.h"
#include "covidLoader.h"
#include "ofMain.h"
#include "clock.h"
#include "palette/palette.h"
#include "particle/particle.h"

#include <map>

class Covid19 : public ofx::piMapper::FboSource {
public:
	void setup();
	void update();
	void draw();
	void reset();
	void onSpeedChange(float &s);
	void onTempoChange(float &s);
	void onDrawChange(bool &b);
	void onClearChange(bool &b);
	void onXOffsetChange(float &f);
	void onYOffsetChange(float &f);
	void onLabelRotationChange(float &f);

	ofTrueTypeFont font;

	ofEvent<void> onNextPalette;

private:
	void enumerate_palettes();
	void next_palette();
	std::vector<string> palettes;
	int selectedPalette;

	void handleNextPaletteEvent();

	glm::vec2 screenSize, labelOffset;;
	glm::ivec2 colorLocation;
	float speed = 1.0f;
	float resetTime;
	float size = 20.0f;
	float labelRotation = 0.f;
	float scaledSize = 0.0f;
	float scaledStep = 0.0f;
	bool clearScreen = false;
	bool triggerClear = false;
	bool resetTriggered = false;

	void loadCovidCsv();
	void sortDataByDate();
	LoadedCovidData covidData;
	int index, lastIndex;
	Clock clock;

	ParentReference particlePayload;

	std::map<BucketKey, Particle*> particles;
};