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
	BALL_MAX = 5
};

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

}ball[BALL_MAX];


Random random;

void Init()
{


	for (int i = 0; i < BALL_MAX; i++)
	{

		ball[i].size_x = 10;
		ball[i].size_y = 10;
		ball[i].r = 10;
		ball[i].x = random.fromFirstToLast(-WIDTH / 2, WIDTH / 2);
		ball[i].y = random.fromFirstToLast(-HEIGHT / 2, HEIGHT / 2);
		ball[i].speed_x = random.fromFirstToLast(1.0f, 2.0f);
		ball[i].speed_y = random.fromFirstToLast(3.0f, 4.0f);
		ball[i].color = Color(random.fromFirstToLast(0.0f, 1.0f), random.fromFirstToLast(0.0f, 1.0f), random.fromFirstToLast(0.0f, 1.0f));
	}


}

float gravity = 0.9;



// 
// メインプログラム
// 
int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);


	random.setSeed(u_int(time(nullptr)));
	Init();
	

	while (env.isOpen()) {


		for (int i = 0; i < BALL_MAX; i++)
		{
			ball[i].x += ball[i].speed_x;
			ball[i].y += ball[i].speed_y;
		}


		for (int i = 0; i < BALL_MAX; i++)
		{
			if (ball[i].x >= WIDTH / 2 - ball[i].size_x || ball[i].x <= -WIDTH / 2 + ball[i].size_x)
			{
				ball[i].speed_x *= -1;
			}



			if (ball[i].y >= HEIGHT / 2 - ball[i].size_y || ball[i].y <= -HEIGHT / 2 + ball[i].size_y)
			{
				ball[i].speed_y *= -1;
				if (ball[i].y <= -HEIGHT / 2 + ball[i].size_y)
				{
					ball[i].y = -HEIGHT / 2 + ball[i].size_y;
				}

			}

			if (env.isPressKey('G'))
			{
				ball[i].speed_y -= gravity;
				ball[i].y += ball[i].speed_y;
			}
		}

		env.setupDraw();

		for (int i = 0; i < BALL_MAX; i++)
		{
			drawFillCircle(ball[i].x, ball[i].y, ball[i].size_x, ball[i].size_y, 100, ball[i].color);
		}

		env.update();
	}
}
