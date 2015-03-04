//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include "time.h"

enum Window {
	WIDTH = 512,
	HEIGHT = 512
};

//プレイヤー
struct Player
{
	float x;
	float y;
	bool jumping;
	float vy;
}player;

//ジャンプした際の加速的な
const float jump_power = 20.0f;
//重力
const float gravity = -1.0f;
//初期化
void Init()
{
	player.x = 0;
	player.y = 0;
	player.jumping = false;
}


// 
// メインプログラム
// 
int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);


	

	while (env.isOpen()) {

		//ジャンプしてない時
		if (!player.jumping){
			if (env.isPushKey('S'))
			{
				player.jumping = true;
				player.vy = jump_power;
			}
		}
		//ジャンプさせているとき
		if (player.jumping)
		{
			player.y += player.vy + 0.5 * gravity;
			player.vy += gravity;
		}
		//着地用
		if (player.y <= 0)
		{
			player.jumping = false;
		}

		env.setupDraw();

		drawFillCircle(player.x, player.y, 10, 10, 100, Color(1, 1, 1));

		
		env.update();
	}
}