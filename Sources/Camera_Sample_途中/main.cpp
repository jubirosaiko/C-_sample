//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include "time.h"

enum Window {
	WIDTH = 640,
	HEIGHT = 480
};

struct Bg
{
	float x;
	float y;
	float size_x;
	float size_y;
	float max_size_x;
	float max_size_y;
}bg;

struct Enemy
{
	float x;
	float y;
	float size_x;
	float size_y;
}enemy;

struct Player
{
	float x;
	float y;
	float size_x;
	float size_y;
}player;


//初期化
void Init()
{
	bg.x = -WIDTH / 2;
	bg.y = -HEIGHT / 2;
	bg.size_x = WIDTH;
	bg.size_y = HEIGHT;
	bg.max_size_x = 0;
	bg.max_size_y = 0;

	player.x = -WIDTH / 2;
	player.y = -HEIGHT / 2;
	player.size_x = 50;
	player.size_y = 50;


}

//プレイヤーを動かす
void Player_move(AppEnv &env)
{
	if (env.isPressKey('A'))
	{
		player.x -= 3;
	}
	if (env.isPressKey('D'))
	{
		player.x += 3;
	}
	if (env.isPressKey('W'))
	{
		player.y += 3;
	}
	if (env.isPressKey('X'))
	{
		player.y -= 3;
	}
}
//プレイヤーの移動制限
void Player_move_area(Player x)
{
	if (player.x > -WIDTH / 2 + 110)
	{
		player.x -= 0;
	}
}
//カメラ移動
//void Camera_move



















// 
// メインプログラム
// 
int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	Texture t_bg("res/bg.png");
	Texture t_enemy("res/enemy.png");
	Texture t_player("res/player.png");

	Init();


	while (env.isOpen()) {

		Player_move(env);
		Player_move_area(player);

		env.setupDraw();


		drawTextureBox(bg.x, bg.y, bg.size_x, bg.size_y, 0, 0, 1024, 512, t_bg, Color(1, 1, 1)); //切り抜き開始位置をカメラで動かす
		drawTextureBox(player.x, player.y, player.size_x, player.size_y, 0, 0, 128, 128, t_player, Color(1, 1, 1));
		//drawTextureBox(Color(1, 1, 1));

		env.update();
	}
}