
#pragma once

#include "FadeBase.h"


class FadeIn :public FadeBase {

private:

	std::function<void()>fade;

	void fullScreenFade(
		int endTime = 2,
		Color color = Color::black(),
		bool isUseEasing = false);

	void circleScalingFade(
		int endTime = 2,
		Color color = Color::black(),
		bool isUseEasing = false);

	void veilDownFade(
		int endTime = 2,
		Color color = Color::black(),
		bool isUseEasing = false);

	void fromLeftCurtainFade(
		int endTime = 2,
		Color color = Color::black(),
		bool isUseEasing = false);

	void fromRightCurtainFade(
		int endTime = 2,
		Color color = Color::black(),
		bool isUseEasing = false);

	void centerCurtainFade(
		int endTime = 2,
		Color color = Color::black(),
		bool isUseEasing = false);

	void pinHoleFade(
		int endTime = 2, float space = 0.0f, const int slices = 12,
		Color color = Color::black(), bool isUseEasing = false);

public:

	FadeIn();

	void setType(
		FadeType,
		int time = 2,
		Color color = Color::black(),
		bool isUseEasing = false
		);

	bool getIsEnd();

	void draw();

};

