
#pragma once

#include "common.h"

typedef std::shared_ptr<class Particle>ParticleSP;
class Particle {
private:

	struct ParticleStatus {
		Vec3f pos;			//パーティクルポジション
		Vec3f size;			//パーティクルサイズ
		Vec3f speed;		//パーティクル速度
		ColorA color;		//パーティクル色
	};
	std::vector<ParticleStatus>particle;

	int clear_time;					//パーティクルを消す時間制御

	bool is_ready;					//パーティクルの準備ができているかどうか？

public:

	//パーティクル準備
	void create(int, Vec3f);

	//パーティクル
	void draw();

};