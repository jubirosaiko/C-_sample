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

enum
{
	BALL_MAX = 8
};

//ボール
struct Ball
{
	float x;
	float y;
	float size_x;
	float size_y;
	float r;
	float speed_x;
	float speed_y;
	Color color;
	bool active;

}ball[BALL_MAX];

Random random;
bool isMouse_click;

//初期化
void Init()
{
	for (int i = 0; i < BALL_MAX; ++i){
		ball[i].x = 0;
		ball[i].y = 0;
		ball[i].size_x = 10;
		ball[i].size_y = 10;
		ball[i].r = 10;
		bool active = false;
	}
}

//重力
const float gravity = -1.0;

// 
// メインプログラム
// 
int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	random.setSeed(u_int(time(nullptr)));
	Init();





	while (env.isOpen()) {


		//クリック判定
		if (env.isPushButton(Mouse::LEFT))
		{
			isMouse_click = true;
		}


		for (int i = 0; i < BALL_MAX; ++i)
		{
			//クリックしたら
			if (isMouse_click)
			{

				if (!ball[i].active)
				{
					ball[i].active = true;

					ball[i].x = env.mousePosition().x();
					ball[i].y = env.mousePosition().y();

					ball[i].speed_x = random.fromFirstToLast(1.0f, 3.0f);
					ball[i].speed_y = random.fromFirstToLast(2.0f, 3.0f);

					ball[i].color = Color(random.fromFirstToLast(0.0f, 1.0f), random.fromFirstToLast(0.0f, 1.0f), random.fromFirstToLast(0.0f, 1.0f));

					isMouse_click = false;
				}
			}
		}

		//弾の動き
		for (int i = 0; i < BALL_MAX; ++i)
		{
			ball[i].x += ball[i].speed_x;
			ball[i].y += ball[i].speed_y;

		
			if (ball[i].x >= WIDTH / 2)
			{
				ball[i].x = WIDTH / 2 - ball[i].size_x;
				ball[i].speed_x *= -1;
			}
			
			if (ball[i].x <= -WIDTH / 2)
			{
				ball[i].speed_x *= -1;
			}

			if (ball[i].y >= HEIGHT / 2)
			{
				ball[i].y = HEIGHT / 2 - ball[i].size_y;
				ball[i].speed_y *= -1;
			}

			if (ball[i].y <= -HEIGHT / 2)
			{
				ball[i].y = -HEIGHT / 2;
				ball[i].speed_y *= -1;
			}
			//押したら重力をかける
			if (env.isPressKey('G'))
			{
				ball[i].speed_y += gravity;	
			}		
		}


		env.setupDraw();

		//描画→クリック判定と配列を見る
		for (int i = 0; i < BALL_MAX; ++i)
		{
			if (ball[i].active)
			{
				drawFillCircle(ball[i].x, ball[i].y, ball[i].size_x, ball[i].size_y, 100, ball[i].color);
			}
		}

		env.update();
	}
}