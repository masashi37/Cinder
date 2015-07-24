
#pragma once

#include "common.h"


typedef std::shared_ptr<class Star>StarSP;
class Star{

private:
	struct StarDate{
		Vec3f star_pos;
		Color star_color;
		float angle = 0;
		float star_move_speed = 50.0f;
		const float angle_plus = 0.1f;
		const float star_size = 3.0f;
	};
	std::vector<StarDate>star;

	int star_change_time = 0;

public:

	Star(const int star_number){
		for (int i = 0; i < star_number; ++i){
			star.emplace_back();
		}
	}

	void updata(){
		star_change_time++;

		for (auto& stars : star){

			//ˆÊ’u‚ÆF‚Ì•ÏX
			if (star_change_time % 60 * 2 == 0){
				stars.star_pos = {
					Rand::randFloat(-WIDTH / 2 * 3, WIDTH / 2 * 3),
					Rand::randFloat(-HEIGHT / 2 * 3, HEIGHT / 2 * 3),
					Rand::randFloat(0, -DEPTH)
				};
				stars.star_color = { Color(
					Rand::randFloat(0, 1),
					Rand::randFloat(0, 1),
					Rand::randFloat(0, 1))
				};
			}

			//ˆÚ“®
			stars.star_pos.z += stars.star_move_speed;
			if (stars.star_pos.z > -DEPTH / 2)
				stars.star_pos.z = -DEPTH;

			//‰ñ“]
			stars.angle += stars.angle_plus;
		}

	}

	void draw(){
		for (auto& stars : star){
			//•`‰æ
			gl::rotate(Vec3f(0, 0, stars.angle));
			gl::color(stars.star_color);

			//gl::drawSphere(stars.star_pos, stars.star_size);
			gl::drawLine(stars.star_pos,
				Vec3f(stars.star_pos.x, stars.star_pos.y, stars.star_pos.z - 100));

			gl::color(1, 1, 1);
			gl::rotate(Vec3f(0, 0, -stars.angle));
		}
	}
};