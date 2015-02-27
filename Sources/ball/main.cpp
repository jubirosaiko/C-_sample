//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"


enum Window {
	WIDTH = 512,
	HEIGHT = 512
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

}ball;


void Init()
{
	ball.x = 10;
	ball.y = 10;
	ball.size_x = 10;
	ball.size_y = 10;
	ball.r = 10;
	ball.speed_x = 2;
	ball.speed_y = 3;

}

float gravity = 0.9;

// 
// メインプログラム
// 
int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);


	Init();



	while (env.isOpen()) {

		ball.x += ball.speed_x;
		ball.y += ball.speed_y;

		if (ball.x >= WIDTH / 2 - ball.size_x || ball.x <= -WIDTH / 2 + ball.size_x)
		{
			ball.speed_x *= -1;
		}



		if (ball.y >= HEIGHT / 2 - ball.size_y || ball.y <= -HEIGHT / 2 + ball.size_y)
		{
			ball.speed_y *= -1;
			if (ball.y <= -HEIGHT / 2 + ball.size_y)
			{
				ball.y = -HEIGHT / 2 + ball.size_y;
			}

		}

		if (env.isPressKey('G'))
		{
			ball.speed_y -= gravity;
			ball.y += ball.speed_y;
		}





		env.setupDraw();

		drawFillCircle(ball.x, ball.y, ball.size_x, ball.size_y, ball.r, Color(1, 1, 1));



		env.update();
	}
}